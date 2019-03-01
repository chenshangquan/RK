/*=============================================================================
ģ   ��   ��: �ն˿���̨ҵ���ܿ�
��   ��   ��: evmtclib.h
�� ��  �� ��: ��
�ļ�ʵ�ֹ���: mtclib ��Ϣ����
��        ��: ���
��        ��: V4.0  Copyright(C) 2003-2007 Kedacom, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2007/05/31  4.0     ���        ����
=============================================================================*/

#ifndef _EVMTCLIB_20070531_H_
#define _EVMTCLIB_20070531_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


///////////////////////////////////////////////////////////////////////////////
//  a. ����淢�͵���Ϣ
///////////////////////////////////////////////////////////////////////////////
//1. ����
    //���ӳɹ�����Ϣ�壺u32(�ն�IP��ַ��������)
    OSPEVENT( MTCLIB_DISP_CONNECT_ACK,                  MTCLIB_MSG_BGN );
    //����ʧ�ܣ���Ϣ�壺u32(�ն�IP��ַ��������)
    OSPEVENT( MTCLIB_DISP_CONNECT_NACK,                 MTCLIB_MSG_BGN + 1 );


//2. VOD��Ϣ
    //��¼�ɹ�����Ϣ�壺EmVODState(ע����ev_VODStateInd�����ֶ���)
    OSPEVENT( MTCLIB_DISP_VOD_LOGIN_ACK,                MTCLIB_MSG_BGN + 10 );
    //��¼ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_VOD_LOGIN_NACK,               MTCLIB_MSG_BGN + 11 );

    //�˳��ɹ�����Ϣ�壺EmVODState(ע����ev_VODStateInd�����ֶ���)
    OSPEVENT( MTCLIB_DISP_VOD_LOGOUT_ACK,               MTCLIB_MSG_BGN + 12 );
    //�˳�ʧ��,��Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_VOD_LOGOUT_NACK,              MTCLIB_MSG_BGN + 13 );

    //��ȡ�ļ��б�ɹ�����Ϣ�壺TVODFile[]
    OSPEVENT( MTCLIB_DISP_VOD_GETFILELIST_ACK,          MTCLIB_MSG_BGN + 14 );
    //��ȡ�ļ��б�ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_VOD_GETFILELIST_NACK,         MTCLIB_MSG_BGN + 15 );

    //��ȡ�ļ���Ϣ�ɹ�����Ϣ�壺TVODFile
    OSPEVENT( MTCLIB_DISP_VOD_GETFILEINFO_ACK,          MTCLIB_MSG_BGN + 16 );
    //��ȡ�ļ���Ϣʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_VOD_GETFILEINFO_NACK,         MTCLIB_MSG_BGN + 17 );

    //�����ļ��ɹ�����Ϣ�壺EmVODState(ע����ev_VODStateInd�����ֶ���)
    OSPEVENT( MTCLIB_DISP_VOD_PLAYFILE_ACK,             MTCLIB_MSG_BGN + 18 );
    //�����ļ�ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_VOD_PLAYFILE_NACK,            MTCLIB_MSG_BGN + 19 );

    //��ͣ���ųɹ�����Ϣ�壺EmVODState(ע����ev_VODStateInd�����ֶ���)
    OSPEVENT( MTCLIB_DISP_VOD_PAUSEFILE_ACK,            MTCLIB_MSG_BGN + 20 );
    //��ͣ����ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_VOD_PAUSEFILE_NACK,           MTCLIB_MSG_BGN + 21 );

    //�ָ����ųɹ�����Ϣ�壺EmVODState(ע����ev_VODStateInd�����ֶ���)
    OSPEVENT( MTCLIB_DISP_VOD_RESUMEFILE_ACK,           MTCLIB_MSG_BGN + 22 );
    //��ͣ����ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_VOD_RESUMEFILE_NACK,          MTCLIB_MSG_BGN + 23 );

    //ֹͣ���ųɹ�����Ϣ�壺EmVODState(ע����ev_VODStateInd�����ֶ���)
    OSPEVENT( MTCLIB_DISP_VOD_STOPFILE_ACK,             MTCLIB_MSG_BGN + 24 );
    //ֹͣ����ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_VOD_STOPFILE_NACK,            MTCLIB_MSG_BGN + 25 );

    //VOD״̬֪ͨ����Ϣ�壺EmVODState(ע������ѷ���ACK�����ٷ��͸���Ϣ)
    OSPEVENT( MTCLIB_DISP_VOD_STATE_NOTIF,              MTCLIB_MSG_BGN + 26 );
    //���Ž���֪ͨ����Ϣ�壺u32(��ʱ����������) + u32(�Ѳ���ʱ����������)
    OSPEVENT( MTCLIB_DISP_VOD_PROGRESS_NOTIF,           MTCLIB_MSG_BGN + 27 );


