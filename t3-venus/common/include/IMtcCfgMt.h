/*******************************************************************************
 *  ģ����   : MtcLib                                                          *
 *  �ļ���   : IMtcCfgMt.h													   *
 *  ����ļ� :                                                                 *
 *  ʵ�ֹ��� : �ṩ������Ϣ�����Ľӿ�                                          *
 *  ����     : �����                                                          *
 *  �汾     : V4.0  Copyright(c) 2003 - 2006 KDC, All rights reserved.          *
 *                                                                             *
 *    =======================================================================  *
 *  �޸ļ�¼:                                                                  *
 *    ��  ��    �汾        �޸���      �޸�����                               *
 *  2006/2/21  4.0         �����       ע��                                   *
 *                                                                             *
 *******************************************************************************/

#ifndef __IMTCCFGMT_H__
#define __IMTCCFGMT_H__

#include "dispevent.h"
#include "mtstruct.h"
#include <vector>
using std::vector;


typedef struct tagMcDualParamCfg
{
	EmVideoFormat	emVidFormat;
	EmVideoResolution emVidRes;
	u32				  dwFrame;
	u32              dwRemain1;
	u32				dwRemain2;
	tagMcDualParamCfg() { emVidFormat =  emVEnd; emVidRes = emVResEnd; 
							dwFrame = 0; dwRemain1 = 0; dwRemain2 = 0;}
}TMcDualParamCfg;


class IMtcCfgMt : public CDispEvent
{
public:
    /*�������� EmLanguage& GetLanguage
    ��    �ܣ� ��ȡ�ն˺�OSD��ǰʹ�õ�������Ϣ
    ��    ���� 
    �� �� ֵ�� const EmLanguage&
    ˵    ���� */
	virtual const EmLanguage& GetLanguage() const = 0;
	virtual u16 UpdateLanguage(const EmLanguage& em) = 0;

    /*�������� ResetSystem
    ��    �ܣ� �������������óɳ���Ĭ��ֵ
    ��    ���� 
    �� �� ֵ�� BOOL32
    ˵    ���� */
	virtual BOOL32 ResetSystem() = 0;

	/*����	������Ϣ����
	����	cfg		������Ϣ
	����ֵ	������Ϣ
			�ɹ�����0;ʧ�ܷ��ش�����
	˵��	��*/
	virtual const TH323Cfg& GetH323Cfg() const = 0;
	virtual u16 UpdateH323Cfg(const TH323Cfg& cfg) = 0;
	virtual u16 ResetH323Cfg() = 0;
	virtual BOOL IsGKSupportDN() const = 0;
	virtual void ResetIsGKSupportDN() = 0;
	virtual const s8* GetGKDomainName() const = 0;
	virtual u16 UpdateGKDomainName(s8 achGKDomainName[MT_MAX_H323GKSERVER_NAME_LEN]) = 0;
	/*����	������Ϣ����
	����	cfg		������Ϣ
	����ֵ	������Ϣ
			�ɹ�����0;ʧ�ܷ��ش�����
	˵��	��*/
	virtual const TEthnetInfo& GetEthnetCfg(u8 byIndex) const = 0;
	virtual u16 UpdateEthnetCfg(u8 byIndex, const TEthnetInfo& cfg) = 0;
	virtual u16 ResetEthnetCfg( u8 byIndex ) = 0;
	/*����	H.460����
	����	cfg		������Ϣ
	����ֵ	������Ϣ
			�ɹ�����0;ʧ�ܷ��ش�����
	˵��	��*/
//	virtual const TH460Info& GetH460Cfg() const = 0;
//	virtual u16 UpdateH460Cfg(const TH460Info& cfg) = 0;
//	virtual u16 ResetH460Cfg() = 0;
	/*����	������Ϣ����
	����	cfg		������Ϣ
	����ֵ	������Ϣ
			�ɹ�����0;ʧ�ܷ��ش�����
	˵��	��*/
	virtual const TUserCfg& GetUserCfg() const = 0;
	virtual u16 UpdateUserCfg(const TUserCfg& cfg) = 0;
	virtual u16 ResetUserCfg() = 0;
	/*����	��Ƶ��Ϣ����
	����	byIndex	������
			cfg		������Ϣ
	����ֵ	������Ϣ
			�ɹ�����0;ʧ�ܷ��ش�����
	˵��	��*/	
	virtual const TVideoParam& GetVideoCfg(EmVideoType emType) const = 0;
	virtual u16 UpdateVideoCfg(EmVideoType emType, const TVideoParam& cfg) = 0;
	virtual u16 ResetVideoCfg(EmVideoType emType, EmMtModel emModel) = 0;
	virtual u16 UpdateH264FomateSel(u32 dwSel) = 0;

