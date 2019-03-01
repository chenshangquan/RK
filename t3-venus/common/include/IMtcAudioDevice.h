#ifndef __IMTCAUDIODEVICE_H__
#define __IMTCAUDIODEVICE_H__

#include "dispevent.h"

class IMtcAudioDevice : public CDispEvent
{
public:
	/*����	��ѯ�Ƿ���
	����	��
	����ֵ	TRUE	������
			FALSE	�Ǿ���
	˵��	�ն��Ƿ������Ƶ�ź�*/
	virtual BOOL IsLocalSpeakerMute() const = 0;
	/*����	��ѯ�Ƿ�����
	����	��
	����ֵ	TRUE	������
			FALSE	������
	˵��	�ն��Ƿ񱻽�����Ƶ�źŵ�����*/
	virtual BOOL IsLocalMicMute() const = 0;
	/*����	��ѯ�ն�����������룩����
	����	��
	����ֵ	������С������0~25֮��
	˵��	��*/
	virtual u8 GetLocalSpeakerVolume() const = 0;
	virtual u8 GetLocalMicVolume() const = 0;
	/*����	�����ն�����������룩����
	����	dwVolume	������С������0~25֮��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
    virtual u16 AdjustLocalSpeakerVolume(u8 byVolume) = 0;
    virtual u16 AdjustLocalMicVolume(u8 byVolume) = 0;
	/*����	����(��ȡ��)����
	����	bMute	�Ƿ����þ���
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
	virtual u16 MuteLocalSpeaker(BOOL bMute = TRUE) = 0;
	virtual u16 MuteLocalMic(BOOL bMute = TRUE) = 0;

	/*����	ת��
	����	��
	����ֵ	��
	˵��	��*/
	virtual void Dump() = 0;
}; // IMtcAudioDevice


#endif