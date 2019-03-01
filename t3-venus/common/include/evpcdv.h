/*****************************************************************************
   ģ����      : PCDV
   �ļ���      : evpcdv.h
   ����ļ�    : 
   �ļ�ʵ�ֹ���: PCDV �ڲ���Ϣ����
   ����        : 
   �汾        : V4.0  Copyright(C) 2004-2007 KDC, All rights reserved.
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���      �޸�����
   2006/12/31  4.0         ����      ����
******************************************************************************/


#ifndef EVPCDV_H
#define EVPCDV_H

#include "osp.h"

#define EVPCDV_BEGIN            (WM_USER+976)       // 2000

// �����ն�
OSPEVENT( UI_SSN_CONNECT_REQ    ,      (EVPCDV_BEGIN + 1) );
OSPEVENT( SSN_UI_CONNECT_ACK    ,      (EVPCDV_BEGIN + 2) );
OSPEVENT( SSN_UI_CONNECT_NACK   ,      (EVPCDV_BEGIN + 3) ); // ��Ϣ��:CUIMsg*, ��������

// ��ʼ˫��
OSPEVENT( UI_SSN_STARTDUAL_REQ  ,      (EVPCDV_BEGIN + 6) );
OSPEVENT( SSN_UI_STARTDUAL_ACK  ,      (EVPCDV_BEGIN + 7) );
OSPEVENT( SSN_UI_STARTDUAL_NACK ,      (EVPCDV_BEGIN + 8) );

// ֹͣ˫��
OSPEVENT( UI_SSN_STOPDUAL_REQ   ,      (EVPCDV_BEGIN + 11) );
OSPEVENT( SSN_UI_STOPDUAL_ACK   ,      (EVPCDV_BEGIN + 12) );
OSPEVENT( SSN_UI_STOPDUAL_NACK  ,      (EVPCDV_BEGIN + 13) );

// �Ҷ��ն�
OSPEVENT( UI_SSN_LOGOUT_REQ     ,      (EVPCDV_BEGIN + 16) );

// ���沶׽����
OSPEVENT( UI_SSN_CAPTEST_CMD    ,      (EVPCDV_BEGIN + 19) );
OSPEVENT( SSN_UI_CAPTEST_PROGNOTIF,    (EVPCDV_BEGIN + 20) );

OSPEVENT( SSN_UI_MTPARAMCHANGED_NOTIF, (EVPCDV_BEGIN + 21) );

// ��ʱ��
OSPEVENT( CONNECTMT_TIMER       ,      (EVPCDV_BEGIN + 31) );
OSPEVENT( REQUEST_TIMER         ,      (EVPCDV_BEGIN + 32) );   

//˫���ֱ����ն˺�pc����һֱ
OSPEVENT(DIFF_RES_BETWEEN_MTANDPC,     (EVPCDV_BEGIN + 33) );

#define  PCDV_MSG_END                  (EVPCDV_BEGIN + 50)

#endif //EVPCDV_H