    /*�������� TVideoParam& GetPCVideoCfg
    ��    �ܣ� PC˫����������Ϣ
    ��    ���� 
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const TVideoParam& GetPCVideoCfg() const = 0;
	virtual u16 UpdatePCVideoCfg(const TVideoParam& cfg) = 0;
	virtual u16 ResetPCVideoCfg(EmMtModel emModel) = 0;

    /*�������� TOsdCfg& GetOSDCfg
    ��    �ܣ� ��ʾ������Ϣ
    ��    ���� 
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const TOsdCfg& GetOSDCfg() const = 0;
	virtual u16 UpdateOSDCfg(const TOsdCfg& cfg) = 0;
	virtual u16 ResetOSDCfg() = 0;

    /*�������� TE1Config& GetE1Cfg
    ��    �ܣ� E1 ������Ϣ
    ��    ���� 
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const TE1Config& GetE1Cfg() const = 0;
	virtual u16 UpdateE1Cfg(const TE1Config& cfg) = 0;
	virtual u16 DeleteE1Cfg() = 0;
	virtual u16 ResetE1Config() = 0;
	
    /*�������� TSerialCfg& GetSerialCfg
    ��    �ܣ� ����������Ϣ
    ��    ���� EmSerialType emType
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const TSerialCfg& GetSerialCfg(EmSerialType emType) const = 0;
	virtual u16 UpdateSerialCfg(EmSerialType emType, const TSerialCfg& cfg) = 0;
	virtual u16 ResetSerialCfg(EmSerialType emType) = 0;
	virtual EmSerialType GetSerialIndex() = 0;
    /*�������� TplArray<TRouteCfg>& GetAllRouteCfg
    ��    �ܣ� ·��������Ϣ
    ��    ���� 
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const TplArray<TRouteCfg>& GetAllRouteCfg() const = 0;
	virtual u16 AddRouteCfg(const TRouteCfg& cfg) = 0;
	virtual u16 DelRouteCfg(const TRouteCfg& cfg) = 0;

    /*�������� TPPPOECfg& GetPPPOECfg
    ��    �ܣ� PPPoE������Ϣ
    ��    ���� 
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const TPPPOECfg& GetPPPOECfg() const = 0;
	virtual u16 UpdatePPPOECfg(const TPPPOECfg& cfg) = 0;
	virtual u16 ResetPPPoECfg() = 0;

    /*�������� TSNMPCfg& GetSNMPCfg
    ��    �ܣ� SNMP������Ϣ
    ��    ���� 
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const TSNMPCfg& GetSNMPCfg() const = 0;
	virtual u16 UpdateSNMPCfg(const TSNMPCfg& cfg) = 0;
	virtual u16 ResetSNMPCfg() = 0;

    /*�������� TIPQoS& GetIPQoS
    ��    �ܣ� Qos������Ϣ
    ��    ���� 
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const TIPQoS& GetIPQoS() const = 0;
	virtual u16 UpdateIPQos(const TIPQoS& cfg) = 0;
	virtual u16 ResetIPQos() = 0;

    /*�������� TEmbedFwNatProxy& GetFireWallCfg
    ��    �ܣ� ����ǽ������Ϣ
    ��    ���� 
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const TEmbedFwNatProxy& GetFireWallCfg() const = 0;
	virtual u16 UpdateFireWallCfg(const TEmbedFwNatProxy& cfg) =0;
	virtual u16 ResetFireWallCfg() = 0;
	virtual u8  GetProxyDomainInd() = 0;
	virtual BOOL IsFirewallSupportDN() const = 0;
	virtual void ResetIsFirewallSupportDN() = 0;
	virtual const s8* GetFirewallDomainName() const = 0;
//	virtual u16 UpdateFirewallDomainName(s8 achFirewallDomainName[MT_MAX_H323GKSERVER_NAME_LEN]) = 0;
    /*�������� u16& GetUDPBasePort
    ��    �ܣ� �˿�������Ϣ
    ��    ���� 
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const u16& GetUDPBasePort() const = 0;
	virtual const u16& GetTCPBasePort() const = 0;
	virtual u16 UpdateCommonBasePort(u16 wUDPPort, u16 wTCPPort) = 0;
	virtual u16 ResetCommonBasePort() = 0;

    /*�������� TNATMapAddr& GetNapMapAddr
    ��    �ܣ� ��̬napӰ��������Ϣ
    ��    ���� 
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const TNATMapAddr& GetNapMapAddr() const = 0;
	virtual u16 UpdateNapMapAddr(const TNATMapAddr& cfg) = 0;
	virtual u16 ResetNapMapAddr() = 0;

	virtual const TLostPackResend& GetRetransCfg() const = 0;
	virtual u16 UpdateRetransCfg(const TLostPackResend& cfg , BOOL IsCustomized = 0) = 0;
	virtual u16 ResetRetransCfg() = 0;

	//��������
	virtual const u32& GetSoundPriority() const = 0;
	virtual u16 UpdateSoundPriority(u32 dwSoundPriority) = 0;
	virtual u16 ResetSoundPriority() = 0;

    /*�������� TStreamMedia& GetStreamCfg
    ��    �ܣ� ��ý��������Ϣ
    ��    ���� 
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const TStreamMedia& GetStreamCfg() const = 0;
	virtual u16 UpdateStreamCfg(const TStreamMedia& cfg) = 0;
	virtual u16 ResetStreamCfg() = 0;

    /*�������� TAVPriorStrategy& GetAVPriorCfg
    ��    �ܣ� ��Ƶ��ѡЭ��������Ϣ
    ��    ���� 
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const TAVPriorStrategy& GetAVPriorCfg() const = 0;
	virtual u16 UpdateAVPriorCfg(const TAVPriorStrategy& cfg) = 0;
	virtual u16 ResetAVPriorCfg() = 0;

    /*�������� TCameraCfg* GetCameraCfg
    ��    �ܣ� ����ͷ������Ϣ
    ��    ���� 
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const TCameraCfg* GetCameraCfg() const = 0;
	virtual u16 UpdateCameraCfg(u8 byIndex, const TCameraCfg& cfg) = 0;
	virtual const vector<TCameraTypeInfo>& GetCamTypeInfo() const = 0;
	virtual u16 ResetCameraCfg(u8 byIndex) = 0;

    /*�������� TVideoStandard& GetVStandard
    ��    �ܣ� ��Ƶ��ʽ������Ϣ
    ��    ���� EmVideoType emType
               BOOL32 bIsInPort
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const TVideoStandard& GetVStandard(EmVideoType emType, BOOL32 bIsInPort) const = 0;

//	virtual const TVideoStandard& GetVStandard(EmVideoType emType, BOOL32 bIsInPort) coideoStandard& tVideoStandard) = 0;
	virtual u16 UpdateVStandard(const TVideoStandard& tVideoStandard) = 0;
	
    /*�������� TImageAdjustParam& GetImageAdjustCfg
    ��    �ܣ� ͼ�����������Ϣ
    ��    ���� 
    �� �� ֵ�� virtual const 
    ˵    ���� */
//	virtual const TImageAdjustParam& GetImageAdjustCfg(u8 byIndex) const = 0;
//	virtual u16 UpdateImageAdjustCfg(const u8 byIndex, const TImageAdjustParam& cfg) = 0;
//	virtual u16 ResetImageAdjustCfg(const u8 byIndex, EmMtModel emModel) = 0;
	virtual const TImageAdjustParam* GetImageAdjustCfg() const = 0;
	virtual u16 UpdateImageAdjustCfg(const u8 byIndex, const TImageAdjustParam* pCfg) = 0;
	virtual u16 ResetImageAdjustCfg(const u8 byIndex, EmMtModel emModel) = 0;
	//pmct
	virtual u16 UpdateImageAdjustCfg(const TImageAdjustParam& cfg) = 0;
	virtual u16 ResetImageAdjustCfg(EmMtModel emModel) = 0;

