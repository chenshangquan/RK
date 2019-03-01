/*=======================================================================
ģ����      : �ն˿���̨
�ļ���      : MtcLib.h
����ļ�    : 
�ļ�ʵ�ֹ���: �����ն˿���̨�ӿ�
����        : �ܹ㻯
�汾        : V3.0  Copyright(C) 1997-2003 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2003/12/15  3.0         �ܹ㻯      ����
2004/08/23  3.5         ���ǿ      �淶���룬���Ľṹ
2005/06/22  3.6         �ź���      �޸ģ����������벻ͬ��ͷ�ļ��У���С����������
=======================================================================*/
#ifndef MTCLIB_H
#define MTCLIB_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning( disable : 4786 )	// ��ʶ�����Ƴ���255�ֽ�
#include <vector>
#include <map>

#include <afxmt.h>
#include "kdvType.h"		// ��������
#include "kdvdef.h"			// �����궨��
#include "osp.h"			// OSPҵ��
#include "MtcLibEvent.h"	// �ն˿���̨�ڲ��¼�
#include "MtcLibError.h"	// ������
#include "ummessagestruct.h"// �����֤ҵ��
#include "evusermanage.h"	// �����֤ҵ��
#include "Addrbook.h"		// ��ַ��ҵ��
//#include "vccommon.h"		// �ն˿���ҵ��
#include "IMtcConnectMt.h"
#include "MtcMt.h"

#define AID_MTC_INTTEST	AID_MTC_BGN + 0	// 21 @kdvDef.h

typedef void (CALLBACK* SDKCALLBACKFUNC)(DWORD dwMsgID, WPARAM wParam, LPARAM lParam);

class CDispEvent;
////////////////////////////////////////////////////////////////////////////////
class CMtcLib
{
	friend class CDispEvent;
public:
	/*����	����ʵ���˽ӿ�IMtcConnectMt�Ķ���
	����	ppICnt	[out]�ɹ�����IMtcConnectMt�ӿ�,ʧ�ܷ���NULL
	����ֵ	�ɹ�����0,ʧ�ܷ��ط�0������
	˵��	�ӿ�ʹ����ɺ�,����DestroyInstance�������ٶ���*/
	static u16 CreateInstance(IMtcConnectMt **ppICnt);
	/*����	����ʵ���˽ӿ�IMtcConnectMt�Ķ���
	����	ppICnt	[in, out]�ӿ�IMtcConnectMt,�ɹ��󷵻�NULL
	����ֵ	�ɹ�����0,ʧ�ܷ��ط�0������
	˵��	ֻ��������CreateInstance���������Ķ���*/
	static u16 DestroyInstance(IMtcConnectMt **ppICnt);
	/*����	��ȡ������ѡIP
	����	��
	����ֵ	������ѡIP(������)
	˵��	��*/
	static u32 GetHostIP();
	/*����	������Ϣ���ͽ��յ�����Ϣ
	����	b32On		�Ƿ����
			dwCatalog	��Ϣ���
	����ֵ	��
	˵��	��*/
	static void MsgLog(BOOL b32On, u32 dwCatalog);
	/*����	��ȡ���������Ϣ���״̬
    ����	dwSN		�Ƿ����
            dwCatalog	��Ϣ���
    ����ֵ	��
    ˵��	��*/
	static void GetTraceStatus(u32 &dwSN, u32* dwCatalog);


	static void SetPointOfCallBackFunc(SDKCALLBACKFUNC  pCallBack);
	
	static SDKCALLBACKFUNC m_spCallBackFunc;

private:
#define MTC_MSGCATALOG_COUNT 12
	// ��Ϣ���������Ϣ���״̬
	static u32 s_dwCatalog[MTC_MSGCATALOG_COUNT];
	// ��Ϣ����˵��
	static char* s_szCataDesc[MTC_MSGCATALOG_COUNT];
	static CCriticalSection s_csCatalog;
	// �޸����,����ͬ����ʶ
	static u32 s_dwSN;
};
API void cls();
API u32 mtclibver();
API u32 mtclibhelp();
API void cfghelp();
API void confhelp();
API u32 mtclibmsgon(u32 dwOn);
API u32 mtclibmsgoff(u32 dwOff);

//MutiConf
API void mtlist();
API void confinfo();
API void conflist();
API void reqchairlist();
API void reqspeaklist();
API void vmpstatus();
API void pollstatus();
//p2p
API void caller();
API void mtme();

//audio
API void audio();

//address
API void addrinfo();

//snap
API void snap();

//user
API void alluser();


//����
API void h323cfg();
API void usercfg();
API void osdcfg();
API void avpriorcfg();
API void videoparam(u8 byType);
API void audioparam();
API void firewall(); 
API void napmapcfg();
API void ethnetcfg();
API void snmpcfg();
API void pppoecfg();
API void cameracfg();
API void serialcfg();
API void qoscfg();
API void imageadjust();
API void videosource();
API void e1cfg();
API void allroutecfg();

API void reqikey(u8 byLocal);


#endif //MTCLIB_H










































