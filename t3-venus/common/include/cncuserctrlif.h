//cncuserctrlif.h: interface for the CCncUserCtrlIF class.
//
//////////////////////////////////////////////////////////////////////
#ifndef __CNCUSERCTRLIF_H__
#define __CNCUSERCTRLIF_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "kdvdispevent.h"
#include "ummessagestruct.h"

class CCncUserCtrlIF : public CKdvDispEvent  
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
	virtual u16  AddUserReq( const CUserFullInfo& tUser ) = 0 ;


 
	/**
    * ����:	 	�޸��û�
	* @param [in]  tUser	 �û� 
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
	virtual u16  ModifyUserReq( const CUserFullInfo& tUser ) = 0 ;


 
  /**
    * ����:	 	ɾ���û�
	* @param [in]  tUser	 �û� 
	* @return  u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks 
	*/
	virtual u16  DeleteUserReq( const CUserFullInfo& tUser )  = 0 ;

	/** @}*/ // �����û��ӿ�

};

#endif
