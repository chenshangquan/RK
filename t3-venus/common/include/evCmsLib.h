/*****************************************************************************
ģ����      : cms����̨
�ļ���      : evCmsLib.h
����ļ�    : 
�ļ�ʵ�ֹ���: ������Ϣ����cms��UI���ֺ�lib��umclib �� cnclib�����ֹ�ͬʹ�ã�
����        : �����
�汾        : V1.0  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2011/4/23   1.0         �����      ����
*******************************************************************************/
#pragma once

#ifndef _EVCMSLIB_20110423_H_
#define _EVCMSLIB_20110423_H_

#include "msgIdDispatch.h"
#include "tpeventcomm.h"

/** @defgroup  cms ��Ϣ���岿��
 *  @{
 */

// �������̨�ڲ���Ϣ  

//#define CMS_MSG_BEGIN		WM_USER + 0x100


//umcLib����Ϣ����
enum EmUiUmcMsg
{

#define UI_UMC_MSG_BEGIN    CMS_MSG_BEGIN

	/************************************************************************/
	/** ����  UMS  
	wparam = BOOL  //�Ƿ����ӳɹ�
	lparam = errorCode*/
	/************************************************************************/
	ev_UIUMSConnected		=	UI_UMC_MSG_BEGIN,
#define	UI_UMS_CONNECTED    ev_UIUMSConnected
	
		
		/************************************************************************/
		/**�ѶϿ�UMS
		wParam = 0
		lparam = 0*/
		/************************************************************************/
		ev_UIUmsDisconnected,
#define UI_UMS_DISCONNECTED	 ev_UIUmsDisconnected



        /************************************************************************/
		/**���˻��Ѿ�����һ���ط���¼
		wParam = u32_IP
		lparam = 0*/
		/************************************************************************/
		ev_UIUmsGrabLoginNotify,
#define UI_UMS_GRAB_LOGIN_NOTIFY	 ev_UIUmsGrabLoginNotify

		/************************************************************************/
		/**����IP����ץ��ʱ����ֹ��¼
		wParam = u32_IP
		lparam = 0*/
		/************************************************************************/
		ev_UICnsRefuseLoginNotify,
#define UI_CNS_REFUSE_LOGIN_NOTIFY	 ev_UICnsRefuseLoginNotify

        /************************************************************************/
		/**UMS�Ĵ�����Ϣ֪ͨ
		wParam = TTPUmsReasonInd
		lparam = 0*/
		/************************************************************************/
		ev_UIUmsReasonInd,
#define UI_UMS_UMSREASON_IND	 ev_UIUmsReasonInd
		

    	/************************************************************************/
		/** ums �����ʱ
		wParam = 0
		lparam = 0*/
		/************************************************************************/
		ev_UIUmsCmdTimeout,
#define UI_UMS_CMD_TIMEOUT	 ev_UIUmsCmdTimeout


        /************************************************************************/
		/** ums ��¼�����ʱ
		wParam = 0
		lparam = 0*/
		/************************************************************************/
		ev_UIUmsLoginTimeout,
#define UI_UMS_LOGIN_TIMEOUT	 ev_UIUmsLoginTimeout
	  
   
    	/************************************************************************/
		/** ����ģ���������ظ�
		wParam = 0
		lparam = 0*/
		/************************************************************************/
		ev_UIUmsOperateConfTemplateRet,
#define UI_UMS_OPERATE_CONFTEMP_RET	 ev_UIUmsOperateConfTemplateRet

		/************************************************************************/
		/** ɾ��ȫ��ģ����ϢӦ��
		wParam = 0
		lparam = 0*/
		/************************************************************************/
		ev_UIUmsDelAllConftempRet,
#define UI_UMS_DEL_ALL_CONFTEMP_RET	 ev_UIUmsDelAllConftempRet

		 /************************************************************************/
		 /**	����ģ�����֪ͨ
			wParam = confTempID  //��������Ļ���ģ��ID��ɾ��ʱΪ��һ��Ҫɾ����ģ��ID
			lparam = 0*/
		/************************************************************************/ 
        ev_UIUmsRefreshConfTemplateList ,
#define UI_UMS_REFRESH_CONFTEMPLATE_LIST  ev_UIUmsRefreshConfTemplateList



    	/************************************************************************/
		/** �û���������ظ�
		wParam = 0
		lparam = 0*/
		/************************************************************************/
		ev_UIUmsOperateUserRet,
#define UI_UMS_OPERATE_USER_RET	 ev_UIUmsOperateUserRet


		 /************************************************************************/
		 /**	�û�����֪ͨ
			wParam = 0
			lparam = 0*/
		/************************************************************************/ 
	    ev_UIUmsRefreshUserList  ,
#define UI_UMS_REFRESH_USER_LIST ev_UIUmsRefreshUserList


        /************************************************************************/
		 /**	���»����б�
			wParam = 0
			lparam = 0*/
		/************************************************************************/ 
	    ev_UIUmsRefreshConfList   ,
#define UI_UMS_REFRESH_CONF_LIST ev_UIUmsRefreshConfList 



	    /************************************************************************/
		 /**	��������ظ�
			wParam = confTemplateID 
			lparam =  errorCode*/
		/************************************************************************/ 
	    ev_UIUmsStartConfTemplateRsp  ,
#define UI_UMS_START_CONFTEMPLATE_RSP ev_UIUmsStartConfTemplateRsp
        

		/************************************************************************/
		 /**	����cns���ظ�
			wParam = strCnsInfoE164/alias 
			lparam =  errorCode*/
		/************************************************************************/ 
	    ev_UIUmsInviteCnsRsp  ,
#define UI_UMS_INVITE_CNS_RSP ev_UIUmsInviteCnsRsp


        /************************************************************************/
		 /**���÷����˽��
			wParam = confID 
			lparam =  EmTpApplySpeakerRet*/
		/************************************************************************/ 
	    ev_UIUmsSetSpeakerRsp  ,
#define UI_UMS_SET_SPEAKER_RSP ev_UIUmsSetSpeakerRsp


        /************************************************************************/
		 /**�����������
			wParam = confID 
			lparam =  bStart*/
		/************************************************************************/ 
	    ev_UIUmsSetMuteCnsRsp  ,
#define UI_UMS_SET_MUTE_CNS_RSP ev_UIUmsSetMuteCnsRsp


        /************************************************************************/
		 /**���þ������
			wParam = confID 
			lparam =  bStart*/
		/************************************************************************/ 
	    ev_UIUmsSetQuietCnsRsp  ,
#define UI_UMS_SET_QUIET_CNS_RSP ev_UIUmsSetQuietCnsRsp


        /************************************************************************/
		 /**����˫�����
			wParam = confID 
			lparam =  bStart*/
		/************************************************************************/ 
	    ev_UIUmsSetDualCnsRsp  ,
#define UI_UMS_SET_DUAL_CNS_RSP ev_UIUmsSetDualCnsRsp


        /************************************************************************/
		 /** ˫��Դ�ı�֪ͨ
			wParam = confID 
			lparam =  cnsID*/
		/************************************************************************/ 
	    ev_UIUmsDualCnsNotify,
#define UI_UMS_DUAL_CNS_NOTIFY ev_UIUmsDualCnsNotify

 
         /************************************************************************/
		 /**	���·�����֪ͨ
			wParam = confID
			lparam = speakerID*/
		/************************************************************************/ 
	    ev_UIUmsChangeSpeakerNotify,
#define UI_UMS_CHANGE_SPEAKER_NOTIFY ev_UIUmsChangeSpeakerNotify


            /************************************************************************/
		 /**	��ϯ
			wParam = confID  �¼�����ID
			lparam = */
		/************************************************************************/ 
	    ev_UIUmsChairCnsNotify,
#define UI_UMS_CHAIR_CNS_NOTIFY ev_UIUmsChairCnsNotify



    /************************************************************************/
		 /**	��������֪ͨ
			wParam = confID  �¼�����ID
			lparam = */
		/************************************************************************/ 
	    ev_UIUmsCascadeConfNotify,
#define UI_UMS_CASCADE_CONF_NOTIFY ev_UIUmsCascadeConfNotify



        /************************************************************************/
		 /**	�Ҷϻ���ظ�
			wParam = confID 
			lparam = errorCode*/
		/************************************************************************/ 
	    ev_UIUmsHangupConfRsp ,
#define UI_UMS_HANGUP_CONF_RSP ev_UIUmsHangupConfRsp


		/************************************************************************/
		 /**	���»����еĻ᳡�б�
			wParam = confID
			lparam = 0*/
		/************************************************************************/ 
	    ev_UIUmsRefreshConfCnsList  ,
#define UI_UMS_REFRESH_CONFCNS_LIST ev_UIUmsRefreshConfCnsList

 
		/************************************************************************/
		 /**	���»����еĻ᳡�б�
			wParam = confID
			lparam =  TConfCnsInfo*/
		/************************************************************************/ 
	    ev_UIUmsUpdateConfCnsList  ,
#define UI_UMS_UPDATE_CONFCNS_LIST ev_UIUmsUpdateConfCnsList
 

		/************************************************************************/
		 /**	���»��� 
		 
		/************************************************************************/ 
	    ev_UIUmsUpdateConfInfo  ,
#define UI_UMS_UPDATE_CONFINFO ev_UIUmsUpdateConfInfo


		/************************************************************************/
		 /**	���»����еĻ����б�
			wParam = confID
			lparam = 0*/
		/************************************************************************/ 
	    ev_UIUmsRefreshConfAudMixList  ,
#define UI_UMS_REFRESH_CONFAUDMIX_LIST ev_UIUmsRefreshConfAudMixList

        /************************************************************************/
		 /** ���»����еĻ����б�-- ����cns���ڻ���
			wParam = confID
			lparam = 0*/
		/************************************************************************/ 
	    ev_UIUmsRefreshConfAudMixListLocal  ,
#define UI_UMS_REFRESH_CONFAUDMIX_LIST_LOCAL ev_UIUmsRefreshConfAudMixListLocal


		/************************************************************************/
		 /**	���»�������ѯ�б�
			wParam = confID
			lparam = 0*/
		/************************************************************************/ 
	    ev_UIUmsRefreshConfPollList  ,
#define UI_UMS_REFRESH_CONFPOLL_LIST ev_UIUmsRefreshConfPollList

 




 	/************************************************************************/
		 /** umsע���������Ϣ֪ͨ
			wParam = 0
			lparam = 0*/
		/************************************************************************/ 
	    ev_UIUmsRegInfoNotify  ,
#define UI_UMS_REG_INFO_NOTIFY ev_UIUmsRegInfoNotify


  	/************************************************************************/
		 /**	umsע����������
			wParam = EmTpCnsRegUms:ע�᷵�صĴ�����
			lparam = 0*/
		/************************************************************************/ 
	    ev_UIUmsRegServRsp  ,
#define UI_UMS_REG_SERV_RSP ev_UIUmsRegServRsp


	/************************************************************************/
		 /**	umsIP
			wParam = EmTpCnsRegUms: 
			lparam = 0*/
		/************************************************************************/ 
	    ev_UIUmsEthnetInfoNotify  ,
#define UI_UMS_ETHNETINFO_NOTIFY ev_UIUmsEthnetInfoNotify

        
	/************************************************************************/
		 /**	umsˢ�µ���ǽ�б�֪ͨ
			wParam =  HandleID
			lparam = 0*/
		/************************************************************************/ 
	    ev_UIUmsRefreshTvwLstNotify  ,
#define UI_UMS_REFRESH_TVW_LIST_NOTITFY ev_UIUmsRefreshTvwLstNotify

        /************************************************************************/
		 /**	���� ����ǽ �ظ�
			wParam =  TRUE��Ack�� FALSE��NAck
			lparam =  HandleID/
		/************************************************************************/ 
	    ev_UIUmsPlayHduRsp  ,
#define UI_UMS_PLAY_HDU_RSP ev_UIUmsPlayHduRsp


               /************************************************************************/
		 /**	ֹͣ���� ����ǽ �ظ�
			wParam =  TRUE��Ack�� FALSE��NAck
			lparam =  HandleID/
		/************************************************************************/ 
	    ev_UIUmsStopPlayHduRsp  ,
#define UI_UMS_STOP_PLAY_HDU_RSP  ev_UIUmsStopPlayHduRsp


               /************************************************************************/
		 /**	 ����ǽ���Ƿ�������֪ͨ
			wParam =  HandleID 
			lparam =  BOOL/
		/************************************************************************/ 
	    ev_UIUmsHudCodeStreamNotify  ,
#define UI_UMS_HDU_CODE_STREAM_NOTIFY  ev_UIUmsHudCodeStreamNotify
        


        /************************************************************************/
		/**	 ϵͳʱ��֪ͨ
		/************************************************************************/ 
	    ev_GetUmsSystimeNotify  ,
#define UI_GET_UMS_SYSTIME  ev_GetUmsSystimeNotify


        /************************************************************************/
		/**	 �����ж�֪ͨ
		/************************************************************************/ 
	    ev_HungUp_Conf_Reason,
#define UI_HUNGUP_UMS_CONF_REASON  ev_HungUp_Conf_Reason

        /************************************************************************/
		/**	 ����ǽ���֪ͨ
		/************************************************************************/ 
        ev_Tvw_HduStyleNotify,
#define UI_UMS_HDUSTYLE_NOTIFY  ev_Tvw_HduStyleNotify

        /************************************************************************/
		/**	 ����ǽ����Ӧ
		/************************************************************************/ 
        ev_Tvw_HduStyleRsp,
#define UI_UMS_HDUSTYLE_RSP  ev_Tvw_HduStyleRsp

		/************************************************************************/
		/**	 ���µ���ǽԤ����Ӧ
		/************************************************************************/ 
        ev_Tvw_HduStyleUpdateRsp,
#define UI_UMS_HDUSTYLE_UPDATE_RSP  ev_Tvw_HduStyleUpdateRsp

        /************************************************************************/
		/**	 ɾ������ǽԤ��Ӧ��
		/************************************************************************/ 
//         ev_Tvw_HduStyle_Del_Rsp,
// #define UI_UMS_HDUSTYLE_DEL_RSP  ev_Tvw_HduStyle_Del_Rsp

        /************************************************************************/
		/**	 ����ǽ���֪ͨ
             To Umc
		/************************************************************************/ 
        ev_Tvw_HduPlanNotify,
#define UI_UMS_HDUPLAN_NOTIFY  ev_Tvw_HduPlanNotify

        /************************************************************************/
		/**	 ���»���ģ����Դռ�����
             To Umc
		/************************************************************************/ 
        ev_ConfTmp_ResUsedCountNotify,
#define UI_UMS_CONFTMPRESUSEDCOUNT_NOTIFY  ev_ConfTmp_ResUsedCountNotify


