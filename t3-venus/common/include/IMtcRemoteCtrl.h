#ifndef __IMTCREMOTECTRL_H__
#define __IMTCREMOTECTRL_H__

#include "dispevent.h"
#include "key.h"

class IMtcRemoteCtrl : public CDispEvent
{
public:
	/*����	��ѯ�ն˵�ǰ�Ƿ����ң��������
	����	��
	����ֵ	TRUE	�ն˵�ǰ����ң��������
	FALSE	�ն˵�ǰ��ֹң��������
	˵��	��*/
	virtual BOOL IsEnableRemoteCtrl() const = 0;
	/*����	�����ն����û����ң����
	����	bEnable	�Ƿ�����ң����
	����ֵ	��
	˵��	��*/
	virtual u16 EnableRemoteCtrl(BOOL bEnable = TRUE) = 0;
    /*����	����ң�����������ܽӿ�
    ����	��
    ����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
    ˵��	PressDown	����
    ReleaseUp	����
    Click		���(���º��ٵ���)*/
    virtual u16 PressDown(u8 u8Key, u8 u8Type = SBLACK_REMOTE) = 0;	// ����
    virtual u16 ReleaseUp(u8 u8Key, u8 u8Type = SBLACK_REMOTE) = 0;	// ����
    virtual u16 Click(u8 u8Key, u8 u8Type = SBLACK_REMOTE) = 0;		// ���º���

}; // IRemoteCtrl

#endif