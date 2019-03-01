/*****************************************************************************
   ģ����      : PCDV
   �ļ���      : pcdvcomm.h
   ����ļ�    : 
   �ļ�ʵ�ֹ���: PCDV �ڲ��ṹ����
   ����        : 
   �汾        : V4.0  Copyright(C) 2004-2007 KDC, All rights reserved.
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���      �޸�����
   2006/12/31  4.0         ����      ����
******************************************************************************/

#ifndef _PCDVCOMM_H_
#define _PCDVCOMM_H_

#include "osp.h"

//#define SOFT_CODEC

#include "pcdualvideoevent.h"
#include "mttype.h"
#include "mtstruct.h"
#include "codecevent.h"
#include "callevent.h"
#include "ummessagestruct.h"

#define PCDV_VER            (const char*)"pcdv40.40.01.04.070621 R4"

const u16 RTP_LOCALSNAP_PORT  = 40200;
const u16 wMtListenPort = 60000;

// ������
#define  PCDV_RET_OK                (u16)0
#define  PCDV_RET_OSPFAILED         (u16)1001   // OSP ʧ��
#define  PCDV_RET_NETWORKFAILED     (u16)1002   // ����ͨ�Ŵ���
#define  PCDV_RET_BUSY              (u16)1003   // Ӧ��æ
#define  PCDV_RET_AUTHFAIL          (u16)1004   // �û���֤ʧ��
#define  PCDV_RET_DUPLOGIN          (u16)1005   // �����û���¼
#define  PCDV_RET_INCOMPVER         (u16)1006   // �汾������
#define  PCDV_RET_NOPERMIT          (u16)1007   // û��Ȩ��
#define  PCDV_RET_ENCODEFAIL        (u16)1008   // ��ʼ���沶׽ʧ��
#define  PCDV_RET_RESNONSTANDARD    (u16)1009   // ����ֱ��ʲ�֧��
#define  PCDV_RET_RES_DIFF_HIGH     (u16)1010   // �ն˺�pc�ķֱ��ʲ�һֵ(�����ֱ��ʸ���)
#define  PCDV_RET_RES_DIFF_LOW      (u16)1011   // �ն˺�pc�ķֱ��ʲ�һֵ(�����ֱ��ʵ���)
// ʱ��
#define  TIMEOUT_CONNECT            (u32)5000
#define  TIMEOUT_REQ                (u32)15000

// ���Կ���
#define PCDV_DEBUG_CRITICAL           (u8)0
#define PCDV_DEBUG_WARNING            (u8)1
#define PCDV_DEBUG_INFO               (u8)2

// �ֱ��ʶ���
#define RES_VGA_X       640
#define RES_VGA_Y       480
#define RES_SVGA_X      800
#define RES_SVGA_Y      600
#define RES_XGA_X       1024
#define RES_XGA_Y       768
#define RES_SXGA_X		1280	//SQ081218
#define RES_SXGA_Y		1024
#define RES_UXGA_X		1600
#define RES_UXGA_Y		1200
// uilib ����
#define TITLEHIGHT          20
#define COLOR_TITLEHILIGT   RGB(216, 228, 235)
#define COLOR_TITLELOW      RGB(54, 95, 135)
#define COLOR_BKWHITE       RGB(255, 255, 255)
#define COLOR_TEXT          RGB(67,108,145)
#define COLOR_BKDIALOG      RGB(226,234,240)


#define LOCAL_IP        htonl(0x7f000001)
#define WM_ICONNOTIFY   (WM_USER + 0xA0)

#define START_WAIT {BeginWaitCursor(); SetCapture(); }
#define END_WAIT   {RestoreWaitCursor(); EndWaitCursor(); ReleaseCapture();}


enum enState
{
    stateIdle = 0,      // �ն�δ����
    stateConnectedIdle, // ���ڻ�����
    stateInConf,        // �ڻ�����
    stateSending        // �ڷ���˫��
};

//��������
enum EMLanType
{
    enumLanTypeCHN      = 1,    //��������
    enumLanTypeENG      = 2,     //Ӣ��
	enumLanTypeOTHER      = 3    //�������֣�ͨ��ѡ�����԰���ʽѡ�񣬲��޾�������
};

#define FILENAME_CFG    "pcdv.ini"

void ShowMsg(LPCSTR lpszMsg );

#endif 