/*=============================================================================
ģ   ��   ��: �ն˿���̨ҵ���ܿ�
��   ��   ��: mtclibssninst.h
�� ��  �� ��: mtclibssninst.cpp
�ļ�ʵ�ֹ���: mtclibʵ��
��        ��: ���
��        ��: V4.0  Copyright(C) 2003-2007 KDC, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2007/05/28  4.0     ���        ����
=============================================================================*/

#ifndef _MTCLIBSSNINST_20070528_H_
#define _MTCLIBSSNINST_20070528_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MtclibInterface.h"

class CMtclibSsnInst : public CMtclibInterface
{
public:
    CMtclibSsnInst();

    virtual ~CMtclibSsnInst();

public:
    virtual void DaemonInstanceEntry(CMessage * const pcMsg, CApp *pcApp);

    virtual void InstanceEntry(CMessage * const pcMsg);

    virtual void InstanceExit(void);

    //��ȡ������Ϣ����
    void GetRecvMsgQueue(queue<CMessage> &queueMsg);

    //���ٶ�ʱ��
    void MtclibKillTimer(u32 dwTimer);

private:
    //����ʱ�¼�
    void ProcTimeout(void);

    //��������¼�
    void ProcOspDisconnect(CMessage * const pcMsg);

protected:
    u8              m_abyMsgDealBuf[MAX_MSG_LEN];
    queue<CMessage> m_queueRecvMsg;
};


#endif//_MTCLIBSSNINST_20070528_H_
