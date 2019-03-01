// Logger.cpp: implementation of the CLogger class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Logger.h"
#define MAX_LOG_LEN 1024
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//һЩ��ӡ�ӿ�
bool g_debuginfo = true;
API void pthelp()
{
	LOGEVENT("showdvc\t\t\t����:��\t\t\t��ӡ��ǰ�豸\n");
	LOGEVENT("showbrd\t\t\t����:�忨����\t\t��ӡָ���忨\n");
	LOGEVENT("showcurcase\t\t����:��\t\t\t��ӡ��ǰ������\n");
};

API void debugon()
{
	g_debuginfo = true;
};

API void debugoff()
{
	g_debuginfo = false;
};

API void showdvc()
{
	IDevice *pDvc = USERDATA->GetDevice();
	if ( pDvc != NULL )
	{
		pDvc->Print();
	}
	else
	{
		LOGEVENT( "�豸Ϊ��\n" );
	}
}

API void showbrd( u32 dwIdx = 0 )
{
	IDevice *pDvc = USERDATA->GetDevice();
	if ( pDvc != NULL )
	{
		IBoard *pBoard = pDvc->GetBoard(dwIdx);
		if( pBoard != NULL )
		{
			pBoard->Print();
			IMsgQueMngr *pQue = pBoard->GetPreMsgQue();
			if ( pQue != NULL )
			{
				LOGEVENT("\t---------------PreMsgQue------------------\n");
				pQue->Print();
			}
			pQue = pBoard->GetEndMsgQue();
			if ( pQue != NULL )
			{
				LOGEVENT("\t---------------EndMsgQue------------------\n");
				pQue->Print();
			}
			pQue = pBoard->GetResMsgQue();
			if ( pQue != NULL )
			{
				LOGEVENT("\t---------------ResMsgQue------------------\n");
				pQue->Print();
			}
		}
		else
		{
			LOGEVENT("�忨��Ч\n");
		}
	}
	else
	{
		LOGEVENT( "�豸��Ч\n" );
	}
}

API void showcurcase()
{
	IDevice *pDvc = USERDATA->GetDevice();
	if ( pDvc != NULL )
	{
		ITestCase *pCase = pDvc->GetCurTestCase();
		if ( pCase != NULL )
		{
			pCase->Print();
		}
		else
		{
			LOGEVENT("��ǰ��������Ч\n");
		}
	}
	else
	{
		LOGEVENT( "�豸Ϊ��\n" );
	}

}

CLogger::CLogger()
{

}

CLogger::~CLogger()
{

}

bool CLogger::LogEvent( LPCTSTR pszFormat, ...  )
{	
	char szMsg[MAX_LOG_LEN] = { 0 };
	va_list pvlist;
	va_start(pvlist, pszFormat);
	vsprintf((char *)szMsg, pszFormat, pvlist);
	OspPrintf( g_debuginfo, TRUE, szMsg );
	va_end( pvlist );
	return true;
}