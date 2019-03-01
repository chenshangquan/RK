/*=============================================================================
ģ   ��   ��: �������̨ҵ���ܿ�
��   ��   ��: evmcslib.h
�� ��  �� ��: ��
�ļ�ʵ�ֹ���: mcslib����Ϣ��������
��        ��: ���
��        ��: V4.0  Copyright(C) 2003-2005 KDC, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2005/04/26  4.0     ���        ����
=============================================================================*/

#ifndef _EVMCSLIB_20050426_H_
#define _EVMCSLIB_20050426_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "eventid.h"


//�����Ϣ�����ޣ���������WM_USER ���ϼ�ʮ�Ŀؼ���Ϣ
#define MCS_DISP_MSG_BGN                                (WM_USER + 0x80)
//1 ��MCUͨ����Ϣ
//1.1   ��������

//1.1.1	����
    //MCU׼��Ӧ��, ��Ϣ��: s32(��TCtrlData�е���������)
    #define MCS_DISP_CONNECT_ACK                        (MCS_DISP_MSG_BGN + 1)
    //MCU�ܾ�Ӧ��, ��Ϣ��: u32(��MCU��IP��ַ, Ϊ0��ʾû����MCU)
    #define MCS_DISP_CONNECT_NACK                       (MCS_DISP_MSG_BGN + 2)
    //����MCU��ʱ, ��Ϣ��: ��
    #define MCS_DISP_CONNECT_MCU_TIMEOUT                (MCS_DISP_MSG_BGN + 3)
    //Osp����, ��Ϣ��: s32(�Ự����) + s8[MAXLEN_MCU_NAME](MCU��)
    #define MCS_DISP_OSP_DISCONNECT                     (MCS_DISP_MSG_BGN + 4)
    //MCU���ӵĿ���̨����, ��Ϣ��: ��
    #define MCS_DISP_OSP_OVERFLOW                       (MCS_DISP_MSG_BGN + 5)

//1.1.2	ͬ������ʱ��
    //ϵͳͬ��ʱ��ɹ�, ��Ϣ��: ��
    #define MCS_DISP_SYNCTIME_ACK                       (MCS_DISP_MSG_BGN + 6)
    //ϵͳͬ��ʱ��ʧ��, ��Ϣ��: ��
    #define MCS_DISP_SYNCTIME_NACK                      (MCS_DISP_MSG_BGN + 7)

//1.1.3 ����MCU����
	//�¼�MCU������״̬֪ͨ, ��Ϣ��: CConfId + n * ( TMCU + u8 (1-������0-����) )
	#define MCS_DISP_MCULOCKSTATUS_NOTIF                (MCS_DISP_MSG_BGN + 8)

	//�����м�����Mcuý��Դ֪ͨ, ��Ϣ��: CConfId + n * ( TMcu + TMt )
	#define MCS_DISP_MCUMEDIASRC_NOTIF                  (MCS_DISP_MSG_BGN + 9)

//1.2   MCU����
//1.2.1 MCU״̬
    //��ȡTMcuStatus�ɹ�Ӧ��, ��Ϣ��: TMcuStatus
    #define MCS_DISP_GETMCUSTATUS_ACK                   (MCS_DISP_MSG_BGN + 20)
    //��ȡTMcuStatusʧ��Ӧ��, ��Ϣ��: ��
    #define MCS_DISP_GETMCUSTATUS_NACK                  (MCS_DISP_MSG_BGN + 21)
    //TMcuStatus֪ͨ, ��Ϣ��: TMcuStatus
    #define MCS_DISP_MCUSTATUS_NOTIF                    (MCS_DISP_MSG_BGN + 22)

//1.2.2 CPUʹ����
    //��ȡCPUʹ���ʳɹ�Ӧ��, ��Ϣ��: ��
    #define MCS_DISP_GETMCUCPUUSAGE_ACK                 (MCS_DISP_MSG_BGN + 25)
    //��ȡCPUʹ����ʧ��Ӧ��, ��Ϣ��: ��
    #define MCS_DISP_GETMCUCPUUSAGE_NACK                (MCS_DISP_MSG_BGN + 26)
    //CPUʹ����֪ͨ, ��Ϣ��: u8(0-100)(%)
    #define MCS_DISP_MCUCPUUSAGE_NOTIF                  (MCS_DISP_MSG_BGN + 27)

//1.2.3 ��ȡMCU����
    //��ȡMCU�豸���óɹ�Ӧ��, ��Ϣ��: ��
    #define MCS_DISP_GETMCUCFG_ACK                      (MCS_DISP_MSG_BGN + 28)
    //��ȡMCU�豸����ʧ��Ӧ��, ��Ϣ��: ��
    #define MCS_DISP_GETMCUCFG_NACK                     (MCS_DISP_MSG_BGN + 29)

//1.2.4 �޸�MCU��������
    //�޸�MCU�������óɹ�Ӧ��, ��Ϣ��: ��
    #define MCS_DISP_MODIFYMCUEQPCFG_ACK                (MCS_DISP_MSG_BGN + 30)
    //�޸�MCU��������ʧ��Ӧ��, ��Ϣ��: ��
    #define MCS_DISP_MODIFYMCUEQPCFG_NACK               (MCS_DISP_MSG_BGN + 31)
    //MCU�豸����֪ͨ, ��Ϣ��: TMcuEqpCfg
    #define MCS_DISP_MCUEQPCFG_NOTIF                    (MCS_DISP_MSG_BGN + 32)

//1.2.5 �޸�MCU��������
    //�޸�MCU�������óɹ�Ӧ��, ��Ϣ��: ��
    #define MCS_DISP_MODIFYMCUBRDCFG_ACK                (MCS_DISP_MSG_BGN + 33)
    //�޸�MCU��������ʧ��Ӧ��, ��Ϣ��: ��
    #define MCS_DISP_MODIFYMCUBRDCFG_NACK               (MCS_DISP_MSG_BGN + 34)
    //��������֪ͨ(��Ϣ����ܴ���32K), ��Ϣ��: CBrdCfg����
    #define MCS_DISP_MCUBRDCFG_NOTIF                    (MCS_DISP_MSG_BGN + 35)

    //¼�������֪ͨ, ��Ϣ��: TEqpRecCfgInfo����(����Ϊ��)
    #define MCS_DISP_RECCFG_NOTIF                       (MCS_DISP_MSG_BGN + 36)

    //����BAS����֪ͨ, ��Ϣ��: TEqpBasHDCfgInfo����(����Ϊ��)
    #define MCS_DISP_BAS_HD_CFG_NOTIF                   (MCS_DISP_MSG_BGN + 37)

//1.2.6 �޸�MCU��������
    //�޸�MCU�������óɹ�Ӧ��, ��Ϣ��: ��
    #define MCS_DISP_MODIFYMCUGENERALCFG_ACK            (MCS_DISP_MSG_BGN + 40)
    //�޸�MCU��������ʧ��Ӧ��, ��Ϣ��: ��
    #define MCS_DISP_MODIFYMCUGENERALCFG_NACK           (MCS_DISP_MSG_BGN + 41)
    //MCU��������֪ͨ, ��Ϣ��: TMcuGeneralCfg
    #define MCS_DISP_MCUGENERALCFG_NOTIF                (MCS_DISP_MSG_BGN + 42)

//1.2.7 ��ȡMCUʱ��
    //��ػ�ȡmcuϵͳʱ��ɹ�, ��Ϣ��: TKdvTime(��ǰmcuϵͳʱ��)
    #define MCS_DISP_GETMCUTIME_ACK                     (MCS_DISP_MSG_BGN + 43)
    //��ػ�ȡmcuϵͳʱ��ʧ��, ��Ϣ��: ��
    #define MCS_DISP_GETMCUTIME_NACK                    (MCS_DISP_MSG_BGN + 44)

//1.2.8 �޸�MCUʱ��
    //����޸�mcuϵͳʱ��ɹ�, ��Ϣ��: TKdvTime(��ǰmcuϵͳʱ��)
    #define MCS_DISP_MODIFYMCUTIME_ACK                  (MCS_DISP_MSG_BGN + 45)
    //����޸�mcuϵͳʱ��ʧ��, ��Ϣ��: ��
    #define MCS_DISP_MODIFYMCUTIME_NACK                 (MCS_DISP_MSG_BGN + 46)

//1.2.9 ���𵥰�
    //������𵥰�ɹ�, ��Ϣ��: u8(��������)
    #define MCS_DISP_REBOOTBRD_ACK                      (MCS_DISP_MSG_BGN + 47)
    //������𵥰�ʧ��, ��Ϣ��: u8(��������)
    #define MCS_DISP_REBOOTBRD_NACK                     (MCS_DISP_MSG_BGN + 48)
    //��������״̬֪ͨ(MCU��������), ��Ϣ��: TBoardStatusNotify
    #define MCS_DISP_BRDSTATUS_NOTIF                    (MCS_DISP_MSG_BGN + 49)
// liuruifei [4/4/2006]
//1.2.10 �����ϴ�/����
	//���������ļ��ɹ�
	#define MCS_DISP_DOWNLOADCFG_ACK				    (MCS_DISP_MSG_BGN + 50)
	//���������ļ�ʧ��
	#define MCS_DISP_DOWNLOADCFG_NACK				    (MCS_DISP_MSG_BGN + 51)
	//�ϴ������ļ��ɹ�
	#define MCS_DISP_UPLOADCFG_ACK					    (MCS_DISP_MSG_BGN + 52)
	//�ϴ������ļ�ʧ��
	#define MCS_DISP_UPLOADCFG_NACK			    		(MCS_DISP_MSG_BGN + 53)
	//�����ļ��ɹ�
	#define MCS_DISP_UPGRADE_ACK					    (MCS_DISP_MSG_BGN + 54)
	//�����ļ�ʧ��
	#define MCS_DISP_UPGRADE_NACK					    (MCS_DISP_MSG_BGN + 55)

//1.2.11 �忨����
    #define MCS_DISP_UPDATEBRDFILE_NOTIF                (MCS_DISP_MSG_BGN + 56)

//1.2.12 ����ʧ��֪ͨ
	//����ʧ��֪ͨ ����Ϣ��:TMSEnvConflict
	#define MCS_MSSYN_FAILED_NOTIF						(MCS_DISP_MSG_BGN + 57)

//1.2.13 ��ز���ʧ��֪ͨ(�������κβ���, ��Ҫ֪ͨ��������µ���Ϣ)
    #define MCS_DISP_ALARMINFO_NOTIF                    (MCS_DISP_MSG_BGN + 58)

//1.2.14 N+1���� ���ݶ� ������ͬ���� N�� ��Ϣ֪ͨ
    //N+1���� ���ݶ� ������ͬ���� N�� ͬ���ɹ�
    #define MCS_DISP_NPLUSROLLBACK_ACK                  (MCS_DISP_MSG_BGN + 59)
    //N+1���� ���ݶ� ������ͬ���� N�� ͬ��ʧ��
    #define MCS_DISP_NPLUSROLLBACK_NACK                 (MCS_DISP_MSG_BGN + 60)

//1.2.15 �ϴ��ļ�
    //MCUͬ���������
    #define MCS_DISP_STARTUPDATEDSCVERSION_ACK          (MCS_DISP_MSG_BGN + 61)
    //MCU��ͬ���������
    #define MCS_DISP_STARTUPDATEDSCVERSION_NACK         (MCS_DISP_MSG_BGN + 62)
    //MCU��MCS�����Ľ��ճɹ���Ӧ
    #define MCS_DISP_DSCUPDATEFILE_ACK                  (MCS_DISP_MSG_BGN + 63)
    //MCU��MCS�����Ľ���ʧ�ܻ�Ӧ
    #define MCS_DISP_DSCUPDATEFILE_NACK                 (MCS_DISP_MSG_BGN + 64)
    //�ϴ��ļ���ʱ
    #define MCS_DISP_UPLOAD_FILE_TIMEOUT                (MCS_DISP_MSG_BGN + 65)