//3. ������Ϣ
    //��ȡ���о��󷽰��ɹ�����Ϣ�壺u8(������) + TAVInnerMatrixScheme[]
    OSPEVENT( MTCLIB_DISP_MATRIX_GETALLINNERSCHEME_ACK, MTCLIB_MSG_BGN + 35 );
    //��ȡ���о��󷽰�ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MATRIX_GETALLINNERSCHEME_NACK,MTCLIB_MSG_BGN + 36 );

    //��ȡָ�����󷽰��ɹ�����Ϣ�壺TAVInnerMatrixScheme
    OSPEVENT( MTCLIB_DISP_MATRIX_GETINNERSCHEME_ACK,    MTCLIB_MSG_BGN + 37 );
    //��ȡָ�����󷽰�ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MATRIX_GETINNERSCHEME_NACK,   MTCLIB_MSG_BGN + 38 );

    //������󷽰��ɹ�����Ϣ�壺TAVInnerMatrixScheme
    OSPEVENT( MTCLIB_DISP_MATRIX_SAVEINNERSCHEME_ACK,   MTCLIB_MSG_BGN + 39 );
    //������󷽰�ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MATRIX_SAVEINNERSCHEME_NACK,  MTCLIB_MSG_BGN + 40 );
    //���󷽰����֪ͨ����Ϣ�壺TAVInnerMatrixScheme
    OSPEVENT( MTCLIB_DISP_MATRIX_INNERSCHEME_NOTIF,     MTCLIB_MSG_BGN + 41 );

    //���õ�ǰ���󷽰��ɹ�����Ϣ�壺u8(��������)
    OSPEVENT( MTCLIB_DISP_MATRIX_SETCURSCHEME_ACK,      MTCLIB_MSG_BGN + 42 );
    //���õ�ǰ���󷽰�ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MATRIX_SETCURSCHEME_NACK,     MTCLIB_MSG_BGN + 43 );
    //��ǰ���󷽰����֪ͨ����Ϣ�壺u8(��������)
    //(ע��ev_InnerMatrixSetCurSchemeInd��ev_InnerMatrixCurSchemeInd������Ϣ�Ĵ���)
    OSPEVENT( MTCLIB_DISP_MATRIX_CURSCHEME_NOTIF,       MTCLIB_MSG_BGN + 44 );

    //��ȡ��ǰ���󷽰��ɹ�����Ϣ�壺u8(��������)
    OSPEVENT( MTCLIB_DISP_MATRIX_GETCURSCHEME_ACK,      MTCLIB_MSG_BGN + 45 );
    //��ȡ��ǰ���󷽰�ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MATRIX_GETCURSCHEME_NACK,     MTCLIB_MSG_BGN + 46 );

    //��ǰ��ƵԴ�˿�֪ͨ����Ϣ�壺EmVideoType + EmMtVideoPort
    OSPEVENT( MTCLIB_DISP_MATRIX_CURVIDEOSOURCE_NOTIF,  MTCLIB_MSG_BGN + 50 );
    //��ǰ��ǰ��ƵԴ(����/Զ��)֪ͨ����Ϣ�壺EmSite
    OSPEVENT( MTCLIB_DISP_MATRIX_CURVIDEOSITE_NOTIF,    MTCLIB_MSG_BGN + 51 );
    //��ƵԴ����֪ͨ(�������ú����)����Ϣ�壺TVideoSourceInfo
    OSPEVENT( MTCLIB_DISP_MATRIX_CURVIDEOSOURCENAME_NOTIF,  MTCLIB_MSG_BGN + 52 );

    //��ȡ��Ӿ�����Ϣ�ɹ�����Ϣ�壺TExternalMatrixInfo
    OSPEVENT( MTCLIB_DISP_MATRIX_GETOUTERINFO_ACK,      MTCLIB_MSG_BGN + 60 );
    //��ȡ��Ӿ�����Ϣʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MATRIX_GETOUTERINFO_NACK,     MTCLIB_MSG_BGN + 61 );
    //��Ӿ�����Ϣ֪ͨ����Ϣ�壺TExternalMatrixInfo
    OSPEVENT( MTCLIB_DISP_MATRIX_OUTERINFO_NOTIF,       MTCLIB_MSG_BGN + 62 );

    //������Ӿ�����ƵԴ�ɹ�����Ϣ�壺TVideoSourceInfo
    OSPEVENT( MTCLIB_DISP_MATRIX_SETOUTERVIDEOSOURCE_ACK,   MTCLIB_MSG_BGN + 63 );
    //������Ӿ�����ƵԴʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MATRIX_SETOUTERVIDEOSOURCE_NACK,  MTCLIB_MSG_BGN + 64 );

    //��ȡ��Ӿ�����ƵԴ�ɹ�����Ϣ�壺TVideoSourceInfo[]
    OSPEVENT( MTCLIB_DISP_MATRIX_GETOUTERVIDEOSOURCE_ACK,   MTCLIB_MSG_BGN + 65 );
    //��ȡ��Ӿ�����ƵԴʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MATRIX_GETOUTERVIDEOSOURCE_NACK,  MTCLIB_MSG_BGN + 66 );
    //������ƵԴ��Ϣ֪ͨ����Ϣ�壺TVideoSourceInfo[]
    OSPEVENT( MTCLIB_DISP_MATRIX_ALLVIDEOSOURCEINFO_NOTIF,  MTCLIB_MSG_BGN + 67 );


