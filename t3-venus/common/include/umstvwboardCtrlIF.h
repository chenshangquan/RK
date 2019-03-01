/*****************************************************************************
ģ����      : umstool����ά������
�ļ���      : umstvwboardCtrlIF.h
����ļ�    : 
�ļ�ʵ�ֹ���: ums����ǽ����忨�����в���
����        : ����ӡ
�汾        : V1.0  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2012/11/23  1.0         ����ӡ      ����
******************************************************************************/
#if !defined(AFX_TVWBOARDCTRLIF_H__F47ED342_9A87_4124_8677_30F8A69F7D1A__INCLUDED_)
#define AFX_TVWBOARDCTRLIF_H__F47ED342_9A87_4124_8677_30F8A69F7D1A__INCLUDED_
#include "kdvdispevent.h"
#include "ummessagestruct.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUmsTvwBoardCtrlIF :public  CKdvDispEvent  
{
public:

		/**
    * ����:	 ��ȡ����ǽ�������
	* @param [out]  THduStyleData  ����ǽ�������
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
	virtual u16  GetUmsTvwStyleData( THduStyleData& tHduStyleData ) const = 0;	
				/**
    * ����:	 ��ȡ����ǽ��������
	* @param [out]  std::multimap<u8,THduCfg>  ����ǽ��Ϣ���㡢�ۡ�IP��ͨ����Ϣ�ȣ�
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
	virtual u16  GetUmsTvwBoardData( std::multimap<u8,THduCfg>& mulmapTHduCfg ) const = 0;

    /**
    * ����:	 	        ������ӵ���ǽ��������
	* @param [in]       ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  TvwBoardAddReq( const TTPBrdPos& tTPBrdPos ) = 0;

    /**
    * ����:	 	        �����޸ĵ���ǽ��������
	* @param [in]       ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  TvwBoardModifyReq( const TTPBrdPos& tTPBrdPos ) = 0;

    /**
    * ����:	 	        ����ɾ������ǽ��������
	* @param [in]       ������Ϣ��
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  TvwBoardDeleteReq( const TTPBrdPos& tTPBrdPos ) = 0;

    /**
    * ����:	 	        ������ӵ���ǽ����ģʽ����
	* @param [in]       ģʽ��Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  TvwBoardModeAddReq( const THduInfo& tTHduInfo ) = 0;

    /**
    * ����:	 	        �����޸ĵ���ǽ����ģʽ����
	* @param [in]       ģʽ��Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  TvwBoardModeModifyReq( const THduInfo& tTHduInfo ) = 0;

    /**
    * ����:	 	        ����ɾ������ǽ����ģʽ����
	* @param [in]       ģʽλ��
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  TvwBoardModeDeleteReq( const TTPBrdPos& tTPBrdPos ) = 0;

	    /**
    * ����:	 	        ������������ǽ��������
	* @param [in]       TTPBrdPos ����λ��
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  TvwBoardRebootReq( const TTPBrdPos& tTPbrdPos ) = 0;

			    /**
    * ����:	 	        ����ǽ������������
	* @param [in]       const TTPBrdUpGrade& tBrdUpGrade   ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  TvwBoardUpgradeReq(const TTPBrdUpGrade& tBrdUpGrade) = 0;

	    /**
    * ����:	 	        ��ӵ���ǽ�������
	* @param [in]       tHduStyleData ����ǽ�����Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  AddTvwStyleReq( const THduStyleData& tHduStyleData ) = 0;

	    /**
    * ����:	 	        ɾ������ǽԤ������
	* @param [in]       tHduStyleData ����ǽ�����Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	//virtual u16  TvwStyleDeleteReq() = 0;

 /** @}*/ // ��������ǽ����忨�ӿ�

};

#endif // !defined(AFX_TVWBOARDCTRLIF_H__F47ED342_9A87_4124_8677_30F8A69F7D1A__INCLUDED_)
