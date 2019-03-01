/*****************************************************************************
ģ����      : umstool����ά������
�ļ���      : umssysinfoCtrlIF.h
����ļ�    : 
�ļ�ʵ�ֹ���: umsϵͳ��Ϣ�����в���
����        : ����ӡ
�汾        : V1.0  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2012/11/23  1.0         ����ӡ      ����
******************************************************************************/
#if !defined(AFX_SYSINFOCTRLIF_H__F47ED342_9A87_4124_8677_30F8A69F7D1A__INCLUDED_)
#define AFX_SYSINFOCTRLIF_H__F47ED342_9A87_4124_8677_30F8A69F7D1A__INCLUDED_
#include "kdvdispevent.h"
#include "ummessagestruct.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUmsSysInfoCtrlIF :public  CKdvDispEvent  
{
public:

	/**
    * ����:	 ��ȡums�汾��Ϣ����
	* @param [out]  tUmsVer	 ums�汾
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
	virtual u16  GetUmsVerData( TUmsVersion& tUmsVer) const = 0;

	/**
    * ����:	 ��ȡums CPU���ڴ����Ϣ����
	* @param [out]  tUmsSysInfo	 ums cpu���ڴ���Ϣ
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
	virtual u16  GetUmsSysInfoData( TToolSysInfo& tUmsSysInfo) const = 0;


	
    /**
    * ����:	 	        ˢ��umsϵͳ��Ϣ����
	* @param [in]       ��
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  RefreshUmsSysInfoReq() = 0;
	
    /**
    * ����:	 	        ��ȡums������Ŀ
	* @param [in]       ��
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  ConfCountReq() = 0;

	/**
    * ����:	 ��ȡums������Ŀ
	* @param [out]  body	u32   ��Ŀ 
	* @return  ������Ŀ
	* @remarks 
	*/
	virtual u32  GetConfCountData() = 0;

    /**
    * ����:	 	        ������Ȩ��Ŀ����
	* @param [in]       ��
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  AuthCountReq() = 0;

	/**
    * ����:	 ��ȡums��Ȩ��Ŀ
	* @param [out]  body	u32   ��Ŀ 
	* @return  ������Ŀ
	* @remarks 
	*/
	virtual std::pair<int,int>  GetAuthCountData() = 0;


    /**
    * ����:	 	        ���͵���ǽռ���������
	* @param [in]       ��
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  TvwUsedCountReq() = 0;

		/**
    * ����:	 ��ȡ����ǽռ�������Ϣ����
	* @param [out]  TTPBrdUsedInfo	����ǽ��ռ����Ϣ
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
	virtual u16  GetUmsTvwUsedData( TTPBrdUsedInfo& tTvwUsed) const = 0;

 /** @}*/ // ����umsϵͳ��Ϣ�ӿ�

};

#endif // !defined(AFX_SYSINFOCTRLIF_H__F47ED342_9A87_4124_8677_30F8A69F7D1A__INCLUDED_)
