/*=============================================================================
ģ   ��   ��: vcs��pcmt����ͷ�ļ�
��   ��   ��: evvcspcmt.h 
�� ��  �� ��: 
�ļ�ʵ�ֹ���: ��Ҫ����Ϣ�Ŷ���
��        ��: �½���
ע        ��: Ŀǰvcs������ÿ�գ���pcmt��r5�����Ը��ļ�Ҫ�͸���ÿ���ϵ���Ӧ�ļ�����һ��
��        ��: V1.0  Copyright(C) 2003-2009 KDC, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2009/07/14  1.0     �½���        ����
=============================================================================*/

#ifndef _EVMTCVCS_H_
#define _EVMTCVCS_H_


#include "osp.h"

const int    AID_VCSLIB          =   100;   //��app�Ų��ܺ�mcu�������app��ͬ,fix
const int    AID_PCMTLIB         =   150;   //��app�Ų��ܺ�mt�������app��ͬ 
        
/*Pcmtlib��VCSͨ����Ϣ(0-100) */
#define EV_PCMTVCS_BGN                  0
#define EV_PTMTVCS_END                  EV_PCMTVCS_BGN + 100

/*------------------------------------------------------------------------------
 PCMTLIB��VCSLIB�ӿ���Ϣ(1-99)
------------------------------------------------------------------------------*/
//body: none
OSPEVENT( VCS_PCMT_CONNECT_REQ,                         EV_PCMTVCS_BGN + 1 );
OSPEVENT( PCMT_VCS_CONNECT_ACK,                         EV_PCMTVCS_BGN + 2 );

OSPEVENT( VCS_PCMT_POWEROFF_CMD,                        EV_PCMTVCS_BGN + 3 );

//body:Ҫ���Ƶ�HWND hPreview + HWND hPrimo + HWND hSecond
OSPEVENT( VCS_PCMT_SETVCSHWND_CMD,                      EV_PCMTVCS_BGN + 4 );

//body:none
OSPEVENT( PCMT_VCS_ENTRY_CONF_NOTIFY,                   EV_PCMTVCS_BGN + 5 );

//body:none
OSPEVENT( VCS_PCMT_QUITCONF_CMD,                        EV_PCMTVCS_BGN + 6 );

//body:u8 ��ֵ������pcmt���Ӧ��ģʽö��ֵ��ͬ
OSPEVENT( VCS_PCMT_SETANSWERMODE_CMD,                   EV_PCMTVCS_BGN + 7 );

//body:none pcmt֪ͨvcs���˳�������
OSPEVENT( PCMT_VCS_QUITCONF_NOTIFY,                     EV_PCMTVCS_BGN + 8 );

//body:none ��Ϣ��:CammerCtrID(4�ֽ�) + CtrState(4�ֽ�)
OSPEVENT( VCS_PCMT_SET_CAMMER_CMD,                      EV_PCMTVCS_BGN + 9 );

//body:none 
OSPEVENT( VCS_PCMT_CTR_CAMMER_PRE_CMD,                  EV_PCMTVCS_BGN + 10 );

//body:none 
OSPEVENT( PCMT_VCS_INITOK_NOTIFY,				        EV_PCMTVCS_BGN + 11 );
/*------------------------------------------------------------------------------
 PCMTLIB��VCSLIB���õĺ�
------------------------------------------------------------------------------*/
#define VCSLIB_LISTEN_PORT                      60100  
#define PCMTLIB_LISTEN_PORT                     60200 

enum emCammerCtrID
{
	emCtrBgn,
    emCtrUP,
    emCtrDown,
    emCtrLeft,
    emCtrRight,
    emCtrFocusAuto,
    emCtrFocusFar,
    emCtrFocusNear,
    emCtrZommOut,
    emCtrZoomIn,
    emCtrBrightLow,
    emCtrBrightHigh,   
};

typedef struct tagCammeralCtr 
{
	tagCammeralCtr(emCammerCtrID emCtrId=emCtrBgn, BOOL32 bCtrState=FALSE): m_emCtrId(emCtrId), m_CtrState(bCtrState) {};

	emCammerCtrID	m_emCtrId;
	BOOL32			m_CtrState;

}TCammeralCtr;

#endif