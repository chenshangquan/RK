#ifndef __IMTCCONF_H__
#define __IMTCCONF_H__

#include "dispevent.h"
//#include "mcustruct.h"		// Mcu���ͽṹ
#include "mtcmt.h"
#include "mtmisc.h"
#include <vector>
using std::vector;


typedef struct tagTerDumbStatus
{
public:
    TMtId   m_tMtId;
    BOOL32  m_bIsDumb;
}TerDumbStatus, *PTerDumbStatus;

typedef struct tagPollInfo
{
	s8 achSchemeName[ MT_MAX_NAME_LEN + 1 ];
	u32 dwIndex;
	TMtPollInfo tPollInfo;
	tagPollInfo() { memset(this, 0 , sizeof(tagPollInfo)); }
}TMtcPollInfo;


//�������ģʽ
typedef enum EmMixMode
{
	emNoMix = 0,
		emWholeMix,
		emPartMix,
		emVacMix,
		emVacWholeMix,
		emVacPartMix,
};


class IMtcConf : public CDispEvent
{
public:
	/*����	��ѯMcu�ϵ�ǰ�����ٿ��Ķ������б�
	����	terMcu	����ѯ�Ķ����Ƶ�Ԫ
	����ֵ	���Ļ����б�
	˵��	��*/
	virtual const TplArray<TConfBaseInfo>& GetConfs() const = 0;
	/*����	�Ƿ����ڵȴ�����������룩�����Ӧ
	����	��
	����ֵ	TRUE	���ڵȴ�����������룩�����Ӧ
		FALSE	û�����ڵȴ�����������룩�����Ӧ
	˵��	����ϯ�ն����Ƿ���һ���յ��б�*/
	virtual BOOL32 IsWaitingCreateAck() const = 0;
	virtual BOOL32 IsWaitingJoinAck() const = 0;
	/*����	�Ƿ����ڶ�������
	����	pConfInfo	���ز��������ڶ������У����ز���Ķ�������Ϣ�����Դ���NULL
	����ֵ	TRUE	�ڶ�������
			FALSE	���ڶ�������
	˵��	��*/
	virtual BOOL32 IsInConf(TMtConfInfo *pConfInfo = NULL) const = 0;
	/*����	�Ƿ�������ѯ
	����	��
	����ֵ	TRUE	������ѯ��
			FALSE	������ѯ��
	˵��	��*/
	virtual BOOL32 IsPolling() const = 0;
	/*����	�Ƿ���ѯ��ͣ��
	����	��
	����ֵ	TRUE	������ͣ
	˵��	FALSE	û����ͣ
	˵��	��*/
	virtual BOOL32 IsPollingPaused() const = 0;
	/*����	�Ƿ����Լ�����
	����	��
	����ֵ	TRUE	���Լ�����
	˵��	FALSE	û�����Լ���
	˵��	��*/
	virtual BOOL32 IsVAC() const = 0;
	/*����	��ѯ����ն��б�
	����	��
	����ֵ	�����ն��б�
	˵��	��*/
	virtual const vector<CMtcMt>& GetMts() const = 0;
	/*����	��ѯ�ն��Ƿ����ն�
	����	cMt	����ѯ���ն�
	����ֵ	TRUE	�Ƿ����ն�
			FALSE	�Ƿ����ն�
	˵��	��*/
	virtual BOOL32 IsSpeaker(const CMtcMt& cMt) const = 0;
	/*����	��ѯ�ն��Ƿ���ϯ�ն�
	����	cMt	����ѯ���ն�
	����ֵ	TRUE	����ϯ�ն�
			FALSE	����ϯ�ն�
	˵��	��*/
	virtual BOOL32 IsChairman(const CMtcMt& cMt) const = 0;
    /*����	��ѯ�ն��Ƿ�廰
    ����	 
    ����ֵ	TRUE	�廰
    FALSE	�ǲ廰
    ˵��	��*/
    virtual BOOL32 IsChime() const = 0;
		/*����	��ѯ��ǰ�Ļ�����Ϣ
	����	��
	����ֵ	��ǰ�ķ����ն�
	˵��	��*/
	virtual const TMtConfInfo& GetConfInfo() const = 0;
		/*����	��ѯָ��McuIdMtId���ն�
	����	byMcuId	�����Ƶ�Ԫ��ʶ
			byMtId	�ն˱�ʶ
	����ֵ	�����ѯ��,�����ն�ָ��,û�в�ѯ������NULL
	˵��	��*/
	virtual const CMtcMt* ConfGetMt(u8 byMcuId, u8 byMtId) const = 0;
	/*����	��ѯ��ǰ�ķ����ն�
	����	��
	����ֵ	��ǰ�ķ����ն�
	˵��	��*/
	virtual const CMtcMt& GetSpeaker() const = 0;
	/*����	��ѯ��ǰ����ϯ�ն�
	����	��
	����ֵ	��ǰ����ϯ�ն�
	˵��	��*/
	virtual const CMtcMt& GetChairman() const = 0;
	/*����	��ѯ��ǰ����ƵԴ
	����	��
	����ֵ	��ǰ����ƵԴ
	˵��	��*/
	virtual const CMtcMt& GetVideoSource() const = 0;
	/*����	��ѯ��ǰmcѡ���ն�
	����	��
	����ֵ	
	˵��	��*/
	virtual const CMtcMt& GetCurMCSelMT() const = 0;
	/*����	��ѯ��ǰ���뷢�Ե��ն�
	����	��
	����ֵ	��ǰ���뷢�Ե��ն��б�
	˵��	����ϯ�ն����Ƿ���һ���յ��б�*/
	virtual const vector<CMtcMt>& GetReqSpeakerMts() const = 0;
	/*����	��ѯ��ǰ������ϯ���ն�
	����	��
	����ֵ	��ǰ������ϯ���ն��б�
	˵��	����ϯ�ն����Ƿ���һ���յ��б�*/
	virtual const vector<CMtcMt>& GetReqChairmanMts() const = 0;
    /*����	��ѯ��ǰ����廰���ն�
	����	��
	����ֵ	��ǰ����廰���ն��б�
	˵��	����ϯ�ն����Ƿ���һ���յ��б�*/
	virtual const vector<CMtcMt>& GetReqChimeMts() const = 0;
	/*����	���»����б�
	����	terMcu	�ô�MCU�ϵĻ����б����
	����ֵ	�ɹ�����0;ʧ�ܷ��ش�����
	˵��	�����MTC_UI_CONFSLIST_UPDATED�����Ѹ���*/
	virtual u16 UpdateConfsList(const TMtAddr &tMcu, u16 wBitRate) = 0;
	/*����	����������
	����	conf	��ͼ����Ļ���
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	����һ���������вſ�������������*/
	virtual u16 JoinConf(const TConfBaseInfo& tConfBaseInfo) = 0;
	/*����	ȡ���������
	����	u128ConfId	Ҫ����Ļ����ʶ
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	������ͼ����һ�������вſ���ȡ������*/
	virtual u16 CancelJoinConf() = 0;
	/*����	���뷢��
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	�����Ƿ����նˣ������*/
	virtual u16 ReqSpeak() = 0;
	/*����	������ϯ
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��������ϯ�նˣ������*/
	virtual u16 ReqChairman() = 0;
    /*����	����廰
    ����	��
    ����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
    ˵��	�����ǲ廰�������*/
    virtual u16 ReqChime() = 0;
	/*����	��������
	����	dwMcuIp	Mcu IP ��ַ
			u16Bitrate ��������
			info	������Ϣ
			vMts	����ն��б�
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	�����Ƿ����նˣ���û��*/
	virtual u16 CreateConf(const TMtAddr &tMcu, const TConfBaseInfo &info, 
							const vector<TMtAddr>& vMts ) = 0;
	virtual u16 CreateConf(const TMtAddr &tMcu, u16 wBitrate,
                        const TConfBaseInfo &info, const vector<TMtAddr>& vMts) = 0;
    // �������к�������
    virtual u16 CreateSiteCall(const TSitecallInformation &tSiteCallInfo) = 0;
	/*����	����ն������˳�����
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	�����Ƿ����նˣ���û��*/
	virtual u16 QuitConf() = 0;
	/*����	��ѯ�ն�
	����	emType		��ѵ������ emMediaAV, emMediaVideo, emMediaAdieo
			byInterval	��ѵ�ļ��(ʱ���Ƿ���)
			vMts		��ѵ���ն��б�
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
	virtual u16 MtcConfStartPoll(EmMediaType emType, 
		u16 byInterval, const vector<CMtcMt>& vMts) = 0;
	/*����	������ѯ
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
	virtual u16 MtcConfEndPoll() = 0;
	/*����	��ͣ��ѯ
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
	virtual u16 PausePoll() = 0;
	/*����	�ָ���ѯ
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
	virtual u16 ResumePoll() = 0;
	/*����	��ѯ��ѯ����
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	�첽����*/
	virtual u16 ReqPollStatus() = 0;
	virtual EmMediaType GetPollType() = 0;
	virtual u16 GetPollInterval() = 0;
	virtual const vector<CMtcMt>& GetPollMts() = 0;
	/*����	������ն˷��Ͷ���Ϣ
	����	cMt	����������Ϣ���ն�
			strMsg	��Ϣ���ݣ����1024�ֽڣ�������β��'\0'
			byTimes	�ظ�����
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	�ɽӿ�,����ʹ��������½ӿ�*/
	virtual u16 SendShortMessage(const CMtcMt& cMt, const CString &strMsg,
		EmSMSType emType = emSMSSingleLine,	u8 byRollSpeed = 3,	u8 byTimes = 1) = 0;
	/*����	������ն˷��Ͷ���Ϣ
	����	msgex	CRollMsg���͵���Ϣ
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	�µķ��Ͷ���Ϣ�ӿ�,֧�ֹ�����Ϣ*/
	virtual u16 SendShortMessage(const CShortMsg &cSMS) = 0;
	/*����	�����ն�
	����	dwIP	�������ն�IP(������)
		    terMt	�������ն�
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	����ϯȨ��*/
	virtual u16 Invite(u32 dwIP) = 0;
    virtual u16 Invite(const TMtAddr &tMt) = 0;
	/*����	�����ն�
	����	cMt	�������ն�
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	����ϯȨ��*/
	virtual u16 MtcConfDropMt(const CMtcMt& cMt) = 0;
	/*����	ָ�������նˣ�����ϯ�նˡ��廰��
	����	cMt	�ն�
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	����ϯȨ��*/
	virtual u16 SpecifySpeaker(const CMtcMt& cMt) = 0;
    virtual u16 SpecifyChairman(const CMtcMt& cMt) = 0;
    virtual u16 SpecifyChime(const CMtcMt& mt) = 0;
	/*����	ȡ����ǰ�����ն˵ķ���Ȩ
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	����ϯȨ��*/
	virtual u16 RevokeSpeaker() = 0;
	/*����	ȡ����ǰ��ϯ�ն˵���ϯȨ
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	����ϯȨ��*/
	virtual u16 RevokeChairman() = 0;
	/*����	��׼����ܾ�����ᡢ���ԡ���Ϊ��ϯ���廰
	����	cMt	�ն�
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	����ϯȨ��*/
	virtual u16 AcceptSpeak(const CMtcMt& cMt) = 0;
	virtual u16 RefuseSpeak(const CMtcMt& cMt) = 0;
	virtual u16 AcceptChairman(const CMtcMt& cMt) = 0;
	virtual u16 RefuseChairman(const CMtcMt& cMt) = 0;
    virtual u16 AcceptChime(const CMtcMt& mt) = 0;
    virtual u16 RefuseChime(const CMtcMt& mt) = 0;
	/*����	Զ�˾���
	����	cMt	��������Զ���ն�
	bSilent	�Ƿ���
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	����ϯȨ��*/	
	virtual u16 Silence(const CMtcMt& cMt, BOOL bSilent = TRUE) = 0;
	/*����	Զ������
	����	cMt	��������Զ���ն�
	bSilent	�Ƿ�����
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	����ϯȨ��*/	
	virtual u16 Dumb(const CMtcMt& cMt, BOOL bDumb = TRUE) = 0;
	/*����	��������
	����	cMt	�ն�
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	����ϯȨ��*/
	virtual u16 EndConf() = 0;
	/*����	�㲥/ѡ���ն�
	����	cMt		�������ն�
			byMode	ѡ��ģʽMT_AUDIO:����Ƶ MT_VIDEO:����Ƶ MT_AV:��Ƶ����Ƶ
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	����ϯȨ��*/
	virtual u16 MtcConfViewMt(const CMtcMt& cMt, EmMediaType emType = emMediaVideo) = 0;
	virtual u16 StopViewMt() = 0;
	/*����	�����첽���ʱʱ��
	����	u32		�³�ʱʱ��(����)
	����ֵ	u32		�ɳ�ʱʱ��(����)
	˵��	���³�ʱʱ��Ϊ0xffffffff,�򲻸��³�ʱʱ��,�����س�ʱʱ��*/
	virtual u32 SetAsyncWaitTime(u32 dwTime) = 0;
	/*����	��ʼ/��������
	����	u32Max	���μ������ն���Ŀ
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
	virtual u16 StartDiscuss(u8 byMaxNum = 10) = 0;
	virtual u16 StopDiscuss() = 0;
	/*����	�����������
	����	strPwd	�������룬��󳤶�ΪMT_PWD_LEN
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	�ڽ��յ�MTC_UI_CONFPWDʱ���ô˽ӿ�*/
	virtual u16 InputConfPwd(const CString &strPwd) = 0;
	/*����	DTMF��������
	����	strPwd	DTMF���֣���󳤶�ΪMT_PWD_LEN
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	�û����ô˽ӿ�*/
	virtual u16 InputConfDTMF(const CString &strDTMF) = 0;
	/*����	��ʼ/ֹͣ����ն�
	����	cMt		������ն�
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
	virtual u16 StartMonMt(const CMtcMt &cMt) = 0;
	virtual u16 StopMonMt(const CMtcMt &cMt) = 0;
	/*����	��ʼ��Ƶ����
	����	tVmpParam		��Ƶ���ϲ���
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
	virtual u16 StartVMP(const TMtVMPParam &tVmpParam) = 0;
	virtual u16 StartVMP(const TMtVMPParam& tVmpParam, vector<TMtVmpItem> &vec) = 0;
	virtual u16 StopVMP() = 0;
	virtual u16 StopVMP(const TMtVMPParam& tVmpParam, vector<TMtVmpItem> &vec) = 0;
	/*����	������Ƶ���ϲ���
	����	tVmpParam		��Ƶ���ϲ���
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������*/
	virtual u16 UpdateVMP(const TMtVMPParam &tVmpParam) = 0;
	virtual u16 UpdateVMP(const TMtVMPParam &tVmpParam , vector<TMtVmpItem> &vec) = 0;
	/*����	������Ƶ���ϲ���
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	�ڽ��յ�֪ͨ��ϢMTC_UI_VMP�����GetVMP��ȡ��Ƶ���ϲ���*/
	virtual u16 ReqVMP() = 0;
//	virtual u16 ReqVMP(const TMtVMPParam &tVmpParam , vector<TMtVmpItem> &vec);
	/*����	��ȡ��Ƶ���ϲ���
	����	��
	����ֵ	��Ƶ���ϲ���
	˵��	��MTC_UI_VMP֮�����*/
	virtual const TMtVMPParam& GetVMP()const = 0;
	virtual const vector<TMtVmpItem> &GetVMPEX()const = 0;
	virtual BOOL IsInVMP() = 0;
	/*����	����/ֹͣ��������
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
	virtual u16 StartVAC() = 0;
	virtual u16 StopVAC() = 0;
		/*����	��Ƶ��ظ���
	˵��	����cMt�鶨��Ľӿ�EV_CONF_STARTMONITOR_RSP������ʹ��,����һ����Ƕ��
			�μ���ϢMTC_UI_MONMT*/
    
