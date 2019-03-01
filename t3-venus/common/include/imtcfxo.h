// imtcfxo.h: interface for the IMtcFxo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMTCFXO_H__CB4EE46F_7D3F_4953_8689_1B571C0F6B67__INCLUDED_)
#define AFX_IMTCFXO_H__CB4EE46F_7D3F_4953_8689_1B571C0F6B67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "dispevent.h"
#include "mtcmt.h"
class IMtcFxo : public CDispEvent  
{
public:
	public:
	/*����	��绰
	����	const char *pchFxoNo [in]   �Է�����
	        const u16 wFxoNoLen  [in]   ���볤��
	����ֵ	�ɹ�����0
	˵��	��*/
	virtual u16 MakeCall(const TMtAddr &tMtAddr,const char *pchFxoNo,const u16 wFxoNoLen) = 0;
	/*����	�Ҷϵ绰
	����	
	����ֵ	�ɹ�����0
	˵��	��*/
	virtual u16 Hangup() = 0;
	/*����	���ܵ绰
	����	
	����ֵ	�ɹ�����0
	˵��	��*/
	virtual u16 Accept() = 0;
	/*����	�Ƿ����ں���
	����	
	����ֵ	TRUE	���ں���
			FALSE	û�ں���
	˵��	��*/
	virtual BOOL32 IsCalling()  = 0;
	/*����	�Ƿ�������״̬
	����	
	����ֵ	TRUE	��������
			FALSE	����������
	˵��	��*/
	virtual BOOL32 IsConnect()  = 0;
	/*����	�Ƿ��ڿ���״̬
	����	
	����ֵ	TRUE	�ڿ�����
			FALSE	���ڿ�����
	˵��	��*/
	virtual BOOL32 IsIdle()  = 0;
	/*����	�ܾ�����
	����	
	����ֵ	TRUE	�ɹ�
			FALSE	ʧ��
	˵��	��*/
	virtual u16 Reject() = 0;

};

#endif // !defined(AFX_IMTCFXO_H__CB4EE46F_7D3F_4953_8689_1B571C0F6B67__INCLUDED_)