	//AEC����
	virtual const BOOL32& IsAEC() const = 0;
	virtual u16 UpdateAEC(BOOL32 bEnable) = 0;
	//AGC����
	virtual const BOOL32& IsAGC() const = 0;
	virtual u16 UpdateAGC(BOOL32 bEnable) = 0;
    //��Ƶ�˿�ѡ������
    virtual const THdAudioPort& GetHDAudioPortCfg() const = 0;
    virtual u16 UpdateHDAudioPortCfg(const THdAudioPort& tAudioPort) = 0;	
	//ANS����
	virtual const BOOL32& IsANS() const = 0;
	virtual u16 UpdateANS(BOOL32 bEnable) = 0;

	//��������
	virtual const u8& GetInputVol() const = 0;
	virtual u16 UpdateInputVol(u8 byVolume) = 0 ;
	//�������
	virtual const u8& GetOutputVol() const = 0;
	virtual u16 UpdateOutputVol(u8 byVolum) = 0;
	
    /*�������� TBannerInfo& GetBannerInfo
    ��    �ܣ� ���������Ϣ
    ��    ���� 
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const TBannerInfo& GetBannerInfo() const = 0;
	virtual u16 UpdateBannerInfo( TBannerInfo &tBanner, s8 *pContent = 0) = 0;
	virtual u16 ResetBannerInfo() = 0;
	virtual s8* GetBannerContent() = 0;
	//�������ص�IP��ַ��������
	virtual const u32& GetGatewayIP() const = 0;
	//���ص�IP(������)
	virtual u16 UpdateGatewayIP(u32 dwIP) = 0; 
	

	//����CNS��IP �� ���� 2011-4-19 by yjj 
    virtual const TMtCnsParam& GetCnsInfo() const = 0; 
	virtual u16 UpdateCns(TMtCnsParam &tParam) = 0 ; 

	
    /*�������� GetExMatrixCtrlType
    ��    �ܣ� �������������Ϣ
    ��    ���� 
    �� �� ֵ�� virtual EmSerialType& 
    ˵    ���� */
	virtual EmSerialType& GetExMatrixCtrlType() = 0;
	virtual const TIPTransAddr& GetEXMatrixCtrlIp() = 0;
	//��ȡ�ն�֧���ⲿ������������
	virtual u16 ReqExtenalMatrixCfg() = 0;
	//�ն��ⲿ��������
	virtual u16 UpdateExtenalMatrixCfg(EmSerialType emType, const TIPTransAddr &tIPAddr) = 0;
	
