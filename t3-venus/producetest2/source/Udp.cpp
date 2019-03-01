#include "StdAfx.h"
#include <windows.h>
#include <winuser.h>

#include <stdio.h>
#include <winsock.h>
#include <process.h>
#include <deque>

using namespace std;

#include "udp.h"



//extern void putStrToWnd(const char * str);
//extern void log(char * fileName, int line, char * info);

///////////////////////////////
//
// 函 数 名: bool LoadWinSocket()
// 功    能: 载入WSOCK32.DLL
// 输入参数: 无
// 输出参数: 成功返回TRUE,否则FALSE
//////////////////////////////////

bool loadWinSocket(void)
{

	WSADATA	wsaData;
	int nWINSOCKVersion;
	nWINSOCKVersion = 0x0202;		//表示 Winsock version 2.2

	if(WSAStartup(nWINSOCKVersion, &wsaData) != 0)
	{
		return false;
	}

	if(LOBYTE( wsaData.wVersion ) != 2 || HIBYTE( wsaData.wVersion ) != 2 )
	{
		WSACleanup( );
		return false;
	}
	return true;

}

typedef struct
{
    unsigned long ip;  // 以网络格式存储的IP地址 
    unsigned short port; //  以网络格式存储的端口号 
    char * data;
    short len;
}TUdpData;

class  CVauUdp
{
public:
   CVauUdp(SOCKET udpSocket, UdpRecCallBack pfBackCall);
   ~CVauUdp(void);
   // 从应用层接收需要发送的数据包 
   void receive(const char * ip, u_short port, const char * data, short len);

   void read(void); // 从网络中读包
   void write(void); // 将包写入网络 
   void close(void); // 将UDP关闭. 

   // 提供给读线程，决定读线程是继续执行，还是退出。 
   bool readContinue(void);
   // 提供给写线程，决定写线程是继续执行，还是退出。 
   bool writeContinue(void);
   
   // 读线程通知，线程已结束。 
   void readEnd(void);
   // 写线程通知，线程已结束。 
   void writeEnd(void);
private:
    SOCKET m_hSocket;  // SOCKET句柄 

    HANDLE m_hQueue;  // 事件句柄，此事件用来通知UDP，队列中有数据需要发送。 
    deque<TUdpData> m_QueueReceive;  // 接收队列，需要发送的数据先送到队列中，再按序发送。 
    
    UdpRecCallBack m_fnBackCallReceive; // 接收到数据后，交给应用层的回调函数。 
    
    // 每个UDP都有一个读进程和一个写进程. 
    // 记录进程状态，以便于对进程进行控制。
    // 0:进程继续  1:进程退出 2:进程退出完成 
    u8   m_byStateWriteThread; 
    u8   m_byStateReadThread;
};

// UDP层的读线程，从网络读取UDP数据交给应用层。 
DWORD WINAPI   ThreadUdpRead(PVOID pvoid)
{
    Sleep(100);
    CVauUdp * vauUdp;

    vauUdp = (CVauUdp *)pvoid;
    while (vauUdp->readContinue())
    {
        vauUdp->read( );
    }

    vauUdp->readEnd( );

	return 0;
}

// UDP层的写线程，从应用层接收UDP数据包送给网络
DWORD WINAPI ThreadUdpWrite(PVOID pvoid)
{
    CVauUdp * vauUdp;

    Sleep(100);
    vauUdp = (CVauUdp *)pvoid;

    while(vauUdp->writeContinue())
    {
        vauUdp->write( );
    }

    vauUdp->writeEnd( );

	return 0;
}

// -------------- 成员函数 ------------------------------ 

CVauUdp::CVauUdp(SOCKET udpSocket, UdpRecCallBack pfBackCall)
{
   m_hQueue = CreateEvent (0, false, false, 0) ;

   m_hSocket = udpSocket;
   m_fnBackCallReceive = pfBackCall;

   //_beginthread(thread_udp_read, 0, (PVOID)this);
   //_beginthread(thread_udp_write, 0, (PVOID)this);

   CreateThread (NULL, 0, ThreadUdpRead, (PVOID)this, 0, 0);
   CreateThread (NULL, 0, ThreadUdpWrite, (PVOID)this, 0, 0);

   m_byStateReadThread = 0;
   m_byStateWriteThread = 0;
}

CVauUdp::~CVauUdp(void)
{
    CloseHandle(m_hQueue);
}

// 提供给应用层用，将应用层要发的数据包放入队列。 
void CVauUdp::receive(const char * ip, u_short port, const char * data, short len)
{
    TUdpData udpData;

    udpData.ip = inet_addr(ip);
    udpData.port = htons(port);
    udpData.data = (char *)malloc(len);
    memcpy(udpData.data, data, len);
    udpData.len = len;
    m_QueueReceive.push_back(udpData);
    SetEvent(m_hQueue);
}

