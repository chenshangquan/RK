/*=============================================================================
ģ   ��   ��: �ն˿���̨ҵ���ܿ�
��   ��   ��: mtclibconnectmsgdeal.h
�� ��  �� ��: mtclibconnectmsgdeal.cpp
�ļ�ʵ�ֹ���: mtclib������Ϣ������
��        ��: ���
��        ��: V4.0  Copyright(C) 2003-2007 KDC, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2007/06/02  4.0     ���        ����
=============================================================================*/

#ifndef _MTCLIBCONNECTMSGDEAL_20070602_H_
#define _MTCLIBCONNECTMSGDEAL_20070602_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMtclibConnectMsgDeal
{
public:
    CMtclibConnectMsgDeal() {}
    virtual ~CMtclibConnectMsgDeal() {}

public:
    //��Ϣ����
    BOOL32 MessageProc(CMessage * const pcMsg, s32 nInstIndex);

private:
    //
};

#endif//_MTCLIBCONNECTMSGDEAL_20070602_H_