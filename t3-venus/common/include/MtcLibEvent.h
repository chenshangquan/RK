/*****************************************************************************
ģ����      : �ն˿���̨
�ļ���      : MtcLibEvent.h
����ļ�    : 
�ļ�ʵ�ֹ���: ������Ϣ����
����        : �ܹ㻯
�汾        : V3.0  Copyright(C) 1997-2003 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2003/12/16  3.0         �ܹ㻯      ����
*******************************************************************************/
#pragma once

/* ժ��eventid.h
�ն˿���̨�ڲ���Ϣ(12001-13000)
#define EV_MTC_BGN	EV_MC_END + 0x001
#define EV_MTC_END	EV_MTC_BGN + 0x3E7*/
#include "eventid.h"	// ��Ϣ�뷶Χ�ζ���

#define MTC_SYS_MSG_BEGIN		EV_MTC_BGN + 0x000


///////////////////////////////////////////////////////////////////////////////

enum EmMtcSysMsg
{
	/************************************************************************/
	/* mtc �������ն�
	  wparam = 0
	  lparam = 0*/
	/************************************************************************/
	ev_MtcUIConnect		=	MTC_SYS_MSG_BEGIN,
#define		MTC_UI_CONNECTED  ev_MtcUIConnect
	/************************************************************************/
	/* �ѶϿ��ն�
	 wParam = 0
	 lparam = 0*/
	/************************************************************************/
	ev_MtcUIDisconnected,
#define MTC_UI_DISCONNECTED	 ev_MtcUIDisconnected
	/************************************************************************/
	/* �ն�״̬����
	lparam = 0
	wparam = 0*/
	/************************************************************************/
	ev_MtcUIMtStatusUpdated,
#define MTC_UI_MTSTATUS_UPDATED  ev_MtcUIMtStatusUpdated
	/************************************************************************/
	/* �ն˴���֪ͨ
	wparam			MT_SLEEP/MT_WAKEUP	��������
	lparma = 0*/
	/************************************************************************/
	ev_MtcUIDemancyInfo,
#define MTC_UI_DORMANCY_INFO       ev_MtcUIDemancyInfo
	/************************************************************************/
	/* ������Ϣ֪ͨ
	wParam = 0
	lparam = 0
	*/
	/************************************************************************/
	ev_MtcUISnapshotUpdated,
#define MTC_UI_SNAPSHOT_UPDATED	 	ev_MtcUISnapshotUpdated
	/************************************************************************/
	/* GK ע��״̬֪ͨ
	 wparam = Trus/False  �ɹ�/ʧ��*/
	/************************************************************************/
	ev_MtcUIGKRegistInd,

	ev_MtcUISerialNumber,

	/************************************************************************/
	/* PCMT���ݻ���������Ӧ֪ͨ
	 wparam = Trus/False  TRUE,����;FALSE,������
	/************************************************************************/
	ev_MtcUIPcmtDataConfRspInd,
#define MTC_UI_PCMT_DATACONF_RSP	 	ev_MtcUIPcmtDataConfRspInd

	/************************************************************************/
	/* PCMT���ݻ�����������֪ͨ
	 wparam = Trus/False  TRUE,����;FALSE,������
	/************************************************************************/
	ev_MtcUIPcmtDataConfReqInd,
#define MTC_UI_PCMT_DATACONF_REQ	 	ev_MtcUIPcmtDataConfReqInd
	/************************************************************************/
	/*    �忨����֪ͨ         
	 wparam    emMtModel
	 lparam		= 0*/
	/************************************************************************/
	ev_MtcUIMtBoardUpdated,

	/************************************************************************/
	/* �ն�������Ӧ
	wparam = True   ͬ��  False  ��ͬ��
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIUpdateSysAck,

#define MTC_UI_MTBOARD_UPDATED   ev_MtcUIMtBoardUpdated

	/************************************************************************/
	/* �ն������Ƿ�ɹ�
	wparam = True   �ɹ�  False  ���ɹ�
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIUpdateSysInd,
#define MTC_UI_UPDATESYS_IND   ev_MtcUIUpdateSysInd

	/************************************************************************/
	/*  �ն��û��б����
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIUserUpdated,
#define MTC_UI_USERS_UPDATED  ev_MtcUIUserUpdated
	/************************************************************************/
	/*   ��ʼ���ͽ�����Ƶ�� u32 u32RtpIP u16 u16RtpPort
	wpram		���������˫��Ϊu32RptIP	RTPĿ��IP��ַ ����0
	lparam		���������˫��Ϊu16PrtPort	RTPĿ�Ķ˿�   ����0
	�ϲ����������ж�˫������*/
	/************************************************************************/
	ev_MtcUIStartSnap,
#define MTC_UI_STARTSNAP			ev_MtcUIStartSnap
	/************************************************************************/
	/* ֹͣ���ͽ�����Ƶ��(˫��)                                                                     */
	/************************************************************************/
	ev_MtcUIStopSnap,
#define MTC_UI_STOPSNAP				ev_MtcUIStopSnap
	/************************************************************************/
	/*   ˫��Ƶ��״ָ̬ʾ
	  wparam		True / False 
	  lparam		0    (�Ѿ�����) */
	/************************************************************************/
	ev_MtcUIDualVInd,
#define MTC_UI_DUALV_IND		ev_MtcUIDualVInd
	/************************************************************************/
	/*  �����ı�	BOOL bInput, u32 dwVolume
	 wparam �����뻹�����(true ����, false ���) 
	 lparam  u32 ����*/
	/************************************************************************/
	ev_MtcUIVolChanged,
#define MTC_UI_VOLUME_CHANGED   ev_MtcUIVolChanged
	/************************************************************************/
	/* ��������  BOOL bSilent, BOOL bOn
	wparam bSilent	�Ǿ�����������.����ָ�ر���Ƶ�ź����,����ָ�ر���Ƶ�ź�����
	lparam bOn		�ǿ������ǹر�.��������ʹ��ǰû����Ƶ���,��֮�ǹرվ���*/
	/************************************************************************/
	ev_MtcUISlientAndMute,
#define MTC_UI_SILENT_AND_MUTE		ev_MtcUISlientAndMute

	/************************************************************************/
	/* Զ��ң�� BOOL bEnable  
	wparam  bEnable	�ǿ������ǽ��� */
	/************************************************************************/
	ev_MtcUIbFECC,
#define MTC_UI_REMOTE_CONTROL    ev_MtcUIbFECC

	/************************************************************************/
	/* ��ַ���ı�  BOOL bEntry     
	wparam bEntry  ����Ŀ������Ŀ��*/
	/************************************************************************/
	ev_MtcUIAddrChanged,
#define MTC_UI_ADDRBOOK_CHANGED		ev_MtcUIAddrChanged

	/************************************************************************/
	/* �Ի�����֪ͨ 
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUISelfCircleTest,
#define MTC_UI_CIRCLETEST		ev_MtcUISelfCircleTest

	/************************************************************************/
	/* Զ�˻��ز���֪ͨ 
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIRemoteLoopBackTest,
#define MTC_UI_REMOTE_LOOP_BACK_TEST		ev_MtcUIRemoteLoopBackTest

	ev_MtcUIGKUnRegistInd,

	ev_MtcUISysMsgEnd
};



enum EmMtcMatrixMsg
{
	ev_MtcMatrixMsgBegin = ev_MtcUISysMsgEnd + 1,

	/************************************************************************/
	/*��ǰӦ�þ������÷����Ÿ��� 
	lparam 0
	wparam 0*/
	/************************************************************************/
	ev_MtcUIMatrixCurSchemeUpdated,
#define MTC_UI_MATRIX_UPDATED		ev_MtcUIMatrixCurSchemeUpdated
	/************************************************************************/
	/*  ���󷽰����ݸ���
	lparam 0
	wparam 0*/
	/************************************************************************/
	ev_MtcUIMatrixSchemeUpdated,
#define MTC_UI_MATRIX_SCHEME		ev_MtcUIMatrixSchemeUpdated
	/************************************************************************/
	/* ����������Ϣ����
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIExMatrixCfgUpdated,
#define MTC_UI_EXMATRIX_UPDATED   ev_MtcUIExMatrixCfgUpdated
	/************************************************************************/
	/* �ⲿ������Ϣ����ָʾ   
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIExMatrixInfoUpdated,
#define MTC_UI_EXMATRIX_INFO_UPDATED	ev_MtcUIExMatrixInfoUpdated
	
	/************************************************************************/
	/* �ⲿ�������ӹ�ϵ��ָʾ
	wparam = u8    ����˿ڵ�index (0����)
	lparam = 0 */
	/************************************************************************/
	ev_MtcUIExVSourceUpdated,

	MTC_UI_EXMATRIX_NOTIFY,


	MTC_UI_AUDIOMATRIX,//��Ƶ����
	ev_MtcMatrixMsgEnd
};


enum EmMtcP2PMsg
{
	ev_MtcP2PMsgBegin = ev_MtcMatrixMsgEnd + 1,
	
