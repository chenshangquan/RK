// umclib.h: interface for the CUmcLib class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UMCLIB_H__0716A064_82EA_4A2A_AF20_4D58037DB76E__INCLUDED_)
#define AFX_UMCLIB_H__0716A064_82EA_4A2A_AF20_4D58037DB76E__INCLUDED_

//#ifndef UMCLIB_H
//#define UMCLIB_H

#pragma warning( disable : 4786 )	// ��ʶ�����Ƴ���255�ֽ�	// ��ʶ�����Ƴ���255�ֽ�
#include "kdvtype.h"
#include "umsSessionCtrlIF.h" 

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

  
/*��  ��	����session
��  ��	��
����ֵ	 
˵  ��	��*/
void	CreateUmsSession( CUmsSessionCtrlIF ** ppSession = NULL, u16 wAppId = AID_CMS2UMS_APP, BOOL bUseAddr = TRUE );

/*��  ��	����session
��  ��	��
����ֵ	 
˵  ��	��*/
void    DesdoryUmsSession( CUmsSessionCtrlIF ** ppSession );

 

#endif // !defined(AFX_UMCLIB_H__0716A064_82EA_4A2A_AF20_4D58037DB76E__INCLUDED_)
