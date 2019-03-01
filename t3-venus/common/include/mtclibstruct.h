/*=============================================================================
ģ   ��   ��: �ն˿���̨ҵ���ܿ�
��   ��   ��: mtclibstruct.h
�� ��  �� ��: mtclibstruct.cpp
�ļ�ʵ�ֹ���: mtclib�ϲ�ӿ�ʵ��
��        ��: ���
��        ��: V4.0  Copyright(C) 2003-2007 KDC, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2007/04/20  4.0     ���        ����
=============================================================================*/

#ifndef _MTCLIBSTRUCT_20070420_H_
#define _MTCLIBSTRUCT_20070420_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MtclibConst.h"
#include "MtMsg.h"

///////////////////////////////////////////////////////////////////////////////
//  a. UI/LIB���ýṹ
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//  1. �ն�����
///////////////////////////////////////////////////////////////////////////////
class CMTConfig
{
public:
    //���캯��
    CMTConfig();
    //��������
    virtual ~CMTConfig();

public:
    //���
    void SetNull(void);

    //�����Ƿ�����������
    inline void SetAECEnabled(BOOL32 bEnabled) { m_bIsAEC = bEnabled; }

    //�ж��Ƿ�����������
    inline BOOL32 IsAECEnabled(void) const { return m_bIsAEC; }

    //�����Ƿ��Զ�����
    inline void SetAGCEnabled(BOOL32 bEnabled) { m_bIsAGC = bEnabled; }

    //�ж��Ƿ��Զ�����
    inline BOOL32 IsAGCEnabled(void) const { return m_bIsAGC; }

    //�����Ƿ����Զ���������
    inline void SetANSEnabled(BOOL32 bEnabled) { m_bIsANS = bEnabled; }

    //�ж��Ƿ����Զ���������
    inline BOOL32 IsANSEnabled(void) const { return m_bIsANS; }

    //T2��������Ƶ����Ƿ�VIDEO
    inline void SetMainVideoToVideo(BOOL32 bEnabled)
    { m_bMainVideoToVideo = bEnabled; }

    //T2�ж�����Ƶ����Ƿ�VIDEO
    inline BOOL32 IsMainVideoToVideo(void) const { return m_bMainVideoToVideo; }
 
    //��������ͷ״̬
    inline void SetCamState(s32 nIndex, BOOL32 bState)
    {
        if (    nIndex >= 0
             && nIndex < sizeof (m_abCamState) / sizeof (m_abCamState[0]) )
        {
            m_abCamState[nIndex] = bState;
        }
    }

    //��ȡ����ͷ״̬
    inline BOOL32 GetCamState(s32 nIndex) const
    {
        if (    nIndex >= 0
             && nIndex < sizeof (m_abCamState) / sizeof (m_abCamState[0]) )
        {
            return m_abCamState[nIndex];
        }
        else
        {
            return FALSE;
        }
    }

    //���ÿ�������
    inline void SetSerialType(EmSerialType emType) { m_emSerialType = emType; }

    //��ȡ��������
    inline EmSerialType GetSerialType(void) const { return m_emSerialType; }

    //����VGA��ʾ�Ƿ��Ǳ���
    inline void SetVGAShowLocal(BOOL32 bEnabled) { m_bVGAShowLocal = bEnabled; }

    //��ȡVGA��ʾ�Ƿ��Ǳ���
    inline BOOL32 IsVGAShowLocal(void) const { return m_bVGAShowLocal; }

    //���õڶ�·��Ƶ�Ƿ������VGA
    inline void Set2ndVideoToVGA(BOOL32 bEnabled)
    { m_bSecondVideoToVGA = bEnabled; }

    //��ȡ�ڶ�·��Ƶ�Ƿ������VGA
    inline BOOL32 Is2ndVideoToVGA(void) const { return m_bSecondVideoToVGA; }

    //�����Ƿ������л������
    inline void SetEnableMonitor(BOOL32 bEnabled)
    { m_bEnableMonitor = bEnabled; }

    //��ȡ�Ƿ������л������
    inline BOOL32 IsEnableMonitor(void) const { return m_bEnableMonitor; }

    //�����Ƿ������;�̬ͼƬ
    inline void SetSendStaticPic(BOOL32 bEnabled) { m_bSendStaticPic = bEnabled; }

    //��ȡ�Ƿ������;�̬ͼƬ
    inline BOOL32 IsSendStaticPic(void) const { return m_bSendStaticPic; }

    //�����Ƿ�����DHCP
    inline void SetUseDHCP(BOOL32 bEnabled) { m_bUseDHCP = bEnabled; }

    //��ȡ�Ƿ�����DHCP
    inline BOOL32 IsUseDHCP(void) const { return m_bUseDHCP; }

    //���ú�������(������)
    inline void SetCallRate(u32 dwCallRate) { m_dwCallRate = dwCallRate; }

    //��ȡ��������(������)
    inline u32 GetCallRate(void) const { return m_dwCallRate; }

    //��������(������)
    inline void SetGateway(u32 dwNetGateway)
    { m_dwGateWay = ntohl( dwNetGateway ); }

    //��ȡ����(������)
    inline u32 GetGateway(void) const { return m_dwGateWay; }

    //����DNS������IP(������)
    inline void SetDNSIP(u32 dwNetDNSIP)
    { m_dwDNSServerIP = ntohl( dwNetDNSIP ); }

    //��ȡDNS������IP(������)
    inline u32 GetDNSIP(void) const { return m_dwDNSServerIP; }

    //����MTUֵ(������)
    inline void SetMTU(u32 dwMTU) { m_dwMTU = dwMTU; }

    //��ȡMTUֵ(������)
    inline u32 GetMTU(void) const { return m_dwMTU; }

    //����UDP��ʼ�˿�(������)
    inline void SetUDPStartPort(u16 wPort) { m_wUDPStartPort = wPort; }

    //��ȡUDP��ʼ�˿�(������)
    inline u16 GetUDPStartPort(void) const { return m_wUDPStartPort; }

    //����TCP��ʼ�˿�(������)
    inline void SetTCPStartPort(u16 wPort) { m_wTCPStartPort = wPort; }