	/************************************************************************/
	/* ��Ե���鿪ʼ 
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIP2PStarted,
#define MTC_UI_P2P_STARTED		ev_MtcUIP2PStarted
	/************************************************************************/
	/*��Ե����ȡ�� 
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIP2PCanceled,
#define MTC_UI_P2P_CANCELED   ev_MtcUIP2PCanceled
	/************************************************************************/
	/*��Ե�������
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIP2PEnd,
#define MTC_UI_P2P_ENDED			ev_MtcUIP2PEnd
	/************************************************************************/
	/* ��Ե���鱻����
	wparam	u32 dwip  �����˵�IP��ַ
	lparam  TCHAR * tszAlias  �����˵ı���
	*/
	/************************************************************************/
	ev_MtcUIP2PBeCalled,
#define MTC_UI_P2P_CALLED			ev_MtcUIP2PBeCalled
	/************************************************************************/
	/* ���鱻��չ 
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIP2PExpanded,
#define MTC_UI_P2P_EXPANDED			ev_MtcUIP2PExpanded
	/************************************************************************/
	/* ��Ե���鲻��ԭ����ֹ
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIP2PDiscard,
#define MTC_UI_P2P_DISCARD			ev_MtcUIP2PDiscard

	/************************************************************************/
	/* �ն����ں���
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIP2PCalling,
#define MTC_UI_P2P_CALLING			ev_MtcUIP2PCalling

	ev_MtcP2PMsgEnd
};


enum EmMtcMConfMsg
{
	ev_MtcMConfMsgBegin = ev_MtcP2PMsgEnd + 1,
	/************************************************************************/
	/* �����鿪ʼ 
	wparam = dwIp		�Զ˵�IP��ַ(������)
	lparam =			�Զ˵ı���*/
	/************************************************************************/
	ev_MtcUIConfStarted,
#define MTC_UI_CONF_STARTED			ev_MtcUIConfStarted
	/************************************************************************/
	/* �����˸ı�
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUISpeakerChanged,
#define MTC_UI_SPEAKER_CHANGED		ev_MtcUISpeakerChanged
	/************************************************************************/
	/*��ϯ�ı�  
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIChairmanChanged,
#define MTC_UI_CHAIRMAN_CHANGED		ev_MtcUIChairmanChanged
	/************************************************************************/
	/*����ն˸ı� 
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIConfMtListChanged,
#define MTC_UI_MT_CHANGED			ev_MtcUIConfMtListChanged
	/************************************************************************/
	/*����mc�����ն�ʧ����ʾ 
	wparam = ��������
	lparam = 0*/
	/************************************************************************/
	ev_MtcMCIllegalCallInd,
#define MTC_MC_CALL_RESULT          ev_MtcMCIllegalCallInd        
	/************************************************************************/
	/* ��ϯ����
	wparam = 0��
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIConfLostChairman,

	/************************************************************************/
	/*���ն��ύ����  
	wparam = ��������
	ev_ConfApplySpeakReq | ev_ConfApplyChairInInd |ev_ConfApplyChimeInInd
	lparam dwMcuMtId	32����McuMt���ϱ�ʶ*/
	/************************************************************************/
	ev_MtcUIConfRequsting,
#define MTC_UI_MT_REQUSTING			ev_MtcUIConfRequsting
	/************************************************************************/
	/* �뿪���� 
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIConfLeave,
#define MTC_UI_CONF_LEAVE			ev_MtcUIConfLeave
	/************************************************************************/
	/*���鼴������
	wparam = dwDelay	���ж��ٷ��ӻ������
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIConfWillEnd,
#define MTC_UI_CONF_BEFORE_END		ev_MtcUIConfWillEnd
	/************************************************************************/
	/* �����б��Ѹ��� 
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIConfListUpdated,
#define MTC_UI_CONFLIST_UPDATED		ev_MtcUIConfListUpdated
	/************************************************************************/
	/*  ���鱻ȡ��
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIConfCanceled,
#define MTC_UI_CONF_CANCELED		ev_MtcUIConfCanceled
	/************************************************************************/
	/* ������Ϣ����
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIConfInfoUpdated,
#define MTC_UI_CONFINFO_UPDATED		ev_MtcUIConfInfoUpdated
	/************************************************************************/
	/* Զ����ƵԴ�л�֪ͨ
	wparam dwMcuMtId               32���ص�McuMt���ϱ�ʶ
	lparam 0*/
	/************************************************************************/
	ev_MtcUIConfVSrcChange,
#define MTC_UI_CONF_VRSRC			ev_MtcUIConfVSrcChange
	/************************************************************************/
	/* ��ѯ������ѯ���� 
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIConfPollUpdated,
#define MTC_UI_CONFPOLL_UPDATED		ev_MtcUIConfPollUpdated
	/************************************************************************/
	/*����ģʽ��� 
	wparam = BOOL bDiscuss      �Ƿ�����������
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIConfDiscussUpdated,
#define MTC_UI_DISCUSS_UPDATED		ev_MtcUIConfDiscussUpdated
	/************************************************************************/
	/* Ҫ��������� 
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIConfReqPwd,
#define MTC_UI_CONFPWD				ev_MtcUIConfReqPwd
	/************************************************************************/
	/*����ն�֪ͨ 
	 wparam CAuxMonParam
	 ˵��	����Ϣ��Send��*/
	/************************************************************************/
	ev_MtcUIConfMonMt,
#define MTC_UI_MONMT				ev_MtcUIConfMonMt
	/************************************************************************/
	/* ��Ƶ���ϲ����ѻ�ȡ֪ͨ  
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIConfGetVMPParamInd,
#define MTC_UI_VMP					ev_MtcUIConfGetVMPParamInd
	/************************************************************************/
	/*�ն�״̬֪ͨ��Ϣ  
	wparam &TMtId
	lparam &TMtStatus*/
	/************************************************************************/
	ev_MtcUIConfOtherTerStatusInd,
#define MTC_UI_CONF_MTSTATUS		ev_MtcUIConfOtherTerStatusInd
	/************************************************************************/
	/*ǿ���ն��Ƴ� (�����ն�ʧ��)
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIConfDropTerFailed,
#define MTC_UI_CONF_DROPTERREJECT_IND	ev_MtcUIConfDropTerFailed
	/************************************************************************/
	/* ��ϯ�����ն�ʧ��
		wparam				dwMcuMtId
		lparam				0*/
	/************************************************************************/
	ev_MtcConfInviteFailedInd,
#define MTC_UI_INVITEMT_FAILED		ev_MtcConfInviteFailedInd
	/************************************************************************/
	/* �յ�����Ϣ
	wparam dwMcuMtId
	lparam ptstrMsg	�յ�����Ϣ,�����β���ִ�,λ����ʱ������
	˵��	����Ϣ���ͳ�(SendMessage)*/
	/************************************************************************/
	ev_MtcUIConfRecSMSInd,
#define MTC_UI_SHORT_MSG_RECVED		ev_MtcUIConfRecSMSInd
/************************************************************************/
	/*  ��������ʧ�� u32 dwEventId
	 wparam = dwEventId		��������ID,�μ�MtEvent.h
	 lparam = 0*/
	/************************************************************************/
	ev_MtcUICmdFailed,
#define MTC_UI_CMD_FAILED		ev_MtcUICmdFailed
	/************************************************************************/
	/* ��������ɹ�  
	wparam = dwEventId		��������ID,�μ�MtEvent.h
	lparam = 0*/
	/************************************************************************/
	ev_MtcUICmdSuccess,
#define MTC_UI_CMD_SUCCESS		ev_MtcUICmdSuccess	
	/************************************************************************/
	/* �������ʱ u32 dwEventId 
	wparam = dwEventId		��������ID,�μ�MtEvent.h
	lparam = 0*/
	/************************************************************************/
	ev_MtcUICmdTimeOut,
#define MTC_UI_CMD_TIMEOUT		ev_MtcUICmdTimeOut
	/************************************************************************/
	/* �ն˱�ʾ����ָʾ
	 wparam McuMtId*/
	/************************************************************************/
	 ev_MtcUIConfLabelAssign,
	 /************************************************************************/
	 /* ����������Ӧ
	  wparam =  True ͬ��   False 
	  lparam = 0*/
	 /************************************************************************/
	ev_MtcUIConfStartVACRsp,
	ev_MtcUIConfStopVACRsp,
	/************************************************************************/
	/*  �������ۻ�Ӧ
	wparam = True   ͬ��  False  ��ͬ��
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIConfStartDiscussRsp,
	ev_MtcUIConfStopDiscussRsp,
	/************************************************************************/
	/* VMP��ʼ��Ӧ 
	wparam = True   ͬ��  False  ��ͬ��
	lparam = 0*/
	/************************************************************************/
	ev_MtcUIConfStartVMPRsp,
	ev_MtcUIConfStopVMPRsp,
	/************************************************************************/
	/* ����VMP������Ӧ
	wparam = True   ͬ��  False  ��ͬ��
	lparam = 0*/
	/************************************************************************/
	ev_MtcUISetVMPParamRsp,
	/************************************************************************/
	/* ����ͬ����Ϣ  ����ͬ��OSD��MTC��״̬
	  wparam = 0
	  lparam = 0*/
	/************************************************************************/
	ev_MtcUISynNotify,

	/************************************************************************/
	/* PC ˫����������ϱ�
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcPCDualEncodeParamInd,
	/************************************************************************/
	/* PC ˫�����������������
	wparam = ����
	lparam = 0*/
	//add by fangdi for ����˫����������
	/************************************************************************/
	ev_MtcPcDualEncodeSetBitRate, 
	/************************************************************************/
	/* PC ˫����̬�غɺ���Կָʾ
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcPCDualEncryptInd,
	/************************************************************************/
	/* PC ˫����ʼ����ָʾ
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcPCDualEncodeStartInd,
	/************************************************************************/
	/* ��ʼ����˫��ָʾ
	wparam = True ��ʼ / false ֹͣ
	lparam = 0*/
	/************************************************************************/
	ev_MtcRecvDualInd,
	/************************************************************************/
	/* ���к�������ָʾ
	wparam = True �ɹ� / false ʧ��
	lparam = 0*/
	/************************************************************************/
    ev_MtcUISiteCallSuccess,
#define MTC_UI_SITE_CALL_SUCCESS    ev_MtcUISiteCallSuccess

    ev_MtcMcCallIncommingInd,
#define MTC_UI_MC_CALL_INCOMMING    ev_MtcMcCallIncommingInd

    ev_MtcMcCapStateInd,
#define MTC_UI_MC_CAPSTATE  ev_MtcMcCapStateInd

    ev_MtcMcDiscussMmbInd,
#define MTC_UI_MC_DISCUSS_MMB  ev_MtcMcDiscussMmbInd

    ev_MtcMcFeccTermInd,
#define MTC_UI_MC_FECC_TERM  ev_MtcMcFeccTermInd

    ev_MtcMcModeCfgInd,
#define MTC_UI_MC_MODE_CFG  ev_MtcMcModeCfgInd

    ev_MtcMcVMPCfgInd,
#define MTC_UI_MC_VMP_CFG  ev_MtcMcVMPCfgInd

    ev_MtcMcSetVMPStyleInd,
#define MTC_UI_MC_SET_VMP_STYLE  ev_MtcMcSetVMPStyleInd

    ev_MtcMcPollInd,
#define MTC_UI_MC_POLL  ev_MtcMcPollInd

	ev_MtcmcViewInd,
#define MTC_UI_MC_VIEW   ev_MtcmcViewInd
    ev_MtcMcMtJoin,
#define MTC_UI_MC_MT_JOIN  ev_MtcMcMtJoin

    ev_MtcMcMtLeave,
#define MTC_UI_MC_MT_LEAVE  ev_MtcMcMtLeave

	/************************************************************************/
	/* FEC����ָʾָʾ
	wparam = m_byFecCapacity 0,1,2
	lparam = 0*/
	/************************************************************************/
	ev_MtcFecCapacity,
#define MTC_UI_FEC_CAPACITY ev_MtcFecCapacity

	MTC_UI_CONF_POLLSCHEME,


	//���ƻ���
	//	ev_ConfStartMixRsp,
#define MTC_UI_STARTMIXRSP ev_ConfStartMixRsp
	
	//	ev_ConfStopMixRsp,
#define MTC_UI_STOPMIXRSP  ev_ConfStopMixRsp
	
	//	ev_ConfMixParamInd,
#define MTC_UI_SELMTSMIXAUDIOIND ev_ConfMixParamInd

	ev_MtcConfMsgEnd

};



enum emMtcVODMsg
{
	ev_MtcVODMsgBegin = ev_MtcConfMsgEnd + 1,
		
	/************************************************************************/
	/* Vod ���ڵ�½ָʾ
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcVodLoging,
	/************************************************************************/
	/* Vod �ļ��б����ָʾ
	   wParam = 0
	   lparam = 0*/
	/************************************************************************/
	ev_MtcVODFileListUpdate, 
	/************************************************************************/
	/* Vod �ļ���Ϣ����ָʾ
		wParam = 0
		lParam = 0*/
	/************************************************************************/
	ev_MtcVODFileInfoUpdate,
	/************************************************************************/
	/* Vod �ļ�������Ϣָʾ����
		wparam = m_dwDuration   �����ļ���ʱ�������룩;
		lparam = m_dwPlayTime   �Ѿ������ļ��ĳ��ȣ����룩*/
	/************************************************************************/
	ev_MtcVODFilePlayInfoUpdate, 
	//vod ��½���˳���ͬ����Ϣָʾ
	ev_MtcVODLoginSys,
	ev_MtcVODLogOutSys,

	/************************************************************************/
	/* Vod �ļ���ϸ�����ļ��б�����
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcVodReqing,
	/************************************************************************/
	/* Vod ֹͣ������Ϣ ��֪ͨ������Ϊ�ǵȴ���״̬                                                                    */
	/************************************************************************/
	ev_MtcVodEndReq,
	/************************************************************************/
	/* Vod ״ָ̬ʾ����Ҫ������֪ͨ��������֮�����Խ��л������	
	wparam = True ��vod / False ����
	lparam vod�Ĳ���״̬*/
	/************************************************************************/
	ev_MtcVodStateInd,

	ev_MtcCamControlSourceInd,
	ev_MtcCamNumInd,
	/************************************************************************/
	/* ������ƵԴ�����Ƹı�                                                                     */
	/************************************************************************/
	ev_MtcCamNameChangeInd,

	ev_MtcCamAutoDualSrcInd,

	ev_MtcVODMsgEnd
};

enum EmMtcCfgMsg
{
	/************************************************************************/
	/*������Ϣ��ʼ*/
	/************************************************************************/
	ev_emMtcCfgMsgBegin = ev_MtcVODMsgEnd + 1,
	/************************************************************************/
	/*H323 ������Ϣ����                                                     
	/************************************************************************/
	ev_emUICfgH323Updated,
#define MTC_UI_CFGH323_UPDATED			ev_emUICfgH323Updated