		ev_UIUmsEnd,
#define UI_UMS_MSG_END  ev_UIUmsEnd
		
} ;


//cncLib����Ϣ����
enum EmUiCnsMsg
{

#define UI_CNC_MSG_BEGIN  	UI_UMS_MSG_END + 0x1 

	/************************************************************************/
	/** ����  CNS 
	wparam = 0
	lparam = 0*/
	/************************************************************************/
	ev_UICnsConnect	= UI_CNC_MSG_BEGIN,
#define	UI_CNS_CONNECTED  ev_UICnsConnect
	
	/************************************************************************/
	/** �ѶϿ�CNS
	wParam = 0
	lparam = 0*/
	/************************************************************************/
	ev_UICnsDisconnected,
#define UI_CNS_DISCONNECTED	 ev_UICnsDisconnected

   /************************************************************************/
	/** ��¼CNS ���ջظ���ʱ
	wParam = 0
	lparam = 0*/
	/************************************************************************/
	ev_UICnsLoginTimeOut,
#define UI_CNS_LOGIN_TIMEOUT	 ev_UICnsLoginTimeOut
		 
    
	/************************************************************************/
	/**	���µ�ַ��
		wParam = 0
		lparam = 0*/
	/************************************************************************/ 
	ev_UIAddrbookChanged,
#define UI_CNS_ADDRBOOK_CHANGED		ev_UIAddrbookChanged

	/************************************************************************/
	/**	��ַ�������Ŀ֪ͨ
		wParam = EntryIndex
		lparam = 0*/
	/************************************************************************/ 
	ev_UIAddrbookAddEntry,
#define	UI_CNS_ADDRBOOK_ADDENTRY    ev_UIAddrbookAddEntry

	/************************************************************************/
	/**	��ַ�������Ŀ���޸���Ŀ֪ͨ
		wParam = EntryIndex
		lparam = 0*/
	/************************************************************************/ 
	ev_UIAddrbookAddGroup,
#define	UI_CNS_ADDRBOOK_ADDGROUP    ev_UIAddrbookAddGroup

	ev_UIAddrbookModify,
#define	UI_CNS_ADDRBOOK_MODIFY      ev_UIAddrbookModify

    /************************************************************************/
	/**	��ַ������ʧ��֪ͨ
		wParam = EntryIndex
		lparam = 0*/
	/************************************************************************/ 
    ev_UIAddrbookOptFailed,
#define	UI_CNS_ADDRBOOKOPT_FAILED      ev_UIAddrbookOptFailed

	/************************************************************************/
	/**	CNS��Ϣ
		wParam = 0
		lparam = 0*/
	/************************************************************************/ 
	ev_UICnsInfoNotify,
#define	UI_CNS_CNSINFO_NOTIFY       ev_UICnsInfoNotify

	/************************************************************************/
	/**	����״̬
		wParam = 0
		lparam = 0*/
	/************************************************************************/ 
	ev_UICnsConfStateNotify,
#define	UI_CNS_CONFSTATE_NOTIFY     ev_UICnsConfStateNotify


	/************************************************************************/
	/**	cns �뿪����
		wParam = 0
		lparam = 0*/
	/************************************************************************/ 
	ev_UICnsLeaveConfNotify,
#define	UI_CNS_LEAVECONF_NOTIFY     ev_UICnsLeaveConfNotify


 	/************************************************************************/
	/** ��״̬֪ͨ
	wParam = screenID
	lparam = emScreenState  
	/************************************************************************/
	ev_UiScreenStateNotify,
#define UI_CNS_SCREEN_STATE_NOTIFY  ev_UiScreenStateNotify

	/************************************************************************/
	/** ����֪ͨ
	wParam = screenID
	lparam = cstringCnsName */
	/************************************************************************/
	ev_UiScreenNameNotify,
#define UI_CNS_SCREEN_NAME_NOTIFY   ev_UiScreenNameNotify

 

	/************************************************************************/
	/** ����ѡ���ظ�
	wParam = screenID
	lparam = bScucces */
	/************************************************************************/
	ev_UiCnsSelViewRsp,
#define UI_CNS_SEL_VIEW_RSP   ev_UiCnsSelViewRsp


    /************************************************************************/
	/** ȡ��ѡ���ظ�
	wParam = screenID
	lparam = bScucces */
	/************************************************************************/
	ev_UiCnsCancleSelViewRsp,
#define UI_CNS_CANCLE_SEL_VIEW_RSP   ev_UiCnsCancleSelViewRsp

    /************************************************************************/
	/** ������ѯ�ظ�
	wParam =  bSucess
	lparam = emReslut */
	/************************************************************************/
	ev_UiCnsStartPollRsp,
#define UI_CNS_START_POLL_RSP   ev_UiCnsStartPollRsp


    /************************************************************************/
	/** ��ѯ״̬֪ͨ
	wParam =  bPoll
	lparam = 0 */
	/************************************************************************/
	ev_UiCnsPollStateNty,
#define UI_CNS_POLL_STATE_NOTIFY   ev_UiCnsPollStateNty


        /************************************************************************/
	/** ��Ե����Ҷ�֪ͨ
	wParam =  bPoll
	lparam = 0 */
	/************************************************************************/
	evUiCnsHungupP2pNty,
#define UI_CNS_HUNGUP_P2P_NOTIFY   evUiCnsHungupP2pNty

   /************************************************************************/
	/** ����˫���ظ�
	wParam =  bStart
	lparam = bScucces */
	/************************************************************************/
	ev_UiCnsStartDualRsp,
#define UI_CNS_START_DUAL_RSP   ev_UiCnsStartDualRsp

	/************************************************************************/
	/** ˫��״̬֪ͨ
	wParam =  bStart
	lparam = bScucces */
	/************************************************************************/
	ev_UiCnsDualStateNty,
#define	UI_CNS_DUAL_STATE_NOTIFY   ev_UiCnsDualStateNty

	
    	/************************************************************************/
	/** ˫��״̬֪ͨ
	wParam =  bStart
	lparam = bScucces */
	/************************************************************************/
	ev_UiCnsRecvDualNty,
#define	UI_CNS_RECV_DUAL_NOTIFY   ev_UiCnsRecvDualNty
	
	/************************************************************************/
	/** ˫��������Կ֪ͨ
	/************************************************************************/
    ev_UiCnsRecvDualKeyNty,
#define UI_CNS_DUAL_KEY_NOTIFY   ev_UiCnsRecvDualKeyNty

    	/************************************************************************/
	/** ����˫��ʱ�쳣�ж�
 
	/************************************************************************/
	ev_UiRecvDualInterruptNty,
#define	UI_RECV_DUAL_INTERRUPT   ev_UiRecvDualInterruptNty

	/************************************************************************/
	/** ������ϯ
	wParam = seatID
	lparam =  0 */
	/************************************************************************/
	ev_UiSpokesSeatNotify,
#define UI_CNS_SPOKES_SEAT_NOTIFY   ev_UiSpokesSeatNotify

	/************************************************************************/
	/* ��������֪ͨ  
	wparam = bQuite 	�Ǿ�����������.TRUE ������ FALSE ����
	lparam = bOn		�ǿ������ǹر�.��������ʹ��ǰû����Ƶ���,��֮�ǹرվ���*/
	/************************************************************************/
	ev_UiCnsQuiteMute,
#define UI_CNS_QUITE_MUTE           ev_UiCnsQuiteMute

	/************************************************************************/
	/* ������������֪ͨ  
	wparam = 0 	
	lparam = 0		
	/************************************************************************/
	ev_UiCnsInVolUpdate,
#define	UI_CNS_INVOL_UPDATE         ev_UiCnsInVolUpdate

	/************************************************************************/
	/* ���������֪ͨ  
	wparam = 0 	
	lparam = 0		
	/************************************************************************/
	ev_UiCnsOutVolUpdate,
#define	UI_CNS_OUTVOL_UPDATE        ev_UiCnsOutVolUpdate      
    
	/************************************************************************/
	/**	Sipע����Ϣ
		wParam = 0
		lparam = 0*/
	/************************************************************************/ 
	ev_UIRegSipNotify,
#define	UI_CNS_REGSIP_NOTIFY       ev_UIRegSipNotify

	/************************************************************************/
	/**	Sipע���Ƿ�ɹ�
		wParam = BOOL
		lparam = �᳡��*/
	/************************************************************************/ 
	ev_UIRegSipResultNotify,
#define	UI_CNS_REGRESULT_NOTIFY       ev_UIRegSipResultNotify

	/************************************************************************/
	/**	Sipע������ظ�֪ͨ
		wParam = BOOL
		lparam = �᳡��*/
	/************************************************************************/ 
	ev_UIRegSipAliasRepeatNotify,
#define	UI_CNS_SIPREG_ALIASREPEAT_NOTIFY       ev_UIRegSipAliasRepeatNotify

    /************************************************************************/
	/**	�õ�GKע����
	 
	/************************************************************************/ 
	ev_UIRegGkResultRsp,
#define	UI_CNS_REG_GK_RSP       ev_UIRegGkResultRsp


     /************************************************************************/
	/**	������֪ͨ GKע����Ϣ
	 
	/************************************************************************/ 
	ev_UIRegGkNty,
#define	UI_CNS_REG_GK_NTY       ev_UIRegGkNty


	/**	������Ϣ֪ͨ
		wParam = 0
		lparam = 0*/
	/************************************************************************/
	ev_UICnsEthnetInfoNotify,
#define	UI_CNS_ETHNETINFO_NOTIFY       ev_UICnsEthnetInfoNotify

	/**	˫����������Ϣ֪ͨ
		wParam = 0
		lparam = 0*/
	/************************************************************************/
	ev_UICnCfgWEthnetNty,
#define	UI_CNS_CFGWETHNET_NTY       ev_UICnCfgWEthnetNty

	/**	˫����������Ϣ֪ͨ
		wParam = 0
		lparam = 0*/
	/************************************************************************/
	ev_UICnCfgEthStateNty,
#define	UI_CNS_CFGETHSTATE_NTY       ev_UICnCfgEthStateNty

	/**	˫����������Ϣ֪ͨ
		wParam = 0
		lparam = 0*/
	/************************************************************************/
	ev_UICnCfgWEthnetRsp,
#define	UI_CNS_CFGWETHNET_RSP       ev_UICnCfgWEthnetRsp
	
	/************************************************************************/
	/**	���᳡��֪ͨ
		wParam = 0
		lparam = 0*/
	/************************************************************************/ 
	ev_UICnsMainRoomInd,
#define	UI_CNS_MAINROOM_NOTIFY       ev_UICnsMainRoomInd

	/************************************************************************/
	/**	�᳡����֪ͨ
		wParam = �᳡��
		lparam = 0*/
	/************************************************************************/ 
	ev_UICnsRoomOffline,
#define UI_CNS_ROOMOFFLINE           ev_UICnsRoomOffline

    /************************************************************************/
	/**	ϵͳʱ��ظ�
		wParam = TTpTime
		lparam = 0*/
	/************************************************************************/ 
	ev_UICnsSystimeRsp,
#define UI_CNS_SYSTIME_RSP           ev_UICnsSystimeRsp

	/************************************************************************/
	/**	Cns�᳡�б�
		wParam = 0
		lparam = 0*/
	/************************************************************************/ 
	ev_UICnsCnListNty,
#define	UI_CNS_CNLIST_NOTIFY         ev_UICnsCnListNty

	/************************************************************************/
	/**	����CNS�᳡֪ͨ
		wParam = 0
		lparam = 0*/
	/************************************************************************/ 
	ev_UICnsInsConnect,
#define	UI_CNSINS_CONNECTED          ev_UICnsInsConnect
 
	/************************************************************************/
	/**	����˫�������ظ�
		wParam =   
		lparam = 0*/
	/************************************************************************/ 
	ev_UICnsStartDualCdStrmRsp,
#define	UI_CNSINS_START_DUALCODESTREAM_RSP          ev_UICnsStartDualCdStrmRsp   

	/************************************************************************/
	/**	ѡ��˫�������ظ�
		wParam =   
		lparam = 0*/
	/************************************************************************/ 
	ev_UICnsScrnDisplayDualRsp,
#define	UI_CNS_SCRN_DISPLAY_DUAL_RSP          ev_UICnsScrnDisplayDualRsp  
    

    /************************************************************************/
	/**	ȡ��ѡ��˫�������ظ�
		wParam =   
		lparam = 0*/
	/************************************************************************/ 
	ev_UICnsStopScrnDisplayDualRsp,
#define	UI_CNS_STOP_SCRN_DISPLAY_DUAL_RSP          ev_UICnsStopScrnDisplayDualRsp  
	
   /************************************************************************/
	/**	���� �ظ�
		wParam =   
		lparam = 0*/
	/************************************************************************/ 
	ev_UICnsScrnDisplayLocalRsp,
#define	UI_CNS_SCRN_DISPLAY_LOCAL_RSP          ev_UICnsScrnDisplayLocalRsp  

    /************************************************************************/
	/**ȡ��	���� �ظ�
		wParam =   
		lparam = 0*/
	/************************************************************************/ 
	ev_UICnsStopScrnDisplayLocalRsp,
#define	UI_CNS_STOP_SCRN_DISPLAY_LOCAL_RSP          ev_UICnsStopScrnDisplayLocalRsp  

	/************************************************************************/
	/**˫��Դ����֪ͨ
		wParam =   
		lparam = 0*/
	/************************************************************************/ 
	ev_UICnsRoomDualOfflineNty,
#define UI_CNS_DUALOFFLINE_NOTIFY         ev_UICnsRoomDualOfflineNty

	/************************************************************************/
	/**���»���ģ��֪ͨ
		wParam =   
		lparam = 0*/
	/************************************************************************/ 
	ev_UICnsRefreshConfTemplateList,
#define UI_CNS_REFRESH_CONFTEMPLATE_LIST         ev_UICnsRefreshConfTemplateList

	/************************************************************************/
	/**���»���ģ��֪ͨ
		wParam =   
		lparam = 0*/
	/************************************************************************/ 
	ev_UICnsRefreshGlobalAddrbook,
#define UI_CNS_REFRESH_GLOBAL_ADDRBOOK         ev_UICnsRefreshGlobalAddrbook

	/************************************************************************/
	/**���»���ģ��֪ͨ
		wParam =  BOOL : ��ʾ�Ƿ���sip��ַ 
		lparam = 0*/
	/************************************************************************/ 
	ev_UICnsRefreshGlobalAddrbookEx,
#define UI_CNS_REFRESH_GLOBAL_ADDRBOOKEX       ev_UICnsRefreshGlobalAddrbookEx