    //��ȡTCP��ʼ�˿�(������)
    inline u16 GetTCPStartPort(void) const { return m_wTCPStartPort; }

    //���õ�ǰ��������
    inline void SetCurLanguage(EmLanguage emLan) { m_emCurLanguage = emLan; }

    //��ȡ��ǰ��������
    inline EmLanguage GetCurLanguage(void) const { return m_emCurLanguage; }

    //������˷��������
    inline void SetMicAdjust(u8 byMic) { m_byMicAdjust = byMic; }

    //��ȡ��˷��������
    inline u8 GetMicAdjust(void) const { return m_byMicAdjust; }

    //����LDAP������
    inline void SetLDAPAddr(LPCSTR lptrLDAP)
    {
        memset( m_szLDAPServer, 0, sizeof (m_szLDAPServer) );
        if ( lptrLDAP != NULL )
        {
            strncpy( m_szLDAPServer, lptrLDAP,
                     sizeof (m_szLDAPServer) - 1 );
        }
    }

    //��ȡLDAP������
    inline LPCSTR GetLDAPAddr(void) const { return m_szLDAPServer; }

    //���ñ�������
    inline void SetEncVol(u8 byVol) { m_byEncVol = byVol; }

    //��ȡ��������
    inline u8 GetEncVol(void) const { return m_byEncVol; }

    //���ý�������
    inline void SetDecVol(u8 byVol) { m_byDecVol = byVol; }

    //��ȡ��������
    inline u8 GetDecVol(void) const { return m_byDecVol; }

public:
    //��ӡ
    void Print(void);

public:
    TH323Cfg            m_tH323Cfg;                         //H.323������Ϣ
    TUserCfg            m_tUserCfg;                         //�û�����������Ϣ

    TOsdCfg             m_tOSDCfg;                          //�ն���ʾ������Ϣ

    TEthnetInfo         m_atEthnetInfo[MT_MAX_ETHNET_NUM];  //��̫��������Ϣ
    TE1Config           m_tE1Cfg;                           //E1��Ϣ����
    TSerialCfg          m_atSerialCfg[4];                   //������Ϣ����
    vector<TRouteCfg>   m_vctRouteCfg;                      //·����Ϣ����
    TPPPOECfg           m_tPPPoECfg;                        //PPPoE��Ϣ����
    TSNMPCfg            m_tNetManageCfg;                    //������Ϣ����
    TIPQoS              m_tIPQoSCfg;                        //IPQoS��Ϣ����
    TEmbedFwNatProxy    m_tEmbedFwCfg;                      //����ǽ��Ϣ����
    TNATMapAddr         m_tNatMap;                          //��̬ӳ��

    TLostPackResend     m_tRetransCfg;                      //�����ش���Ϣ����
    TStreamMedia        m_tStreamCfg;                       //��ý����Ϣ����
    TVideoParam         m_atVideoParam[2];                  //��Ƶ�����������
    TVideoParam         m_tPCVideoParam;                    //PC˫������
    TAVPriorStrategy    m_tAVPriorCfg;                      //��ѡЭ����Ϣ����
    vector<TCameraTypeInfo> m_vctCamTypeInfo;               //����ͷ��������
    TCameraCfg          m_atCameraCfg[MT_MAX_CAMERA_NUM];   //����ͷ��Ϣ����
    TVideoStandard      m_atVideoStandInput[2];             //��Ƶ������ʽ
    TVideoStandard      m_atVideoStandOutput[2];            //��Ƶ�����ʽ
    TImageAdjustParam   m_tImageAdjust;                     //ͼ�����
    TBannerInfo         m_tBannerInfo;                      //�������
    TIPTransAddr        m_tIPAddr;                          //���ڿ���ʱ��ַ
    TMonitorService     m_tMonitorService;                  //����л�ҵ������
    TDualRation         m_tDualRatio;                       //˫������
    TMtEquipmentCapset  m_tMTEquipmentCapset;               //MT�豸������
    TInnerMcCfg         m_tInnerMcCfg;                      //����MC����
    TInnerGKCfg         m_tInnerGKCfg;                      //����GK����ǽ����
    TRapidKey           m_tShortcutKey;                     //ң������ݼ�����

    TCapType            m_tCapType;                         //PCMT��ƵԴ��Ϣ

    TVgaOutCfg          m_tVGAOutCfg;                       //8010C����VGA�������

protected:
    BOOL32              m_bIsAEC;                           //�Ƿ�����������
    BOOL32              m_bIsAGC;                           //�Ƿ��Զ�����
    BOOL32              m_bIsANS;                           //�Ƿ����Զ���������

    BOOL32              m_bMainVideoToVideo;                //T2����Ƶ����Ƿ�VIDEO

    BOOL32              m_abCamState[MT_MAX_CAMERA_NUM];    //����ͷ״̬
    EmSerialType        m_emSerialType;                     //��������
    BOOL32              m_bVGAShowLocal;                    //VGA��ʾ�Ƿ��Ǳ���
    BOOL32              m_bSecondVideoToVGA;                //�ڶ�·��Ƶ�Ƿ������VGA
    BOOL32              m_bEnableMonitor;                   //�Ƿ������л������
    BOOL32              m_bSendStaticPic;                   //�Ƿ������;�̬ͼƬ
    BOOL32              m_bUseDHCP;                         //�Ƿ�����DHCP

    u32                 m_dwCallRate;                       //��������(������)
    u32                 m_dwGateWay;                        //����(������)
    u32                 m_dwDNSServerIP;                    //DNS������IP(������)
    u32                 m_dwMTU;                            //MTUֵ(������)

    u16                 m_wUDPStartPort;                    //UDP��ʼ�˿�(������)
    u16                 m_wTCPStartPort;                    //TCP��ʼ�˿�(������)

    EmLanguage          m_emCurLanguage;                    //��ǰ��������

    s8                  m_szLDAPServer[MT_MAX_LDAPSERVER_NAME_LEN]; //LDAP������
    u8                  m_byMicAdjust;                      //��˷��������

    u8                  m_byEncVol;                         //��������
    u8                  m_byDecVol;                         //��������
};