//1.2.16 ����telnet����
    //����telnet����ɹ���Ӧ
    #define MCS_DISP_UPDATETELNETLOGININFO_ACK          (MCS_DISP_MSG_BGN + 66)
    //����telnet����ʧ�ܻ�Ӧ
    #define MCS_DISP_UPDATETELNETLOGININFO_NACK         (MCS_DISP_MSG_BGN + 67)

//1.3	�������
//1.3.1	��������б�
    //��ʱ����������Ϣ֪ͨ, ��Ϣ��: CConfId + TConfInfo
    #define MCS_DISP_CONFINFO_NOTIF                     (MCS_DISP_MSG_BGN + 70)
    //��ʱ�������Ϣ֪ͨ, ��Ϣ��: CConfId + TBasicConfInfo
    #define MCS_DISP_SIMCONFINFO_NOTIF                  (MCS_DISP_MSG_BGN + 71)
    //����ģ��(ԤԼ����)��Ϣ֪ͨ, ��Ϣ��: CConfId + TConfInfo
    #define MCS_DISP_TEMSCHCONFINFO_NOTIF               (MCS_DISP_MSG_BGN + 72)

//1.3.2	��������
    //�������̨��MCU�ϴ���һ������ɹ�Ӧ��, ��Ϣ��: CConfId + u8(CONF_TAKEMODE_*)
    #define MCS_DISP_CREATECONF_ACK                     (MCS_DISP_MSG_BGN + 73)
    //�������̨��MCU�ϴ���һ������ʧ��, ��Ϣ��: ��
    #define MCS_DISP_CREATECONF_NACK                    (MCS_DISP_MSG_BGN + 74)

    //����ģ��ɹ���ת��ɼ�ʱ/ԤԼ����, ��Ϣ��: CConfId + u8(CONF_TAKEMODE_*)
    #define MCS_DISP_HOLDCONF_BYTEMPLATE_ACK            (MCS_DISP_MSG_BGN + 75)
    //����ģ��ת��ɼ�ʱ/ԤԼ����ʧ��, ��Ϣ��: ��
    #define MCS_DISP_HOLDCONF_BYTEMPLATE_NACK           (MCS_DISP_MSG_BGN + 76)

    //������GK��ע��ɹ�֪ͨ, ��Ϣ��: CConfId
    #define MCS_DISP_CONFREGGKSUCCESS_NOTIF             (MCS_DISP_MSG_BGN + 77)	
    //������GK��ע��ʧ��֪ͨ, ��Ϣ��: CConfId, �μ���Ϣͷ�еĴ�����
    #define MCS_DISP_CONFREGGKFAIL_NOTIF                (MCS_DISP_MSG_BGN + 78)

//1.3.3	��������
    //MCU�ɹ���������Ӧ��, ��Ϣ��: CConfId
    #define MCS_DISP_RELEASECONF_ACK                    (MCS_DISP_MSG_BGN + 80)
    //MCU�ܾ���������, ��Ϣ��: CConfId
    #define MCS_DISP_RELEASECONF_NACK                   (MCS_DISP_MSG_BGN + 81)
    //MCU��������֪ͨ, ��Ϣ��: CConfId + u8(CONF_TAKEMODE_*)
    #define MCS_DISP_RELEASECONF_NOTIF                  (MCS_DISP_MSG_BGN + 82)

//1.3.4	��������
//1.3.4.1	��������
    //MCU�ɹ��ı���鱣����ʽ����Ӧ��, ��Ϣ��: CConfId + BOOL(TRUE or FALSE)
    #define MCS_DISP_CHANGECONFLOCKMODE_ACK             (MCS_DISP_MSG_BGN + 85)
    //MCU�ܾ��ı���鱣����ʽ����, ��Ϣ��: ��
    #define MCS_DISP_CHANGECONFLOCKMODE_NACK            (MCS_DISP_MSG_BGN + 86)
    //MCU�ı���鱣����ʽ, ��Ϣ��: CConfId + u8(���鱣����ʽ)
    #define MCS_DISP_CONFLOCKMODE_NOTIF                 (MCS_DISP_MSG_BGN + 87)

//1.3.4.2	�������
    //MCU���������̨�ĵ�ǰ�������Ŀ���̨����Ϣ,
	//��Ϣ��: CConfId + 4byte(�����ص�IP,������)+32byte(�����ص��û���)
    #define MCS_DISP_LOCKUSERINFO_NOTIF                 (MCS_DISP_MSG_BGN + 88)

//1.3.4.3	��������
    //MCUҪ��������̨�����������, ��Ϣ��: CConfId
    #define MCS_DISP_ENTERCONFPWD_REQ                   (MCS_DISP_MSG_BGN + 90)
    //MCU��ʾ�������̨�������, ��Ϣ��: CConfId
    #define MCS_DISP_WRONGCONFPWD_NOTIF                 (MCS_DISP_MSG_BGN + 91)

//1.3.4.4	���Ļ�������
    //MCU�ɹ����Ļ�������Ӧ��, ��Ϣ��: CConfId + 32byte�ַ���
    #define MCS_DISP_CHANGECONFPWD_ACK                  (MCS_DISP_MSG_BGN + 92)
    //MCU�ܾ����Ļ�������, ��Ϣ��: CConfId
    #define MCS_DISP_CHANGECONFPWD_NACK                 (MCS_DISP_MSG_BGN + 93)
    //MCU�޸Ļ�������֪ͨ, ��Ϣ��: CConfId + 32byte�ַ���
    #define MCS_DISP_CONFPWD_NOTIF                      (MCS_DISP_MSG_BGN + 94)

//1.3.5	�������
    //MCU�ɹ��������Ӧ��, ��Ϣ��: CConfId
    #define MCS_DISP_SAVECONF_ACK                       (MCS_DISP_MSG_BGN + 96)
    //MCU�ܾ��������, ��Ϣ��: CConfId
    #define MCS_DISP_SAVECONF_NACK                      (MCS_DISP_MSG_BGN + 97)

//1.3.6	�޸�ԤԼ����
    //MCU�ɹ��޸�ԤԼ����, ��Ϣ��: CConfId + u8(TakeMode)
    #define MCS_DISP_MODIFYCONF_ACK                     (MCS_DISP_MSG_BGN + 100)
    //MCU�ܾ��޸�ԤԼ����, ��Ϣ��: CConfId
    #define MCS_DISP_MODIFYCONF_NACK                    (MCS_DISP_MSG_BGN + 101)  

//1.3.7	�ӳ�����
    //MCU�ɹ��ӳ�����Ӧ��, ��Ϣ��: CConfId + u16(����)
	#define MCS_DISP_DELAYCONF_ACK                      (MCS_DISP_MSG_BGN + 102)
	//MCU�ܾ��ӳ�����Ӧ��, ��Ϣ��: CConfId
	#define MCS_DISP_DELAYCONF_NACK                     (MCS_DISP_MSG_BGN + 103)
	//MCU�ӳ�����֪ͨ, ��Ϣ��: CConfId + u16(�ӳ�ʱ�䣬��λ������)
	#define MCS_DISP_DELAYCONF_NOTIF                    (MCS_DISP_MSG_BGN + 104)	
	//MCU֪ͨ��ػ������ʣ��ʱ��, ��Ϣ��: CConfId + u16(�������ʣ��ʱ��, ��λ: ����)
	#define MCS_DISP_CONFTIMELEFT_NOTIF                 (MCS_DISP_MSG_BGN + 105)
//1.3.8 MAU״̬ //xts20081125
    //��ȡTMAuStatus�ɹ�Ӧ��, ��Ϣ��: TMauStatus
    #define MCS_DISP_GETMAUSTATUS_ACK                   (MCS_DISP_MSG_BGN + 106)
    //��ȡTMcuStatusʧ��Ӧ��, ��Ϣ��: ��
    #define MCS_DISP_GETMAUSTATUS_NACK                  (MCS_DISP_MSG_BGN + 107)
    //TMcuStatus֪ͨ, ��Ϣ��: TMcuStatus
    #define MCS_DISP_MAUSTATUS_NOTIF                    (MCS_DISP_MSG_BGN + 108)
//1.4	�������
//1.4.1	ָ����ϯ
	//MCU�ɹ�ָ��������ϯӦ��, ��Ϣ��: CConfId
	#define MCS_DISP_SPECCHAIRMAN_ACK                   (MCS_DISP_MSG_BGN + 110)
	//MCU�ܾ�ָ��������ϯӦ��, ��Ϣ��: CConfId
	#define MCS_DISP_SPECCHAIRMAN_NACK                  (MCS_DISP_MSG_BGN + 111)
	//ָ����ϯ֪ͨ, 
    //�ϲ����ͨ������MCS_DISP_SIMCONFINFO_NOTIF���Դ���Ϣ,
    //��Ϣ��: CConfId + TMt(����ϯ���ն�) 
	#define MCS_DISP_SPECCHAIRMAN_NOTIF                 (MCS_DISP_MSG_BGN + 112)
	//�ն�������ϯ֪ͨ, ��Ϣ��: CConfId + TMt(������ն�) 
	#define MCS_DISP_MTAPPLYCHAIRMAN_NOTIF              (MCS_DISP_MSG_BGN + 113)

//1.4.2	ȡ����ϯ
	//MCU�ɹ�ȡ��������ϯӦ��, ��Ϣ��: CConfId
    #define MCS_DISP_CANCELCHAIRMAN_ACK                 (MCS_DISP_MSG_BGN + 115)
	//����������ϯ, ��Ϣ��: CConfId
	#define MCS_DISP_CANCELCHAIRMAN_NACK                (MCS_DISP_MSG_BGN + 116)
	//ȡ����ϯ֪ͨ, 
    //�ϲ����ͨ������MCS_DISP_SIMCONFINFO_NOTIF���Դ���Ϣ,
    //��Ϣ��: CConfId
	#define MCS_DISP_CANCELCHAIRMAN_NOTIF               (MCS_DISP_MSG_BGN + 117)

//1.4.3 ��ϯģʽ
    //MCU֪ͨ��ϯģʽ, ��Ϣ��: CConfId
    #define MCS_DISP_CONFCHAIRMODE_NOTIF                (MCS_DISP_MSG_BGN + 118)

//1.4.4	ָ������ 
    //MCU�ɹ�ָ��������, ��Ϣ��: CConfId
    #define MCS_DISP_SPECSPEAKER_ACK                    (MCS_DISP_MSG_BGN + 120)
    //ָ��֮ǰ�ķ����߱�ȡ��, ��Ϣ��: CConfId
    #define MCS_DISP_SPECSPEAKER_NACK                   (MCS_DISP_MSG_BGN + 121)
    //ָ������֪ͨ, 
    //�ϲ����ͨ������MCS_DISP_SIMCONFINFO_NOTIF���Դ���Ϣ,
    //��Ϣ��: CConfId + TMt(�����ն�)
    #define MCS_DISP_SPECSPEAKER_NOTIF                  (MCS_DISP_MSG_BGN + 122)

    //MCU֪ͨ����ն����뷢��, ��Ϣ��: CConfId + TMt(�����ն�)
    #define MCS_DISP_MTAPPLYSPEAKER_NOTIF               (MCS_DISP_MSG_BGN + 123)

