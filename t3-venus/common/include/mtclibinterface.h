/*=============================================================================
ģ   ��   ��: �ն˿���̨ҵ���ܿ�
��   ��   ��: mtclibinterface.h
�� ��  �� ��: mtclibinterface.cpp
�ļ�ʵ�ֹ���: mtclib��Ϣ���ͽӿ�(UI->MT)
��        ��: ���
��        ��: V4.0  Copyright(C) 2003-2007 KDC, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2007/05/28  4.0     ���        ����
=============================================================================*/

#ifndef _MTCLIBINTERFACE_20070528_H_
#define _MTCLIBINTERFACE_20070528_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "addrbook.h"
#include "key.h"
#include "ummessagestruct.h"

class CMtclibInterface : public CInstance
{
public:
    CMtclibInterface();
    virtual ~CMtclibInterface();

//UI���ýӿ�
public:
    ///////////////////////////////////////////////////////////////////////////////
    //  1. ���ӽӿ�
    ///////////////////////////////////////////////////////////////////////////////

    //�����ն�
    EMMtclibErrorCode ConnectMtReq(u32 dwMtIP, u16 wMtListenPort,
                                   LPCSTR lpszUserName, LPCSTR lpszPwd,
                                   u32 &dwLocalIpAddr);

    //�Ͽ�����
    EMMtclibErrorCode DisconnectMtCmd(void);

    ///////////////////////////////////////////////////////////////////////////////
    //  2. VOD�ӿ�
    ///////////////////////////////////////////////////////////////////////////////

    //��¼VOD������
    EMMtclibErrorCode VodLoginReq(u32 dwServerIP, u16 wPort, LPCSTR lpszUsername,
                                  LPCSTR lpszPassword);

    //�˳�VOD������
    EMMtclibErrorCode VodLogoutReq(void);

    //��ȡVODָ��Ŀ¼���ļ��б�
    EMMtclibErrorCode VodGetFileListReq(LPCSTR lpszDirectory);

    //��ȡVODָ���ļ���Ϣ
    EMMtclibErrorCode VodGetFileInfoReq(LPCSTR lpszFilename);

    //����VOD�ļ�
    EMMtclibErrorCode VodPlayFileReq(LPCSTR lpszFilename);

    //��ͣ����VOD�ļ�
    EMMtclibErrorCode VodPauseFileReq(void);

    //�ָ�����VOD�ļ�
    EMMtclibErrorCode VodResumeFileReq(void);

    //ֹͣ����VOD�ļ�
    EMMtclibErrorCode VodStopFileReq(void);

    //��ָ��λ�ò���VOD�ļ�(������)
    EMMtclibErrorCode VodPlayFileAtPosCmd(u32 dwPos);

    ///////////////////////////////////////////////////////////////////////////////
    //  3. ����ӿ�
    ///////////////////////////////////////////////////////////////////////////////

    //��ȡ�������þ��󷽰�
    EMMtclibErrorCode MatrixGetAllInnerSchemeReq(void);

    //��ȡָ�����þ��󷽰�
    EMMtclibErrorCode MatrixGetInnerSchemeReq(u8 byIndex);

    //�������þ��󷽰�
    EMMtclibErrorCode MatrixSaveInnerSchemeReq(const TAVInnerMatrixScheme &tScheme);

    //���õ�ǰӦ�����þ��󷽰�
    EMMtclibErrorCode MatrixSetCurApplyInnerSchemeReq(u8 byIndex);

    //��ȡ��ǰӦ�����þ��󷽰�
    EMMtclibErrorCode MatrixGetCurApplyInnerSchemeReq(void);

    //���õ�ǰ������ƵԴ
    EMMtclibErrorCode MatrixSetCurInnerVideoSourceCmd(EmMtVideoPort emPort);

    //ѡ��ǰ��ƵԴ(����/Զ��)
    EMMtclibErrorCode MatrixSetCurInnerSiteCmd(EmSite emSite);

