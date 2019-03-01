/*=======================================================================
ģ����      :NmsCommon.lib��Ԫ����
�ļ���      : calladdr.cpp
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
#include "calladdr.h"
#include "nmscommon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////////
// CCallAddrCase

void CCallAddrCase::setUp()
{
}

void CCallAddrCase::tearDown()
{
}

void CCallAddrCase::NewDelete()
{
#ifdef _DEBUG

	CMemoryState cStateInit, cStateEnd, cStateDiff;    
	cStateInit.Checkpoint();

	CCallAddr *pcAddr = new CCallAddr;
    CPPUNIT_ASSERT(pcAddr != NULL);

	DEL_PTR(pcAddr);

	cStateEnd.Checkpoint();
	BOOL bLeak = cStateDiff.Difference(cStateInit, cStateEnd);
	if (bLeak)
	{
		cStateDiff.DumpStatistics();
		cStateInit.DumpAllObjectsSince();
	}

	CPPUNIT_ASSERT(!bLeak); 
#endif
}

/*========================================================================
�� �� ����IsValidIplpStr
��    �ܣ��ִ���IP��ַ����Ч���ж�
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CCallAddrCase::IsValidIplpStr()
{
    // ��Чֵ
    BOOL bRet = CCallAddr::IsValidIpV4("172.16.5.200");
    CPPUNIT_ASSERT(bRet == TRUE);

    // ���ִ�ָ��
    LPCSTR lpIP = NULL;
    bRet = CCallAddr::IsValidIpV4(lpIP);
    CPPUNIT_ASSERT(bRet == FALSE);

    // ���Ȳ���ȷ
    bRet = CCallAddr::IsValidIpV4("172.13");
    CPPUNIT_ASSERT(bRet == FALSE);
    bRet = CCallAddr::IsValidIpV4("182.152.236.2344");
    CPPUNIT_ASSERT(bRet == FALSE);
    
    // ��0��ͷ
    bRet = CCallAddr::IsValidIpV4("0.12.6.6");
    CPPUNIT_ASSERT(bRet == FALSE);

    // �ԡ�.����ͷ
    bRet = CCallAddr::IsValidIpV4(".72.6.78");
    CPPUNIT_ASSERT(bRet == FALSE);

    // û��"."
    bRet = CCallAddr::IsValidIpV4("172165223");
    CPPUNIT_ASSERT(bRet == FALSE);

    // �������ַ�
    bRet = CCallAddr::IsValidIpV4("172.a16.5.5");
    CPPUNIT_ASSERT(bRet == FALSE);

    // ���λ�ò���
    bRet = CCallAddr::IsValidIpV4("1721.3.4.5");
    CPPUNIT_ASSERT(bRet == FALSE);

    bRet = CCallAddr::IsValidIpV4("172..16.46.5");
    CPPUNIT_ASSERT(bRet == FALSE);

    bRet = CCallAddr::IsValidIpV4("172.1682.5.3");
    CPPUNIT_ASSERT(bRet == FALSE);

    // �����򳬹�255
    bRet = CCallAddr::IsValidIpV4("354.2.53.6");
    CPPUNIT_ASSERT(bRet == FALSE);
    
    bRet = CCallAddr::IsValidIpV4("172.335.0.5");
    CPPUNIT_ASSERT(bRet == FALSE);
}

/*========================================================================
�� �� ����IsValidIpCString
��    �ܣ�CString��IP��ַ����Ч���ж�
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CCallAddrCase::IsValidIpCString()
{
    // ��Чֵ
    BOOL bRet = CCallAddr::IsValidIpV4(CString("172.16.5.200"));
    CPPUNIT_ASSERT(bRet == TRUE);

    //��ָ��
    
    bRet = CCallAddr::IsValidIpV4(CString(""));
    CPPUNIT_ASSERT(bRet == FALSE);

    //���Ȳ���ȷ
    bRet = CCallAddr::IsValidIpV4(CString("172.13"));
    CPPUNIT_ASSERT(bRet == FALSE);
    bRet = CCallAddr::IsValidIpV4(CString("182.152.236.2344"));
    CPPUNIT_ASSERT(bRet == FALSE);
    
    // ��0��ͷ
    bRet = CCallAddr::IsValidIpV4(CString("0.12.6.6"));
    CPPUNIT_ASSERT(bRet == FALSE);

    // �ԡ�.����ͷ
    bRet = CCallAddr::IsValidIpV4(CString(".72.6.78"));
    CPPUNIT_ASSERT(bRet == FALSE);

    // û��"."
    bRet = CCallAddr::IsValidIpV4(CString("172165223"));
    CPPUNIT_ASSERT(bRet == FALSE);

    // �������ַ�
    bRet = CCallAddr::IsValidIpV4(CString("172.a16.5.5"));
    CPPUNIT_ASSERT(bRet == FALSE);

    // ���λ�ò���
    bRet = CCallAddr::IsValidIpV4(CString("1721.3.4.5"));
    CPPUNIT_ASSERT(bRet == FALSE);

    bRet = CCallAddr::IsValidIpV4(CString("172..16.46.5"));
    CPPUNIT_ASSERT(bRet == FALSE);

    bRet = CCallAddr::IsValidIpV4(CString("172.1682.5.3"));
    CPPUNIT_ASSERT(bRet == FALSE);

    // �����򳬹�255
    bRet = CCallAddr::IsValidIpV4(CString("354.2.53.6"));
    CPPUNIT_ASSERT(bRet == FALSE);
    
    bRet = CCallAddr::IsValidIpV4(CString("172.335.0.5"));
    CPPUNIT_ASSERT(bRet == FALSE);
}

/*========================================================================
�� �� ����IsValidIpDword
��    �ܣ�˫�ֽ���IP��ַ����Ч���ж�
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CCallAddrCase::IsValidIpDword()
{
    // ��Чֵ
    BOOL bRet = CCallAddr::IsValidIpV4(0xAC1005C8);
    CPPUNIT_ASSERT(bRet == TRUE);

    // 0ֵ
    bRet = CCallAddr::IsValidIpV4((u32)0);
    CPPUNIT_ASSERT(bRet == FALSE);
    
    // ��0��ͷ
    bRet = CCallAddr::IsValidIpV4(0x001005C8);
    CPPUNIT_ASSERT(bRet == FALSE);
}

/*========================================================================
�� �� ����GetLastErrorInfo
��    �ܣ����س�����Ϣ
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CCallAddrCase::GetLastErrorInfo()
{
    // ��Чֵ
    CCallAddr::IsValidIpV4("172.16.5.200");
    CString csErroInfo;
    CCallAddr::GetLastErrorInfo(csErroInfo);

    CPPUNIT_ASSERT(csErroInfo.Find("�Ϸ�") >= 0);

    // ���ִ�ָ��
    LPCSTR lpIP = NULL;
    CCallAddr::IsValidIpV4(lpIP);
    CCallAddr::GetLastErrorInfo(csErroInfo);
    CPPUNIT_ASSERT(csErroInfo.Find("Ϊ��") >= 0);

    // ���Ȳ���ȷ
    CCallAddr::IsValidIpV4("172.36");
    CCallAddr::GetLastErrorInfo(csErroInfo);
    CPPUNIT_ASSERT(csErroInfo.Find("���ȷǷ�") >= 0);

    CCallAddr::IsValidIpV4("182.152.236.2344");
    CCallAddr::GetLastErrorInfo(csErroInfo);
    CPPUNIT_ASSERT(csErroInfo.Find("���ȷǷ�") >= 0);

    
    // ��0��ͷ
    CCallAddr::IsValidIpV4("0.12.6.6");
    CCallAddr::GetLastErrorInfo(csErroInfo);
    CPPUNIT_ASSERT(csErroInfo.Find("��0��ͷ") >= 0);

    // �ԡ�.����ͷ
    CCallAddr::IsValidIpV4(".72.6.78");
    CCallAddr::GetLastErrorInfo(csErroInfo);
    CPPUNIT_ASSERT(csErroInfo.Find("�Ե㿪ͷ") >= 0);

    // û��"."
    CCallAddr::IsValidIpV4("172165223");
    CCallAddr::GetLastErrorInfo(csErroInfo);
    CPPUNIT_ASSERT(csErroInfo.Find("IP��ַ�ָ���λ�ò���ȷ") >= 0);

    // �������ַ�
    CCallAddr::IsValidIpV4("172.a16.5.5");
    CCallAddr::GetLastErrorInfo(csErroInfo);
    CPPUNIT_ASSERT(csErroInfo.Find("�Ƿ��ַ�") >= 0);

    // ���λ�ò���
    CCallAddr::IsValidIpV4("1721.3.4.5");
    CCallAddr::GetLastErrorInfo(csErroInfo);
    CPPUNIT_ASSERT(csErroInfo.Find("��λ�ò���ȷ") >= 0);

    CCallAddr::IsValidIpV4("172..16.46.5");
    CCallAddr::GetLastErrorInfo(csErroInfo);
    CPPUNIT_ASSERT(csErroInfo.Find("����ķָ���") >= 0);

    CCallAddr::IsValidIpV4("172.1682.5.3");
    CCallAddr::GetLastErrorInfo(csErroInfo);
    CPPUNIT_ASSERT(csErroInfo.Find("��λ�ò���ȷ") >= 0);

    // �����򳬹�255
    CCallAddr::IsValidIpV4("354.2.53.6");
    CCallAddr::GetLastErrorInfo(csErroInfo);
    CPPUNIT_ASSERT(csErroInfo.Find("����Χ") >= 0);

    CCallAddr::IsValidIpV4("172.335.0.5");
    CCallAddr::GetLastErrorInfo(csErroInfo);
    CPPUNIT_ASSERT(csErroInfo.Find("����Χ") >= 0);
}

/*========================================================================
�� �� ����GetIpStr
��    �ܣ�˫�ֽڵ��ִ��͵�ַ��ת��
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CCallAddrCase::GetIpStr()
{
    CString csIP = CCallAddr::GetIpStr(0xAC1005C8);
    CPPUNIT_ASSERT(csIP == "172.16.5.200");
}

/*========================================================================
�� �� ����GetCallStrType
��    �ܣ��õ��ִ��Ǻ��ֺ�������
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CCallAddrCase::GetCallStrType()
{
    CString csCallAddr = "";
    UINT dwType = CCallAddr::GetCallStrType(csCallAddr);
    CPPUNIT_ASSERT(dwType == CCallAddr::NORMAL_STR);

    csCallAddr = "172.16.5.200";
    dwType = CCallAddr::GetCallStrType(csCallAddr);
    CPPUNIT_ASSERT(dwType == CCallAddr::IP_STR);

    csCallAddr = "123455";
    dwType = CCallAddr::GetCallStrType(csCallAddr);
    CPPUNIT_ASSERT(dwType == CCallAddr::NUM164_STR);

    csCallAddr = "Mt20";
    dwType = CCallAddr::GetCallStrType(csCallAddr);
    CPPUNIT_ASSERT(dwType == CCallAddr::H323ID_STR);
}
/*========================================================================
�� �� ����GetCallStrType
��    �ܣ�һ��u32 ���ǲ���һ���Ϸ���Ip����
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/08/31	4.0		�����	����
========================================================================*/
void CCallAddrCase::IsValidIpMask()
{
	//��Ч
	BOOL32 bRet = CCallAddr::IsValidIpMask(0xffffff00);
	CPPUNIT_ASSERT(bRet == TRUE);

	//0ֵ
	bRet = CCallAddr::IsValidIpMask(u32(0));
	CPPUNIT_ASSERT(FALSE == bRet);

	//101 
	bRet = CCallAddr::IsValidIpMask(0xffdf0000);
	CPPUNIT_ASSERT(FALSE == bRet);

	//255.255.255.255
	bRet = CCallAddr::IsValidIpMask(0xffffffff);
	CPPUNIT_ASSERT(FALSE == bRet);
}
/*========================================================================
�� �� ����IsValidIpMaskStr
��    �ܣ� �ַ����ǲ���һ���Ϸ���Ip��ַ
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/08/31	4.0		�����	����
========================================================================*/
void CCallAddrCase::IsValidIpMaskStr()
{
	//�Ϸ�
	BOOL32 bRet = CCallAddr::IsValidIpMask("255.255.255.0");
	CPPUNIT_ASSERT(TRUE == bRet);

	//0 value
	bRet = CCallAddr::IsValidIpMask("0.0.0.0");
	CPPUNIT_ASSERT(FALSE == bRet);

	//�Ƿ�
	bRet = CCallAddr::IsValidIpMask("255.225.223.0");
	CPPUNIT_ASSERT(FALSE == bRet);

	//255.255.255.255
	bRet = CCallAddr::IsValidIpMask("255.255.255.255");
	CPPUNIT_ASSERT(FALSE == bRet);

	//255.001.000.000
	bRet = CCallAddr::IsValidIpMask("255.001.000.000");
	CPPUNIT_ASSERT(FALSE == bRet);
}

/*=============================================================================
�� �� ��:GetLocalIpAddr
��    ��:��ȡ���б���IP��ַ����
��    ��:��
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/10/29  4.0   ���    ����
=============================================================================*/
void CCallAddrCase::GetLocalIpAddr(void)
{
    WSAData wsaData;
    WSAStartup( 0x0202, &wsaData );

    u32 *pdwLocalIp = NULL;
    s32 nIpNum = 0;
    CCallAddr::GetLocalIpAddr( pdwLocalIp, nIpNum );
    DEL_PTR_ARRAY( pdwLocalIp );
    CPPUNIT_ASSERT( nIpNum > 0 );

    WSACleanup();
}