//1.4.5	ȡ������
    //MCU�ɹ�ȡ��������ϯӦ��, ��Ϣ��: CConfId
    #define MCS_DISP_CANCELSPEAKER_ACK                  (MCS_DISP_MSG_BGN + 125)
    //ȡ��������ʧ��, ��Ϣ��: CConfId
	#define MCS_DISP_CANCELSPEAKER_NACK                 (MCS_DISP_MSG_BGN + 126)
	//ȡ��������֪ͨ, 
    //�ϲ����ͨ������MCS_DISP_SIMCONFINFO_NOTIF���Դ���Ϣ,
    //��Ϣ��: CConfId
	#define MCS_DISP_CANCELSPEAKER_NOTIF                (MCS_DISP_MSG_BGN + 127)

//1.4.6	�����ն�
	//MCUͬ��������̨�����ն�, ��Ϣ��: CConfId
	#define MCS_DISP_ADDMT_ACK                          (MCS_DISP_MSG_BGN + 130)
	//MCU�ܾ��������̨�����ն�, ��Ϣ��: CConfId
	#define MCS_DISP_ADDMT_NACK                         (MCS_DISP_MSG_BGN + 131)

//1.4.7	ɾ���ն�
	//�ն˱��ɹ�����, ��Ϣ��: CConfId
	#define MCS_DISP_DELMT_ACK                          (MCS_DISP_MSG_BGN + 132)
	//��Ϣ�������ܾ������ն�, ��Ϣ��: CConfId
	#define MCS_DISP_DELMT_NACK                         (MCS_DISP_MSG_BGN + 133)

//1.4.8	��ʼ���
	//MCUӦ��������̨����ն�, MCU_MCS_STARTSWITCHMC_ACK,
	//��Ϣ��: u8(���ͨ��)
	#define MCS_DISP_STARTMONITOR_ACK                   (MCS_DISP_MSG_BGN + 135)
	//MCU�ܾ��������̨����ն�, MCU_MCS_STARTSWITCHMC_NACK, ��Ϣ��: ��
	#define MCS_DISP_STARTMONITOR_NACK                  (MCS_DISP_MSG_BGN + 136)
	//MCU����صĿ�ʼ���֪ͨ, MCU_MCS_STARTPLAY_NOTIF,
	//��Ϣ��: u8(���ͨ��)
    //ע��MCU����������Ϣ�����Ѿ�����CMcuSession::m_atMonitorMember��
	#define MCS_DISP_STARTMONITOR_NOTIF                 (MCS_DISP_MSG_BGN + 137)

//1.4.9 ֹͣ���
	//MCUӦ��������̨����ն�, MCU_MCS_STOPSWITCHMC_ACK, ��Ϣ��: u8(ͨ����)
	#define MCS_DISP_STOPMONITOR_ACK                    (MCS_DISP_MSG_BGN + 138)
	//MCU�ܾ��������̨����ն�, MCU_MCS_STOPSWITCHMC_NACK, ��Ϣ��: ��
	#define MCS_DISP_STOPMONITOR_NACK                   (MCS_DISP_MSG_BGN + 139)
	//MCU����ص�ֹͣ���֪ͨ, MCU_MCS_STOPPLAY_NOTIF, ��Ϣ��: u8(ͨ����)
	#define MCS_DISP_STOPMONITOR_NOTIF                  (MCS_DISP_MSG_BGN + 140)

//1.4.10 ���Ͷ���Ϣ
	//MCU���������̨�ķ��Ͷ���Ϣ֪ͨ, ��Ϣ��: CConfId + TRunMsgInfo 
    #define MCS_DISP_SENDRUNMSG_NOTIF                   (MCS_DISP_MSG_BGN + 145)

//1.4.11 �����ն��б�
    //MCU�����������̨���ն��б�֪ͨ, ��Ϣ��: CConfId + TMcu + TMtExt����
    #define MCS_DISP_MTLIST_NOTIF                       (MCS_DISP_MSG_BGN + 150)
    //MCU�����������̨���ն�������Ϣ֪ͨ, ��Ϣ��: CConfId + TConfAllMtInfo
    #define MCS_DISP_CONFALLMTINFO_NOTIF                (MCS_DISP_MSG_BGN + 151)

//1.4.12 ָ�����᳡���ϼ��ش����ն�
    //MCU�ɹ�ָ�����᳡���ϼ��ش����ն� ,��Ϣ�壺  TMt
    #define MCS_DISP_SPECOUTVIEW_ACK                    (MCS_DISP_MSG_BGN + 152)
    //ָ�����᳡���ϼ��ش����ն�ʧ�ܣ���Ϣ�壺  TMt
    #define MCS_DISP_SPECOUTVIEW_NACK                   (MCS_DISP_MSG_BGN + 153)

//1.5	�������
//1.5.1	��ѯ��ѯ����
    //MCUӦ��������̨��ѯ������ѯ����, ��Ϣ��: CConfId + TPollInfo + TMtPollParam����
    #define MCS_DISP_GETPOLLPARAM_ACK                   (MCS_DISP_MSG_BGN + 155) 
    //MCU�ܾ��������̨��ѯ������ѯ����, ��Ϣ��: CConfId
    #define MCS_DISP_GETPOLLPARAM_NACK                  (MCS_DISP_MSG_BGN + 156)
    //MCU֪ͨ�������̨��ǰ����ѯ״̬, ��Ϣ��: CConfId + TPollInfo
    #define MCS_DISP_POLLSTATE_NOTIF                    (MCS_DISP_MSG_BGN + 157)
    //MCU������ѯ�����ı�֪ͨ, ��Ϣ��: CConfId + TPollInfo + TMtPollParam����
    #define MCS_DISP_POLLPARAMCHANGE_NTF                (MCS_DISP_MSG_BGN + 158) 
    //MCUӦ��ı䵱ǰ��ѯ�ն�, ��Ϣ��: CConfId
    #define MCS_DISP_SPECPOLLPOS_ACK                    (MCS_DISP_MSG_BGN + 159) 
    //MCU�ܾ��ı䵱ǰ��ѯ�ն�, ��Ϣ��: CConfId
    #define MCS_DISP_SPECPOLLPOS_NACK                   (MCS_DISP_MSG_BGN + 160) 

//1.5.2 ��ѯ����ǽ��ѯ����
    //MCUӦ��������̨��ѯ����ǽ��ѯ����, ��Ϣ��: CConfId + TTvWallPollInfo + TMtPollParam����
    #define MCS_DISP_GETTWPOLLPARAM_ACK                   (MCS_DISP_MSG_BGN + 161) 
    //MCU�ܾ��������̨��ѯ����ǽ��ѯ����, ��Ϣ��: CConfId
    #define MCS_DISP_GETTWPOLLPARAM_NACK                  (MCS_DISP_MSG_BGN + 162)
    //MCU֪ͨ�������̨��ǰ�ĵ���ǽ��ѯ״̬, ��Ϣ��: CConfId + TTvWallPollInfo
    #define MCS_DISP_TWPOLLSTATE_NOTIF                    (MCS_DISP_MSG_BGN + 163)

//1.5.3 �ı����������л�ʱ��
    //MCUͬ��������̨�ı����������л�ʱ�������, ��Ϣ��: CConfId + 1byte(��λ:��)
    #define MCS_DISP_CHANGEVACHOLDTIME_ACK              (MCS_DISP_MSG_BGN + 164)
    //MCU�ܾ��������̨�ı����������л�ʱ�������, ��Ϣ��: CConfId + 1byte(��λ:��)
    #define MCS_DISP_CHANGEVACHOLDTIME_NACK             (MCS_DISP_MSG_BGN + 165)
    //MCU���������̨�ı����������л�ʱ���֪ͨ, ��Ϣ��: CConfId + 1byte(��λ:��)
    #define MCS_DISP_CHANGEVACHOLDTIME_NOTIF            (MCS_DISP_MSG_BGN + 166)

//1.5.4	����״̬֪ͨ
    //MCU���������̨�Ļ���״̬֪ͨ, ��Ϣ��: CConfId + TConfStatus
    #define MCS_DISP_CONFSTATUS_NOTIF                   (MCS_DISP_MSG_BGN + 167)
    //MCU���������̨�Ļ���ģʽ֪ͨ, ��Ϣ��: CConfId + TConfMode
    #define MCS_DISP_CONFMODE_NOTIF                     (MCS_DISP_MSG_BGN + 168)

//1.5.5	��������
    //MCUͬ�⿪ʼ�������� ��Ϣ�壺  ����ģʽ u8 (ROLLCALL_MODE_NONE ��)
    #define MCU_DISP_STARTROLLCALL_ACK                  (MCS_DISP_MSG_BGN + 170)
    //MCU�ܾ���ʼ�������� ��Ϣ�壺  
    #define MCU_DISP_STARTROLLCALL_NACK                 (MCS_DISP_MSG_BGN + 171)
    //MCU���������̨�Ŀ�ʼ����֪ͨ, ��Ϣ�壺  ����ģʽ u8
    #define MCU_DISP_STARTROLLCALL_NOTIF                (MCS_DISP_MSG_BGN + 172)

    //MCUͬ��ֹͣ�������� ��Ϣ�壺  
    #define MCU_DISP_STOPROLLCALL_ACK                   (MCS_DISP_MSG_BGN + 173)
    //MCU�ܾ�ֹͣ�������� ��Ϣ�壺  
    #define MCU_DISP_STOPROLLCALL_NACK                  (MCS_DISP_MSG_BGN + 174)
    //MCU���������̨��ֹͣ����֪ͨ, ��Ϣ�壺  
    #define MCU_DISP_STOPROLLCALL_NOTIF                 (MCS_DISP_MSG_BGN + 175)

    //MCUͬ������������ ��Ϣ�壺  TMt��TMt
    #define MCU_DISP_CHANGEROLLCALL_ACK                 (MCS_DISP_MSG_BGN + 176)
    //MCU�ܾ������������ ��Ϣ�壺  
    #define MCU_DISP_CHANGEROLLCALL_NACK                (MCS_DISP_MSG_BGN + 177)
    //MCU���������̨�ĵ������֪ͨ, ��Ϣ�壺  TMt��TMt
    #define MCU_DISP_CHANGEROLLCALL_NOTIF               (MCS_DISP_MSG_BGN + 178)

//1.6	�ն˲���
//1.6.1	�����ն�
    //MCUͬ������ն�Ӧ��, ��Ϣ��: CConfId + TMt(����ն�)
    #define MCS_DISP_CALLMT_ACK                         (MCS_DISP_MSG_BGN + 180)
    //MCU�ܾ������ն�, ��Ϣ��: CConfId
    #define MCS_DISP_CALLMT_NACK                        (MCS_DISP_MSG_BGN + 181)
    //�ն�����״̬�仯֪ͨ, ��Ϣ��: CConfId + TMt + u8(״̬:0-���� 1-����) + u8(����ԭ��: 0-�쳣 1-�����Ҷ� 2-��·��)
    #define MCS_DISP_MTONLINECHANGE_NOTIF               (MCS_DISP_MSG_BGN + 182)
    //�ն˺��в��ɹ�֪ͨ, ��Ϣ��: CConfId + TMt ԭ���������
    #define MCS_DISP_CALLMTFAILURE_NOTIF                (MCS_DISP_MSG_BGN + 183)