    //����ͬ���ṹ  
    typedef struct tagEncryptMT
    {
	    s32			  m_nSynchFlag;			         //shall be the Dynamic PayloadType for H.323
	    u8			  m_abyH235Key[64]; //H.235 encoded value(1-65535)
        s32           m_nH235KeyLen;
        
        tagEncryptMT()
	    {
		    Reset();
	    }

        void Reset()
	    {
		    m_nSynchFlag  = 0;
		    m_nH235KeyLen = 0;
	    }

        void host2net(BOOL bhton)
        {
            if (bhton)
            {
                m_nSynchFlag  = htonl(m_nSynchFlag);
                m_nH235KeyLen = htonl(m_nH235KeyLen);
            }
            else
            {
                m_nSynchFlag  = ntohl(m_nSynchFlag);
                m_nH235KeyLen = ntohl(m_nH235KeyLen);
            }
        }

        //��ȡH235Key�ĳ���
	    s32 GetH235KeyLen() 
	    {
		    return m_nH235KeyLen; 
	    }
        //��ȡH235Key
	    u8* GetH235Key()
	    {
		    return m_abyH235Key;
	    }
    }TEncrypt;

    
	class CAuxMonParam
	{
	public:
		u8	m_byMcuId;			// �����Ƶ�Ԫ��ʶ
		u8	m_byMtId;			// �ն˱�ʶ
		u32	m_dwIP;			    // IP��ַ, ������
		u16	m_wPortAudio;		// ��Ƶ�˿ں�, ������
		u16	m_wPortVideo;		// ��Ƶ�˿ں�, ������
		u8  m_byRealAudioPT;    // ��Ƶ��ʵ�غ�ֵ
        u8  m_byRealVideoPT;    // ��Ƶ��ʵ�غ�ֵ
        u8  m_byActiveAudioPT;  // ��Ƶ��̬�غ�ֵ
        u8  m_byActiveVideoPT;  // ��Ƶ��̬�غ�ֵ
        u8  m_byAudioEncType;   // ��Ƶ��������
        u8  m_byVideoEncType;   // ��Ƶ��������
        TEncryptKey m_tAudioEnc;// ��Ƶ��Կ
        TEncryptKey m_tVideoEnc;// ��Ƶ��Կ
	};
	/*����	�ӳ���������
	����	wMin	�ӳ����ٷ���
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	����ӳ����Ͽ�,�յ�MTC_UI_CMD_SUCCESS��Ϣ,��Ϣ��wParamΪEV_CONF_DELAY_REQ
			����ӳ�û�б��Ͽ�,�յ�MTC_UI_CMD_FAILED��Ϣ,��Ϣ��wParamΪEV_CONF_DELAY_REQ*/
	virtual u16 Delay(u16 wMin) = 0;
	/*����	���������ն˵�״̬
	����	cMt	����ѯ״̬���ն�
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	�ɹ����յ�MTC_UI_CONF_MTSTATUS��Ϣ	
			��û�յ�ҵ���ն˵�״̬����,����IDΪEV_CONF_MTSTATUS_REQ*/
	virtual u16 ReqStatus(const CMtcMt& cMt) = 0;
    /*�������� StartForceBroadcast
    ��    �ܣ� ��ʼ/ֹͣǿ�Ʋ��ŷ����˵�����
    ��    ���� 
    �� �� ֵ�� virtual u16 �ɹ�����0;ʧ�ܷ��ط�0������
    ˵    ���� */
	virtual u16 StartForceBroadcast() = 0;
	virtual u16 StopForceBroadcast() = 0;
	