    /************************************************************************/
	/**˫��Դ��Ϣ֪ͨ
		wParam =   
		lparam = 0*/
	/************************************************************************/ 
    ev_UICnsVgaInfoNty,
#define UI_CNS_VGAINFO_NOTIFY                  ev_UICnsVgaInfoNty

    /************************************************************************/
	/**������˫��Դ��Ϣ֪ͨ
		wParam =   
		lparam = 0*/
	/************************************************************************/ 
    ev_UICnsConfVgaInfoNty,
#define UI_CNS_CONFVGAINFO_NOTIFY              ev_UICnsConfVgaInfoNty

    /************************************************************************/
	/**�������л�˫��Դ֪ͨ
		wParam =   
		lparam = 0*/
	/************************************************************************/ 
    ev_UICnsSelDualInputPortInd,
#define UI_CNS_SELDUALPORT_IND                 ev_UICnsSelDualInputPortInd

	/************************************************************************/
	/**	������֪ͨ ��̬NATע����Ϣ
	 
	/************************************************************************/ 
	ev_UIRegNatNty,
#define	UI_CNS_REG_NAT_NTY       ev_UIRegNatNty


	/************************************************************************/
	/**  ���������б�ҳ����޸����ܵ�ǰѡ�����ݷ���
	wParam = Window*   
	lparam = Type*/
	/************************************************************************/
	ev_UiCnsNetMngSelDataClick,
#define UI_CNS_MSG_NETMNGSELDATA_Click  ev_UiCnsNetMngSelDataClick
	/************************************************************************/
	/**  ϵͳ����ҳ����Ϣ֪ͨ
	wParam = Window*   
	lparam = Type*/
	/************************************************************************/
	ev_UiCnsSleepInfoNotify,
#define UI_CNS_SLEEPINFO_NOTIFY  ev_UiCnsSleepInfoNotify

    /************************************************************************/
	/**  �п��¶�֪ͨ
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiCnsSchTempNotify,
#define UI_CNS_SCHTEMP_NTY  ev_UiCnsSchTempNotify
    /************************************************************************/
	/**  �пصƹ�֪ͨ
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiCnsSchLightNotify,
#define UI_CNS_SCHLIGHT_NTY  ev_UiCnsSchLightNotify
    /************************************************************************/
	/**  �п����״̬֪ͨ
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiCnsSchStateNotify,
#define UI_CNS_SCHSTATE_NTY  ev_UiCnsSchStateNotify
    /************************************************************************/
	/**  ϵͳ��Դ���ػظ�
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiCnsSchPowerInd,
#define UI_CNS_SCHPOWER_IND  ev_UiCnsSchPowerInd
     /************************************************************************/
    /**  �ƹ⿪�ػظ�
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiCnsSchAllLightInd,
#define UI_CNS_SCHALLLIGHT_IND  ev_UiCnsSchAllLightInd
    /************************************************************************/
	/**  ���ƿ��ػظ�
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiCnsSchMidLightInd,
#define UI_CNS_SCHMIDLIGHT_IND  ev_UiCnsSchMidLightInd
    /************************************************************************/
	/**  ���ƿ��ػظ�
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiCnsSchScrLightInd,
#define UI_CNS_SCHSCRLIGHT_IND  ev_UiCnsSchScrLightInd
    /************************************************************************/
	/**  ���ӻ�״̬֪ͨ
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiCnsTVStateNotify,
#define UI_CNS_TVSTATE_NTY  ev_UiCnsTVStateNotify
    /************************************************************************/
	/**  ���ӻ����ػظ�
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiCnsSeleteTvInd,
#define  UI_CNS_SELETETV_IND ev_UiCnsSeleteTvInd
    /************************************************************************/
	/**  ���ӻ�ѡ��״̬�ظ�
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiCnsTVPowerModeInd,
#define  UI_CNS_TVPOWERMODE_IND ev_UiCnsTVPowerModeInd
    /************************************************************************/
	/**  �ĵ������״̬֪ͨ
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiCnsDCamStateNotify,
#define UI_CNS_DCAMSTATE_NTY  ev_UiCnsDCamStateNotify
    /************************************************************************/
	/**  �ĵ���������ػظ�
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiCnsDCamPowerInd,
#define UI_CNS_DCAMPOWER_IND  ev_UiCnsDCamPowerInd
    /************************************************************************/
	/**  �յ�״̬֪ͨ
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiCnsACStateNotify,
#define UI_CNS_ACSTATE_NTY  ev_UiCnsACStateNotify

	/************************************************************************/
	/**  �յ�ѡ����ظ�
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiCnsSelectAirInd,
#define  UI_CNS_SELECTAIR_IND ev_UiCnsSelectAirInd
	/************************************************************************/
	/**  �յ�ȫ��Ӧ�ÿ��������ظ�
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiCnsApplyToAllInd,
#define  UI_CNS_APPLYTOALL_IND ev_UiCnsApplyToAllInd

	/************************************************************************/
	/**  �յ���Դ����״̬֪ͨ
	wParam = *   
	lparam = */
	/************************************************************************/
//     ev_UiCnsACPowerStateInd,
// #define UI_CNS_ACPOWERSTATE_IND  ev_UiCnsACPowerStateInd
    /************************************************************************/
	/**  �пش���֪ͨ
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiTPadCentreSleepNotify,
#define UI_TPAD_CENTRESLEEP_NTY  ev_UiTPadCentreSleepNotify

    /************************************************************************/
	/**  TPad��¼�û�֪ͨ
	wParam = User*   
	lparam = */
	/************************************************************************/
    ev_UiTPadLoginUserNotify,
#define UI_TPAD_LOGINUSER_NOTIFY  ev_UiTPadLoginUserNotify

    /************************************************************************/
	/**  TPadϵͳ����֪ͨ
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiTPadUpdateSystemCmd,
#define UI_TPAD_UPDATESYS_CMD  ev_UiTPadUpdateSystemCmd

    /************************************************************************/
	/**  UMS�Ĵ�����Ϣ֪ͨ
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiUmsReason_Ind,
#define UI_CNS_UMSREASON_IND   ev_UiUmsReason_Ind

    /************************************************************************/
	/**  cnc����ϵͳ�����޸�֪ͨ  dyy 2013��8��29��
	wParam = ϵͳ����   
	lparam = */
	/************************************************************************/
    ev_UiTPadCncSetSysNameNotify,
#define UI_TPAD_SETSYSNAME  ev_UiTPadCncSetSysNameNotify

    /************************************************************************/
	/**  TPad Home����Ӧ
	wParam = *   
	lparam = */
	/************************************************************************/
    ev_UiTPadHomeKeyNotify,
#define UI_TPAD_HOMEKEY_NOTIFY  ev_UiTPadHomeKeyNotify

    /************************************************************************/
	/**  cnc����״̬֪ͨ  
	wParam =    
	lparam = */
	/************************************************************************/
    ev_UiTPadConfStateNty,
#define UI_CONFSTATE_NTY  ev_UiTPadConfStateNty

    /************************************************************************/
	/**  ����pc˫���Ľ�� 
	wParam =    
	lparam = */
	/************************************************************************/
    ev_UiTPadFileDualResult,
#define UI_FILE_DUAL_RESULT  ev_UiTPadFileDualResult

    /************************************************************************/
	/**  ����pc˫��Զ�˵�ַ 
	wParam =    
	lparam = */
	/************************************************************************/
    ev_UiTPadFileDualRcvAddr,
#define UI_FILE_DUAL_RCVADDR  ev_UiTPadFileDualRcvAddr

    /************************************************************************/
	/**  ֹͣpc˫�� 
	wParam =    
	lparam = */
	/************************************************************************/
    ev_UiTPadStopFileDual,
#define UI_FILE_DUAL_STOP  ev_UiTPadStopFileDual

    /************************************************************************/
	/**  pc˫��key��֪ͨ 
	wParam =    
	lparam = */
	/************************************************************************/
    ev_UiTPadFileDualkey,
#define UI_FILE_DUAL_KEY  ev_UiTPadFileDualkey

    /************************************************************************/
	/**  Զ������ؼ�֡ 
	wParam =    
	lparam = */
	/************************************************************************/
    ev_UiTPadFileKeyFrame,
#define UI_FILE_DUAL_KEYFRAME_REQ  ev_UiTPadFileKeyFrame

	/************************************************************************/
	/** ����ѡ������ǽ�ظ�
	wParam = screenID
	lparam = bScucces */
	/************************************************************************/
	ev_UiCnsSelTVSViewRsp,
#define UI_CNS_SEL_TVSVIEW_RSP   ev_UiCnsSelTVSViewRsp


    /************************************************************************/
	/** ȡ��ѡ������ǽ�ظ�
	wParam = screenID
	lparam = bScucces */
	/************************************************************************/
	ev_UiCnsCancleSelTVSViewRsp,
#define UI_CNS_CANCLE_SEL_TVSVIEW_RSP   ev_UiCnsCancleSelTVSViewRsp

   /************************************************************************/
	/**  ������������һ�����ݻ���
	wParam =    
	lparam = */
	/************************************************************************/
    ev_UiSelfStartWBConf,
#define UI_SELFSTARTWBCONFNTY  ev_UiSelfStartWBConf

    /************************************************************************/
	/**  �������ݻ��� 
	wParam =    
	lparam = */
	/************************************************************************/
    ev_UiJoinWBConfCmd,
#define UI_JOINWBCONF_CMD  ev_UiJoinWBConfCmd
    /************************************************************************/
	/**  ���ʻ���������뿪���ݻ���  
	wParam =    
	lparam = ip */
	/************************************************************************/
    ev_UiLeaveWBConfNty,
#define UI_LEAVEWBCONF_NTY  ev_UiLeaveWBConfNty
    /************************************************************************/
	/**  WB�»����������Tpad���� 
	wParam =    
	lparam = IP*/
	/************************************************************************/
    ev_UiNewWBConfCallReq,
#define UI_NEWWBCONFCALL_REQ  ev_UiNewWBConfCallReq

    /************************************************************************/
	/**  �����û᳡��Ϣʱ���᳡����������
	wParam =    
	lparam = �᳡�� m_achRoomName*/
	/************************************************************************/
    ev_UiConfRoomName,
#define UI_CONFROOMNAME_NTY  ev_UiConfRoomName

    /************************************************************************/
	/**  ���ݻ���״̬��������
	wParam =    
	lparam = �Ƿ������ݻ�����
	/************************************************************************/
    ev_UiWBConfStateNty,
#define UI_WBCONFSTATE_NTY  ev_UiWBConfStateNty
    /************************************************************************/
	/**  WB����IP�������� cns->tpad 
	wParam =    
	lparam = IP*/
	/************************************************************************/
    ev_UiTppSetDataServerInfoNty,
#define UI_TPPSETDATASERVERINFONTY  ev_UiTppSetDataServerInfoNty
    /************************************************************************/
	/**  WB����IP�Ƿ�����ɹ�������������� cns->tpad 
	wParam =    
	lparam = IP*/
	/************************************************************************/
	ev_UiTppSetDataServerInd,
#define	UI_TPPSETDATASERVER_IND  ev_UiTppSetDataServerInd

	/************************************************************************/
	/**  MatrixServer����IP�������� cns->tpad 
	wParam =    
	lparam = IP*/
	/************************************************************************/
	ev_UiTpSetMatrixServerInfoNty,
#define UI_TPSETMATRIXSERVERINFO_NTY ev_UiTpSetMatrixServerInfoNty

	/************************************************************************/
	/** MatrixServer����IP�Ƿ�����ɹ�������������� cns->tpad 
	wParam =    
	lparam = IP*/
	/************************************************************************/
	ev_UiTpSetMatrixServerInfoInd,
#define	UI_TPSETMATRIXSERVERINFO_IND  ev_UiTpSetMatrixServerInfoInd

	/************************************************************************/
	/**  NtpServer����IP�������� cns->tpad 
	wParam =    
	lparam = IP*/
	/************************************************************************/
	ev_UitppSetNtpServerInfoNty,
#define UI_TPSETNTPSERVERINFO_NTY ev_UitppSetNtpServerInfoNty

	/************************************************************************/
	/** NtpServer����IP�Ƿ�����ɹ�������������� cns->tpad 
	wParam =    
	lparam = IP*/
	/************************************************************************/
	ev_UitppSetNtpServerInfoInd,
#define	UI_TPSETNTPSERVERINFO_IND  ev_UitppSetNtpServerInfoInd

    /************************************************************************/
	/**  ���˿�����Ƶ����
	wParam =    
	lparam = 
	/************************************************************************/
    ev_UiSelfStartConfCmdNty,
#define UI_SELFSTARTCONF_CMD  ev_UiSelfStartConfCmdNty
    /************************************************************************/
	/**  �޸İװ������ip
	wParam =  bool �Ƿ�ɹ�  
	lparam = IP*/
	/************************************************************************/
    ev_UiSetWBServerIpNty,
#define UI_SETWBSERVERIP_NTY  ev_UiSetWBServerIpNty
    /************************************************************************/
	/**  ��Ե�������ݻ�������Ϣ cns->tpad 
	wParam =    
	lparam = IP*/
	/************************************************************************/
    ev_UiTppSetDataConfNameNty,
#define UI_TPPSETDATACONFNAMENTY  ev_UiTppSetDataConfNameNty
    /************************************************************************/
	/**  ����T300֪ͨ cns->tpad 
	wParam =    
	lparam = IP*/
	/************************************************************************/
    ev_UiTppUpDateT300Nty,
#define UI_TPPUPDATET300NTY  ev_UiTppUpDateT300Nty

    ev_UICncEnd,
#define	UI_CNC_MSG_END   ev_UICncEnd

};



//cms �߼���Ԫ�����Ϣ����
enum EmUiCmsMsg
{  

#define UI_CMS_MSG_BEGIN  UI_CNC_MSG_END + 0x1

    	/************************************************************************/
		/** �����쳣
		wParam = �쳣������
		lparam = 0*/
		/************************************************************************/
	ev_UiCMsError = UI_CMS_MSG_BEGIN,
#define UI_CMS_ERROR  ev_UiCMsError


			
    /************************************************************************/
	/**  
	wParam =  errorcode
	lparam = 0*/
	/************************************************************************/
	ev_UiConnectRsp,
#define UI_CONNECT_RSP  ev_UiConnectRsp