    //��ǰ��ƵԴ����
    EMMtclibErrorCode MatrixEditCurInnerVideoSourceNameCmd(
                                                const TVideoSourceInfo &tInfo);

    //��ȡ���þ�����Ϣ
    EMMtclibErrorCode MatrixGetOuterInfoReq(void);

    //�������þ�����ƵԴ
    EMMtclibErrorCode MatrixSetOuterVideoSourceReq(const TVideoSourceInfo &tInfo);

    //��ȡ���þ�����ƵԴ
    EMMtclibErrorCode MatrixGetOuterVideoSourceReq(void);

    ///////////////////////////////////////////////////////////////////////////////
    //  4. ���ýӿ�
    ///////////////////////////////////////////////////////////////////////////////

    //����H.323����
    EMMtclibErrorCode CfgSetH323CfgCmd(const TH323Cfg &tCfg);

    //�����û�����
    EMMtclibErrorCode CfgSetUserCfgCmd(const TUserCfg &tCfg);

    //�����ն���ʾ����
    EMMtclibErrorCode CfgSetOSDCfgCmd(const TOsdCfg &tCfg);

    //������̫������
    EMMtclibErrorCode CfgSetEthnetCfgCmd(u8 byIndex, const TEthnetInfo &tCfg);

    //����E1����
    EMMtclibErrorCode CfgSetE1CfgCmd(const TE1Config &tCfg);

    //���ô�����Ϣ����
    EMMtclibErrorCode CfgSetSerialCtrlCmd(EmSerialType emType,
                                          const TSerialCfg &tCfg);

    //���·��
    EMMtclibErrorCode CfgAddRouteCmd(const TRouteCfg &tCfg);

    //ɾ��·��
    EMMtclibErrorCode CfgDelRouteCmd(const TRouteCfg &tCfg);

    //����PPPoE����
    EMMtclibErrorCode CfgSetPPPoECfgCmd(const TPPPOECfg &tCfg);

    //������������
    EMMtclibErrorCode CfgSetNetManagementCfgCmd(const TSNMPCfg &tCfg);

    //����IPQoS��Ϣ����
    EMMtclibErrorCode CfgSetIPQoSCfgCmd(const TIPQoS &tCfg);

    //���÷���ǽ��Ϣ����
    EMMtclibErrorCode CfgSetEmbedFirewallCfgCmd(const TEmbedFwNatProxy &tCfg);

    //���þ�̬ӳ��
    EMMtclibErrorCode CfgSetNatMapCfgCmd(const TNATMapAddr &tCfg);

    //���÷����ش���Ϣ����
    EMMtclibErrorCode CfgSetRetransCfgCmd(const TLostPackResend &tCfg);

    //������ý����Ϣ����
    EMMtclibErrorCode CfgSetStreamCfgCmd(const TStreamMedia &tCfg);

    //������Ƶ�����������
    EMMtclibErrorCode CfgSetVideoParamCmd(EmVideoType emType,
                                          const TVideoParam &tCfg);

    //����PC˫������
    EMMtclibErrorCode CfgSetPCVideoParamCmd(const TVideoParam &tCfg);

    //������ѡЭ����Ϣ����
    EMMtclibErrorCode CfgSetAVPriorCfgCmd(const TAVPriorStrategy &tCfg);

    //��������ͷ��Ϣ����
    EMMtclibErrorCode CfgSetCameraCfgCmd(u8 byIndex, const TCameraCfg &tCfg);

    //������Ƶ��ʽ(����/���)
    EMMtclibErrorCode CfgSetVideoStandardCmd(const TVideoStandard &tStand);

    //����ͼ�����
    EMMtclibErrorCode CfgSetImageAdjustCfgCmd(const TImageAdjustParam &tParam);

    //���ú������
    EMMtclibErrorCode CfgSetBannerInfoCmd(const TBannerInfo &tInfo);

