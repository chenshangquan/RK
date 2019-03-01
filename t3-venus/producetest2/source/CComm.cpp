// CComm.cpp : Defines the entry point for the console application.
//
#include "StdAfx.h"
#include "CComm.h"

//�ȴ������߳�
DWORD WINAPI CComm::CommWatchProc(PVOID pvoid)
{
	CComm *Comm = (CComm*) pvoid;
	DWORD dwEventMask = 0; //�������¼��� 
	OVERLAPPED ol;
	ol.hEvent = CreateEvent(0, false, false, 0);
	while(Comm->GetOpenState()) 
	{
		//�ȴ����ӵ��¼����� 
		WaitCommEvent(Comm->GetCommHandle(), &dwEventMask, NULL );  //�ֳ�����
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
			//���ζ�ȡ���20ms ��ֹ�����¼�����
			Sleep(20);
			Comm->GetComReadCallback()();
		}
	}
    	//���źţ�ָʾ�����߳̽���
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
	//��ֹCOM10���ϴ��ڴ�ʧ��
	m_strCommName = pCommPort;
	m_strCommName = "\\\\.\\" + m_strCommName;
	if((m_hComm = CreateFile(m_strCommName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 
        FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL)) == INVALID_HANDLE_VALUE) 
	{
		return FALSE; 
	}
	//�����������������
	SetupComm( m_hComm, 1024, 1024 );
	m_bOpen = TRUE;
	return TRUE;
}

BOOL CComm::SetCommParam(u32 dwBaud, u32 dwfParity, BYTE byByteSize, BYTE byStopBits)
{
	DCB dcb;
	GetCommState(m_hComm, &dcb);  
	//�趨������
	dcb.BaudRate = dwBaud;  
	//�趨��żУ�� 
	dcb.fParity = dwfParity;  
	//�趨����λ
	dcb.ByteSize = byByteSize;  
	//�趨ֹͣλ 
	dcb.StopBits = byStopBits;
	SetCommMask(m_hComm, EV_ERR | EV_RXCHAR);		//���Ӵ��ڵĴ���ͽ��յ��ַ������¼� 
	//���ô����豸���Ʋ��� 
    SetCommState(m_hComm, &dcb);   
	//�������ڼ���߳�
	HANDLE hTread = CreateThread (NULL, 0, CommWatchProc, (PVOID)this, 0, 0);  
	CloseHandle(hTread);
	return TRUE;
}


BOOL CComm::WriteComm(const LPSTR pSndBuffer, u32 dwBytesToWrite) 
{ 
	//�豸�Ѵ� 
	BOOL bWriteState;  
	//ʵ�ʷ��͵��ֽ��� 
	DWORD dwBytesWritten;  
	//�豸δ�� 
	if(!m_bOpen) 
		return FALSE;  
//	LOGEVENT( "�豸�Ƿ��:%d \n", m_bOpen );
	bWriteState= WriteFile(m_hComm, pSndBuffer, dwBytesToWrite, &dwBytesWritten, &m_Wol); 
 	if(!bWriteState || dwBytesToWrite != dwBytesWritten) 
		//����ʧ�� 
		return FALSE;  
	else 
		//���ͳɹ� 
		return TRUE;  
} 



u32 CComm::ReadComm(LPSTR pInBuffer, u32 dwBytesToRead) 
{ 
	if ( m_bOpen == FALSE )
	{
		return FALSE;
	}
	//�����豸״̬�ṹ 
	COMSTAT ComStat;  
	DWORD dwBytesRead, dwErrorFlags;
	//�豸δ�� 
	if(!m_bOpen) 
		return 0; 
	//��ȡ�����豸�ĵ�ǰ״̬ 
	ClearCommError(m_hComm, &dwErrorFlags, &ComStat);  
	//Ӧ�ö�ȡ�����ݳ��� 
	dwBytesRead = min(dwBytesToRead, ComStat.cbInQue);  
	if(dwBytesRead>0) 
		//��ȡ���� 
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
	//ֹͣ���ͺͽ������ݣ���������ͺͽ��ջ����� 
	PurgeComm(m_hComm, PURGE_TXABORT|PURGE_RXABORT|PURGE_TXCLEAR|PURGE_RXCLEAR); 
	CloseHandle(m_hComm);
	return TRUE;
}

