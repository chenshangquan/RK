#ifndef __IMTCMONITOR_H__
#define __IMTCMONITOR_H__

#include "dispevent.h"

typedef struct tagAudAACParam
{
	u32 dwSamplePerSecond;
	u32 dwChannel;
}TAudAACParam;

typedef struct tagMonitorParam
{
	u8 abyRealType[2];			         //��һ·��Ƶ����Ƶ���غ�����
	u8 abyDynamicPayLoad[2];			//��һ·��Ƶ����Ƶ�Ķ�̬�غ�����
	TEncryptKey  atEncryptKey[2];		//��һ·��Ƶ����Ƶ����Կ
	EmSite emSite;
public:
	tagMonitorParam()
	{
		memset(this, 0 ,sizeof(struct tagMonitorParam));
	}
}TMtcMonitorParam;

typedef struct tagMTCPUMemStatus
{
	u8	byCupRate;				//CPUʹ�õİٷֱ�
	u32	dwMTTotalMem;			//MT�ܵ��ڴ���Ŀ
	u32 dwUsedMem;				//ʹ�õ��ڴ��С
	u32	dwFreeMem;				//�ɹ�������ڴ�Ĵ�С
	public:
		tagMTCPUMemStatus()
		{
			memset(this, 0, sizeof(tagMTCPUMemStatus));
		}
}TMTCPUMemStatus, *PTMTCPUMemStatus;

typedef struct tagResSolution
{
	tagResSolution(){ memset( this, 0 ,sizeof( tagResSolution ) ); }
	u32 dwPriSendVidRes;
	u32 dwSecSendVidRes;
	u32 dwPriRecvVidRes;
	u32 dwSecRecvVidRes;
}TResolution, *PTResolution;

typedef struct tagDIP
{
	tagDIP(){ memset( this, 0 ,sizeof( tagDIP ) ); }
	u32 dwDIPWidth;
	u32 dwDIPHeight;
}TDIP, *PTDIP;

typedef struct tagVideoFrameRate
{
	tagVideoFrameRate(){ memset( this, 0 ,sizeof( tagVideoFrameRate ) ); }
	u32 dwPriSendVidFrmRate;
	u32 dwSecSendVidFrmRate;
	u32 dwPriRecvVidFrmRate;
	u32 dwSecRecvVidFrmRate;
}TVidFrameRate, *PTVidFrameRate;

class IMtcMonitor : public CDispEvent
{
public:
	/*�������� GetVideoParam
    ��    �ܣ� ��ȡ���ʱ����Ƶ������������̬�غɣ���Կ�ȣ�
    ��    ���� 
    �� �� ֵ�� TMtcMonitorParam  MTC�ļ�ز���
    ˵    ���� */
	virtual const TMtcMonitorParam& GetVideoParam() = 0;
    /*�������� IsInDual
    ��    �ܣ� �Ƿ���˫���У���������˫��
    ��    ���� 
    �� �� ֵ�� virtual BOOL32 
    ˵    ���� */
    virtual BOOL32 IsInDual() = 0;

    /*=============================================================================
    �� �� ��:IsRcvDual
    ��    ��:��ǰ�ն��Ƿ����˫��
    ��    ��:��
    ע    ��:��
    �� �� ֵ:����˫����: TRUE; û�н���˫��: FALSE
    -------------------------------------------------------------------------------
    �޸ļ�¼:
    ��      ��  �汾    �޸���  �޸�����
    2006/04/26  4.0     ���    ����
    =============================================================================*/
    virtual BOOL32 IsRcvDual(void) const = 0;

	//�Ƿ��ڷ���pc˫��
	virtual BOOL32 IsInPCDual() = 0;

	/*�������� StartDual
    ��    �ܣ� ��ʼ/ֹͣ����˫��
    ��    ���� EmMtVideoPort emVPort   ����˫���Ķ˿ڣ�C1 - C6��VGA��S-Video��
			   BOOL32 bStart           True  ��ʼ/  False  ֹͣ
    �� �� ֵ�� virtual BOOL32 
    ˵    ���� */
	virtual u16 StartDual(EmMtVideoPort emVPort, BOOL32 bStart) = 0;