    //���ô��ڿ�������
    EMMtclibErrorCode CfgSetSerialCfgCmd(EmSerialType emType,
                                         const TIPTransAddr &tIPAddr);

    //���ü���л�ҵ������
    EMMtclibErrorCode CfgSetMonitorServiceCfgCmd(const TMonitorService &tCfg);

    //����˫������
    EMMtclibErrorCode CfgSetDualRatioCfgCmd(const TDualRation &tRatio);

    //��������MC����
    EMMtclibErrorCode CfgSetInnerMCCfgCmd(const TInnerMcCfg &tCfg);

    //����6610E����GK����
    EMMtclibErrorCode CfgSetInnerGKCmd(const TInnerGKCfg &tCfg);

    //����ң������ݼ�
    EMMtclibErrorCode CfgSetShortcutKeyCmd(const TRapidKey &tKey);

    //����PCMT��ƵԴ��Ϣ
    EMMtclibErrorCode CfgSetPcmtVideoSourceCmd(const TCapType &tType);

    //����8010C����VGA�������
    EMMtclibErrorCode CfgSetVGAOutCfgCmd(const TVgaOutCfg &tCfg);

    //���û�������
    EMMtclibErrorCode CfgSetAECCmd(BOOL32 bEnable);

    //�����Զ�����
    EMMtclibErrorCode CfgSetAGCCmd(BOOL32 bEnable);

    //�����Զ���������
    EMMtclibErrorCode CfgSetANSCmd(BOOL32 bEnable);

    //��������Ƶ���
    EMMtclibErrorCode CfgSetMainVideoOutCmd(BOOL32 bOutToVideo);

    //����VGA��ʾ�Ƿ��Ǳ���
    EMMtclibErrorCode CfgSetVGAShowLocalCmd(BOOL32 bLocal);

    //���õڶ�·��Ƶ�Ƿ������VGA
    EMMtclibErrorCode CfgSetSecondVideoToVGACmd(BOOL32 bVGA);

    //�����Ƿ��;�̬ͼƬ
    EMMtclibErrorCode CfgSetSendStaticPicCmd(BOOL32 bSend);

    //�����Ƿ�ʹ��DHCP
    EMMtclibErrorCode CfgSetUseDHCPCmd(BOOL32 bUsed);

    //���ú�������(������)
    EMMtclibErrorCode CfgSetCallRateCmd(u32 dwCallRate);

    //��������(������)
    EMMtclibErrorCode CfgSetGatewayCmd(u32 dwIP);

    //����DNS������IP��ַ(������)
    EMMtclibErrorCode CfgSetDNSServerIPCmd(u32 dwDNSIP);

    //����MTUʱ��(������)
    EMMtclibErrorCode CfgSetMTUCmd(u32 dwMTU);

    //����TCP��UDP��ʼ�˿�(������)
    EMMtclibErrorCode CfgSetTCPUDPStartPortCmd(u16 wTCPPort, u16 wUDPPort);

    //������������
    EMMtclibErrorCode CfgSetLanguageCmd(EmLanguage emLan);

    //����LDAP������
    EMMtclibErrorCode CfgSetLDAPCmd(LPCSTR lpszLDAP);

    //������˷��������
    EMMtclibErrorCode CfgSetMicAdjustCmd(u8 byMicAdjust);

    //���ñ�������
    EMMtclibErrorCode CfgSetEncVolCmd(u8 byVol);

    //���ý�������
    EMMtclibErrorCode CfgSetDecVolCmd(u8 byVol);

    //�����ն�ϵͳʱ��
    EMMtclibErrorCode CfgSetSysTimeCmd(const TMtKdvTime &tTime);

    //��ȡ����������Ϣ(�������л�ȡ���õ�CMD)
    EMMtclibErrorCode CfgGetAllCfgCmd(EmMtModel emModel);

    ///////////////////////////////////////////////////////////////////////////////
    //  5. ���սӿ�
    ///////////////////////////////////////////////////////////////////////////////

