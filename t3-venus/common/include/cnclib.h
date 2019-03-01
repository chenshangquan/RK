// cnclib.h: interface for the CCncLib class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CNCLIB_H__846EEC8C_FDB4_4222_A2A6_55EC0820D8B3__INCLUDED_)
#define AFX_CNCLIB_H__846EEC8C_FDB4_4222_A2A6_55EC0820D8B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "cnsSessionCtrlIF.h"

class CCncLib  
{
public:
	CCncLib();
	virtual ~CCncLib();

	/*����	����ʵ���˽ӿ�CCnsSessionCtrlIF�Ķ���
	����	ppICnt	[out]�ɹ�����CCnsSessionCtrlIF�ӿ�,ʧ�ܷ���NULL
	����ֵ	�ɹ�����0,ʧ�ܷ��ط�0������
	˵��	�ӿ�ʹ����ɺ�,����DestroyInstance�������ٶ���*/
	static u16 CreateSession(CCnsSessionCtrlIF **ppICnt);
	/*����	����ʵ���˽ӿ�CCnsSessionCtrlIF�Ķ���
	����	ppICnt	[in, out]�ӿ�CCnsSessionCtrlIF,�ɹ��󷵻�NULL
	����ֵ	�ɹ�����0,ʧ�ܷ��ط�0������
	˵��	ֻ��������CreateInstance���������Ķ���*/
	static u16 DestroySession(CCnsSessionCtrlIF **ppICnt);

};

#endif // !defined(AFX_CNCLIB_H__846EEC8C_FDB4_4222_A2A6_55EC0820D8B3__INCLUDED_)
