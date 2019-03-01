/*****************************************************************************
ģ����      : CMS����̨
�ļ���      : cmsConst.h
����ļ�    : 
�ļ�ʵ�ֹ���: ���������ʹ������,��cms��UI���ֺ�lib��umclib �� cnclib�����ֹ�ͬʹ��
����        : �����
�汾        : V1.0  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2011/4/23  1.0          �����      ����
******************************************************************************/
#pragma once

#ifndef _CMSCONST_20110423_H_
#define _CMSCONST_20110423_H_

#include "printctrl.h"  

//------------------------------��������------begin-------------------------------
#define ARRAY                          vector
#define INVALID_WORD           0xffff                                           //�Ƿ���u16 / unsinged short ���͵�ֵ
#define INVALID_DWORD          0xffffffffff                                     //�Ƿ���u32/ DWORD ���͵�ֵ
#define MSG_SUCESS             -1                                               //��Ϣ����ʱʹ��


#define INSTANT_CONFTEMPLATE_ID   0                                             //���ڿ���ʱ����� ����ģ��  
#define INSTANT_CONFTEMPLATE_NAME "����ʱ����"                                  //���ڿ���ʱ����� ����ģ�� 
#define PTP_CONF                  "��Ե����"                                  //��Ե����

#define CONFTEMPLATE_MAX_COUNT    128                                            //����ģ������Ϊ128��
#define MAX_VOLUME                32                                           //�������


#define MAX_USER_COUNT           128                                         //����û�����
#define MAX_PAGE_COUNT           14                                          //һҳ��ʾ�����᳡����

#define MANAGER_USER              "admin"                                    //����Ա�û���
#define MANAGER_PSWD              "kedacomTP"									 //����Ա����
#define TP_PASSWORD               "tpkedacom"                                //������������

 
#define CONNETCT_SERVER_PORT   60001                                     //��¼UMS�������˿�
#define CONNETCT_CNS_PORT      60002                                     //CNS�������˿ں� 
#define CNS_SIP_LISTEN_PORT    60000
#define LOCAL_CNS                 1                                      //����CNS Inst��

#define INVALID_ALIAS_FOR_SHOW        "; / ? : @ & = + $ �� % ^ ����#"               //��ʾ���û��ķǷ��ַ��������в����԰�����������������ʧ��
#define INVALID_ALIAS_FOR_CODE        "  `~!@$^&%()+=#|{}:;'\\[]<>/?����������������������������'�����������磦"  //������ʹ�ã�Ϊ�˱�����ʾ��ͬʱ���õ��������뷨�µ���ͬ�ַ�
#define RTP_LOCALVIDEO_PORT    10000 	                // ����RTP�˿�

#define DEFAULT_CODEGE         CP936

//������MainMenu��
#define MENU_ENDCONF           "��������"       
#define MENU_CNSCTRL           "�᳡����"
#define MENU_AUDMIX            "��������"
#define MENU_PIP		       "���л�"
#define MENU_TVW               "����ǽ"
#define MENU_CNSPOLL           "�᳡��ѯ"
#define MENU_MUTE              "��˷翪��"
#define MENU_QUITE             "����������"
#define MENU_CNSDUAL           "������ʾ����"
#define MENU_SPEAKER           "������"
#define MENU_MIC               "��˷�"
#define MENU_DUALSRC           "��ʾԴ"
#define MENU_ADDRBOOK          "��ַ��"


#define PrtMsg (CPrintCtrl::GetPrintCtrl()->PrintMsg)                        //��ӡ��Ϣ�ӿ�
#define PrtMsgForce (CPrintCtrl::GetPrintCtrl()->ForcePrtMsg)
#define IS_PRINT_ENTER_MSG (CPrintCtrl::GetPrintCtrl()->IsPrintEnterMsg())   //�Ƿ�Ҫ��ӡ��ڴ���Ϣ
#define IS_PRINT_OUT_MSG (CPrintCtrl::GetPrintCtrl()->IsPrintOutMsg())       //�Ƿ��ӡ���ڴ���Ϣ
#define MAPPING_HELPER (CPrintCtrl::GetPrintCtrl()->MappingHelper)           //ע���ӡ����Ϣ��
  


