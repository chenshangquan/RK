#ifndef __IMTCRECODER_H__
#define __IMTCRECODER_H__

#include "dispevent.h"

#include "RPCtrl.h"
#include "CodecLib.h"
#include "channelinfo.h"
#include "vccommon.h"

class IMtcRecoder : public CDispEvent
{
public:
	//����¼��
	virtual DWORD ResumeRec() = 0;
	
	//��ͣ¼��
	virtual DWORD PauseRec() = 0;
	
	//�Ƿ���ͣ¼��
	virtual BOOL IsPause() = 0;
	
	//�Ƿ�����¼��
	virtual BOOL IsRunning() = 0;
	//   ����¼��Ƶ����Ϣ
	virtual void SetRecChannelInfo(TChannelEncrypt  tChannelInfo) = 0;
    
	//��ʼ��¼���
    ///virtual static BOOL InitRec(const DWORD dwRecCount) = 0;
	virtual BOOL InitRec(const DWORD dwRecCount) = 0;
	
	//�����ļ�����·��
    virtual BOOL SetRecPath(const CString &strPath) = 0;
	
	//��������ת������
    virtual BOOL SetTransferDecoder(CKdvDecoder *pcDecoder, DWORD dwDestIP, WORD wDestPort, u8 byActivePt=0) = 0;
	
	//��ʼ¼��
    virtual WORD StartRec() = 0;
    
	//ֹͣ¼��
    virtual BOOL StopRec() = 0;
    
	//�˳����ͷ�¼�����
    ///virtual static  BOOL QuitRec() = 0;
	virtual BOOL QuitRec() = 0;
    
	// �Ƿ��Ѿ���ʼ��
    ///virtual static BOOL IsInited() = 0;    
	virtual BOOL IsInited() = 0;    
	
	//�Ƿ���¼�������
    virtual BOOL IsRecording() = 0;    
}; // IMtcRecoder

#endif
