/*****************************************************************************
ģ����      : CMS����̨
�ļ���      : umsconfigctrlIF.h
����ļ�    : 
�ļ�ʵ�ֹ���: ums������
����        : �����
�汾        : V1.0  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2011/4/25  1.0          �����      ����
******************************************************************************/

#if !defined(AFX_UMSCONFIGCTRLIF_H__DD124CB2_4C14_4570_A2F4_F6411FA98B52__INCLUDED_)
#define AFX_UMSCONFIGCTRLIF_H__DD124CB2_4C14_4570_A2F4_F6411FA98B52__INCLUDED_
#include "kdvdispevent.h"
#include "eventoutumsreg.h"
#include "cmsstruct.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUmsConfigCtrlIF:public  CKdvDispEvent   
{
public:

/** @defgroup  ums���ò��ֽӿ�
 *  @{
*/

 /*��  ��	sipע��
	��  ��	 
	����ֵ	�ɹ�����0,ʧ�ܷ��ط�0������
	˵  ��	 */
	virtual u16 RegSipService( const TTPSipRegistrarCfg &tSipCfg )   = 0;


 /*��  ��	ע��sip 
	��  ��	 
	����ֵ	�ɹ�����0,ʧ�ܷ��ط�0������
	˵  ��	 */
	virtual u16 UnRegSipService( const TTPSipRegistrarCfg &tSipCfg )   = 0;


 /*��  ��	��ȡsip����
	��  ��	 
	����ֵ	�ɹ�����0,ʧ�ܷ��ط�0������
	˵  ��	 */
	virtual u16 GetSipCfg( TTPSipRegistrarCfg &tSipCfg )   = 0;

    /* ����:  ��ȡIP����	 
        * @param [out]   
        * @return u16 �ɹ�����0;ʧ�ܷ��ط�0������
        * @remarks	 
        */ 
	virtual u16 GetEthnetCfg( TTPEthnetInfo &tEthnetCfg ) = 0 ;

	/** 
	* ����:  ����IP	 
	* @param [out]  cfg ��ip��Ϣ
	* @return u16 �ɹ�����0;ʧ�ܷ��ط�0������
	* @remarks	 
	*/ 
	virtual u16  UpdateEthnetCfg( const TTPEthnetInfo& cfg ) = 0;


			     /**
    * ����:	 gk ע������
    * @param [int]  tTvwInfo�����󲥷ŵĵ���ǽ��Ϣ
    * @return    
    * @remarks  �ɹ�����0��ʧ�ܷ��ش�����
    */
	virtual u16 GkRegReq( const TTPGKCfg & tGkwInfo ) = 0; 

		    /* ����:  ��ȡGK����	 
        * @param [out]   
        * @return u16 �ɹ�����0;ʧ�ܷ��ط�0������
        * @remarks	 
        */ 
	virtual u16 GetGkCfg( TTPGKCfg &tGKRegCfg ) = 0;

			/**
    * ����:	  UMSϵͳʱ������
    * @param [out]  cMsg ��Ϣ
    * @return  ��
    * @remarks   
    */
	virtual u16 OnSysTimeSetReq(const TTPTime& time) = 0;

		/** 
	* ����  UI�õ�ϵͳʱ��ӿ�
	* @param [in]  
	* @return  
	*/
	virtual u16 GetUmsSystime(TTPTime& pTTime) = 0;

		/** 
	* ����  ����SIPע����Ϣ
	* @param [in]  emType ע������
	* @return  
	* @remarks 
	*/
	virtual u16 ReqSipRegInfo( EmGetRegInfoType emType ) = 0;

	    /**
    * ����:	 	        ����ums��������
	* @param [in]       ��
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  RebootReq() = 0;

	/** 
	* ����  ��ȡCnsע����Ϣ
	* @return  vector<TTPAlias>  Cnsע����Ϣ
	* @remarks 
	*/
	//virtual const vector<TTPAlias>& GetCnsRegInfo() const = 0;

	/** 
	* ����  ��ȡUmsע����Ϣ
	* @return  vector<TTPAlias>  Umsע����Ϣ
	* @remarks
	*/
	//virtual const vector<TTPAlias>& GetUmsRegInfo() const = 0;

			/** 
	* ����  ��ȡ����ע����Ϣ
	* @param [in]  
	* @return  
	*/
	//virtual const vector<TTPAlias>& GetAllRegInfo() const = 0;

	/** 
	* ����  ��ȡ����ע����Ϣ
	* @param [in]  
	* @return  
	*/
	virtual const vector<TAliasEx>& GetAllTAliasEx() const = 0;

	/* ����:  ��ȡSipע����
    * @param
    * @return BOOL �ɹ�����TRUE;ʧ�ܷ���FALSE
    * @remarks	 
    */ 
	virtual BOOL GetSipRegRsp() = 0;

	/* ����:  ��ȡGKע����
    * @param
    * @return BOOL �ɹ�����TRUE;ʧ�ܷ���FALSE
    * @remarks	 
    */
	virtual BOOL GetGKRegRsp() = 0;


/** @}*/ 
};

#endif // !defined(AFX_UMSCONFIGCTRLIF_H__DD124CB2_4C14_4570_A2F4_F6411FA98B52__INCLUDED_)