    //��ȡ������Ϣ
    EMMtclibErrorCode SnapShotGetInfoReq(void);

    //�ն˿���
    EMMtclibErrorCode SnapShotCmd(void);

    //��տ�����Ϣ
    EMMtclibErrorCode SnapShotClearCmd(void);

    ///////////////////////////////////////////////////////////////////////////////
    //  6. FXO�ӿ�
    ///////////////////////////////////////////////////////////////////////////////

    //FXO����
    EMMtclibErrorCode FXOCallReq(LPCSTR lpszPhoneNo, u16 wNoLen,
                                 LPCSTR lpszEntryName = NULL);

    //FXO�ҶϺ���
    EMMtclibErrorCode FXOHangupCmd(void);

    //FXO�ܾ�����
    EMMtclibErrorCode FXORejectCmd(void);

    //FXO����
    EMMtclibErrorCode FXOAcceptCmd(void);

    ///////////////////////////////////////////////////////////////////////////////
    //  7. ��ַ���ӿ�
    ///////////////////////////////////////////////////////////////////////////////

    //ע���ַ��
    EMMtclibErrorCode AddrRegisterReq(void);

    //ע����ַ��
    EMMtclibErrorCode AddrUnregisterReq(void);

    //�����Ŀ
    EMMtclibErrorCode AddrAddEntryReq(const CAddrEntry &cEntry);

    //�޸���Ŀ
    EMMtclibErrorCode AddrEditEntryReq(const CAddrEntry &cEntry);

    //ɾ����Ŀ
    EMMtclibErrorCode AddrDelEntryReq(u32 dwIndex);

    //��ӻ�����
    EMMtclibErrorCode AddrAddGroupReq(const CAddrMultiSetEntry &cGroup);

    //�޸Ļ�����
    EMMtclibErrorCode AddrEditGroupReq(const CAddrMultiSetEntry &cGroup);

    //ɾ��������
    EMMtclibErrorCode AddrDelGroupReq(u32 dwIndex);

    //������������Ŀ
    EMMtclibErrorCode AddrAddEntryToGroupReq(const TADDRMULTISETENTRY &tEntry);

    //�ӻ�����ɾ����Ŀ
    EMMtclibErrorCode AddrDelEntryFromGroupReq(const TADDRMULTISETENTRY &tEntry);

    //�ϴ���ַ���ļ�����
    EMMtclibErrorCode AddrUploadFileNotif(LPCSTR lpszFilename);

    //������ӵĵ�ַ��ĿĬ����ӵ�UserDef������
    EMMtclibErrorCode AddrAddEntryToUserDefReq(u32 dwIndex);

    ///////////////////////////////////////////////////////////////////////////////
    //  8. ����ͷ���ƽӿ�
    ///////////////////////////////////////////////////////////////////////////////

    //����ͷ�������
    EMMtclibErrorCode CameraMoveDirectionCmd(EmDirection emDirect, EmAction emAct);

    //����ͷ�Զ�����
    EMMtclibErrorCode CameraAutoFocusCmd(void);

    //����ͷ�ֶ�����
    EMMtclibErrorCode CameraAdjustFocusCmd(BOOL32 bNear, EmAction emAct);

    //����ͷ��Ұ����
    EMMtclibErrorCode CameraAdjustZoomCmd(BOOL32 bZoomOut, EmAction emAct);

    //����ͷ���ȵ���
    EMMtclibErrorCode CameraAdjustBrightnessCmd(BOOL32 bDec, EmAction emAct);

    //����ͷԤ��λ
    EMMtclibErrorCode CameraPresetCmd(BOOL32 bLoad, u8 byPos);

    ///////////////////////////////////////////////////////////////////////////////
    //  9. ��ؽӿ�
    ///////////////////////////////////////////////////////////////////////////////

    //��ʼ���
    EMMtclibErrorCode MonitorStartCmd(EmSite emSite, const TIPTransAddr &tIpAddr);

