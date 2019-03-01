/*=============================================================================
ģ   ��   ��: �ն˿���̨ҵ���ܿ�
��   ��   ��: mtclibconst.h
�� ��  �� ��: mtclibconst.cpp
�ļ�ʵ�ֹ���: mtclib�궨��
��        ��: ���
��        ��: V4.0  Copyright(C) 2003-2007 KDC, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2007/05/28  4.0     ���        ����
=============================================================================*/

#ifndef _MTCLIBCONST_20070528_H_
#define _MTCLIBCONST_20070528_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//��������ն���
#ifndef MAX_MTCLIB_SSN_NUM
#define MAX_MTCLIB_SSN_NUM              (s32)16
#endif

//������Ϣ����
enum EMSendMsgType
{
    enumSendMsgTypeUnKnown      = (s32)0,
    enumSendMsgTypeCMessage     = (s32)1,//��ͨCMessage
    enumSendMsgTypeCMtMsg       = (s32)2//CMtMsg
};

//������
enum EMMtclibErrorCode
{
    enumMtclibErrorCodeNoError      = (u16)0,//�ɹ�
    enumMtclibErrorCodeDeliver      = (u16)1,//����ʧ��
    enumMtclibErrorCodeUnknownType  = (u16)2,//δ֪��Ϣ����
    enumMtclibErrorCodeOspInit      = (u16)3,//OSP��ʼ��ʧ��
    enumMtclibErrorCodeCreateApp    = (u16)4,//����LIB�߳�ʧ��
    enumMtclibErrorCodeMemory       = (u16)5,//�ڴ治��
};

//ʵ��״̬
enum EMInstState
{
    enumInstStateIdle           = (s32)0,//����
    enumInstStateConnecting     = (s32)1,//������
    enumInstStateService        = (s32)2//������
};


#ifndef MTCLIB_MSG_BGN
#define MTCLIB_MSG_BGN              WM_USER + 0x500
#endif
#ifndef MTCLIB_MSG_END
#define MTCLIB_MSG_END              WM_USER + 0x900
#endif


//  ��Ϣջ��󳤶�
#ifndef QUEUE_SIZE
#define QUEUE_SIZE                  (u16)2000
#endif

//��Ӿ���������
#ifndef MAX_OUTER_MATRIX_NUM
#define MAX_OUTER_MATRIX_NUM        (s32)64
#endif


//MC����ϳ��ն�������
#ifndef MAX_MC_CP_MEMBER_NUM
#define MAX_MC_CP_MEMBER_NUM        (s32)6
#endif

#endif//_MTCLIBCONST_20070528_H_
