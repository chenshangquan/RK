/*****************************************************************************
ģ����      :  
�ļ���      : printctrl.cpp
����ļ�    : 
�ļ�ʵ�ֹ���: ��ӡ����,��cms��UI���ֺ�lib��umclib �� cnclib�����ֹ�ͬʹ��
����        : �����
�汾        : V1.0  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2011/4/23  1.0          �����      ����
******************************************************************************/

#include "stdafx.h"
#include "printctrl.h"
#include "osp.h"

//kdvlog
#include "kdvlog.h"
#include "loguserdef.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

u32  CPrintCtrl::m_dwPrintMsgType = 0;   //Ҫ��ӡ����Ϣ����
u32  CPrintCtrl::m_dwPrintMsgID = 0 ;     //Ҫ��ӡ����Ϣ��
u32  CPrintCtrl::m_dwPrintRangeMax = 0;  //Ҫ��ӡ����Ϣ��Χ �е����ֵ
u32  CPrintCtrl::m_dwPrintRangeMin = 0;  //Ҫ��ӡ����Ϣ��Χ �е���Сֵ 
BOOL32  CPrintCtrl::m_bPrintMsgBdy =  /*FALSE*/TRUE;  //�Ƿ�Ҫ��ӡ��Ϣ�� //for test
BOOL32  CPrintCtrl::m_bPrintAllMsg =  FALSE ;  //for test 
BOOL32  CPrintCtrl::m_bPrintEnterMsg =  FALSE; //�Ƿ�Ҫ��ӡ��ڴ���Ϣ
BOOL32  CPrintCtrl::m_bPrintOutMsg = FALSE;  //�Ƿ�Ҫ��ӡ���ڴ���Ϣ
u8    CPrintCtrl::m_bayPrintLevel = 0;
map<u16, u8> CPrintCtrl::m_mapEventLevel;
map<u16, CString>CPrintCtrl::m_mapEventsName;
CPrintCtrl* CPrintCtrl::m_pPrtCtrl = NULL ;


CPrintCtrl::CPrintCtrl()
{
  //  LogInit();
#ifdef _DEBUG
    //m_bPrintAllMsg = TRUE;
	m_bayPrintLevel = 2;
#endif
}


CPrintCtrl::~CPrintCtrl()
{
	if ( NULL != m_pPrtCtrl ) 
	{
		delete[] m_pPrtCtrl;
		m_pPrtCtrl = NULL;
	}

//esumeMem();
}

const CPrintCtrl*CPrintCtrl::GetPrintCtrl()  
{
	if ( m_pPrtCtrl == NULL )
	{    
		m_pPrtCtrl = new CPrintCtrl();
    }
    
    return m_pPrtCtrl;
}

const CString CPrintCtrl::GetTime()
{
    SYSTEMTIME st;
    GetLocalTime(&st);  
    CString time = "";
    time.Format("%4d/%.2d/%.2d %.2d:%.2d:%.2d\n",
                 st.wYear, st.wMonth,  st.wDay,
			     st.wHour, st.wMinute, st.wSecond);
    return time;
}

void CPrintCtrl::ForcePrtMsg( u16 dwMsgID, EmEventType emEventType,char * format,... )
{   
    //��ӡ��Ϣ�� 
    CString strEventType = GetEventTypeDescribe(emEventType);
    CString strEvent = "";
    if ( emEventType != emEventTypeCmsWindow )
    { 
        strEvent = GetEventDescribe( dwMsgID );
    }
    
    char szMsg[200] = {0}; 
    _snprintf(szMsg,sizeof(szMsg),"\n%s%s: %s[%d].  ", GetTime(),strEventType,strEvent, dwMsgID );
    
    int n = strlen( szMsg );
    szMsg[n] = '\0';
    
    OspPrintf( TRUE, FALSE,  szMsg ); 
    

//	LogPrint(LOG_LVL_DETAIL,MID_PUB_ALWAYS,szMsg); 
  
	//��ӡ��Ϣ��
	va_list arg_ptr;  
	char szBuffer[300] = { 0 };
	
	va_start(arg_ptr, format);  
	_vsntprintf ( szBuffer, sizeof (szBuffer) / sizeof (TCHAR),format, arg_ptr) ; 
	
	va_end(arg_ptr);  

	n = strlen(szBuffer);
    szBuffer[n] = '\0'; 
    
	OspPrintf(TRUE,FALSE,szBuffer);  
	OspPrintf(TRUE,FALSE,"\n");  
//	LogPrint(LOG_LVL_DETAIL,MID_PUB_ALWAYS,szBuffer);
//	LogPrint(LOG_LVL_DETAIL,MID_PUB_ALWAYS,"\n");

 
}