    //ֹͣ���
    EMMtclibErrorCode MonitorStopCmd(EmSite emSite);

    //����ؼ�֡
    EMMtclibErrorCode MonitorRequestKeyFrameCmd(EmSite emSite);

    ///////////////////////////////////////////////////////////////////////////////
    //  10. ģ��ң�����ӿ�
    ///////////////////////////////////////////////////////////////////////////////

    //����ң������ť
    EMMtclibErrorCode RemotePressDownCmd(u8 byKey, u8 byRemoteType = LBLACK_REMOTE);

    //�ſ�ң������ť
    EMMtclibErrorCode RemoteReleaseUpCmd(u8 byKey, u8 byRemoteType = LBLACK_REMOTE);

    ///////////////////////////////////////////////////////////////////////////////
    //  11. �û�����ӿ�
    ///////////////////////////////////////////////////////////////////////////////

    //�����û��б�
    EMMtclibErrorCode UserGetListReq(void);

    //����û�
    EMMtclibErrorCode UserAddReq(const CUserFullInfo &cUser);

    //�޸��û�
    EMMtclibErrorCode UserEditReq(const CUserFullInfo &cUser);

    //ɾ���û�
    EMMtclibErrorCode UserDelReq(const CUserFullInfo &cUser);

    ///////////////////////////////////////////////////////////////////////////////
    //  12. ��Ե����ӿ�
    ///////////////////////////////////////////////////////////////////////////////

    //�����ն�
    EMMtclibErrorCode P2PCallReq(const TMtAddr &tMtAddr, u16 wCallRate = 768,
                                 LPCSTR lpszEntryName = NULL);

    //ֹͣ����/������Ե����
    EMMtclibErrorCode P2PEndCallCmd(void);

    //���ܵ�Ե����
    EMMtclibErrorCode P2PAcceptAck(BOOL32 bAccept);

    //���Ͷ���Ϣ(��Ե����)
    EMMtclibErrorCode P2PSendMsgCmd(LPCSTR lpszMsg,
                                    EmSMSType emType = emSMSSingleLine,
                                    u8 byRollSpeed = 3, u8 byTimes = 1);

    ///////////////////////////////////////////////////////////////////////////////
    //  13. MCU������ӿ�
    ///////////////////////////////////////////////////////////////////////////////

    //��������
    EMMtclibErrorCode McuConfCreateReq(const TMtAddr &tMcu, u16 wCallRate,
                                       const TConfBaseInfo &tConfInfo,
                                       const vector<TMtAddr> &vctMtList);

    //���к�������
    EMMtclibErrorCode McuConfSiteCallCreateReq(const TSitecallInformation &tCall);

    //��������
    EMMtclibErrorCode McuConfEndCmd(void);

    //�����������Ӧ��
    EMMtclibErrorCode McuConfEnterPwdAck(LPCSTR lpszPwd);

    //����MCU(����ȡMCU�����б�)
    EMMtclibErrorCode McuConfCallMcuReq(const TMtAddr &tMcu, u16 wCallRate);

    //�������
    EMMtclibErrorCode McuConfJoinConfAck(const TConfBaseInfo &tConfInfo);

    //�����ն�
    EMMtclibErrorCode McuConfInviteMtCmd(const TMtAddr &tAddr);

    //�����ն�
    EMMtclibErrorCode McuConfDropMtCmd(const TMtId &tMt);

    //������ϯ
    EMMtclibErrorCode McuConfApplyChairmanCmd(void);

    //���뷢��
    EMMtclibErrorCode McuConfApplySpeakerCmd(void);

    //�������
    EMMtclibErrorCode McuConfApplyMixingCmd(void);

    //������ϯ����
    EMMtclibErrorCode McuConfAcceptChairmanCmd(const TMtId &tMt, BOOL32 bAccept);

    //���ܷ�������
    EMMtclibErrorCode McuConfAcceptSpeakerCmd(const TMtId &tMt, BOOL32 bAccept);