	/* ��̫��������Ϣ 
		����	wParam  ��̫�������������� 
				lparam   0*/
	ev_emUICfgEthnetUpdated,
#define MTC_UI_CFGETHNET_UPDATED		ev_emUICfgEthnetUpdated

	/* �û�������Ϣ����*/
	ev_emUICfgUserUpdated, 
#define MTC_UI_CFGUSER_UPDATED			ev_emUICfgUserUpdated

	/* ��Ƶ������Ϣ����
	����	wParam	��Ƶ�������������  EmVideoType
			lParam	0*/
	ev_emUICfgVideoUpdated,
#define MTC_UI_CFGVIDEO_UPDATED			ev_emUICfgVideoUpdated

	/* ��Ƶ������Ϣ����*/
	ev_emUICfgAudioUpdated,
#define MTC_UI_CFGAUDIO_UPDATED			ev_emUICfgAudioUpdated

	/* ����/�����ش���Ϣ����*/
	ev_emUICfgRetransUpdated,
#define MTC_UI_CFGRETRANS_UPDATED		ev_emUICfgRetransUpdated
	
	/* ǰ�����*/
	ev_emCfgFecTypeUpdated,
#define MTC_UI_CFGFECTYPE_UPDATED     ev_emCfgFecTypeUpdated

	ev_emUICfgSoundPriorityUpdated,
#define MTC_UI_CFGSOUNDPRIORITY_UPDATED ev_emUICfgSoundPriorityUpdated

	/* ͼ��������Ϣ����*/
	ev_emUICfgImageUpdated,
#define MTC_UI_CFGIMGEQ_UPDATED			ev_emUICfgImageUpdated

	/* ���ӻ���ʽ���ø���*/
	ev_emUICfgVidDisplayFrmUpdated,
#define MTC_UI_CFGVIDDISPLAYFRM_UPDATED			ev_emUICfgVidDisplayFrmUpdated

	/* OSD��Ϣ����*/
	ev_emUICfgOsdUpdated,
#define MTC_UI_CFGOSD_UPDATED			ev_emUICfgOsdUpdated

	/* �ڶ�·��Ƶ�����VGA��Ϣ����*/
	ev_emUICfgSecondVideoToVGAUpdated,
#define MTC_UI_CFGSECONDVIDEOTOVGA_UPDATED  ev_emUICfgSecondVideoToVGAUpdated
    
	/* SNMP������Ϣ����*/
	ev_emUICfgSnmpUpdated,
#define MTC_UI_CFGSNMP_UPDATED			ev_emUICfgSnmpUpdated

	/* AEC������Ϣ*/
	ev_emUICfgAecUpdated,
#define MTC_UI_CFGAEC_UPDATED			ev_emUICfgAecUpdated

	/* ��ý��������Ϣ*/
	ev_emUICfgStreamUpdated,
#define MTC_UI_CFGSTREAM_UPDATED		ev_emUICfgStreamUpdated

	/* ����ͷ����*/
	ev_emUICfgCameraUpdated,
#define MTC_UI_CFGCAMERA_UPDATED		ev_emUICfgCameraUpdated

	/* ��Ƶ�������*/
	ev_emUICfgVidoeOutUpdated,
#define MTC_UI_CFGVIDEOOUT_UPDATED		ev_emUICfgVidoeOutUpdated

	ev_emUICfgVideoSourceUpdated,

	/*Ĭ����������*/
	ev_emUICfgGatewayUpdated,
#define MTC_UI_GATEWAY_UPDATED			ev_emUICfgGatewayUpdated
	
	/* ����������Ϣ*/
	ev_emUICfgSerialUpdated,
#define MTC_UI_CFGSERIAPORT_UPDATED		ev_emUICfgSerialUpdated

	/* ��Ļ������Ϣ*/
	ev_emUICfgCaptionUpdated,
#define MTC_UI_CFGCAPTION_UPDATED		ev_emUICfgCaptionUpdated

	/* E1ͨ��������Ϣ*/
	ev_emUICfgE1ChanInfoUpdated,
#define MTC_UI_CFGE1CHANINFO_UPDATED	ev_emUICfgE1ChanInfoUpdated

	/* ����ģ����Ϣ*/
	ev_emUICfgNetModuleUpdated,
#define MTC_UI_CFGNETMODULE_UPDATED		ev_emUICfgNetModuleUpdated

	/* ·��������Ϣ*/
	ev_emUICfgRouteInfoUpdated,
#define MTC_UI_CFGROUTEINFO_UPDATED		ev_emUICfgRouteInfoUpdated

	/* PPPoE ������Ϣ�ϱ�*/
	ev_emUICfgPppoeUpdated, 
#define  MTC_UI_CFGPPPOE_UPDATED		ev_emUICfgPppoeUpdated

	/*Qos ������Ϣ�ϱ� */
	ev_emUICfgQosUpdated,
#define  MTC_UI_CFGQOS_UPDATED			ev_emUICfgQosUpdated

	/*��ѡЭ�����ø��� */
	ev_emUICfgPriorUpdated,
#define  MTC_UI_CFGAVPRIOR_UPDATED		ev_emUICfgPriorUpdated

	/*AGC ������Ϣ */
	ev_emUICfgAgcUpdated,
#define  MTC_UI_CFGAGC_UPDATED			ev_emUICfgAgcUpdated

	/*������������*/
	ev_emUICfgInVolUpdated,
#define  MTC_UI_CFGINVOL_UPDATED		ev_emUICfgInVolUpdated

	/*����������� */
	ev_emUICfgOutVolUpdated,
#define  MTC_UI_CFGOUTVOL_UPDATED		ev_emUICfgOutVolUpdated

	/* ��Ƶ��ʽ���ø��� 
		WPARAM		��Ƶ· EmVideoType*/
	ev_emUICfgVStandardUpdated,
#define  MTC_UI_CFGVSTANDARD_UPDATED	ev_emUICfgVStandardUpdated

	/*�����������ø��� */
	ev_emUICfgCallRateUpdated,
#define  MTC_UI_CFGCALLRATE_UPDATED		ev_emUICfgCallRateUpdated

	/*�����������ø��� */
	ev_emUICfgLangUpdated,
#define  MTC_UI_CFGLANGUAGE_UPDATED		ev_emUICfgLangUpdated

	/*����ǽ���ø��� */
	ev_emUICfgFireWallUpdated,
#define  MTC_UI_CFGFIREWALL_UPDATED		ev_emUICfgFireWallUpdated

	/*Nap ��̬Ӱ����� */
	ev_emUICfgNapMapUpdated,
#define  MTC_UI_CFGNAPMAPADDR_UPDATED	ev_emUICfgNapMapUpdated

	// ����ͷ���������ϱ�
	ev_emUICfgCamTypeUpdated,
#define MTC_UI_CFGCAMTYPE_UPDATED		ev_emUICfgCamTypeUpdated

	//UDP��TCP��ʼ�˿ں�
	ev_emUICfgCommonBasePortUpdated,
#define  MTC_UI_CFGCOMMONBASEPORT_UPDATED	ev_emUICfgCommonBasePortUpdated
	//�Զ��л�Ϊ����ն˵Ĳ�������
	ev_emUICfgMonitorServiceUpdated,
	//�Ƿ�����Զ��л�������
	ev_emUICfgIsEnableMonitor,
	//IP��ַ��ͻָʾ
	ev_emUICfgIPConflict,
	//CPU Mem ʹ������ϱ�
	ev_emUICpuMemStatus,
	//�Ƿ��;�̬ͼƬ״̬�ı�
	ev_emUISendPicStatus,
	//ͼ�������Ϣָʾ 
	//Wparam  ����״̬
	//lparam  Զ��״̬
	ev_emRabbonTestInd,

/* �����������Ϣ����*/
MTC_UI_CFGCODEC_UPDATED,


/* �Ƿ��������˫���еĻ��л�*/
MTC_UI_DUALPIP_UPDATED,      

/* �Ƿ���������ն˼��*/
MTC_UI_CFGMTSWITCH_UPDATED, 


/* ��Ƶ��ʽ�ϱ���Ϣ*/
MTC_UI_VIDEOFORMATINFO_UPDATED,  

/* ��Ƶ�����ϱ���Ϣ*/
MTC_UI_AUDIOPOWER_UPDATED,

MTC_UI_AUDIO_G7221_PARAM_UPDATED,

/* ������״̬�ϱ�*/
MTC_UI_CODECSTATUS_UPDATED,
MTC_UI_REALRESSTATUS_UPDATED,//��ʵ�ֱ����ϱ�
/* mt�ӱ��������ȡ�ĵ�һ����·�߿���Ϣ�ϱ� */
MTC_UI_DECODE_RESOLUTION_UPDATED,

/* ˫�������ñ�����ʾ*/
MTC_UI_DUAL_SETUPDATE,

MTC_UI_CAMERA_STATUS,

    /* �ն˰汾��Ϣ�ϱ� */
    ev_emUITerminalInformationUpdated,
#define MTC_UI_TERMINALINFORMATION_UPDATED  ev_emUITerminalInformationUpdated

    /* PCMT��ƵԴ��Ϣ�ϱ� */
    ev_emUIPcmtVidSourceUpdated,
#define MTC_UI_PCMTVIDSOURCE_UPDATED  ev_emUIPcmtVidSourceUpdated

    /* 8010c��ʾVGA����video�����ϱ� */
    ev_emUI8010cShowModelParamUpdated,
#define MTC_UI_8010CSHOWMODELPARAM_UPDATED  ev_emUI8010cShowModelParamUpdated

    /* ˫�����ʱ��ϱ� */
    ev_emUIDualCodeRationUpdated,
#define MTC_UI_DUALCODERATION_UPDATED  ev_emUIDualCodeRationUpdated

    /* mt����mtc����pc˫��ʱ�ı���ͳ����Ϣ */
    ev_emUIMTCEncStatisReq,
#define MTC_UI_MTCENCSTATIS_REQ  ev_emUIMTCEncStatisReq

    /* h261��ʽ�Ŀ��ջ�ʧ�ܣ����ϲ㣨mtc/���棩���ʹ�����ָʾ */
    ev_emUIMTCCodecErrorCodeInd,
#define MTC_UI_MTCCODECERRORCODE_IND  ev_emUIMTCCodecErrorCodeInd

    /* Mic�������ָʾ */
    ev_emUIMicAdjustInd,
#define MTC_UI_MICADJUST_IND  ev_emUIMicAdjustInd

    /* mt�豸����ָʾ */
    ev_emUIMtEquipmentCapsetInd,
#define MTC_UI_MTEQUIPMENTCAPSET_IND  ev_emUIMtEquipmentCapsetInd

    /* �Ƿ�����DHCP����ָʾ */
    ev_emUIMtDHCPIPInd,
#define MTC_UI_MTDHCPIP_IND  ev_emUIMtDHCPIPInd
    
    /* MC����ģʽָʾ */
    ev_emUIMCModeInd,
#define MTC_UI_MCMode_IND  ev_emUIMCModeInd

    /* DNS������IPָʾ */
    ev_emUIDNSServerInd,
#define MTC_UI_DNSSERVER_IND  ev_emUIDNSServerInd

	//mc��gk���ø���
	ev_emUICfgPxyIPInd,
#define MTC_UI_CFGPXYIP_IND ev_emUICfgPxyIPInd
    /* ��Ƕmc����ָʾ */
    ev_emUIInnerMCInd,
#define MTC_UI_INNERMC_IND  ev_emUIInnerMCInd

	
	
	//��������������
		ev_emUISpeakerValUPDATED, 
#define  MTC_UI_CFGSpeakerVal_UPDATED		ev_emUISpeakerValUPDATED
		
    /* Ldap������IPָʾ */
    ev_emUILdapServerUPDATED,
#define MTC_UI_LdapSERVER_UPDATED  ev_emUILdapServerUPDATED
	
