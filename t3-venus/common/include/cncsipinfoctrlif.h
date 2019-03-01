/*****************************************************************************
ģ����      : cmc cnclib�ӿ�
�ļ���      : cncsipinfoctrlif.h
����ļ�    : 
�ļ�ʵ�ֹ���: ��ȡsip������ע����Ϣ�ӿ�
����        : Ф��Ȼ
�汾        : V1.0  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2012/4/12   1.0         Ф��Ȼ        ����
******************************************************************************/
#ifndef __CNCSIPINFOCTRLIF_H__
#define __CNCSIPINFOCTRLIF_H__

#include "kdvdispevent.h"

class CCncSipInfoCtrlIF : public CKdvDispEvent
{
public:
	/** 
	* ����  ����SIPע����Ϣ
	* @param [in]  emType ע������
	* @return  
	* @remarks 
	*/
	virtual u16 ReqSipRegInfo( EmGetRegInfoType emType ) = 0;

	/** 
	* ����  ��ȡCnsע����Ϣ
	* @return  vector<TTPAlias>  Cnsע����Ϣ
	* @remarks 
	*/
	virtual const vector<TAddrInfo>& GetCnsRegInfo() const = 0;

	/** 
	* ����  ��ȡUmsע����Ϣ
	* @return  vector<TTPAlias>  Umsע����Ϣ
	* @remarks
	*/
	virtual const vector<TTPAlias>& GetUmsRegInfo() const = 0;

};

#endif