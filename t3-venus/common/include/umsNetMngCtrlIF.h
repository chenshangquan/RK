/*****************************************************************************
ģ����      : umstool����ά������
�ļ���      : umsNetMngCtrlIF.h
����ļ�    : 
�ļ�ʵ�ֹ���: ums���ܵ����в���
����        : ʯ��
�汾        : V1.0  Copyright(C) 2012-2013 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2013/1/7    1.0         ʯ��	      ����
******************************************************************************/
#if !defined(AFX_NETMNGCTRLIF_H__F47ED342_9A87_4124_8677_30F8A69F7D1A__INCLUDED_)
#define AFX_NETMNGCTRLIF_H__F47ED342_9A87_4124_8677_30F8A69F7D1A__INCLUDED_
#include "kdvdispevent.h"
#include "tpstruct.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUmsNetMngCtrlIF :public  CKdvDispEvent  
{
public:
	/**
    * ����:	 	        ���������������
	* @param [in]       ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   ev_CnAgtAddNMServerCmd
	*/
	virtual u16  NetMngAddReq( const TTPNMServerCfg& tTPNMServerCfg ) = 0;

    /**
    * ����:	 	        �����޸���������
	* @param [in]       ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   ev_CnAgtDelNMServerCmd
	*/
	virtual u16  NetMngModifyReq( const TTPNMServerCfg& tTPNMServerCfg ) = 0;

    /**
    * ����:	 	        ����ɾ����������
	* @param [in]       ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   ev_CnAgtModifyNMServerCmd
	*/
	virtual u16  NetMngDeleteReq( const TTPNMServerCfg& tTPNMServerCfg ) = 0;

	/** 
	* ����  ��ȡ������Ϣ
	* @param [in]  
	* @return  
	*/
	virtual u16 GetUmsNetMngData( vector<TTPNMServerCfg> &vecTTPNMServerCfg ) = 0;

 /** @}*/ // ��������ӿ�

};

#endif // !defined(AFX_NETMNGCTRLIF_H__F47ED342_9A87_4124_8677_30F8A69F7D1A__INCLUDED_)
