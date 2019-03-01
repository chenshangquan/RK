#pragma once

#ifndef _TPADPLATCONST_H_
#define _TPADPLATCONST_H_

#include "printctrl.h"  

//------------------------------��������------begin-------------------------------
#define ARRAY                  vector
#define INVALID_WORD           0xffff                                          //�Ƿ���u16 / unsinged short ���͵�ֵ
#define INVALID_DWORD          0xffffffffff                                    //�Ƿ���u32/ DWORD ���͵�ֵ
#define MSG_SUCESS             -1                                              //��Ϣ����ʱʹ��


#define MAX_PAGEITEM_COUNT        12                                         //MainMenuһҳ��ʾ�����Item����

#define MANAGER_USER              "admin"                                    //����Ա�û���
#define MANAGER_PSWD              "kedacomTP"									 //����Ա����
#define TP_PASSWORD               "tpkedacom"                                //������������


#define WIFI_MAX_SEARCH_NUM     (30)                                         //wifi���������������


//MainMenu��
#define MENU_CNSCONSOLE        _T("�������")       
#define MENU_NETCFG            _T("��������")
#define MENU_IEXPLORE          _T("�����")
#define MENU_VOLUMECTRL        _T("��������")
#define MENU_READSHARE         _T("�ļ�����")              /*_T("�Ķ��빲��")*/
#define MENU_SYSLOG            _T("ϵͳ��־")
#define MENU_FILEMANAGE        _T("�ļ�����")
#define MENU_REBOOT            _T("����")
#define MENU_SHUTDOWN          _T("�ػ�")
#define MENU_SLEEP             _T("����")
#define MENU_SYSUPDATE         _T("ϵͳ����")
#define MENU_CENTERCTRL        _T("�пع���")
#define MENU_LOUOUT            _T("ע��")
#define MENU_WATCHVEDIO		   _T("�տ���ʾ")
#define MENU_DATACONF          _T("���ݻ���")


#define CENTERCTRL_PATH      _T("centerctrl\\bin\\")         // �п�ϵͳĿ¼



#define TPAD_VERSION_ID	   "1.1.4.0.1."

#define CONNETCT_CNS_PORT  60002                             //cns�������˿�

#define TPAD_LISTEN_PORT   60888                             //TPad�����˿�

#define AID_TPAD_MSGTRANS    1                               //TPad��Ϣת��App
#define AID_TPAD_CNC         2                               //TPad��cnc App
#define AID_TPAD_CENTERCTRL  3                               //TPad���п� App


#define PrtMsg (CPrintCtrl::GetPrintCtrl()->PrintMsg)                        //��ӡ��Ϣ�ӿ�
#define PrtMsgForce (CPrintCtrl::GetPrintCtrl()->ForcePrtMsg)
#define IS_PRINT_ENTER_MSG (CPrintCtrl::GetPrintCtrl()->IsPrintEnterMsg())   //�Ƿ�Ҫ��ӡ��ڴ���Ϣ
#define IS_PRINT_OUT_MSG (CPrintCtrl::GetPrintCtrl()->IsPrintOutMsg())       //�Ƿ��ӡ���ڴ���Ϣ
#define MAPPING_HELPER (CPrintCtrl::GetPrintCtrl()->MappingHelper)           //ע���ӡ����Ϣ��



//TPad�ڲ���Ϣ����
#include "msgIdDispatch.h"

enum EmUiTPadMsg
{
#define UI_TPAD_MSG_BEGIN    TPAD_MSG_BEGIN

	    ev_UIUpdateMainMenu  = UI_TPAD_MSG_BEGIN,
#define	UI_TPAD_UPDATE_MAINMENU    ev_UIUpdateMainMenu


        ev_UIShowWifiConnectingDlg,
#define	UI_TPAD_SHOW_WIFI_CONNECTING_DLG    ev_UIShowWifiConnectingDlg

        ev_UIHideWifiConnectingDlg,
#define	UI_TPAD_HIDE_WIFI_CONNECTING_DLG    ev_UIHideWifiConnectingDlg

		ev_UIWifiConnectingTimeOut,
#define	UI_TPAD_WIFICONNECTING_TIMEOUT    ev_UIWifiConnectingTimeOut

		ev_UIWifiCancleConnect,
#define	UI_TPAD_WIFI_CANCLE_CONNECT         ev_UIWifiCancleConnect

		ev_UIRefreshWifi,
#define UI_TPAD_REFRESH_WIFI                ev_UIRefreshWifi    

		/************************************************************************/
		/** ϵͳ�������
		wParam =    
		lparam = 0*/
		/************************************************************************/
		ev_UISysUpdateOver,
#define	UI_TPAD_SYSUPDATE_OVER              ev_UISysUpdateOver

        ev_UITPadUpdate_Progress,
#define	UI_TPADUPDATE_PROGRESS              ev_UITPadUpdate_Progress

		ev_UITPadEnd,
#define UI_TPAD_MSG_END    ev_UITPadEnd
};



//------------------------------�����벿��------begin-------------------------------
/* ժ��errorid.h
/*TPadPlat������ ��29501 - 30000��
#define ERR_TPADPLAT_BGN      ERR_CMS_END + 1
#define ERR_TPADPLAT_END      ERR_TPADPLAT_BGN + 499
*/
#include "errorid.h"	// �����뷶Χ�ζ���

//���ò��� 
enum EmErrTPad
{
#define  ERR_TPAD_BEGIN   ERR_TPADPLAT_BGN

	errTPadPlat = ERR_TPAD_BEGIN,
#define  ERR_TPADPLAT   errTPadPlat 

    errTPadInterface,
#define  ERR_TPAD_INTERFACE  errTPadInterface

    errTPadOspInit,
#define  ERR_TPAD_OSPINIT  errTPadOspInit

    errTPadCreatTcpNode,
#define  ERR_TPAD_CREAT_TCPNODE  errTPadCreatTcpNode

    errTPadActiveConnect,
#define  ERR_TPAD_ACTIVE_CONNECT  errTPadActiveConnect

    errTPadTcpConnect,
#define  ERR_TPAD_TCPCONNECT  errTPadTcpConnect

    errTPadWaitForSendCmd,
#define  ERR_TPAD_WAIT_FOR_SEND_CMD  errTPadWaitForSendCmd

	errTPadPlatEnd,
#define ERR_TPAD_END  errTPadPlatEnd
};  
 

 
#endif