    /*�������� StartPCDual
    ��    �ܣ� ��ʼ/ֹͣPC˫��	
    ��    ���� BOOL32 bStart	TRUE��ʼ/False ֹͣ
               TIPTransAddr& tLocalIPAddr  ����RTCP�ش���ַ
    �� �� ֵ�� virtual u16 
    ˵    ���� */
	virtual u16 StartPCDual(BOOL32 bStart, TIPTransAddr& tLocalIPAddr) = 0;
    /*�������� GetPCEncodeParam
    ��    �ܣ� 
    ��    ���� ��ȡPC˫���ı������
    �� �� ֵ�� virtual TVideoEncodeParameter 
    ˵    ���� */
	virtual TVideoEncodeParameter GetPCEncodeParam() = 0;
	
    /*�������� GetPCEncodeEncrypeKey
    ��    �ܣ� 
    ��    ���� ��ȡPC˫���������Կ
    �� �� ֵ�� virtual TEncryptKey 
    ˵    ���� */
	virtual TEncryptKey GetPCEncodeEncrypeKey() = 0;

    /*�������� GetPCEncodePayload
    ��    �ܣ� ��ȡPC˫������Ķ�̬�غ�ֵ
    ��    ���� 
    �� �� ֵ�� virtual u8 ��̬�غ� 
    ˵    ���� */
	virtual u8 GetPCEncodePayload() = 0;

    /*�������� GetPCSendAddr
    ��    �ܣ� ��ȡPC˫����Զ�˵�ַ
    ��    ���� TIPTransAddr& tRTPAddr	Զ��RTP��ַ
               TIPTransAddr& tRTCPAddr	Զ��RTCP��ַ
    �� �� ֵ�� virtual void 
    ˵    ���� */
	virtual void GetPCSendAddr(TIPTransAddr& tRTPAddr, TIPTransAddr& tRTCPAddr) = 0;

    /*����	��ȡ��ǰ˫��Ƶ��������
	����	��
	����ֵ	u16 u16Type ����  --0��ʾ��Ч
	˵��	��*/
	virtual EmMtVideoPort GetDualType() = 0;
	/*����	��ʼ���ͱ���/Զ��ý����
	����	EmSite emSite	  ����/Զ��
	        const TIPTransAddr& tIpAddr		��Ƶ�����͵�IP��ַ�Ͷ˿�
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
	virtual u16 StartMonitor(EmSite emSite, const TIPTransAddr& tIpAddr) = 0;
	/*����	����ǰ���Դ�Ĺؼ�֡
	����	��
	����ֵ	EmSite emSite   ���ػ���Զ��
	˵��	��*/
	virtual u16 ReqMonitorKeyFrame(EmSite emSite) = 0;
	/*����	ֹͣ���ͱ���/Զ��ý����
	����	EmSite emSite	  ����/Զ��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
	virtual u16 StopMonitor(EmSite emSite) = 0;
	/*����	�Ի�����
	����	BOOL32 bStart      ��ʼ/ֹͣ
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	�Ժ���յ�֪ͨ��ϢMTC_UI_CIRCLETEST*/
	virtual u16 SelfTest(BOOL32 bStart) = 0;
	/*����	�����������ϱ�֪ͨ
	����	byCodecId	��������ʶ
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
//	virtual u16 CodecPackedLost(u8 byCodecId) = 0;
    /*����	ͼ�����
	����	EmSite emSite			����/Զ��
	        BOOL32 bStart			��ʼ/ֹͣ
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��    ��*/
	virtual u16 ImageTest(EmSite emSite, BOOL32 bStart) = 0;
	/*����	����/ֹͣ��������Ϣ
	����	u8 byEnable ��ʼ/ֹͣ MT_ENABLE/MT_DISABLE
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	����ɹ���,���յ�MTC_UI_CODECSTATUS_UPDATED֪ͨ*/
	virtual u16 ReqCodecStatus() = 0;
    /*����	��ȡ��������Ϣ
	����	��
	����ֵ	������Ϣ
	˵��	�յ�MTC_UI_CODECSTATUS_UPDATED��Ϣ���ô˷���������Ϣ*/
	virtual const TCallInfoStatistics& GetCodecStatus()const = 0;
	/*����	��ʼ/ֹͣ��������
	����	
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	����ɹ���,���յ�MTC_UI_AUDIOPOWER_UPDATED֪ͨ*/
	virtual u16 ReqAudioPower() = 0;
    /*����	�Ƿ����Ի�,���ء�Զ��ͼ�����,��������
	����	��
	����ֵ	�Ի���TURE 
	˵��	*/
	virtual BOOL32 IsInnerLoop() = 0;
    virtual BOOL32 IsLocalImageTest() = 0;
    virtual BOOL32 IsRemoteImageTest() = 0;
    virtual BOOL32 IsVolumeImageTest() = 0;
    /*����	���л��л�����
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������ 
	˵��	*/
	virtual u16 SwitchPIP() = 0;
    /*����	���л�λ�õ�������
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������ 
	˵��	*/
    virtual u16 MovePIP() = 0;
    /*����	�����ϱ�
    ����	��
    ����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
    ˵��	�����ն���ҵ����ϱ���������*/
//    virtual u16 ReportBitRate(_TBITRATE &tBitRate) = 0;