	/*����	����ȫ��������Ϣ
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
	virtual u16 ReqAllCfg() = 0;

    /*��������  BOOL& GetVGAShowCfg
    ��    �ܣ� VGA���������Ϣ
    ��    ���� 
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const  BOOL& GetVGAShowCfg() = 0 ;
	virtual u16 UpdateVGAShowCfg( BOOL32 bLocal ) = 0 ;
	
    /*��������  BOOL& GetVGAShowCfg
    ��    �ܣ� �ڶ�·��Ƶ�Ƿ������VGA
    ��    ���� 
    �� �� ֵ�� virtual const BOOL32&
    ˵    ���� */
    virtual const BOOL32& GetSecondVideoToVGA() = 0;
    virtual u16 UpdateSecondVideoToVGA(BOOL32 bToVGA) = 0;

    /*�������� GetMonitorService
    ��    �ܣ� �Զ��л�Ϊ����ն�������Ϣ
    ��    ���� 
    �� �� ֵ�� virtual TMonitorService& 
    ˵    ���� */
	virtual TMonitorService& GetMonitorService() = 0;
	virtual u16 UpdateMonitorService( TMonitorService& tMonService ) = 0;
	virtual BOOL32 IsEnablwMonitor() = 0;
	/*�������� SendStaticPic
    ��    �ܣ� ���;�̬ͼƬ
    ��    ���� BOOL32 bSend  True ���� / False ������
    �� �� ֵ�� virtual u16 
    ˵    ���� */
	virtual u16 SendStaticPic(BOOL32 bSend) = 0;
    /*�������� IsSendStaticPic
    ��    �ܣ� �Ƿ��;�̬ͼƬ
    ��    ���� 
    �� �� ֵ�� virtual BOOL 
    ˵    ���� */
	virtual inline BOOL32& IsSendStaticPic() = 0;
    
    // ��ȡ�ն�Ӳ��������ϵͳ������汾��Ϣ
    virtual const u8 GetHardwareVersion() = 0;
    virtual const u8 GetSubHardwareVersion() = 0;
    virtual const EmMtOSType GetMtOSType() = 0;
    virtual const s8* GetOSVersion() = 0;
    virtual const s8* GetSoftwareVersion() = 0;
	//��ȡ�ն�Mac��ַ
	virtual const s8* GetMacAddr()=0;      