//1.6.2	���ú����ն˷�ʽ
    //�ɹ�����MCU�����ն˷�ʽ  ��Ϣ��: CConfId + TMt(�������ն�) + u8(���з�ʽ)
    #define MCS_DISP_SETMTCALLMODE_ACK                  (MCS_DISP_MSG_BGN + 185)
    //�ܾ�����MCU�����ն˷�ʽ, ��Ϣ��: CConfId
    #define MCS_DISP_SETMTCALLMODE_NACK                 (MCS_DISP_MSG_BGN + 186)
    //MCU�����ն˷�ʽ֪ͨ  ��Ϣ��: CConfId + TMtExt
    #define MCS_DISP_MTCALLMODE_NOTIF                   (MCS_DISP_MSG_BGN + 187)

//1.6.3	�Ҷ��ն�
    //�ն˱��ɹ��Ҷ�, ��Ϣ��: CConfId
    #define MCS_DISP_DROPMT_ACK                         (MCS_DISP_MSG_BGN + 190)
    //MCU�ܾ��Ҷϸ��ն�, ��Ϣ��: CConfId
    #define MCS_DISP_DROPMT_NACK	                    (MCS_DISP_MSG_BGN + 191)

    //��ϯѡ��vmp
    #define MCS_DISP_STARTVMPSEE_ACK                     (MCS_DISP_MSG_BGN + 192)
    #define MCS_DISP_STARTVMPSEE_NACK                    (MCS_DISP_MSG_BGN + 193)

//1.6.4	ǿ���ն�ѡ��
    //MCUӦ����ǿ��Ŀ���ն�ѡ��Դ�ն�, MCS_MCU_STARTSWITCHMT_ACK, 
    //��Ϣ��: CConfId + TSwitchInfo
    #define MCS_DISP_STARTMTSEE_ACK                     (MCS_DISP_MSG_BGN + 195)
    //�ܾ����ǿ��Ŀ���ն�ѡ��Դ�ն�, MCS_MCU_STARTSWITCHMT_NACK, 
    //��Ϣ��: CConfId
    #define MCS_DISP_STARTMTSEE_NACK                    (MCS_DISP_MSG_BGN + 196)

//1.6.5	ȡ���ն�ѡ��
    //MCUӦ����ȡ��Ŀ���ն�ѡ��Դ�ն�, MCU_MCS_STOPSWITCHMT_ACK,
    //��Ϣ��: CConfId + TMt
    #define MCS_DISP_STOPMTSEE_ACK                      (MCS_DISP_MSG_BGN + 197)
    //MCU�ܾ����ȡ��Ŀ���ն�ѡ��Դ�ն�, MCU_MCS_STOPSWITCHMT_NACK,
    //��Ϣ��: CConfId
    #define MCS_DISP_STOPMTSEE_NACK                     (MCS_DISP_MSG_BGN + 198)

//1.6.6	��ѯ�ն�״̬
    //MCU���������̨�Ĳ�ѯ�ն�״̬֪ͨ, ��Ϣ��: CConfId + TMtStatus����
    #define MCS_DISP_MTSTATUS_NOTIF                     (MCS_DISP_MSG_BGN + 200)

//�������ǽ��������
    #define MCS_DISP_SETCHANNELVOLUME_ACK               (MCS_DISP_MSG_BGN + 201)
    #define MCS_DISP_SETCHANNELVOLUME_NACK              (MCS_DISP_MSG_BGN + 202)


//1.6.7 ��ѯ�ն˱���
    //MCUӦ��������̨��ѯ�ն˱���, ��Ϣ��: CConfId + TMt + TMtAlias����
    #define MCS_DISP_GETMTALIAS_ACK                     (MCS_DISP_MSG_BGN + 205)
    //MCUû���ն˵ı�����Ϣ, ��Ϣ��: CConfId + TMt(Ҫ��ѯ���ն�)
    #define MCS_DISP_GETMTALIAS_NACK                    (MCS_DISP_MSG_BGN + 206)
    //MCU���������̨���ն˱���֪ͨ, ��Ϣ��: CConfId + TMt + TMtAlias����
    #define MCS_DISP_MTALIAS_NOTIF                      (MCS_DISP_MSG_BGN + 207)

    //MCUӦ��������̨��ѯ�����ն˱���, ��Ϣ��: CConfId + TMCU + �����������(��� TMt+1byte(��������)+2byte(��������)+�������� )
    #define MCS_DISP_GETALLMTALIAS_ACK                  (MCS_DISP_MSG_BGN + 208)
    //MCU�ܾ��������̨�Ĳ�ѯ�����ն˱���, ��Ϣ��: CConfId + TMCU
    #define MCS_DISP_GETALLMTALIAS_NACK                 (MCS_DISP_MSG_BGN + 209)
    //MCU���������̨�Ĳ�ѯ�����ն˱���֪ͨ, ��Ϣ��: CConfId + TMCU + �����������(��� TMt+1byte(��������)+2byte(��������)+�������� )
    #define MCS_DISP_ALLMTALIAS_NOTIF                   (MCS_DISP_MSG_BGN + 210)

//1.6.8 ��ȡ�ն�����
    //MCUӦ��������̨��ѯ�ն�����, ��Ϣ��: CConfId 
    #define MCS_DISP_GETMTBITRATE_ACK                   (MCS_DISP_MSG_BGN + 211)
    //MCU�ܾ��������̨��ѯ�ն�����, ��Ϣ��: CConfId
    #define MCS_DISP_GETMTBITRATE_NACK                  (MCS_DISP_MSG_BGN + 212)
    //MCU�ܾ��������̨��ѯ�ն�����, ��Ϣ��: CConfId + TMtBitrate����
    #define MCS_DISP_GETMTBITRATE_NOTIF                 (MCS_DISP_MSG_BGN + 213)

//1.6.9	�����ն˾���
    //MCUӦ��������̨�����ն˾���, ��Ϣ��: CConfId + TMt + u8(1- MUTE 0-NOMUTE) + u8(1-DECODER 2-CAPTURE) 
    #define MCS_DISP_MTAUDMUTE_ACK                      (MCS_DISP_MSG_BGN + 215)
    //MCU�ܾ��������̨�����ն˾���, ��Ϣ��: CConfId + TMt
    #define MCS_DISP_MTAUDMUTE_NACK                     (MCS_DISP_MSG_BGN + 216)
    //MCU֪ͨ�������̨�����ն˾���, ��Ϣ��: CConfId + TMt + u8(1- MUTE 0-NOMUTE) + u8(1-DECODER 2-CAPTURE)
    #define MCS_DISP_MTAUDMUTE_NOTIF                    (MCS_DISP_MSG_BGN + 217)

//1.6.10�й���Ƶ�������

//1.6.10.1	���þ���
    //���о�����Ϣ: CConfId + TMt(�����ն�) + u8( ������ ) + ITInnerMatrixScheme[]
    #define MCS_DISP_MATRIX_ALLSCHE_NOTIF               (MCS_DISP_MSG_BGN + 220)

    //����������Ϣ ��Ϣ��: CConfId + TMt(�����ն�) + ITInnerMatrixScheme
    #define MCS_DISP_MATRIX_ONESCHE_NOTIF               (MCS_DISP_MSG_BGN + 221) 

    //��ǰ������Ϣ, ��Ϣ��: CConfId + TMt(�����ն�) + u8(0, 1-6)
    #define MCS_DISP_MATRIX_CURSCHE_NOTIF               (MCS_DISP_MSG_BGN + 222)

//1.6.10.2 ���þ����Ѿ�����
    //�ն����þ�����Ϣ֪ͨ, ��Ϣ��: CConfId + TMt(�����ն�) + u8(��������˿��� 0��ʾû�о���) 
    #define MCS_DISP_MATRIXEXINFO_NOTIF                 (MCS_DISP_MSG_BGN + 225)

    //�ն����þ������Ӷ˿ڻ�ȡ�ɹ�, ��Ϣ��: CConfId + TMt(�����ն�)
    #define MCS_DISP_MATRIXEXGETPORT_ACK                (MCS_DISP_MSG_BGN + 226)

    //�ն����þ������Ӷ˿ڻ�ȡʧ��, ��Ϣ��: CConfId + TMt(�����ն�)
    #define MCS_DISP_MATRIXEXGETPORT_NACK               (MCS_DISP_MSG_BGN + 227)

    //�ն����þ������Ӷ˿�֪ͨ, ��Ϣ��: CConfId + TMt(�����ն�) + u8(1-64)
    #define MCS_DISP_MATRIXEXGETPORT_NOTIF              (MCS_DISP_MSG_BGN + 228)

    //�ն����þ���˿���֪ͨ, ��Ϣ��: CConfId + TMt(�����ն�) + u8(1-64 )+s8[MAXLEN_MATRIXPORTNAME] 0��β���ַ���
    #define MCS_DISP_MATRIXEXPORTNAME_NOTIF             (MCS_DISP_MSG_BGN + 229)

    //�ն����þ������ж˿���֪ͨ, ��Ϣ��: CConfId + TMt(�����ն�) + s8[][MAXLEN_MATRIXPORTNAME] ����0 ��ʾ����˿��� ����Ϊ����˿ڣ����ַ������飩
    #define MCS_DISP_MATRIXEXGETALLPORTNAME_NOTIF       (MCS_DISP_MSG_BGN + 230)

//1.6.10.3 ��չ��ƵԴ
    //�ն���չ��ƵԴ���ж˿���֪ͨ, ��Ϣ��: CConfId + TMt(�����ն�) + tagITVideoSourceInfo[]
    #define MCS_DISP_VIDEOEXALLINFO_NOTIF               (MCS_DISP_MSG_BGN + 231)

    //�ն���չ��ƵԴ��Ϣ֪ͨ, ��Ϣ��: CConfId + TMt(�����ն�) + tagITVideoSourceInfo
    #define MCS_DISP_VIDEOEXINFO_NOTIF                  (MCS_DISP_MSG_BGN + 232)

//1.6.11 ����MCU����
    //�����¼�MCU����ɹ�Ӧ�� ��Ϣ��: CConfId + TMcu + BOOL
    #define MCS_DISP_LOCKSMCU_ACK                       (MCS_DISP_MSG_BGN + 235)
    //�����¼�MCU����ʧ��Ӧ�� ��Ϣ��: CConfId + TMcu
    #define MCS_DISP_LOCKSMCU_NACK                      (MCS_DISP_MSG_BGN + 236)

//1.6.12 ��ȡ�ն˰汾��Ϣ
    //��ȡ�ն˰汾��Ϣ�ɹ�Ӧ�� ��Ϣ��: CConfId
    #define MCS_DISP_GETMTVERSION_ACK                   (MCS_DISP_MSG_BGN + 237)
    //��ȡ�ն˰汾��Ϣʧ��Ӧ�� ��Ϣ��: CConfId
    #define MCS_DISP_GETMTVERSION_NACK                  (MCS_DISP_MSG_BGN + 238)

//1.7	�������
//1.7.1	¼���������
//1.7.1.1	¼�����
//1.7.1.1.1	����¼��
    //�����MCU����¼��
    //MCUͬ���ط�������, ��Ϣ��: CConfId + TMt + TEqp
    #define MCS_DISP_STARTREC_ACK                       (MCS_DISP_MSG_BGN + 240)
    //MCU�ܾ���ط�������, ��Ϣ��: CConfId + TMt + TEqp
    #define MCS_DISP_STARTREC_NACK                      (MCS_DISP_MSG_BGN + 241)
    //MCU֪ͨ���¼�����, ��Ϣ��: CConfId + TMt + TEqp + TRecProg
    #define MCS_DISP_RECPROG_NOTIF                      (MCS_DISP_MSG_BGN + 242)

//1.7.1.1.2	��ͣ¼������
    //MCUͬ������ͣ��������, ��Ϣ��: CConfId + TMt
    #define MCS_DISP_PAUSEREC_ACK                       (MCS_DISP_MSG_BGN + 243)
    //MCU�ܾ������ͣ��������, ��Ϣ��: CConfId + TMt
    #define MCS_DISP_PAUSEREC_NACK                      (MCS_DISP_MSG_BGN + 244)

