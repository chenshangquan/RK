/*=======================================================================
ģ����      :NmsCommon.lib��Ԫ����
�ļ���      : tplarray.cpp
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
#include "tplarray.h"
#include "nmscommon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define TEST_SIZE              49

#define ADD_INIT_ITEM                                   \
    TplArray<u32> tplArray;                             \
    for(s32 nIndex = 0; nIndex < TEST_SIZE; nIndex++)   \
    {                                                   \
        u32 dwItem = nIndex + 10;                       \
        tplArray.Add(&dwItem);                          \
    }

//////////////////////////////////////////////////////////////////////////
// CTplArrayCase

void CTplArrayCase::setUp()
{
}

void CTplArrayCase::tearDown()
{
}

/*========================================================================
�� �� ����NewDelete
��    �ܣ����Է����ɾ���ռ�
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::NewDelete()
{
#ifdef _DEBUG
	CMemoryState cStateInit, cStateEnd, cStateDiff;    
	cStateInit.Checkpoint();

	TplArray<u32> *ptplArray = new TplArray<u32>;

    for(s32 nIndex = 0; nIndex < TEST_SIZE; nIndex++)
    {
        u32 dwValue = nIndex + 10;
        ptplArray->Add(&dwValue);
    }

	DEL_PTR(ptplArray);

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
�� �� ����SetGetInvalidItem
��    �ܣ��趨��ȡ����Ч��Ԫ��
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::SetGetInvalidItem()
{
    TplArray<u32> tplArray;
    u32 dwInvalid = 0xFFFF00FF;
    TplArray<u32>::SetInvalidItem(dwInvalid);
    u32 dwNewValue = TplArray<u32>::GetInvalidItem();
    CPPUNIT_ASSERT(dwInvalid == dwNewValue);
}

/*========================================================================
�� �� ����Add
��    �ܣ����Ԫ��
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::Add()
{
    TplArray<u32> tplArray;

    for(s32 nIndex = 0; nIndex < TEST_SIZE; nIndex++)
    {
        u32 dwValue = nIndex + 10;
        s32 nRet = tplArray.Add(&dwValue);
        CPPUNIT_ASSERT(nRet == nIndex);

        s32 nSize = tplArray.Size();
        CPPUNIT_ASSERT(nSize == nIndex + 1);
    }

    for(nIndex = 0; nIndex < TEST_SIZE; nIndex++)
    {
        u32 dwValue = tplArray[nIndex];
        CPPUNIT_ASSERT(dwValue == nIndex + 10);
    }
}

/*========================================================================
�� �� ����InsertAtHead
��    �ܣ��ڿ�ͷ�����
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::InsertAtHead()
{
    TplArray<u32> tplArray;

    // �����һ����
    u32 adwItemTab[] = { 3, 8, 1, 20, 13, 5, 67, 308 };
    s32 nTabSize = sizeof(adwItemTab) / sizeof(u32);

    // һ�β���һ��, ����ǰ������
    for(s32 nIndex = 0; nIndex < TEST_SIZE; nIndex++)
    {
        s32 nRet = tplArray.Insert(0, adwItemTab, nTabSize);
        CPPUNIT_ASSERT(tplArray.Size() == (nIndex + 1) * nTabSize);
        CPPUNIT_ASSERT(nRet == 0);
    }

    for(nIndex = 0; nIndex < TEST_SIZE; nIndex++)
    {
        for(s32 nItemIdx = 0; nItemIdx < nTabSize; nItemIdx++)
        {
            u32 dwItem = adwItemTab[nItemIdx];
            s32 nPos = nIndex * nTabSize + nItemIdx;

            CPPUNIT_ASSERT(tplArray[nPos] == dwItem);
        }
    }
}

/*========================================================================
�� �� ����InsertAtMid
��    �ܣ����м����
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::InsertAtMid()
{
    ADD_INIT_ITEM

    // �����һ����
    u32 adwItemTab[] = { 3, 8, 1, 20, 13, 5, 67, 308 };
    s32 nTabSize = sizeof(adwItemTab) / sizeof(u32);

    s32 nInsPos = TEST_SIZE / 2;
    s32 nRet = tplArray.Insert(nInsPos, adwItemTab, nTabSize);
    CPPUNIT_ASSERT(nRet == nInsPos);

    // ���ǰ���Ԫ��
    for(nIndex = 0; nIndex < nInsPos; nIndex++)
    {
        CPPUNIT_ASSERT(tplArray[nIndex] == nIndex + 10);
    }
    // �������Ԫ��
    for(s32 nInsIdx = 0; nIndex < nInsPos + nTabSize; nIndex++, nInsIdx++)
    {
        CPPUNIT_ASSERT(tplArray[nIndex] == adwItemTab[nInsIdx]);
    }
    // �����Ƶ�Ԫ��
    for(; nIndex < TEST_SIZE + nTabSize; nIndex++)
    {
        CPPUNIT_ASSERT(tplArray[nIndex] == nIndex - nTabSize + 10);
    }
}

/*========================================================================
�� �� ����InsertAtTail
��    �ܣ���ĩβ���
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::InsertAtTail()
{
    ADD_INIT_ITEM

    // �����һ����
    u32 adwItemTab[] = { 3, 8, 1, 20, 13, 5, 67, 308 };
    s32 nTabSize = sizeof(adwItemTab) / sizeof(u32);

    s32 nRet = tplArray.Insert(tplArray.Size(), adwItemTab, nTabSize);
    CPPUNIT_ASSERT(nRet == TEST_SIZE);

    // ���ǰ���Ԫ��
    for(nIndex = 0; nIndex < TEST_SIZE; nIndex++)
    {
        CPPUNIT_ASSERT(tplArray[nIndex] == nIndex + 10);
    }
    // �������Ԫ��
    for(s32 nItemIdx = 0; nItemIdx <nTabSize; nIndex++, nItemIdx++)
    {
        CPPUNIT_ASSERT(tplArray[nIndex] == adwItemTab[nItemIdx]);
    }
}

#ifndef _DEBUG
/*========================================================================
�� �� ����InsertBeforeHead
��    �ܣ�����ֵΪ�������
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::InsertBeforeHead()
{
    TplArray<u32> tplArray;

    u32 adwItemTab[] = { 3, 8, 1, 20, 13, 5, 67, 308 };
    s32 nTabSize = sizeof(adwItemTab) / sizeof(u32);

    s32 nRet = tplArray.Insert(-1, adwItemTab, nTabSize);
    CPPUNIT_ASSERT(nRet < 0);
}

/*========================================================================
�� �� ����InsertBeyondTail
��    �ܣ�����ֵ���������С
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::InsertBeyondTail()
{
    ADD_INIT_ITEM

    u32 adwItemTab[] = { 3, 8, 1, 20, 13, 5, 67, 308 };
    s32 nTabSize = sizeof(adwItemTab) / sizeof(u32);

    s32 nRet = tplArray.Insert(tplArray.Size() + 1, adwItemTab, nTabSize);
    CPPUNIT_ASSERT(nRet < 0);
}
#endif // _DEBUG

/*========================================================================
�� �� ����DeleteFromHead
��    �ܣ���ͷ��ɾ��
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::DeleteFromHead()
{
    ADD_INIT_ITEM

#define DEL_SIZE                13
    s32 nRet = tplArray.Delete(0, DEL_SIZE);
    CPPUNIT_ASSERT(nRet == DEL_SIZE);

    CPPUNIT_ASSERT(tplArray.Size() == TEST_SIZE - DEL_SIZE);

    for(nIndex = 0; nIndex < TEST_SIZE - DEL_SIZE; nIndex++)
    {
        CPPUNIT_ASSERT(tplArray[nIndex] == nIndex + DEL_SIZE + 10);
    }

#undef DEL_SIZE
}

/*========================================================================
�� �� ����DeleteMidNoExceed
��    �ܣ����м�ɾ�����������ϱ߽�
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::DeleteMidNoExceed()
{
    ADD_INIT_ITEM

    s32 nDelPos = TEST_SIZE / 2;
#define DEL_SIZE                13
    s32 nRet = tplArray.Delete(nDelPos, DEL_SIZE);
    CPPUNIT_ASSERT(nRet == DEL_SIZE);

    CPPUNIT_ASSERT(tplArray.Size() == TEST_SIZE - DEL_SIZE);

    // ǰ���Ԫ��û�иı�
    for(nIndex = 0; nIndex < nDelPos; nIndex++)
    {
        CPPUNIT_ASSERT(tplArray[nIndex] == nIndex + 10);
    }
    // �������Ԫ��
    for(; nIndex < TEST_SIZE - DEL_SIZE; nIndex++)
    {
        CPPUNIT_ASSERT(tplArray[nIndex] == nIndex + DEL_SIZE + 10);
    }

#undef DEL_SIZE
}

/*========================================================================
�� �� ����DeleteMidExceed
��    �ܣ����м�ɾ���������ϱ߽�
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::DeleteMidExceed()
{
    ADD_INIT_ITEM

    s32 nDelPos = TEST_SIZE / 2;
#define DEL_SIZE                50
    s32 nRet = tplArray.Delete(nDelPos, DEL_SIZE);

    CPPUNIT_ASSERT(nRet == TEST_SIZE - nDelPos);

    CPPUNIT_ASSERT(tplArray.Size() == nDelPos);

    // ǰ���Ԫ��û�иı�
    for(nIndex = 0; nIndex < nDelPos; nIndex++)
    {
        CPPUNIT_ASSERT(tplArray[nIndex] == nIndex + 10);
    }
#undef DEL_SIZE
}

#ifndef _DEBUG
/*========================================================================
�� �� ����DeleteBeforeHead
��    �ܣ�ɾ��������Ϊ��ֵ
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::DeleteBeforeHead()
{
    ADD_INIT_ITEM

    s32 nRet = tplArray.Delete(-1, 3);
    CPPUNIT_ASSERT(nRet < 0);
}

/*========================================================================
�� �� ����DeleteAfterTail
��    �ܣ�ɾ�������������ϱ߽�
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::DeleteAfterTail()
{
    ADD_INIT_ITEM

    s32 nRet = tplArray.Delete(TEST_SIZE, 3);
    CPPUNIT_ASSERT(nRet < 0);
}
#endif // _DEBUG

/*========================================================================
�� �� ����Clear
��    �ܣ����Ԫ��
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::Clear()
{
    ADD_INIT_ITEM

    tplArray.Clear();
    
    CPPUNIT_ASSERT(tplArray.Size() == 0);
    CPPUNIT_ASSERT(tplArray.GetMaxSize() == 0);
#ifndef _DEBUG
    CPPUNIT_ASSERT(tplArray.GetItemPtr(0) == NULL);
#endif // _DEBUG
}

/*========================================================================
�� �� ����SetAt
��    �ܣ�����Ч�������趨Ԫ��
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::SetAt()
{
    ADD_INIT_ITEM

    u32 adwItemTab[] = { 3, 8, 1, 20, 13, 5, 67, 308 };
    s32 nTabSize = sizeof(adwItemTab) / sizeof(u32);

    s32 nStartPos = TEST_SIZE / 2;
    for(nIndex = 0; nIndex < nTabSize; nIndex++)
    {
        s32 nSetPos = nStartPos + nIndex;
        BOOL bRet = tplArray.SetAt(nSetPos, adwItemTab + nIndex);
        CPPUNIT_ASSERT(bRet == TRUE);
        CPPUNIT_ASSERT(tplArray[nSetPos] == adwItemTab[nIndex]);
    }
}

#ifndef _DEBUG
/*========================================================================
�� �� ����SetAtBeforeHead
��    �ܣ��趨Ԫ������Ϊ��ֵ
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::SetAtBeforeHead()
{
    ADD_INIT_ITEM

    u32 dwItem = 33;
    BOOL bRet = tplArray.SetAt(-1, &dwItem);
    CPPUNIT_ASSERT(bRet == FALSE);
}

/*========================================================================
�� �� ����SetAtAfterTail
��    �ܣ��趨Ԫ�����������ϱ߽�
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::SetAtAfterTail()
{
    ADD_INIT_ITEM

    u32 dwItem = 33;
    BOOL bRet = tplArray.SetAt(TEST_SIZE, &dwItem);
    CPPUNIT_ASSERT(bRet == FALSE);
}

/*========================================================================
�� �� ����SetAtNullPtr
��    �ܣ��趨��ָ��Ԫ��
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::SetAtNullPtr()
{
    ADD_INIT_ITEM

    BOOL bRet = tplArray.SetAt(3, NULL);
    CPPUNIT_ASSERT(bRet == FALSE);
}
#endif// _DEBUG

/*========================================================================
�� �� ����GetAt
��    �ܣ�����Ч�����ڻ�ȡԪ��
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::GetAt()
{
    ADD_INIT_ITEM

    for(nIndex = 0; nIndex < TEST_SIZE; nIndex++)
    {
        u32 dwItem = tplArray.GetAt(nIndex);
        CPPUNIT_ASSERT(dwItem == nIndex + 10);
    }
}

#ifndef _DEBUG
/*========================================================================
�� �� ����GetAtBeforeHead
��    �ܣ���ȡԪ�ص�����Ϊ��
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::GetAtBeforeHead()
{
    ADD_INIT_ITEM

    u32 dwInvalid = 0xFF00FF;
    TplArray<u32>::SetInvalidItem(dwInvalid);

    u32 dwItem = tplArray.GetAt(-1);
    CPPUNIT_ASSERT(dwItem == dwInvalid);
}

/*========================================================================
�� �� ����GetAtAfterTail
��    �ܣ���ȡԪ�ص����������ϱ߽�
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::GetAtAfterTail()
{
    ADD_INIT_ITEM

    u32 dwInvalid = 0xFF00FF;
    TplArray<u32>::SetInvalidItem(dwInvalid);

    u32 dwItem = tplArray.GetAt(TEST_SIZE);
    CPPUNIT_ASSERT(dwItem == dwInvalid);
}
#endif// _DEBUG

/*========================================================================
�� �� ����GetItemPtr
��    �ܣ�����Ч�����ڵõ�Ԫ��ָ��
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::GetItemPtr()
{
    ADD_INIT_ITEM

    const u32 *pdwStart = tplArray.GetItemPtr(0);
    CPPUNIT_ASSERT(pdwStart != NULL);

    for(nIndex = 1; nIndex < TEST_SIZE; nIndex++)
    {
        const u32 *pdwItem = tplArray.GetItemPtr(nIndex);
        CPPUNIT_ASSERT(pdwItem != NULL);
        CPPUNIT_ASSERT(pdwItem - pdwStart == nIndex);
    }
}

#ifndef _DEBUG
/*========================================================================
�� �� ����GetPtrBeforeHead
��    �ܣ���ȡ��Ԫ��ָ������Ϊ��ֵ
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::GetPtrBeforeHead()
{
    ADD_INIT_ITEM

    const u32 *pdwStart = tplArray.GetItemPtr(-1);
    CPPUNIT_ASSERT(pdwStart == NULL);
}

/*========================================================================
�� �� ����GetPtrAfterTail
��    �ܣ���ȡ��Ԫ��ָ�����������ϱ߽�
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::GetPtrAfterTail()
{
    ADD_INIT_ITEM

    const u32 *pdwStart = tplArray.GetItemPtr(TEST_SIZE);
    CPPUNIT_ASSERT(pdwStart == NULL);
}
#endif // _DEBUG

/*========================================================================
�� �� ����IsEmpty
��    �ܣ������Ƿ�Ϊ��
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::IsEmpty()
{
    TplArray<u32> tplArray;

    CPPUNIT_ASSERT(tplArray.IsEmpty() == TRUE);
    for(s32 nIndex = 0; nIndex < TEST_SIZE; nIndex++)
    {
        u32 dwItem = nIndex + 10;
        tplArray.Add(&dwItem);
    }

    CPPUNIT_ASSERT(tplArray.IsEmpty() == FALSE);

    tplArray.Clear();
    CPPUNIT_ASSERT(tplArray.IsEmpty() == TRUE);
}

/*========================================================================
�� �� ����OpEqual
��    �ܣ�=���Ƿ���ȷ������Ϣ
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::OpEqual()
{
    TplArray<u32> tplOldArray(11, 13);
    for(s32 nIndex = 0; nIndex < TEST_SIZE; nIndex++)
    {
        u32 dwItem = nIndex + 10;
        tplOldArray.Add(&dwItem);
    }

    TplArray<u32> tplNewArray;
    tplNewArray = tplOldArray;

    CPPUNIT_ASSERT(tplOldArray.Size() == tplNewArray.Size());
    CPPUNIT_ASSERT(tplOldArray.Size() == tplNewArray.GetMaxSize());
    CPPUNIT_ASSERT(tplOldArray.GetStep() == tplNewArray.GetStep());

    for(nIndex = 0; nIndex < TEST_SIZE; nIndex++)
    {
        CPPUNIT_ASSERT(tplOldArray[nIndex] == tplNewArray[nIndex]);
    }
}

/*========================================================================
�� �� ����GetMaxSize
��    �ܣ��õ���������ռ�
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::GetMaxSize()
{
    TplArray<u32> tplArray;
    CPPUNIT_ASSERT(tplArray.GetMaxSize() == 10);

    for(s32 nIndex = 0; nIndex < TEST_SIZE; nIndex++)
    {
        u32 dwItem = nIndex + 10;
        tplArray.Add(&dwItem);
    }

    s32 nStep = tplArray.GetStep();
    s32 nSize = (TEST_SIZE + nStep - 1) / nStep * nStep;
    CPPUNIT_ASSERT(tplArray.GetMaxSize() == nSize);
}

/*========================================================================
�� �� ����GetStep
��    �ܣ��õ���������Ĳ���
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::GetStep()
{
    TplArray<u32> tplArray;
    CPPUNIT_ASSERT(tplArray.GetStep() == 10);

    for(s32 nIndex = 0; nIndex < TEST_SIZE; nIndex++)
    {
        u32 dwItem = nIndex + 10;
        tplArray.Add(&dwItem);
    }

    CPPUNIT_ASSERT(tplArray.GetStep() == 10);
}

/*========================================================================
�� �� ����GetData
��    �ܣ��õ�������׵�ַ
��    ����
�� �� ֵ��
--------------------------------------------------------------------------
�޸ļ�¼��
��		��	�汾	�޸���	�޸�����
2005/01/25	3.6		���ǿ	����
========================================================================*/
void CTplArrayCase::GetData()
{
    TplArray<u32> tplArray;
    CPPUNIT_ASSERT(tplArray.GetData() != NULL);

    for(s32 nIndex = 0; nIndex < TEST_SIZE; nIndex++)
    {
        u32 dwItem = nIndex + 10;
        tplArray.Add(&dwItem);
    }

    CPPUNIT_ASSERT(tplArray.GetData() != NULL);

    tplArray.Clear();
    CPPUNIT_ASSERT(tplArray.GetData() == NULL);
}


