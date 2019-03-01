/*****************************************************************************
ģ����      : CMS����̨
�ļ���      : confTemplateCtrlIF.h
����ļ�    : 
�ļ�ʵ�ֹ���: ������ص����в���
����        : �����
�汾        : V1.0  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2011/4/25  1.0          �����      ����
******************************************************************************/

#if !defined(AFX_UMCCONFCTRLIF_H__10B44268_D175_431C_ACCA_A0A559086730__INCLUDED_)
#define AFX_UMCCONFCTRLIF_H__10B44268_D175_431C_ACCA_A0A559086730__INCLUDED_
#include "kdvdispevent.h"
#include "cmsstruct.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUmcConfCtrlIF:public  CKdvDispEvent   
{

public:
 
/** @defgroup  ������Ʋ��ֽӿ�
 *  @{
 */



  /**
    * ����:	��ȡ�����б�
	* @param [out]  tplConfList	 �����б�
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
	virtual u16 GetConf(  TCMSConf &tplConf  ) const = 0;
  
   
  /**
    * ����:	��ȡ������cns�б�
	* @param [int]  tplConfList	 �����б�
    * @param [out]  tplConfList	 CNS�б�
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
   virtual u16 GetConfCnsList(  TplArray<TCnsInfo> &tplConfCnsList ) const  = 0 ;

   
  /**
    * ����:	��ȡ��������б�
	* @param [int]  wConfID:����ID  
    * @param [out]  tplConfAudmixList	 �����б�
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
   virtual u16 GetConfAudmixList( TAuxMixList&tConfAudmixList ) const = 0 ;

  
    /**
    * ����:	��ȡ������ѯ�б�
	* @param [int]  wConfID:����ID  
    * @param [out]  tplConfPollList	 ��ѯ�б�
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
   virtual u16 GetConfPollList(  TplArray<u16> &tplConfPollList ) const = 0;

 
 
	 
	 

 
   /**
    * ����:	����ĳcns�᳡����ĳ����
	* @param [int]  tEp	 ����ͻ᳡��Ϣ
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
	virtual u16 InviteCnsReq( const TConfCallEpAddr &tEp )  = 0;

  

    /**
    * ����:	���л������Ѿ����ڵ�cns�᳡����ĳ����
	* @param [int]  tEp	 ����ͻ᳡��Ϣ
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��cms->ums  evtp_CallEP_cmd  \n
                       Ӧ�ظ���ums->cms evtp_CallEP_result   \n
	                   ���ɹ�����Ӧ����ums->cms evtp_UpdateConfCnsList_Notify
	*/ 
	virtual u16 CallConfCnsReq( const TConfEpID &tEp ) = 0;



  
   /**
    * ����:	�Ҷϻ���
	* @param [int]  wConfID ����ID
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
	virtual u16 HangupConfReq( ) = 0;


 
  /**
    * ����:	�Ҷ�ĳ�᳡
	* @param [int]  tConfEpInfo �����᳡ID �� ����ID
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks �����б�����Ȼ���ڸû᳡��ֻ�ǲ�����
	*/
	virtual u16 HangupCNSReq( const TConfEpID &tConfEpInfo ) = 0;


 
  /**
    * ����:	�ӻ������Ƴ�ĳ�᳡
	* @param [int]  tConfEpInfo �����᳡ID �� ����ID
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks �����б��в����ڸû᳡
	*/
	virtual u16 RemoveCNSReq( const TConfEpID &tConfEpInfo )  = 0;


 
	/**
    * ����:	���÷��Ի᳡
	* @param [int]  wConfID	 ����ID
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks  
	*/
	virtual u16 SetSpokeCnsReq( const TConfEpID &tConfEpInfo )    = 0;


    /**
    * ����:	����Զ��cns����
	* @param [int]  wConfID	 ����ID
    * @param [int]  bQuiet  TRUE:����������FALSE��ֹͣ����
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks  
	*/
	virtual u16 SetQuietCnsReq( const TConfEpID &tConfEpInfo, BOOL32 bQuiet)    = 0;


    /**
    * ����:	����Զ��cns����
	* @param [int]  wConfID	 ����ID
    * @param [int]  bMute  TRUE:����������FALSE��ֹͣ����
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks  
	*/
	virtual u16 SetMuteCnsReq( const TConfEpID &tConfEpInfo , BOOL32 bMute)    = 0;




     /**
    * ����:	����Զ��cns����˫��
	* @param [int]  wConfID	 ����ID
    * @param [int]  bStart  TRUE:����˫����FALSE��ֹͣ˫��
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks  
	*/
	virtual u16 SetDualCnsReq( const TConfEpID &tConfEpInfo, BOOL32 bStart )    = 0; 


 
	/**
    * ����:	���»����б�����
	* @param [int]  tMixInfo	 �����б�
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks  
	*/
	virtual u16 UpdateAudMixListReq( const TConfAuxMixInfo &tMixInfoList ) = 0;

	/**
    * ����:	���������б�����
	* @param [int]  tDisListOpr	 һ�������б����
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks  
	*/
	virtual u16 AudMixDisListOprCmd( const TDiscussListOpr &tDisListOpr ) = 0;

 
  /**
    * ����:	������ѯ�б�����
	* @param [int]  tTurnInfoList	 ��ѯ�б�
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks  
	*/
	virtual u16 UpdatePollListReq( const TConfTurnInfo &tTurnInfoList ) = 0;


	
 
  /**
    * ����:	��������
	* @param [int]  wConfID	 ����ID
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks  
	*/
	virtual u16 StartAuxMixReq( const u16 wConfID ) = 0;
 
  /**
    * ����:	ֹͣ����
	* @param [int]  wConfID	 ����ID
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks  
	*/
	virtual u16 StopAuxMixReq( const u16 wConfID ) = 0;

 
  /**
    * ����:	������ѯ
	* @param [int]  wConfID	 ����ID
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks  
	*/
	virtual u16 StartPollReq( const u16 wConfID ) = 0;


  
  /**
    * ����:	ֹͣ��ѯ 
	* @param [int]  wConfID	 ����ID
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks  
	*/
	virtual u16 StopPollReq( const u16 wConfID ) = 0;

 
   
/** @}*/  //������Ʋ��ֽӿ�

};

#endif // !defined(AFX_CONFCTRLIF_H__10B44268_D175_431C_ACCA_A0A559086730__INCLUDED_)