void  CPrintCtrl::PrintMsg(u16 dwMsgID,EmEventType emEventType, char* format,...)
{  
	if ( ! IsPrintMsg(dwMsgID) && emEventType != emEventTypeCmsWindow   ) 
	{
		return;
    }   
	

    //��ӡ��Ϣ�� 
    CString strEventType = GetEventTypeDescribe(emEventType);
    CString strEvent = "";
    if ( emEventType != emEventTypeCmsWindow )
    { 
        strEvent = GetEventDescribe( dwMsgID );
    }

	//��ӡ��Ϣ��
	char szMsg[200] = {0}; 
    _snprintf(szMsg,sizeof(szMsg),"\n%s%s: %s[%d].  ", GetTime(),strEventType, strEvent, dwMsgID );
   
	int n = strlen(szMsg);
    szMsg[n] = '\0';
 	OspPrintf( TRUE, FALSE,  szMsg );  
 // LogPrint(LOG_LVL_DETAIL,MID_PUB_ALWAYS,szMsg);
 
	 
    //����ǽ�����Ϣ ������Ϣ��Ŀ�������
    if ( ! IsPrintMsgBdy() && emEventType != emEventTypeCmsWindow ) 
	{
	  return;
	} 
	
	//��ӡ��Ϣ��
	va_list arg_ptr;  
	char szBuffer[300] = { 0 };
	
	va_start(arg_ptr, format);  
	_vsntprintf ( szBuffer, sizeof (szBuffer) / sizeof (TCHAR),format, arg_ptr) ; 
	
	va_end(arg_ptr);  
	
	n = strlen(szBuffer);
    szBuffer[n] = '\0';

	OspPrintf(TRUE,FALSE,szBuffer); 
	OspPrintf(TRUE,FALSE,"\n");  

//	LogPrint(LOG_LVL_DETAIL,MID_PUB_ALWAYS,szBuffer);
//	LogPrint(LOG_LVL_DETAIL,MID_PUB_ALWAYS,"\n");
 
	
}


void CPrintCtrl::PrintMsg( char * format,... )
{
	va_list arg_ptr;  
	char szBuffer[1024] = { 0 };
	
	va_start(arg_ptr, format);  
	_vsntprintf ( szBuffer, sizeof (szBuffer) / sizeof (TCHAR),format, arg_ptr) ; 
	
	va_end(arg_ptr); 
	
	int n = strlen(szBuffer);
 
    szBuffer[n] = '\0';
	
	OspPrintf(TRUE,FALSE,szBuffer); 
//	LogPrint(LOG_LVL_DETAIL,MID_PUB_ALWAYS,szBuffer);
 
}



void CPrintCtrl::SetPrintMsgType(const u32 dwPrintMsgType , const BOOL bPrint )
{
	if(bPrint)
		m_dwPrintMsgType = m_dwPrintMsgType | dwPrintMsgType;
	else
		m_dwPrintMsgType = m_dwPrintMsgType & ~dwPrintMsgType;  
	 
}


void CPrintCtrl::StopPrint()
{ 
	m_bPrintAllMsg = FALSE;
	m_dwPrintMsgType = 0;
	m_dwPrintRangeMax = 0;
	m_dwPrintRangeMin = 0;
	m_dwPrintMsgID = 0;
	m_bayPrintLevel = 0;
} 


void CPrintCtrl::PrintAllMsg()
{
	//m_bPrintAllMsg = TRUE;
    m_bayPrintLevel = 2;
}
 
void CPrintCtrl::PrintMsgLevel( u8 abyLevel )
{
   m_bayPrintLevel = abyLevel;
   m_bPrintAllMsg = FALSE;
}

void CPrintCtrl::PrintEnterMsg(  BOOL bPrint  )
{
	m_bPrintEnterMsg = bPrint;
}

BOOL CPrintCtrl::IsPrintEnterMsg()
{
	return m_bPrintEnterMsg;
}

