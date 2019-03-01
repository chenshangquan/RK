#ifndef _VCSLIBCOM_H_
#define _VCSLIBCOM_H_

#if _MSC_VER > 1000
#pragma once
#endif

#include "kdvtype.h"
#include "evvcspcmt.h"
#include "evmcslib.h"

//vcslib��Ϣ
enum emVcsLibUIMsg
{
    em_VcsLibUIMsgBgn   =   VCSLIB_DISP_MSG_BGN,

    VCSLIB_VCS_PCMTCONNECTED_ACK,
    VCSLIB_VCS_PCMTENTRYCONF_NOTIFY,
	VCSLIB_VCS_PCMTQIUTCONF_NOTIFY,
	VCSLIB_VCS_PCMTDISCONNECT_NOTIFY,
	VCSLIB_VCS_PCMTINITOK_NOTIFY,

    em_VcsLibUIMsgEnd = VCSLIB_DISP_MSG_END,
};

//pcmt��Ӧ��ʽ����
enum EmTripMode
{
    emTripModeAuto      =0,  //�Զ�
	emTripModeManu      =1,  //�ֶ� 
	emTripModeNegative  =2,   //�ܾ����ر�
};



//ȫ�ֺ�������    
u16 InitVcslib(BOOL32 bOpenTelnet = FALSE);



#endif/*_VCSLIBCOM_H_*/
