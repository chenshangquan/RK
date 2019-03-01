/*=============================================================================
ģ   ��   ��: USB-KEY����
��   ��   ��: UsbImportLicence.h
�� ��  �� ��: UsbImportLicence.cpp
�ļ�ʵ�ֹ���: USB��Ȩ����
��        ��: ���
��        ��: V4.0  Copyright(C) 2006-2006 Kedacom, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2006/10/11  1.0     ���        ����
=============================================================================*/

// UsbImportLicence.h: interface for the CUsbImportLicence class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USBIMPORTLICENCE_H__AEF29107_53CE_4A6B_9EBE_1DB91BEA8C6F__INCLUDED_)
#define AFX_USBIMPORTLICENCE_H__AEF29107_53CE_4A6B_9EBE_1DB91BEA8C6F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UsbKey.h"

//�豸��Ϣ
typedef struct tagUsbDeviceInfo
{
public:
    tagUsbDeviceInfo()
    {
        Clear();
    }

    /*=============================================================================
    �� �� ��:Clear
    ��    ��:���
    ��    ��:��
    ע    ��:��
    �� �� ֵ:��
    -------------------------------------------------------------------------------
    �޸ļ�¼:
    ��      ��  �汾    �޸���  �޸�����
    2006/10/11  1.0     ���    ����
    =============================================================================*/
    inline void Clear(void) { memset( this, 0, sizeof (tagUsbDeviceInfo) ); }

    /*=============================================================================
    �� �� ��:SetTag
    ��    ��:���ñ�ǩ��
    ��    ��:IN LPCSTR lptrTag                      [in]    ��ǩ��
    ע    ��:��
    �� �� ֵ:��
    -------------------------------------------------------------------------------
    �޸ļ�¼:
    ��      ��  �汾    �޸���  �޸�����
    2006/10/11  1.0     ���    ����
    =============================================================================*/
    void SetTag(IN LPCSTR lptrTag);

    /*=============================================================================
    �� �� ��:SetSerialNo
    ��    ��:�������к�
    ��    ��:IN u8 *pbySerialNo                     [in]    ���к�
    ע    ��:�������к�Ϊ16�����ڴ�
    �� �� ֵ:��
    -------------------------------------------------------------------------------
    �޸ļ�¼:
    ��      ��  �汾    �޸���  �޸�����
    2006/10/11  1.0     ���    ����
    =============================================================================*/
    void SetSerialNo(IN u8 *pbySerialNo);

    /*=============================================================================
    �� �� ��:SetUsbFreeSpace
    ��    ��:����USB��ʣ��ռ�
    ��    ��:IN u32 dwUsbFreeSpace                  [in]    ʣ��ռ�
    ע    ��:��
    �� �� ֵ:��
    -------------------------------------------------------------------------------
    �޸ļ�¼:
    ��      ��  �汾    �޸���  �޸�����
    2006/10/11  1.0     ���    ����
    =============================================================================*/
    inline void SetUsbFreeSpace(IN u32 dwUsbFreeSpace)
    { m_dwUsbFreeSpace = dwUsbFreeSpace; }

    /*=============================================================================
    �� �� ��:GetTag
    ��    ��:��ȡ��ǩ��
    ��    ��:��
    ע    ��:��
    �� �� ֵ:��ǩ��
    -------------------------------------------------------------------------------
    �޸ļ�¼:
    ��      ��  �汾    �޸���  �޸�����
    2006/10/11  1.0     ���    ����
    =============================================================================*/
    LPCSTR GetTag(void) const { return m_szTag; }

    /*=============================================================================
    �� �� ��:GetSerialNo
    ��    ��:��ȡ���к�
    ��    ��:��
    ע    ��:�����ַ���
    �� �� ֵ:���к�
    -------------------------------------------------------------------------------
    �޸ļ�¼:
    ��      ��  �汾    �޸���  �޸�����
    2006/10/11  1.0     ���    ����
    =============================================================================*/
    LPCSTR GetSerialNo(void) const { return m_szSerialNo; }

    /*=============================================================================
    �� �� ��:GetUsbFreeSpace
    ��    ��:��ȡUSB��ʣ��ռ�
    ��    ��:��
    ע    ��:��
    �� �� ֵ:USB��ʣ��ռ�
    -------------------------------------------------------------------------------
    �޸ļ�¼:
    ��      ��  �汾    �޸���  �޸�����
    2006/10/11  1.0     ���    ����
    =============================================================================*/
    u32 GetUsbFreeSpace(void) const { return m_dwUsbFreeSpace; }

private:
    s8  m_szTag[MAXLEN_USBKEY_DEVICE_TAG];          //�豸��ǩ��
    s8  m_szSerialNo[2 * HK_SERIAL_NUM_LEN + 1];    //�豸���к�
    u32 m_dwUsbFreeSpace;                           //ʣ��ռ�
} TUsbDeviceInfo;




