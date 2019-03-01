/*****************************************************************************
ģ����      : CMS����̨
�ļ���      : umsSessionCtrlIF.h
����ļ�    : 
�ļ�ʵ�ֹ���: һ��ums�ĻỰ,1.����UMS 2.����������ӹ��̣��ж����򷢳�֪ͨ 3.��������ֱ�Ӻ�UMS�����Ľӿڣ�������Ϣ�ȣ�
����        : �����
�汾        : V1.0  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2011/4/25  1.0          �����      ����
******************************************************************************/

#if !defined(AFX_UMSSESSIONCTRLIF_H__8A75E9D0_6535_4DD2_A298_1BE3D2D80850__INCLUDED_)
#define AFX_UMSSESSIONCTRLIF_H__8A75E9D0_6535_4DD2_A298_1BE3D2D80850__INCLUDED_
#include "kdvdispevent.h"

#include "conftemplatectrlif.h"
#include "confctrlif.h"
#include "umsconfigctrlif.h"
#include "tvwctrlif.h"
#include "userctrlif.h"
#include "cncaddrbookif.h"
#include "umsexportCtrlIF.h"
#include "umssysinfoCtrlIF.h"
#include "umstvwboardCtrlIF.h"
#include "umsboardCtrlIF.h"
#include "umsNetMngCtrlIF.h"
#include "umsVTRCtrlIF.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CUmsSessionCtrlIF:public  CKdvDispEvent 
{
public:
 
/** @defgroup  umsSession�ӿ�
 *  @{
 */


  /**
	* ����   ���ӵ�UMS 
	* @param [in]  dwIP	������UMS��IP��ַ��������
	* @param [in]  strUser �û���	
	* @param [in]  strPwd	����
	* @return u16 �ɹ�����0;ʧ�ܷ��ط�0������ 
	*/
	virtual u16 ConnectUms(u32 dwIP, u16 dwPort,   LPCTSTR pStrUserName,
	                         LPCTSTR pStrUserPswd, BOOL32 bConnect = TRUE) = 0;


   /**
    * ����:	�Ͽ���UMS������
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks	��û�����ӵ�UMSʱ���ô˷����������κ�����
	*/
	virtual u16 DisconnectUms() = 0; 
   
	/**
	* ����:	��ȡ�ӿ�ģ��
	* @param [out]  �ӿ�ģ���Ӧ��ָ��
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
    */
    virtual u16 GetCtrlInterface(CConfTemplateCtrlIF **ppCtrl) const = 0;
	virtual u16 GetCtrlInterface(CConfCtrlIF **ppCtrl) const = 0;
	virtual u16 GetCtrlInterface(CTvwCtrlIF **ppCtrl) const = 0;
	virtual u16 GetCtrlInterface(CUserCtrlIF **ppCtrl) const = 0;
	virtual u16 GetCtrlInterface(CUmsConfigCtrlIF **ppCtrl) const = 0;
	virtual u16 GetCtrlInterface(CCncAddrbookIF **ppCtrl) const = 0;
	virtual u16 GetCtrlInterface(CUmsSysInfoCtrlIF **ppCtrl) const = 0;
	virtual u16 GetCtrlInterface(CUmsExportCtrlIF **ppCtrl) const = 0;
	virtual u16 GetCtrlInterface(CUmsTvwBoardCtrlIF **ppCtrl) const = 0;
	virtual u16 GetCtrlInterface(CUmsBoardCtrlIF **ppCtrl) const = 0;
	virtual u16 GetCtrlInterface(CUmsNetMngCtrlIF **ppCtrl) const = 0;
	virtual u16 GetCtrlInterface(CUmsVTRCtrlIF **ppCtrl) const = 0;

 
	/**
	* ����:	��ѯ�Ƿ��ʼ�����
	* @return  TRUE:��ʼ�����   FALSE:û�г�ʼ�����
    */
	virtual BOOL IsInitFinish() = 0;

 
  /**
	* ����:	��ѯ�Ƿ�������UMS
	* @return  TRUE 	������UMS    FALSE	û������UMS
    */
	virtual BOOL IsConnectedUms() = 0;



 /**
	* ����:	�û��Ƿ��ǹ���Ա
	* @return  TRUE�ǹ���Ա    FALSEһ���û�
	*/
	virtual BOOL IsManagerUser() = 0;

  /**
	* ����:	��ȡums ��IP 
	* @return  u32  IP
    */
	virtual u32 GetUmsIP() = 0;


	/**
	* ����:	��ȡ���� ��IP 
	* @return  u32  IP
    */
	virtual u32 GetLocalIP() = 0;


	/**
	* ����:	��ȡ��¼���û���Ϣ
	* @return   
    */
	virtual const CLoginRequest& GetConnectedUser() = 0;
 
/** @}*/  //umsSession �ӿ�
};

#endif // !defined(AFX_UMSSESSIONCTRLIF_H__8A75E9D0_6535_4DD2_A298_1BE3D2D80850__INCLUDED_)
