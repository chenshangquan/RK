/*=============================================================================
ģ   ��   ��: �ն˿���̨ҵ���ܿ�
��   ��   ��: mtclibmatrixmsgdeal.h
�� ��  �� ��: mtclibmatrixmsgdeal.cpp
�ļ�ʵ�ֹ���: mtclib������Ϣ������
��        ��: ���
��        ��: V4.0  Copyright(C) 2003-2007 KDC, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2007/06/02  4.0     ���        ����
=============================================================================*/

#ifndef _MTCLIBMATRIXMSGDEAL_20070602_H_
#define _MTCLIBMATRIXMSGDEAL_20070602_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMtclibMatrixMsgDeal
{
public:
    CMtclibMatrixMsgDeal() {}
    virtual ~CMtclibMatrixMsgDeal() {}

public:
    //��Ϣ����
    BOOL32 MessageProc(CMessage &cMsg, s32 nInstIndex,
                       u16 &wUIEvent, TMtclibParam &tParam);

private:
    //
};

#endif//_MTCLIBMATRIXMSGDEAL_20070602_H_