//������Ȩ
class CUsbImportLicence : public CUsbKey
{
public:
	CUsbImportLicence();
	virtual ~CUsbImportLicence();

public:
    /*=============================================================================
    �� �� ��:SetDeviceCallBack
    ��    ��:�����豸״̬�ص�����
    ��    ��:IN LPCSTR lptrReaderName               [in]    ��������
             IN TUsbVerifyCallBack pFuncOnCallBack  [in]    ����ص�����
             IN TUsbVerifyCallBack pFuncOffCallBack [in]    �γ��ص�����
             IN void *pCBData                       [in]    �ص�����
    ע    ��:��������GetErrorDescription����
    �� �� ֵ:���óɹ�: 0; ����ʧ��: ������
    -------------------------------------------------------------------------------
    �޸ļ�¼:
    ��      ��  �汾    �޸���  �޸�����
    2006/10/11  1.0     ���    ����
    =============================================================================*/
    u32 SetDeviceCallBack(IN LPCSTR lptrReaderName,
                          IN TUsbVerifyCallBack pFuncOnCallBack,
                          IN TUsbVerifyCallBack pFuncOffCallBack,
                          IN void *pCBData);

    /*=============================================================================
    �� �� ��:FormatDevice
    ��    ��:��ʽ���豸
    ��    ��:IN LPCSTR lptrReaderName               [in]    ��������
    ע    ��:��������GetErrorDescription����
    �� �� ֵ:��ʽ���ɹ�: 0; ��ʽ��ʧ��: ������
    -------------------------------------------------------------------------------
    �޸ļ�¼:
    ��      ��  �汾    �޸���  �޸�����
    2006/10/11  1.0     ���    ����
    =============================================================================*/
    u32 FormatDevice(IN LPCSTR lptrReaderName);

    /*=============================================================================
    �� �� ��:GetDeviceInfo
    ��    ��:��ȡ�豸��Ϣ
    ��    ��:IN LPCSTR lptrReaderName               [in]    ��������
             OUT TUsbDeviceInfo &tInfo              [out]   �豸��Ϣ
    ע    ��:��������GetErrorDescription����
    �� �� ֵ:��ȡ�ɹ�: 0; ��ȡʧ��: ������
    -------------------------------------------------------------------------------
    �޸ļ�¼:
    ��      ��  �汾    �޸���  �޸�����
    2006/10/11  1.0     ���    ����
    =============================================================================*/
    u32 GetDeviceInfo(IN LPCSTR lptrReaderName, OUT TUsbDeviceInfo &tInfo);

    /*=============================================================================
    �� �� ��:SaveRight
    ��    ��:������Ȩ��Ϣ
    ��    ��:IN LPCSTR lptrReaderName               [in]    ��������
             IN const TUsbMcsSaveInfo &tMcsInfo     [in]    MCS������Ϣ
             IN const TUsbNmsSaveInfo &tNmsInfo     [in]    NMS������Ϣ
             IN const TUsbPcmtSaveInfo &tPcmtInfo   [in]    PCMT������Ϣ
             IN const TUsbVosSaveInfo &tVosInfo     [in]    VOS������Ϣ
    ע    ��:��������GetErrorDescription����
    �� �� ֵ:����ɹ�: 0; ����ʧ��: ������
    -------------------------------------------------------------------------------
    �޸ļ�¼:
    ��      ��  �汾    �޸���  �޸�����
    2006/10/12  1.0     ���    ����
    =============================================================================*/
    u32 SaveRight(IN LPCSTR lptrReaderName,
                  IN const TUsbMcsSaveInfo &tMcsInfo,
                  IN const TUsbNmsSaveInfo &tNmsInfo,
                  IN const TUsbPcmtSaveInfo &tPcmtInfo,
                  IN const TUsbVosSaveInfo &tVosInfo);

    /*=============================================================================
    �� �� ��:ReadRight
    ��    ��:��ȡ��Ȩ��Ϣ
    ��    ��:IN LPCSTR lptrReaderName               [in]    ��������
             OUT LPSTR lptrVersion                  [out]   �汾��Ϣ
             OUT TUsbMcsSaveInfo &tMcsInfo          [out]   MCS��Ȩ��Ϣ
             OUT TUsbNmsSaveInfo &tNmsInfo          [out]   NMS��Ȩ��Ϣ
             OUT TUsbPcmtSaveInfo &tPcmtInfo        [out]   PCMT��Ȩ��Ϣ
             OUT TUsbVosSaveInfo &tVosInfo          [out]   VOS��Ȩ��Ϣ
    ע    ��:��������GetErrorDescription����
    �� �� ֵ:��ȡ�ɹ�: 0; ��ȡʧ��: ������
    -------------------------------------------------------------------------------
    �޸ļ�¼:
    ��      ��  �汾    �޸���  �޸�����
    2006/10/12  1.0     ���    ����
    =============================================================================*/
    u32 ReadRight(IN LPCSTR lptrReaderName,
                  OUT LPSTR lptrVersion,
                  OUT TUsbMcsSaveInfo &tMcsInfo,
                  OUT TUsbNmsSaveInfo &tNmsInfo,
                  OUT TUsbPcmtSaveInfo &tPcmtInfo,
                  OUT TUsbVosSaveInfo &tVosInfo);
};

#endif // !defined(AFX_USBIMPORTLICENCE_H__AEF29107_53CE_4A6B_9EBE_1DB91BEA8C6F__INCLUDED_)
