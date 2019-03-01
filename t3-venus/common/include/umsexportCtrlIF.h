/*****************************************************************************
ģ����      : umstool����ά������
�ļ���      : umsexportCtrlIF.h
����ļ�    : 
�ļ�ʵ�ֹ���: ums���뵼�������в���
����        : ����ӡ
�汾        : V1.0  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2012/11/23  1.0         ����ӡ      ����
******************************************************************************/
#if !defined(AFX_EXPORTCTRLIF_H__F47ED342_9A87_4124_8677_30F8A69F7D1A__INCLUDED_)
#define AFX_EXPORTCTRLIF_H__F47ED342_9A87_4124_8677_30F8A69F7D1A__INCLUDED_
#include "kdvdispevent.h"
#include "ummessagestruct.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUmsExportCtrlIF :public  CKdvDispEvent  
{
public:

   /**
    * ����:	   ��������ģ������
	* @param   �� 
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
	virtual u16  ExportInfoReq()   = 0 ;

   /**
    * ����:	   �������ģ������
	* @param   �� 
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
	virtual u16  ImportInfoReq(const s8* strFileName)   = 0 ;

	/**
    * ����:	   ������Ȩ����
	* @param   �� 
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
	virtual u16  ExportAuthReq()   = 0 ;


 /** @}*/ // ����ums���뵼���ӿ�

};

#endif // !defined(AFX_EXPORTCTRLIF_H__F47ED342_9A87_4124_8677_30F8A69F7D1A__INCLUDED_)