	/************************************************************************/
	/**  �����᳡�б��е�cns��Ŀ
	wParam =  cnsInfo
	lparam = ��������item�������Ļ��rect*/
	/************************************************************************/
	ev_UiCnsConfItemClick,
#define UI_CONF_CNS_ITEM_CLICK  ev_UiCnsConfItemClick
   

   /************************************************************************/
	/**  ��������ģ���б��е� ��Ŀ
	wParam =  wConfTempID
	lparam = ��������item�������Ļ��rect*/
	/************************************************************************/
    ev_UiCnsConfTempItemClick,
#define UI_CONF_TEMP_ITEM_CLICK  ev_UiCnsConfTempItemClick

   /************************************************************************/
	/**  ������ַ���б��е���Ŀ����
	wParam =  Args_ClickItemInfo
	lparam = 0*/
	/************************************************************************/
	ev_UiCmsAddrItemCallClick,
#define	UI_ADDR_ITEM_CALL_CLICK  ev_UiCmsAddrItemCallClick



       /************************************************************************/
	/**  ����ʱ��֪ͨ,��titlebar֪ͨ ʱ�����ý���
	wParam =  SYSTEMTIME
	lparam = 0*/
	/************************************************************************/
	ev_UiCmsUpdateTime,
#define	UI_CMS_UPDATE_SYSTEM_TIME  ev_UiCmsUpdateTime


      /************************************************************************/
	/**  ����ʱ��֪ͨ    ��ʱ�����ý���֪ͨtitlebar
	wParam =  SYSTEMTIME
	lparam = 0*/
	/************************************************************************/
	ev_UiCmsModifySystemTime,
#define	UI_CMS_MODIFY_SYSTEM_TIME  ev_UiCmsModifySystemTime

  /************************************************************************/
	/**  mainmenu ����� Toolbar
	wParam =    
	lparam = 0*/
	/************************************************************************/
	ev_UiCmsMainmenuClickToolBtn,
#define	UI_CMS_CLICK_TOOL_BTN  ev_UiCmsMainmenuClickToolBtn

    
   /************************************************************************/
	/**  calling timer ��ʱ�� ���᳡δ����
	wParam =    
	lparam = 0*/
	/************************************************************************/
	ev_UiCmsCallingTimeOut,
#define	UI_CMS_CALLING_TIME_OUT  ev_UiCmsCallingTimeOut


     /************************************************************************/
	/**  ��ʾ����dlg
	wParam =    
	lparam = 0*/
	/************************************************************************/
	ev_UiCmsShowCallingDlg,
#define	UI_UMS_SHOW_CALLING_DLG  ev_UiCmsShowCallingDlg


     /************************************************************************/
	/**  ���غ���dlg
	wParam =    
	lparam = 0*/
	/************************************************************************/
	ev_UiCmsHideCallingDlg, 
#define	UI_UMS_HIDE_CALLING_DLG  ev_UiCmsHideCallingDlg

	/************************************************************************/
	/**  ��ʾ�澯dlg
	wParam =    
	lparam = 0*/
	/************************************************************************/
	ev_UiCmsShowAlarmDlg,
#define UI_CMS_SHOW_ALARM_DLG  ev_UiCmsShowAlarmDlg 



   ev_UiCmsSwitchIme,
#define WM_SWITCH_IME  ev_UiCmsSwitchIme
 
   ev_UiCmsKeyboardClose,
#define WM_KEYBOARD_CLOSE  ev_UiCmsKeyboardClose

   /************************************************************************/
	/**  ��¼ok
	wParam =    
	lparam = 0*/
	/************************************************************************/
    ev_UiCmsLoginOk,
#define WM_CMS_UI_LOGIN_OK  ev_UiCmsLoginOk

   /************************************************************************/
	/**  �Զ���¼CNS�᳡
	wParam =    
	lparam = 0*/
	/************************************************************************/	
	ev_UiCmsAutoLogCnsIns,
#define UI_CMS_AUTOLOG_CNSINS   ev_UiCmsAutoLogCnsIns


   /************************************************************************/
	/** ����Ͽ�
	wParam =    
	lparam = 0*/
	/************************************************************************/
   ev_UiCmsNetDisconnect,
#define WM_NET_DISCONNECT  ev_UiCmsNetDisconnect

   /************************************************************************/
	/**  IP ��ͻ
	wParam =    
	lparam = 0*/
	/************************************************************************/
   ev_UiCmsIpConflict,
#define WM_NET_IPCONFLICT  ev_UiCmsIpConflict

   /************************************************************************/
	/**  ����confmenu
	wParam =    
	lparam = 0*/
	/************************************************************************/
   ev_UiCmsIUpdateConfMenu,
#define WM_CMS_UPDATE_CONFMENU  ev_UiCmsIUpdateConfMenu


    /************************************************************************/
	/**  �������ʾ��Ƶ���밴ť
	wParam =   1 ��ʾ��Ҫ�����ʾ
	lparam = 0*/
	/************************************************************************/
   ev_UiCmsShowVideo,
#define WM_CMS_SHOWVIDEO  ev_UiCmsShowVideo


    /************************************************************************/
	/**  ����mainMenu
	wParam =    
	lparam = 0*/
	/************************************************************************/
    ev_UiCmsIUpdateMainMenu,
#define WM_CMS_UPDATE_CMAINMENU  ev_UiCmsIUpdateMainMenu


    /************************************************************************/
	/**  ����mainMenu
	wParam =    
	lparam = 0*/
	/************************************************************************/
	ev_UiCmsHideVedio,
#define WM_CMS_HIDE_VEDIO  ev_UiCmsHideVedio

	/************************************************************************/
	/**  ��ʼ�ȴ�����ע����Ϣ
	wParam = Window*   
	lparam = Type*/
	/************************************************************************/
	ev_UiCncBeginWaitingRefresh,
#define UI_CNC_BEGINWAITING_REFRESH  ev_UiCncBeginWaitingRefresh

	/************************************************************************/
	/**  �����ȴ�����ע����Ϣ
	wParam = 0 
	lparam = 0*/
	/************************************************************************/
	ev_UiCncEndWaitingRefresh,
#define UI_CNC_ENDWAITING_REFRESH  ev_UiCncEndWaitingRefresh

	/************************************************************************/
	/**  ֪ͨ�����ַ��ʱʣ�����Ŀ����
	wParam = u32 
	lparam = 0*/
	/************************************************************************/
	ev_UiCncLoadAddrNumNty,
#define UI_CNC_LOADADDRNUM_NTY  ev_UiCncLoadAddrNumNty

	/************************************************************************/
	/**  �ȴ�����ע����Ϣ��ʱ
	wParam = 0 
	lparam = 0*/
	/************************************************************************/
	ev_UiCncWaitingRefreshOverTime,
#define UI_CNC_WAITINGREFRESH_OVERTIME  ev_UiCncWaitingRefreshOverTime


	/************************************************************************/
	/**  ���ش��ڵ���Ϣ 
	wParam = 0 
	lparam = 0*/
	/************************************************************************/
	ev_UiCncHideWnd,
#define UI_CNC_HIDE_WND  ev_UiCncHideWnd

	/************************************************************************/
	/**  ���з���������������ʽѡ�����Ϣ (callserverlogic2modelogic)
	wParam = TTPCallSerFormat 
	lparam = 0*/
	/************************************************************************/
	ev_UiCncCallSvr2ModeChooseModeNty,
#define UI_CNC_CALLSVR2MODECHOOSE_MODE_NTY  ev_UiCncCallSvr2ModeChooseModeNty

	/************************************************************************/
	/**  ���з���������������ʽѡ�����Ϣ (modelogic2callserverlogic)
	wParam = TTPCallSerFormat 
	lparam = 0*/
	/************************************************************************/
	ev_UiCncModeChoose2CallSvrModeNty,
#define UI_CNC_MODECHOOSE2CALLSVR_MODE_NTY  ev_UiCncModeChoose2CallSvrModeNty

	/************************************************************************/
	/**  ���з���������������ʽѡ�����Ϣ (callserverlogic2showmodelogic)
	wParam = TTPCallSerFormat 
	lparam = 0*/
	/************************************************************************/
	ev_UiCncCallSvr2ShowModeChooseModeNty,
#define UI_CNC_CALLSVR2SHOWMODECHOOSE_MODE_NTY  ev_UiCncCallSvr2ShowModeChooseModeNty

	/************************************************************************/
	/**  ���з���������������ʽѡ�����Ϣ (showmodelogic2callserverlogic)
	wParam = TTPCallSerFormat 
	lparam = 0*/
	/************************************************************************/
	ev_UiCncShowModeChoose2CallSvrModeNty,
#define UI_CNC_SHOWMODECHOOSE2CALLSVR_MODE_NTY  ev_UiCncShowModeChoose2CallSvrModeNty

	/************************************************************************/
	/**  ���з�����������Ƶ��ʽѡ�����Ϣ (callserverlogic2Audiomodelogic)
	wParam = EmTpAudioFormat
	lparam = 0*/
	/************************************************************************/
	ev_UiCncCallSvr2AudioModeNty,
#define UI_CNC_CALLSVR2AUDIO_MODE_NTY  ev_UiCncCallSvr2AudioModeNty

	/************************************************************************/
	/**  ���з�����������Ƶ��ʽѡ�����Ϣ (Audiomodelogic2callserverlogic)
	wParam = EmTpAudioFormat 
	lparam = 0*/
	/************************************************************************/
	ev_UiCncAudioMode2CallSvrNty,
#define UI_CNC_AUDIO2CALLSVR_MODE_NTY  ev_UiCncAudioMode2CallSvrNty
				
	/************************************************************************/
	/**  ̨���ϴ���������
	wParam =  ����ֵ  
	lparam = 0*/
	/************************************************************************/	
	em_CNC_CONFSIGNPROGRESS,
#define WM_CNC_FTPCONFSIGNPROGRESS  em_CNC_CONFSIGNPROGRESS		   
	
    /************************************************************************/
	/**  ������رջ��л��������� 
	wParam =    
	lparam = */
	/************************************************************************/
    ev_UiViewLocalPIPInd,
#define UI_CNS_VIEWLOCALPIP_IND  ev_UiViewLocalPIPInd
	
    /************************************************************************/
	/**  ���л�������ر�״̬֪ͨ 
	wParam =    
	lparam = */
	/************************************************************************/
    ev_UiViewLocalPIPNty,
#define UI_CNS_VIEWLOCALPIP_NTY  ev_UiViewLocalPIPNty

	ev_UiCmsMsgEnd,
#define UI_CMS_MSG_END  ev_UiCmsMsgEnd
};


enum EmTPadMsg
{
    #define EV_TPAD_MSG_BEGIN  CMS_MSG_BEGIN + 900

    ev_TPadMsg_Begin = EV_TPAD_MSG_BEGIN,

    /************************************************************************/
	/** ֪ͨTpad��¼��Ϣ
	/************************************************************************/
    ev_TPadLoginInfo_Nty,

    /************************************************************************/
	/** cnc�޸�ϵͳ���� dyy
	/************************************************************************/
    ev_TPadSetSysName_Nty,

    /************************************************************************/
	/** ֪ͨTpad Home����Ӧ
	/************************************************************************/
    ev_TPadHomeKey_Nty,

	/************************************************************************/
	/** ֪ͨTpad��Ӧ������cns����
	/************************************************************************/
    ev_TpadDisconnectCns_Nty,

    /************************************************************************/
	/** ֪ͨcnc �Ƿ����װ����  
	/************************************************************************/
    ev_WBConfStateNty,
    /************************************************************************/
	/** ֪ͨ���п�  dyy 2015-5-26
	/************************************************************************/
    ev_OpenCenterCtrl_Nty,

    ev_TPadMsg_End,
};


//umstool����Ϣ����
enum EmUiUmstoolMsg
{
#define UI_UMSTOOL_MSG_BEGIN  UMSTOOL_MSG_BEGIN + 0x1

    	/************************************************************************/
		/** �����쳣
		wParam = �쳣������
		lparam = 0*/
		/************************************************************************/
	ev_UiUMSTOOLError = UI_UMSTOOL_MSG_BEGIN,
#define UI_UMSTOOL_ERROR  ev_UiUMSTOOLError

	/************************************************************************/
	/**  ums�汾��Ϣˢ��
	wParam = Window*   
	lparam = Type*/
	/************************************************************************/
	ev_UiUmstoolUmsVerNty,
#define UI_UMSTOOL_MSG_UMSVER_NTY  ev_UiUmstoolUmsVerNty

	/************************************************************************/
	/**  ums��Ȩ��Ŀ
	wParam = Window*   
	lparam = Type*/
	/************************************************************************/
	ev_UiUmstoolAuthCountNty,
#define UI_UMSTOOL_MSG_AUTHCOUNT_NTY  ev_UiUmstoolAuthCountNty

	/************************************************************************/
	/**  ums������Ŀ
	wParam = Window*   
	lparam = Type*/
	/************************************************************************/
	ev_UiUmstoolConfCountNty,
#define UI_UMSTOOL_MSG_CONFCOUNT_NTY  ev_UiUmstoolConfCountNty

	/************************************************************************/
	/**  umsϵͳ��Ϣ
	wParam = Window*   
	lparam = Type*/
	/************************************************************************/
	ev_UiUmstoolSysInfoNty,
#define UI_UMSTOOL_MSG_SYSINFO_NTY  ev_UiUmstoolSysInfoNty

	/************************************************************************/
	/**  ums����ǽʹ�������Ϣ
	wParam = Window*   
	lparam = Type*/
	/************************************************************************/
	ev_UiUmstoolTvwUsedNty,
#define UI_UMSTOOL_MSG_TVWUSED_NTY  ev_UiUmstoolTvwUsedNty

	/************************************************************************/
	/**  ��������֪ͨ
	wParam = TTPBrdInfo ������Ϣ*   
	lparam = ��*/
	/************************************************************************/
	ev_UiUmstoolRefreshBoardNty,
#define UI_UMSTOOL_MSG_REFRESHBOARD_NTY  ev_UiUmstoolRefreshBoardNty

	/************************************************************************/
	/**  �޸ĵ�������֪ͨ
	wParam = TTPBrdCfg   ��������*   
	lparam = ��*/
	/************************************************************************/
	ev_UiUmstoolModifyBoardNty,
#define UI_UMSTOOL_MSG_MODIFYBOARD_NTY  ev_UiUmstoolModifyBoardNty

	/************************************************************************/
	/**  ɾ����������֪ͨ
	wParam = TTPBrdCfg   ��������*   
	lparam = ��*/
	/************************************************************************/
	ev_UiUmstoolDeleteBoardNty,
#define UI_UMSTOOL_MSG_DELETEBOARD_NTY  ev_UiUmstoolDeleteBoardNty

