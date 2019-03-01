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
// �� �� ��: bool LoadWinSocket()
// ��    ��: ����WSOCK32.DLL
// �������: ��
// �������: �ɹ�����TRUE,����FALSE
//////////////////////////////////

bool loadWinSocket(void)
{

	WSADATA	wsaData;
	int nWINSOCKVersion;
	nWINSOCKVersion = 0x0202;		//��ʾ Winsock version 2.2

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
    unsigned long ip;  // �������ʽ�洢��IP��ַ 
    unsigned short port; //  �������ʽ�洢�Ķ˿ں� 
    char * data;
    short len;
}TUdpData;

class  CVauUdp
{
public:
   CVauUdp(SOCKET udpSocket, UdpRecCallBack pfBackCall);
   ~CVauUdp(void);
   // ��Ӧ�ò������Ҫ���͵����ݰ� 
   void receive(const char * ip, u_short port, const char * data, short len);

   void read(void); // �������ж���
   void write(void); // ����д������ 
   void close(void); // ��UDP�ر�. 

   // �ṩ�����̣߳��������߳��Ǽ���ִ�У������˳��� 
   bool readContinue(void);
   // �ṩ��д�̣߳�����д�߳��Ǽ���ִ�У������˳��� 
   bool writeContinue(void);
   
   // ���߳�֪ͨ���߳��ѽ����� 
   void readEnd(void);
   // д�߳�֪ͨ���߳��ѽ����� 
   void writeEnd(void);
private:
    SOCKET m_hSocket;  // SOCKET��� 

    HANDLE m_hQueue;  // �¼���������¼�����֪ͨUDP����������������Ҫ���͡� 
    deque<TUdpData> m_QueueReceive;  // ���ն��У���Ҫ���͵��������͵������У��ٰ����͡� 
    
    UdpRecCallBack m_fnBackCallReceive; // ���յ����ݺ󣬽���Ӧ�ò�Ļص������� 
    
    // ÿ��UDP����һ�������̺�һ��д����. 
    // ��¼����״̬���Ա��ڶԽ��̽��п��ơ�
    // 0:���̼���  1:�����˳� 2:�����˳���� 
    u8   m_byStateWriteThread; 
    u8   m_byStateReadThread;
};

// UDP��Ķ��̣߳��������ȡUDP���ݽ���Ӧ�ò㡣 
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

// UDP���д�̣߳���Ӧ�ò����UDP���ݰ��͸�����
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

// -------------- ��Ա���� ------------------------------ 

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

// �ṩ��Ӧ�ò��ã���Ӧ�ò�Ҫ�������ݰ�������С� 
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

// ��������� 
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
            // ��IP��ַת��Ϊ�ַ�����ʽ 
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

// ����д������ 
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

// �ر�UDP SOCKET 
void CVauUdp::close(void)
{
    if (m_hSocket != NULL)
    {
        closesocket(m_hSocket);
    }
 

    m_byStateReadThread = 1;
    m_byStateWriteThread = 1;

    // ��һ���հ���д�̣߳���ʹд�߳��˳��� 
    receive("127.0.0.0", 0, 0, 0);

    while ((m_byStateReadThread != 2) || (m_byStateWriteThread != 2))
    {
        Sleep(100);
    }
}

// �ṩ�����̣߳��������߳��Ǽ���ִ�У������˳��� 
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

// �ṩ�����̣߳��������߳��Ǽ���ִ�У������˳��� 
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

// ���߳�֪ͨ���߳��ѽ����� 
void CVauUdp::readEnd(void)
{
    m_byStateReadThread = 2;
}

// д�߳�֪ͨ���߳��ѽ����� 
void CVauUdp::writeEnd(void)
{
    m_byStateWriteThread = 2;
}

/****************  �ṩ������ģ��Ľӿں��� ************************/

// ����UDP SOCKET 
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

// �ر�UDP�˿�
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

// �����ݰ�д��UDP�˿� 
void UdpWrite(long udpId, const s8 * ip, u16 port, const s8 * data, s16 len)
{
    CVauUdp * vauUdp;

    vauUdp = (CVauUdp *)udpId;

    vauUdp->receive(ip, port, data, len);
}