///////////////////////////////////////////////////////////////////////////////
//  2. �ն�״̬(������޹�)
///////////////////////////////////////////////////////////////////////////////
class CMtStatus
{
public:
    CMtStatus();
    virtual ~CMtStatus();

public:
    //���
    void SetNull();

    //�����Ƿ�����
    inline void SetDormancy(BOOL32 bDormancy) { m_bDormancy = bDormancy; }

    //�ж��Ƿ�����
    inline BOOL32 IsDormancy(void) const { return m_bDormancy; }

    //������������������
    inline void SetInnerSpeakerVol(EmMtLoudspeakerVal emVol)
    { m_emInnerSpeakerVol = emVol; }

    //��ȡ��������������
    inline EmMtLoudspeakerVal GetInnerSpeakerVol(void) const
    { return m_emInnerSpeakerVol; }

    //�����ն˲���ϵͳ����
    inline void SetOSType(EmMtOSType emType) { m_emMTOSType = emType; }

    //��ȡ�ն˲���ϵͳ����
    inline u8 GetOSType(void) const { return m_emMTOSType; }

    //�����ն�Ӳ���汾��
    inline void SetHardVer(u8 byHardVer) { m_byMTHardwareVersion = byHardVer; }

    //��ȡ�ն�Ӳ���汾��
    inline u8 GetHardVer(void) const { return m_byMTHardwareVersion; }

    //�����ն˲���ϵͳ�汾��
    inline void SetOSVer(LPCSTR lptrOSVer)
    {
        memset( m_szMTOSVersion, 0, sizeof (m_szMTOSVersion) );
        if ( lptrOSVer != NULL )
        {
            strncpy( m_szMTOSVersion, lptrOSVer, sizeof (m_szMTOSVersion) - 1 );
        }
    }

    //��ȡ�ն˲���ϵͳ�汾��
    inline LPCSTR GetOSVer(void) const { return m_szMTOSVersion; }

    //�����ն�����汾��
    inline void SetSoftVer(LPCSTR lptrSoftVer)
    {
        memset( m_szMTSoftwareVersion, 0, sizeof (m_szMTSoftwareVersion) );
        if ( lptrSoftVer != NULL )
        {
            strncpy( m_szMTSoftwareVersion, lptrSoftVer,
                     sizeof (m_szMTSoftwareVersion) - 1 );
        }
    }

    //��ȡ�ն�����汾��
    inline LPCSTR GetSoftVer(void) const { return m_szMTSoftwareVersion; }

    //�����ն�MAC��ַ
    inline void SetMACAddr(LPCSTR lptrMACAddr)
    {
        memset( m_szMTMac, 0, sizeof (m_szMTMac) );
        if ( lptrMACAddr != NULL )
        {
            strncpy( m_szMTMac, lptrMACAddr, sizeof (m_szMTMac) - 1 );
        }
    }

    //��ȡ�ն�MAC��ַ
    inline LPCSTR GetMACAddr(void) const { return m_szMTMac; }

    //�����Ƿ�����MC����
    inline void SetMCEnabled(BOOL32 bEnabled) { m_bUseMC = bEnabled; }

    //��ȡ�Ƿ�����MC����
    inline BOOL32 IsMCEnabled(void) const { return m_bUseMC; }

    //����MC����ģʽ
    inline void SetMCMode(EmMCMode emMode) { m_emMCMode = emMode; }

    //��ȡMC����ģʽ
    inline EmMCMode GetMCMode(void) const { return m_emMCMode; }

    //����FXO״̬
    inline void SetFXOStatus(EmFxoState emStatus) { m_emFXOStatus = emStatus; }

    //��ȡFXO״̬
    inline EmFxoState GetFXOStatus(void) const { return m_emFXOStatus; }

    //�����Ƿ�������������
    inline void SetVolumeTest(BOOL32 bTesting) { m_bVolumeTest = bTesting; }

    //��ȡ�Ƿ�������������
    inline BOOL32 IsVolumeTest(void) const { return m_bVolumeTest; }

    //�����Ƿ����ڱ���ͼ�����
    inline void SetLocalImageTest(BOOL32 bTesting)
    { m_bLocalImageTest = bTesting; }

    //��ȡ�Ƿ����ڱ���ͼ�����
    inline BOOL32 IsLocalImageTest(void) const { return m_bLocalImageTest; }

    //�����Ƿ�����Զ��ͼ�����
    inline void SetRemoteImageTest(BOOL32 bTesting)
    { m_bRemoteImageTest = bTesting; }

    //��ȡ�Ƿ�����Զ��ͼ�����
    inline BOOL32 IsRemoteImageTest(void) const { return m_bRemoteImageTest; }

    //���÷���˫��״̬
    inline void SetSendDual(BOOL32 bSendDual) { m_bSendDual = bSendDual; }

    //��ȡ����˫��״̬
    inline BOOL32 IsSendDual(void) const { return m_bSendDual; }

    //���ý���˫��״̬
    inline void SetRecvDual(BOOL32 bRecvDual) { m_bRecvDual = bRecvDual; }

    //��ȡ����˫��״̬
    inline BOOL32 IsRecvDual(void) const { return m_bRecvDual; }

    //���õ�ǰ˫������
    inline void SetCurDualType(EmMtVideoPort emCurType)
    { m_emCurDualType = emCurType; }

    //��ȡ��ǰ˫������
    inline EmMtVideoPort GetCurDualType(void) const { return m_emCurDualType; }

    //�����Ƿ�Զ�˻��ز���
    inline void SetRemoteLoopbackTest(BOOL32 bTesting)
    { m_bRemoteLoopBackTest = bTesting; }

    //��ȡ�Ƿ�Զ�˻��ز���
    inline BOOL32 IsRemoteLoopbackTest(void) { return m_bRemoteLoopBackTest; }

    //����Զ�˻��ز�������
    inline void SetRemoteLoopbackTestType(EmVideoType emType)
    { m_emRemoteLoopBackVideoType = emType; }

    //��ȡԶ�˻��ز�������
    inline EmVideoType GetRemoteLoopbackTestType(void) const
    { return m_emRemoteLoopBackVideoType; }

    //����CPUʹ����
    inline void SetCPUUsage(u8 byCPUUsage) { m_byCPUUsage = byCPUUsage; }

