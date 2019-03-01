/*=============================================================================
ģ   ��   ��: �ļ������ͻ���ҵ���ܿ�
��   ��   ��: succonst.h
�� ��  �� ��: ��
�ļ�ʵ�ֹ���: sucģ�鹫�ú궨��
��        ��: ���
��        ��: V1.0  Copyright(C) 2006-2007 Kedacom, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2007/02/11  1.0     ���        ����
=============================================================================*/

#ifndef _SUCCONST_
#define _SUCCONST_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//suclib���ʵ����
#define MAXINST_SUCLIB_NUM              (s32)16

//��ʱʱ��(6��)
#define DEFAULT_TIMEOUT                 (u32)(6 * 1000)

//Ȩ��
#define RIGHT_ADMIN                     (u8)1//����Ա
#define RIGHT_OPERATOR                  (u8)0//����Ա

//������
#define SUCLIB_ERRORCODE_BEGIN          (u16)10000
#define SUCLIB_ERRORCODE_END            (u16)20000
#define SUCLIB_OK                       (u16)0
//#define SUCLIB_PWD_EMPTY                (SUCLIB_ERRORCODE_BEGIN + 1)
#define SUCLIB_ALREADY_CONNECT          (SUCLIB_ERRORCODE_BEGIN + 2)
#define SUCLIB_CONNECT_FAIL             (SUCLIB_ERRORCODE_BEGIN + 3)
#define SUCLIB_POST_MSG_TO_SUS_FAIL     (SUCLIB_ERRORCODE_BEGIN + 4)
#define SUCLIB_MSG_LEN_ERROR            (SUCLIB_ERRORCODE_BEGIN + 5)
#define SUCLIB_BUSY_LAST_REQ            (SUCLIB_ERRORCODE_BEGIN + 6)
#define SUCLIB_NO_RIGHT                 (SUCLIB_ERRORCODE_BEGIN + 7)
#define SUCLIB_READ_FILE_FAIL           (SUCLIB_ERRORCODE_BEGIN + 8)


#define SUC_EVENT(msg, id)      const u16 msg = (u16)(id);


#define SUCLIB_MSG_BGN              WM_USER + 0x500
#define SUCLIB_MSG_END              WM_USER + 0x800



#endif//_SUCCONST_