	/* ����Ƶ�����Video��Ϣ����*/
	ev_emUICfgMainVideoToVideoUpdated,
#define MTC_UI_CFGMainVIDEOTOVideo_UPDATED  ev_emUICfgMainVideoToVideoUpdated
	/* ң�����ȼ�����*/
	ev_emUICfgRemoteHotKeyUpdated,
#define MTC_UI_CFGRemoteHotKey_UPDATED  ev_emUICfgRemoteHotKeyUpdated
	/* ����GK����ǽ����*/
	ev_emUICfgInnerGKUpdated,
#define MTC_UI_CFGInnerGK_UPDATED  ev_emUICfgInnerGKUpdated
	
	/* ����Proxy���ø���*/
	ev_emUICfgInnerProxyUpdated,
#define MTC_UI_CFGInnerProxy_UPDATED ev_emUICfgInnerProxyUpdated
	
	ev_emUICfgSetNetSelectMaskInd,
#define MTC_UI_CFGSETNETSELECTMASK_IND  ev_emUICfgSetNetSelectMaskInd

		/* MTU����*/
	ev_emUICfgMTUUpdated,
#define MTC_UI_CFGMTU_UPDATED  ev_emUICfgMTUUpdated
	/* ϵͳʱ�����*/
	ev_emUICfgMtTimeUpdated,
#define MTC_UI_CFGMtTime_UPDATED  ev_emUICfgMtTimeUpdated
		/* �Զ��������Ƹ���*/
	ev_emUICfgAnsUpdated,
#define MTC_UI_CFGANS_UPDATED  ev_emUICfgAnsUpdated

	//h264�Ƿ�ѡ��
	ev_emCfgH264FormatSelInd,
#define MTC_UI_CFG_H264SEL_UPDATED ev_emCfgH264FormatSelInd
	/************************************************************************/
	/* Fxo������
	wparam	0
	lparam  TCHAR *   �����˵ĺ���
	*/
	/************************************************************************/
	ev_MtcUIFxoBeCalled,
#define MTC_UI_FXO_CALLED			ev_MtcUIFxoBeCalled
	/************************************************************************/
    /************************************************************************/
	/* Fxo״̬����
	wparam	0
	lparam  EmFxoStatus
	*/
	/************************************************************************/
	ev_MtcUIFxoStatusUpdated,
#define MTC_UI_FXOStatus_Updated			ev_MtcUIFxoStatusUpdated
	/************************************************************************/
	    /************************************************************************/
	/* Fxo��ʱ
	wparam	0
	lparam  EmFxoStatus
	*/
	/************************************************************************/
	ev_MtcUIFxoTimeOut,
#define MTC_UI_FXO_TimeOut			ev_MtcUIFxoTimeOut
	/************************************************************************/
	/* Fxo���ٵȴ�
	wparam	0
	lparam  EmFxoStatus
	*/
	/************************************************************************/
	ev_MtcUIFxoNotWaiting,
#define MTC_UI_FXO_NotWaiting			ev_MtcUIFxoNotWaiting
	/************************************************************************/
	
	/* Fxo��·����
	wparam	0
	lparam  0
	*/
	/************************************************************************/
	ev_MtcUIFxoLineBreak,
#define MTC_UI_FXO_LINE_BREAK			ev_MtcUIFxoLineBreak
	/************************************************************************/

	/************************************************************************/
	/* ������cpu�쳣���ն˸�λ
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcCodecCpuResetInd,
#define MTC_UI_CODEC_CPU_RESET      ev_MtcCodecCpuResetInd  
	

	/************************************************************************/
	/* ������cpu�쳣���ն˸�λ
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcT2IPConflictInd,
#define MTC_UI_T2DEV_IPCONFLICT_IND  ev_MtcT2IPConflictInd

	/************************************************************************/
	/* telnet �����޸�
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcSysTelnetPwdInd,
#define MTC_UI_TELNET_PWD_IND  ev_MtcSysTelnetPwdInd 
	/************************************************************************/
	/* wifi ɨ�����ϱ�
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcWiFiScanBSSInd,
#define MTC_WIFI_SCAN_RESULT_IND  ev_MtcWiFiScanBSSInd

	/************************************************************************/
	/* wifi ���ý���ϱ�
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcWifiCfgInd,
#define MTC_WIFI_CFG_IND ev_MtcWifiCfgInd
	
	/************************************************************************/
	/* wifi ����״̬�ϱ�
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcWiFiLinkStatInd,
#define MTC_WIFI_LINKSTATE_IND ev_MtcWiFiLinkStatInd

	/************************************************************************/
	/* wifi ip������Ϣ
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcCfgWiFiNetInd,
#define MTC_WIFI_NET_IP_IND ev_MtcCfgWiFiNetInd

	/************************************************************************/
	/* ϵͳ����ʱ���ϱ�
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcSystemTimeInd,
#define MTC_SYSTEM_TIME_IND ev_MtcSystemTimeInd

	/************************************************************************/
	/* ���ڹ���ģʽ�ϱ�
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcEthModeInd,
#define MTC_ETH_MODE_IND ev_MtcEthModeInd
	/* ProxyDomain������Ϣ
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcFwProxyDomainReqInd,
#define MTC_PROXY_DOMAIN_REQ_IND ev_MtcFwProxyDomainReqInd
	/************************************************************************/
	/* Socket5�ϱ�
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcSocket5Ind,
#define MTC_UI_SOCKET5_CFG_IND ev_MtcSocket5Ind
	/************************************************************************/
	/* osd���ӷ�����,����mtc����
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUpgradeConnectSrvInd,
#define MTC_LOCKMTC_IND ev_MtcUpgradeConnectSrvInd
	/************************************************************************/
	/* ����������������,����mtc����
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUpgradeDisconnectSrvInd,
#define	MTC_UNLOCKMTC_IND ev_MtcUpgradeDisconnectSrvInd
	/************************************************************************/
	/* ���ӵ�������������Ϣ
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUpgradeConnectSrvStatusInd,
#define MTC_CONNECT_SRV_IND ev_MtcUpgradeConnectSrvStatusInd

	/************************************************************************/
	/* �Ͽ�����������
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUpgradeDisconnectInd,
#define MTC_UPGRADE_DISCONNECT_IND ev_MtcUpgradeDisconnectInd

	/************************************************************************/
	/* �����ļ��б�
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUpgradeNewVersionInfoListInd,
#define MTC_UPGRADE_FILELIST_IND ev_MtcUpgradeNewVersionInfoListInd

	/************************************************************************/
	/* �ն˿�ʼ�����ļ�
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcStartUpgrade,
#define MTC_START_UPGRADE_IND ev_MtcStartUpgrade

	/************************************************************************/
	/* �����ļ���Ϣ
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUpgradeFileDownloadInfoInd,
#define MTC_FILE_DOWNLOAD_INFO_IND ev_MtcUpgradeFileDownloadInfoInd

	/************************************************************************/
	/* ��ǰ�ļ����ؽ���
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_MtcUpgradeFileDownloadCompletedInd,
#define MTC_FILE_DOWNLOAD_COMPLETE_IND ev_MtcUpgradeFileDownloadCompletedInd

	//������Ƶ�˿�ѡ��
	ev_MtcCfgHDAudioPortInd,
#define  MTC_UI_CFGHDAudioPort_UPDATED 	ev_MtcCfgHDAudioPortInd

	//AAC��Ƶ��������
	ev_MtcCodecAudAacParamCmd,
#define  MTC_UI_AudAACParam_Cmd     ev_MtcCodecAudAacParamCmd    

	/************************************************************************/
	/*H460 ������Ϣ����                                                     
	/************************************************************************/
	ev_emUICfgH460Updated,
#define MTC_UI_CFGH460_UPDATED			ev_emUICfgH460Updated
	//////////////////////////////////////////////////////////////////////////
	ev_emUICfgVideoEncodeDecodeModeUpdated,
#define MTC_UI_CFGVIDEOENCODEDECODEMODE_UPDATED		ev_emUICfgVideoEncodeDecodeModeUpdated

	MTC_UI_ETH_NO,

	ev_MtcCfgLogStatusInd,
#define MTC_UI_STARTSTOPLOG			ev_MtcCfgLogStatusInd
	
	ev_MtcCfgLogExportInd,
#define MTC_UI_LOGEXPORT			ev_MtcCfgLogExportInd



	ev_MtE1GroupInd,
#define MTC_UI_E1Group				ev_MtE1GroupInd
	
	ev_MtE1UnitInd,
#define MTC_UI_E1Unit				ev_MtE1UnitInd

	MTC_UI_PASSTHROUGH,

	MTC_UI_CFG_LASTFRAMESHOW,
	MTC_UI_CFG_SHOWAPPLICATION,

	MTC_UI_VIDFRAMERATE_UPDATE,

	MTC_UI_CFG_MCDUALCFG,

	MTC_UI_CFG_SERIALIND,
	MTC_UI_MTCBOXCALLCFG_UPDATE,

	MTC_UI_CFG_SIP_UPDATE,			//����SIP�������
	MTC_UI_CFG_VGA_CTRLSTATUS,		//����VGA�ؼ��Ƿ�ɱ༭��Ϣ
	MTC_UI_CFG_VGA_PHASECLOCKIND,
	MTC_UI_CFG_VGA_FILTERSTATUS,
	
	ev_MtCnsInd,
#define MTC_UI_CNS_UPDATE				ev_MtCnsInd

	ev_MtCnsRegRsp,
#define MTC_UI_CNSREG_NOTIFY            ev_MtCnsRegRsp   
	
	/* Mic�������ָʾ */
    ev_emUIAecAdjustInd,
#define MTC_UI_AECADJUST_IND  ev_emUIAecAdjustInd

	ev_MtcUICfgMsgEnd
};











////////////////////////////////////////////////////////////////////////////////
// ���ɲ���
/* ��ѯ�Ƿ��������ն�
   ask	N/A
   rep	BOOL	TRUE������,FALSEδ����*/
//#define MTC_INT_IS_CONNECTED		EV_MTC_BGN + 0x100

/* ��ѯ��ǰ���ӵ��ն�
   ask	N/A
   rep	CMtcMt	�����ӵ��ն�*/
//#define MTC_INT_CONNECTED_MT		EV_MTC_BGN + 0x101

/* ��ѯ��¼���û�
   ask	N/A
   rep	CLoginRequest	��¼���û�*/
//#define MTC_INT_LOGIN_USER			EV_MTC_BGN + 0x102

/* �Ƿ���˼����
   ask	N/A
   rep	BOOL	TRUE�Ѽ��,FALSEδ���*/
//#define MTC_INT_MONITOR_NEAR		EV_MTC_BGN + 0x103

/* �Ƿ�Զ�˼����
   ask	N/A
   rep	BOOL	TRUE�Ѽ��,FALSEδ���*/
//#define MTC_INT_MONITOR_FAR			EV_MTC_BGN + 0x104

/* ��ǰ��Ƶ����ģʽ
   ask	N/A
   rep	_TMATRIXSCHEME	��ǰ��Ƶ����ģʽ*/
//#define MTC_INT_AMSCHE				EV_MTC_BGN + 0x105

/* ��ǰ��Ƶ����ģʽ
   ask	N/A
   rep	_TMATRIXSCHEME	��ǰ��Ƶ����ģʽ*/
//#define MTC_INT_VMSCHE				EV_MTC_BGN + 0x106

/* ��ǰ��Ƶ����Դ
   ask	N/A
   rep	u32	��ǰ��Ƶ����Դ*/
//#define MTC_INT_ASRC				EV_MTC_BGN + 0x107

/* ��ǰ��Ƶ����Դ
   ask	N/A
   rep	u32	��ǰ��Ƶ����Դ*/
//#define MTC_INT_VSRC				EV_MTC_BGN + 0x108

/* �Ƿ���˾���
   ask	N/A
   rep	BOOL	TRUE������,FALSEδ����*/
//#define MTC_INT_SPEAKER_MUTE		EV_MTC_BGN + 0x0109

/* �Ƿ��������
   ask	N/A
   rep	BOOL	TRUE������,FALSEδ����*/
//#define MTC_INT_MIC_MUTE			EV_MTC_BGN + 0x10a

/* �������
   ask	N/A
   rep	u32	�������*/