    //��ȡCPUʹ����
    inline u8 GetCPUUsage(void) const { return m_byCPUUsage; }

    //�����ն������ڴ��С(������)
    inline void SetPhysicMem(u32 dwMem) { m_dwPhysicMem = dwMem; }

    //��ȡ�ն������ڴ��С(������)
    inline u32 GetPhysicMem(void) const { return m_dwPhysicMem; }

    //�����ն���ʹ���ڴ��С(������)
    inline void SetUsedMem(u32 dwMem) { m_dwUsedMem = dwMem; }

    //��ȡ�ն���ʹ���ڴ��С(������)
    inline u32 GetUsedMem(void) const { return m_dwUsedMem; }

    //�����ն˿����ڴ��С(������)
    inline void SetFreeMem(u32 dwMem) { m_dwFreeMem = dwMem; }

    //��ȡ�ն˿����ڴ��С(������)
    inline u32 GetFreeMem(void) const { return m_dwFreeMem; }

    //�����Ƿ���
    inline void SetMute(BOOL32 bMute) { m_tMtStatus.bIsQuiet = bMute; }

    //�ж��Ƿ���
    inline BOOL32 IsMute(void) const { return m_tMtStatus.bIsQuiet; }

    //�����Ƿ�����
    inline void SetDumb(BOOL32 bDumb) { m_tMtStatus.bIsMute = bDumb; }

    //�ж��Ƿ�����
    inline BOOL32 IsDumb(void) const { return m_tMtStatus.bIsMute; }

    //����MIC����
    inline void SetMicVol(u8 byVol) { m_tMtStatus.byEncVol = byVol; }

    //��ȡMIC����
    inline u8 GetMicVol(void) const { return m_tMtStatus.byEncVol; }

    //��������������
    inline void SetSpeakerVol(u8 byVol) { m_tMtStatus.byDecVol = byVol; }

    //��ȡ����������
    inline u8 GetSpeakerVol(void) const { return m_tMtStatus.byDecVol; }

    //��ȡ�ն�����
    inline EmMtModel GetModel(void) const { return m_tMtStatus.emMtModel; }

    //�ж��Ƿ���VOD״̬��
    inline BOOL32 IsInVOD(void) const { return m_tMtStatus.bIsInVOD; }

public:
    //��ӡ
    void Print(void);

protected:
    BOOL32              m_bDormancy;                        //�ն��Ƿ�����

    EmMtLoudspeakerVal  m_emInnerSpeakerVol;                //��������������

    EmMtOSType          m_emMTOSType;                       //�ն˲���ϵͳ����

    u8                  m_byMTHardwareVersion;              //�ն�Ӳ���汾��
    u8                  m_abyReserved1[3];

    s8                  m_szMTOSVersion[256];               //�ն˲���ϵͳ�汾��
    s8                  m_szMTSoftwareVersion[256];         //�ն�����汾��
    s8                  m_szMTMac[256];                     //�ն�MAC��ַ

    BOOL32              m_bUseMC;                           //�Ƿ�ʹ��MC
    EmMCMode            m_emMCMode;                         //MC�Ĺ���ģʽ

    EmFxoState          m_emFXOStatus;                      //FXO״̬

    BOOL32              m_bVolumeTest;                      //�Ƿ�������������
    BOOL32              m_bLocalImageTest;                  //�Ƿ����ڱ���ͼ�����
    BOOL32              m_bRemoteImageTest;                 //�Ƿ�����Զ��ͼ�����

    BOOL32              m_bSendDual;                        //��ǰ�Ƿ���˫��
    BOOL32              m_bRecvDual;                        //��ǰ�Ƿ����˫��
    EmMtVideoPort       m_emCurDualType;                    //��ǰ˫������

    BOOL32              m_bRemoteLoopBackTest;              //�Ƿ�Զ�˻��ز���
    EmVideoType         m_emRemoteLoopBackVideoType;        //Զ�˻��ز�������

    u8                  m_byCPUUsage;                       //CPUʹ����
    u8                  m_abyReserved2[3];
    u32                 m_dwPhysicMem;                      //�ն������ڴ��С(���ֽڼ��㣬������)
    u32                 m_dwUsedMem;                        //�ն���ʹ���ڴ��С(���ֽڼ��㣬������)
    u32                 m_dwFreeMem;                        //�ն˿����ڴ��С(���ֽڼ��㣬������)

public:
    TTerStatus          m_tMtStatus;                        //�ն�״̬
    TSnapInfo           m_tSnapInfo;                        //������Ϣ

    EmVideoType         m_aaDualCap[2][MT_MAXNUM_VIDSOURCE];//˫������

    TCallInfoStatistics m_tMtStatics;                       //ͳ����Ϣ
};

namespace kdvmtc
{

    class CMt
    {
    public:
        CMt();
        CMt(u8 byMcuID, u16 wMtID, LPCSTR lptrMtAlias = NULL,
            LPCSTR lptrE164ID = NULL);
        CMt(const CMt &cMt);
        virtual ~CMt();

    public:
        //���
        void SetNull(void);

        //�ж��Ƿ�Ϊ��
        inline BOOL32 IsNull(void)
        { return ( m_byMcuId == 0 && m_wMtId == 0 ); }

        //����MCU ID
        inline void SetMcuID(u8 byMcuID) { m_byMcuId = byMcuID; }

        //��ȡMCU ID
        inline u8 GetMcuID(void) const { return m_byMcuId; }

        //����MT ID
        inline void SetMtID(u16 wMtID) { m_wMtId = wMtID; }

        //��ȡMT ID
        inline u16 GetMtID(void) const { return m_wMtId; }

        //�����ն˱���
        inline void SetMtAlias(LPCSTR lptrAlias)
        {
            memset( m_szMtAlias, 0, sizeof (m_szMtAlias) );
            if ( lptrAlias != NULL )
            {
                strncpy( m_szMtAlias, lptrAlias, sizeof (m_szMtAlias) - 1 );
            }
        }

        //��ȡ�ն˱���
        inline LPCSTR GetMtAlias(void) const { return m_szMtAlias; }