//4. ������Ϣ
    //H.323����֪ͨ����Ϣ�壺TH323Cfg
    OSPEVENT( MTCLIB_DISP_CONFIG_H323_NOTIF,            MTCLIB_MSG_BGN + 90 );
    //�û�����֪ͨ����Ϣ�壺TUserCfg
    OSPEVENT( MTCLIB_DISP_CONFIG_USER_NOTIF,            MTCLIB_MSG_BGN + 91 );
    //OSD����֪ͨ����Ϣ�壺TOsdCfg
    OSPEVENT( MTCLIB_DISP_CONFIG_OSD_NOTIF,             MTCLIB_MSG_BGN + 92 );
    //��̫������֪ͨ����Ϣ�壺u8(��̫������  0 - eth0 ) + TEthnetInfo
    OSPEVENT( MTCLIB_DISP_CONFIG_ETHNET_NOTIF,          MTCLIB_MSG_BGN + 93 );
    //E1����֪ͨ����Ϣ�壺TE1Config
    OSPEVENT( MTCLIB_DISP_CONFIG_E1_NOTIF,              MTCLIB_MSG_BGN + 94 );
    //������Ϣ����֪ͨ����Ϣ�壺EmSerialType + TSerialCfg
    OSPEVENT( MTCLIB_DISP_CONFIG_SERIAL_NOTIF,          MTCLIB_MSG_BGN + 95 );
    //·������֪ͨ����Ϣ�壺TRouteCfg[MT_MAX_ROUTE_NUM]
    OSPEVENT( MTCLIB_DISP_CONFIG_ROUTE_NOTIF,           MTCLIB_MSG_BGN + 100 );
    //PPPoE����֪ͨ����Ϣ�壺TPPPOECfg
    OSPEVENT( MTCLIB_DISP_CONFIG_PPPOE_NOTIF,           MTCLIB_MSG_BGN + 101 );
    //��������֪ͨ����Ϣ�壺TSNMPCfg
    OSPEVENT( MTCLIB_DISP_CONFIG_NETMANAGEMENT_NOTIF,   MTCLIB_MSG_BGN + 102 );
    //IPQoS����֪ͨ����Ϣ�壺TIPQos
    OSPEVENT( MTCLIB_DISP_CONFIG_IPQOS_NOTIF,           MTCLIB_MSG_BGN + 103 );
    //����ǽ����֪ͨ����Ϣ�壺TEmbedFwNatProxy
    OSPEVENT( MTCLIB_DISP_CONFIG_EMBEDFIREWALL_NOTIF,   MTCLIB_MSG_BGN + 104 );
    //��̬ӳ������֪ͨ����Ϣ�壺TNATMapAddr
    OSPEVENT( MTCLIB_DISP_CONFIG_NATMAP_NOTIF,          MTCLIB_MSG_BGN + 105 );
    //�ش�����֪ͨ����Ϣ�壺TLostPackResend
    OSPEVENT( MTCLIB_DISP_CONFIG_RETRANSFER_NOTIF,      MTCLIB_MSG_BGN + 110 );
    //��ý������֪ͨ����Ϣ�壺TStreamMedia
    OSPEVENT( MTCLIB_DISP_CONFIG_STREAM_NOTIF,          MTCLIB_MSG_BGN + 111 );
    //��Ƶ�������֪ͨ����Ϣ�壺EmVideoType + TVideoEncodeParameter
    OSPEVENT( MTCLIB_DISP_CONFIG_VIDEOPARAM_NOTIF,      MTCLIB_MSG_BGN + 112 );
    //PC˫������֪ͨ����Ϣ�壺TVideoParam
    OSPEVENT( MTCLIB_DISP_CONFIG_PCVIDEOPARAM_NOTIF,    MTCLIB_MSG_BGN + 113 );
    //��ѡЭ������֪ͨ����Ϣ�壺TAVPriorStrategy
    OSPEVENT( MTCLIB_DISP_CONFIG_AVPRIOR_NOTIF,         MTCLIB_MSG_BGN + 114 );
    //����ͷ����֪ͨ����Ϣ�壺u8(����ͷ������ 1-6) + TCameraCfg
    OSPEVENT( MTCLIB_DISP_CONFIG_CAMERA_NOTIF,          MTCLIB_MSG_BGN + 115 );
    //��Ƶ��ʽ����֪ͨ����Ϣ�壺TVideoStandard
    OSPEVENT( MTCLIB_DISP_CONFIG_VIDEOSTANDARD_NOTIF,   MTCLIB_MSG_BGN + 116 );
    //ͼ���������֪ͨ����Ϣ�壺TImageAdjustParam
    OSPEVENT( MTCLIB_DISP_CONFIG_IMAGEADJUST_NOTIF,     MTCLIB_MSG_BGN + 117 );
    //�������֪ͨ����Ϣ�壺TBannerInfo
    OSPEVENT( MTCLIB_DISP_CONFIG_BANNERINFO_NOTIF,      MTCLIB_MSG_BGN + 118 );
    //���ڿ�������֪ͨ����Ϣ�壺EmSerialType + TIPTransAddr
    OSPEVENT( MTCLIB_DISP_CONFIG_SERIALCTRL_NOTIF,      MTCLIB_MSG_BGN + 119 );
    //����л�ҵ������֪ͨ����Ϣ�壺TMonitorService
    OSPEVENT( MTCLIB_DISP_CONFIG_MONITORSERVICE_NOTIF,  MTCLIB_MSG_BGN + 120 );
    //˫������֪ͨ����Ϣ�壺TDualRation
    OSPEVENT( MTCLIB_DISP_CONFIG_DUALRATIO_NOTIF,       MTCLIB_MSG_BGN + 125 );
    //����MC����֪ͨ����Ϣ�壺TInnerMcCfg
    OSPEVENT( MTCLIB_DISP_CONFIG_INNERMC_NOTIF,         MTCLIB_MSG_BGN + 126 );
    //6610E����GK����֪ͨ����Ϣ�壺TInnerGKCfg
    OSPEVENT( MTCLIB_DISP_CONFIG_INNERGK_NOTIF,         MTCLIB_MSG_BGN + 127 );
    //ң������ݼ�����֪ͨ����Ϣ�壺TRapidKey
    OSPEVENT( MTCLIB_DISP_CONFIG_SHORTCUTKEY_NOTIF,     MTCLIB_MSG_BGN + 128 );
    //PCMT��ƵԴ֪ͨ����Ϣ�壺TCapType
    OSPEVENT( MTCLIB_DISP_CONFIG_PCMTVIDEOSOURCE_NOTIF, MTCLIB_MSG_BGN + 129 );
    //8010C VGA�������֪ͨ����Ϣ�壺TVgaOutCfg
    OSPEVENT( MTCLIB_DISP_CONFIG_VGAOUT_NOTIF,          MTCLIB_MSG_BGN + 130 );
    //������������֪ͨ����Ϣ�壺BOOL32(TRUE = ���� FALSE = �ر�)
    OSPEVENT( MTCLIB_DISP_CONFIG_AEC_NOTIF,             MTCLIB_MSG_BGN + 135 );
    //�Զ���������֪ͨ����Ϣ�壺BOOL32(TRUE = ���� FALSE = �ر�)
    OSPEVENT( MTCLIB_DISP_CONFIG_AGC_NOTIF,             MTCLIB_MSG_BGN + 136 );
    //�Զ�������������֪ͨ����Ϣ�壺BOOL32(TRUE = ���� FALSE = �ر�)
    OSPEVENT( MTCLIB_DISP_CONFIG_ANS_NOTIF,             MTCLIB_MSG_BGN + 137 );
    //����Ƶ�������֪ͨ����Ϣ�壺BOOL32(TRUE��ʾ�����Video)
    OSPEVENT( MTCLIB_DISP_CONFIG_MAINVIDEOTOVIDEO_NOTIF,MTCLIB_MSG_BGN + 138 );
    //VGA��ʾ�Ƿ��Ǳ�������֪ͨ����Ϣ�壺BOOL32
    OSPEVENT( MTCLIB_DISP_CONFIG_VGASHOWLOCAL_NOTIF,    MTCLIB_MSG_BGN + 139 );
    //�ڶ�·��Ƶ�Ƿ������VGA����֪ͨ����Ϣ�壺BOOL32
    OSPEVENT( MTCLIB_DISP_CONFIG_SECONDVIDEOTOVGA_NOTIF,MTCLIB_MSG_BGN + 140 );
    //�Ƿ��;�̬ͼƬ����֪ͨ����Ϣ�壺(BOOL32 TRUE = ��ʼ���� FALSE = ֹͣ����)
    OSPEVENT( MTCLIB_DISP_CONFIG_SENDSTATICPIC_NOTIF,   MTCLIB_MSG_BGN + 145 );
    //�Ƿ�ʹ��DHCP����֪ͨ����Ϣ�壺BOOL32
    OSPEVENT( MTCLIB_DISP_CONFIG_USEDHCP_NOTIF,         MTCLIB_MSG_BGN + 146 );
    //������������֪ͨ����Ϣ�壺u32(������)
    OSPEVENT( MTCLIB_DISP_CONFIG_CALLRATE_NOTIF,        MTCLIB_MSG_BGN + 147 );
    //��������֪ͨ����Ϣ�壺u32(������)
    OSPEVENT( MTCLIB_DISP_CONFIG_GATEWAY_NOTIF,         MTCLIB_MSG_BGN + 148 );
    //DNS������IP��ַ֪ͨ����Ϣ�壺u32(������)
    OSPEVENT( MTCLIB_DISP_CONFIG_DNSSERVERIP_NOTIF,     MTCLIB_MSG_BGN + 149 );
    //MTUʱ������֪ͨ����Ϣ�壺u32(������)
    OSPEVENT( MTCLIB_DISP_CONFIG_MTU_NOTIF,             MTCLIB_MSG_BGN + 150 );
    //TCP��UDP��ʼ�˿�����֪ͨ����Ϣ�壺u16(TCP ��ʼ�˿ںţ�������)
    //                                + u16(UDP ��ʼ�˿ںţ�������)
    OSPEVENT( MTCLIB_DISP_CONFIG_TCPUDPSTARTPORT_NOTIF, MTCLIB_MSG_BGN + 151 );
    //��������֪ͨ����Ϣ�壺EmLanguage
    OSPEVENT( MTCLIB_DISP_CONFIG_LANGUAGE_NOTIF,        MTCLIB_MSG_BGN + 152 );
    //LDAP����������֪ͨ����Ϣ�壺s8[MT_MAX_LDAPSERVER_NAME_LEN](����)
    OSPEVENT( MTCLIB_DISP_CONFIG_LDAP_NOTIF,            MTCLIB_MSG_BGN + 153 );
    //��˷������������֪ͨ����Ϣ�壺u8
    OSPEVENT( MTCLIB_DISP_CONFIG_MICADJUST_NOTIF,       MTCLIB_MSG_BGN + 154 );
    //������������֪ͨ����Ϣ�壺u8
    OSPEVENT( MTCLIB_DISP_CONFIG_ENCVOL_NOTIF,          MTCLIB_MSG_BGN + 155 );
    //������������֪ͨ����Ϣ�壺u8
    OSPEVENT( MTCLIB_DISP_CONFIG_DECVOL_NOTIF,          MTCLIB_MSG_BGN + 160 );
    //�ն�ϵͳʱ��֪ͨ����Ϣ�壺TMtKdvTime
    OSPEVENT( MTCLIB_DISP_CONFIG_SYSTIME_NOTIF,         MTCLIB_MSG_BGN + 161 );