//1.7.1.1.3	�ָ�¼��
    //MCUͬ���ػָ���������,��Ϣ��: CConfId + TMt
    #define MCS_DISP_RESUMEREC_ACK                      (MCS_DISP_MSG_BGN + 245)
    //MCU�ܾ���ػָ���������,��Ϣ��: CConfId + TMt
    #define MCS_DISP_RESUMEREC_NACK                     (MCS_DISP_MSG_BGN + 246)

//1.7.1.1.4	ֹͣ¼��
    //MCUͬ����ֹͣ��������, ��Ϣ��: CConfId + TMt
    #define MCS_DISP_STOPREC_ACK                        (MCS_DISP_MSG_BGN + 247)
    //MCU�ܾ����ֹͣ��������, ��Ϣ��: CConfId + TMt
    #define MCS_DISP_STOPREC_NACK                       (MCS_DISP_MSG_BGN + 248)

//1.7.1.2	�������
//1.7.1.2.1	��ʼ����
    //MCU��ʼ����Ӧ��, ��Ϣ��: CConfId + TEqp
    #define MCS_DISP_STARTPLAY_ACK                      (MCS_DISP_MSG_BGN + 250)
    //MCU�ܾ���ʼ����, ��Ϣ��: CConfId + TEqp
    #define MCS_DISP_STARTPLAY_NACK                     (MCS_DISP_MSG_BGN + 251)
    //�������֪ͨ, ��Ϣ��: CConfId + TEqp + TRecProg
    #define MCS_DISP_PLAYPROG_NOTIF                     (MCS_DISP_MSG_BGN + 252)

//1.6.1.2.2	��ͣ����
    //MCU��ͣ����Ӧ��, ��Ϣ��: CConfId + TEqp
    #define MCS_DISP_PAUSEPLAY_ACK                      (MCS_DISP_MSG_BGN + 253)
    //MCU�ܾ���ͣ����, ��Ϣ��: CConfId + TEqp
    #define MCS_DISP_PAUSEPLAY_NACK                     (MCS_DISP_MSG_BGN + 254)

//1.7.1.2.3	�ָ�����
    //MCU�ָ�����Ӧ��, ��Ϣ��: CConfId + TEqp
    #define MCS_DISP_RESUMEPLAY_ACK                     (MCS_DISP_MSG_BGN + 255)
    //MCU�ܾ��ָ�����, ��Ϣ��: CConfId + TEqp
    #define MCS_DISP_RESUMEPLAY_NACK                    (MCS_DISP_MSG_BGN + 256)

//1.7.1.2.4	ֹͣ����
    //MCUֹͣ����Ӧ��, ��Ϣ��: CConfId + TEqp
    #define MCS_DISP_STOPPLAY_ACK                       (MCS_DISP_MSG_BGN + 257)
    //MCUֹͣ�ָ�����, ��Ϣ��: CConfId + TEqp
    #define MCS_DISP_STOPPLAY_NACK                      (MCS_DISP_MSG_BGN + 258)

//1.7.1.2.5	������ȵ���
    //MCUͬ������������Ӧ��, ��Ϣ��: CConfId + TEqp
    #define MCS_DISP_SEEKPLAY_ACK                       (MCS_DISP_MSG_BGN + 259)
    //MCU�ܾ������������Ӧ��, ��Ϣ��: CConfId + TEqp
    #define MCS_DISP_SEEKPLAY_NACK                      (MCS_DISP_MSG_BGN + 260)

//1.7.1.3   ¼�����쳣
    //����¼�����쳣֪ͨ, ��Ϣ��: CConfId + TEqp
    #define MCS_DISP_RECORDERABNORMAL_NOTIF             (MCS_DISP_MSG_BGN + 261)

//1.7.1.4	¼���ļ��б����
//1.7.1.4.1	��ȡ�ļ��б�����
    //��ȡ¼���ļ��б�Ӧ��, ��Ϣ��: TEqp
    #define MCS_DISP_GETRECFILELIST_ACK                 (MCS_DISP_MSG_BGN + 265)
    //��ȡ¼���ļ��б�ܾ�, ��Ϣ��: TEqp
    #define MCS_DISP_GETRECFILELIST_NACK                (MCS_DISP_MSG_BGN + 266)
    //¼���ļ��б�֪ͨ��Ϣ, ��Ϣ��: TEqp
    #define MCS_DISP_RECFILELIST_NOTIF                  (MCS_DISP_MSG_BGN + 267)
	//¼���ļ��ļ���������1000֪ͨ��Ϣ
    #define  MCS_DISP_REACH_MAX_REC_FILE_NOTIF			(MCS_DISP_MSG_BGN + 264)

//1.7.1.4.2 �޸�¼���ļ���
    //�޸�¼���ļ����ɹ�, ��Ϣ��: TEqp
    #define MCS_DISP_MODIFYRECFILE_ACK                  (MCS_DISP_MSG_BGN + 268)
    //�޸�¼���ļ���ʧ��, ��Ϣ��: TEqp
    #define MCS_DISP_MODIFYRECFILE_NACK                 (MCS_DISP_MSG_BGN + 269)

//1.7.1.4.3	ɾ����¼�ļ�����
    //�������ɾ���ļ�Ӧ��, ��Ϣ��: TEqp + ��¼��
    #define MCS_DISP_DELRECFILE_ACK                     (MCS_DISP_MSG_BGN + 270)
    //�������MCU_MCS_ɾ���ļ��ܾ�, ��Ϣ��: TEqp
    #define MCS_DISP_DELRECFILE_NACK                    (MCS_DISP_MSG_BGN + 271)

//1.7.1.5 �ļ���������
//1.7.1.5.1 �������MCU�����ļ�
    //ͬ�⣬��Ϣ��: TEqp + u8(PUBLISH_LEVEL) + ¼����
    #define MCS_DISP_PUBLISHRECFILE_ACK                 (MCS_DISP_MSG_BGN + 272)
    //���ԣ���Ϣ��: TEqp + u8(PUBLISH_LEVEL) + ¼����
    #define MCS_DISP_PUBLISHRECFILE_NACK                (MCS_DISP_MSG_BGN + 273)

//1.7.1.5.2 �������MCUȡ�������ļ�
    //ͬ�⣬��Ϣ��: TEqp + ¼����
    #define MCS_DISP_CANCELRECFILEPUBLISH_ACK           (MCS_DISP_MSG_BGN + 274)
    //���ԣ���Ϣ��: TEqp + ¼����
    #define MCS_DISP_CANCELRECFILEPUBLISH_NACK          (MCS_DISP_MSG_BGN + 275)

//1.7.2	����
//1.7.3.1	��ʼ��������(����/����)
	//MCUͬ�⿪ʼ��������, ��Ϣ��: CConfId + TMcu + u8(ͬʱ�μ�����(����)�ĳ�Ա����) + TMt����(ָ����Ա����ʱ����)
	#define MCS_DISP_STARTMIX_ACK                       (MCS_DISP_MSG_BGN + 280)
	//MCU�ܾ���ʼ��������, ��Ϣ��: CConfId + TMcu + u8(ͬʱ�μ�����(����)�ĳ�Ա����) + TMt����(ָ����Ա����ʱ����)
	#define MCS_DISP_STARTMIX_NACK                      (MCS_DISP_MSG_BGN + 281)
	//MCU��ʼ��������֪ͨ, ��Ϣ��: CConfId + TMcu + u8(ͬʱ�μ�����(����)�ĳ�Ա����)
	#define MCS_DISP_STARTMIX_NOTIF                     (MCS_DISP_MSG_BGN + 282)
    //MCU���������̨�Ļ�������֪ͨ, ��Ϣ��: CConfId + n * (TMcu + TDiscussParam )
    #define MCS_DISP_MIXPARAM_NOTIF                     (MCS_DISP_MSG_BGN + 283)

//1.7.3.2	������������(����/����)
    //MCUͬ��������̨������������������, ��Ϣ��: CConfId + TMcu
    #define MCS_DISP_STOPMIX_ACK                        (MCS_DISP_MSG_BGN + 284)
    //MCU�ܾ��������̨������������������, ��Ϣ��: CConfId + TMcu
    #define MCS_DISP_STOPMIX_NACK                       (MCS_DISP_MSG_BGN + 285)
    //MCU���������̨��������������֪ͨ, ��Ϣ��: CConfId + TMcu
    #define MCS_DISP_STOPMIX_NOTIF                      (MCS_DISP_MSG_BGN + 286)

//1.7.3.3  ������Ա����
    //�ն�����������֪ͨ, ��Ϣ��: CConfId + TMt(�����ն�)
    #define MCS_DISP_MTAPPLYMIX_NOTIF                   (MCS_DISP_MSG_BGN + 287)

//1.7.3.4  ������ʱ
    //MCUͬ��������̨������ʱ����, ��Ϣ��: CConfId
    #define MCS_DISP_MODIFYMIXDELAY_ACK                 (MCS_DISP_MSG_BGN + 288)
    //MCU�ܾ��������̨������ʱ����, ��Ϣ��: CConfId
    #define MCS_DISP_MODIFYMIXDELAY_NACK                (MCS_DISP_MSG_BGN + 289)
    //������ʱ֪ͨ, ��Ϣ��: CConfId + u16(��ʱ������)
    #define MCS_DISP_MIXDELAY_NOTIF                     (MCS_DISP_MSG_BGN + 290)

//1.7.3.5	���������������Ʒ���
    //MCUͬ��������̨��ʼ�����������Ʒ��Ե�����, ��Ϣ��: CConfId
    #define MCS_DISP_STARTVAC_ACK                       (MCS_DISP_MSG_BGN + 295)
    //MCU�ܾ��������̨��ʼ�����������Ʒ��Ե�����, ��Ϣ��: CConfId
    #define MCS_DISP_STARTVAC_NACK                      (MCS_DISP_MSG_BGN + 296)
    //MCU���������̨��ʼ�����������Ʒ��Ե�֪ͨ, 
    //�ϲ����ͨ������MCS_DISP_CONFSTATUS_NOTIF���Դ���Ϣ,
    //��Ϣ��: CConfId
    #define MCS_DISP_STARTVAC_NOTIF                     (MCS_DISP_MSG_BGN + 297)

//1.7.3.6	ȡ�������������Ʒ���
    //MCUͬ��������ֹ̨ͣ�����������Ʒ��Ե�����, ��Ϣ��: CConfId
    #define MCS_DISP_STOPVAC_ACK                        (MCS_DISP_MSG_BGN + 300)
    //MCU�ܾ��������ֹ̨ͣ�����������Ʒ��Ե�����, ��Ϣ��: CConfId
    #define MCS_DISP_STOPVAC_NACK                       (MCS_DISP_MSG_BGN + 301)
    //MCU���������ֹ̨ͣ�����������Ʒ��Ե�֪ͨ, 
    //�ϲ����ͨ������MCS_DISP_CONFSTATUS_NOTIF���Դ���Ϣ,
    //��Ϣ��: CConfId
    #define MCS_DISP_STOPVAC_NOTIF                      (MCS_DISP_MSG_BGN + 302)