        //�����ն�E.164����
        inline void SetMtE164ID(LPCSTR lptrE164ID)
        {
            memset( m_szMtE164ID, 0, sizeof (m_szMtE164ID) );
            if ( lptrE164ID != NULL )
            {
                strncpy( m_szMtE164ID, lptrE164ID, sizeof (m_szMtE164ID) - 1 );
            }
        }

        //��ȡ�ն�E.164����
        inline LPCSTR GetMtE164ID(void) const { return m_szMtE164ID; }

        //�����Ƿ�����
        inline void SetDumb(BOOL32 bDumb) { m_byDumb = (bDumb ? 1 : 0); }

        //�ж��Ƿ�����
        inline BOOL32 IsDumb(void) const
        { return ( m_byDumb > 0 ? TRUE: FALSE ); }

        //���úϲ��ն˺�
        inline void SetID(u8 byMcuID, u16 wMtID)
        {
            m_byMcuId = byMcuID;
            m_wMtId = wMtID;
        }

        //���úϲ��ն˺�
        inline void SetID(u32 dwMtID)
        {
            m_byMcuId = HIWORD(LOBYTE(dwMtID));
            m_wMtId = LOWORD(dwMtID);
        }

        //��ȡ�ϲ��ն˺�
        inline u32 GetID(void) const
        {
            return MAKELONG(m_wMtId, MAKEWORD(m_byMcuId, 0));
        }

        //�Ƚ�
        inline BOOL32 operator==(const CMt &cMt) const
        { return ( m_byMcuId == cMt.m_byMcuId && m_wMtId == cMt.m_wMtId ); }

        //�Ƚ�
        inline BOOL32 operator==(const TMtId &tMt) const
        { return ( m_byMcuId == tMt.byMcuNo && m_wMtId == tMt.byTerNo ); }

        //�Ƚ�
        inline BOOL32 operator==(const TMtInfo &tMt) const
        { return ( m_byMcuId == tMt.tLabel.byMcuNo && m_wMtId == tMt.tLabel.byTerNo ); }

        //�Ƚ�
        inline BOOL32 operator!=(const CMt &cMt) const
        { return ( m_byMcuId != cMt.m_byMcuId || m_wMtId != cMt.m_wMtId ); }

        //�Ƚ�
        inline BOOL32 operator!=(const TMtId &tMt) const
        { return ( m_byMcuId != tMt.byMcuNo || m_wMtId != tMt.byTerNo ); }

        //�Ƚ�
        inline BOOL32 operator!=(const TMtInfo &tMt) const
        { return ( m_byMcuId != tMt.tLabel.byMcuNo || m_wMtId != tMt.tLabel.byTerNo ); }

        //��ֵ
        CMt& operator=(const CMt &cMt);

        //��ֵ
        CMt& operator=(const TMtId &tMt);

        //��ֵ
        CMt& operator=(const TMtInfo &tMt);

        //��ȡ�ϲ��ն˺�(��̬�������뱾���ڲ������޹�)
        inline static u32 GetID(u8 byMcuID, u16 wMtID)
        { return MAKELONG(wMtID, MAKEWORD(byMcuID, 0)); }

    public:
        //��ӡ
        void Print(void);

    private:
        u8  m_byMcuId;                          //MCU ID
        u8  m_byDumb;                           //����״̬(MCʱ��Ч) ����: 1; δ����: 0
        u16 m_wMtId;                            //MT ID
        s8  m_szMtAlias[MT_MAX_H323ALIAS_LEN];  //�ն˱���
        s8  m_szMtE164ID[MT_MAX_E164NUM_LEN];   //E.164����
    };

}



///////////////////////////////////////////////////////////////////////////////
//  3. �������
///////////////////////////////////////////////////////////////////////////////
class CMatrix
{
public:
    CMatrix();
    virtual ~CMatrix();

public:
    //���
    void SetNull(void);

    //���õ�ǰ�ڲ���ƵԴ
    inline void SetCurInnerVSource(EmMtVideoPort emPort)
    {
        m_emCurInnerVSource = ( emPort < emMtExternalVid ? emPort : emMtC1Vid );
    }

    //��ȡ��ǰ�ڲ���ƵԴ
    inline EmMtVideoPort GetCurInnerVSource(void) const
    { return m_emCurInnerVSource; }

    //���õ�ǰ��Ӿ���˿�
    inline void SetCurOuterPort(EmMtVideoPort emPort)
    {
        m_byCurOuterVPort = ( emPort < emMtExternalVid ? -1 : (u8)(emPort - emMtExternalVid) );
    }

    //��ȡ��ǰ��Ӿ���˿�
    inline u8 GetCurOuterPort(void) const { return m_byCurOuterVPort; }

    //���õ�ǰ��Ӿ��󷽰�
    inline void SetCurOuterScheme(u8 bySchemeNo)
    { m_byCurOuterScheme = bySchemeNo; }

    //��ȡ��ǰ��Ӿ��󷽰�
    inline u8 GetCurOuterScheme(void) const { return m_byCurOuterScheme; }

    //������Ӿ����������
    inline void SetOuterMatrixCap(u8 byCap) { m_byOuterMatrixCap = byCap; }

    //��ȡ��Ӿ����������
    inline u8 GetOuterMatrixCap(void) const { return m_byOuterMatrixCap; }

public:
    //��ӡ
    void Print(void);

protected:
    EmMtVideoPort                   m_emCurInnerVSource;    //��ǰ�ڲ���ƵԴ
    u8                              m_byCurOuterVPort;      //��ǰ��Ӿ���˿�
    u8                              m_byCurOuterScheme;     //��ǰ��Ӿ��󷽰�
    u8                              m_byOuterMatrixCap;     //��Ӿ����������
    u8                              m_byReserved1;

public:
    vector<TVideoSourceInfo>        m_vctInnerVSourceInfo;  //�ڲ���ƵԴ����Ϣ
    vector<TAVInnerMatrixScheme>    m_vctAVMatrixScheme;    //ȫ���ڲ����󷽰�

    TExternalMatrixInfo             m_tOuterMatrixInfo;     //��Ӿ�����Ϣ
    vector<TVideoSourceInfo>        m_vctOuterMatrixName;   //��Ӿ���˿���
};


