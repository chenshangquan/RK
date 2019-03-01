/*=======================================================================
ģ����      : NmsCommon.lib��Ԫ����
�ļ���      : tplarray.h
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
#ifndef _TPLARRAY_H
#define _TPLARRAY_H

#include "testcase.h"
#include "extensions\HelperMacros.h"

class CTplArrayCase : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE(CTplArrayCase);
		CPPUNIT_TEST_NEW(NewDelete, "New&Delete");
        CPPUNIT_TEST_NEW(SetGetInvalidItem, "SetInvalidItem&GetInvalidItem");
        CPPUNIT_TEST_NEW(Add, "Add - ����һ��");
        // Insert
        CPPUNIT_TEST_NEW(InsertAtHead, "Insert - ��ǰ������");
        CPPUNIT_TEST_NEW(InsertAtMid, "Insert - ���м����");
        CPPUNIT_TEST_NEW(InsertAtTail, "Insert - ��β������");
#ifndef _DEBUG
        CPPUNIT_TEST_NEW(InsertBeforeHead, "Insert - ��������Ϊ��");
        CPPUNIT_TEST_NEW(InsertBeyondTail, "Insert - ����λ�ó������ֵ");
#endif // _DEBUG
        // Delete
        CPPUNIT_TEST_NEW(DeleteFromHead, "Delete - ��ͷ��ʼɾ��");
        CPPUNIT_TEST_NEW(DeleteMidNoExceed, "Delete - ���м俪ʼɾ��,��Խ��");
        CPPUNIT_TEST_NEW(DeleteMidExceed, "Delete - ���м�ɾ����Խ��");
#ifndef _DEBUG
        CPPUNIT_TEST_NEW(DeleteBeforeHead, "Delete - ɾ������Ϊ��");
        CPPUNIT_TEST_NEW(DeleteAfterTail, "Delete - ɾ��λ��Խ�����ֵ");
#endif // _DEBUG

        CPPUNIT_TEST_NEW(Clear, "Clear");
        CPPUNIT_TEST_NEW(SetAt, "SetAt");
#ifndef _DEBUG
        CPPUNIT_TEST_NEW(SetAtBeforeHead, "SetAt - �趨����Ϊ��");
        CPPUNIT_TEST_NEW(SetAtAfterTail, "SetAt - �趨�����������ֵ");
        CPPUNIT_TEST_NEW(SetAtNullPtr, "SetAt - ����Ĳ���Ϊ��");
#endif// _DEBUG

        CPPUNIT_TEST_NEW(GetAt, "GetAt");
#ifndef _DEBUG
        CPPUNIT_TEST_NEW(GetAtBeforeHead, "GetAt - ��ѯ����ֵΪ��");
        CPPUNIT_TEST_NEW(GetAtAfterTail, "GetAt - ��ѯλ�ó������ֵ");
#endif// _DEBUG

        CPPUNIT_TEST_NEW(GetItemPtr, "GetItemPtr");
#ifndef _DEBUG
        CPPUNIT_TEST_NEW(GetPtrBeforeHead, "GetItemPtr - ��ѯ����ֵΪ��");
        CPPUNIT_TEST_NEW(GetPtrAfterTail, "GetItemPtr - ��ѯ�����������ֵ");
#endif // _DEBUG
        CPPUNIT_TEST_NEW(IsEmpty, "IsEmpty");
        CPPUNIT_TEST_NEW(OpEqual, "Operator =");
        CPPUNIT_TEST_NEW(GetMaxSize, "GetMaxSize");
        CPPUNIT_TEST_NEW(GetStep, "GetStep");
        CPPUNIT_TEST_NEW(GetData, "GetData");
    CPPUNIT_TEST_SUITE_END_NEW("TplArray");

public:
	virtual void setUp();
	virtual void tearDown();
public:
    // �����ɾ���ռ�
    void NewDelete();
    // �趨��ȡ����Ч��Ԫ��
    void SetGetInvalidItem();
    // ���Ԫ��
    void Add();
    // �ڿ�ͷ�����
    void InsertAtHead();
    // ���м����
    void InsertAtMid();
    // ��ĩβ���
    void InsertAtTail();
#ifndef _DEBUG
    // ����ֵΪ�������
    void InsertBeforeHead();
    // ����ֵ���������С
    void InsertBeyondTail();
#endif // _DEBUG

    // ��ͷ��ɾ��
    void DeleteFromHead();
    // ���м�ɾ�����������ϱ߽�
    void DeleteMidNoExceed();
    // ���м�ɾ���������ϱ߽�
    void DeleteMidExceed();
#ifndef _DEBUG
    // ɾ��������Ϊ��ֵ
    void DeleteBeforeHead();
    // ɾ�������������ϱ߽�
    void DeleteAfterTail();
#endif // _DEBUG
    // ���Ԫ��
    void Clear();

    // ����Ч�������趨Ԫ��
    void SetAt();
#ifndef _DEBUG
    // �趨Ԫ������Ϊ��ֵ
    void SetAtBeforeHead();
    // �趨Ԫ�����������ϱ߽�
    void SetAtAfterTail();
    // �趨��ָ��Ԫ��
    void SetAtNullPtr();
#endif // _DEBUG

    // ����Ч�����ڻ�ȡԪ��
    void GetAt();
#ifndef _DEBUG
    // ��ȡԪ�ص�����Ϊ��
    void GetAtBeforeHead();
    // ��ȡԪ�ص����������ϱ߽�
    void GetAtAfterTail();
#endif // _DEBUG

    // ����Ч�����ڵõ�Ԫ��ָ��
    void GetItemPtr();
#ifndef _DEBUG
    // ��ȡ��Ԫ��ָ������Ϊ��ֵ
    void GetPtrBeforeHead();
    // ��ȡ��Ԫ��ָ�����������ϱ߽�
    void GetPtrAfterTail();
#endif // _DEBUG
    // �����Ƿ�Ϊ��
    void IsEmpty();
    // =���Ƿ���ȷ������Ϣ
    void OpEqual();
    // �õ���������ռ�
    void GetMaxSize();
    // �õ���������Ĳ���
    void GetStep();
    // �õ�������׵�ַ
    void GetData();
};

#endif // _TPLARRAY_H