    //���ܻ�������
    EMMtclibErrorCode McuConfAcceptMixingCmd(const TMtId &tMt, BOOL32 bAccept);

    //ָ����ϯ
    EMMtclibErrorCode McuConfSpecChairmanCmd(const TMtId &tMt);

    //ָ������
    EMMtclibErrorCode McuConfSpecSpeakerReq(const TMtId &tMt);

    //ȡ����ϯ
    EMMtclibErrorCode McuConfCancelChairmanReq(void);

    //ȡ������
    EMMtclibErrorCode McuConfCancelSpeakerCmd(void);

    //ѡ���ն�(����Ƶ)
    EMMtclibErrorCode McuConfViewMtOnlyVideoCmd(TMtId &tMt);

    //ѡ���ն�(����Ƶ)
    EMMtclibErrorCode McuConfViewMtWithAudioReq(TMtId &tMt,
                                                EmMediaType emViewType);

    //ֹͣѡ��
    EMMtclibErrorCode McuConfStopViewCmd(void);

    //�˳�����
    EMMtclibErrorCode McuConfQuitConfCmd(void);

    //��ʼ��ѯ
    EMMtclibErrorCode McuConfStartPollCmd(EmMediaType emPollType, u16 wInterval,
                                          vector<TMtId> &vctMtList);

    //��ͣ��ѯ
    EMMtclibErrorCode McuConfPausePollCmd(void);

    //�ָ���ѯ
    EMMtclibErrorCode McuConfResumePollCmd(void);

    //ֹͣ��ѯ
    EMMtclibErrorCode McuConfStopPollCmd(void);

    //���Ͷ���Ϣ
    EMMtclibErrorCode McuConfSendMsgCmd(const TMtId &tMt, LPCSTR lpszMsg,
                                        EmSMSType emType = emSMSSingleLine,
                                        u8 byRollSpeed = 3, u8 byTimes = 1);

    //�ն˾���
    EMMtclibErrorCode McuConfMuteMtCmd(const TMtId &tMt, BOOL32 bMute);

    //�ն�����
    EMMtclibErrorCode McuConfDumbMtCmd(const TMtId &tMt, BOOL32 bDumb);

    //��ʼȫ�����
    EMMtclibErrorCode McuConfStartEntireMixingReq(u8 byDepth = 10);

    //ֹͣȫ�����
    EMMtclibErrorCode McuConfStopEntireMixingReq(void);

    //��ʼ����ϳ�
    EMMtclibErrorCode McuConfStartCPReq(const TMtVMPParam &tParam);

    //�޸Ļ���ϳɲ���
    EMMtclibErrorCode McuConfEditCPParamReq(const TMtVMPParam &tParam);

    //ֹͣ����ϳ�
    EMMtclibErrorCode McuConfStopCPReq(void);

    //��ʼ��������
    EMMtclibErrorCode McuConfStartVACReq(void);

    //ֹͣ��������
    EMMtclibErrorCode McuConfStopVACReq(void);

    //������ʱ
    EMMtclibErrorCode McuConfProlongReq(u16 wMinute);

    //�����ն�״̬
    EMMtclibErrorCode McuConfGetMtStatusReq(const TMtId &tMt);

    //ǿ�ƹ㲥
    EMMtclibErrorCode McuConfStartForceBroadcastCmd(void);

    //ֹͣǿ�ƹ㲥
    EMMtclibErrorCode McuConfStopForceBroadcastCmd(void);

    //��ʼ���
    EMMtclibErrorCode McuConfStartMonitorReq(const TMtId &tMt);

    //ֹͣ���
    EMMtclibErrorCode McuConfStopMonitorCmd(const TMtId &tMt);

    ///////////////////////////////////////////////////////////////////////////////
    //  14. MC������ӿ�
    ///////////////////////////////////////////////////////////////////////////////

