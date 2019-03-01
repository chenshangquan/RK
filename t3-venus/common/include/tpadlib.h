// tpadlib.h: interface for the CTpadLib class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TPADLIB_H__0EE6CC47_C8B2_4333_B5FE_001BDD8DD258__INCLUDED_)
#define AFX_TPADLIB_H__0EE6CC47_C8B2_4333_B5FE_001BDD8DD258__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "tpadsessionif.h"

class CTPadLib  
{
public:
	CTPadLib();
	virtual ~CTPadLib();

    /*����	����ʵ���˽ӿ�CTPadSessionIF�Ķ���
	����	ppIf	[out]�ɹ�����CTPadSessionIF�ӿ�,ʧ�ܷ���NULL
	����ֵ	�ɹ�����0,ʧ�ܷ��ط�0������
	˵��	�ӿ�ʹ����ɺ�,����DestroyInstance�������ٶ���*/
	static u16 CreateSession( CTPadSessionIF **ppIf );

	/*����	����ʵ���˽ӿ�CTPadSessionIF�Ķ���
	����	ppIf	[in, out]�ӿ�CTPadSessionIF,�ɹ��󷵻�NULL
	����ֵ	�ɹ�����0,ʧ�ܷ��ط�0������
	˵��	ֻ��������CreateSession���������Ķ���*/
	static u16 DestroySession( CTPadSessionIF **ppIf );
};

#endif // !defined(AFX_TPADLIB_H__0EE6CC47_C8B2_4333_B5FE_001BDD8DD258__INCLUDED_)
