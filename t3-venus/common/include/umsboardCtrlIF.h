/*****************************************************************************
ģ����      : umstool����ά������
�ļ���      : umsboardCtrlIF.h
����ļ�    : 
�ļ�ʵ�ֹ���: ums��������в���
����        : ����ӡ
�汾        : V1.0  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2012/11/23  1.0         ����ӡ      ����
******************************************************************************/
#if !defined(AFX_BOARDCTRLIF_H__F47ED342_9A87_4124_8677_30F8A69F7D1A__INCLUDED_)
#define AFX_BOARDCTRLIF_H__F47ED342_9A87_4124_8677_30F8A69F7D1A__INCLUDED_
#include "kdvdispevent.h"
#include "ummessagestruct.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUmsBoardCtrlIF :public  CKdvDispEvent  
{
public:
		/**
    * ����:	 ��ȡ����ռ�������Ϣ����
	* @param [out]  TTPBrdUsedInfo	����ռ����Ϣ(����������������ϳɡ�����������ռ��)
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
	virtual u16  GetUmsBoardUsedData( TTPBrdUsedInfo& tBoardUsed) const = 0;

       /**
    * ����:	 	        �����޸ĵ�������
	* @param [in]       ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  BoardModifyReq( const TTPBrdCfg& tTPbrdCfg ) = 0;

    /**
    * ����:	 	        ����ɾ����������
	* @param [in]       ������Ϣ��
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  BoardDeleteReq( const TTPBrdCfg& tTPbrdCfg ) = 0;

    /**
    * ����:	 	        ������ӵ�������
	* @param [in]       ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  BoardAddReq( const TTPBrdCfg& tTPbrdCfg ) = 0;

    /**
    * ����:	 	        ������ӵ���ģʽ����
	* @param [in]       ģʽ��Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
//	virtual u16  BoardModeAddReq( const TTPBrdMdlInfo& tTPbrdMdlInfo ) = 0;

    /**
    * ����:	 	        �����޸ĵ���ģʽ����
	* @param [in]       ģʽ��Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  BoardModeModifyReq( const TTPBrdMdlInfo& tTPbrdMdlInfo ) = 0;

    /**
    * ����:	 	        ����ɾ������ģʽ����
	* @param [in]       ģʽ��Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  BoardModeDeleteReq( const TTPBrdMdlInfo& tTPbrdMdlInfo ) = 0;

	    /**
    * ����:	 	        ����������������
	* @param [in]       TTPBrdPos ����λ��
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  BoardRebootReq( const TTPBrdPos& tTPbrdPos ) = 0;

	    /**
    * ����:	 	        ���ͻ�����ռ������
	* @param [in]       ��
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  BoardAudiomixReq() = 0;
	
	    /**
    * ����:	 	        ���ͻ���ϳ�ռ������
	* @param [in]       ��
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  BoardVmpReq() = 0;

	    /**
    * ����:	 	        ������������ռ������
	* @param [in]       ��
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  BoardBasStreamReq() = 0;

	    /**
    * ����:	 	        ������������
	* @param [in]       const TTPBrdUpGrade& tBrdUpGrade   ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   
	*/
	virtual u16  BoardUpgradeReq(const TTPBrdUpGrade& tBrdUpGrade) = 0;

 /** @}*/ // ��������ӿ�

};

#endif // !defined(AFX_BOARDCTRLIF_H__F47ED342_9A87_4124_8677_30F8A69F7D1A__INCLUDED_)
