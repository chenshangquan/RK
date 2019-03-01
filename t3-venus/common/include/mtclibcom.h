/*=============================================================================
ģ   ��   ��: �ն˿���̨ҵ���ܿ�
��   ��   ��: mtclibcom.h
�� ��  �� ��: mtclibcom.cpp
�ļ�ʵ�ֹ���: mtclib��UIʹ�ýӿ�
��        ��: ���
��        ��: V4.0  Copyright(C) 2003-2007 KDC, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2007/06/01  4.0     ���        ����
=============================================================================*/

#ifndef _MTCLIBCOM_20070601_H_
#define _MTCLIBCOM_20070601_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MtclibSsnData.h"

//LIB�߳�
extern zTemplate<CMtclibSsnInst, MAX_MTCLIB_SSN_NUM, CMtclibSsnData> *g_pcMtclibApp;
//��Ϣ���ͽӿ���(UI->MT)
extern CMtclibSsnInst           *g_pcCurInterface;

typedef zTemplate<CMtclibSsnInst, MAX_MTCLIB_SSN_NUM, CMtclibSsnData> CMtclibApp;


/*=============================================================================
�� �� ��: MtclibInit
��    ��: MTCLIB��ʼ��
��    ��: HWND hWnd                         [in]    UI���ھ��
          u16 wListenPort                   [in]    telnet�˿�
          BOOL32 bOpenTelnet                [in]    �Ƿ��telnet����
ע    ��: ��
�� �� ֵ: �ɹ�����enumMtclibErrorCodeNoError, ʧ�ܷ��ش�����
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2007/06/01  4.0     ���    ����
=============================================================================*/
EMMtclibErrorCode MtclibInit(HWND hWnd, u16 wListenPort = 0, BOOL32 bOpenTelnet = FALSE);


/*=============================================================================
�� �� ��: MtclibQuit
��    ��: MTCLIB�˳�
��    ��: ��
ע    ��: ��
�� �� ֵ: �ɹ�����enumMtclibErrorCodeNoError, ʧ�ܷ��ش�����
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2007/06/01  4.0     ���    ����
=============================================================================*/
EMMtclibErrorCode MtclibQuit(void);


#endif//_MTCLIBCOM_20070601_H_
