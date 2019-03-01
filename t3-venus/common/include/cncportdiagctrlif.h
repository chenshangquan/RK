#ifndef _CNCPORTDIAGNOSISIF_H_
#define _CNCPORTDIAGNOSISIF_H_

#include "kdvdispevent.h"

class CCncPortDiagCtrlIF : public CKdvDispEvent
{
public:	
	//��ȡ����汾��Ϣ
	virtual s8* GetSoftVersionInfo() = 0;
	virtual EmCnModel GetEmCnModelInfo() = 0;
	//��Ƶ�ӿ���Ϣ
	virtual TTpAudioPortInfo* GetAudioPortInfo() = 0;							
	virtual	u16 SetAudioPortInfoCmd( const TTpAudioPortInfo** atAudioPortInfo ) = 0;
	virtual u16 SetMic10InfoCmd( const TTpMic10Info &tTPMic10Info ) = 0;
	virtual u16 SetNoDeskAudioCmd( bool bNoDeskAudio ) = 0;
	virtual	u16 DefaultAudioPortCmd( const TTpAudioPortInfo** atAudioPortInfo ) = 0;
	
	//���綪����Ϣ
	virtual u16 LostPacketInfoReq() = 0;
	virtual const CString& GetLostPacketInfo()const = 0;			
	
	//�ϴ���������
	virtual const TTPUpDownSpeedInfo& GetUpDownstreamRate()const = 0;
	
	//ץ��
	virtual u16 SetCaptureStateCmd( const BOOL& bCapture ) const = 0;
	
	//ѡ������Ƶ���󷽰�������
	virtual u16 SelAVMatrixCmd( const TTPVgaMixInfo& tVgaMixInfo ) = 0;
	//��ȡ�˿���Ͻ��
	virtual const TTPVideoDiagInfo& GetVideoDiagInfo()const = 0;
	virtual const TTPAudioDiagInfo& GetAudioDiagInfo()const = 0;

	//��ȡ���簲ȫFTP��TELNET��Ϣ
	virtual const TTPFtpInfo& GetFtpInfo()const = 0;
	virtual const TTPTelnetInfo& GetTelnetInfo()const = 0;
	
	//ֹͣ��ϲ�������
	virtual u16 StopAVMatrixReq() = 0;
	
	//Tpad�б�
	virtual	const TTPTPadList& GetTpadList()const = 0;								
	virtual	u16 UpdateTpadListReq() = 0;	

	//����Cns
	virtual u16 RebootCns() = 0;
	
	//����T300
	virtual u16 UpgradeCns( const TTPFTPFileInfo& tVerFileInfo ) = 0;
	
	//ά������ˢ�½�������
	virtual u16 ReqRefresh() = 0;
	
	//��Ƶ��������������
	virtual u16 AudiotMixerCmd( const u8** aAudioMixerInfo ) = 0;
	virtual u8* GetAudioMixerInfo() = 0;
	virtual u16 DefaultMixerCmd( const u8** aAudioMixerInfo ) = 0;
	
	//��Ƶ��������������
	virtual u16 AudioEqualizerCmd( const TTPEqualizer** atEqualizer ) = 0;
	virtual TTPEqualizer* GetAudioEqualizer() = 0;
	virtual u16 DefaultEqCmd( const TTPEqualizer** atEqualizer ) = 0;
	
	//���з�������ַ
	virtual u16 CallServerCmd( const TTPCallSerInfo& tCallSerInfo ) = 0;
	virtual const TTPCallSerInfo& GetCallServerInfo()const = 0;

	//������������ַ
	virtual u16 UpgradeSerCmd( const TTPUpgradeSer& tUpgradeSer ) = 0;

	//�������ݻ����������ַ
	virtual u16 SetDataConfSerCmd( const TTPDataConfInfo& tWBSerIp ) = 0;

	virtual u16 SetMatrixSerCmd( const TTPMatrixServerInfo& tTPMatrixServerInfo) = 0;

	virtual u16 SetNtpSerCmd( const TTPNtpSer& tTpNtpSer) = 0;

	virtual u16 SetQtEncryptSerCmd( const TTpQtEncryptCfg& tTpQtEncryptCfg) = 0;

	virtual const TTPUpgradeSer& GetUpgradeSerInfo()const = 0;

    //�װ��������ַ
    virtual const TTPDataConfInfo& GetWBSerIp()const = 0;

	virtual const TTpQtEncryptCfg& GetQtEncryptCfg() const = 0;

	virtual const TTPNtpSer& GetNtpSerIP() const = 0;

	virtual const TTPMatrixServerInfo& GetMatrixSerInfo() const = 0;
	