//------------------------------�����벿��------begin-------------------------------
/* ժ��errorid.h
�ն˿���̨����(27501 - 29500)
#define ERR_CMS_BGN		ERR_HDU_END + 1
#define ERR_CMS_END		ERR_CMS_BGN + 1999
*/
#include "errorid.h"	// �����뷶Χ�ζ���

//���ò��� 
enum EmErrCommon
{
#define  ERR_COMMON_BEGIN  ERR_CMS_BGN

	
	errCms = ERR_COMMON_BEGIN,
#define  ERR_CMS  errCms 

//osp ��ʼ��ʧ��
	errOspInit,
#define  ERR_CMS_OSP_Init  errOspInit   

//���ʱ
    errCmdTimeout,
#define  ERR_CMS_CMD_TIME_OUT errCmdTimeout 

	//δ�ҵ���Ӧ��
    errNotFind,
#define  ERR_CMS_NOT_FIND   errNotFind


	//�����Ƿ�
    errParamIllegal,
#define  ERR_CMS_PARAM   errParamIllegal

 
   errCommonEnd,
#define ERR_COMMON_END  errCommonEnd
};


 

//umcLib�еĴ�����
enum EmErrUmcLib
{
#define  ERR_UMC_LIB_BEGIN  ERR_COMMON_END+1  

	
//�����ʱ
   errUmcCmdTimeout= ERR_UMC_LIB_BEGIN, 
#define ERR_UMC_CMD_TIMEOUT errUmcCmdTimeout 

//umcLib ��ʼ�� ospʧ��	
   errUmcOspInit,
#define	ERR_UMC_OSP_Init       
 
//����APP ʧ��
  errCreateOspFail,
#define ERR_UMC_CREATE_OSP_FAIL errCreateOspFail
 

//������
   errActiveConnection,
#define	 ERR_UMC_ACTIVE_CONNECTION errActiveConnection 
   

//tcp����ʧ��
   errCreateTcpFail,
#define	ERR_UMC_CREATE_TCP_FAIL errCreateTcpFail    

   

//osp �ȴ��������� 
   errWaitForSendCmd,
#define  ERR_UMC_WAIT_FOR_SEND_CMD    NO_ERROR   //errWaitForSendCmd �����������ʱ �ᱨ��            
 	 
//---------login--------- 
//��¼umsʧ��
    errLoginFail,
#define ERR_UMC_LOGIN_FAIL   errLoginFail

    errLoginUmsUserErr,
#define  ERR_UMC_LOGIN_UMS_USER_ERR errLoginUmsUserErr 

   errLoginUmsPswdErr,
#define  ERR_UMC_LOGIN_UMS_PSWD_ERR errLoginUmsPswdErr    

   //�ﵽ�û���¼����
   errLoginUmsMaxLogin,
#define  ERR_UMC_LOGIN_UMS_MAX_LOGIN errLoginUmsMaxLogin          
 	
//�ﵽ�û���¼����
   errLoginUmsLogged,
#define  ERR_UMC_LOGIN_UMS_LOGED errLoginUmsLogged   


  //�ﵽ�û���¼����
   errLoginUmsSysIniting,
#define  ERR_UMC_LOGIN_UMS_SYSINITING errLoginUmsSysIniting   

   
//---------ʹ�û���ģ�忪�����--------- 
//δ֪����
   errCmsStartConf_UnknowErr,
#define  ERR_UMC_STARTCONF_CONFTEMP_UNKNOW_ERR  errCmsStartConf_UnknowErr

   //��������ʧ�ܣ�����ģ�岻����
   errCmsStartConf_ConftempUnexist,
#define  ERR_UMC_STARTCONF_CONFTEMP_UNEXIST  errCmsStartConf_ConftempUnexist
   
   //��������ʧ�ܣ���������
   errCmsStartConf_ConfFull,
#define  ERR_UMC_STARTCONF_CONF_FULL  errCmsStartConf_ConfFull
    
   
   //��������ʧ�ܣ������Ѵ���
   errCmsStartConf_ConfExist,
#define  ERR_UMC_STARTCONF_CONF_EXIST  errCmsStartConf_ConfExist
   
//---------�������---------    
   // ����ʧ�ܣ��Զ˲�����
   errCmsCallCnsHungup,
#define  ERR_UMC_CALLCNS_HUNGUP EmCnsCallReason_hungup
   