///////////////////////////////////////////////////////////////////////////////
//  4. ��ز���
///////////////////////////////////////////////////////////////////////////////
typedef struct tagMtcMonitorParam
{
public:
    tagMtcMonitorParam() { SetNull(); }

    //���
    inline void SetNull(void) { memset( this, 0, sizeof (tagMtcMonitorParam) ); }

public:
    //��ӡ
    void Print(void);

public:
    EmSite              m_emSite;                           //����/Զ��
    u8                  m_abyRealPayload[2];                //��Ƶ����Ƶ����ʵ�غ�����
    u8                  m_abyDynamicPayload[2];             //��Ƶ����Ƶ�Ķ�̬�غ�����
    TEncryptKey         m_atEncryptKey[2];                  //��Ƶ����Ƶ����Կ
} TMtcMonitorParam;

class CMonitorParam
{
public:
    CMonitorParam();
    virtual ~CMonitorParam();

public:
    //���
    void SetNull(void);

public:
    //��ӡ
    void Print(void);

public:
    TMtcMonitorParam        m_atMonitorParam[2];            //����/Զ�� ��ز���
    TVideoEncodeParameter   m_tPCDualParam;                 //PC˫������
    u8                      m_byPCDynamicPayload;           //PC˫����̬�غ�
    TEncryptKey             m_tPCDualEncryptKey;            //PC˫����Կ
    TIPTransAddr            m_tRTPSendAddr;                 //RTP���͵�ַ
    TIPTransAddr            m_tRTCPSendAddr;                //RTCP���͵�ַ
};


///////////////////////////////////////////////////////////////////////////////
//  5. VOD����
///////////////////////////////////////////////////////////////////////////////
class CVODParam
{
public:
    CVODParam();
    virtual ~CVODParam();

public:
    //���
    void SetNull(void);

    //����VOD�㲥״̬
    inline void SetVODState(EmVODState emState) { m_emVODState = emState; }

    //��ȡVOD�㲥״̬
    inline EmVODState GetVODState(void) const { return m_emVODState; }

    //���õ�ǰ�ļ�����״̬
    inline void SetCurFileState(EmAction emState) { m_emCurFileState = emState; }

    //��ȡ��ǰ�ļ�����״̬
    inline EmAction GetCurFileState(void) const { return m_emCurFileState; }

    //���ò�����ʱ��(������)
    inline void SetDuration(u32 dwDuration) { m_dwDuration = dwDuration; }

    //��ȡ������ʱ��(������)
    inline u32 GetDuration(void) const { return m_dwDuration; }

    //�����Ѳ���ʱ��(������)
    inline void SetProgress(u32 dwProgress) { m_dwProgress = dwProgress; }

    //��ȡ�Ѳ���ʱ��(������)
    inline u32 GetProgress(void) const { return m_dwProgress; }

public:
    //��ӡ
    void Print(void);

protected:
    EmVODState                      m_emVODState;           //VOD�㲥״̬
    EmAction                        m_emCurFileState;       //��ǰ�ļ��Ĳ��ŵ�״̬
    u32                             m_dwDuration;           //������ʱ��(���룬������)
    u32                             m_dwProgress;           //�Ѳ���ʱ��(���룬������)

public:
    vector<TVODFileNameInfo>        m_vctCurDirFileList;    //��ǰĿ¼�µ������ļ�����Ŀ¼
    TVODFileInfo                    m_tCurSelectFile;       //ָ���ļ�����ϸ��Ϣ
    TVODFileNameInfo                m_tCurSelectFileName;   //ָ���ļ���������Ϣ
};


///////////////////////////////////////////////////////////////////////////////
//  6. ��Ե����״̬
///////////////////////////////////////////////////////////////////////////////
class CP2PConfStatus
{
public:
    CP2PConfStatus();
    virtual ~CP2PConfStatus();

public:
    //���
    void SetNull(void);

    //���õ�Ե����״̬
    inline void SetInConf(BOOL32 bInConf) { m_bInConf = bInConf; }

    //��ȡ��Ե����״̬
    inline BOOL32 IsInConf(void) const { return m_bInConf; }

    //���ú���״̬
    inline void SetInCalling(BOOL32 bInCalling) { m_bInCalling = bInCalling; }

    //��ȡ����״̬
    inline BOOL32 IsInCalling(void) const { return m_bInCalling; }

    //�����Ƿ����ն�
    inline void SetMaster(BOOL32 bMaster) { m_bMaster = bMaster; }

    //�ж��Ƿ����ն�
    inline BOOL32 IsMaster(void) const { return m_bMaster; }

    //��������
    inline void SetLocalMt(const kdvmtc::CMt &cMt) { m_cMtLocal = cMt; }

    //��ȡ����
    inline const kdvmtc::CMt& GetLocalMt(void) const { return m_cMtLocal; }

    //���öԶ�
    inline void SetRemoteMt(const kdvmtc::CMt &cMt) { m_cMtRemote = cMt; }

    //��ȡ�Զ�
    inline const kdvmtc::CMt& GetRemoteMt(void) const { return m_cMtRemote; }

    //���ú��в���
    inline void SetCallParam(const TDialParam &tParam) { m_tCallParam = tParam; }

    //��ȡ���в���
    inline const TDialParam& GetCallParam(void) const { return m_tCallParam; }

public:
    //��ӡ
    void Print(void);

protected:
    BOOL32      m_bInConf;      //�Ƿ��ڵ�Ե������
    BOOL32      m_bInCalling;   //�Ƿ��ں�����
    BOOL32      m_bMaster;      //(����)�Ƿ����ն�

    kdvmtc::CMt m_cMtLocal;     //����
    kdvmtc::CMt m_cMtRemote;    //�Զ�
    TDialParam  m_tCallParam;   //���в���
};


///////////////////////////////////////////////////////////////////////////////
//  7. ������״̬
///////////////////////////////////////////////////////////////////////////////