	/************************************************************************/
	/**  ��ӵ�������֪ͨ(�޸Ĺ���)
	wParam = TTPBrdCfg   ��������*   
	lparam = ��*/
	/************************************************************************/
	ev_UiUmstoolOptBoardNty,
#define UI_UMSTOOL_MSG_OPTBOARD_NTY  ev_UiUmstoolOptBoardNty

	/************************************************************************/
	/**  ����������ݽ����Ӧ����� ɾ�� �޸ģ�
	wParam = TTPBrdCfg   ��������*   
	lparam = EmTpBoardRet ʧ��ԭ��*/
	/************************************************************************/
	ev_UiUmstoolOptBoardRsp,
#define UI_UMSTOOL_MSG_OPTBOARD_RSP  ev_UiUmstoolOptBoardRsp

	/************************************************************************/
	/**  ��ӵ���ģʽ����֪ͨ(�޸� ɾ������  ����ɾ��������Ϊ��)
	wParam = TTPBrdMdlInfo   ����ģʽ��Ϣ*   
	lparam = ��*/
	/************************************************************************/
	ev_UiUmstoolOptBoardModeNty,
#define UI_UMSTOOL_MSG_OPTBOARDMODE_NTY  ev_UiUmstoolOptBoardModeNty

	/************************************************************************/
	/**  ����ģʽ�������ݽ����Ӧ����� ɾ�� �޸ģ�
	wParam = TTPBrdMdlInfo   ��������*   
	lparam = EmTpBoardRet ʧ��ԭ��*/
	/************************************************************************/
	ev_UiUmstoolOptBoardModeRsp,
#define UI_UMSTOOL_MSG_OPTBOARDMODE_RSP  ev_UiUmstoolOptBoardModeRsp

	/************************************************************************/
	/**  ����ռ�����֪ͨ   ���� ������������ϳɡ���������ռ�����
	wParam = Window*   
	lparam = Type*/
	/************************************************************************/
	ev_UiUmstoolBoardUsed,
#define UI_UMSTOOL_MSG_BOARDUSED_NTY  ev_UiUmstoolBoardUsed


	/************************************************************************/
	/**  ����ҳ������޸ĵ��嵱ǰѡ�����ݷ���
	wParam = Window*   
	lparam = Type*/
	/************************************************************************/
	ev_UiUmstoolBoardSelDataClick,
#define UI_UMSTOOL_MSG_BOARDSELDATA_Click  ev_UiUmstoolBoardSelDataClick

	/************************************************************************/
	/**  ����ǽ����ҳ������޸ĵ��嵱ǰѡ�����ݷ���
	wParam = Window*   
	lparam = Type*/
	/************************************************************************/
	ev_UiUmstoolTvwBoardSelDataClick,
#define UI_UMSTOOL_MSG_TVWBOARDSELDATA_Click  ev_UiUmstoolTvwBoardSelDataClick

	/************************************************************************/
	/**  ����ǽ������ݱ��淢��
	wParam = TTvwStyleInfo m_tSelTvwStyleInfo     ��ǰѡ�ж�Ӧ�ĵ���ǽͨ������    ���������б�ʹ��*   
	lparam = Type*/
	/************************************************************************/
	ev_UiUmstoolTvwStyleSave,
#define UI_UMSTOOL_MSG_TVWSTYLESAVE  ev_UiUmstoolTvwStyleSave

	/************************************************************************/
	/**  ����ǽ���ͨ��������ݷ���
	wParam = Window*   
	lparam = Type*/
	/************************************************************************/
	ev_UiUmstoolTvwStyleSelDataClick,
#define UI_UMSTOOL_MSG_TVWSTYLESELDATA_Click  ev_UiUmstoolTvwStyleSelDataClick

	/************************************************************************/
	/**  ����ǽ��������֪ͨ
	wParam = TTPBrdInfo ������Ϣ*   
	lparam = ��*/
	/************************************************************************/
	ev_UiUmstoolRefreshTvwBoardNty,
#define UI_UMSTOOL_MSG_REFRESHTVWBOARD_NTY  ev_UiUmstoolRefreshTvwBoardNty

	/************************************************************************/
	/**  ��ӵ���ǽ��������֪ͨ(�޸Ĺ���)
	wParam = TTPBrdCfg   ��������*   
	lparam = ��*/
	/************************************************************************/
	ev_UiUmstoolOptTvwBoardNty,
#define UI_UMSTOOL_MSG_OPTTVWBOARD_NTY  ev_UiUmstoolOptTvwBoardNty

	/************************************************************************/
	/**  ����ǽ����������ݽ����Ӧ����� �޸� ɾ����
	wParam = TTPBrdCfg   ��������*   
	lparam = EmTpBoardRet ʧ��ԭ��*/
	/************************************************************************/
	ev_UiUmstoolOptTvwBoardRsp,
#define UI_UMSTOOL_MSG_OPTTVWBOARD_RSP  ev_UiUmstoolOptTvwBoardRsp

	/************************************************************************/
	/**  ����ǽ�����������֪ͨ��ɾ����
	wParam = TTPBrdCfg   ��������*   
	lparam = EmTpBoardRet ʧ��ԭ��*/
	/************************************************************************/
	ev_UiUmstoolDelTvwBoardNty,
#define UI_UMSTOOL_MSG_DELTVWBOARD_NTY  ev_UiUmstoolDelTvwBoardNty

	/************************************************************************/
	/**  ��ӵ���ǽ����ģʽ֪ͨ(�޸Ĺ���)
	wParam = TTPBrdCfg   ��������*   
	lparam = ��*/
	/************************************************************************/
	ev_UiUmstoolOptTvwBoardModeNty,
#define UI_UMSTOOL_MSG_OPTTVWBOARDMODE_NTY  ev_UiUmstoolOptTvwBoardModeNty

	/************************************************************************/
	/**  ����ǽ�������ģʽ�����Ӧ����� �޸� ɾ����
	wParam = TTPBrdCfg   ��������*   
	lparam = EmTpBoardRet ʧ��ԭ��*/
	/************************************************************************/
	ev_UiUmstoolOptTvwBoardModeRsp,
#define UI_UMSTOOL_MSG_OPTTVWBOARDMODE_RSP  ev_UiUmstoolOptTvwBoardModeRsp

	/************************************************************************/
	/**  ����ǽ�������ģʽ֪ͨ��ɾ����
	wParam = TTPBrdCfg   ��������*   
	lparam = EmTpBoardRet ʧ��ԭ��*/
	/************************************************************************/
	ev_UiUmstoolDelTvwBoardModeNty,
#define UI_UMSTOOL_MSG_DELTVWBOARDMODE_NTY  ev_UiUmstoolDelTvwBoardModeNty

	/************************************************************************/
	/**  �������ָʾ
	wParam = EmModifyNMServerRet �Ƿ�ɹ�
	lparam = ��*/
	/************************************************************************/
	ev_UIUmstoolAddNetmngRsp,
#define UI_UMSTOOL_ADD_NETMNG_RSP  ev_UIUmstoolAddNetmngRsp

	/************************************************************************/
	/**  ɾ������ָʾ
	wParam = EmModifyNMServerRet �Ƿ�ɹ�
	lparam = ��*/
	/************************************************************************/
	ev_UIUmstoolDelNetmngRsp,
#define UI_UMSTOOL_DEL_NETMNG_RSP  ev_UIUmstoolDelNetmngRsp

	/************************************************************************/
	/**  ������Ϣ֪ͨ
	wParam = NULL
	lparam = ��*/
	/************************************************************************/
	ev_UIUmstoolNetmngNty,
#define UI_UMSTOOL_NETMNG_NTY  ev_UIUmstoolNetmngNty

	/************************************************************************/
	/**  �޸�����ָʾ
	wParam = EmModifyNMServerRet �Ƿ�ɹ�
	lparam = ��*/
	/************************************************************************/
	ev_UIUmstoolModifyNetmngRsp,
#define UI_UMSTOOL_MODIFY_NETMNG_RSP  ev_UIUmstoolModifyNetmngRsp

	/************************************************************************/
	/**  ����ҳ������޸����ܵ�ǰѡ�����ݷ���
	wParam = Window*   
	lparam = Type*/
	/************************************************************************/
	ev_UiUmstoolNetMngSelDataClick,
#define UI_UMSTOOL_MSG_NETMNGSELDATA_Click  ev_UiUmstoolNetMngSelDataClick
	
        /************************************************************************/
		/**	 ��������ǽ�忨��Ӧ
		wParam = TTPBrdPos  ����λ����Ϣ*   
		lparam = EmModifyHduRet �������ؽ��*/
		/************************************************************************/ 
        ev_Tvw_RebootRsp,
#define UI_UMSTOOL_MSG_REBOOTTVWBOARD_RSP  ev_Tvw_RebootRsp

        /************************************************************************/
		/**	 ����������Ӧ
		wParam = BOOL  �����ɹ�ʧ��*   
		/************************************************************************/ 
        ev_Board_UpgradeRsp,
#define UI_UMSTOOL_MSG_BOARDUPGRADE_RSP  ev_Board_UpgradeRsp

        /************************************************************************/
		/**	 ����֪ͨ������ ����������Ϣ
		wParam = CString  �ļ���*   
		/************************************************************************/ 
        em_UMSTOOL_BOARDBEGINUPGRADE,
#define UI_UMSTOOL_BOARDBEGINUPGRADE  em_UMSTOOL_BOARDBEGINUPGRADE

	/************************************************************************/
	/**  ¼���ҳ������޸����ܵ�ǰѡ�����ݷ���
	wParam = Window*   
	lparam = Type*/
	/************************************************************************/
	ev_UiUmstoolVTRSelDataClick,
#define UI_UMSTOOL_MSG_VTRSELDATA_Click  ev_UiUmstoolVTRSelDataClick

	/************************************************************************/
	/**  ���¼�����Ӧ
	wParam = EmModifyVTRRet �Ƿ�ɹ�
	lparam = ��*/
	/************************************************************************/
	ev_UIUmstoolAddVTRRsp,
#define UI_UMSTOOL_ADD_VTR_RSP  ev_UIUmstoolAddVTRRsp

	/************************************************************************/
	/**  ɾ��¼�����Ӧ
	wParam = EmModifyVTRRet �Ƿ�ɹ�
	lparam = ��*/
	/************************************************************************/
	ev_UIUmstoolDelVTRRsp,
#define UI_UMSTOOL_DEL_VTR_RSP  ev_UIUmstoolDelVTRRsp

	/************************************************************************/
	/**  ¼�����Ϣ֪ͨ
	wParam = NULL
	lparam = ��*/
	/************************************************************************/
	ev_UIUmstoolVTRNty,
#define UI_UMSTOOL_VTR_NTY  ev_UIUmstoolVTRNty

	/************************************************************************/
	/**  ¼���ע��״̬֪ͨ
	wParam = NULL
	lparam = ��*/
	/************************************************************************/
	ev_UIUmstoolVTRRegStateNty,
#define UI_UMSTOOL_VTR_REG_STATE_NTY  ev_UIUmstoolVTRRegStateNty

	/************************************************************************/
	/**  �޸�¼�����Ӧ
	wParam = EmModifyVTRRet �Ƿ�ɹ�
	lparam = ��*/
	/************************************************************************/
	ev_UIUmstoolModifyVTRRsp,
#define UI_UMSTOOL_MODIFY_VTR_RSP  ev_UIUmstoolModifyVTRRsp
	
	/************************************************************************/
	/**  ����ģ�嵼����Ӧ
	wParam = void 
	lparam = ��*/
	/************************************************************************/
	ev_UIUmstoolExpTemplateRsp,
#define UI_UMSTOOL_EXPTEMPLATE_RSP  ev_UIUmstoolExpTemplateRsp

	/************************************************************************/
	/**  SIPע�����������֪ͨ
	wParam = NULL
	lparam = ��*/
	/************************************************************************/
	ev_UIUmstoolRegNty,
#define UI_UMSTOOL_REG_NTY  ev_UIUmstoolRegNty


	/************************************************************************/
	/**  GKע�����������֪ͨ
	wParam = NULL
	lparam = ��*/
	/************************************************************************/
	ev_UIUmstoolGkNty,
#define UI_UMSTOOL_GK_NTY  ev_UIUmstoolGkNty

        /************************************************************************/
		/**	 ����֪ͨ������ ����������Ϣ
		wParam = �� ��*   
		/************************************************************************/ 
        em_UMSTOOL_TVWBOARDBEGINUPGRADE,
#define UI_UMSTOOL_TVWBOARDBEGINUPGRADE  em_UMSTOOL_TVWBOARDBEGINUPGRADE

        /************************************************************************/
		/**	 ����ǽ����������Ӧ
		wParam = EmUpdateHduRet  �����ɹ�ʧ��*   
		/************************************************************************/ 
        ev_TvwBoard_UpgradeRsp,
#define UI_UMSTOOL_MSG_TVWBOARDUPGRADE_RSP  ev_TvwBoard_UpgradeRsp

		/************************************************************************/
		/**  ¼��������������Ϣ֪ͨ
		wParam = NULL
		lparam = ��*/
		/************************************************************************/
		ev_UIUmstoolRecBaseInfoNty,
#define UI_UMSTOOL_REC_BASE_INFO_NTY  ev_UIUmstoolRecBaseInfoNty

		/************************************************************************/
		/**  ¼���������ļ��б�֪ͨ
		wParam = NULL
		lparam = ��*/
		/************************************************************************/
		ev_UIUmstoolRecFileListInfoNty,
#define UI_UMSTOOL_REC_FILE_LIST_INFO_NTY  ev_UIUmstoolRecFileListInfoNty

		/************************************************************************/
		/**  ¼���������޸��ļ��ظ�
		wParam = NULL
		lparam = BOOL �Ƿ�ɹ�*/
		/************************************************************************/
		ev_UIUmstoolRecMdyFileRsp,
#define UI_UMSTOOL_REC_MDY_FILE_RSP  ev_UIUmstoolRecMdyFileRsp

		/************************************************************************/
		/**  ����¼����Ϣ֪ͨ
		wParam = TConfRecInfo* ����¼����Ϣ
		lparam = BOOL �Ƿ�ɹ�*/
		/************************************************************************/
		ev_UIUmstoolRecConfRecInfoNty,
#define UI_UMSTOOL_REC_CONF_REC_INFO_NTY  ev_UIUmstoolRecConfRecInfoNty

		/************************************************************************/
		/**  ��ʼ¼�ƻظ�
		wParam = NULL 
		lparam = EmRecStartRecorderRes ���*/
		/************************************************************************/
		ev_UIUmstoolRecStartRecordRsp,
#define UI_UMSTOOL_REC_START_CONF_RSP  ev_UIUmstoolRecStartRecordRsp