//#define MTC_INT_SPEAKER_VOLUME		EV_MTC_BGN + 0x10b

/* ��������
   ask	N/A
   rep	u32	��������*/
//#define MTC_INT_MIC_VOLUME			EV_MTC_BGN + 0x10c

/* ң��������״̬
   ask	N/A
   rep	BOOL	TRUE�ѿ���,FALSE�ѽ���*/
//#define MTC_INT_REMOTECTRL			EV_MTC_BGN + 0x10d

/* ��ַ����Ŀ����
   ask	N/A
   rep	u32	��Ŀ����*/
//#define MTC_INT_ENTRY_COUNT			EV_MTC_BGN + 0x10e

/* ��ַ����Ŀ������
   ask	N/A
   rep	u32	��Ŀ������*/
//#define MTC_INT_GROUP_COUNT			EV_MTC_BGN + 0x10f

/* ��ȡ��Ŀ
   ask	u32		��Ŀ����
   rep	CAddrEntry	��Ŀ*/
//#define MTC_INT_ENTRY				EV_MTC_BGN + 0x110

/* ��ȡ��Ŀ��
   ask	u32				��Ŀ������
   rep	CAddrMultiSetEntry	��Ŀ��*/
//#define MTC_INT_GROUP				EV_MTC_BGN + 0x111

/* �Ƿ��ڵ�Ե������
   ask	N/A
   rep	BOOL	TRUE�ڵ�Ե������,FALSE���ڵ�Ե������*/
//#define MTC_INT_P2PCONF				EV_MTC_BGN + 0x112

/* �Ƿ����ں��������ն�
   ask	N/A
   rep	BOOL	TRUE���ں���,FALSEû�ں���*/
//#define MTC_INT_CALLING				EV_MTC_BGN + 0x113

/* ��ǰ�������б�
   ask	N/A
   rep	u32		������Ŀ
		_TCONFINFO*	��������*/
//#define MTC_INT_CONFLIST			EV_MTC_BGN + 0x114

/* �Ƿ����ڵȴ����������Ӧ
   ask	N/A
   rep	BOOL	TRUE���ڵȴ���Ӧ,FALSEδ�ȴ���Ӧ*/
//#define MTC_INT_WAITING_CREATE		EV_MTC_BGN + 0x115

/* �Ƿ����ڵȴ��������뱻��׼
   ask	N/A
   rep	BOOL	TRUE���ڵȴ����������Ӧ,FALSEδ�ȴ���Ӧ*/
//#define MTC_INT_WAITING_JOIN		EV_MTC_BGN + 0x116

/* �Ƿ����ڶ�������
   ask	N/A
   rep	BOOL	TRUE���ڶ�������,FALSEδ�ڶ�������*/
//#define MTC_INT_MCONF				EV_MTC_BGN + 0x117

/* �Ƿ���ѯ��
   ask	N/A
   rep	BOOL	TRUE������ѯ��,FALSEδ����ѯ��*/
//#define MTC_INT_POLLING				EV_MTC_BGN + 0x118

/* ����ն��б�
   ask	N/A
   rep	u32	�ն���Ŀ
		CMtcMt	����ն�����*/
//#define MTC_INT_MTLIST				EV_MTC_BGN + 0x119

/* �������ն��б�
   ask	N/A
   rep	u32	�ն���Ŀ
		CMtcMt	�����ն�����*/
//#define MTC_INT_ONLINE_MTLIST		EV_MTC_BGN + 0x11a

/* �����ն�
   ask	N/A
   rep	CMtcMt	��ǰ�����ն�*/
//#define MTC_INT_SPEAKER				EV_MTC_BGN + 0x11b

/* ��ϯ�ն�
   ask	N/A
   rep	CMtcMt	��ǰ��ϯ�ն�*/
//#define MTC_INT_CHAIRMAN			EV_MTC_BGN + 0x11c

/* ���������ն��б�
   ask	N/A
   rep	u32	�ն���Ŀ
		CMtcMt	��ǰ��������ն�����*/
//#define MTC_INT_REQ_JOIN			EV_MTC_BGN + 0x11d

/* ���뷢�Ե��ն��б�
   ask	N/A
   rep	u32	�ն���Ŀ
		CMtcMt	��ǰ���뷢���ն�����*/
//#define MTC_INT_REQ_SPEAK			EV_MTC_BGN + 0x11e

/* ������ϯ���ն��б�
   ask	N/A
   rep	u32	�ն���Ŀ
		CMtcMt	��ǰ������ϯ�ն�����*/
//#define MTC_INT_REQ_CHAIRMAN		EV_MTC_BGN + 0x11f

/* ��ʼ���˼��
   ask	N/A
   rep	BOOL	�������*/
//#define MTC_INT_STARTMONNEAR		EV_MTC_BGN + 0x120

/* ��ʼԶ�˼��
   ask	N/A
   rep	BOOL	�������*/
//#define MTC_INT_STARTMONFAR			EV_MTC_BGN + 0x121

/* ֹͣ���˼��
   ask	N/A
   rep	BOOL	�������*/
#define MTC_INT_STOPMONNEAR			EV_MTC_BGN + 0x122

/* ֹͣԶ�˼��
   ask	N/A
   rep	BOOL	�������*/
//#define MTC_INT_STOPMONFAR			EV_MTC_BGN + 0x123

///* ����ͷ��̨��ʼ�����˶�
//   ask	N/A
//   rep	BOOL	�������*/
// #define MTC_INT_CAMERATURNUP		EV_MTC_BGN + 0x124

/* ����ͷ��ֹ̨ͣ�����˶�
   ask	N/A
   rep	BOOL	�������*/
// #define MTC_INT_CAMERATURNUPSTOP	EV_MTC_BGN + 0x125

/* ����ͷ��̨��ʼ�����˶�
	ask N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERATURNDOWN		EV_MTC_BGN + 0x126

/* ����ͷ��ֹ̨ͣ�����˶�
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERATURNDOWNSTOP	EV_MTC_BGN + 0x127

/* ����ͷ��̨��ʼ�����˶�
	ask N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERATURNLEFT		EV_MTC_BGN + 0x128

/* ����ͷ��ֹ̨ͣ�����˶�
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERATURNLEFTSTOP	EV_MTC_BGN + 0x129

/* ����ͷ��̨��ʼ�����˶�
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERATURNRIGHT		EV_MTC_BGN + 0x12a

/* ����ͷ��ֹ̨ͣ�����˶�
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERATURNRIGHTSTOP	EV_MTC_BGN + 0x12b

/* ����ͷ�Զ���������
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERAADJUSTFOCUSAUTO	EV_MTC_BGN + 0x12c

/* ����ͷ��ʼ�������࿪ʼ
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERAADJUSTFOCUS2NEAR	EV_MTC_BGN + 0x12d

/* ����ͷ��ʼ��������ֹͣ
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERAADJUSTFOCUS2NEARSTOP	EV_MTC_BGN + 0x12e

/* ����ͷ��Զ���࿪ʼ
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERAADJUSTFOCUS2FAR	EV_MTC_BGN + 0x12f

/* ����ͷ��Զ����ֹͣ
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERAADJUSTFOCUS2FARSTOP	EV_MTC_BGN + 0x130

/* ����ͷ�������ӿ�ʼ
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERAINCLUM		EV_MTC_BGN + 0x131

/* ����ͷ��������ֹͣ
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERAINCLUMSTOP	EV_MTC_BGN + 0x132

/* ����ͷ���ȼ�С��ʼ
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERADECLUM		EV_MTC_BGN + 0x133

/* ����ͷ���ȼ�Сֹͣ
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERADECLUMSTOP	EV_MTC_BGN + 0x134

/* ����ͷͼ��Ŵ�ʼ
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERAZOOMIN		EV_MTC_BGN + 0x135

/* ����ͷͼ��Ŵ�ֹͣ
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERAZOOMINSTOP	EV_MTC_BGN + 0x136

/* ����ͷͼ����С��ʼ
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERAZOOMOUT		EV_MTC_BGN + 0x137

/* ����ͷͼ����Сֹͣ
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CAMERAZOOMOUTSTOP	EV_MTC_BGN + 0x138

/* ����ȱʡ����ģʽ
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_LOADSCHEDEFAULT		EV_MTC_BGN + 0x139

/* ��������ͷ״̬
	ask	u32		״̬������
	rep	BOOL	�������*/
// #define MTC_INT_CAMERALOADSTATUS	EV_MTC_BGN + 0x13a

/* ��������ͷ״̬
	ask	u32		״̬������
	rep	BOOL	�������*/
// #define MTC_INT_CAMERASAVESTATUS	EV_MTC_BGN + 0x13b

/* ѡ������ͷ
	ask	u32		����ͷ���
	rep	BOOL	�������*/
// #define MTC_INT_SELECTCAMERA		EV_MTC_BGN + 0x13c

/* ����Զ������ͷ�л�
	ask	BOOL	�Ƿ��л�����������ͷ
	rep	BOOL	�������*/
// #define MTC_INT_SWITCHSOURCECAM		EV_MTC_BGN + 0x13d

/* ������Ƶ�˿�
	ask	TMATRIXPORT	����˿�
		TMATRIXPORT	����˿�
	rep	BOOL	�������*/
// #define MTC_INT_CFGAPORTS			EV_MTC_BGN + 0x13e

/* ������Ƶ�˿�
	ask	TMATRIXPORT	����˿�
		TMATRIXPORT	����˿�
	rep	BOOL	�������*/
//#define MTC_INT_CFGVPORTS			EV_MTC_BGN + 0x13f

/* ѡ����Ƶ����Դ
	ask	u32		����Դ
	rep	BOOL	�������*/
// #define MTC_INT_SETAINPUTSRC		EV_MTC_BGN + 0x140

/* ѡ����Ƶ����Դ
	ask	u32		����Դ
	rep	BOOL	�������*/
// #define MTC_INT_SETVINPUTSRC		EV_MTC_BGN + 0x141

/* �������ģʽ
	ask	u32		����λ����
	rep	BOOL	�������*/
// #define MTC_INT_LOADSCHE			EV_MTC_BGN + 0x142

/* �������ģʽ
	ask	u32		����λ����
		TCHAR*	˵���ַ���
	rep	BOOL	�������*/
// #define MTC_INT_SAVESCHE			EV_MTC_BGN + 0x143

/* ���ڱ����������
	ask	u32		����
	rep	BOOL	�������*/
// #define MTC_INT_ADJLOCALSPKVOL		EV_MTC_BGN + 0x144

/* ���ڱ�����������
	ask	u32		����
	rep	BOOL	�������*/
// #define MTC_INT_ADJLOCALMICVOL		EV_MTC_BGN + 0x145

/* �����������
	ask	BOOL	�Ƿ����þ���
	rep	BOOL	�������*/
// #define MTC_INT_MUTELOCALSPK		EV_MTC_BGN + 0x146

/* �������뾲��
	ask	BOOL	�Ƿ����þ���
	rep	BOOL	�������*/
// #define MTC_INT_MUTELOCALMIC		EV_MTC_BGN + 0x147

/* ���û�������
	ask	BOOL	�Ƿ����û�������
	rep	BOOL	�������*/
// #define MTC_INT_ENABLEAEC			EV_MTC_BGN + 0x148

/* ����ң����
	ask	BOOL	�Ƿ�����ң����
	rep	BOOL	�������*/
// #define MTC_INT_ENABLERCTRL			EV_MTC_BGN + 0x149

/* �޸��û�
	ask	CLoginRequest	��Ҫ���޸ĵ��û�
		BOOL	�Ƿ��Ϊ����Ա�û�
	rep	BOOL	�������*/
//#define MTC_INT_BOOKMODUSER				EV_MTC_BGN + 0x14a

/* �����û�
	ask	CLoginRequest	��Ҫ���޸ĵ��û�
		BOOL	�Ƿ�����Ϊ����Ա�û�
	rep	BOOL	�������*/
// #define MTC_INT_BOOKADDUSER				EV_MTC_BGN + 0x14b