//1.7.4	����ϳɿ���
//1.7.4.1	��ʼ����ϳ�
    //MCUͬ�⻭��ϳ�����, ��Ϣ��: CConfId
    #define MCS_DISP_STARTVMP_ACK                       (MCS_DISP_MSG_BGN + 310)
    //MCU��ͬ�⻭��ϳ�����, ��Ϣ��: CConfId
    #define MCS_DISP_STARTVMP_NACK                      (MCS_DISP_MSG_BGN + 311)
    //����ϳɳɹ���ʼ֪ͨ, 
    //�ϲ����ͨ������MCS_DISP_CONFSTATUS_NOTIF���Դ���Ϣ,
    //��Ϣ��: CConfId + TVMPParam
    #define MCS_DISP_STARTVMP_NOTIF                     (MCS_DISP_MSG_BGN + 312)
    //MCU���������̨�Ļ���ϳɲ���֪ͨ,
    //�ϲ����ͨ������MCS_DISP_CONFSTATUS_NOTIF���Դ���Ϣ,
    //��Ϣ��: CConfId + TVMPParam
    #define MCS_DISP_VMPPARAM_NOTIF                     (MCS_DISP_MSG_BGN + 313)

//1.7.4.2 ֹͣ����ϳ�	
    //MCUͬ����Ƶ������������, ��Ϣ��: CConfId
    #define MCS_DISP_STOPVMP_ACK                        (MCS_DISP_MSG_BGN + 314)
    //MCU��ͬ���������ϳ�����, ��Ϣ��: CConfId
    #define MCS_DISP_STOPVMP_NACK                       (MCS_DISP_MSG_BGN + 315)
    //����ϳɳɹ�����֪ͨ, 
    //�ϲ����ͨ������MCS_DISP_CONFSTATUS_NOTIF���Դ���Ϣ,
    //��Ϣ��: CConfId
    #define MCS_DISP_STOPVMP_NOTIF                      (MCS_DISP_MSG_BGN + 316)

//1.7.4.3	�ı仭��ϳɲ���
    //MCUͬ��������̨�ĸı仭��ϳɲ�������, ��Ϣ��: CConfId + TVMPParam
    #define MCS_DISP_CHANGEVMPPARAM_ACK                 (MCS_DISP_MSG_BGN + 317)
    //MCU�ܾ��������̨�ĸı仭��ϳɲ�������, ��Ϣ��: CConfId
    #define MCS_DISP_CHANGEVMPPARAM_NACK                (MCS_DISP_MSG_BGN + 318)
    //MCUͬ��������̨�ĸı仭��ϳɲ�������, ��Ϣ��: CConfId + TVMPParam
    #define MCS_DISP_CHANGEVMPPARAM_NOTIF               (MCS_DISP_MSG_BGN + 319)

//1.7.4.4	����ϳɹ㲥����
    //MCUͬ��㲥����ϳ�����, ��Ϣ��: CConfId
    #define MCS_DISP_STARTVMPBRDST_ACK                  (MCS_DISP_MSG_BGN + 321)
    //MCU�ܾ��㲥����ϳ�����, ��Ϣ��: CConfId
    #define MCS_DISP_STARTVMPBRDST_NACK                 (MCS_DISP_MSG_BGN + 322)

    //MCUͬ��ֹͣ�㲥����ϳ�����, ��Ϣ��: CConfId
    #define MCS_DISP_STOPVMPBRDST_ACK                   (MCS_DISP_MSG_BGN + 323)
    //MCU�ܾ�ֹͣ�㲥����ϳ�����, ��Ϣ��: CConfId
    #define MCS_DISP_STOPVMPBRDST_NACK                  (MCS_DISP_MSG_BGN + 324)

    //�������ǽ
    #define MCS_DISP_STARTHDTVWALL_ACK                  (MCS_DISP_MSG_BGN + 325)
    #define MCS_DISP_STARTHDTVWALL_NACK                 (MCS_DISP_MSG_BGN + 326)
    #define MCS_DISP_STOPHDTVWALL_ACK                   (MCS_DISP_MSG_BGN + 327)
    //MCU�ܾ�ֹͣ����ͼ��, ��Ϣ��: CConfId + TTWSwitchInfo
    #define MCS_DISP_STOPHDTVWALL_NACK                  (MCS_DISP_MSG_BGN + 328)

//1.7.5	����ǽ����
//1.7.5.1	����ǽ����
    //MCUͬ�⿪ʼ����ͼ��, ��Ϣ��: CConfId + TTWSwitchInfo
    #define MCS_DISP_STARTTVWALL_ACK                    (MCS_DISP_MSG_BGN + 330)
    //MCU�ܾ���ʼ����ͼ��, ��Ϣ��: CConfId + TTWSwitchInfo
    #define MCS_DISP_STARTTVWALL_NACK                   (MCS_DISP_MSG_BGN + 331)

    //MCUͬ��ֹͣ����ͼ��, ��Ϣ��: CConfId + TTWSwitchInfo
    #define MCS_DISP_STOPTVWALL_ACK                     (MCS_DISP_MSG_BGN + 332)
    //MCU�ܾ�ֹͣ����ͼ��, ��Ϣ��: CConfId + TTWSwitchInfo
    #define MCS_DISP_STOPTVWALL_NACK                    (MCS_DISP_MSG_BGN + 333)

//1.7.5.1	�໭�����ǽ����
    //MCUͬ�⸴�ϵ���ǽ����, ��Ϣ��: CConfId
    #define MCS_DISP_STARTMULTITVWALL_ACK               (MCS_DISP_MSG_BGN + 334)
    //MCU�ܾ����ϵ���ǽ����, ��Ϣ��: CConfId
    #define MCS_DISP_STARTMULTITVWALL_NACK              (MCS_DISP_MSG_BGN + 335)
    //���ϵ���ǽ�ɹ���ʼ֪ͨ, ��Ϣ��: CConfId + TVMPParam
    #define MCS_DISP_STARTMULTITVWALL_NOTIF             (MCS_DISP_MSG_BGN + 336)

    //MCUͬ��������ϵ���ǽ����, ��Ϣ��: CConfId
    #define MCS_DISP_STOPMULTITVWALL_ACK                (MCS_DISP_MSG_BGN + 337)
    //MCU�ܾ��������ϵ���ǽ����, ��Ϣ��: CConfId
    #define MCS_DISP_STOPMULTITVWALL_NACK               (MCS_DISP_MSG_BGN + 338)
    //���ϵ���ǽ�ɹ�����֪ͨ, ��Ϣ��: CConfId
    #define MCS_DISP_STOPMULTITVWALL_NOTIF              (MCS_DISP_MSG_BGN + 339)

    //MCUͬ��������̨�ĸı临�ϵ���ǽ��������, ��Ϣ��: CConfId + TVMPParam
    #define MCS_DISP_CHANGEMULTITVWALLPARAM_ACK         (MCS_DISP_MSG_BGN + 340)
    //MCU�ܾ��������̨�ĸı临�ϵ���ǽ��������, ��Ϣ��: CConfId
    #define MCS_DISP_CHANGEMULTITVWALLPARAM_NACK        (MCS_DISP_MSG_BGN + 341)
    //��Ƶ���ϲ���֪ͨ, ��Ϣ��: CConfId + TVMPParam
    //�ϲ����ͨ������MCS_DISP_CONFSTATUS_NOTIF���Ե�����Ϣ
    #define MCS_DISP_MULTITVWALLPARAM_NOTIF             (MCS_DISP_MSG_BGN + 342)

    //mpu--vmp��ز���
    //��Ϣ��: u8 byMtId+TChnnlMemberInfo[]
    #define MCS_DISP_VMPPPRISEIZE_REQ                   (MCS_DISP_MSG_BGN + 343)
    #define MCS_DISP_VMPOVERHDCHNNLLMT_NOTIF            (MCS_DISP_MSG_BGN + 344)


//1.7.6	����״̬
    //MCUӦ��������̨�Ĳ�ѯ����״̬����, ��Ϣ��: TPeriEqpStatus  
    #define MCS_DISP_GETMCUPERIEQPSTATUS_ACK            (MCS_DISP_MSG_BGN + 360)
    //MCU�ܻ������̨�Ĳ�ѯ����״̬����, ��Ϣ��: ��
    #define MCS_DISP_GETMCUPERIEQPSTATUS_NACK           (MCS_DISP_MSG_BGN + 361)	
    //֪ͨ�������״̬�ı�,��Ϣ��: TPeriEqpStatus
    #define MCS_DISP_MCUPERIEQPSTATUS_NOTIF             (MCS_DISP_MSG_BGN + 362)

	//MCUӦ��������̨�Ĳ�ѯDCS����״̬����, ��Ϣ��: TPeriDCSStatus
	#define MCS_DISP_GETMCUDCSSTATUS_ACK				(MCS_DISP_MSG_BGN + 363)
	//MCU�ܻ������̨�Ĳ�ѯ����״̬����, ��Ϣ��: TEqp
	#define MCS_DISP_GETMCUDCSSTATUS_NACK				(MCS_DISP_MSG_BGN + 364)
    //֪ͨ�������״̬�ı�,��Ϣ��: TPeriDCSStatus
	#define MCS_DISP_GETMCUDCSSTATUS_NOTIF				(MCS_DISP_MSG_BGN + 365)
    //֪ͨMCS����ת����������,��Ϣ��: u8 byMpId + s8* achIp
	#define MCS_DISP_MPFLUXOVERRUN_NOTIF				(MCS_DISP_MSG_BGN + 366)
    //֪ͨMCS����ת����������,��Ϣ��: u8(DSC����),u32(DSC ip (������)),u32(DSC���ӵı���MCU��IP)
	#define MCS_DISP_NEWDSCREGREQ_NOTIF				    (MCS_DISP_MSG_BGN + 367)

//1.8	MCU�û�����
//1.8.1	����û�
    //MCU���ܻ������̨������û�����, ��Ϣ��: �û���[MAX_CHARLENGTH]
    #define MCS_DISP_ADDUSER_ACK                        (MCS_DISP_MSG_BGN + 380)
    //MCU�ܾ��������̨������û�����, ��Ϣ��: �û���[MAX_CHARLENGTH]
    #define MCS_DISP_ADDUSER_NACK                       (MCS_DISP_MSG_BGN + 381)
    //MCU֪ͨ�������̨����û�, ��Ϣ��: CUserFullInfo
    #define MCS_DISP_ADDUSER_NOTIF                      (MCS_DISP_MSG_BGN + 382)

//1.8.2	ɾ���û�
    //MCU���ܻ������̨��ɾ���û�����, ��Ϣ��: �û���[MAX_CHARLENGTH]
    #define MCS_DISP_DELUSER_ACK                        (MCS_DISP_MSG_BGN + 383)
    //MCU�ܾ��������̨��ɾ���û�����, ��Ϣ��: �û���[MAX_CHARLENGTH]
    #define MCS_DISP_DELUSER_NACK                       (MCS_DISP_MSG_BGN + 384)
    //MCU֪ͨ�������̨ɾ���û�, ��Ϣ��: �û���[MAX_CHARLENGTH]
    #define MCS_DISP_DELUSER_NOTIF                      (MCS_DISP_MSG_BGN + 385)

//1.8.3	�û��б�
    //�û��б�֪ͨ����Ϣ��: CLongMessage + CUserFullInfo����
    #define MCS_DISP_USERLIST_NOTIF                     (MCS_DISP_MSG_BGN + 386)

//1.8.4	�޸��û�
    //MCU���ܻ������̨���޸��û�����, ��Ϣ��: �û���[MAX_CHARLENGTH]
    #define MCS_DISP_MODIFYUSER_ACK                     (MCS_DISP_MSG_BGN + 387)
    //MCU�ܾ��������̨���޸��û�����, ��Ϣ��: �û���[MAX_CHARLENGTH]
    #define MCS_DISP_MODIFYUSER_NACK                    (MCS_DISP_MSG_BGN + 388)
    //MCU֪ͨ�������̨�޸��û�, ��Ϣ��: CUserFullInfo
    #define MCS_DISP_MODIFYUSER_NOTIF                   (MCS_DISP_MSG_BGN + 389)
