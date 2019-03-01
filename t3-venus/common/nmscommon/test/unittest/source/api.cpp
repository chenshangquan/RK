/*=======================================================================
ģ����      :NmsCommon.lib��Ԫ����
�ļ���      : api.cpp
����ļ�    :
�ļ�ʵ�ֹ��� :
����        : ���ǿ
�汾        : V3.6  Copyright(C) 2003-2005 Suzhou Keda Technology Co.Ltd
                    All rights reserved.
--------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2005/01/25  3.6         ���ǿ      ����
=======================================================================*/
#include "stdafx.h"
#include "api.h"
#include "nmscommon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////////
// CAPICase

void CAPICase::setUp()
{
}

void CAPICase::tearDown()
{
}

/*========================================================================
�� �� ����GetConfBitrate
��    �ܣ��õ���������
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CAPICase::GetConfBitrate()
{
    u32 *pdwConfRate = NULL;
    s32 nRateNum = 0;
    ::GetConfBitrate(&pdwConfRate, nRateNum);
    CPPUNIT_ASSERT(pdwConfRate != NULL);
    CPPUNIT_ASSERT(nRateNum >= 0);
    for(s32 nIndex = 0; nIndex < nRateNum; nIndex++)
    {
        u32 dwRate = pdwConfRate[nIndex];
        CPPUNIT_ASSERT(dwRate > 0);
        CPPUNIT_ASSERT((dwRate % 64) == 0);
    }
}

/*========================================================================
�� �� ����GetModuleFullPath
��    �ܣ��õ�ģ��ȫ·��
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CAPICase::GetModuleFullPath()
{
    CString csModePath = ::GetModuleFullPath();
    CPPUNIT_ASSERT(!csModePath.IsEmpty());

    s32 nPos = csModePath.Find(":\\");
    CPPUNIT_ASSERT(nPos == 1);

    nPos = csModePath.ReverseFind('\\');
    CPPUNIT_ASSERT(nPos == csModePath.GetLength() - 1);
}

/*========================================================================
�� �� ����nmscommonver
��    �ܣ��õ���İ汾��
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CAPICase::nmscommonver()
{
    ::nmscommonver();
}

/*========================================================================
�� �� ����ModuleRegToOsp
��    �ܣ���ospע��ģ��
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CAPICase::ModuleRegToOsp()
{
    BOOL bRet = ::ModuleRegToOsp();
    CPPUNIT_ASSERT(bRet == TRUE);
}

void CAPICase::Encrypt(void)
{
    s8 aszPwd[32];
    s8 aszDecrptPwd[32];
    s8 aszEncryptedPwd[64];

    ZeroMemory( aszDecrptPwd, 32 );
    ZeroMemory( aszEncryptedPwd, 64 );
    strcpy( aszPwd, "qwertyuiopasdfghjklzxcvbnm" );

    ::EncryptPwd( aszPwd, aszEncryptedPwd );
    ::DecryptPwd( aszEncryptedPwd, aszDecrptPwd );
    CPPUNIT_ASSERT( strcmp( aszPwd, aszDecrptPwd ) == 0 );
}