/* ɾ���û�
	ask	CLoginRequest	��Ҫ��ɾ�����û�
	rep	BOOL	�������*/
// #define MTC_INT_BOOKDELUSER				EV_MTC_BGN + 0x14c

/* ���ӵ�ַ����Ŀ
	ask	CAddrEntry	���ӵ���Ŀ
	rep	BOOL	�������*/
// #define MTC_INT_ADDENTRY			EV_MTC_BGN + 0x14d

/* �޸ĵ�ַ����Ŀ
	ask	CAddrEntry
	rep	BOOL	�������*/
// #define MTC_INT_MODENTRY			EV_MTC_BGN + 0x14e

/* ɾ����ַ����Ŀ
	ask	u32		��Ҫɾ������Ŀ����
	rep	BOOL	�������*/
// #define MTC_INT_DELENTRY			EV_MTC_BGN + 0x14f

/* ���ӵ�ַ����
	ask	CAddrMultiSetEtry	���ӵ���Ŀ��
	rep	BOOL	�������*/
// #define MTC_INT_ADDGROUP			EV_MTC_BGN + 0x150

/* �޸ĵ�ַ����
	ask	CAddrMultiSetEntry	�޸ĵ���Ŀ��
	rep	BOOL	�������*/
// #define MTC_INT_MODGROUP			EV_MTC_BGN + 0x151

/* ɾ����ַ����
	ask	u32		��Ҫɾ������Ŀ������
	rep	BOOL	�������*/
// #define MTC_INT_DELGROUP			EV_MTC_BGN + 0x152

/* P2P��IP����
	ask	u32		�������ն˵�IP��ַ
	rep	BOOL	�������*/
// #define MTC_INT_CALLBYIP			EV_MTC_BGN + 0x153

/* P2P��E164�������
	ask	TCHAR	�������ն�E164����	
	rep	BOOL	�������*/
// #define MTC_INT_CALLBYNUM			EV_MTC_BGN + 0x154

/* P2Pȡ������
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CANCELCALLING		EV_MTC_BGN + 0x155

/* P2P������Ե����
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_ENDP2PCONF			EV_MTC_BGN + 0x156

/* �������
	ask	_TCONFINFO	�μӵĻ���
	rep	BOOL	�������*/
// #define MTC_INT_JOINCONF			EV_MTC_BGN + 0x157

/* ȡ���������
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_CANCELJOIN			EV_MTC_BGN + 0x158

/* ���뷢��
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_REQSPK				EV_MTC_BGN + 0x159

/* ������ϯ
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_REQCHAIRMAN			EV_MTC_BGN + 0x15a

/* ��������
	ask	u32		�������ڵ�MCU��IP��ַ
		_TCONFINFO	������Ϣ
		u32		����ն���Ŀ
		_TERADDR*	����ն�
	rep	BOOL	�������*/
//# define MTC_INT_CREATECONF			EV_MTC_BGN + 0x15b

/* �˳�����
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_QUITCONF			EV_MTC_BGN + 0x15c

/* ��ʼ��ѯ
	ask	BOOL	�Ƿ�㲥
		BOOL	�Ƿ������Ƶ
		BOOL	�Ƿ������Ƶ
		u32		��ѯʱ����
		u32		����ѯ�ն���Ŀ
		CMtcMt*	����ѯ�ն�
	rep	BOOL	�������*/
// #define MTC_INT_STARTPOLL			EV_MTC_BGN + 0x15d

/* ������ѯ
	ask	N/A
	rep	BOOL	�������*/
//#define MTC_INT_ENDPOLL				EV_MTC_BGN + 0x15e

/* ���Ͷ���Ϣ
	ask	CMtcMt	��ϢĿ���ն�
		TCHAR*	��Ϣ
	rep	BOOL	�������*/
// #define MTC_INT_SENDMSG				EV_MTC_BGN + 0x15f

/* �����ն�(��IP)
	ask	u32		�������ն�IP��ַ
	rep	BOOL	�������*/
// #define MTC_INT_INVITEBYIP			EV_MTC_BGN + 0x160

/* �����ն�(�ն˽ṹ)
	ask	_TERADDR�������ն�_TERADDR�ṹ
	rep	BOOL	�������*/
// #define MTC_INT_INVITE_MT		    EV_MTC_BGN + 0x161

/* �����ն�
	ask	CMtcMt	�������ն�
	rep	BOOL	�������*/
// #define MTC_INT_DROPMT				EV_MTC_BGN + 0x162

/* ָ������
	ask	CMtcMt	��ָ�����Ե��ն�
	rep	BOOL	�������*/
// #define MTC_INT_SPECSPK				EV_MTC_BGN + 0x163

/* ָ����ϯ
	ask	CMtcMt	��ָ��Ϊ��ϯ���ն�
	rep	BOOL	�������*/
// #define MTC_INT_SPECCHAIRMAN		EV_MTC_BGN + 0x164

/* ȡ������
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_REVOKESPK			EV_MTC_BGN + 0x165

/* ȡ����ϯ
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_REVOKECHAIRMAN		EV_MTC_BGN + 0x166

/* �����������
	ask	CMtcMt	�����������ն�
	rep	BOOL	�������*/
// #define MTC_INT_ACCEPTJOIN			EV_MTC_BGN + 0x167

/* �ܾ��������
	ask	CMtcMt	���ܾ������ն�
	rep	BOOL	�������*/
// #define MTC_INT_REFUSEJOINT			EV_MTC_BGN + 0x168

/* ���ܷ�������
	ask	CMtcMt	�����ܷ���������ն�
	rep	BOOL	�������*/
//#define MTC_INT_ACCEPTSPK			EV_MTC_BGN + 0x169

/* �ܾ���������
	ask	CMtcMt	���ܾ�����������ն�
	rep	BOOL	�������*/
// #define MTC_INT_REFUSESPK			EV_MTC_BGN + 0x16a

/* ����������ϯȨ������
	ask	CMtcMt	��������ϯ������ն�
	rep	BOOL	�������*/
// #define MTC_INT_ACCEPTCHAIRMAN		EV_MTC_BGN + 0x16b

/* �ܾ�������ϯȨ������
	ask	CMtcMt	���ܾ���ϯ������ն�
	rep	BOOL	�������*/
// #define MTC_INT_REFUSECHAIRMANT		EV_MTC_BGN + 0x16c

/* ����
	ask	CMtcMt	���������ն�
		BOOL	�Ƿ����þ���
	rep	BOOL	�������*/
// #define MTC_INT_SILENCE				EV_MTC_BGN + 0x16d

/* ����
	ask	CMtcMt	���������ն�
		BOOL	�Ƿ���������
	rep	BOOL	�������*/
// #define MTC_INT_DUMB				EV_MTC_BGN + 0x16e

/* ��������
	ask	N/A
	rep	BOOL	�������*/
// #define MTC_INT_ENDCONF				EV_MTC_BGN + 0x16f

/* �㲥�ն�
	ask	CMtcMt	���㲥���ն�
	rep	BOOL	�������*/
// #define MTC_INT_BROADCASTMT			EV_MTC_BGN + 0x170

/* ѡ���ն�
	ask	CMtcMt	��ѡ�����ն�
	rep	BOOL	�������*/
// #define MTC_INT_VIEWMT				EV_MTC_BGN + 0x171

/* ��ʼ����
	ask u8		�����������ն���Ŀ
	rep	BOOL	�������*/
//#define MTC_INT_START_DISCUSS		EV_MTC_BGN + 0x172

/* ֹͣ����
	ask NULL
	rep BOOL	�������*/
//#define MTC_INT_STOP_DISCUSS		EV_MTC_BGN + 0x0173

/* ʹMtcLib���ӵ��ն�ҵ��
	ask	u32		�ն�ҵ��IP��ַ
		u16		�ն�ҵ��˿�
		TCHAR*	�û���,�����β���ַ���
		TCHAR*	����,�����β���ַ���
	rep	BOOL	�������*/
//#define	MTC_INT_CONNECT				EV_MTC_BGN + 0x0174

/* ʹMtcLib�Ͽ��ն�ҵ��
	ask	N/A
	rep	BOOL	�������*/
//#define MTC_INT_DISCONNECT			EV_MTC_BGN + 0x0175

/* ��ȡ����������Ϣ
	ask N/A
	rep BOOL	�������*/
//#define MTC_INT_REQALLCFG			EV_MTC_BGN + 0x0176

/* �����ļ�-����
	ask N/A
	rep BOOL		�������
		_TTERCFG	����������Ϣ*/
//#define MTC_INT_GETCFGLOCAL			EV_MTC_BGN + 0x0177

/* �����ļ�-����
	ask	N/A
	rep BOOL		�������
		_TNETCFG	����������Ϣ*/
//#define MTC_INT_GETCFGNET			EV_MTC_BGN + 0x0178

/* �����ļ�-����
	ask	N/A
	rep BOOL		�������
		_TCALLCFG	����������Ϣ*/
//#define MTC_INT_GETCFGCALL			EV_MTC_BGN + 0x0179

/* �����ļ�-��Ƶ����
	ask	N/A
	rep BOOL		�������
		_TVENCPARAM	��Ƶ����������Ϣ*/
//#define MTC_INT_GETCFGVENC			EV_MTC_BGN + 0x017a

/* �����ļ�-��Ƶ����
	ask	N/A
	rep BOOL		�������
		_TVDECPARAM	��Ƶ����������Ϣ*/
//#define MTC_INT_GETCFGVDEC			EV_MTC_BGN + 0x017b

/* �����ļ�-��Ƶ����
	ask	N/A
	rep BOOL		�������
		_TAENCPARAM	��Ƶ����������Ϣ*/
//#define MTC_INT_GETCFGAENC			EV_MTC_BGN + 0x017c

/* �����ļ�-��Ƶ����
	ask	N/A
	rep BOOL		�������
		_TADECPARAM	��Ƶ����������Ϣ*/
//#define MTC_INT_GETCFGADEC			EV_MTC_BGN + 0x017d

/* �����ļ�-�����ش�
	ask	N/A
	rep BOOL		�������
		_TSENDRTCFG	�����ش�������Ϣ*/
//#define MTC_INT_GETCFGSENDRT		EV_MTC_BGN + 0x017e

/* �����ļ�-�����ش�
	ask	N/A
	rep BOOL		�������
		_TRECVRTCFG	�����ش�������Ϣ*/
//#define MTC_INT_GETCFGRECVRT		EV_MTC_BGN + 0x017f

/* �����ļ�-����
	ask	_TTERCFG	��������
	rep	BOOL		�������*/
//#define MTC_INT_UPDATECFGLOCAL		EV_MTC_BGN + 0x0180

/* �����ļ�-����
	ask	_TNETCFG	��������
	rep	BOOL		�������*/
//#define MTC_INT_UPDATECFGNET		EV_MTC_BGN + 0x0181

/* �����ļ�-����
	ask	_TCALLCFG	��������
	rep	BOOL		�������*/
//#define MTC_INT_UPDATECFGCALL		EV_MTC_BGN + 0x0182

/* �����ļ�-��Ƶ����
	ask	_TVENCPARAM	��Ƶ��������
	rep	BOOL		�������*/
//#define MTC_INT_UPDATECFGVENC		EV_MTC_BGN + 0x0183

/* �����ļ�-��Ƶ����
	ask	_TVDECPARAM	��Ƶ��������
	rep	BOOL		�������*/
//#define MTC_INT_UPDATECFGVDEC		EV_MTC_BGN + 0x0184

/* �����ļ�-��Ƶ����
	ask	_TAENCPARAM	��Ƶ��������
	rep	BOOL		�������*/
//#define MTC_INT_UPDATECFGAENC		EV_MTC_BGN + 0x0185

/* �����ļ�-��Ƶ����
	ask	_TADECPARAM	��Ƶ��������
	rep	BOOL		�������*/
//#define MTC_INT_UPDATECFGADEC		EV_MTC_BGN + 0x0186

/* �����ļ�-�����ش�
	ask	_TSENDRT	�����ش�����
	rep	BOOL		�������*/