//MCU�����б�
typedef struct tagJoinConfList
{
public:
    tagJoinConfList() { memset( this, 0, sizeof (tagJoinConfList) ); }

public:
    //���
    void SetNull(void) { memset( this, 0, sizeof (tagJoinConfList) ); }

    //���û����
    void SetConfID(LPCSTR lptrConfID);

    //��ȡ�����
    inline const u8* GetConfID(void) const { return m_abyConfID; }

    //��ȡ������ַ���
    void GetConfIdString(LPSTR lptrConfId, s32 nBufLen) const;

    //���û�����
    inline void SetConfName(LPCSTR lptrConfName)
    {
        memset( m_szConfName, 0, sizeof (m_szConfName) );
        if ( lptrConfName != NULL )
        {
            strncpy( m_szConfName, lptrConfName, sizeof (m_szConfName) - 1 );
        }
    }

    //��ȡ������
    inline LPCSTR GetConfName(void) const { return m_szConfName; }

public:
    //��ӡ
    void Print(void);

protected:
    u8  m_abyConfID[MT_MAX_CONF_ID_LEN];    //Conf ID
    s8  m_szConfName[MT_MAX_CONF_NAME_LEN]; //������
} TJoinConfList;

//������״̬
class CMultiConfStatus : public TMtConfInfo
{
public:
    CMultiConfStatus();
    virtual ~CMultiConfStatus();
    CMultiConfStatus(const CMultiConfStatus &cConf);

public:
    //���
    void SetNull(void);

    //���������, ���µĻ�����Ϣ��������
    const CMultiConfStatus& operator+=(const TMtConfInfo &tInfo);

    //��ֵ���������
    const CMultiConfStatus& operator=(const CMultiConfStatus &cConf);

    //��ȡ��ϯ�ն�
    const kdvmtc::CMt& GetChairman(void) const;

    //��ȡ�����ն�
    const kdvmtc::CMt& GetSpeaker(void) const;

    //��ȡ��ѯ�ն��б�
    BOOL32 GetPollMtList(vector<kdvmtc::CMt> &vctMtList) const;

    //��ȡ�ն�
    const kdvmtc::CMt& GetMt(const TMtId &tMt) const;

    //��ȡ�ն�
    const kdvmtc::CMt& GetMt(const TMtInfo &tMt) const;

    //��ȡ�ն�
    const kdvmtc::CMt& GetMt(u8 byMcuID, u16 wMtID) const;

    //��ȡ�ն�
    const kdvmtc::CMt& GetMt(u32 dwID) const;

    //�����ն�
    BOOL32 SetMt(const kdvmtc::CMt &cMt);

    //�����Ƿ��ڶ�������
    inline void SetInConf(BOOL32 bInConf) { m_bInConf = bInConf; }

    //�ж��Ƿ��ڶ�������
    inline BOOL32 IsInConf(void) const { return m_bInConf; }

    //�����Ƿ��������
    inline void SetApplyMixing(BOOL32 bApply) { m_bApplyMixing = bApply; }

    //�ж��Ƿ��������
    inline BOOL32 IsApplyMixing(void) const { return m_bApplyMixing; }

    //�����Ƿ��ȡ�˻�����Ϣ
    inline void SetGetConfInfo(BOOL32 bGet) { m_bGetConfInfo = bGet; }

    //�ж��Ƿ��ȡ�˻�����Ϣ
    inline BOOL32 IsGetConfInfo(void) const { return m_bGetConfInfo; }

    //���û����Ƿ����
    inline void SetConfEncrypted(BOOL32 bEncrypted)
    { m_bConfEncrypted = bEncrypted; }

    //�жϻ����Ƿ����
    inline BOOL32 IsConfEncrypted(void) const { return m_bConfEncrypted; }

    //���õ�ǰ��ƵԴ�ն�
    inline void SetVideoSource(const TMtId &tMt) { m_tVideoSrc = tMt; }

    //��ȡ��ǰ��ƵԴ�ն�
    const kdvmtc::CMt& GetVideoSource(void) const;

    //���û����ӳ�ʱ��
    inline void SetDelayTime(u16 wTime) { m_wDelayTime = wTime; }

    //��ȡ�����ӳ�ʱ��
    inline u16 GetDelayTime(void) const { return m_wDelayTime; }

//MC�ӿ�
public:
    //�����Ƿ񼤻�MC����
    inline void SetMCActivate(BOOL32 bActivate) { m_bMCActivate = bActivate; }

    //�ж��Ƿ񼤻�MC����
    inline BOOL32 IsMCActivate(void) const { return m_bMCActivate; }

    //���õ�ǰMCģʽ
    inline void SetMCMode(EmMCMode emMode) { m_emMCMode = emMode; }

    //��ȡ��ǰMCģʽ
    inline EmMCMode GetMCMode(void) const { return m_emMCMode; }

    //����MC�ڵ�ǰ�������Ƿ����
    inline void SetMCEnabledInConf(BOOL32 bEnabled)
    { m_bMCEnabledInConf = bEnabled; }

    //�ж�MC�ڵ�ǰ�������Ƿ����
    inline BOOL32 IsMCEnabledInConf(void) const { return m_bMCEnabledInConf; }

    //����MC�Ƿ��Զ�����ϳ�
    inline void SetMCAutoCP(BOOL32 bAutoCP) { m_bMCAutoCP = bAutoCP; }

    //�ж�MC�Ƿ��Զ�����ϳ�
    inline BOOL32 IsMCAutoCP(void) const { return m_bMCAutoCP; }

    //����MCʱ��ѯ��Ϣ
    inline void SetMCPollInfo(const TMtPollInfo &tInfo)
    { m_tMCPollInfo = tInfo; }

    //��ȡMCʱ��ѯ��Ϣ
    inline const TMtPollInfo& GetMCPollInfo(void) const
    { return m_tMCPollInfo; }

    //����MC����ϳɷ��
    inline void SetMCCPStyle(EmInnerVMPStyle emStyle)
    { m_emMCCPStyle = emStyle; }

    //��ȡMC����ϳɷ��
    inline EmInnerVMPStyle GetMCCPStyle(void) const { return m_emMCCPStyle; }

    //����MCԶң�ն�
    inline void SetMCRemoteControlMt(const TMtId &tMt)
    { m_tMCRemoteControlMt = tMt; }