    // ����PCMT��ƵԴ��Ϣ
    virtual u16 UpdatePcmtVidSource(const TCapType& cfg) = 0;
    // ��ȡPCMT��ƵԴ��Ϣ
    virtual const TCapType& GetPcmtVidSource() const = 0;
    // PCMT��ƵԴ��Ϣ�ó�Ĭ��ֵ
    virtual u16 ResetPcmtVidSource() = 0;
	// ����PCMT��Ƶ�ɼ�����, ����ͼ����/�߶�
	virtual u16 UpdatePcmtCapParam(u16 wWidth, u16 wHeight) = 0;
    
    /*�������� GetVGAOutCfg
    ��    �ܣ� 8010c��ʾVGA����video����
    ��    ���� 
    �� �� ֵ�� TVgaOutCfg& 
    ˵    ���� */
    virtual const TVgaOutCfg& GetVGAOutCfg() const = 0;
    virtual u16 UpdateVGAOutCfg(const TVgaOutCfg& cfg) = 0;
    virtual u16 ResetVGAOutCfg() = 0;

    // ˫�����ʱ�
    /*=============================================================================
    �� �� ��:GetDualRatio
    ��    ��:��ȡ˫������
    ��    ��:��
    ע    ��:��
    �� �� ֵ:˫�����ʽṹ
    -------------------------------------------------------------------------------
    �޸ļ�¼:
    ��      ��  �汾    �޸���  �޸�����
    2006/06/30  4.0     ���    ����
    =============================================================================*/
    virtual const TDualRation& GetDualRatio(void) const = 0;
    /*=============================================================================
    �� �� ��:UpdateDualRatio
    ��    ��:����˫������
    ��    ��:const TDualRation &tDualRatio      [in]    ˫������
    ע    ��:������Ϣ�ӿ�
    �� �� ֵ:��Ϣ���ͽӿڷ���ֵ
    -------------------------------------------------------------------------------
    �޸ļ�¼:
    ��      ��  �汾    �޸���  �޸�����
    2006/06/30  4.0     ���    ����
    =============================================================================*/
    virtual u16 UpdateDualRatio(const TDualRation &tDualRatio) = 0;
    /*=============================================================================
    �� �� ��:ResetDualRatio
    ��    ��:�ָ�˫������Ĭ��ֵ
    ��    ��:��
    ע    ��:������Ϣ�ӿ�
    �� �� ֵ:��Ϣ���ͽӿڷ���ֵ
    -------------------------------------------------------------------------------
    �޸ļ�¼:
    ��      ��  �汾    �޸���  �޸�����
    2006/06/30  4.0     ���    ����
    =============================================================================*/
    virtual u16 ResetDualRatio(void) = 0;
    
    // mt�豸����ָʾ
    virtual const TMtEquipmentCapset& GetMtEquipmentCapset() const = 0;
    // Mic����
    virtual const u8 GetMicAdjust() const = 0;
    // Mic�������
    virtual u16 AdjustMic(const u8 byMicAdjust) = 0;
    // ��������
	virtual const u32 GetAecAdjust() const = 0;
	virtual u16 AdjustAec(const u32 dwAecAdjust) = 0;
    // ����ʹ�û�ʹ��DHCP����
    virtual u16 UseDHCP(const BOOL32 bUseDHCP) = 0;
    virtual BOOL32& IsUseDHCP() = 0;

    // ��ȡDHCP IP
    virtual u16 GetDHCPIP() = 0;
    // �ر�DHCP ����
    virtual u16 ShutDownDHCPIP() = 0;

    // ��ȡDNS������IP
    virtual u32_ip& GetDNSServer() = 0;
    // ����DNS������IP
    virtual u16 SetDNSServer(u32_ip dwDNSServer) = 0;
    //�Ƿ��п��õ�DNS��������dhcp��ȡ���ģ��ֶ�����ģ�
	virtual u8 IsUseDNS() = 0;

    // ��Ƕmc����
    virtual u16 UpdateInnerMcCfg(const TInnerMcCfg &tInnerMcCfg) = 0;
    virtual const TInnerMcCfg& GetInnerMcCfg() = 0;

	//������������������
	virtual const EmMtLoudspeakerVal &GetSpeakerVal()=0;
	virtual u16 UpdateSpeakerVal(const EmMtLoudspeakerVal emLoudVal)=0;
	//LDAP ����������
	virtual const CHAR* GetLdapServer()=0;
	virtual u16  UpdateLdapServer(const CString &strLdapServer)=0;
	