//#define MTC_INT_UPDATECFGSENDRT		EV_MTC_BGN + 0x0187

/* �����ļ�-�����ش�
	ask	_TRECVRT	�����ش�����
	rep	BOOL		�������*/
//#define MTC_INT_UPDATECFGRECVRT		EV_MTC_BGN + 0x0188

/* �û�����-����
	ask CUserFullInfo	�����ӵ��û�
	rep BOOL			�������*/
//#define MTC_INT_ADDUSER				EV_MTC_BGN + 0x0189

/* �û�����-�޸�
	ask CUserFullInfo	���޸ĵ��û�
	rep BOOL			�������*/
//#define MTC_INT_MODUSER				EV_MTC_BGN + 0x018a

/* �û�����-ɾ��
	ask CUserFullInfo	��ɾ�����û�
	rep BOOL			�������*/
//#define MTC_INT_DELUSER				EV_MTC_BGN + 0x018b

/* �û�����-����ȫ���û�
	ask N/A
	rep BOOL			�������*/
//#define MTC_INT_REQALLUSERS			EV_MTC_BGN + 0x018c

/* �û�����-��ȡ�û���Ŀ
	ask N/A
	rep u32		�û���Ŀ*/
//#define MTC_INT_GETUSERCOUNTS		EV_MTC_BGN + 0x018d

/* �û�����-��ȡȫ���û�
	ask N/A
	rep	u32				�û���Ŀ
		CUserFullInfo*	�û�����*/
//#define MTC_INT_GETALLUSERS			EV_MTC_BGN + 0x018e

/* ֹͣѡ��
	ask N/A
	rep BOOL			�������*/
//#define MTC_INT_STOPVIEWMT			EV_MTC_BGN + 0x018f

/* ��һ����ַ����Ŀ
	ask N/A
	rep CAddrEntry		��Ŀ*/
//#define MTC_INT_FIRSTENTRY			EV_MTC_BGN + 0x0190

/* ��һ����ַ����Ŀ
	ask u32				����
	rep CAddrEntry		��Ŀ*/
//#define MTC_INT_NEXTENTRY			EV_MTC_BGN + 0x0191

/* ��һ����ַ����Ŀ
	ask N/A
	rep CAddrEntry		��Ŀ*/
//#define MTC_INT_FIRSTGROUP			EV_MTC_BGN + 0x0192

/* ��һ����ַ����Ŀ
	ask u32				����
	rep CAddrEntry		��Ŀ*/
//#define MTC_INT_NEXTGROUP			EV_MTC_BGN + 0x0193

/* �����ӳ�
	ask u16				�ӳ�ʱ��,�Է��Ӽ�
	rep N/A*/
//#define MTC_INT_CONFDELAY			EV_MTC_BGN + 0x0194

/* ��ʼ��Ƶ����
	ask TVMPParam		��Ƶ���ϲ���
	rep N/A*/
//#define MTC_INT_STARTVMP			EV_MTC_BGN + 0x0195

/* ֹͣ��Ƶ����
	ask N/A
	rep N/A*/
//#define MTC_INT_STOPVMP				EV_MTC_BGN + 0x0196

/* ������Ƶ���ϲ���
	ask TVMPParam		��Ƶ���ϲ���
	rep N/A*/
//#define MTC_INT_UPDATEVMP			EV_MTC_BGN + 0x0197

/* ��ȡ����ID
	ask N/A
    rep BOOL		�������
        char*   ����ID�ַ�������ָ��*/
//#define MTC_INT_GETCURRENTCONF			EV_MTC_BGN + 0x0198

/* ��ȡ��ǰѡ���ն�
	ask N/A
    rep BOOL		�������
        CMtcMt      �ն�*/
//#define MTC_INT_GETCURRENTCHOICE    	EV_MTC_BGN + 0x0199

//����Ϊ����20041230
/* �Ƿ���ڵ�ǰ��ַ��Ŀ
	ask CAddrEntry  ��ַ��Ŀ
    rep BOOL32		�������*/
//#define MTC_INT_ISEXIST_ENTRY    	EV_MTC_BGN + 0x019a

/* �Ƿ���ڵ�ǰ����Ŀ
	ask CAddrMultiSetEntry  ����Ŀ
    rep BOOL32		�������*/
//#define MTC_INT_ISEXIST_GROUP    	EV_MTC_BGN + 0x019b

/* �Ƿ���ڵ�ǰ�û�
	ask CUserFullInfo  �û�
    rep BOOL32		�������*/
//#define MTC_INT_ISEXIST_USER    	EV_MTC_BGN + 0x019c

/* �Ƿ���˫��
	ask N/A  
    rep BOOL32		�������*/
//#define MTC_INT_IS_DUAL         	EV_MTC_BGN + 0x019d

/* ��ȡ˫������
	ask N/A  �û�
    rep u8		�������*/
//#define MTC_INT_GETDUALTYPE    	    EV_MTC_BGN + 0x019e

/* �Ƿ��ڲ廰
	ask N/A  
    rep BOOL32		�������*/
//#define MTC_INT_ISCHIME      	    EV_MTC_BGN + 0x019f

/* ��õ�ǰ��ƵԴ
	ask N/A  
    rep CMtcMt		�������*/
//#define MTC_INT_GETVSOURCE      	EV_MTC_BGN + 0x0200


/* �������
	ask N/A  
    rep CMtcMt		�������*/
//#define MTC_INT_GETCFGIMG               EV_MTC_BGN + 0x0201
//#define MTC_INT_GETCFGOSD               EV_MTC_BGN + 0x0202
//#define MTC_INT_GETCFGSNMP              EV_MTC_BGN + 0x0203
//#define MTC_INT_GETCFGAEC               EV_MTC_BGN + 0x0204
//#define MTC_INT_GETCFGMATRIX            EV_MTC_BGN + 0x0205
//#define MTC_INT_GETCFGPANEL             EV_MTC_BGN + 0x0206
//#define MTC_INT_GETCFGCAMERAL           EV_MTC_BGN + 0x0207
//#define MTC_INT_GETCFGTVOUT             EV_MTC_BGN + 0x0208
//#define MTC_INT_GETCFGSMALLLOCAL        EV_MTC_BGN + 0x0209
//#define MTC_INT_GETCFGMONIORSW          EV_MTC_BGN + 0x020a
//#define MTC_INT_GETCFGSERIAPORT         EV_MTC_BGN + 0x020b
//#define MTC_INT_GETCFGCAPTION           EV_MTC_BGN + 0x020c

/* ��õ�ǰ��Ƶ����״̬
	ask N/A  
    rep CMtcMt		�������*/
//#define MTC_INT_GETVMPINFO      	    EV_MTC_BGN + 0x020d

/* ��õ�ǰ�ն�״̬
	ask N/A  
    rep _TTERSTATUS		�������*/
//#define MTC_INT_GETMTSTATUS      	    EV_MTC_BGN + 0x020e

/* ��õ�ǰ�ն�״̬
	ask u8 byType  ����  
    rep _TVENCPARAM		�������*/
//#define MTC_INT_GETDUALCFG              EV_MTC_BGN + 0x020f

/* ��õ�ǰ�ն�״̬
	ask N/A  ����  
    rep u16  ����		�������*/
//#define MTC_INT_GETSNAPSHOTCOUNT        EV_MTC_BGN + 0x0210


/* ��յ�ַ��*/
//#define MTC_INT_UI_CLEAR_ADDRBOOK           EV_MTC_BGN + 0X0212

/* ����û� */
//#define MTC_INT_UI_CLEAR_USER               EV_MTC_BGN + 0X0213



/*��ȡ�ڶ�������ĳ���ն˵ı�����Ϣ*/
//#define MTC_INT_GETMTINFO					EV_MTC_BGN + 0X0215

/*��ȡ��Ե�����к����ն˵���Ϣ*/
//#define MTC_INT_P2PCALLER						EV_MTC_BGN + 0X0216

/* ��ȡ��Ե�����б����ն˵���Ϣ*/
//#define MTC_INT_P2PMTME						EV_MTC_BGN + 0X0217

/*
 *	=====================================================================
 *	���ɲ�����Ϣ
 *  =====================================================================
 */
//CConnect
/* ��ѯ�Ƿ��������ն�
   ask	N/A
   rep	BOOL	TRUE������,FALSEδ����*/
#define MTC_INT_IS_CONNECTED		EV_MTC_BGN + 0x100

/* ��ѯ��ǰ���ӵ��ն�
   ask	N/A
   rep	TMtInfo	�����ӵ��ն�*/
#define MTC_INT_CONNECTED_MT		EV_MTC_BGN + 0x101

/* ��ѯ��¼���û�
   ask	N/A
   rep	CLoginRequest	��¼���û�*/
#define MTC_INT_LOGIN_USER			EV_MTC_BGN + 0x102
/* ��ѯ�ն˵�״̬
   ask	N/a
   rep   TMtStatus */
#define MTC_INT_MT_STATUS			EV_MTC_BGN + 0x103
/*	��ѯ���յ���Ŀ
 *	ask	n/a
	rep u16		������Ŀ */
#define  MTC_INT_GETSNAPSHOTCOUNT			EV_MTC_BGN +0x104
//CConfig
/*	��ѯ��ǰ����������
 *	ask n/a
	rep EmLanguage	�������� */
#define  MT_INT_CFG_LANGUAGE		EV_MTC_BGN + 0x105
/*	��ѯ��ǰ����̫������
 *	ask u8�������
	rep	TEthnetInfo	��̫������ */
#define  MT_INT_CFG_ETHNET			EV_MTC_BGN + 0x106
/*	��ѯ��ǰ���û�����
 *	ask	n/a
	rep TUserCfg	�û����� */
#define  MT_INT_CFG_USER			EV_MTC_BGN + 0x107
/*	��ѯ��ǰ��H323����
 *	ask n/a
	rep	TH323Cfg	H323����*/	
#define  MT_INT_CFG_H323			EV_MTC_BGN + 0x108
/*  ��ѯ��Ƶ������Ϣ
 *	ask EmVideoType emType
	rep TVideoParam 
 */
#define  MT_INT_CFG_VIDEO			EV_MTC_BGN + 0x109
/*	��ѯ̨������
 *	ask n/a
	rep	TOsdCfg */
#define  MT_INT_CFG_OSD				EV_MTC_BGN + 0x10a
/*	��ѯE1����
 *	ask n/a
	rep TE1Config */
#define  MT_INT_CFG_E1				EV_MTC_BGN + 0x10b
/*	��ѯ��ǰ�Ĵ�����Ϣ
 *	ask	EmSerialType
	rep TSerialCfg	*/	
#define	 MT_INT_CFG_SERIAL			EV_MTC_BGN + 0x10c
/*	��ѯQos������Ϣ
 *	 ask	n/a
	rep		TIpQoscfg */
#define  MT_INT_CFG_IPQOS			EV_MTC_BGN + 0x10d
/*	��ѯ����ǽ��������Ϣ
 *	ask		n/a
	rep		TEmbedFwNatProxy */
#define  MT_INT_CFG_FIREWALL		EV_MTC_BGN + 0x10e
/*	��ѯ·��������Ϣ	
 *	ask u8 dwIndex
	rep TRouteCfg */
#define MT_INT_CFG_ROUTE			EV_MTC_BGN + 0x10f
/*	��ѯPPPoE����
 *	ask     no
	rep		TPPPOECfg */
#define MT_INT_CFG_PPPOE			EV_MTC_BGN + 0x110
/*	��ѯsnmp����
 *	ask			no
	rep			TSNMPCfg */
#define MT_INT_CFG_SNMP				EV_MTC_BGN + 0x111
/*	��ѯ��̬ӳ��������Ϣ
 *	ask		no
	rep		TNATMapAddr */
#define MT_INT_CFG_NAPMAP			EV_MTC_BGN + 0x112
/*	��ѯ�����ش�����
 *	ask			no
	rep			TRetransCfg */