    //������չ
    EMMtclibErrorCode McConfExtendReq(const TDialParam &tParam);

    //����MC����
    EMMtclibErrorCode McConfAcceptCallAck(const TMtId &tMt, BOOL32 bAccept);

    //MC����ģʽ����
    EMMtclibErrorCode McConfSetModeReq(BOOL32 bEnable, EmMCMode emMode);

    //MC�滻����ϳ��ն�
    EMMtclibErrorCode McConfCPReplaceMtCmd(u8 byIndex, const TMtId &tMt);

    //MC����ϳ��Զ�����趨
    EMMtclibErrorCode McConfSetAutoCPStyleCmd(BOOL32 bAuto);

    //MC����ϳɲ����趨(���Զ�����ϳ�״̬��)
    EMMtclibErrorCode McConfSetCPParamCmd(EmInnerVMPStyle emStyle,
                                          const TMtId atMt[MAX_MC_CP_MEMBER_NUM]);

    //MCԶң�ն�
    EMMtclibErrorCode McConfControlRemoteMtReq(const TMtId &tMt);

    //MC��ʼ�ն���ѯ
    EMMtclibErrorCode McConfStartPollCmd(EmMediaType emType, u16 wInterval,
                                         const vector<CMt>& vctMtList);

    //MCֹͣ�ն���ѯ
    EMMtclibErrorCode McConfStopPollCmd(void);

    ///////////////////////////////////////////////////////////////////////////////
    //  15. �ն���������ӿ�
    ///////////////////////////////////////////////////////////////////////////////

    //��ȡ�ն�״̬
    EMMtclibErrorCode MtGetStatusReq(void);

    //�ն˸�λ
    EMMtclibErrorCode MtResetCmd(void);

    //��ʼ����
    EMMtclibErrorCode MtStartDormancyCmd(void);

    //ֹͣ����
    EMMtclibErrorCode MtStopDormancyCmd(void);

    //���ļ�����
    EMMtclibErrorCode MtTransferBigFileReq(EmMtFile emType, const u8 *pbyBuf,
                                           u32 dwSize, u16 wTimedOut = 6000);

    //�ն�ҵ���ļ�����
    EMMtclibErrorCode MtUpgradeServiceReq(LPCSTR lpszFilename);


//LIB�ڲ����ýӿ�
protected:
    //��ȡ�ȴ���Ϣ1
    inline u16 GetWaitEvent1(void) const { return m_wWaitEvent1; }

    //��ȡ�ȴ���Ϣ2
    inline u16 GetWaitEvent2(void) const { return m_wWaitEvent2; }

    //������һ����Ϣ
    EMMtclibErrorCode PostNextMsg(void);

    //ȡ����ǰ��ȡ������Ϣ
    void CancelSendMsg(void);

    //���
    void SetNull(void);

    //��������
    inline void Lock(void) { EnterCriticalSection( &m_cSect ); }

    //��������
    inline void Unlock(void) { LeaveCriticalSection( &m_cSect ); }

    //LIB������Ϣ
    EMMtclibErrorCode PostMsg(const TSendCMessage &tMsg);

    //���ն˷�����Ϣ
    EMMtclibErrorCode PostMsgToMt(const TSendCMessage &tMsg);

    //�����ն�
    void WakeupMt(u16 wEventID);

protected:
    u8                              m_abySendBuf[MAX_MSG_LEN];
    u16                             m_wWaitEvent1;
    u16                             m_wWaitEvent2;
    u16                             m_wTimerEvent;
    u32                             m_dwLibNode;
    queue<TSendCMessage>            m_queueSendMsg;

    u32                             m_dwMtNode;
    u32                             m_dwMtIID;

    HANDLE                          m_hEvent;//�˳��ȴ��¼�

private:
    CRITICAL_SECTION                m_cSect;

    friend class CMessageProcWnd;
    friend class CMtclibSsnData;
};

#endif//_MTCLIBINTERFACE_20070528_H_