   //����ʧ�ܣ��Զ˲��ɴ�
   errCmsCallCnsUnreachable,
#define  ERR_CMS_CALLCNS_UNREACHABLE errCmsCallCnsUnreachable
   
   
   //����ʧ�ܣ��Զ��޿�����Դ
   errCmsCallCnsResourcefull,
#define  ERR_UMC_CALLCNS_RESOURCE_FULL errCmsCallCnsResourcefull
   
   
   //����ʧ�ܣ��Զ˲�����
   errCmsCallCnsDstNotFound,
#define  ERR_UMC_CALLCNS_DST_NOT_FOUND errCmsCallCnsDstNotFound
   
   
   //����ʧ�ܣ��Զ�æ
   errCmsCallCnsBusy,
#define  ERR_UMC_CALLCNS_BUSY errCmsCallCnsBusy
   
   //����ʧ�ܣ�����ԭ��
   errCmsCallCnsLocal,
#define  ERR_UMC_CALLCNS_LOCAL errCmsCallCnsLocal
   
   //����ʧ�ܣ����鲻����
   errCmsCallCnsNoConf,
#define  ERR_CMS_CALLCNS_NO_CONF errCmsCallCnsNoConf
   
   //����ʧ�ܣ��Զ����ڻ�����
   errCmsCallCnsExist,
#define  ERR_UMC_CALLCNS_CNS_EXIST errCmsCallCnsExist

   //�Զ˾ܾ�
   errCmsCallCnsRejected,
#define  ERR_UMC_CALLCNS_CNS_REJECTED errCmsCallCnsRejected

   //�Զ˹Ҷ�
   errCmsCallCnsPeerHungup,
#define  ERR_UMC_CALLCNS_CNS_PEERHUNGUP errCmsCallCnsPeerHungup

   //���ص��߹Ҷ�
   errCmsCallCnsAbnormal,
#define  ERR_UMC_CALLCNS_CNS_ABNORMAL  errCmsCallCnsAbnormal
   
   //�Զ˵��߹Ҷ�
   errCmsCallCnsPeerAbnormal,
#define  ERR_UMC_CALLCNS_CNS_PEERABNORMAL  errCmsCallCnsPeerAbnormal

   //�������
   errCmsCallCnsConfOver,
#define  ERR_UMC_CALLCNS_CNS_CONFOVER  errCmsCallCnsConfOver

   //����ģ��(cncall)����
   errCmsCallCnsCallException,
#define  ERR_UMC_CALLCNS_CNS_CALLEXCEPTION  errCmsCallCnsCallException

   //�����Ѵ���
   errCmsCallCnsConfExist,
#define  ERR_UMC_CALLCNS_CNS_CONFEXIST  errCmsCallCnsConfExist

   //δ֪ԭ��
   errCmsCallCnsUnKnown,
#define  ERR_UMC_CALLCNS_CNS_UNKNOWN  errCmsCallCnsUnKnown
   
   //�Ҷϻ������
   errCmsHungupConfUnexist,
#define  ERR_UMC_HUNGUP_CONF_UNEXIST errCmsHungupConfUnexist

//---------��ַ�����--------- 
   //������ͬ��ַ����Ŀ
   errUmcAddrEntryExist,
#define ERR_UMC_ADDR_ENTRY_EXIST errUmcAddrEntryExist

    errUmcLibEnd,
#define ERR_UMC_LIB_END errUmcLibEnd

};




//cncLib�еĴ�����
enum EmErrCncLib
{

#define ERR_CNC_LIB_BEGIN  ERR_UMC_LIB_END+1 

	// CNS����̨����
	errCnc = ERR_CNC_LIB_BEGIN,
#define ERR_CNC                 errCnc

	//����ʵ��ʧ��
	errCreatInstance,
#define ERR_CNC_CREATINSTANCE   errCreatInstance

	//�ӿ���Ч
	errInterface,
#define ERR_CNC_INTERFACE       errInterface

	//��������
	errActiveConnect,
#define	ERR_CNC_ACTIVE_CONNECT  errActiveConnect