		/************************************************************************/
		/**  ��ͣ¼�ƻظ�
		wParam = NULL 
		lparam = EmRecStartRecorderRes ���*/
		/************************************************************************/
		ev_UIUmstoolRecPauseRecordRsp,
#define UI_UMSTOOL_REC_PAUSE_CONF_RSP  ev_UIUmstoolRecPauseRecordRsp

		/************************************************************************/
		/**  ����¼�ƻظ�
		wParam = NULL 
		lparam = EmRecStartRecorderRes ���*/
		/************************************************************************/
		ev_UIUmstoolRecResumeRecordRsp,
#define UI_UMSTOOL_REC_RESUME_CONF_RSP  ev_UIUmstoolRecResumeRecordRsp

		/************************************************************************/
		/**  ����¼�ƻظ�
		wParam = NULL 
		lparam = EmRecStartRecorderRes ���*/
		/************************************************************************/
		ev_UIUmstoolRecStopRecordRsp,
#define UI_UMSTOOL_REC_STOP_CONF_RSP  ev_UIUmstoolRecStopRecordRsp

		/************************************************************************/
		/**  ��ʼ����ظ�
		wParam = NULL 
		lparam = EmRecStartRecorderRes ���*/
		/************************************************************************/
		ev_UIUmstoolRecStartPlayRsp,
#define UI_UMSTOOL_START_PLAY_RSP  ev_UIUmstoolRecStartPlayRsp

		/************************************************************************/
		/**  ��ͣ����ظ�
		wParam = NULL 
		lparam = EmRecStartRecorderRes ���*/
		/************************************************************************/
		ev_UIUmstoolRecPausePlayRsp,
#define UI_UMSTOOL_PAUSE_PLAY_RSP  ev_UIUmstoolRecPausePlayRsp

		/************************************************************************/
		/**  ��������ظ�
		wParam = NULL 
		lparam = EmRecStartRecorderRes ���*/
		/************************************************************************/
		ev_UIUmstoolRecResumePlayRsp,
#define UI_UMSTOOL_RESUME_PLAY_RSP  ev_UIUmstoolRecResumePlayRsp

		/************************************************************************/
		/**  ��������ظ�
		wParam = NULL 
		lparam = EmRecStartRecorderRes ���*/
		/************************************************************************/
		ev_UIUmstoolRecStopPlayRsp,
#define UI_UMSTOOL_STOP_PLAY_RSP  ev_UIUmstoolRecStopPlayRsp

		/************************************************************************/
		/**  �������֪ͨ
		wParam = NULL 
		lparam = NULL*/
		/************************************************************************/
		ev_UIUmstoolRecConfPlayInfoNty,
#define UI_UMSTOOL_REC_CONF_PLAY_INFO_NTY  ev_UIUmstoolRecConfPlayInfoNty

		/************************************************************************/
		/**  ��ַ��OPT��ʾ״̬�ı�֪ͨ
		wParam = bShow ��ʾ״̬ 
		lparam = NULL*/
		/************************************************************************/
		ev_UIUmstoolAddreditChangeStateNty,
#define MSG_UMSTOOL_ADDREDITOPT_CHANGESTATE_NTY  ev_UIUmstoolAddreditChangeStateNty
		
		/************************************************************************/
		/**  ¼��������ɾ���ļ��ظ�
		wParam = NULL
		lparam = BOOL �Ƿ�ɹ�*/
		/************************************************************************/
		ev_UIUmstoolRecDelFileRsp,
#define UI_UMSTOOL_REC_DEL_FILE_RSP  ev_UIUmstoolRecDelFileRsp

		/************************************************************************/
		/**  Recordɸѡ֪ͨ
		wParam = emShowState ɸѡ״̬
		lparam = NULL*/
		/************************************************************************/
		ev_UIUmstoolShowOptNty,
#define UI_UMSTOOL_SHOWOPT_NTY  ev_UIUmstoolShowOptNty

		/************************************************************************/
		/**  Recordepɸѡ֪ͨ
		wParam = emShowState ɸѡ״̬
		lparam = NULL*/
		/************************************************************************/
		ev_UIUmstoolShowOptEpNty,
#define UI_UMSTOOL_SHOWOPT_EP_NTY  ev_UIUmstoolShowOptEpNty

		/************************************************************************/
		/**  ��Ȩ������Ӧ
		wParam = BOOL32 �Ƿ�ɹ�
		lparam = s8* ����·��+�ļ���*/
		/************************************************************************/
		ev_UIUmstoolExpAuthRsp,
#define UI_UMSTOOL_EXPAUTH_RSP  ev_UIUmstoolExpAuthRsp

		/************************************************************************/
		/**  �᳡��ʽ��Ӧ
		wParam = TTPRecMtFormat �᳡��ʽ��Ϣ
		lparam = NULL*/
		/************************************************************************/
		ev_UIUmstoolRecMtFormatRsp,
#define UI_UMSTOOL_REC_MT_FORMAT_RSP  ev_UIUmstoolRecMtFormatRsp

};


//cnstool��Ϣ����
enum EmUiCnstoolMsg
{
#define UI_CNSTOOL_MSG_BEGIN  CNSTOOL_MSG_BEGIN + 0x1

    	/************************************************************************/
		/** �����쳣
		wParam = �쳣������
		lparam = 0*/
		/************************************************************************/
	ev_UiCNSTOOLError = UI_CNSTOOL_MSG_BEGIN,
#define UI_CNSTOOL_ERROR  ev_UiCNSTOOLError

	/************************************************************************/
	/**  ����TPadIP�б�ظ���Ϣ
	wParam =  &TTPTPadList
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolTPadIPRsp,
#define UI_CNSTOOL_MSG_TPadIP_RSP  ev_UiCnstoolTPadIPRsp

	/************************************************************************/
	/**  ����TPadIP�б�֪ͨ��Ϣ
	wParam =  &TTPTPadList
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolTPadIPNty,
#define UI_CNSTOOL_MSG_TPadIP_NTY  ev_UiCnstoolTPadIPNty

	/************************************************************************/
	/**  ����cpu/�ڴ�֪ͨ��Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolSYSInfoNty,
#define UI_CNSTOOL_MSG_CPURAM_NTY  ev_UiCnstoolSYSInfoNty

	/************************************************************************/
	/**  ���ջ�����Ϣ֪ͨ��Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolConfInfoNty,
#define UI_CNSTOOL_MSG_CONF_NTY  ev_UiCnstoolConfInfoNty

	/************************************************************************/
	/**  ������Ƶ�˿�����֪ͨ��Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolAudPortInd,
#define UI_CNSTOOL_MSG_AudPort_NTY  ev_UiCnstoolAudPortInd

	/************************************************************************/
	/**  ���շ�������˷�����֪ͨ��Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnSetDesktopMicInfoNty,
#define UI_CNSTOOL_SETDESKTOPMIC_NTY  ev_UiCnSetDesktopMicInfoNty
	
	/************************************************************************/
	/**  ���շ�������˷����ûظ���Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnSetDesktopMicInfoInd,
#define UI_CNSTOOL_SETDESKTOPMIC_IND  ev_UiCnSetDesktopMicInfoInd

	/************************************************************************/
	/**  ����GANNON10��������Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UitppSetMic10InfoInd,
#define UI_CNSTOOL_SETMIC10INFO_IND  ev_UitppSetMic10InfoInd
	
	/************************************************************************/
	/**  ����Ĭ����Ƶ�˿���Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDftAudPortInd,
#define UI_CNSTOOL_MSG_DftAudPort_NTY  ev_UiCnstoolDftAudPortInd
	
	/************************************************************************/
	/**  ��������������֪ͨ��Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolUpDownstreamInd,
#define UI_CNSTOOL_MSG_UpDownstream_NTY  ev_UiCnstoolUpDownstreamInd

	/************************************************************************/
	/**  ���ն�����Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolLostPacketRsp,
#define UI_CNSTOOL_MSG_LostPacket_Rsp  ev_UiCnstoolLostPacketRsp

	/************************************************************************/
	/**  ������ϲ�����Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolAVDiagInd,
#define UI_CNSTOOL_MSG_AVDiag_IND  ev_UiCnstoolAVDiagInd

	/************************************************************************/
	/**  �������ָʾ
	wParam = EmModifyNMServerRet �Ƿ�ɹ�
	lparam = ��*/
	/************************************************************************/
	ev_UICnstoolAddNetmngInd,
#define UI_CNSTOOL_ADD_NETMNG_IND  ev_UICnstoolAddNetmngInd

	/************************************************************************/
	/**  ɾ������ָʾ
	wParam = EmModifyNMServerRet �Ƿ�ɹ�
	lparam = ��*/
	/************************************************************************/
	ev_UICnstoolDelNetmngInd,
#define UI_CNSTOOL_DEL_NETMNG_IND  ev_UICnstoolDelNetmngInd

	/************************************************************************/
	/**  ������Ϣ֪ͨ
	wParam = TTPNMServerCfg* ������Ϣ
	lparam = ��*/
	/************************************************************************/
	ev_UICnstoolNetmngNty,
#define UI_CNSTOOL_NETMNG_NTY  ev_UICnstoolNetmngNty

	/************************************************************************/
	/**  �޸�����ָʾ
	wParam = EmModifyNMServerRet �Ƿ�ɹ�
	lparam = ��*/
	/************************************************************************/
	ev_UICnstoolModifyNetmngInd,
#define UI_CNSTOOL_MODIFY_NETMNG_IND  ev_UICnstoolModifyNetmngInd

	/************************************************************************/
	/**  ����ҳ������޸����ܵ�ǰѡ�����ݷ���
	wParam = Window*   
	lparam = Type*/
	/************************************************************************/
	ev_UiCnstoolNetMngSelDataClick,
#define UI_CNSTOOL_MSG_NETMNGSELDATA_Click  ev_UiCnstoolNetMngSelDataClick

	/************************************************************************/
	/**  ����ҳ������޸����ܵ�ǰѡ�����ݷ���
	wParam = Window*   
	lparam = Type*/
	/************************************************************************/
	ev_UiCnstoolRouteSelDataClick,
#define UI_CNSTOOL_MSG_ROUTESELDATA_Click  ev_UiCnstoolRouteSelDataClick
	
	/************************************************************************/
	/**  ���պ��з�������֪ͨ��Ϣ
	wParam = 0   
	lparam = 0
	/************************************************************************/
	ev_UiCnstoolCallSerNty,
#define UI_CNSTOOL_MSG_CallSer_NTY  ev_UiCnstoolCallSerNty
		
	/************************************************************************/
	/**  ���պ��з������Ļظ���Ϣ
	wParam = TTPCallSerInfo  
	lparam = bSuccess 
	/************************************************************************/
	ev_UiCnstoolCallSerInd,
#define UI_CNSTOOL_MSG_CallSer_IND  ev_UiCnstoolCallSerInd
	
	/************************************************************************/
	/**  ����������������֪ͨ��Ϣ
	wParam = 0   
	lparam = 0
	/************************************************************************/
	ev_UiCnstoolUpgradeSerNty,
#define UI_CNSTOOL_MSG_UpgradeSer_NTY  ev_UiCnstoolUpgradeSerNty
		
	/************************************************************************/
	/**  ���������������Ļظ���Ϣ
	wParam = u32_Ip
	lparam = bSuccess 
	/************************************************************************/
	ev_UiCnstoolUpgradeSerInd,
#define UI_CNSTOOL_MSG_UpgradeSer_IND  ev_UiCnstoolUpgradeSerInd
		
	/************************************************************************/
	/**  �����п���Ϣ�пյ�����Ϣ
	wParam = 0  
	lparam = 0
	/************************************************************************/
	ev_UiCnstoolAirInfoNty,
#define UI_CNSTOOL_MSG_AirInfo_NTY  ev_UiCnstoolAirInfoNty
	
	/************************************************************************/
	/**  �����п���Ϣ���·����Ϣ
	wParam = 0 
	lparam = 0
	/************************************************************************/
	ev_UiCnstoolXinFengInfoNty,
#define UI_CNSTOOL_MSG_XinFengInfo_NTY  ev_UiCnstoolXinFengInfoNty
	
	/************************************************************************/
	/**  �����п���Ϣ����ʾ������Ϣ
	wParam = 0 
	lparam = 0
	/************************************************************************/
	ev_UiCnstoolDisplayInfoNty,
#define UI_CNSTOOL_MSG_DisplayInfo_NTY  ev_UiCnstoolDisplayInfoNty
	
	/************************************************************************/
	/**  �����п���Ϣ�����������Ϣ
	wParam = 0 
	lparam = 0
	/************************************************************************/
	ev_UiCnstoolCameraInfoNty,
#define UI_CNSTOOL_MSG_CameraInfo_NTY  ev_UiCnstoolCameraInfoNty
	
	/************************************************************************/
	/**  �����п���Ϣ���ĵ����������Ϣ
	wParam = 0 
	lparam = 0
	/************************************************************************/
	ev_UiCnstoolDocCamInfoNty,
#define UI_CNSTOOL_MSG_DocCamInfo_NTY  ev_UiCnstoolDocCamInfoNty
	
	/************************************************************************/
	/**  �����п���Ϣ�еƹ����Ϣ
	wParam = 0 
	lparam = 0
	/************************************************************************/
	ev_UiCnstoolLightInfoNty,
#define UI_CNSTOOL_MSG_LightInfo_NTY  ev_UiCnstoolLightInfoNty

	/************************************************************************/
	/**  ���������֪ͨ
	wParam = NULL
	lparam = NULL
	/************************************************************************/
	ev_UICnstoolCameraCfgNty,
#define UI_CNSTOOL_CAMERA_CFG_NTY  ev_UICnstoolCameraCfgNty

	/************************************************************************/
	/**  ѡ������������������
	wParam = NULL
	lparam = BOOL  = TRUE ѡ��ɹ� =FALSE ѡ��ʧ��
	/************************************************************************/
	ev_UICnstoolCameraSelectInd,
#define UI_CNSTOOL_CAMERA_SELECT_IND  ev_UICnstoolCameraSelectInd

