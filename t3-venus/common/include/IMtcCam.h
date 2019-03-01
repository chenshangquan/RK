#ifndef __IMTCCAM_H__
#define __IMTCCAM_H__

#include "dispevent.h"
#include "vector"

using namespace std;

class IMtcCam : public CDispEvent
{
public:
    /*�������� GetCamSource
    ��    �ܣ� �õ���ǰ����ƵԴ(Զ�ˣ�����)
    ��    ���� 
    �� �� ֵ�� virtual u16& 
    ˵    ���� */
	virtual u16 GetCamSource() = 0;

    /*�������� GetVSource
    ��    �ܣ� ��ȡ��ǰ����ƵԴ��c1 -- c6 , vga ,s��
    ��    ���� 
    �� �� ֵ�� virtual EmMtVideoPort& 
    ˵    ���� */
	virtual EmMtVideoPort& GetVSource() = 0;
    /*�������� GetVSource
    ��    �ܣ� ��ȡ��ǰ����ƵԴ
    ��    ���� 
    �� �� ֵ�� virtual EmMtVideoPort& 
    ˵    ���� */
	virtual EmMtVideoPort& GetVSecSource() = 0;

	/*����	��������ͷ��̨���ϡ����¡����������˶�
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
	virtual u16 CameraTurnUp() = 0;
	virtual u16 CameraTurnUpStop() = 0;
	virtual u16 CameraTurnDown() = 0;
	virtual u16 CameraTurnDownStop() = 0;
	virtual u16 CameraTurnLeft() = 0;
	virtual u16 CameraTurnLeftStop() = 0;
	virtual u16 CameraTurnRight() = 0;
	virtual u16 CameraTurnRightStop() = 0;
	/*����	�Զ���������ͷ�Ľ���
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/	
	virtual u16 CameraAdjustFocusAuto() = 0;
	/*����	�ֶ��������Զ����ͷ�Ľ���
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
	virtual u16 CameraAdjustFocus2Near() = 0;
	virtual u16 CameraAdjustFocus2NearStop() = 0;
	virtual u16 CameraAdjustFocus2Far() = 0;
	virtual u16 CameraAdjustFocus2FarStop() = 0;
	/*����	���ӣ����С������ͷ������
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/	
	virtual u16 CameraIncLum() = 0;
	virtual u16 CameraIncLumStop() = 0;
	virtual u16 CameraDecLum() = 0;
	virtual u16 CameraDecLumStop() = 0;
	/*����	�Ŵ����С����ͷ����Ұ
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/	
	virtual u16 CameraZoomIn() = 0;
	virtual u16 CameraZoomInStop() = 0;
	virtual u16 CameraZoomOut() = 0;
	virtual u16 CameraZoomOutStop() = 0;
	/*����	���أ��򱣴棩����ͷ��״̬
	����	dwPos	����λ����������Ч��Χ(0~3)
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/	
	virtual u16 CameraLoadStatus(u8 byPos) = 0;
	virtual u16 CameraSaveStatus(u8 byPos) = 0;
	/*����	ѡ����ƵԴ
	����	EmMtVideoPort emPort
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/	
	virtual u16 SelectCamera( EmMtVideoPort emPort , EmVideoType emType = emPriomVideo) = 0;
	/*����	����Զ������ͷ�л�
	����	bLocal �Ƿ��л�����������ͷ
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
	virtual u16 SwitchSourceCam(EmSite emSite) = 0;
	
	virtual const vector<TVideoSourceInfo>& GetVSourceInfo() = 0;

	virtual u16 UpdateVSourceInfo( const TVideoSourceInfo& tVSourceInfo ) = 0;

	virtual u16 SetAutoDualSrc() = 0;
	virtual BYTE& GetAutoDualSrc() = 0;
}; // IMtcCam

#endif