// 从网络读包 
void CVauUdp::read(void)
{
    s8 * buf;
    s32 len, addrLen;
    sockaddr addr;
    u64 ip;
    u16 port;

    buf = (char *)malloc(2000);
    memset(buf, 0, 2000);

    addrLen = sizeof(addr);
    len = recvfrom(m_hSocket, buf, 2000, 0, &addr, &addrLen);
    ip = *(u64 *)&(addr.sa_data[2]);
    port = *(u16 *)addr.sa_data;

    if (len >0)
    {
        if (m_fnBackCallReceive)
        {
            // 将IP地址转化为字符串形式 
            s8 ipStr[50];
            struct in_addr inAddr;

            inAddr.S_un.S_addr = ip;
            strcpy(ipStr, inet_ntoa(inAddr));

            m_fnBackCallReceive(ipStr, ntohs(port), buf, len);
        }
    }
    else
    {
        //log(__FILE__, __LINE__, "rcvUdpData failure len == 0");
    }

    free(buf);
}

// 将包写入网络 
void CVauUdp::write(void)
{
    sockaddr addr;
    int sndLen;
    TUdpData udpData;

    WaitForSingleObject(m_hQueue, INFINITE);

    while (!m_QueueReceive.empty())
    {
        udpData = m_QueueReceive.front();

        if ((udpData.len == 0) || (udpData.data == 0))
        {
           m_QueueReceive.pop_front();
           continue;
        } 

        addr.sa_family = AF_INET;
        *(u_long *)&addr.sa_data[2] = udpData.ip;
        *(u_short *)addr.sa_data = udpData.port;

        sndLen = sendto(m_hSocket, udpData.data, udpData.len, 0, &addr, sizeof(addr));
    
  

        free(udpData.data);

        m_QueueReceive.pop_front();
    }
}

// 关闭UDP SOCKET 
void CVauUdp::close(void)
{
    if (m_hSocket != NULL)
    {
        closesocket(m_hSocket);
    }
 

    m_byStateReadThread = 1;
    m_byStateWriteThread = 1;

    // 发一个空包给写线程，促使写线程退出。 
    receive("127.0.0.0", 0, 0, 0);

    while ((m_byStateReadThread != 2) || (m_byStateWriteThread != 2))
    {
        Sleep(100);
    }
}

// 提供给读线程，决定读线程是继续执行，还是退出。 
bool CVauUdp::readContinue(void)
{
     if (m_byStateReadThread == 0)
     {
         return true;
     }
     else
     {
         return false;
     }
}

// 提供给读线程，决定读线程是继续执行，还是退出。 
bool CVauUdp::writeContinue(void)
{
     if (m_byStateWriteThread == 0)
     {
         return true;
     }
     else
     {
         return false;
     }
}

// 读线程通知，线程已结束。 
void CVauUdp::readEnd(void)
{
    m_byStateReadThread = 2;
}

// 写线程通知，线程已结束。 
void CVauUdp::writeEnd(void)
{
    m_byStateWriteThread = 2;
}

/****************  提供给其它模块的接口函数 ************************/

// 创建UDP SOCKET 
long UdpOpen(unsigned short port, UdpRecCallBack pfBackCall)
{
    sockaddr_in addr;
    SOCKET h_socket;
    CVauUdp * vauUdp;

    if(!loadWinSocket( ))
    {
        //log(__FILE__, __LINE__, "udp socket load failure!");
        return 0;
    }

    h_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (h_socket == 0)
    {
        //log(__FILE__, __LINE__, "udp socket create failure!");
        return 0;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(h_socket, (LPSOCKADDR)&addr, sizeof(addr)) == SOCKET_ERROR)
    {
        //log(__FILE__, __LINE__, "udp socket bind failure!");
        closesocket(h_socket);
        return 0;
    }

    vauUdp = new CVauUdp(h_socket, pfBackCall);

    return (long)vauUdp;
}

// 关闭UDP端口
void UdpClose(u32 dwUdpId)
{
    CVauUdp * vauUdp;
    
    vauUdp = (CVauUdp *)dwUdpId;
    
    if (vauUdp != NULL)
    {   
        vauUdp->close( );
        
        delete vauUdp;
        
    }

}

// 将数据包写入UDP端口 
void UdpWrite(long udpId, const s8 * ip, u16 port, const s8 * data, s16 len)
{
    CVauUdp * vauUdp;

    vauUdp = (CVauUdp *)udpId;

    vauUdp->receive(ip, port, data, len);
}