	/************************************************************************/
	/**  �ָ�������������÷�����Ϣ
	wParam = NULL
	lparam = BOOL   =TRUE ���óɹ�  FALSE ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraResetInd,
#define UI_CNSTOOL_CAMERA_RESET_IND  ev_UICnstoolCameraResetInd

	/************************************************************************/
	/**  ������Ұ���ڷ�������
	wParam = NULL
	lparam = BOOL:				TRUE ���óɹ�  =FALSE ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraZoomInd,
#define UI_CNSTOOL_CAMERA_ZOOM_IND  ev_UICnstoolCameraZoomInd

	/************************************************************************/
	/**  ����� ��Ұ��OSD����ʾ������������
	wParam = NULL
	lparam = BOOL          =TRUE ���óɹ�  =FALSE ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraOSDShowInd,
#define UI_CNSTOOL_CAMERA_OSDSHOW_IND  ev_UICnstoolCameraOSDShowInd

	/************************************************************************/
	/**  ����ͷ�Զ��۽���������
	wParam = BOOL   =TRUE ���óɹ�   =FALSE ����ʧ��
	lparam = NULL
	/************************************************************************/
	ev_UICnstoolCameraAutoFocusInd,
#define UI_CNSTOOL_CAMERA_AUTO_FOCUS_IND  ev_UICnstoolCameraAutoFocusInd

	/************************************************************************/
	/**  ����ͷ�۽���������
	wParam = EmFocus         emFar Զ��  emNear����
	lparam = BOOL        =TRUE ���óɹ�  =FALSE ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraFocusInd,
#define UI_CNSTOOL_CAMERA_FOCUS_IND  ev_UICnstoolCameraFocusInd

	/************************************************************************/
	/**  ������Զ��عⷵ������
	wParam = NULL
	lparam = BOOL       =TRUE ���óɹ�  =FALSE ����ʧ�� 
	/************************************************************************/
	ev_UICnstoolCameraAutoExposureInd,
#define UI_CNSTOOL_CAMERA_AUTO_EXPOSURE_IND  ev_UICnstoolCameraAutoExposureInd

	/************************************************************************/
	/**  ������ֶ��ع⡪��������ڷ�������
	wParam = NULL
	lparam = BOOL    =��TRUE ���óɹ�   =FALSE ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraGainInd,
#define UI_CNSTOOL_CAMERA_GAIN_IND  ev_UICnstoolCameraGainInd

	/************************************************************************/
	/**  ������ֶ��ع⡪�����ŵ��ڷ�������
	wParam = NULL
	lparam = BOOL    =��TRUE ���óɹ�   =FALSE ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraShutSpdInd,
#define UI_CNSTOOL_CAMERA_SHUT_SPD_IND  ev_UICnstoolCameraShutSpdInd

	/************************************************************************/
	/**  ������ֶ��ع⡪��������ڷ�������
	wParam = NULL
	lparam = BOOL    =��TRUE ���óɹ�   =FALSE ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraBackLightInd,
#define UI_CNSTOOL_CAMERA_BACK_LIGHT_IND  ev_UICnstoolCameraBackLightInd

	/************************************************************************/
	/**  ������ֶ��ع⡪����Ȧ���ڷ�������
	wParam = NULL
	lparam = BOOL   =TRUE ���óɹ�   =FALSE ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraApertureInd,
#define UI_CNSTOOL_CAMERA_APERTURE_IND  ev_UICnstoolCameraApertureInd

	/************************************************************************/
	/**  ������Զ���ƽ�ⷵ������
	wParam = BOOL   =TRUE ���óɹ�   =FALSE ����ʧ��
	lparam = NULL
	/************************************************************************/
	ev_UICnstoolCameraAutoWBInd,
#define UI_CNSTOOL_CAMERA_AUTO_WB_IND  ev_UICnstoolCameraAutoWBInd

	/************************************************************************/
	/**  ������ֶ���ƽ��--R Gain��������
	wParam = NULL
	lparam = BOOL   =TRUE ���óɹ�      =FALSE  ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraRGainInd,
#define UI_CNSTOOL_CAMERA_RGAIN_IND  ev_UICnstoolCameraRGainInd

	/************************************************************************/
	/**  ������ֶ���ƽ��--B Gain��������
	wParam = NULL
	lparam = BOOL   =TRUE ���óɹ�      =FALSE  ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraBGainInd,
#define UI_CNSTOOL_CAMERA_BGAIN_IND  ev_UICnstoolCameraBGainInd

	/************************************************************************/
	/**  ���������ģʽ��������
	wParam = NULL
	lparam = BOOL   =TRUE ���óɹ�      =FALSE  ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraPicSceneModeInd,
#define UI_CNSTOOL_CAMERA_PIC_SCENE_MODE_IND  ev_UICnstoolCameraPicSceneModeInd

	/************************************************************************/
	/**  ����� ģʽ--- �ֶ� GAMMA���ڷ�������
	wParam = NULL
	lparam = BOOL   =TRUE ���óɹ�      =FALSE  ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraGammaInd,
#define UI_CNSTOOL_CAMERA_GAMMA_IND  ev_UICnstoolCameraGammaInd

	/************************************************************************/
	/**  ����� ģʽ--- ��Ȧ���ڷ�������
	wParam = NULL
	lparam = BOOL   =TRUE ���óɹ�      =FALSE  ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraPicSceAptInd,
#define UI_CNSTOOL_CAMERA_PIC_SCE_APT_IND  ev_UICnstoolCameraPicSceAptInd

	/************************************************************************/
	/**  ����� ͼƬ����---�Աȶ� ���ڷ�������
	wParam = NULL
	lparam = BOOL   =TRUE ���óɹ�      =FALSE  ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraContrastInd,
#define UI_CNSTOOL_CAMERA_CONTRAST_IND  ev_UICnstoolCameraContrastInd

	/************************************************************************/
	/**  ����� ͼƬ����---���Ͷ� ���ڷ�������
	wParam = NULL
	lparam = BOOL   =TRUE ���óɹ�      =FALSE  ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraSaturatInd,
#define UI_CNSTOOL_CAMERA_SATURAT_IND  ev_UICnstoolCameraSaturatInd

	/************************************************************************/
	/**  ����� ͼƬ����--- ɫ�� ���ڷ�������
	wParam = NULL
	lparam = BOOL   =TRUE ���óɹ�      =FALSE  ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraHueInd,
#define UI_CNSTOOL_CAMERA_HUE_IND  ev_UICnstoolCameraHueInd

	/************************************************************************/
	/**  ����� ͼƬ����--- ���� ���ڷ�������
	wParam = NULL
	lparam = BOOL   =TRUE ���óɹ�      =FALSE  ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraBrightInd,
#define UI_CNSTOOL_CAMERA_BRIGHT_IND  ev_UICnstoolCameraBrightInd

	/************************************************************************/
	/**  ����� ����---������ ���ڷ�������
	wParam = NULL
	lparam = BOOL   =TRUE ���óɹ�      =FALSE  ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraNRStmCleanInd,
#define UI_CNSTOOL_CAMERA_NR_STM_CLEAN_IND  ev_UICnstoolCameraNRStmCleanInd

	/************************************************************************/
	/**  ����� ����---3D���� ���ڷ�������
	wParam = NULL
	lparam = BOOL   =TRUE ���óɹ�      =FALSE  ����ʧ��
	/************************************************************************/
	ev_UICnstoolCamera3DNRInd,
#define UI_CNSTOOL_CAMERA_3DNR_IND  ev_UICnstoolCamera3DNRInd

	/************************************************************************/
	/**  ����� Ԥ��λ���淵������
	wParam = NULL	
	lparam = BOOL	TRUE= ����Ԥ��λ�ɹ�   = FALSE ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraPersetSaveInd,
#define UI_CNSTOOL_CAMERA_PERSET_SAVE_IND  ev_UICnstoolCameraPersetSaveInd

	/************************************************************************/
	/**  ����� ���ÿ�������Ԥ��λ
	wParam = NULL	
	lparam = BOOL	TRUE= ���óɹ�   = FALSE ����ʧ��
	/************************************************************************/
	ev_UICnstoolCameraPersetMoveInd,
#define UI_CNSTOOL_CAMERA_PERSET_MOVE_IND  ev_UICnstoolCameraPersetMoveInd

	/************************************************************************/
	/**  ����� ����ZOOM
	wParam = NULL	
	lparam = BOOL	TRUE= ���óɹ�   = FALSE ����ʧ��
	/************************************************************************/
	ev_UICnstoolSetCameraZoomInd,
#define UI_CNSTOOL_SET_CAMERA_ZOOM_IND  ev_UICnstoolSetCameraZoomInd
			
	/************************************************************************/
	/**  ������Ƶ����������֪ͨ��Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolAudMixerInd,
#define UI_CNSTOOL_MSG_AudMixer_NTY  ev_UiCnstoolAudMixerInd
				
	/************************************************************************/
	/**  ����ϵͳĬ����Ƶ��������Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDefaultMixerInd,
#define UI_CNSTOOL_MSG_DftMixer_NTY  ev_UiCnstoolDefaultMixerInd
	
	/************************************************************************/
	/**  ������Ƶ����������֪ͨ��Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolAudEqualizerInd,
#define UI_CNSTOOL_MSG_AudEqualizer_NTY  ev_UiCnstoolAudEqualizerInd
				
	/************************************************************************/
	/**  ����ϵͳĬ����Ƶ��������Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDefaultEqInd,
#define UI_CNSTOOL_MSG_DftEq_NTY  ev_UiCnstoolDefaultEqInd
			
	/************************************************************************/
	/**  ��������T300�ظ���Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolUpgradeCnsInd,
#define UI_CNSTOOL_MSG_UpgradeCns_NTY  ev_UiCnstoolUpgradeCnsInd
			
	/************************************************************************/
	/**  ����ֹͣ���Իظ���Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolStopAVMatrixRsp,
#define UI_CNSTOOL_MSG_StopAVMatrix_RSP  ev_UiCnstoolStopAVMatrixRsp
				
	/************************************************************************/
	/**  �п������״̬֪ͨ��Ϣ
	wParam =  aemCam   ������������ͷָ��
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolCamPowerStateNty,
#define UI_CNSTOOL_MSG_CamPowerState_NTY  ev_UiCnstoolCamPowerStateNty
				
	/************************************************************************/
	/**  �����յ���GKע����Ϣ�ı������Ϣ�����״̬
	wParam =  0   
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolGKRspNty,
#define UI_CNSTOOL_MSG_GKRsp_NTY  ev_UiCnstoolGKRspNty
				
	/************************************************************************/
	/**  �����յ���sipע����Ϣ�ı������Ϣ�����״̬
	wParam =  0   
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolSIPRspNty,
#define UI_CNSTOOL_MSG_SIPRsp_NTY  ev_UiCnstoolSIPRspNty
				
	/************************************************************************/
	/**  ��־���ؽ������� 
	wParam =  ����ֵ  
	lparam = 0*/
	/************************************************************************/
	em_CNSTOOL_FTPLOGPROGRESS,
#define WM_CNSTOOL_FTPLOGPROGRESS  em_CNSTOOL_FTPLOGPROGRESS				   
				
	/************************************************************************/
	/**  ��ַ�����뵼����������
	wParam =  ����ֵ  
	lparam = 0*/
	/************************************************************************/	
	em_CNSTOOL_FTPADDRBOOKPROGRESS,
#define WM_CNSTOOL_FTPADDRBOOKPROGRESS  em_CNSTOOL_FTPADDRBOOKPROGRESS  
    
	/************************************************************************/
	/**  ����ץ�����ߵ����Լ�ץ���ļ�����
	wParam =  ����ֵ  
	lparam = 0*/
	/************************************************************************/	
	em_CNSTOOL_FTPCAPTUREPROGRESS,
#define WM_CNSTOOL_FTPCAPTUREPROGRESS  em_CNSTOOL_FTPCAPTUREPROGRESS

	/************************************************************************/
	/**  ����ץ��ʧ��
	*/
	/************************************************************************/
	em_CNSTOOL_CAPTUREFAIL,
#define WM_CNSTOOL_CAPTUREFAIL 	em_CNSTOOL_CAPTUREFAIL
	
	/************************************************************************/
	/**  ֹͣץ����Ϣ
	wParam =  ����ֵ  
	lparam = 0*/
	/************************************************************************/	
	em_CNSTOOL_CAPTUREMAXSIZE,
#define WM_CNSTOOL_CAPTUREMAXSIZE  em_CNSTOOL_CAPTUREMAXSIZE

	/************************************************************************/
	/**  ̨���ϴ���������
	wParam =  ����ֵ  
	lparam = 0*/
	/************************************************************************/	
	em_CNSTOOL_CONFSIGNPROGRESS,
#define WM_CNSTOOL_FTPCONFSIGNPROGRESS  em_CNSTOOL_CONFSIGNPROGRESS		   
				
	/************************************************************************/
	/**  �ļ��ϴ��������� 
	wParam =  ����ֵ  
	lparam = 0*/
	/************************************************************************/
	em_CNSTOOL_UPLODEPROGRESS,
#define WM_CNSTOOL_UPLODEPROGRESS  em_CNSTOOL_UPLODEPROGRESS				   

	/************************************************************************/
	/**  �յ�������ϵ���Ϣ
	wParam = 0  
	lparam = 0*/
	/************************************************************************/
	ev_UICnstoolCameraPowerOnNty,
#define UI_CNSTOOL_CAMERA_POWER_ON_NTY  ev_UICnstoolCameraPowerOnNty
	
	/************************************************************************/
	/**  �յ�������ѡ��ʽ��Ϣ
	wParam = 0  
	lparam = 0*/
	/************************************************************************/
	ev_UICnstoolVideoFormatInd,
#define UI_CNSTOOL_VIDEOFORMAT_IND  ev_UICnstoolVideoFormatInd
		
	/************************************************************************/
	/**  �յ���ʾ��ѡ��ʽ��Ϣ
	wParam = 0  
	lparam = 0*/
	/************************************************************************/
	ev_UICnstoolDualVideoFormatInd,
#define UI_CNSTOOL_DUALVIDEOFORMAT_IND  ev_UICnstoolDualVideoFormatInd
			
	/************************************************************************/
	/**  �յ�����������Ϣ
	wParam = 0  
	lparam = 0*/
	/************************************************************************/
	ev_UICnstoolCallRateInd,
#define UI_CNSTOOL_CALLRATE_IND  ev_UICnstoolCallRateInd
				
	/************************************************************************/
	/**  �յ���ʾ������Ϣ
	wParam = 0  
	lparam = 0*/
	/************************************************************************/
	ev_UICnstoolDualCallRateInd,
#define UI_CNSTOOL_DUALCALLRATE_IND  ev_UICnstoolDualCallRateInd
					
	/************************************************************************/
	/**  �յ��汾֪ͨ��Ϣ
	wParam = 0  
	lparam = 0*/
	/************************************************************************/
	ev_UICnstoolVerInfoNty,
#define UI_CNSTOOL_VERINFO_NTY  ev_UICnstoolVerInfoNty
				
