/*=======================================================================
ģ����      :NmsCommon.lib��Ԫ����
�ļ���      : tplhash.h
����ļ�    :
�ļ�ʵ�ֹ��� :
����        : ���ǿ
�汾        : V3.6  Copyright(C) 2003-2005 Suzhou Keda Technology Co.Ltd
                    All rights reserved.
--------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2005/01/26  3.6         ���ǿ      ����
=======================================================================*/
#ifndef _TPLHASH_H
#define _TPLHASH_H

#include "testcase.h"
#include "extensions\HelperMacros.h"
#include "nmscommon.h"

class CTplHashCase : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(CTplHashCase);
        CPPUNIT_TEST_NEW(HashTest,          "hash����");
    CPPUNIT_TEST_SUITE_END_NEW("TplHash");

public:
	virtual void setUp();
	virtual void tearDown();

    void HashTest(void);

private:
    void NoItem(TplHash<u32, s16> &tplHash);
    void OneItem(TplHash<u32, s16> &tplHash);
    void TwoItems(TplHash<u32, s16> &tplHash);
    void ThreeItems(TplHash<u32, s16> &tplHash);
    void FourItems(TplHash<u32, s16> &tplHash);
    void FiveItems(TplHash<u32, s16> &tplHash);

    void FivePart1(TplHash<u32, s16> &tplHash);
    void FivePart2(TplHash<u32, s16> &tplHash);
    void FivePart3(TplHash<u32, s16> &tplHash);
    void FivePart4(TplHash<u32, s16> &tplHash);
    void FivePart5(TplHash<u32, s16> &tplHash);

private:
    u32 m_adwFirst[5];
    s16 m_aswSecond[5];
};

#endif // _TPLHASH_H