    /*�������� ConfIsEncrypte
    ��    �ܣ� �����Ƿ����
    ��    ���� 
    �� �� ֵ�� virtual BOOL32 
    ˵    ���� */
	virtual BOOL32 ConfIsEncrypte() = 0;

    // mc ��ز���
    // ��Ե������չ
    virtual u16 P2PConfExtend(const TDialParam &tDialParam) = 0;
    //mcʱ�����滻���渴���ն�
    virtual u16 McVMPReplaceMt(u8 byIndex, const TMtId &tMtId) = 0;
    // mcԶң�ն�
    virtual u16 McFeccTerm(const TMtId& tMtId) = 0;
    // ����mc����ģʽ����
    virtual u16 McModeCfg(BOOL bEnable, EmMCMode emMcMode) = 0;
    // ���û���ϳ��Զ�����/���߹̶�
    virtual u16 McVMPCfg(BOOL bAuto) = 0;
    // ����vmp�ķ��
    virtual u16 McSetVMPStyle(EmInnerVMPStyle emVMPStyle, const TMtId *tMtId) = 0;
	// MC�ն�ѡ��
	virtual u16 MCConfViewMt(BOOL byIsView, const CMtcMt& cMt) = 0;
	virtual BOOL IsInSel() = 0;
    // mc�ն���ѯ�㲥
    virtual u16 McPollStart(EmMediaType emType, u16 wInterval, const vector<CMtcMt>& vMts) = 0;
    virtual u16 McPollStop() = 0;


	
	//���� ��ϯѡ���ն˵Ļ���ϳ� 
	virtual u16 ConfmtSelectVmpReq(BOOL view) = 0;
	virtual BOOL IsSelectedVmp() = 0;
	// mc��ϯ��ѯ
    virtual u16 McChairmanPollStart(EmMediaType emType, u16 wInterval, const vector<CMtcMt>& vMts) = 0;
    virtual u16 McChairmanPollStop()  = 0;
	virtual EmAction GetMCChairmanPollState() = 0;
	virtual EmAction GetMCPollState() = 0;
    // mc���պ���
    virtual u16 McAccept(const TMtId &tMtId, BOOL32 bAccept) = 0;
    // MC�Ƿ񼤻�
    virtual BOOL32 IsMcActive() const = 0;
    // ��ȡ��ǰMCģʽ
    virtual EmMCMode GetMcMode() const = 0;
    // �ж�MC�ڵ�ǰ�������Ƿ����
    virtual BOOL32 IsMcEnableInCurConf() const = 0;
    // ��ȡMC��ѯʱ����Ϣ
    virtual const TMtPollInfo& GetMcPollInfo() const = 0;
    // ��ȡMC����ϳɷ��
    virtual EmInnerVMPStyle GetMcVMPStyle() const = 0;
    // MC�Ƿ��Զ�����ϳ�
    virtual BOOL32 IsMcAutoVMP() const = 0;
    // ��ȡMC����ϳɳ�Ա
    virtual const TMtId* GetMcVMPMember() const = 0;
    // ��ȡMC�����ն˳�Ա
    virtual const TerDumbStatus* GetMcDumbTer() const = 0;
    // ��ȡԶң�ն�
    virtual const TMtId& GetMcFeccTerm() const = 0;


	//����������ѯ����
	virtual u16 UpdateAllPollSchemes(vector<TMtcPollInfo> &vec) = 0;
	//���������ѯ����
	virtual const vector<TMtcPollInfo>& GetAllPollSchemes()const = 0;
	//���õ�ǰ��ѯ����
	virtual u16 UpdateOnePollScheme(u8 Index , s8* achName , EmMediaType emType, u16 wInterval, const vector<CMtcMt>& vMts) = 0;
	//��õ�ǰ��ѯ����
	virtual const TMtcPollInfo& GetOnePollScheme() = 0;


	//���ƻ���
	virtual BOOL IsInSelMtsMixAudio() = 0;
	virtual u16 StartSelMtsMixAudio(TMtMixParam &tMixParam) = 0;
	virtual u16 StopSelMtsMixAudio() = 0;
	virtual u16 AddSelMtsMixAudio(TMtMixParam &tMixParam) = 0;
	virtual u16 RemoveSelMtsMixAudio(TMtMixParam &tMixParam) = 0;
	virtual const TMtMixParam& GetMtsInSelMixAudio() const = 0;
	 
	virtual EmMixMode GetMixMode() = 0;
}; // IMtcConf

#endif