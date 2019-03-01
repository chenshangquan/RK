/*=======================================================================
ģ����      :NmsCommon.lib��Ԫ����
�ļ���      : api.h
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
#ifndef _API_H
#define _API_H

#include "testcase.h"
#include "extensions\HelperMacros.h"

class CAPICase : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(CAPICase);
		CPPUNIT_TEST_NEW(GetConfBitrate, "GetConfBitrate");
		CPPUNIT_TEST_NEW(GetModuleFullPath, "GetModuleFullPath");
		CPPUNIT_TEST_NEW(nmscommonver, "nmscommonver");
		CPPUNIT_TEST_NEW(ModuleRegToOsp, "ModuleRegToOsp");
        CPPUNIT_TEST_NEW(Encrypt,           "�ӽ���");
    CPPUNIT_TEST_SUITE_END_NEW("Global API");
public:
	void setUp();
	void tearDown();
public:
    // �õ���������
    void GetConfBitrate();
    // �õ�ģ��ȫ·��
    void GetModuleFullPath();
    // �õ���İ汾��
    void nmscommonver();
    // ��ospע��ģ��
    void ModuleRegToOsp();
    //�ӽ���
    void Encrypt(void);
};

#endif // _API_H
