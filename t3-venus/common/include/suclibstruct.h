/*=============================================================================
ģ   ��   ��: �ļ������ͻ���ҵ���ܿ�
��   ��   ��: suclibstruct.h
�� ��  �� ��: suclibstruct.cpp
�ļ�ʵ�ֹ���: suclib�ڲ��ṹ����
��        ��: ���
��        ��: V1.0  Copyright(C) 2006-2007 Kedacom, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2007/02/11  1.0     ���        ����
=============================================================================*/

#ifndef _SUCLIBSTRUCT_
#define _SUCLIBSTRUCT_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "filesrvconst.h"


enum EMSessionState
{
    enumSessionStateIdle    = (s32)0,
    enumSessionStatePrepare = (s32)1,
    enumSessionStateService = (s32)2
};

//������Ϣ
typedef struct tagSucParam
{
public:
    tagSucParam() : m_dwErrorCode(0), m_bTimedout(FALSE), m_wLen(0),
                    m_pbyMsg(NULL) {}

public:
    u32     m_dwErrorCode;  //������(��ʱ��Ϊ��ʱ��REQ��Ϣ��)
    BOOL32  m_bTimedout;    //�Ƿ�ʱ
    u16     m_wLen;         //��Ϣ����(������)
    u8      *m_pbyMsg;      //��Ϣ��(������)
} TSucParam;


class CSucFile
{
public:
    CSucFile() : m_dwFileSize(0), m_dwSizePerPkt(0), m_wTotalPkt(0),
                 m_wCurPkt(0), m_pbyFile(NULL)
    { memset( m_szFilename, 0, sizeof (m_szFilename) ); }

    virtual ~CSucFile() { DEL_PTR_ARRAY(m_pbyFile); };

public:
    s8  m_szFilename[MAX_FILESRV_FILENAME_LEN];
    u32 m_dwFileSize;
    u32 m_dwSizePerPkt;
    u16 m_wTotalPkt;
    u16 m_wCurPkt;
    u8  *m_pbyFile;
};


#endif//_SUCLIBSTRUCT_