	//T2����Ƶ��������  TRUE��ʾ�����Video 
	virtual const BOOL32&  GetMainVideoToVideo()=0;
	virtual u16     UpdateMainVideoToVideo(const BOOL32 bOutVideo)=0;

	//ң�����ȼ�����
	virtual const TRapidKey& GetRemoteHotKey()=0;
	virtual u16   UpdateRemoteHotKey(const TRapidKey& tHotKey)=0;
	
	//����GK����ǽ����
	virtual const TInnerGKCfg& GetInnerGKCfg()=0;
	virtual u16   UpdateInnerGKCfg(const TInnerGKCfg& tInnerGkCfg)=0;
	virtual u16 UpdateMultiGKCfg(const TPxyIPCfg &tPxyIPCfg, u32 dwOperateType)=0;
	virtual const TPxyIPCfg * GetMultiGKConfig() = 0;
	
	//MTU ����
	virtual const  u32& GetUseSliceCfg() = 0;
	virtual u16 UpdateUseSliceCfg(const u32 dwIsUseMTU) = 0;	
	virtual const u32& GetMTUCfg()=0;
	virtual u16   UpdateMTUCfg(const u32 dwMTU)=0;
	//ϵͳʱ��
	virtual const TMtKdvTime& GetMTSysTime()=0;
	virtual u16   UpdateMTSysTime(const TMtKdvTime& tMTTime)=0;
	virtual const u32 &GetCfgH264FormatSel() const= 0;
	virtual u16 UpdateInnerProxyCfg(const TInnerProxyCfg &tInnerProxyCfg) = 0;
	
	virtual BOOL32 IsMasterIPConflict() = 0;
	virtual u32_ip GetMasterIP() = 0;
	virtual BOOL32 IsSlaveIPconflict() = 0;
	virtual u32_ip GetSlaveIP() = 0;
	virtual const TInnerProxyCfg& GetInnerProxyCfg() = 0;
	virtual const u8 GetNetMask() = 0;
	virtual u16 UpdateNetMask(u8 byNetMask) = 0;
	
	//fec
	virtual u16 UpdateFecTypeCfg(const TFecInfo &tFecInfo) = 0;
	virtual const TFecInfo &GetFecType() = 0;
	virtual u16 ResetFecTypeCfg() = 0;

	//����ģʽ
	virtual BOOL32 UpdateCfgEthMode( u32 dwCfgEthMode ) = 0;
	virtual u32& GetCfgEthMode() = 0;
	//telnet ����
	virtual u16 UpdateTelnetPwd(const char *pTelnetPwd) = 0;
	virtual const char *GetTelnetPwd() = 0;
	//ϵͳ����ʱ��
	virtual BOOL32 QuerySystemRunTime() = 0;
	virtual u32& GetSystemRunTime() = 0;

	//����ϵͳ
	//virtual BOOL32 ResetSystem() = 0;

// 	//wifi
// 	virtual u16 AddWifiCfg(TWiFiBSSIDCfg &tWiFiBSSIDCfg) = 0;
// 	virtual u16 DelWifiCfg(TWiFiBSSIDCfg &tWiFiBSSIDCfg) = 0;
// 	virtual u16 ConnectWifi(TWiFiBSSIDInfo &tWiFiBSSIDInfo) = 0;
// 	virtual u16 ConnectWifi(TWiFiBSSIDCfg &tWiFiBSSIDCfg) = 0;
// 	virtual u16 DisconnectWifi() = 0;
// 	virtual TWiFiLinkStatus &GetWifiCurrentLinkState() = 0;
// 	virtual u16 ScanWifiLink() = 0;
// 	virtual TWiFiBSSIDCfg *GetWifiCfgInfo() = 0;
// 	virtual TWiFiBSSIDInfo *GetWifiScanResult() = 0;
// 	virtual TWiFiNetCfg &GetWiFiNetIP() = 0;
// 	virtual u16 UpdateWifiNetIP(const TWiFiNetCfg &tWiFiNetCfg) = 0;
// 	virtual u16 ModifyWiFiItem(u32 nItem, const TWiFiBSSIDCfg &tWiFiBSSIDCfg) = 0;

	//Socket5
//	virtual TSocks5Proxy& GetSock5Info() = 0;
//    virtual u16 UpdateSock5Info(const TSocks5Proxy& cfg) = 0;