//1.8.5 �����û���
	//MCU���ܻ������̨�������û�����, ��Ϣ��: NULL
	#define MCS_DISP_ADDUSERGROUP_ACK					(MCS_DISP_MSG_BGN + 390)
	//MCU�ܾ��������̨�������û�����, ��Ϣ��: NULL
	#define MCS_DISP_ADDUSERGROUP_NACK					(MCS_DISP_MSG_BGN + 391)
	//MCU֪ͨ�������̨�����û�, ��Ϣ��: NULL
	#define MCS_DISP_ADDUSERGROUP_NOTIF					(MCS_DISP_MSG_BGN + 392)

//1.8.6  ɾ���û���
	//MCU���ܻ������̨��ɾ���û�����, ��Ϣ��: NULL
	#define MCS_DISP_DELUSERGROUP_ACK					(MCS_DISP_MSG_BGN + 393)
	//MCU�ܾ��������̨��ɾ���û�����, ��Ϣ��: NULL
	#define MCS_DISP_DELUSERGROUP_NACK					(MCS_DISP_MSG_BGN + 394)
	//MCU֪ͨ�������̨ɾ���û�, ��Ϣ��: NULL
	#define MCS_DISP_DELUSERGROUP_NOTIF					(MCS_DISP_MSG_BGN + 395)

//1.8.7  �޸��û���
	//MCU���ܻ������̨���޸��û�����  ��Ϣ��: NULL
	#define MCS_DISP_MODIFYUSERGROUP_ACK				(MCS_DISP_MSG_BGN + 396)
	//MCU�ܾ��������̨���޸��û�����  ��Ϣ��: NULL
	#define MCS_DISP_MODIFYUSERGROUP_NACK				(MCS_DISP_MSG_BGN + 397)
	//MCU֪ͨ�������̨�޸��û�  ��Ϣ��: NULL
	#define MCS_DISP_MODIFYUSERGROUP_NOTIF				( MCS_DISP_MSG_BGN + 398 )

	//MCU֪ͨ�������̨�û����б���Ϣ ��Ϣ�� : NULL
	#define MCS_DISP_USERGROUPLIST_NOTIF				(MCS_DISP_MSG_BGN + 399)

//2   ��ַ��

//2.1   ���ӵ�ַ����Ŀ
    //���ӵ�ַ����Ŀ�ɹ�ȷ��, ��Ϣ��: ��
    #define MCS_DISP_ADDRBOOK_ADDENTRY_ACK              (MCS_DISP_MSG_BGN + 400)
    //���ӵ�ַ����Ŀ�ܾ�, ��Ϣ��: ��
    #define MCS_DISP_ADDRBOOK_ADDENTRY_NACK             (MCS_DISP_MSG_BGN + 401)

//2.2   ɾ����ַ����Ŀ
    //ɾ����ַ����Ŀ�ɹ�ȷ��, ��Ϣ��: ��
    #define MCS_DISP_ADDRBOOK_DELENTRY_ACK              (MCS_DISP_MSG_BGN + 402)
    //ɾ����ַ����Ŀ�ܾ���ʧ��, ��Ϣ��: ��
    #define MCS_DISP_ADDRBOOK_DELENTRY_NACK             (MCS_DISP_MSG_BGN + 403)
    //ɾ����ַ����Ŀ֪ͨ, ��Ϣ��: u32(��Ŀ������)
    #define MCS_DISP_ADDRBOOK_DELENTRY_NOTIF            (MCS_DISP_MSG_BGN + 404)

//2.3   �޸ĵ�ַ����Ŀ
    //�޸ĵ�ַ����Ŀ�ɹ�ȷ��, ��Ϣ��: ��
    #define MCS_DISP_ADDRBOOK_MODIFYENTRY_ACK           (MCS_DISP_MSG_BGN + 405)
    //�޸ĵ�ַ����Ŀ�ܾ���ʧ��, ��Ϣ��: ��
    #define MCS_DISP_ADDRBOOK_MODIFYENTRY_NACK          (MCS_DISP_MSG_BGN + 406)

//2.4   ���ӻ�������Ŀ
    //���ӵ�ַ��������Ŀ�ɹ�ȷ�� , ��Ϣ��: ��
    #define MCS_DISP_ADDRBOOK_ADDGROUP_ACK              (MCS_DISP_MSG_BGN + 407)
    //���ӵ�ַ����������Ŀ�ܾ���ʧ��, ��Ϣ��: ��
    #define MCS_DISP_ADDRBOOK_ADDGROUP_NACK             (MCS_DISP_MSG_BGN + 408)

//2.5   ɾ����������Ŀ
    //ɾ����ַ����������Ŀ�ɹ�ȷ��, ��Ϣ��: ��
    #define MCS_DISP_ADDRBOOK_DELGROUP_ACK              (MCS_DISP_MSG_BGN + 409)
    //ɾ����ַ����������Ŀ�ܾ���ʧ��, ��Ϣ��: ��
    #define MCS_DISP_ADDRBOOK_DELGROUP_NACK             (MCS_DISP_MSG_BGN + 410)
    //ɾ����ַ����������Ŀ֪ͨ, ��Ϣ��: u32(������������)
    #define MCS_DISP_ADDRBOOK_DELGROUP_NOTIF            (MCS_DISP_MSG_BGN + 411)

//2.6   �޸Ļ�������Ŀ
    //�޸ĵ�ַ����������Ŀ�ɹ�ȷ��, ��Ϣ��: ��
    #define MCS_DISP_ADDRBOOK_MODIFYGROUP_ACK           (MCS_DISP_MSG_BGN + 412)
    //�޸ĵ�ַ����������Ŀ�ܾ���ʧ��, ��Ϣ��: ��
    #define MCS_DISP_ADDRBOOK_MODIFYGROUP_NACK          (MCS_DISP_MSG_BGN + 413)

//2.7   ������������ն�
    //�����������������ն˳ɹ�ȷ��, ��Ϣ��: ��
    #define MCS_DISP_ADDRBOOK_ADDENTRYTOGROUP_ACK       (MCS_DISP_MSG_BGN + 414)
    //�����������������ն˾ܾ���ʧ��, ��Ϣ��: ��
    #define MCS_DISP_ADDRBOOK_ADDENTRYTOGROUP_NACK      (MCS_DISP_MSG_BGN + 415)

//2.8   �ӻ�������ɾ���ն�
    //ɾ���������е��ն˳ɹ�ȷ��, ��Ϣ��: ��
    #define MCS_DISP_ADDRBOOK_DELENTRYFROMGROUP_ACK     (MCS_DISP_MSG_BGN + 416)
    //ɾ���������е��ն˳ɹ��ܾ���ʧ��, ��Ϣ��: ��
    #define MCS_DISP_ADDRBOOK_DELENTRYFROMGROUP_NACK    (MCS_DISP_MSG_BGN + 417)

//2.9   ��ַ����Ϣ֪ͨ
    //��ַ����Ŀ֪ͨ, ��Ϣ��: TMcuAddrEntry
    #define MCS_DISP_ADDRBOOK_REFRESHENTRY_NOTIF        (MCS_DISP_MSG_BGN + 419)
    //��ַ��������֪ͨ, ��Ϣ��: TMcuAddrGroup
    #define MCS_DISP_ADDRBOOK_REFRESHGROUP_NOTIF        (MCS_DISP_MSG_BGN + 420)

//1.2.5 �޸�MCU�������ǽ����
    //�޸�MCU�������ǽ���óɹ�Ӧ��, ��Ϣ��: ��
    #define MCS_DISP_CHANGEHDUSCHEMEINFO_ACK                (MCS_DISP_MSG_BGN + 421)
    //�޸�MCU�������ǽ����ʧ��Ӧ��, ��Ϣ��: ��
    #define MCS_DISP_CHANGEHDUSCHEMEINFO_NACK               (MCS_DISP_MSG_BGN + 422)
    //�������ǽ����֪ͨ(��Ϣ����ܴ���32K), ��Ϣ��: THduStyleCfgInfo����
    #define MCS_DISP_MCU_HDUSCHEMEINFO_NOTIF                (MCS_DISP_MSG_BGN + 423)

//�������ǽͨ��������ѯ
    //��ʼ
    #define MCS_DISP_STARTHDUBATCHPOLL_ACK               (MCS_DISP_MSG_BGN + 424)
    #define MCS_DISP_STARTHDUBATCHPOLL_NACK              (MCS_DISP_MSG_BGN + 425)

    //ֹͣ
    #define MCS_DISP_STOPHDUBATCHPOLL_ACK               (MCS_DISP_MSG_BGN + 426)
    #define MCS_DISP_STOPHDUBATCHPOLL_NACK              (MCS_DISP_MSG_BGN + 427)

    //��ͣ
    #define MCS_DISP_PAUSEHDUBATCHPOLL_ACK               (MCS_DISP_MSG_BGN + 428)
    #define MCS_DISP_PAUSEHDUBATCHPOLL_NACK              (MCS_DISP_MSG_BGN + 429)

    //����
    #define MCS_DISP_RESUMEHDUBATCHPOLL_ACK              (MCS_DISP_MSG_BGN + 430)
    #define MCS_DISP_RESUMEHDUBATCHPOLL_NACK             (MCS_DISP_MSG_BGN + 431)

    //֪ͨ
    #define MCS_DISP_HDUBATCHPOLLSTATUS_NOTIF            (MCS_DISP_MSG_BGN + 432)


//3   ����
//3.1 ������ʱ
    #define MCS_DISP_OPERATE_TIMEOUT                    (MCS_DISP_MSG_BGN + 498) 
//3.2 ��⵽ҵ����Ϣ���Ȳ�����֪ͨ�ϲ㽫���ָ�
    #define MCS_DISP_SERVMSGLENERROR                    (MCS_DISP_MSG_BGN + 499)

//4   ������������Ϣ
//4.1 �޸ĵ���ģʽ
    #define MCU_DISP_VCS_CHANGE_MODE_ACK                (MCS_DISP_MSG_BGN + 600)
    #define MCU_DISP_VCS_CHANGE_MODE_NACK               (MCS_DISP_MSG_BGN + 601)
    #define MCU_DISP_VCS_CHANGE_MODE_NOTIF              (MCS_DISP_MSG_BGN + 602)

//4.2 �����ն�
    #define MCS_DISP_VCS_SHEDUALE_MT_ACK                (MCS_DISP_MSG_BGN + 603)
    #define MCS_DISP_VCS_SHEDUALE_MT_NACK               (MCS_DISP_MSG_BGN + 604)
    #define MCS_DISP_VCS_SHEDUALE_MT_NOTIF              (MCS_DISP_MSG_BGN + 605)

//4.3 ����״̬֪ͨ
    #define MCS_DISP_VCS_CONF_STATUS_NOTIF              (MCS_DISP_MSG_BGN + 606)

//4.4 �������
    #define MCU_DISP_VCS_ENTER_CONF_ACK                 (MCS_DISP_MSG_BGN + 607)
    #define MCU_DISP_VCS_ENTER_CONF_NACK                (MCS_DISP_MSG_BGN + 608)

//4.5 �뿪����
    #define MCU_DISP_VCS_QUIT_CONF_ACK                  (MCS_DISP_MSG_BGN + 609)
    #define MCU_DISP_VCS_QUIT_CONF_NACK                 (MCS_DISP_MSG_BGN + 610)

