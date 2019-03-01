/*=============================================================================
ģ   ��   ��: �ն˿���̨ҵ���ܿ�
��   ��   ��: mtclibssndata.h
�� ��  �� ��: mtclibssndata.cpp
�ļ�ʵ�ֹ���: mtclibʵ������ά����
��        ��: ���
��        ��: V4.0  Copyright(C) 2003-2007 KDC, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2007/05/28  4.0     ���        ����
=============================================================================*/

#ifndef _MTCLIBSSNDATA_20070528_H_
#define _MTCLIBSSNDATA_20070528_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MtclibStruct.h"
#include "MtclibSsnInst.h"
#include "addrbook.h"
#include "ummessagestruct.h"

class CMtclibSsnData
{
public:
    CMtclibSsnData();
    virtual ~CMtclibSsnData();

//��UI���õĽӿ�
public:
    //���õ�ǰ�Ựλ��
    void SetCurSession(s32 nSession);

    //��ȡ��ǰ�Ựλ��
    s32 GetCurSession(void);

    //��ȡ��һ��������������MT�ĻỰ
    BOOL32 GetNextFreeInterface(u32 dwIP, CMtclibSsnInst* &pcInterface);

    //��ȡVOD����
    BOOL32 GetVODParam(s32 nSession, CVODParam &cParam);

    //��ȡ�������
    BOOL32 GetMatrix(s32 nSession, CMatrix &cMatrix);

    //��ȡ���ò���
    BOOL32 GetConfig(s32 nSession, CMTConfig &cConfig);

    //��ȡ�ն�״̬
    BOOL32 GetStatus(s32 nSession, CMtStatus &cStatus);

    //��ȡ��ز���
    BOOL32 GetMonitorParam(s32 nSession, CMonitorParam &cParam);

    //��ȡ���������
    BOOL32 GetMultiConfStatus(s32 nSession, CMultiConfStatus &cStatus);

    //��ȡ��Ե�������
    BOOL32 GetP2PConfStatus(s32 nSession, CP2PConfStatus &cStatus);

    //��ȡ��ַ��
    BOOL32 GetAddrbook(s32 nSession, CAddrBook &cAddrbook);

    //��ȡ�û��б�
    BOOL32 GetUserList(s32 nSession, vector<CUserFullInfo> &vctUserList);

//LIB�ڲ��ӿ�
protected:
    //��������
    inline void Lock(void) { EnterCriticalSection( &m_cSect ); }

    //��������
    inline void Unlock(void) { LeaveCriticalSection( &m_cSect ); }

    //����ʵ��״̬
    BOOL32 SetInstState(s32 nInstID, EMInstState emState);

    //��ȡʵ��״̬
    EMInstState GetInstState(s32 nInstID);

    //�����ն�IP��ַ
    BOOL32 SetMtIP(s32 nInstID, u32 dwIP);

    //��ȡ�ն�IP��ַ
    u32 GetMtIP(s32 nInstID);

    //���ûỰ
    void SetSsnInst(CMtclibSsnInst *pcInst, s32 nInstID);

    //���
    void SetNull(void);

    //�ж��ն��Ƿ�����
    BOOL32 IsMtDormancy(s32 nInstIndex);

protected:
    EMInstState         m_aenumInstState[MAX_MTCLIB_SSN_NUM];   //ʵ��״̬
    u32                 m_adwMtIP[MAX_MTCLIB_SSN_NUM];          //ʵ�����ӵ�MT��ַ

    CVODParam           *m_pcVodParam;                          //VOD����
    CMatrix             *m_pcMatrix;                            //�������
    CMTConfig           *m_pcMtConfig;                          //���ò���
    CMtStatus           *m_pcMtStatus;                          //�ն�״̬
    CMonitorParam       *m_pcMonitorParam;                      //��ز���
    CMultiConfStatus    *m_pcMultiConfStatus;                   //���������
    CP2PConfStatus      *m_pcP2PConfStatus;                     //��Ե�������
    CAddrBook            *m_pcAddrbook;                         //��ַ��
    vector<vector<CUserFullInfo> >  m_vvctUserList;             //�û��б�

protected:
    CMtclibSsnInst*     m_apcInst[MAX_MTCLIB_SSN_NUM];

private:
    s32                 m_nCurSession;
    CRITICAL_SECTION    m_cSect;

    friend EMMtclibErrorCode MtclibQuit(void);
    friend class CMtclibInterface;
    friend class CMtclibSsnInst;
};

#endif//_MTCLIBSSNDATA_20070528_H_
