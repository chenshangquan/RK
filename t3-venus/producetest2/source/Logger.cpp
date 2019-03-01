// Logger.cpp: implementation of the CLogger class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Logger.h"
#define MAX_LOG_LEN 1024
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//一些打印接口
bool g_debuginfo = true;
API void pthelp()
{
	LOGEVENT("showdvc\t\t\t参数:无\t\t\t打印当前设备\n");
	LOGEVENT("showbrd\t\t\t参数:板卡索引\t\t打印指定板卡\n");
	LOGEVENT("showcurcase\t\t参数:无\t\t\t打印当前测试项\n");
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
		LOGEVENT( "设备为空\n" );
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
			LOGEVENT("板卡无效\n");
		}
	}
	else
	{
		LOGEVENT( "设备无效\n" );
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
			LOGEVENT("当前测试项无效\n");
		}
	}
	else
	{
		LOGEVENT( "设备为空\n" );
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