	/************************************************************************/
	/**  �յ�����������Ϣ
	wParam = 0  
	lparam = 0*/
	/************************************************************************/
	ev_UICnstoolConfDisInd,
#define UI_CNSTOOL_CONFDIS_IND  ev_UICnstoolConfDisInd
				
	/************************************************************************/
	/**  �յ�������ѯ��Ϣ
	wParam = 0  
	lparam = 0*/
	/************************************************************************/
	ev_UICnstoolConfPollInd,
#define UI_CNSTOOL_CONFPOOL_IND  ev_UICnstoolConfPollInd
				
	/************************************************************************/
	/**  �յ���Ƶ��ʽ��Ϣ
	wParam = 0  
	lparam = 0*/
	/************************************************************************/
	ev_UICnstoolAudioFormatInd,
#define UI_CNSTOOL_AUDIOFORMAT_IND  ev_UICnstoolAudioFormatInd
				
	/************************************************************************/
	/**  �пص���ǽ֪ͨ��Ϣ
	wParam = 0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolCfgDisplayInd,
#define UI_CNSTOOL_MSG_DISPLAY_IND  ev_UiCnstoolCfgDisplayInd

	/************************************************************************/
	/**  �п���ʾ����ʾ���ý���֪ͨ��Ϣ
	wParam = 0
	lparam = 0*/
	/************************************************************************/
	ev_UICnstoolDisplayShowNty,
#define UI_CNSTOOL_DISPLAY_SHOW_Nty  ev_UICnstoolDisplayShowNty

	/************************************************************************/
	/**  �п���ʾ����ʾ���ý���֪ͨ��Ϣ
	wParam = 0
	lparam = 0*/
	/************************************************************************/
	ev_UICnstoolDisplayShowInd,
#define UI_CNSTOOL_DISPLAY_SHOW_Ind  ev_UICnstoolDisplayShowInd
	/************************************************************************/
	/**  �п���ʾ���ͺ�֪ͨ��Ϣ
	wParam = 0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolCfgTVModeInd,
#define UI_CNSTOOL_MSG_TVMode_IND  ev_UiCnstoolCfgTVModeInd

	/************************************************************************/
	/**  �յ���������������Ϣ
	wParam = ������������  
	lparam = 0*/
	/************************************************************************/
	ev_UITpadCurtainStateNty,
#define UI_TPAD_CURTAINSTATE_NTY  ev_UITpadCurtainStateNty
	
	/************************************************************************/
	/**  ������Ƶ���ö˿���Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolAudioInd,
#define UI_CNSTOOL_MSG_Audio_NTY  ev_UiCnstoolAudioInd

	/************************************************************************/
	/**  ��Ƶ���ü�������˿���Ϣ ���ػ���Զ�˻���
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_TppSetMixTypeInd,
#define UI_CNSTOOL_MSG_Listen_NTY ev_TppSetMixTypeInd

	/************************************************************************/
	/**  AUX2 OUT�����������
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_TppSetLocalAudExtendInd,
#define UI_CNSTOOL_MSG_AUX2_NTY  ev_TppSetLocalAudExtendInd
	/************************************************************************/
	/**  ����Ĭ����Ƶ���ö˿���Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDftAudioInd,
#define UI_CNSTOOL_MSG_DftAudio_NTY  ev_UiCnstoolDftAudioInd
	/************************************************************************/
	/**  ���հ�����������Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolWhiteNoiseInd,
#define UI_CNSTOOL_MSG_WhiteNoise_NTY  ev_UiCnstoolWhiteNoiseInd
	/************************************************************************/
	/**  ���ո��°�������Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolWhiteNoiseUpdate,
#define UI_CNSTOOL_MSG_WhiteNoiseUpdate_NTY  ev_UiCnstoolWhiteNoiseUpdate
	/************************************************************************/
	/**  ��������Ƶ������Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolVideoSourceInd,
#define UI_CNSTOOL_MSG_VideoSource_NTY  ev_UiCnstoolVideoSourceInd
	/************************************************************************/
	/**  ����Ĭ������Ƶ������Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDefMainAudioInd,
#define UI_CNSTOOL_MSG_DefAudio_NTY  ev_UiCnstoolDefMainAudioInd
	/************************************************************************/
	/**  ������������ƵԴ�˿���Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolRenameVideoSourceClick,
#define UI_CNSTOOL_MSG_RenameVideoSource_Click  ev_UiCnstoolRenameVideoSourceClick
	/************************************************************************/
	/**  ������ƵԴ�˿ڸ�����Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolUpdateVideoSourceNty,
#define UI_CNSTOOL_MSG_UpdateVideoSource_Nty  ev_UiCnstoolUpdateVideoSourceNty
	/************************************************************************/
	/**  ������ʾԴ��Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDisplaySourceInd,
#define UI_CNSTOOL_MSG_DisplaySource_Nty  ev_UiCnstoolDisplaySourceInd
	/**  ����Ĭ����ʾԴ��Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDefaultDisplaySourceInd,
#define UI_CNSTOOL_MSG_DefaultDisplaySource_Nty  ev_UiCnstoolDefaultDisplaySourceInd
	/************************************************************************/
	/**  ������������ʾԴ��Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolRenameDisplaySourceClick,
#define UI_CNSTOOL_MSG_ReDisplaySrc_Click  ev_UiCnstoolRenameDisplaySourceClick
	/**  ������������ƵԴ������Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolRenameDisplaySourceNty,
#define UI_CNSTOOL_MSG_RenameDisplaySource_Nty  ev_UiCnstoolRenameDisplaySourceNty
	/**  �������ͼ�������Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolImageAdjustInd,
#define UI_CNSTOOL_MSG_ImageAdjust_Nty  ev_UiCnstoolImageAdjustInd
	/**  ����Ĭ�����ͼ�������Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDefaultImageAdjustInd,
#define UI_CNSTOOL_MSG_DefaultImageAdjust_Nty  ev_UiCnstoolDefaultImageAdjustInd
	/**  ��ʼ����ͳ��
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolStartRecorderNty,
#define UI_CNSTOOL_MSG_StartRecorder_Nty  ev_UiCnstoolStartRecorderNty
	/**  ����ͳ�Ʋ�����Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolStatisticNty,
#define UI_CNSTOOL_MSG_Statistic_Nty  ev_UiCnstoolStatisticNty
	/**  ����ȫ�������֪ͨ��Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
//	ev_UiCnstoolPanCamNty,
//#define UI_CNSTOOL_PanCam_Nty  ev_UiCnstoolPanCamNty
	/**  ��������ȫ�����������������Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolPanCamNumInd,
#define UI_CNSTOOL_PanCamNum_Nty  ev_UiCnstoolPanCamNumInd
	/**  �����ĵ������ZOOM��Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDcCameraZOOMInd,
#define UI_CNSTOOL_DCCAMERA_ZOOM_Nty  ev_UiCnstoolDcCameraZOOMInd
	/**  �����ĵ����������ֵ��Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
//	ev_UiCnstoolDcCameraZOOMValueInd,
//#define UI_CNSTOOL_DCCAMERA_ZOOMValue_Nty  ev_UiCnstoolDcCameraZOOMValueInd
	/**  �����ĵ�������Զ�/�ֶ���Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDcCameraAutoFocusInd,
#define UI_CNSTOOL_DCCAMERA_AUTO_FOCUS_IND  ev_UiCnstoolDcCameraAutoFocusInd
	/**  �����ĵ�������ع�ģʽ��Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDCamExposureInd,
#define UI_CNSTOOL_DCamExposure_Nty  ev_UiCnstoolDCamExposureInd
	/**  �����ĵ������������Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDCamGainInd,
#define UI_CNSTOOL_DCamGain_Nty  ev_UiCnstoolDCamGainInd
	/**  �����ĵ������������Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDCamShutterInd,
#define UI_CNSTOOL_DCamShut_Nty  ev_UiCnstoolDCamShutterInd
	/**  �����ĵ��������Ȧ��Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDCamApertureInd,
#define UI_CNSTOOL_DCamAperture_Nty  ev_UiCnstoolDCamApertureInd
	/**  �����ĵ��������ƽ����Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDcCameraWBInd,
#define UI_CNSTOOL_DCCAMERA_WB_Nty  ev_UiCnstoolDcCameraWBInd
	/**  �����ĵ������R������Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDcCameraRGainInd,
#define UI_CNSTOOL_DCCAMERA_RGain_Nty  ev_UiCnstoolDcCameraRGainInd
	/**  �����ĵ������B������Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDcCameraBGainInd,
#define UI_CNSTOOL_DCCAMERA_BGain_Nty  ev_UiCnstoolDcCameraBGainInd
	/**  �����ĵ������Ԥ��λ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDcCameraPreSetNty,
#define UI_CNSTOOL_DCCAMERA_PreSet_Nty  ev_UiCnstoolDcCameraPreSetNty
	/**  �����ĵ����������Ԥ��λ��Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDcCamSavePreSetInd,
#define UI_CNSTOOL_DCCAMERA_SavePreSet_Nty  ev_UiCnstoolDcCamSavePreSetInd
	/**  �����ĵ����������Ԥ��λ��Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDcCamCallPreSetInd,
#define UI_CNSTOOL_DCCAMERA_CallPreSet_Nty  ev_UiCnstoolDcCamCallPreSetInd
	/**  ���մ�����������Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolCurtainRenameNty,
#define UI_CNSTOOL_CurtainRename_Nty  ev_UiCnstoolCurtainRenameNty
	/**  ����CNS������������Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolCurtainRenameInd,
#define UI_CNSTOOL_CENTRE_CurRename_Nty  ev_UiCnstoolCurtainRenameInd
	/**  ���մ���������Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolCurtainNumInd,
#define UI_CNSTOOL_CENTRE_CurNumSet_Nty  ev_UiCnstoolCurtainNumInd
	/**  ���մ�������/�ر���Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolCurtainOpenInd,
#define UI_CNSTOOL_CENTRE_CurOpen_Nty  ev_UiCnstoolCurtainOpenInd
	/**  ���տ�����Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolSnapShotInd,
#define UI_CNSTOOL_SnapShot_Nty  ev_UiCnstoolSnapShotInd
	/**  ���ռ�����Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolEncryptInfoInd,
#define UI_CNSTOOL_EncryptInfo_Nty  ev_UiCnstoolEncryptInfoInd
	/**  ���ն����ָ���Ϣ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolLostPacketInd,
#define UI_CNSTOOL_LostPacket_Nty  ev_UiCnstoolLostPacketInd
	/************************************************************************/
	/**  ������������ 
	wParam =  ����ֵ  
	lparam = 0*/
	/************************************************************************/
	em_CNSTOOL_FTPSnapDownLoad,
#define WM_CNSTOOL_FTPSnapDownLoad  em_CNSTOOL_FTPSnapDownLoad
	/**  �ӿ���Ͻ���ˢ������Ƶ�ӿ�
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolRefInportTitleNty,
#define UI_CNSTOOL_RefInportTitle_Nty  ev_UiCnstoolRefInportTitleNty
	/**  ˫��������֪ͨ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDualScreenNty,
#define UI_CNSTOOL_DUALSCREEN_Nty  ev_UiCnstoolDualScreenNty
	/**  �����ĵ������֪ͨ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDCCamCfgNty,
#define UI_CNSTOOL_DCCamCfg_Nty  ev_UiCnstoolDCCamCfgNty
	/**  �����ĵ��������������Ԥ��λ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDCCamBootCallPresetNty,
#define UI_CNSTOOL_DCCamBootCallPreset_Nty  ev_UiCnstoolDCCamBootCallPresetNty
	/**  ���ÿյ��Ƿ����
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolAirCondtitionNty,
#define UI_CNSTOOL_AirCondtition_Nty  ev_UiCnstoolAirCondtitionNty
	/**  �����ĵ�������ͺ�
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolDocCamTypeNty,
#define UI_CNSTOOL_DocCamType_Nty  ev_UiCnstoolDocCamTypeNty
	/**  ����ȫ��������ͺ�
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UiCnstoolPanCamTypeNty,
#define UI_CNSTOOL_PanCamType_Nty  ev_UiCnstoolPanCamTypeNty
	/**  ���Ӽ�����Ϣ֪ͨ����
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UISetQtEncryptInfoNty,
#define UI_SETQTENCRYPTINFO_Nty  ev_UISetQtEncryptInfoNty
		/**  ���Ӽ���������Ϣ֪ͨ����
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UISetQtEncryptInfoInd,
#define UI_SETQTENCRYPTINFO_Ind  ev_UISetQtEncryptInfoInd
	/**  Ftp״̬��Ϣ֪ͨ����
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_CnFtpStateNty,
#define UI_FTPSTATE_NTY  ev_CnFtpStateNty
	/**  Ftp״̬���ûظ���Ϣ֪ͨ����
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_CnOpenFtpRsp,
#define UI_OPENFTP_Rsp  ev_CnOpenFtpRsp
	/**  Ftp�û�����������Ϣ֪ͨ����
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_CnFtpInfoNty,
#define UI_FTPINFO_Nty  ev_CnFtpInfoNty
	/**  Ftp�û������������ûظ���Ϣ֪ͨ����
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_CnSetFtpRsp,
#define UI_SETFTPINFO_Rsp  ev_CnSetFtpRsp
		/**  Telnet״̬��Ϣ֪ͨ����
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_CnTelnetStateNty,
#define UI_TELNETSTATE_NTY  ev_CnTelnetStateNty
	/**  Telnet״̬���ûظ���Ϣ֪ͨ����
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_CnOpenTelnetRsp,
#define UI_OPENTELNET_Rsp  ev_CnOpenTelnetRsp
	/**  Telnet�û�����������Ϣ֪ͨ����
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_CnTelnetInfoNty,
#define UI_TELNETINFO_Nty  ev_CnTelnetInfoNty
	/**  Telnet�û������������ûظ���Ϣ֪ͨ����
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_CnSetTelnetRsp,
#define UI_SETTELNETINFO_Rsp  ev_CnSetTelnetRsp

	/**  ·��֪ͨ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UItppRouteInfoNty,
#define UI_ROUTEINFO_Nty  ev_UItppRouteInfoNty

	/**  ·�����֪ͨ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UItppAddRouteInd,
#define UI_ADDROUTE_Ind  ev_UItppAddRouteInd
	
	/**  ·��ɾ��֪ͨ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UItppDelRouteInd,
#define UI_DelROUTE_Ind  ev_UItppDelRouteInd

	/**  ��ƽ̨������֪ͨ
	wParam =  0
	lparam = 0*/
	/************************************************************************/
	ev_UICloudServerInd,
#define UI_CNC_CLOUDSERVER_IND  ev_UICloudServerInd
};
//* @}*/
#endif 