//5. ������Ϣ
    //��ȡ������Ϣ�ɹ�����Ϣ�壺TSnapInfo
    OSPEVENT( MTCLIB_DISP_SNAPSHOT_GETINFO_ACK,         MTCLIB_MSG_BGN + 300 );
    //��ȡ������Ϣʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_SNAPSHOT_GETINFO_NACK,        MTCLIB_MSG_BGN + 301 );
    //������Ϣ֪ͨ(����ev_SnapshotInd��ev_SnapshotInfoInd)����Ϣ�壺TSnapInfo
    OSPEVENT( MTCLIB_DISP_SNAPSHOT_INFO_NOTIF,          MTCLIB_MSG_BGN + 302 );

    //������Ϣ���֪ͨ����Ϣ�壺BOOL32
    OSPEVENT( MTCLIB_DISP_SNAPSHOT_CLEAR_NOTIF,         MTCLIB_MSG_BGN + 303 );


//6. FXO��Ϣ
    //���гɹ�����Ϣ�壺EmFxoState(ע����ev_FxoCallLinkStateInd�����ֶ���)
    OSPEVENT( MTCLIB_DISP_FXO_CALL_ACK,                 MTCLIB_MSG_BGN + 320 );
    //����ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_FXO_CALL_NACK,                MTCLIB_MSG_BGN + 321 );

    //�绰����֪ͨ����Ϣ�壺s8*(�Է�����)
    OSPEVENT( MTCLIB_DISP_FXO_CALLINCOMING_NOTIF,       MTCLIB_MSG_BGN + 322 );
    //���س�ʱ֪ͨ����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_FXO_LOCALTIMEDOUT_NOTIF,      MTCLIB_MSG_BGN + 323 );
    //�Զ˳�ʱ֪ͨ����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_FXO_PEERTIMEDOUT_NOTIF,       MTCLIB_MSG_BGN + 324 );
    //����״̬֪ͨ����Ϣ�壺EmFxoState(ע������ѷ���ACK�����ٷ��͸���Ϣ)
    OSPEVENT( MTCLIB_DISP_FXO_STATE_NOTIF,              MTCLIB_MSG_BGN + 325 );


//7. ��ַ����Ϣ
    //��ַ��ע��ɹ�����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_REGISTER_ACK,        MTCLIB_MSG_BGN + 350 );
    //��ַ��ע��ʧ�ܣ���Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_REGISTER_NACK,       MTCLIB_MSG_BGN + 351 );

    //��ַ��ע���ɹ�����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_UNREGISTER_ACK,      MTCLIB_MSG_BGN + 352 );
    //��ַ��ע��ʧ�ܣ���Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_UNREGISTER_NACK,     MTCLIB_MSG_BGN + 353 );

    //��ӵ�ַ����Ŀ�ɹ�����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_ADDENTRY_ACK,        MTCLIB_MSG_BGN + 354 );
    //��ӵ�ַ����Ŀʧ�ܣ���Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_ADDENTRY_NACK,       MTCLIB_MSG_BGN + 355 );
    //��ӵ�ַ����Ŀ֪ͨ����Ϣ�壺TADDRENTRY(��ADDRBOOK_REFRESHENTRY_NOTIF�����ֶ���)
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_ADDENTRY_NOTIF,      MTCLIB_MSG_BGN + 356 );

    //�޸ĵ�ַ����Ŀ�ɹ�����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_EDITENTRY_ACK,       MTCLIB_MSG_BGN + 357 );
    //�޸ĵ�ַ����Ŀʧ�ܣ���Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_EDITENTRY_NACK,      MTCLIB_MSG_BGN + 358 );
    //�޸ĵ�ַ����Ŀ֪ͨ����Ϣ�壺TADDRENTRY(��ADDRBOOK_REFRESHENTRY_NOTIF�����ֶ���)
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_EDITENTRY_NOTIF,     MTCLIB_MSG_BGN + 359 );

    //ɾ����ַ����Ŀ�ɹ�����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_DELENTRY_ACK,        MTCLIB_MSG_BGN + 360 );
    //ɾ����ַ����Ŀʧ�ܣ���Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_DELENTRY_NACK,       MTCLIB_MSG_BGN + 361 );
    //ɾ����ַ����Ŀ֪ͨ����Ϣ�壺�ޣ�GetEntryIndex����ɾ������Ŀ
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_DELENTRY_NOTIF,      MTCLIB_MSG_BGN + 362 );

    //��ӻ�����ɹ�����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_ADDGROUP_ACK,        MTCLIB_MSG_BGN + 363 );
    //��ӻ�����ʧ�ܣ���Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_ADDGROUP_NACK,       MTCLIB_MSG_BGN + 364 );
    //��ӻ�����֪ͨ����Ϣ�壺TADDRMULTISETENTRY(��ADDRBOOK_REFRESHMULSETENTRY_NOTIF�����ֶ���)
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_ADDGROUP_NOTIF,      MTCLIB_MSG_BGN + 365 );

    //�޸Ļ�����ɹ�����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_EDITGROUP_ACK,       MTCLIB_MSG_BGN + 366 );
    //�޸Ļ�����ʧ�ܣ���Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_EDITGROUP_NACK,      MTCLIB_MSG_BGN + 367 );
    //�޸Ļ�����֪ͨ����Ϣ�壺TADDRMULTISETENTRY(��ADDRBOOK_REFRESHMULSETENTRY_NOTIF�����ֶ���)
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_EDITGROUP_NOTIF,     MTCLIB_MSG_BGN + 368 );

    //ɾ��������ɹ�����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_DELGROUP_ACK,        MTCLIB_MSG_BGN + 369 );
    //ɾ��������ʧ�ܣ���Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_DELGROUP_NACK,       MTCLIB_MSG_BGN + 370 );
    //ɾ��������֪ͨ����Ϣ�壺�ޣ�GetEntryIndex����ɾ���Ļ�����
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_DELGROUP_NOTIF,      MTCLIB_MSG_BGN + 371 );

    //������������Ŀ�ɹ�����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_ADDENTRYTOGROUP_ACK, MTCLIB_MSG_BGN + 372 );
    //������������Ŀʧ�ܣ���Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_ADDENTRYTOGROUP_NACK,MTCLIB_MSG_BGN + 373 );

    //�ӻ�����ɾ����Ŀ�ɹ�����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_DELENTRYFROMGROUP_ACK,   MTCLIB_MSG_BGN + 374 );
    //�ӻ�����ɾ����Ŀʧ�ܣ���Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_ADDRBOOK_DELENTRYFROMGROUP_NACK,  MTCLIB_MSG_BGN + 375 );


