/*****************************************************************************
ģ����      : tptooldef
�ļ���      : tptooldef.h
����ļ�    : 
�ļ�ʵ�ֹ���: tptool�⹫������
����        : ����ӡ
�汾        : V1.0  Copyright(C) 2012-2013 KDV, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��         �汾        �޸���      �޸�����
2012/12/11     1.0         ����ӡ      ����
******************************************************************************/
#ifndef TPTOOLDEF_H 
#define TPTOOLDEF_H

///////////////////////////��tptoolͨ�ý�����Ϣ////////////////////////////////
enum TPTOOLMSG
{
	em_TPTOOL_LOGINRESULT = TPTOOL_MSG_BEGIN + 0x01,
#define WM_TPTOOL_LOGINRESULT em_TPTOOL_LOGINRESULT      //tptool��½���  EM_LOGIN__TYPE:��½��Ϣ����  ����������  lParam:����ԭ��   Ĭ��ע������Ҫ���� ֱ�Ӹ�0   ��ռ����д��ռ��IP

	em_TPTOOL_LOGOFF,
#define WM_TPTOOL_LOGOFF em_TPTOOL_LOGOFF                //tptoolע���¼�

	em_TPTOOL_LOGGRAB,
#define WM_TPTOOL_LOGGRAB em_TPTOOL_LOGGRAB              //tptool��ռ�¼�

};


enum EM_SERVERAPP_TYPE      //��ǰ��½�ķ���������
{
	em_UMSTOOL_APP,
	em_CNSTOOL_APP,
	em_MOONTOOL_APP
};

enum EM_LOGIN__TYPE      //��½����
{
	em_LOGIN_SUCCESS,    //��½�ɹ�
	em_LOGIN_ERROR_RSQ,  //��½���
	em_LOGIN_TIMEOUT,	 //��½��ʱ
	em_LOGIN_LOGOFF,	 //ע��
	em_LOGIN_GRAP,		 //��ռ
	em_LOGIN_REFUSE,     //���Ǳ��ܾ�
	em_LOGIN_EXCEPTION,  //��½�쳣
	em_LOGIN_BREAK		 //��������Ͽ�
};


#endif