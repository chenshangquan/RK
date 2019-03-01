/*=============================================================================
ģ   ��   ��: �ļ������ͻ���ҵ���ܿ�
��   ��   ��: suclib.h
�� ��  �� ��: suclib.cpp
�ļ�ʵ�ֹ���: sucģ��ӿ�ʵ��
��        ��: ���
��        ��: V1.0  Copyright(C) 2006-2007 Kedacom, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2007/02/11  1.0     ���        ����
=============================================================================*/

#ifndef _SUCLIB_
#define _SUCLIB_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "succonst.h"
#include "suclibstruct.h"
#include "sucstruct.h"
#include <afxmt.h>
#include <vector>
#include "filesrvclientstruct.h"

using namespace std;

class CPrepareMsgDeal;
class CConnectMsgDeal;
class CUserMsgDeal;
class CVersionMsgDeal;
class CMsgHandler;
class CConfigMsgDeal;
class CFileMsgDeal;

//���ݴ����ӿڵ�����
class CSucSession
{
public:
    CSucSession();

    virtual ~CSucSession();

    //��ȡ������IP
    inline u32 GetSusIP(void) const { return m_dwSusIP; }

    //��ȡ����״̬
    inline EMSessionState GetState(void) const { return m_emState; }

    //��ȡInstID
    inline s32 GetInstID(void) const { return m_nInstID; }

    //����InstID
    inline void SetInstID(s32 nInstID) { m_nInstID = nInstID; }

    //����
    u16 Create(HWND hWnd);

    //���
    u16 Free(void);

    //��Ϣ����
    void OnDealMsg(CMessage * const pcMsg, CMsgHandler *pcHandler);

    //׼��״̬�µ���Ϣ����
    void OnPrepare(CMessage * const pcMsg, CMsgHandler *pcHandler);

    //����״̬�µ���Ϣ����
    void OnService(CMessage * const pcMsg, CMsgHandler *pcHandler);

    //�������������Ϣ
    BOOL32 PostMsgToSus(u16 wEventID, const u8 * const pbyMsg, u16 wMsgLen,
                        u32 dwTimeout = DEFAULT_TIMEOUT,
                        u16 *pwTotalPkt = NULL, u16 *pwCurPkt = NULL);

    //���ϲ���淢��Ϣ
    void SendMsgToUI(u16 wEventId, const TSucParam &tParam);

    //�����Ϣ����
    BOOL32 CheckMsgLen(u16 wEventId, u16 wExpectLen, u16 wRecvLen);

    //����״̬��ʱ��Ϣ����
    void OnTimerService(CMessage * const pcMsg, CMsgHandler *pcHandler);

//�ӿ�
public:
    //1. ����
    //����
    u16 ConnectSusReq(u32 dwIP, u16 wPort, LPCTSTR lptrUsername, LPCTSTR lptrPwd);

    //�Ͽ�
    u16 DisconnectSusReq(void);

    //����
    u16 ResetSusReq(BOOL32 bNoResetIfMtLogin);

    //2. �û�
    //��ȡ�û��б�
    u16 GetUserListReq(void);

    //����û�
    u16 AddUserReq(const CUserFullInfo &tInfo);

    //�༭�û�
    u16 EditUserReq(const CFCSrvUserInfo &tInfo);

    //ɾ���û�
    u16 DelUserReq(u32 dwUserNo);

    //3. ����
    //��ȡ����
    u16 GetCfgReq(void);

    //�༭����
    u16 EditCfgReq(const ISusConfig &tCfg);

    //4. �ļ�
    //4.1 �汾�޸�
    //��ѯ�����Ƽ��汾
    u16 GetAllRecommendedVerReq(void);

    //��ѯĳһ�豸��ʷ�汾��ϸ��Ϣ(�����Ƽ��汾)
    u16 GetDevVerInfoReq(const IFCSrvDev &tDev);
    //�����Ƽ��汾
    u16 SetRecommendedVerReq(u32 dwDevNo);

    //ɾ���汾
    u16 DelVerReq(u32 dwDevNo);

    //�༭�汾
    u16 EditVerReq(u32 dwDevNo, const IFCHardwareVer &tHardVer,
                   LPCSTR lptrBugReport);

    //4.2 �ļ��ϴ�
    //��ʼ�ϴ�
    u16 StartUpgradeReq(const CAddVerInfo &cInfo);

    //ֹͣ�ϴ�
    u16 StopUpgradeReq(void);

//��ȡ�洢��Ϣ
public:
    //��ȡ�û��б�
    void GetUserList(vector<CFCSrvUserInfo> &vctUserList);

    //��ȡ����������
    void GetSuSCfg(ISusConfig &tCfg);

    //��ȡ�Ƽ��汾�б�
    void GetRecommendedVerList(vector<IFCSrvDevVerFullInfo> &vctVerList);

    //��ȡȨ��
    u8 GetRight(void) const { return m_byRight; }

//ˢ�´洢��Ϣ
private:
    //ˢ���û���Ϣ
    void UpdateUserList(const u8 * const pbyMsg);

    //ˢ�·���������
    void UpdateSusCfg(const u8 * const pbyMsg);

private:
    u32     m_dwSusNode;        //�������ڵ�
//    u32     m_dwSusIID;         //������IID

    u32     m_dwSusIP;          //������IP
    u32     m_dwSusSn;          //�����������

    EMSessionState  m_emState;  //��Ins����״̬
    HWND            m_hWnd;     //�ϲ���Ϣ���ͽ�����
    u16             m_wWaitEvent;   //�ȴ���Ϣ
    u16             m_wSendACKNOTIF;//����REQ�����������ACK��NOTIF��
                                    //����libֻ��Ҫ����淢��һ����Ϣ����
                                    //����Ϣ�����ֵ��׷���ACK����NOTIF

    u8              m_byRight;      //�û�Ȩ��
    u8              m_byUpgrading;  //�Ƿ��ڰ汾����״̬
    u8              m_byCurFileIdx; //��ǰ�����ļ����

    s32     m_nInstID;          //���Ự��g_ptCtrlData->m_acSucSession�е�λ��
    vector<CSucFile>    m_vctFile;  //�����ϴ����ļ���Ϣ

    CCriticalSection    m_cLock;

    friend class CPrepareMsgDeal;
    friend class CConnectMsgDeal;
    friend class CUserMsgDeal;
    friend class CVersionMsgDeal;
    friend class CConfigMsgDeal;
    friend class CFileMsgDeal;

//�洢����
    vector<CFCSrvUserInfo>          m_vctUserInfo;  //�û��б�
    ISusConfig                      m_tSusCfg;      //����������
    vector<IFCSrvDevVerFullInfo>    m_vctDevList;   //�Ƽ��汾�б�

    s8                              m_szUsername[MAX_FILESRV_USERNAME_LEN];
    //��ʱ�洢����
    IFCSrvDevVerFullInfo            *m_ptDevVer;    //ĳһ�豸���а汾��Ϣ
};









#endif//_SUCLIB_
