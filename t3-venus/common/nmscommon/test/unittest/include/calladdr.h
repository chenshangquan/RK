/*=======================================================================
ģ����      :NmsCommon.lib��Ԫ����
�ļ���      : calladdr.h
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
#ifndef _CALLADDR_H
#define _CALLADDR_H
    
#include "testcase.h"
#include "extensions\HelperMacros.h"

class CCallAddrCase : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(CCallAddrCase);
		CPPUNIT_TEST_NEW(NewDelete,         "New&Delete");
		CPPUNIT_TEST_NEW(IsValidIplpStr,    "IsValidIpV4 - �ִ���");
		CPPUNIT_TEST_NEW(IsValidIpCString,  "IsValidIpV4 - CString��");
		CPPUNIT_TEST_NEW(IsValidIpDword,    "IsValidIpV4 - DWORD��");
		CPPUNIT_TEST_NEW(GetLastErrorInfo,  "GetLastErrorInfo");
		CPPUNIT_TEST_NEW(GetIpStr,          "GetIpStr");
		CPPUNIT_TEST_NEW(GetCallStrType,    "GetCallStrType");
		CPPUNIT_TEST_NEW(IsValidIpMask,     "IsValidIpMask ");
		CPPUNIT_TEST_NEW(IsValidIpMaskStr,  "IsValidIpMask - �ִ���");
        CPPUNIT_TEST_NEW(GetLocalIpAddr,    "��ȡ��������IP��ַ");
    CPPUNIT_TEST_SUITE_END_NEW("CCallAddr");

public:
	void setUp();
	void tearDown();
public:
    // �����ɾ���ռ�
    void NewDelete();
    // �ִ���IP��ַ����Ч���ж�
    void IsValidIplpStr();
    // CString��IP��ַ����Ч���ж�
    void IsValidIpCString();
    // ˫�ֽ���IP��ַ����Ч���ж�
    void IsValidIpDword();
    // ���س�����Ϣ
    void GetLastErrorInfo();
    // ˫�ֽڵ��ִ��͵�ַ��ת��
    void GetIpStr();
    // �õ��ִ��Ǻ��ֺ�������
    void GetCallStrType();
	//�Ƿ���һ���Ϸ���IP����
	void IsValidIpMask();
	//�Ƿ���һ���Ϸ���Ip���룬�ַ�����
	void IsValidIpMaskStr();
    //  ��ȡ��������IP��ַ
    void GetLocalIpAddr(void);
};

#endif