//4.6 ��������
    #define MCU_DISP_VCS_SOUND_CONTROL_ACK              (MCS_DISP_MSG_BGN + 611)
    #define MCU_DISP_VCS_SOUND_CONTROL_NACK             (MCS_DISP_MSG_BGN + 612)

//4.7 VCS����
    #define MCU_DISP_VCS_CHANGE_VCS_NAME_ACK            (MCS_DISP_MSG_BGN + 613)
    #define MCU_DISP_VCS_CHANGE_VCS_NAME_NACK           (MCS_DISP_MSG_BGN + 614)
    #define MCU_DISP_VCS_CHANGE_VCS_NAME_NOTIF          (MCS_DISP_MSG_BGN + 615)

//5.1 ������������
    #define MCU_DISP_VCS_CALL_GROUP_ACK                 (MCS_DISP_MSG_BGN + 616)
    #define MCU_DISP_VCS_CALL_GROUP_NACK                (MCS_DISP_MSG_BGN + 617)
    #define MCU_DISP_VCS_CALL_GROUP_NOTIF               (MCS_DISP_MSG_BGN + 618)

//5.2 �����Ҷ�������ն�
    #define MCU_DISP_VCS_DROP_CALL_GROUP_MT_ACK         (MCS_DISP_MSG_BGN + 619)
    #define MCU_DISP_VCS_DROP_CALL_GROUP_MT_NACK        (MCS_DISP_MSG_BGN + 620)

//5.3 ����������ѯ
    #define MCU_DISP_VCS_START_CHAIRMANPOLL_ACK         (MCS_DISP_MSG_BGN + 621)
    #define MCU_DISP_VCS_START_CHAIRMANPOLL_NACK        (MCS_DISP_MSG_BGN + 622)

//5.4 �رձ�����ѯ
    #define MCU_DISP_VCS_STOP_CHAIRMANPOLL_ACK         (MCS_DISP_MSG_BGN + 623)
    #define MCU_DISP_VCS_STOP_CHAIRMANPOLL_NACK        (MCS_DISP_MSG_BGN + 624)

//5.5 ��ʱ����ն�
    #define MCU_DISP_VCS_ADD_MT_ACK                     (MCS_DISP_MSG_BGN + 625)
    #define MCU_DISP_VCS_ADD_MT_NACK                    (MCS_DISP_MSG_BGN + 626)

//5.6 ɾ���ն�
    #define MCU_DISP_VCS_DELETE_MT_ACK                  (MCS_DISP_MSG_BGN + 627)
    #define MCU_DISP_VCS_DELETE_MT_NACK                 (MCS_DISP_MSG_BGN + 628)

//7 �û�����
    #define MCU_DISP_VCS_USER_SETTING_ACK               (MCS_DISP_MSG_BGN + 629)
    #define MCU_DISP_VCS_USER_SETTING_NACK              (MCS_DISP_MSG_BGN + 630)
    #define MCU_DISP_VCS_USER_SETTING_NOTIF             (MCS_DISP_MSG_BGN + 631)

//8 ƽ��ǿ��
    #define MCU_DISP_VCS_RELEASE_MT_REQ                 (MCS_DISP_MSG_BGN + 632)
    #define MCU_DISP_VCS_RELEASE_MT_NOTIF               (MCS_DISP_MSG_BGN + 633)

// �����ϱ���ʱ֪ͨ�������Ϣ
    #define MCU_DISP_CONNECT_SLAVE_MCU_ACK              (MCS_DISP_MSG_BGN + 699)

//�����Ϣ������
#define MCS_DISP_MSG_END                                (MCS_DISP_MSG_BGN + 700)

//vcslib��Ϣ
#define VCSLIB_DISP_MSG_BGN                             (MCS_DISP_MSG_END + 500)
#define VCSLIB_DISP_MSG_END                             (VCSLIB_DISP_MSG_BGN + 300)

//4 mcslib�ڲ���Ϣ
//4.1   ��ʱ��Ϣ
    OSPEVENT( EV_SET_TIMER,                             EV_MC_BGN );
    OSPEVENT( TIMER_WAIT_REPLY,                         EV_MC_BGN + 1 );
    //���ӱ���MCU, ��MCUע��(����MCS_MCU_CONNECT_REQ��ȴ���Ӧ)
    OSPEVENT( TIMER_REG_BAKMCU,                         EV_MC_BGN + 2 );
    //��ѯMCU��ʱ(CPUʹ���ʡ�TMcuStatus)
    OSPEVENT( TIMER_REFRESHMCU,                         EV_MC_BGN + 6 );

//5 ���Բ�ѯ��Ϣ
//5.1   ��ַ��
    //��ַ����Ŀʹ����, ��Ϣ��
    //����: ��
    //����: u32
    OSPEVENT( MCSLIB_QUERY_ADDRENTRYUSEDNUM,            EV_MC_BGN + 20 );
#define MCSLIB_QUERY_MSG_BEGIN          MCSLIB_QUERY_ADDRENTRYUSEDNUM
    //��ַ��������ʹ����, ��Ϣ��
    //����: ��
    //����: u32
    OSPEVENT( MCSLIB_QUERY_ADDRGROUPUSEDNUM,            EV_MC_BGN + 21 );
    //��ַ��������Ŀ, ��Ϣ��
    //����: u32(�ѽ��ո���)
    //����: u32(�ܸ���) + u32(�ѷ��͸���) + u32(��η��͸���) + n * CAddrEntry
    OSPEVENT( MCSLIB_QUERY_ADDRALLENTRY,                EV_MC_BGN + 22 );
    //��ַ�����л�����, ��Ϣ��
    //����: u32(�ѽ��ո���)
    //����: u32(�ܸ���) + u32(�ѷ��͸���) + u32(��η��͸���) + n * CAddrMultiSetEntry
    OSPEVENT( MCSLIB_QUERY_ADDRALLGROUP,                EV_MC_BGN + 23 );
    //��ַ����Ŀ�Ƿ����, ��Ϣ��
    //����: TADDRENTRYINFO
    //����: BOOL
    OSPEVENT( MCSLIB_QUERY_ENTRYEXIST,                  EV_MC_BGN + 24 );
    //�������Ƿ����, ��Ϣ��
    //����: TMULTISETENTRYINFO
    //����: BOOL
    OSPEVENT( MCSLIB_QUERY_GROUPEXIST,                  EV_MC_BGN + 25 );
    //��ַ����Ŀ�Ƿ�����ڻ�������, ��Ϣ��
    //����: TADDRENTRYINFO + TMULTISETENTRYINFO
    //����: BOOL
    OSPEVENT( MCSLIB_QUERY_ENTRYEXISTINGROUP,           EV_MC_BGN + 26 );

//5.2   �û�
    //�û�����, ��Ϣ��
    //����: ��
    //����: u32
    OSPEVENT( MCSLIB_QUERY_USERNUM,                     EV_MC_BGN + 35 );
    //�����û�, ��Ϣ��
    //����: ��
    //����: u32(�ܸ���) + n * CUserFullInfo
    OSPEVENT( MCSLIB_QUERY_USERTABLE,                   EV_MC_BGN + 36 );

//5.3   ����
    //���л���ID, ��Ϣ��
    //����: ��
    //����: u32(�������) + n * CConfId
    OSPEVENT( MCSLIB_QUERY_ALLCONFID,                   EV_MC_BGN + 45 );
    //TConfInfo, ��Ϣ��
    //����: CConfId
    //����: TConfInfo
    OSPEVENT( MCSLIB_QUERY_CONFINFO,                    EV_MC_BGN + 46 );
    //TConfAllMtInfo, ��Ϣ��
    //����: CConfId
    //����: TConfAllMtInfo
    OSPEVENT( MCSLIB_QUERY_CONFALLMTINFO,               EV_MC_BGN + 47 );
    //����������Ϣ, ��Ϣ��
    //����: CConfId
    //����: TTvWallModule + TVmpModule + u8(m_byLockBySelf) + u32(m_dwLockMcsIP)
    //      + u8[33](m_abyLockUserName) + TEqp(m_tRecEqp) + TEqp(m_tPlayEqp)
    OSPEVENT( MCSLIB_QUERY_CONFOTHERINFO,               EV_MC_BGN + 48 );
    //��������MCU, ��Ϣ��
    //����: CConfId
    //����: u8(MCU����) + n * TMcu
    OSPEVENT( MCSLIB_QUERY_CONFALLMCU,                  EV_MC_BGN + 49 );
    //����MCU����Ϣ, ��Ϣ��
    //����: CConfId + TMcu
    //����: TMt(m_tMediaSrcMt) + u8(m_byLockStatus) + TDiscussParam(m_tMixParam)
    OSPEVENT( MCSLIB_QUERY_CONFMCUOTHERINFO,            EV_MC_BGN + 50 );
    //�����ն��б�, ��Ϣ��
    //����: CConfId + TMcu + u32(�����б��ѽ����ն˸���)
    //����: u32(�ܸ���) + u32(�ѷ��͸���) + u32(��η��͸���) + n * CMt
    OSPEVENT( MCSLIB_QUERY_MTTABLE,                     EV_MC_BGN + 51 );
    //�ն�, ��Ϣ��
    //����: CConfId + TMt
    //����: CMt
    OSPEVENT( MCSLIB_QUERY_MT,                          EV_MC_BGN + 52 );
    //���ͨ����Ϣ, ��Ϣ��
    //����: u8(ͨ����)
    //����: TMonitorParam
    OSPEVENT( MCSLIB_QUERY_MONITORPARAM,                EV_MC_BGN + 53 );

//5.4   ����
    //�����б�, ��Ϣ��
    //����: u32(�ѽ��ܸ���)
    //����: u32(�ܸ���) + u32(�ѷ��͸���) + u32(��η��͸���) + n * ( TPeriEqpStatus + u32(IP) )
    OSPEVENT( MCSLIB_QUERY_PERITABLE,                   EV_MC_BGN + 60 );
    //ָ������, ��Ϣ��
    //����: TEqp
    //����: TPeriEqpStatus
    OSPEVENT( MCSLIB_QUERY_PERISTATUS,                  EV_MC_BGN + 61 );

//5.5   ��ǰMCU״̬
    //�Ƿ����û���¼, ��Ϣ��
    //����: ��
    //����: BOOL
    OSPEVENT( MCSLIB_QUERY_USERLOGON,                   EV_MC_BGN + 70 );
    //TMcuExt, ��Ϣ��
    //����: ��
    //����: TMcuExt
    OSPEVENT( MCSLIB_QUERY_MCUSTATUS,                   EV_MC_BGN + 71);

//5.6   ���ò�ѯMCU������, ��Ϣ��
    //����: u32(MCU IP��ַ)
    //����: BOOL
    OSPEVENT( MCSLIB_QUERY_SETMCUSESSION,               EV_MC_BGN + 75 );
#define MCSLIB_QUERY_MSG_END          MCSLIB_QUERY_SETMCUSESSION

//6 mcslib��Ԫ������Ϣ
//6.1   ģ��MCU����Կ�
    //  ģ��MCU������Կ���Ӧ
    OSPEVENT(MCU_TESTER_REQ,                            EV_MC_BGN + 200);
    //  ���Կ��Ӧģ��MCU��Ӧ����
    OSPEVENT(TESTER_MCU_ACK,                            EV_MC_BGN + 201);

    //  ���Կⷢ��ģ��MCU��Ϣ�������
    OSPEVENT(TESTER_MCU_END_REQ,                        EV_MC_BGN + 202);
    //  ģ��MCU��Ӧ���Կ���Ϣ�����������
    OSPEVENT(MCU_TESTER_END_ACK,                        EV_MC_BGN + 203);

#endif  //  _EVMCSLIB_20050426_H_