	//TCP����ʧ��
	errTcpConnect,
#define	ERR_CNC_TCPCONNECT      errTcpConnect
	
	//ץ���ܾ�����
	refuseCNCLOGIN,
#define	Refuse_CNC_LOGIN      refuseCNCLOGIN

	//TCP����ʧ��
	errCnsLoginFail,
#define	ERR_CNC_LOGIN_FAIL     errCnsLoginFail

	//osp �ȴ��������� 
	errCncWaitSendCmd,
#define ERR_CNC_WAIT_FOR_SEND_CMD errCncWaitSendCmd 
	
    //����Խ��
    errCncArrayOverbounds,
#define ERR_CNC_ARRAY_OVERBOUNDS  errCncArrayOverbounds

	errCncLibEnd,
#define ERR_CNC_LIB_END      errCncLibEnd
		
};


 

//cms UI�еĴ�����
enum EmErrCmsUI
{
 
 //��¼���
    //ums ��¼ʧ��
   errCmsUmsLogin =  ERR_CNC_LIB_END+1 ,
#define ERR_CMS_UI_UMS_LOGIN errCmsUmsLogin

   //cns��¼ʧ��
   errCmsCnsLogin  ,
#define ERR_CMS_UI_CNS_LOGIN errCmsCnsLogin
  
//�û����ظ�
  errCmsNameRepeat,
#define  ERR_CMS_UI_NAME_REPEAT errCmsNameRepeat
 
 
  //E164���ظ�
  errCmsE164Repeat ,
#define  ERR_CMS_UI_E164_REPEAT errCmsE164Repeat
   
  //δ��ȡ������cns��Ϣ
  errCmsGetLocalCnsInfo,
#define ERR_CMS_Get_LOCAL_CNS_INFO errCmsGetLocalCnsInfo



//----����ģ�� ���------begin--

  //cnsID Ϊ�Ƿ�ֵ,cns ������
  errCmsCnsIDInvalid,
#define ERR_CMS_CNSID_INVALID errCmsCnsIDInvalid

  //ģ�� ������
  errCmsConfTempUnexist,
#define ERR_CMS_CONFTEMP_UNEXIST errCmsConfTempUnexist
  //ģ�� ����Ϊ��
  errCmsConfTempAlairsEmpty,
#define ERR_CMS_CONFTEMP_ALIARS_EMPTY errCmsConfTempAlairsEmpty

  //ģ�����ظ�
  errCmsConfTempAlairsRepeat,
#define ERR_CMS_CONFTEMP_ALIARS_REPEAT errCmsConfTempAlairsRepeat

  //ģ�����ظ�
  errCmsConfTempE164Repeat,
#define ERR_CMS_CONFTEMP_E164_REPEAT errCmsConfTempE164Repeat

  
  //cns ����Ϊ��
  errCmsCnsAlairsEmpty,
#define ERR_CMS_CNS_ALIARS_EMPTY errCmsCnsAlairsEmpty

  //cns �����Ѵﵽ���
  errCmsCnsMaxNum,
#define ERR_CMS_CNS_MAX_NUM errCmsCnsMaxNum

  //cns�����ظ�
  errCmsCnsAliarsRepeat,
#define ERR_CMS_CNS_ALIAS_EXIST errCmsCnsAliarsRepeat

  // 
  errCmsCnsUnknow,
#define ERR_CMS_CNS_UNKNOW errCmsCnsUnknow

  errCmsCnsUneixt,
#define ERR_CMS_CNS_UNEXIST errCmsCnsUneixt 


//ģ�����ϯ���Ǳ���cns
  errCmsTemplateChairManNotLocalCns,
#define ERR_CMS_TEMPLATE_CHAIRMAN_NOT_LOCAL_CNS errCmsTemplateChairManNotLocalCns 
//----����ģ�� ���------end




//----����  ���------begin


//���鲻����
errCmsConfUneixt,
#define ERR_CMS_CONF_UNEXIST errCmsConfUneixt


//----����  ���------end



//�û����
//���鲻����
errCmsOperateUserFail,
#define ERR_CMS_OPERATE_USER_FAIL errCmsOperateUserFail
  
  errCmsUiEnd,		
#define ERR_CMS_UI_END   errCmsUiEnd
		
};  
 

 
#endif