#define MT_INT_CFG_RETRANS			EV_MTC_BGN + 0x113
/*	��ѯ�Ƿ�AEC
 *	ask				no
	rep			TRUE/FASLE */
#define MT_INT_CFG_AEC				EV_MTC_BGN + 0x114
/*	��ѯ�Ƿ�AGC
 *	ask				no
	rep			TRUE/FASLE */
#define MT_INT_CFG_AGC				EV_MTC_BGN + 0x115
/*	��ѯ��ѡЭ������
 *	ask				no
	rep				TAVPriorStrategy */
#define MT_INT_CFG_AVPRIOR			EV_MTC_BGN + 0x116
/*	��ѯ��������
 *	ask				no
	rep				u8 ������С */
#define MT_INT_CFG_INVOL			EV_MTC_BGN + 0x117
/*	��ѯ�������
 *	ask				no
	rep				u8 ������С */
#define MT_INT_CFG_OUTVOL			EV_MTC_BGN + 0x118
/*	��ѯͼ������
 *	ask			no
	rep			TImageAdjustParam */
#define MT_INT_CFG_IMAGE			EV_MTC_BGN + 0x119
/*	��ѯ��Ƶ��ʽ
 *	ask			EmVideoType
	rep			EmVideoStandard */
#define MT_INT_CFG_VSTAND			EV_MTC_BGN + 0x11a
/*	��ѯ��������
 *	ask			no
	rep			u32   �������� */
#define MT_INT_CFG_CALLRATE			EV_MTC_BGN + 0x11b
/*	��ѯ����ͷ����
 *	ask			u8 ����ͷ����
	rep			TCameraCfg */
#define MT_INT_CFG_CAMREA			EV_MTC_BGN + 0x11c
/*	��ѯ��ý������
 *	ask			no	
	rep			TStreamMedia */
#define	MT_INT_CFG_STREAM			EV_MTC_BGN + 0x11d
/*	��ѯȫ����·��������Ϣ
 *	ask			no	
	rep			tplarray<TRouteCfg> */
#define MT_INT_CFG_ALLROUTECFG		EV_MTC_BGN + 0x11e

//��ַ�� 
/* ��ַ����Ŀ����
   ask	N/A
   rep	u32	��Ŀ����*/
#define MTC_INT_ENTRY_COUNT			EV_MTC_BGN + 0x120

/* ��ַ����Ŀ������
   ask	N/A
   rep	u32	��Ŀ������*/
#define MTC_INT_GROUP_COUNT			EV_MTC_BGN + 0x121

/* ��ȡ��Ŀ
   ask	u32		��Ŀ����
   rep	CAddrEntry	��Ŀ*/
#define MTC_INT_ENTRY				EV_MTC_BGN + 0x122

/* ��ȡ��Ŀ��
   ask	u32				��Ŀ������
   rep	CAddrMultiSetEntry	��Ŀ��*/
#define MTC_INT_GROUP				EV_MTC_BGN + 0x123

/* ��һ����ַ����Ŀ
	ask N/A
	rep CAddrEntry		��Ŀ*/
#define MTC_INT_FIRSTENTRY			EV_MTC_BGN + 0x0124

/* ��һ����ַ����Ŀ
	ask u32				����
	rep CAddrEntry		��Ŀ*/
#define MTC_INT_NEXTENTRY			EV_MTC_BGN + 0x0125

/* ��һ����ַ����Ŀ
	ask N/A
	rep CAddrEntry		��Ŀ*/
#define MTC_INT_FIRSTGROUP			EV_MTC_BGN + 0x0126

/* ��һ����ַ����Ŀ
	ask u32				����
	rep CAddrEntry		��Ŀ*/
#define MTC_INT_NEXTGROUP			EV_MTC_BGN + 0x0127
/* �Ƿ���ڵ�ǰ��ַ��Ŀ
	ask CAddrEntry  ��ַ��Ŀ
    rep BOOL32		�������*/
#define MTC_INT_ISEXIST_ENTRY    	EV_MTC_BGN + 0x0128

/* �Ƿ���ڵ�ǰ����Ŀ
	ask CAddrMultiSetEntry  ����Ŀ
    rep BOOL32		�������*/
#define MTC_INT_ISEXIST_GROUP    	EV_MTC_BGN + 0x0129


//cuser
/* �û�����-����ȫ���û�
	ask N/A
	rep BOOL			�������*/
#define MTC_INT_REQALLUSERS			EV_MTC_BGN + 0x0130

/* �û�����-��ȡ�û���Ŀ
	ask N/A
	rep u32		�û���Ŀ*/
#define MTC_INT_GETUSERCOUNTS		EV_MTC_BGN + 0x0131

/* �û�����-��ȡȫ���û�
	ask N/A
	rep	u32				�û���Ŀ
		CUserFullInfo*	�û�����*/
#define MTC_INT_GETALLUSERS			EV_MTC_BGN + 0x0132
/* �Ƿ���ڵ�ǰ�û�
	ask CUserFullInfo  �û�
    rep BOOL32		�������*/
#define MTC_INT_ISEXIST_USER    	EV_MTC_BGN + 0x0133

//cmutilpointconf
/* ��ǰ�������б�
   ask	N/A
   rep	u32		������Ŀ
		_TCONFINFO*	��������*/
#define MTC_INT_CONFLIST			EV_MTC_BGN + 0x140

/* �Ƿ����ڵȴ����������Ӧ
   ask	N/A
   rep	BOOL	TRUE���ڵȴ���Ӧ,FALSEδ�ȴ���Ӧ*/
#define MTC_INT_WAITING_CREATE		EV_MTC_BGN + 0x141

/* �Ƿ����ڵȴ��������뱻��׼
   ask	N/A
   rep	BOOL	TRUE���ڵȴ����������Ӧ,FALSEδ�ȴ���Ӧ*/
#define MTC_INT_WAITING_JOIN		EV_MTC_BGN + 0x142

/* �Ƿ����ڶ�������
   ask	N/A
   rep	BOOL	TRUE���ڶ�������,FALSEδ�ڶ�������*/
#define MTC_INT_MCONF				EV_MTC_BGN + 0x143

/* �Ƿ���ѯ��
   ask	N/A
   rep	BOOL	TRUE������ѯ��,FALSEδ����ѯ��*/
#define MTC_INT_POLLING				EV_MTC_BGN + 0x144

/* ����ն��б�
   ask	N/A
   rep	u32	�ն���Ŀ
		CMtcMt	����ն�����*/
#define MTC_INT_MTLIST				EV_MTC_BGN + 0x145

/* �������ն��б�
   ask	N/A
   rep	u32	�ն���Ŀ
		CMtcMt	�����ն�����*/
#define MTC_INT_ONLINE_MTLIST		EV_MTC_BGN + 0x146

/* �����ն�
   ask	N/A
   rep	CMtcMt	��ǰ�����ն�*/
#define MTC_INT_SPEAKER				EV_MTC_BGN + 0x147

/* ��ϯ�ն�
   ask	N/A
   rep	CMtcMt	��ǰ��ϯ�ն�*/
#define MTC_INT_CHAIRMAN			EV_MTC_BGN + 0x148

/* ���������ն��б�
   ask	N/A
   rep	u32	�ն���Ŀ
		CMtcMt	��ǰ��������ն�����*/
#define MTC_INT_REQ_JOIN			EV_MTC_BGN + 0x149

/* ���뷢�Ե��ն��б�
   ask	N/A
   rep	u32	�ն���Ŀ
		CMtcMt	��ǰ���뷢���ն�����*/
#define MTC_INT_REQ_SPEAK			EV_MTC_BGN + 0x14a

/* ������ϯ���ն��б�
   ask	N/A
   rep	u32	�ն���Ŀ
		CMtcMt	��ǰ������ϯ�ն�����*/
#define MTC_INT_REQ_CHAIRMAN		EV_MTC_BGN + 0x14b
/* ��ȡ����ID
	ask N/A
    rep BOOL		�������
        char*   ����ID�ַ�������ָ��*/
#define MTC_INT_GETCURRENTCONF			EV_MTC_BGN + 0x014c

/* ��ȡ��ǰѡ���ն�
	ask N/A
    rep BOOL		�������
        CMtcMt      �ն�*/
#define MTC_INT_GETCURRENTCHOICE    	EV_MTC_BGN + 0x014d
/* �Ƿ��ڲ廰
	ask N/A  
    rep BOOL32		�������*/
#define MTC_INT_ISCHIME      	    EV_MTC_BGN + 0x014e

/* ��õ�ǰ��ƵԴ
	ask N/A  
    rep CMtcMt		�������*/
#define MTC_INT_GETVSOURCE      	EV_MTC_BGN + 0x014f
/* ��õ�ǰ��Ƶ����״̬
	ask N/A  
    rep CMtcMt		�������*/
#define MTC_INT_GETVMPINFO      	    EV_MTC_BGN + 0x0151

/* ��õ�ǰ�ն�״̬
	ask N/A  
    rep _TTERSTATUS		�������*/
#define MTC_INT_GETMTSTATUS      	    EV_MTC_BGN + 0x0152
/* ��ǰ��Ƶ����Դ
   ask	N/A
   rep	u32	��ǰ��Ƶ����Դ*/
#define MTC_INT_VSRC				EV_MTC_BGN + 0x0153
/*��ȡ�ڶ�������ĳ���ն˵ı�����Ϣ*/
#define MTC_INT_GETMTINFO					EV_MTC_BGN + 0X0215

//P2pconf
/* �Ƿ��ڵ�Ե������
   ask	N/A
   rep	BOOL	TRUE�ڵ�Ե������,FALSE���ڵ�Ե������*/
#define MTC_INT_P2PCONF					EV_MTC_BGN + 0x160

/* �Ƿ����ں��������ն�
   ask	N/A
   rep	BOOL	TRUE���ں���,FALSEû�ں���*/
#define MTC_INT_CALLING					EV_MTC_BGN + 0x161
/*��ȡ��Ե�����к����ն˵���Ϣ*/
#define MTC_INT_P2PCALLER				EV_MTC_BGN + 0x162

/* ��ȡ��Ե�����б����ն˵���Ϣ*/
#define MTC_INT_P2PMTME						EV_MTC_BGN + 0x163

//crometectrl
/* ң��������״̬
   ask	N/A
   rep	BOOL	TRUE�ѿ���,FALSE�ѽ���*/
#define MTC_INT_REMOTECTRL			EV_MTC_BGN + 0x169

//cmonintor
/* �Ƿ���˫��
	ask N/A  
    rep BOOL32		�������*/
#define MTC_INT_IS_DUAL         	EV_MTC_BGN + 0x016a

/* ��ȡ˫������
	ask N/A  �û�
    rep u8		�������*/
#define MTC_INT_GETDUALTYPE    	    EV_MTC_BGN + 0x016b
/* �Ƿ���˼����
   ask	N/A
   rep	BOOL	TRUE�Ѽ��,FALSEδ���*/
#define MTC_INT_MONITOR_NEAR		EV_MTC_BGN + 0x16c

/* �Ƿ�Զ�˼����
   ask	N/A
   rep	BOOL	TRUE�Ѽ��,FALSEδ���*/
#define MTC_INT_MONITOR_FAR			EV_MTC_BGN + 0x16d

//caudio
/* �Ƿ���˾���
   ask	N/A
   rep	BOOL	TRUE������,FALSEδ����*/
#define MTC_INT_SPEAKER_MUTE		EV_MTC_BGN + 0x0170

/* �Ƿ��������
   ask	N/A
   rep	BOOL	TRUE������,FALSEδ����*/
#define MTC_INT_MIC_MUTE			EV_MTC_BGN + 0x171

/* �������
   ask	N/A
   rep	u32	�������*/
#define MTC_INT_SPEAKER_VOLUME		EV_MTC_BGN + 0x172

/* ��������
   ask	N/A
   rep	u32	��������*/
#define MTC_INT_MIC_VOLUME			EV_MTC_BGN + 0x173

//��� һ����Ϣ
#define MTCLIB_TO_UI_LASTMSG		EV_MTC_BGN + 0x174