    /*�������� ReqCpuMemStatus
    ��    �ܣ� ����cpu �� mem��״̬
    ��    ���� 
    �� �� ֵ�� 
    ˵    ���� */
	virtual u16	ReqCpuMemStatus() = 0;
    /*�������� TMTCPUMemStatus& GetCPUMemStatus
    ��    �ܣ� ��ȡcpu �� mem ��״̬
    ��    ���� 
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const TMTCPUMemStatus& GetCPUMemStatus() = 0;

	/*�������� ReqMonitorIKey
    ��    �ܣ� �����عؼ�֡
    ��    ���� EmSite emSite   ����/Զ��
    �� �� ֵ�� virtual void 
    ˵    ���� */
	virtual void ReqMonIKey(u8 byLocal) = 0;
    /*�������� GetDualVidCap
    ��    �ܣ� 
    ��    ���� EmVideoType emType
    �� �� ֵ�� virtual EmMtVideoPort* 
    ˵    ���� */
	virtual EmMtVideoPort* GetDualVidCap( EmVideoType emType ) = 0;
    
    /*�������� MTCEncStatisAck
    ��    �ܣ� mtc����ͳ����Ϣ����
    ��    ���� const TCodecPackStat& tCodecPackStat
    �� �� ֵ�� virtual u16 
    ˵    ���� */
	virtual u16 MTCEncStatisAck( const TCodecPackStat& tCodecPackStat ) = 0;

    /*�������� IsRemoteLoopBackTest
    ��    �ܣ� �Ƿ����ڽ���Զ�˻��ز���
    ��    ���� 
    �� �� ֵ�� BOOL32 
    ˵    ���� */
    virtual BOOL32 IsRemoteLoopBackTest() = 0;

    /*�������� RemoteLoopBackTest
    ��    �ܣ� Զ�˻��ز���
    ��    ���� EmVideoType emVideoType, BOOL32 bStart
    �� �� ֵ�� u16 
    ˵    ���� */
    virtual u16 RemoteLoopBackTest(EmVideoType emVideoType, BOOL32 bStart) = 0;
	/*�������� RemoteLoopBackTest
    ��    �ܣ� Զ�˻��ز���
    ��    ���� EmVideoType emVideoType, BOOL32 bStart
    �� �� ֵ�� u16 
    ˵    ���� */
    virtual u16 SpeakerTest() = 0;
	/*�������� SendMtcResToMt
    ��    �ܣ� ˫��ǰ���͸��ն˵�ǰ�ֱ���
    ��    ���� u32 byflag
    �� �� ֵ�� u16 
    ˵    ���� */
	virtual u16 SendMtcResToMt(u32 byflag) = 0;

	//��ȡ����AAC����
	virtual const TAudAACParam& GetLocalAACParam() = 0;
	//��ȡԶ��AAC����
	virtual const TAudAACParam& GetRemoteAACParam() = 0;
	//��������ֱ���
	virtual TDIP* GetRealRes() = 0;
	//�����Ƶ����
	virtual TVidFrameRate* GetVideoFrameRate() = 0;
}; // IMtcMonitor


#endif