void CPrintCtrl::PrintOutMsg(  BOOL bPrint  ) 
{
	m_bPrintOutMsg = bPrint;
}


BOOL CPrintCtrl::IsPrintOutMsg()
{
	return m_bPrintOutMsg;
}


void CPrintCtrl::SetPrintMsgID( const u32 dwPrintEventId )
{
	m_dwPrintMsgID = dwPrintEventId;
} 

 
BOOL32 CPrintCtrl::IsPrintMsg( const u16 dwMsgID )
{ 
	if ( m_bPrintAllMsg )
	{
		return TRUE;
	}

	if ( m_dwPrintMsgID == dwMsgID)
	{
		return TRUE;
	}

	if ( m_dwPrintRangeMin <= dwMsgID 
		&& dwMsgID <= m_dwPrintRangeMax) 
	{
		return TRUE;
	} 

   map<u16, u8>::iterator itr = m_mapEventLevel.find(dwMsgID);
   if(itr != m_mapEventLevel.end())
   {  	
	   if ( m_bayPrintLevel >= (*itr).second )
	   {
		   return TRUE;
	   } 
   }  
   //���dwMsgID ����Ҫ��ӡ�����ͣ��򷵻�TRUE�� �ò�����Ҫ���ⲿ��дʵ��
   return FALSE;
}

BOOL32 CPrintCtrl::IsPrintMsgBdy() 
{
	return m_bPrintMsgBdy;
}

void CPrintCtrl::SetPrintMsgRange( const u32 dwMaxMsgID, const u32 dwMinMsgID )
{
	m_dwPrintRangeMax = dwMaxMsgID;
	m_dwPrintRangeMin = dwMinMsgID;
}
 


void CPrintCtrl::ResumeMem()
{
	m_dwPrintMsgType = 0;   //Ҫ��ӡ����Ϣ����
	m_dwPrintMsgID = 0 ;     //Ҫ��ӡ����Ϣ��
	m_dwPrintRangeMax = 0;  //Ҫ��ӡ����Ϣ��Χ �е����ֵ
	m_dwPrintRangeMin = 0;  //Ҫ��ӡ����Ϣ��Χ �е���Сֵ 
    m_pPrtCtrl = 0;
}

 
void CPrintCtrl::MappingHelper(u16 wEvent, const CString& strName, u8 abyLevel )
{
    m_mapEventsName[wEvent] = strName;
    m_mapEventLevel[wEvent] = abyLevel;
}




CString  CPrintCtrl::GetEventDescribe( u16 wEvent )
{  
	CString str = "";
	map<u16, CString>::iterator itr = m_mapEventsName.find(wEvent);
    if(itr != m_mapEventsName.end())
	{
        str = (*itr).second; 
	}

	return str;
}

 


CString CPrintCtrl::GetEventTypeDescribe(EmEventType emType )
{
    CString str = " ";
    switch(emType) 
    {
    case emEventTypeUms:
		str = "[UMS ��Ϣ]";
		break;
    case emEventTypeCns:
		str = "[CNS ��Ϣ]";
		break;
    case emEventTypeUmsSend:
		str = "[���� UMS ��Ϣ]";
		break;
    case emEventTypeUmsRecv:
		str = "[�յ� UMS ��Ϣ]";
		break; 
    case emEventTypeCnsSend:
		str = "[���� CNS ��Ϣ]";
		break;
    case emEventTypeCnsRecv:
        str = "[�յ� CNS ��Ϣ]";
        break; 
    case emEventTypeCmsWindow:
        str = "[�����ӡ]";
        break;
    case emEventTypeUmstoolSend:
        str = "[���� UMS ��Ϣ]";
        break; 
    case  emEventTypeUmstoolRecv:
        str = "[�յ� UMS ��Ϣ]";
	    break;
    case emEventTypeTPadSend:
        str = "[���� TPad ��Ϣ]";
        break; 
    case emEventTypeTPadRecv:
        str = "[�յ� TPad ��Ϣ]";
        break;
	case emEventTypecnstoolSend:
        str = "[���� CNS ��Ϣ]";
        break; 
    case  emEventTypecnstoolRecv:
        str = "[�յ� CNS ��Ϣ]";
	    break;
    default:
        ;
    }

    return str;
}

u8 CPrintCtrl::GetPrintLevel()
{
	return m_bayPrintLevel;
}




