// userCtrlIF.h: interface for the CUserCtrlIF class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USERCTRLIF_H__F47ED342_9A87_4124_8677_30F8A69F7D1A__INCLUDED_)
#define AFX_USERCTRLIF_H__F47ED342_9A87_4124_8677_30F8A69F7D1A__INCLUDED_
#include "kdvdispevent.h"
#include "ummessagestruct.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUserCtrlIF :public  CKdvDispEvent  
{
public:
 
/** @defgroup  �����û��ӿ�
 *  @{
 */

	/**
    * ����:	 ��ȡ�û��б�
	* @param [out]  tplUserList	 �û��б�
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
	virtual u16  GetUserList( TplArray<CUserFullInfo>& tplUserList) const = 0 ;
   

   /**
    * ����:	 	����û�
	* @param [in]  tUser	 �û� 
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
	virtual u16  AddUserReq( const CUserFullInfo& tUser )   = 0 ;


 
	/**
    * ����:	 	�޸��û�
	* @param [in]  tUser	 �û� 
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
	virtual u16  ModifyUserReq( const CUserFullInfo& tUser )   = 0 ;


 
  /**
    * ����:	 	ɾ���û�
	* @param [in]  tUser	 �û� 
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
	virtual u16  DeleteUserReq( const CUserFullInfo& tUser )   = 0 ;

 /** @}*/ // �����û��ӿ�

};

#endif // !defined(AFX_USERCTRLIF_H__F47ED342_9A87_4124_8677_30F8A69F7D1A__INCLUDED_)
