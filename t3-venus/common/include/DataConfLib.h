
/*****************************************************************************
ģ����      : DataConfLib
�ļ���      : DataConfLib.h
����ļ�    : DataConfLib.cpp
�ļ�ʵ�ֹ���: CDataConfObj Class Define
����        : ����
�汾        : V3.0  Copyright(C) 2003-2005 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2004/04/22  3.0         ����      Create
******************************************************************************/

#ifndef _DATACONFLIB_0601_H_
#define _DATACONFLIB_0601_H_


//----------------------------------------------------------------------

//ģ��汾��Ϣ�ͱ���ʱ�� �� �����Ŀ�İ汾�ͱ���ʱ��
API void dataconflibfver();

//ģ�������Ϣ �� �����Ŀ�İ�����Ϣ
API void dataconflibhelp();

//----------------------------------------------------------------------

#define  WM_DCT120_CONNECTION	(WM_USER + 1)
#define  WM_DC_PLUGABLE_SOCKET  (WM_DCT120_CONNECTION + 1)

#define  WM_DC_STATE_NOTIFY     (WM_USER + 1000)

#define  DCERR_NO_ERROR          (u16)0		//DataConfLib������ɹ� 
#define  DCERR_BASE_CODE         (u16)23000	//�������׼ֵ


#define  DCERR_NOT_INIT_LIB      (u16)(DCERR_BASE_CODE + 1)//û�г�ʼ��dc��
#define  DCERR_NOT_RELEASE_LIB   (u16)(DCERR_BASE_CODE + 2)//û���ͷ�nb��
#define  DCERR_OUTOFMEMORY       (u16)(DCERR_BASE_CODE + 3)//�ڴ�������


#define  DCERR_DC_NOCREATE       (u16)(DCERR_BASE_CODE + 11)//û�гɹ�����CreateDCObj()������ЧCDCManager����
#define  DCERR_INVALID_CON_PARAM (u16)(DCERR_BASE_CODE + 12)//��������������Ч
#define  DCERR_CON_HOST          (u16)(DCERR_BASE_CODE + 13)//��������ʧ��
#define  DCERR_NO_CON_STATE      (u16)(DCERR_BASE_CODE + 14)//û�д���������״̬
#define  DCERR_OPEN_CHAT         (u16)(DCERR_BASE_CODE + 15)//�����칦��ʧ��
#define  DCERR_OPEN_SHAREAPP     (u16)(DCERR_BASE_CODE + 16)//������������ʧ��
#define  DCERR_TRANS_FILE        (u16)(DCERR_BASE_CODE + 17)//�����ļ����书��ʧ��
#define  DCERR_WRITE_BOARD       (u16)(DCERR_BASE_CODE + 18)//�����װ幦��ʧ��
#define  DCERR_WRITE_BOARD_V12   (u16)(DCERR_BASE_CODE + 19)//�����װ�(1.0-2.x)����ʧ��


#define  DCERR_WSA_STARTUP       (u16)(DCERR_BASE_CODE + 100)//wsastartup error
#define  DCERR_COM_STARTUP       (u16)(DCERR_BASE_CODE + 101)//create semapore error


//״̬����
typedef enum {
	DC_CON_LISTENING,    //�ȴ���...
	DC_CON_CONNECTING,   //������...
	DC_CON_CONNECTED,    //������
	DC_CON_DISCONNECTED, //δ����, �ѶϿ�����
	DC_CON_FAILED,       //����ʧ��
	DC_CON_UNKNOWN_STATE //δ֪����״̬
} emDCState;

//----------------------------------------------------------------------

/*=============================================================================
������		nbInit
����		��ʼ�� KEDA���ֻ���ģ�� ��,����֮һ�� �ⲿʹ��
�㷨ʵ��	������ѡ�
�������˵����
����ֵ˵���� �ɹ�����FE_OK,  ʧ�ܷ��ش�����
=============================================================================*/
u16 dclibInit();


/*=============================================================================
������		nbRelease
����		���� KEDA���ֻ���ģ�� ��,�������ò�������,ֱ���ͷſ⣬����֮һ�� �ⲿʹ��
�㷨ʵ��	������ѡ�
�������˵������
����ֵ˵���� �ɹ�����FE_OK,  ʧ�ܷ��ش�����
=============================================================================*/
u16 dclibRelease();


class CDCManager;

class CDataConfObj
{
public:
    CDataConfObj();
    ~CDataConfObj();
	
public:
	u16  CreateDCObj( HWND hPWnd );
	u16  FreeDCObj( );

	u16  ConnectHost(LPSTR pszHostName, u16 wPort=1503);
	u16  Disconnect();
	u16  Chat();
	u16  ShareApp();
	u16  TransFile();
	u16  WhiteBoard();
	u16  WhiteBoardV12();

	u16  CallBackMsg(u32 dwMsg, WPARAM wParam, LPARAM lParam);
	
	u16  GetState(emDCState &emDCState);
	u16  GetDCLastError(CString &szLastErr);
	
private:
	CDCManager *m_pcDCManager;
};


//----------------------------------------------------------------------

#endif /////_DATACONFLIB_0601_H_