	//̨���ļ��ϴ��ɹ�֪ͨ
	virtual u16 ConfSignCmd( const BOOL& bOk, u8 byIndex ) = 0;
	
	//������ѡ��ʽ
	virtual u16 VideoFormatCmd( const TTPVidForamt& tVidForamt ) = 0;
	virtual const TTPVidForamt& GetVideoFormatInfo()const = 0;
	
	//��ʾ��ѡ��ʽ
	virtual u16 DualVideoFormatCmd( const TTPVidForamt& tVidForamt ) = 0;
	virtual const TTPVidForamt& GetDualVideoFormatInfo()const = 0;
	
	//��������
	virtual u16 CallRateCmd( const u16 wCallRate ) = 0;
	virtual const u16 GetCallRate()const = 0;
	
	//��ʾ����
	virtual u16 DualCallRateCmd( const u16 wDualCallRate ) = 0;
	virtual const u16 GetDualCallRate()const = 0;
	
	//������ѯ
	virtual u16 ConfPollCmd( const TTPPollInfo& tPollInfo ) = 0;
	virtual const TTPPollInfo& GetConfPollInfo()const = 0;
	
	//��������
	virtual u16 ConfDisCmd( const BOOL& bDis ) = 0;
	virtual const BOOL& GetConfDisInfo()const = 0;
	
	//��Ƶ��ʽ
	virtual u16 AudioFormatCmd( const EmTpAudioFormat& emAudioFormat ) = 0;
	virtual const EmTpAudioFormat& GetAudioFormatInfo() const = 0;

	//��Ƶ���ýӿ�
	virtual const TTPMPAudioInfo& GetAudioInfo() const= 0;

	virtual	u16 DefaultAudioSetCmd( const TTPMPAudioInfo* atAudioPortInfo ) = 0;

	virtual u16 DefaultListenPortSetCmd(const EmAudMixType emAudMixtype, const u8 byAudMixVolume) = 0;

	virtual u16 DefaultAux2OutSetCmd( const EmAudExtend emAudExtend, const u8 byAudExtendVolume) = 0;

	virtual u16 SetAudioInfoCmd( const TTPMPAudioInfo* atAudioPortInfo ) = 0 ;

	virtual u16 SetListenPortCmd( const EmAudMixType emAudMixtype, const u8 byAudMixVolume ) = 0;

	virtual u16 SetAux2OutCmd( const EmAudExtend emAudExtend, const u8 byAudExtendVolume) = 0;

	virtual u16 SetAudioWhiteNoiseCmd(BOOL bIsOpen ,u32 dwWhiteNoisePort) = 0 ;

	virtual BOOL *GetWhiteNoiseInfo() = 0;

	//����Ƶ���ýӿ�
	virtual const TTPVideoInfoTool &GetMainAudioInfo( ) const= 0 ;

	virtual u16 DefaultMainAudioCmd( const TTPVideoInfoTool* ptAudioInfo ) = 0 ;

	virtual u16 SetMainAudioInfoCmd( const TTPVideoInfoTool* ptAudioInfo ) = 0 ;

	virtual	u16 SnapShotCmd( ) =0;

	//��ʾԴ���ýӿ�
	virtual	u16 SetDefaultDemonStrationCmd( const TVgaInfo *ptDisplaySource,
		const TTPDualDisplayStrategy *ptDualDisplayStrategy,
		const EmVgaType emDefaultDisplay ) = 0;

	virtual	u16 SetDemonStrationCmd( const TVgaInfo *ptDisplaySource,
		const TTPDualDisplayStrategy *ptDualDisplayStrategy,
		const EmVgaType emDefaultDisplay ) = 0;

	virtual TVgaInfo *GetDisplaySourceInfo( ) = 0 ;
	
	virtual TTPDualDisplayStrategy &GetDisplayStrategyInfo( ) = 0 ;
	
	virtual EmVgaType GetDefaultDisplay( ) = 0 ;

	//ͼ���������
	virtual	u16 SetDefParameterCmd(const TTPImageAdjustParam * pImageAdjustParam ) =0;

	virtual TTPImageAdjustParam *GetImageParam() = 0;

	virtual	u16 SetParameterCmd(const TTPImageAdjustParam * pImageAdjustParam ) =0;

	//·������
	virtual void GetRouteInfoData( vector<TRouteCfg> &vecTRouteCfg )const = 0;
	//��Ӻ�ɾ��·��
	virtual u16  RouteMngAddCmd( const TRouteCfg& tRouteCfg ) = 0;
	virtual u16  RouteMngDelCmd( const TRouteCfg& tRouteCfg ) = 0;
};

#endif 