/*=============================================================================
ģ   ��   ��: �ļ������ͻ���ҵ���ܿ�
��   ��   ��: sucstruct.h
�� ��  �� ��: sucstruct.cpp
�ļ�ʵ�ֹ���: sucģ�鹫�ýṹ����
��        ��: ���
��        ��: V1.0  Copyright(C) 2006-2007 Kedacom, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2007/02/11  1.0     ���        ����
=============================================================================*/

#ifndef _SUCSTRUCT_
#define _SUCSTRUCT_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "filesrvclientstruct.h"
#include <vector>
using namespace std;

//�ϴ��ļ���Ϣ
class CAddFileInfo
{
public:
    //���캯��
    CAddFileInfo() : m_emType(enumFileSrvFileTypeUnknown),
                     m_dwFileSize(0)//m_dwFileNo(0), 
    { memset( m_szFilename, 0, sizeof (m_szFilename) ); }

    //��������
    virtual ~CAddFileInfo() {}

public:
    //�����ļ����
//    inline void SetFileNo(u32 dwFileNo) { m_dwFileNo = dwFileNo; }

    //�����ļ���
    inline void SetFilename(LPCSTR lptrFilename)
    {
        memset( m_szFilename, 0, sizeof (m_szFilename) );
        if ( lptrFilename != NULL )
        {
            strncpy( m_szFilename, lptrFilename, sizeof (m_szFilename) - 1 );
        }
    }

    //�����ļ�����
    inline void SetFileType(EMFileSrvFileType emType) { m_emType = emType; }

    //�����ļ���С
    inline void SetFileSize(u32 dwSize) { m_dwFileSize = dwSize; } 

    //��ȡ�ļ����
//    inline u32 GetFileNo(void) const { return m_dwFileNo; }

    //��ȡ�ļ���
    inline LPCSTR GetFilename(void) const { return m_szFilename; }

    //��ȡ�ļ�����
    inline EMFileSrvFileType GetFileType(void) const { return m_emType; }

    //��ȡ�ļ���С
    inline u32 GetFileSize(void) const { return m_dwFileSize; }

private:
//    u32                 m_dwFileNo;             //�ļ����(������)
    s8                  m_szFilename[MAX_PATH]; //�����ļ�ȫ��
    EMFileSrvFileType   m_emType;               //�ļ�����
    u32                 m_dwFileSize;           //�ļ���С(���ֽڼ��㣬������)
};

//�ϴ��汾��Ϣ
class CAddVerInfo
{
public:
    CAddVerInfo() : m_emDevType(enumFileSrvDevTypeUnknown),
                    m_byDevModel(0), m_emOsType(enumFileSrvOSTypeUnknown)//m_dwDevNo(0)
    { memset( m_szBugReport, 0, sizeof (m_szBugReport) ); }

    virtual ~CAddVerInfo() {}

public:
    //�����豸���
//    inline void SetDevNo(u32 dwDevNo) { m_dwDevNo = dwDevNo; }

    //��ȡ�豸���
//    inline u32 GetDevNo(void) const { return m_dwDevNo; }

    //�����豸����
    inline void SetDevType(EMFileSrvDevType emType) { m_emDevType = emType; }

    //��ȡ�豸����
    inline EMFileSrvDevType GetDevType(void) const { return m_emDevType; }

    //�����豸�ͺ�
    inline void SetDevModel(u8 byDevModel) { m_byDevModel = byDevModel; }

    //��ȡ�豸�ͺ�
    inline u8 GetDevModel(void) const { return m_byDevModel; }

    //���ò���ϵͳ����
    inline void SetOsType(EMFileSrvOSType emOsType) { m_emOsType = emOsType; }

    //��ȡ����ϵͳ����
    inline EMFileSrvOSType GetOsType(void) const { return m_emOsType; }

    //����Ӳ���汾��
    inline void SetHardwareVer(const IFCHardwareVer &tHardVer)
    { m_tHardVer = tHardVer; }

    //��ȡӲ���汾��
    inline IFCHardwareVer GetHardwareVer(void) const
    { return m_tHardVer; }

    //��������汾��
    inline void SetSoftwareVer(const IFCSoftwareVer &tSoftVer)
    { m_tSoftVer = tSoftVer; }

    //��ȡ����汾��
    inline IFCSoftwareVer GetSoftwareVer(void) const
    { return m_tSoftVer; }

    //�����޸�����
    inline void SetBugReport(LPCSTR lptrBugReport)
    {
        memset( m_szBugReport, 0, sizeof (m_szBugReport) );
        if ( lptrBugReport != NULL )
        {
            strncpy( m_szBugReport, lptrBugReport, sizeof (m_szBugReport) - 1 );
        }
    }

    //��ȡ�޸�����
    inline LPCSTR GetBugReport(void) const { return m_szBugReport; }

private:
//    u32                     m_dwDevNo;
    EMFileSrvDevType        m_emDevType;
    u8                      m_byDevModel;
    EMFileSrvOSType         m_emOsType;
    IFCHardwareVer          m_tHardVer;
    IFCSoftwareVer          m_tSoftVer;
    s8                      m_szBugReport[MAX_FILESRV_BUG_REPORT_LEN];
public:
    vector<CAddFileInfo>    m_vctFile;
};

#endif//_SUCSTRUCT_
