// CComm.cpp : Defines the entry point for the console application.
//
#include "StdAfx.h"
#include "CComm.h"

//等待串口线程
DWORD WINAPI CComm::CommWatchProc(PVOID pvoid)
{
	CComm *Comm = (CComm*) pvoid;
	DWORD dwEventMask = 0; //发生的事件； 
	OVERLAPPED ol;
	ol.hEvent = CreateEvent(0, false, false, 0);
	while(Comm->GetOpenState()) 
	{
		//等待监视的事件发生 
		WaitCommEvent(Comm->GetCommHandle(), &dwEventMask, NULL );  //现场阻塞
//		LOGEVENT("EventMask %d",dwEventMask);
		u32 dw = dwEventMask & EV_ERR;
		if ((dwEventMask & EV_ERR) == EV_ERR)
		{
			u32 dwErr = ::GetLastError();
//			LOGEVENT("COM msk %x---err %d\n", dwEventMask, dwErr);
			COMSTAT st;
			::ClearCommError(Comm->GetCommHandle(),0,&st);
		}
        if(dwEventMask & EV_RXCHAR == EV_RXCHAR)
		{
			//两次读取间隔20ms 防止界面事件过多
			Sleep(20);
			Comm->GetComReadCallback()();
		}
	}
    	//发信号，指示监视线程结束
        SetEvent(Comm->GetEventHandle()); 
		return 0; 
}

CComm::CComm(ComReadCallBack pfGetCall)
{
	m_bOpen = FALSE;
	m_fnReadCallback = pfGetCall;
	m_hEvent = CreateEvent(0, false, false, 0);	
	memset(&m_Wol, 0, sizeof(OVERLAPPED));
	m_Wol.hEvent = CreateEvent(0, false, false, 0);
	memset(&m_Rol, 0, sizeof(OVERLAPPED));
	m_Rol.hEvent = CreateEvent(0, false, false, 0);
}
CComm::~CComm()
{
	if (m_bOpen)
	{
		CloseComm();
	}
}

ComReadCallBack CComm::GetComReadCallback()
{
	return m_fnReadCallback;
}


HANDLE CComm::GetEventHandle()
{
	return m_hEvent;
}


HANDLE CComm::GetCommHandle()
{
	return m_hComm;
}

BOOL CComm::GetOpenState()
{
	return m_bOpen;
}



BOOL CComm::OpenComm(LPCSTR pCommPort)
{
	if(m_bOpen) 
	{
        return FALSE;
	}
	//防止COM10以上串口打开失败
	m_strCommName = pCommPort;
	m_strCommName = "\\\\.\\" + m_strCommName;
	if((m_hComm = CreateFile(m_strCommName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL)) == INVALID_HANDLE_VALUE) 
	{
		return FALSE; 
	}
	//设置输入输出缓冲区
	SetupComm( m_hComm, 1024, 1024 );
	m_bOpen = TRUE;
	return TRUE;
}

BOOL CComm::SetCommParam(u32 dwBaud, u32 dwfParity, BYTE byByteSize, BYTE byStopBits)
{
	DCB dcb;
	GetCommState(m_hComm, &dcb);  
	//设定波特率
	dcb.BaudRate = dwBaud;  
	//设定奇偶校验 
	dcb.fParity = dwfParity;  
	//设定数据位
	dcb.ByteSize = byByteSize;  
	//设定停止位 
	dcb.StopBits = byStopBits;
	SetCommMask(m_hComm, EV_ERR | EV_RXCHAR);		//监视串口的错误和接收到字符两种事件 
	//设置串行设备控制参数 
    SetCommState(m_hComm, &dcb);   
	//创建串口监控线程
	HANDLE hTread = CreateThread (NULL, 0, CommWatchProc, (PVOID)this, 0, 0);  
	CloseHandle(hTread);
	return TRUE;
}


BOOL CComm::WriteComm(const LPSTR pSndBuffer, u32 dwBytesToWrite) 
{ 
	//设备已打开 
	BOOL bWriteState;  
	//实际发送的字节数 
	DWORD dwBytesWritten;  
	//设备未打开 
	if(!m_bOpen) 
		return FALSE;  
//	LOGEVENT( "设备是否打开:%d \n", m_bOpen );
	bWriteState= WriteFile(m_hComm, pSndBuffer, dwBytesToWrite, &dwBytesWritten, &m_Wol); 
 	if(!bWriteState || dwBytesToWrite != dwBytesWritten) 
		//发送失败 
		return FALSE;  
	else 
		//发送成功 
		return TRUE;  
} 



u32 CComm::ReadComm(LPSTR pInBuffer, u32 dwBytesToRead) 
{ 
	if ( m_bOpen == FALSE )
	{
		return FALSE;
	}
	//串行设备状态结构 
	COMSTAT ComStat;  
	DWORD dwBytesRead, dwErrorFlags;
	//设备未打开 
	if(!m_bOpen) 
		return 0; 
	//读取串行设备的当前状态 
	ClearCommError(m_hComm, &dwErrorFlags, &ComStat);  
	//应该读取的数据长度 
	dwBytesRead = min(dwBytesToRead, ComStat.cbInQue);  
	if(dwBytesRead>0) 
		//读取数据 
		if(!ReadFile(m_hComm, pInBuffer, dwBytesRead, &dwBytesRead, &m_Rol))  
			dwBytesRead = 0; 
	return dwBytesRead; 
} 

BOOL CComm::CloseComm()
{
	if ( m_bOpen == FALSE )
	{
		return FALSE;
	}
	m_bOpen = FALSE;
	SetCommMask(m_hComm, 0);
	WaitForSingleObject(m_hEvent, INFINITE);
	CloseHandle(m_hEvent);
	//停止发送和接收数据，并清除发送和接收缓冲区 
	PurgeComm(m_hComm, PURGE_TXABORT|PURGE_RXABORT|PURGE_TXCLEAR|PURGE_RXCLEAR); 
	CloseHandle(m_hComm);
	return TRUE;
}

