/*==========================================================
ģ����  ��updatecmc
�ļ���  ��updatecmcconst.h
����ļ���
ʵ�ֹ��ܣ�updatecmc��loadcmc�Ĺ�������
����	��Ф��Ȼ
��Ȩ	��
-------------------------------------------------------------------------------------------------------
�޸ļ�¼:
   ��  ��      �汾        �޸���      �޸�����
  2011/11/23   1.0         Ф��Ȼ        ���� 
==========================================================*/
#ifndef UPDATECMCCONST_H
#define UPDATECMCCONST_H

#include "msgIdDispatch.h"

//��Ϣ�¼�����
enum EmUpdateCmcEvent
{
	ev_UpdatecmcEvent_Start = 0,                  //�¼����忪ʼ

	ev_LoginLoadCmc_Req,                          //��¼
	ev_LoginLoadCmc_Rsp,
	ev_LogoutLoadCmc_Req,

	ev_RebootCmc_Cmd,                             //����cmc

	ev_UpdateOver_Nty,                            //�������

	ev_TimeOut,                                   //��ʱ

	ev_UpdatecmcEvent_End,                        //�¼��������
};


enum EmUiUpdateCmcMsg
{
	#define UI_UPDATECMC_MSG_BEGIN    UPDATECMC_MSG_BEGIN

	UI_UPDATECMC_CONNECTED  =  UI_UPDATECMC_MSG_BEGIN,

	UI_UPDATECMC_DISCONNECTED,

	UI_UPDATECMC_OVER,

	UI_REBOOTCMC_CMD,

	UI_FTP_PROGRESS,

	UI_UPDATECMC_MSG_END,
};


#define CONNETCT_PORT   6666                  //�����������˿�
#define TIMEOUT         3000                  //��ʱʱ��

#define BUF_SIZE        4096

typedef struct tagAddress
{
	u32 dwIP;
	u16 wPort;
	tagAddress()
	{
		dwIP = 0;
		wPort = 0;
	}
}TAddr;



#endif //UPDATECMCCONST_H