//8. �����Ϣ
    //��ز���֪ͨ����Ϣ�壺u8[2](��һ·��Ƶ����Ƶ����ʵ�غ�����)
    //                    + u8[2](��һ·��Ƶ����Ƶ�Ķ�̬�غ�����)
    //                    + TEncryptKey[2](��һ·��Ƶ����Ƶ����Կ)
    //                    + EmSite(����orԶ��)
    OSPEVENT( MTCLIB_DISP_MONITOR_PARAM_NOTIF,          MTCLIB_MSG_BGN + 390 );


//9. �û���Ϣ
    //��ȡ�û��б�ɹ�����Ϣ�壺CUserFullInfo[16]
    OSPEVENT( MTCLIB_DISP_USER_GETLIST_ACK,             MTCLIB_MSG_BGN + 400 );
    //��ȡ�û��б�ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_USER_GETLIST_NACK,            MTCLIB_MSG_BGN + 401 );
    //�û���Ϣ���֪ͨ����Ϣ�壺CUserFullInfo[16]
    OSPEVENT( MTCLIB_DISP_USER_LIST_NOTIF,              MTCLIB_MSG_BGN + 402 );

    //����û��ɹ�����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_USER_ADD_ACK,                 MTCLIB_MSG_BGN + 403 );
    //����û�ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_USER_ADD_NACK,                MTCLIB_MSG_BGN + 404 );

    //�޸��û��ɹ�����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_USER_EDIT_ACK,                MTCLIB_MSG_BGN + 405 );
    //�޸��û�ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_USER_EDIT_NACK,               MTCLIB_MSG_BGN + 406 );

    //ɾ���û��ɹ�����Ϣ�壺CUserFullInfo
    OSPEVENT( MTCLIB_DISP_USER_DEL_ACK,                 MTCLIB_MSG_BGN + 407 );
    //ɾ���û�ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_USER_DEL_NACK,                MTCLIB_MSG_BGN + 408 );


//10. ��Ե������Ϣ
    //���гɹ�����Ϣ�壺TLinkState(��ev_CallLinkStateInd�����ֶ���)
    OSPEVENT( MTCLIB_DISP_P2P_CALL_ACK,                 MTCLIB_MSG_BGN + 450 );
    //����ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_P2P_CALL_NACK,                MTCLIB_MSG_BGN + 451 );

    //��·״̬֪ͨ����Ϣ�壺TLinkState(ע������ѷ���ACK�����ٷ��͸���Ϣ)
    OSPEVENT( MTCLIB_DISP_P2P_STATE_NOTIF,              MTCLIB_MSG_BGN + 452 );

    //���е���֪ͨ����Ϣ�壺TDialParam
    OSPEVENT( MTCLIB_DISP_P2P_CALLINCOMING_NOTIF,       MTCLIB_MSG_BGN + 453 );


