/*****************************************************************************
ģ����      : �ն˿���̨
�ļ���      : MtcLibError.h
����ļ�    : 
�ļ�ʵ�ֹ���: �����������
����        : �ܹ㻯
�汾        : V3.0  Copyright(C) 1997-2003 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2003/12/16  3.0         �ܹ㻯      ����
******************************************************************************/
#pragma once

/* ժ��errorid.h
�ն˿���̨����(14001-16000)
#define ERR_MTC_BGN		ERR_MC_END + 0x0001
#define ERR_MTC_END		ERR_MTC_BGN + 0x07cf*/
#include "errorid.h"	// �����뷶Χ�ζ���

// �ն˿���̨����
#define ERR_MTC						ERR_MTC_BGN + 0x0000

// ��¼ʧ��,δ֪���û�������������
#define ERR_MTC_LOGON_FAILURE		ERR_MTC_BGN + 0x0001

// ��ǰ���޷���ͬ���ն�����,��Ϊ�Ѵﵽ�ն˵�������Ŀ����
#define ERR_MTC_CAPACITY_LIMIT		ERR_MTC_BGN + 0x0002

// ����ͬ�µ��ն�����,��Ϊ��ǰ�����ӻ�û�б��ر�
#define ERR_MTC_ACTIVE_CONNECTION	ERR_MTC_BGN + 0x0003

// TCP����ͨ�Ź���
#define ERR_MTC_TCP					ERR_MTC_BGN + 0x0004

// ��Ч�ľ��
#define	ERR_MTC_INVALID_HANDLE		ERR_MTC_BGN + 0x0005

// OSP��ʼ��ʧ��
#define ERR_MTC_OSP_INIT_FAILURE	ERR_MTC_BGN + 0x0006

// OSPû�г�ʼ��
#define ERR_MTC_OSP_NOT_INIT		ERR_MTC_BGN + 0x0007

// ��Ч��ͨ�Žڵ�
#define ERR_MTC_INVALID_NODE		ERR_MTC_BGN + 0x0008

// ��������ʵ��ʧ��
#define ERR_MTC_CREATEINSTANCE		ERR_MTC_BGN + 0x0009

// �ӿ���Ч
#define ERR_MTC_INTERFACE			ERR_MTC_BGN + 0x000a

// ��ʱ
#define ERR_MTC_TIMEOUT				ERR_MTC_BGN + 0x000b

// δ��
#define ERR_MTC_PENDING				ERR_MTC_BGN + 0x000c

// ��Ч����
#define ERR_MTC_INDEX				ERR_MTC_BGN + 0x000d

// û��ʵ��
#define ERR_MTC_NOT_IMPLEMENT		ERR_MTC_BGN + 0x000e

// �����������
#define ERR_MTC_EXCEED_CAPACITY		ERR_MTC_BGN + 0x000f

// ��֧�ֲ�������
#define ERR_MTC_CONCURRENT_CMD		ERR_MTC_BGN + 0x0010

// �Ѿ���һ���ļ����ڴ���
#define ERR_MTC_BUSY_TRANSFER		ERR_MTC_BGN + 0x0011

// ��������뻺������У��ȴ�����
#define MTC_WAIT_FOR_SEND_CMD		ERR_MTC_BGN + 0x0010