    //��ȡMCԶң�ն�
    const kdvmtc::CMt& GetMCRemoteControlMt(void) const;

//��ӡ
public:
    //��ӡ
    void Print(void);

public:
    vector<kdvmtc::CMt>         m_vctMtList;        //����ն��б�
    vector<kdvmtc::CMt>         m_vctApplyChairman; //������ϯ���ն��б�
    vector<kdvmtc::CMt>         m_vctApplySpeaker;  //���뷢�Ե��ն��б�
    vector<kdvmtc::CMt>         m_vctApplyMixing;   //����������ն��б�
    vector<TJoinConfList>       m_vctJoinConfList;  //��ѡ���������б�

protected:
    BOOL32                      m_bInConf;          //�Ƿ��ڶ�������
    BOOL32                      m_bApplyMixing;     //�Ƿ��������
    BOOL32                      m_bGetConfInfo;     //�Ƿ��ȡ�˻�����Ϣ
    BOOL32                      m_bConfEncrypted;   //�����Ƿ����

    TMtId                       m_tVideoSrc;        //��ǰ��ƵԴ�ն�
    u16                         m_wDelayTime;       //�����ӳ�ʱ��(�ն˲�����¼������MTC����ָ����¼ʱ��)

    BOOL32                      m_bMCActivate;      //MC�Ƿ񼤻�
    EmMCMode                    m_emMCMode;         //��ǰMCģʽ
    BOOL32                      m_bMCEnabledInConf; //MC�ڵ�ǰ�������Ƿ����
    TMtPollInfo                 m_tMCPollInfo;      //MCʱ��ѯ��Ϣ
    BOOL32                      m_bMCAutoCP;        //MC�Ƿ��Զ�����ϳ�
    EmInnerVMPStyle             m_emMCCPStyle;      //MC����ϳɷ��

public:
    TMtId                       m_atMCCPMember[6];  //MC����ϳɳ�Ա

protected:
    TMtId                       m_tMCRemoteControlMt;   //MCԶң�ն�

private:
    static kdvmtc::CMt          s_cNullMt;
};

///////////////////////////////////////////////////////////////////////////////
//  8. ����淢����Ϣ�Ľṹ
///////////////////////////////////////////////////////////////////////////////

//���͸��ϲ����Ϣ�ṹ������Ϣ��WPARAM��ָ��˽ṹ��ָ��
typedef struct tagMtclibParam
{
    tagMtclibParam() : m_pbyMsgBody(NULL), m_nMsgBodySize(0),
                       m_dwErrorCode(0) {}

    u8      *m_pbyMsgBody;          //��Ϣ��
    s32     m_nMsgBodySize;         //��Ϣ�峤��
    BOOL32  m_bTimeout;             //�Ƿ�ʱ
    u32     m_dwErrorCode;          //������
    u16     m_wTimeout;             //��ʱ�¼�
} TMtclibParam;


///////////////////////////////////////////////////////////////////////////////
//  b. LIB�ڲ�ʹ�ýṹ
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//  1. ��Ϣ�������װ�����ڷ�����Ϣ�洢����
///////////////////////////////////////////////////////////////////////////////
typedef struct tagSendCMessage
{
public:
    tagSendCMessage();

    tagSendCMessage(const tagSendCMessage &tMsg);

    //���
    void SetNull(void);

    //������Ϣ����
    inline void SetMsgType(EMSendMsgType emType) { m_enumMsgType = emType; }

    //��ȡ��Ϣ����
    inline EMSendMsgType GetMsgType(void) const { return m_enumMsgType; }

    //���öԶ˽ڵ�
    inline void SetDstNode(u32 dwDstNode) { m_dwDstNode = dwDstNode; }

    //��ȡ�Զ˽ڵ�
    inline u32 GetDstNode(void) const { return m_dwDstNode; }

    //���öԶ�IID
    inline void SetDstIID(u32 dwDstIID) { m_dwDstIID = dwDstIID; }

    //��ȡ�Զ�IID
    inline u32 GetDstIID(void) const { return m_dwDstIID; }

    //���ó�ʱʱ��
    inline void SetTimeout(s32 nTimeout) { m_nTimeout = nTimeout; }

    //��ȡ��ʱʱ��
    inline s32 GetTimeout(void) const { return m_nTimeout; }

    //�����Ƿ�������
    inline void SetCancelEnabled(BOOL32 bEnable) { m_bCancelEnabled = bEnable; }

    //�ж��Ƿ�������
    inline BOOL32 IsCancelEnabled(void) const { return m_bCancelEnabled; }

    //���÷����¼�
    inline void SetEvent(u16 wEvent) { m_wEvent = wEvent; }

    //��ȡ�����¼�
    inline u16 GetEvent(void) const { return m_wEvent; }

    //���õ�һ�ȴ��¼�
    inline void SetWaitEvent1(u16 wEvent) { m_wWaitEvent1 = wEvent; }

    //��ȡ��һ�ȴ��¼�
    inline u16 GetWaitEvent1(void) const { return m_wWaitEvent1; }

    //���õڶ��ȴ��¼�
    inline void SetWaitEvent2(u16 wEvent) { m_wWaitEvent2 = wEvent; }

    //��ȡ�ڶ��ȴ��¼�
    inline u16 GetWaitEvent2(void) const { return m_wWaitEvent2; }

    //������Ϣ��
    void SetMsgBody(u8 *pbyMsg = NULL, u16 wLen = 0);

    //�����Ϣ��
    void CatMsgBody(u8 *pbyMsg, u16 wLen);

    //�����Ϣ��
    inline void ClearMsgBody(void)
    {
        memset( m_abyMsg, 0, sizeof (m_abyMsg) );
        m_wMsgLen = 0;
    }

    //��ȡ��Ϣ��
    inline const void* GetMsgBody(void) const { return m_abyMsg; }

    //��ȡ��Ϣ�峤��
    inline u16 GetBodyLen(void) const { return m_wMsgLen; }

protected:
    EMSendMsgType   m_enumMsgType;
    u32             m_dwDstNode;
    u32             m_dwDstIID;
    s32             m_nTimeout;
    BOOL32          m_bCancelEnabled;
    u16             m_wEvent;
    u16             m_wWaitEvent1;
    u16             m_wWaitEvent2;
    u16             m_wMsgLen;
    u8              m_abyMsg[MAX_MSG_LEN - 28];
} TSendCMessage;


#endif//_MTCLIBSTRUCT_20070420_H_