//11. MCU��������Ϣ
    //����ɹ�����Ϣ�壺TLinkState(��ev_CallLinkStateInd�����ֶ���)
    OSPEVENT( MTCLIB_DISP_MCU_CREATECONF_ACK,           MTCLIB_MSG_BGN + 490 );
    //����ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MCU_CREATECONF_NACK,          MTCLIB_MSG_BGN + 491 );

    //��·״̬����Ϣ�壺TLinkState(ע������ѷ���ACK�����ٷ��͸���Ϣ)
    OSPEVENT( MTCLIB_DISP_MCU_STATE_NOTIF,              MTCLIB_MSG_BGN + 492 );

    //���к������гɹ�����Ϣ�壺BOOL32
    OSPEVENT( MTCLIB_DISP_MCU_SITECALLCREATE_ACK,       MTCLIB_MSG_BGN + 495 );
    //���к�������ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MCU_SITECALLREATE_NACK,       MTCLIB_MSG_BGN + 496 );
    //���к�������֪ͨ����Ϣ�壺BOOL32
    OSPEVENT( MTCLIB_DISP_MCU_SITECALLCREATE_NOTIF,     MTCLIB_MSG_BGN + 497 );

    //����MCU(����ȡMCU�����б�)�ɹ�����Ϣ�壺TLinkState(��ev_CallLinkStateInd�����ֶ���)
    OSPEVENT( MTCLIB_DISP_MCU_CALLMCU_ACK,              MTCLIB_MSG_BGN + 500 );
    //����MCU(����ȡMCU�����б�)ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MCU_CALLMCU_NACK,             MTCLIB_MSG_BGN + 501 );

    //�����ն�ʧ��֪ͨ����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_MCU_DROPMTFAIL_NOTIF,         MTCLIB_MSG_BGN + 505 );

    //ָ�������˳ɹ�����Ϣ�壺BOOL32(TRUE = ͬ�� FALSE = �ܾ�)
    OSPEVENT( MTCLIB_DISP_MCU_SPECSPEAKER_ACK,          MTCLIB_MSG_BGN + 506 );
    //ָ��������ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MCU_SPECSPEAKER_NACK,         MTCLIB_MSG_BGN + 507 );

    //ȡ����ϯ�ɹ�����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_MCU_CANCELCHAIRMAN_ACK,       MTCLIB_MSG_BGN + 510 );
    //ȡ����ϯʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MCU_CANCELCHAIRMAN_NACK,      MTCLIB_MSG_BGN + 511 );
    //ȡ����ϯ֪ͨ����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_MCU_CANCELCHAIRMAN_NOTIF,     MTCLIB_MSG_BGN + 512 );

    //����Ƶѡ���ɹ�����Ϣ�壺BOOL32(TRUE = ѡ���ɹ� FALSE = ѡ��ʧ��)
    OSPEVENT( MTCLIB_DISP_MCU_VIEWMTWITHAUDIO_ACK,      MTCLIB_MSG_BGN + 515 );
    //����Ƶѡ��ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MCU_VIEWMTWITHAUDIO_NACK,     MTCLIB_MSG_BGN + 516 );
    //����Ƶѡ��֪ͨ����Ϣ�壺BOOL32(TRUE = ѡ���ɹ� FALSE = ѡ��ʧ��)
    OSPEVENT( MTCLIB_DISP_MCU_VIEWMTWITHAUTIO_NOTIF,    MTCLIB_MSG_BGN + 517 );

    //ȡ��ѡ��֪ͨ����Ϣ�壺BOOL32(TRUE = ͬ�� FALSE = �ܾ�)
    OSPEVENT( MTCLIB_DISP_MCU_STOPVIEW_NOTIF,           MTCLIB_MSG_BGN + 518 );

    //��ʼȫ������ɹ�����Ϣ�壺BOOL32(TRUE = ͬ�� FALSE = �ܾ�)
    OSPEVENT( MTCLIB_DISP_MCU_STARTENTIREMIXING_ACK,    MTCLIB_MSG_BGN + 525 );
    //��ʼȫ�����ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MCU_STARTENTIREMIXING_NACK,   MTCLIB_MSG_BGN + 526 );
    //��ʼȫ�����֪ͨ����Ϣ�壺BOOL32(TRUE = ͬ�� FALSE = �ܾ�)
    OSPEVENT( MTCLIB_DISP_MCU_STARTENTIREMIXING_NOTIF,  MTCLIB_MSG_BGN + 527 );

    //ֹͣȫ������ɹ�����Ϣ�壺BOOL32(TRUE = ͬ�� FALSE = �ܾ�)
    OSPEVENT( MTCLIB_DISP_MCU_STOPENTIREMIXING_ACK,     MTCLIB_MSG_BGN + 528 );
    //ֹͣȫ�����ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MCU_STOPENTIREMIXING_NACK,    MTCLIB_MSG_BGN + 529 );
    //ֹͣȫ�����֪ͨ����Ϣ�壺BOOL32(TRUE = ͬ�� FALSE = �ܾ�)
    OSPEVENT( MTCLIB_DISP_MCU_STOPENTIREMIXING_NOTIF,   MTCLIB_MSG_BGN + 530 );

    //��ʼ����ϳɳɹ�����Ϣ�壺BOOL32(TRUE = ͬ�� FALSE = �ܾ�)
    OSPEVENT( MTCLIB_DISP_MCU_STARTCP_ACK,              MTCLIB_MSG_BGN + 535 );
    //��ʼ����ϳ�ʧ�ܣ���Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_MCU_STARTCP_NACK,             MTCLIB_MSG_BGN + 536 );
    //��ʼ����ϳ�֪ͨ����Ϣ�壺BOOL32(TRUE = ͬ�� FALSE = �ܾ�)
    OSPEVENT( MTCLIB_DISP_MCU_STARTCP_NOTIF,            MTCLIB_MSG_BGN + 537 );

    //�޸Ļ���ϳɲ����ɹ�����Ϣ�壺BOOL32(TRUE = ͬ�� FALSE = �ܾ�)
    OSPEVENT( MTCLIB_DISP_MCU_EDITCPPARAM_ACK,          MTCLIB_MSG_BGN + 538 );
    //�޸Ļ���ϳɲ���ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MCU_EDITCPPARAM_NACK,         MTCLIB_MSG_BGN + 539 );
    //�޸Ļ���ϳɲ���֪ͨ����Ϣ�壺BOOL32(TRUE = ͬ�� FALSE = �ܾ�)
    OSPEVENT( MTCLIB_DISP_MCU_EDITCPPARAM_NOTIF,        MTCLIB_MSG_BGN + 540 );

    //ֹͣ����ϳɳɹ�����Ϣ�壺BOOL32(TRUE = ͬ�� FALSE = �ܾ�)
    OSPEVENT( MTCLIB_DISP_MCU_STOPCP_ACK,               MTCLIB_MSG_BGN + 541 );
    //ֹͣ����ϳ�ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MCU_STOPCP_NACK,              MTCLIB_MSG_BGN + 542 );
    //ֹͣ����ϳ�֪ͨ����Ϣ�壺BOOL32(TRUE = ͬ�� FALSE = �ܾ�)
    OSPEVENT( MTCLIB_DISP_MCU_STOPCP_NOTIF,             MTCLIB_MSG_BGN + 543 );

    //��ʼ���������ɹ�����Ϣ�壺BOOL32(TRUE = ͬ�� FALSE = �ܾ�)
    OSPEVENT( MTCLIB_DISP_MCU_STARTVAC_ACK,             MTCLIB_MSG_BGN + 560 );
    //��ʼ��������ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MCU_STARTVAC_NACK,            MTCLIB_MSG_BGN + 561 );
    //��ʼ��������֪ͨ����Ϣ�壺BOOL32(TRUE = ͬ�� FALSE = �ܾ�)
    OSPEVENT( MTCLIB_DISP_MCU_STARTVAC_NOTIF,           MTCLIB_MSG_BGN + 562 );

    //ֹͣ���������ɹ�����Ϣ�壺BOOL32(TRUE = ͬ�� FALSE = �ܾ�)
    OSPEVENT( MTCLIB_DISP_MCU_STOPVAC_ACK,              MTCLIB_MSG_BGN + 563 );
    //ֹͣ��������ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MCU_STOPVAC_NACK,             MTCLIB_MSG_BGN + 564 );
    //ֹͣ��������֪ͨ����Ϣ�壺BOOL32(TRUE = ͬ�� FALSE = �ܾ�)
    OSPEVENT( MTCLIB_DISP_MCU_STOPVAC_NOTIF,            MTCLIB_MSG_BGN + 565 );

    //������ʱ�ɹ�����Ϣ�壺BOOL32(TRUE = ͬ�� FALSE = �ܾ�)
    OSPEVENT( MTCLIB_DISP_MCU_PROLONG_ACK,              MTCLIB_MSG_BGN + 575 );
    //������ʱʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MCU_PROLONG_NACK,             MTCLIB_MSG_BGN + 576 );
    //������ʱ֪ͨ����Ϣ�壺BOOL32(TRUE = ͬ�� FALSE = �ܾ�)
    OSPEVENT( MTCLIB_DISP_MCU_PROLONG_NOTIF,            MTCLIB_MSG_BGN + 577 );

    //��ȡ�ն�״̬�ɹ�����Ϣ�壺TMtId + TTerStatus
    OSPEVENT( MTCLIB_DISP_MCU_GETMTSTATUS_ACK,          MTCLIB_MSG_BGN + 585 );
    //��ȡ�ն�״̬ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MCU_GETMTSTATUS_NACK,         MTCLIB_MSG_BGN + 586 );
    //�ն�״̬֪ͨ����Ϣ�壺TMtId + TTerStatus
    OSPEVENT( MTCLIB_DISP_MCU_MTSTATUS_NOTIF,           MTCLIB_MSG_BGN + 587 );

    //��ʼ��سɹ�����Ϣ�壺TMtId + u32(Ŀ���ն�IP��ַ�����ʧ����Ϊ0��������)
    //                    + u16(��Ƶ�˿ڣ�������) + u16(��Ƶ�˿ڣ�������)
    //                    + u8(��Ƶ��ʵ�غ�ֵ) + u8(��Ƶ��ʵ�غ�ֵ)
    //                    + EmEncryptArithmetic(��Ƶ��������)
    //                    + EmEncryptArithmetic(��Ƶ��������)
    //                    + u32(��Ƶ��̬�غɣ�������)
    //                    + TEncryptKey(��Ƶ������Ϣ)
    //                    + u32(��Ƶ��̬�غɣ�������)
    //                   + TEncryptKey(��Ƶ������Ϣ)
    OSPEVENT( MTCLIB_DISP_MCU_STARTMONITOR_ACK,         MTCLIB_MSG_BGN + 590 );
    //��ʼ���ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MCU_STARTMONITOR_NACK,        MTCLIB_MSG_BGN + 591 );


    //�ն�������֤������Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_MCU_ENTERPWD_REQ,             MTCLIB_MSG_BGN + 650 );
    //�ն˼������������Ϣ�壺TConfListInfo
    OSPEVENT( MTCLIB_DISP_MCU_JOINCONF_REQ,             MTCLIB_MSG_BGN + 651 );
    //�ն˺�֪ͨ����Ϣ�壺TMtId
    OSPEVENT( MTCLIB_DISP_MCU_MTID_NOTIF,               MTCLIB_MSG_BGN + 652 );
    //�ն���ϯ����֪ͨ����Ϣ�壺TMtId
    OSPEVENT( MTCLIB_DISP_MCU_APPLYCHAIRMAN_NOTIF,      MTCLIB_MSG_BGN + 653 );
    //�ն˷�������֪ͨ����Ϣ�壺TMtId
    OSPEVENT( MTCLIB_DISP_MCU_APPLYSPEAKER_NOTIF,       MTCLIB_MSG_BGN + 654 );
    //�ն˻�������֪ͨ����Ϣ�壺TMtId
    OSPEVENT( MTCLIB_DISP_MCU_APPLYMIXING_NOTIF,        MTCLIB_MSG_BGN + 655 );
    //��ǰ��ƵԴ�նˣ���Ϣ�壺TMtId
    OSPEVENT( MTCLIB_DISP_MCU_CURVIDEOSOURCE_NOTIF,     MTCLIB_MSG_BGN + 656 );
    //�ն��б�֪ͨ����Ϣ�壺TMtInfo[]
    OSPEVENT( MTCLIB_DISP_MCU_MTLIST_NOTIF,             MTCLIB_MSG_BGN + 657 );
    //��ϯ�ն�֪ͨ����Ϣ�壺TMtId
    OSPEVENT( MTCLIB_DISP_MCU_CHAIRMAN_NOTIF,           MTCLIB_MSG_BGN + 658 );
    //������֪ͨ����Ϣ�壺TMtId
    OSPEVENT( MTCLIB_DISP_MCU_SPEAKER_NOTIF,            MTCLIB_MSG_BGN + 659 );
    //����Ϣ֪ͨ����Ϣ�壺s8[]
    OSPEVENT( MTCLIB_DISP_MCU_SHORTMSG_NOTIF,           MTCLIB_MSG_BGN + 660 );
    //������ѯ״̬֪ͨ����Ϣ�壺TMtPollInfo
    OSPEVENT( MTCLIB_DISP_MCU_POLLSTATUS_NOTIF,         MTCLIB_MSG_BGN + 670 );
    //�����ն�ʧ��֪ͨ����Ϣ�壺BOOL32
    OSPEVENT( MTCLIB_DISP_MCU_INVITEMTFAIL_NOTIF,       MTCLIB_MSG_BGN + 671 );
    //������Ϣ֪ͨ����Ϣ�壺TMtConfInfo
    OSPEVENT( MTCLIB_DISP_MCU_CONFINFO_NOTIF,           MTCLIB_MSG_BGN + 672 );
    //���鼴������֪ͨ����Ϣ�壺u16(ʣ��ʱ�䣬������)
    OSPEVENT( MTCLIB_DISP_MCU_LEFTTIME_NOTIF,           MTCLIB_MSG_BGN + 673 );
    //����ϳɲ���֪ͨ����Ϣ�壺TMtVMPParam
    OSPEVENT( MTCLIB_DISP_MCU_CPPARAM_NOTIF,            MTCLIB_MSG_BGN + 674 );
    //�򵥻�����Ϣ����Ϣ�壺TMtSimpConfInfo
    OSPEVENT( MTCLIB_DISP_MCU_SIMCONFINFO_NOTIF,        MTCLIB_MSG_BGN + 675 );
    //��Ϣ��ͬ��֪ͨ����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_MCU_UISYNCHRONIZE_NOTIF,      MTCLIB_MSG_BGN + 676 );
    //�������֪ͨ����Ϣ�壺BOOL32
    OSPEVENT( MTCLIB_DISP_MCU_CONFENCRYPTED_NOTIF,      MTCLIB_MSG_BGN + 677 );


