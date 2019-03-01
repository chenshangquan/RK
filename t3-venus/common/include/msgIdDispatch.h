/*****************************************************************************
ģ����      : ��Ϣ�ŷ���
�ļ���      : msgIdDispatch.h
����ļ�    : 
�ļ�ʵ�ֹ���: Ϊ��ֹ70Ŀ¼�µ�lib��Ӧ�ó�������Ϣ���ظ����ڴ�������Ϣ�ֶ�
����        : �����
�汾        : V1.0  Copyright(C) 2011-2022 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2011/7/19   1.0         �����      ����
*******************************************************************************/
#pragma once

#ifndef _MSGIDDISPATCH_20110179_H_
#define _MSGIDDISPATCH_20110179_H_

//UILib �ڲ���Ϣ



#define UILIB_MSG_BEGIN      WM_USER + 0x100 
#define UILIB_MSG_END        UILIB_MSG_BEGIN + 0x200

//slider �ſ�thumb֪ͨ
#define SLIDER_RELEASED_CAPTURE UILIB_MSG_END + 0x1
//slider thumbλ�ñ仯֪ͨ
#define SLIDER_CHANGED      SLIDER_RELEASED_CAPTURE + 0x1

//UIEXLib �ڲ���Ϣ   
#define UIEXLIB_MSG_BEGIN   SLIDER_CHANGED + 0x1
#define UIEXLIB_MSG_END     UIEXLIB_MSG_BEGIN + 0x200


// �������̨�ڲ���Ϣ  
#define CMS_MSG_BEGIN		UIEXLIB_MSG_END + 0x1
#define CMS_MSG_END         CMS_MSG_BEGIN + 0x1000 

#define UPDATECMC_MSG_BEGIN  CMS_MSG_END + 0x01
#define UPDATECMC_MSG_END    UPDATECMC_MSG_BEGIN + 0x20

//TPad�ڲ���Ϣ
#define TPAD_MSG_BEGIN		 UPDATECMC_MSG_END + 0x1
#define TPAD_MSG_END         TPAD_MSG_BEGIN + 0x200

//UMS WEB�ڲ���Ϣ
#define UMSWEB_MSG_BEGIN		 TPAD_MSG_END + 0x1
#define UMSWEB_MSG_END         UMSWEB_MSG_BEGIN + 0x200

#define UMSTOOL_MSG_BEGIN		 UMSWEB_MSG_END + 0x1
#define UMSTOOL_MSG_END         UMSTOOL_MSG_BEGIN + 0x200

#define CNSTOOL_MSG_BEGIN		 UMSTOOL_MSG_END + 0x1
#define CNSTOOL_MSG_END         CNSTOOL_MSG_BEGIN + 0x200

#define TPTOOL_MSG_BEGIN		 CNSTOOL_MSG_END + 0x1
#define TPTOOL_MSG_END         TPTOOL_MSG_BEGIN + 0x32


#endif 