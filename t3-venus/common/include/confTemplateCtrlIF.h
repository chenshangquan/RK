/*****************************************************************************
ģ����      : CMS����̨
�ļ���      : confTemplateCtrlIF.h
����ļ�    : 
�ļ�ʵ�ֹ���: ����ģ����ص����в���
����        : �����
�汾        : V1.0  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2011/4/25  1.0          �����      ����
******************************************************************************/
//Note:��������ͻ����E164�ž������ظ����һ����������Ϊ�Ǵ����֣�����164�ű���Ϊ������

#if !defined(AFX_CONFTEMPLATECTRLIF_H__291A729D_3EC2_42F1_8E39_D9C20E52B18A__INCLUDED_)
#include "kdvdispevent.h"
#include "tplarray.h"
#include "cmsstruct.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CConfTemplateCtrlIF:public  CKdvDispEvent 
{
 
public:
/** @defgroup  ����ģ��ӿ�
 *  @{
 */


  /**
    * �� ��:	��ȡ����ģ���б�
	* @param [out] tplConfTempList	 ����ģ���б�
	* @return �ɹ�����0,ʧ�ܷ��ط�0������
	*/
	virtual u16 GetConfTemplateList( TplArray<TTPConfTemplate> &tplConfTempList ) const = 0;
   
  /**
    * ����:  ��ӻ���ģ��
	* @param [in]	tConfTemp	 ����ģ�� 
	* @return	�ɹ�����0,ʧ�ܷ��ط�0������
	*/
	virtual u16 AddConfTemplateReq( const TTPConfTemplate &tConfTemp )    = 0 ;
 
 
	/**
    * ����:  �޸Ļ���ģ��
	* @param [in]	tConfTemp	 ����ģ�� 
	* @return	�ɹ�����0,ʧ�ܷ��ط�0������
	*/
	virtual u16 ModifyConfTemplateReq( const TTPConfTemplate &tConfTemp )    = 0 ;

  
	/**
    * ����:  ɾ������ģ��
	* @param [in] wConfTempID	 ����ģ��ID 
	* @return	�ɹ�����0,ʧ�ܷ��ط�0������
	*/
	virtual u16 DeleteConfTemplateReq( const u16 wConfTempID )    = 0 ;

	/**
    * ����:  ɾ��ȫ��ģ��
	* @param
	* @return	�ɹ�����0,ʧ�ܷ��ط�0������
	*/
	virtual u16 DelAllConfTempReq() = 0;   //by xhx

/** @}*/  //����ģ������ӿ�
};

#endif // !defined(AFX_CONFTEMPLATECTRLIF_H__291A729D_3EC2_42F1_8E39_D9C20E52B18A__INCLUDED_)