//12. MC��������Ϣ
    //������չ�ɹ�����Ϣ�壺TLinkState(��ev_mcCallLinkStateInd�����ֶ���)
    OSPEVENT( MTCLIB_DISP_MC_CONFEXTEND_ACK,            MTCLIB_MSG_BGN + 730 );
    //������չʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MC_CONFEXTEND_NACK,           MTCLIB_MSG_BGN + 731 );

    //����ģʽ���óɹ�����Ϣ�壺BOOL32 + EmMCMode
    OSPEVENT( MTCLIB_DISP_MC_SETMODE_ACK,               MTCLIB_MSG_BGN + 735 );
    //����ģʽ����ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MC_SETMODE_NACK,              MTCLIB_MSG_BGN + 736 );
    //����ģʽ֪ͨ����Ϣ�壺BOOL32 + EmMCMode
    OSPEVENT( MTCLIB_DISP_MC_MODE_NOTIF,                MTCLIB_MSG_BGN + 737 );

    //����ϳ��Ƿ��Զ�֪ͨ����Ϣ�壺BOOL32(TRUE = �Զ� FALSE = ָ�����)
    OSPEVENT( MTCLIB_DISP_MC_AUTOCPSTYLE_NOTIF,         MTCLIB_MSG_BGN + 740 );

    //����ϳɲ���֪ͨ����Ϣ�壺EmInnerVMPStyle + TMtId[6]
    OSPEVENT( MTCLIB_DISP_MC_CPPARAM_NOTIF,             MTCLIB_MSG_BGN + 741 );

    //Զң�ն˳ɹ�����Ϣ�壺TMtId
    OSPEVENT( MTCLIB_DISP_MC_CONTROLREMOTEMT_ACK,       MTCLIB_MSG_BGN + 760 );
    //Զң�ն�ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_MC_CONTROLREMOTEMT_NACK,      MTCLIB_MSG_BGN + 761 );
    //Զң�ն�֪ͨ����Ϣ�壺TMtId
    OSPEVENT( MTCLID_DISP_MC_CONTROLREMOTEMT_NOTIF,     MTCLIB_MSG_BGN + 762 );

    //�ն���ѯ״̬֪ͨ����Ϣ�壺TMtPollInfo
    OSPEVENT( MTCLIB_DISP_MC_POLLSTATUS_NOTIF,          MTCLIB_MSG_BGN + 765 );

    //MC��������֪ͨ����Ϣ�壺TMtId + TDialParam
    OSPEVENT( MTCLIB_DISP_MC_CALLINCOMING_NOTIF,        MTCLIB_MSG_BGN + 780 );
    //MC����֪ͨ����Ϣ�壺BOOL32(�Ƿ�������չ����) + BOOL32(�Ƿ񼤻�)
    OSPEVENT( MTCLIB_DISP_MC_CAPABILITY_NOTIF,          MTCLIB_MSG_BGN + 781 );
    //������Ա֪ͨ����Ϣ�壺TMtId[6]
    //ע��������ƻ����뻭��ϳɰ󶨣����Գ�Ա��ͬ������Ϣ������Ҫ�ֱ�Դ���������չ
    OSPEVENT( MTCLIB_DISP_MC_MIXPARAM_NOTIF,            MTCLIB_MSG_BGN + 782 );
    //MC��·״̬֪ͨ����Ϣ�壺TLinkState(ע������ѷ���ACK�����ٷ��͸���Ϣ)
    OSPEVENT( MTCLIB_DISP_MC_STATE_NOTIF,               MTCLIB_MSG_BGN + 783 );
    //�ն�����֪ͨ����Ϣ�壺TMtId + BOOL32
    OSPEVENT( MTCLIB_DISP_MC_DUMB_NOTIF,                MTCLIB_MSG_BGN + 784 );
    //������֪ͨ����Ϣ�壺TMtId
    OSPEVENT( MTCLIB_DISP_MC_SPEAKER_NOTIF,             MTCLIB_MSG_BGN + 785 );