	/*�������� GetOutputModel& UpdateOutputModel
    ��    �ܣ� �����ʽ
    ��    ���� 
    �� �� ֵ�� virtual const 
    ˵    ���� */
	virtual const u32& GetOutputModel() const = 0;
	virtual u16 UpdateOutputModel(const u32 dwOutputModel) = 0;
// 	virtual u16 ResetOutputModel() = 0;
	
	//ͼ�������ͼ����ǿ   TRUE��ʾͼ����ǿ 
	virtual const BOOL32& GetImgEnhance() const = 0;
	virtual u16 UpdateImgEnhance(const BOOL32 &bEnable) = 0;
	virtual u16 ResetImgEnhance() = 0;

	//Ӳ���������ģʽ //081121 sq���
	virtual u16 UpdateVideoEncodeDecodeModel(u8 model1, u8 model2 = 0, u32 param1 = 0, u32 param2 = 0) = 0;
	virtual u8  GetVideoEncodeDecodeModel() = 0;
	
	//���ӻ���ʽ����
	virtual const TVideoDisplayFrm& GetVidFrm() const = 0;
	virtual u16 UpdateVidFrm(const TVideoDisplayFrm& tVidDisplayFrm ) = 0;
	virtual u16 ResetVidDisplayFrm() = 0;

	//����Э������
	virtual const u8& GetCallProtocolCfg() const = 0;
	virtual u16 UpdateCallProtocol(const u8& byCallProtocol) = 0;
	virtual u16 UpdateCallProtocol(const TGuideCfg& tGuidCfg) = 0;
	virtual u16 ResetCallProtocol() = 0;

	//MTU
	virtual u16 ResetMTUCfg() = 0;
	//���;�̬ͼƬ
	virtual u16 ResetSendStaticPic() = 0;
	//�а�
	virtual u16 ResetUseSliceCfg() = 0;


	//��ǰ����
	virtual u16 UpdateCurrentEthNo(u8 No) = 0;
	virtual u8 GetCurrentEthNo() = 0;


	//E1 Unit
	virtual u16 UpdateE1Units(const TE1Unit* cfg) = 0;
	virtual	TE1Unit* GetE1Units() = 0;
	
	//E1 Group
	virtual u16 UpdateE1Group(const TE1Group* cfg, u8 E1Num) = 0;
	virtual TE1Group* GetE1Groups() = 0;
	virtual u8 GetE1GroupNum() = 0;

	//���ܻ�
	virtual u16  UpdateUsePassThrough(u32 used) = 0;
	virtual u32  GetUsePassThrough() = 0;


	virtual u16 UpdateLastFrame(u32 dwBlue, u32 dwTime) = 0;
	virtual u32& GetLastFrameShow() = 0;
	virtual u32& GetLastFrameSwitchTime() = 0;
	
	virtual u16 UpdateShowApplication(u32 val) = 0;
	virtual BOOL32& IsShowApplication() = 0;

	virtual BOOL &IsResendCustomized() = 0;

	//����mc˫����ʽ
	virtual u16 UpdateMcDualParamCfg(TMcDualParamCfg& cfg)  = 0;
	virtual TMcDualParamCfg& GetMcDualParamCfg() = 0;

	//mtcbox
	virtual u16 UpdateMtcBoxCallCfg(TMtcBoxCallCfg &tCfg, u8 MtcBoxBtnNo) = 0;
	virtual vector<TMtcBoxCallCfg>& GetMtcBoxCallCfg() = 0;
	virtual TSipCfg& GetSipServiceCfg() = 0;
	virtual u16 ResetSipCfg() = 0;
	virtual u16 UpdateSipSrvInfo(const TSipCfg& tSipCfg) = 0;
	virtual const u32& GetVGAFhaseClock(u32 nIndex) = 0;
	virtual const u32& GetVGAFilterStatus(u32 nIndex) = 0;
	virtual const BOOL GetVGACtrlStatus(u32 nIndex) = 0;
	virtual u16 UpdateVGAPhaseClock(u32 anPos[3]) = 0;
	virtual u16 UpdateVGAFilterStatus(BOOL abStatus[3]) = 0;
	virtual u16 UpdateVGAPhaseClockDirctly(u32 anPos[3]) = 0;
	virtual u16 UpdateVGAFiltStatusDirctly(BOOL nStatus[3]) = 0;
}; // IMtCfgMt

#endif