//13. �ն����������Ϣ
    //��ȡ�ն�״̬�ɹ�����Ϣ�壺TTerStatus
    OSPEVENT( MTCLIB_DISP_SELF_GETMTSTATUS_ACK,         MTCLIB_MSG_BGN + 820 );
    //��ȡ�ն�״̬ʧ�ܣ���Ϣ�壺�ޣ���������
    OSPEVENT( MTCLIB_DISP_SELF_GETMTSTATUS_NACK,        MTCLIB_MSG_BGN + 821 );
    //�ն�״̬֪ͨ����Ϣ�壺TTerStatus
    OSPEVENT( MTCLIB_DISP_SELF_MTSTATUS_NOTIF,          MTCLIB_MSG_BGN + 822 );

    //����״̬֪ͨ����Ϣ�壺BOOL32(TURE = ���� FALSE = ����)
    OSPEVENT( MTCLIB_DISP_SELF_DORMANCYSTATE_NOTIF,     MTCLIB_MSG_BGN + 825 );

    //������ļ��ɹ�����Ϣ�壺TFileTransfer
    OSPEVENT( MTCLIB_DISP_SELF_TRANSFERBIGFILE_ACK,     MTCLIB_MSG_BGN + 830 );
    //������ļ�ʧ�ܣ���Ϣ�壺TFileTransfer
    OSPEVENT( MTCLIB_DISP_SELF_TRANSFERBIGFILE_NACK,    MTCLIB_MSG_BGN + 831 );
    //�������֪ͨ����Ϣ�壺u16(��ȷ��С�����һλ)
    OSPEVENT( MTCLIB_DISP_SELF_TRANSFERPROGRESS_NOTIF,  MTCLIB_MSG_BGN + 832 );
    //�������֪ͨ����Ϣ�壺TFileTransfer
    OSPEVENT( MTCLIB_DISP_SELF_TRANSFEREND_NOTIF,       MTCLIB_MSG_BGN + 833 );

    //ҵ���ļ������ɹ�����Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_SELF_UPGRADESERVICE_ACK,      MTCLIB_MSG_BGN + 840 );
    //ҵ���ļ�����ʧ�ܣ���Ϣ�壺��
    OSPEVENT( MTCLIB_DISP_SELF_UPGRADESERVICE_NACK,     MTCLIB_MSG_BGN + 841 );

    //GKע��״̬֪ͨ����Ϣ�壺BOOL32(TRUE = ע��ɹ� FALSE = ע��ʧ��)
    OSPEVENT( MTCLIB_DISP_SELF_GKREGISTERRESULT_NOTIF,  MTCLIB_MSG_BGN + 845 );
    //CODEC������֪ͨ����Ϣ�壺u16
    OSPEVENT( MTCLIB_DISP_SELF_CODECERRORCODE_NOTIF,    MTCLIB_MSG_BGN + 846 );


//14. ������Ϣ
    //��ʱ����������
    OSPEVENT( MTCLIB_DISP_TIMEOUT,                      MTCLIB_MSG_BGN + 1000 );
    //��������Ϣ�壺u32(�ն�IP��ַ��������)
    OSPEVENT( MTCLIB_DISP_DISCONNECTED,                 MTCLIB_MSG_BGN + 1001 );
    //��Ϣ����
    OSPEVENT( MTCLIB_MESSAGEPROC,                       MTCLIB_MSG_BGN + 1002 );


///////////////////////////////////////////////////////////////////////////////
//  b. LIB�ڲ���Ϣ
///////////////////////////////////////////////////////////////////////////////
//1. ��ʱ��Ϣ
    OSPEVENT( TIMER_WAIT_REPLY,                 EV_MTC_BGN + 1 );


#endif//_EVMTCLIB_20070531_H_