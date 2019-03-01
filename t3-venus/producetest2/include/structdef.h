/*
	ͨ�ýṹ�嶨��
*/
#include "tptype.h"
#include "osp.h"
#pragma once
//UIģʽ
enum EmUIMode
{
	emModeNormal,	//��ͨģʽ
		emModeLoad,	//����ģʽ
		emModeTest	//����ģʽ
};

//UI״̬
enum EmUIState
{
	emUILoading,		//���ڼ���
		emUILoadEdit,	//���ر༭״̬
		emUILoadNormal,	//������ͨ״̬
		emUITesting,	//���ڲ���
		emUITestPre,	//����׼��
		emUITestReady	//����׼����
};

/*
	����������
*/
enum EmTestCaseType
{	
	emMediaCase,		//ý�������
		emCmdCase,		//���������
		emExeCase		//ִ�в�����

};

/*
	���������	
*/
enum EmTestCaseProcedure
{
	emCaseEndPending,		//�ȴ�����
		emCasePrePending,	//�ȴ���ʼ
		emCaseTested,		//�Ѿ�����
		emCaseTesting,		//���ڲ���
		emCaseWaiting		//�ȴ�
};

/*
	������״̬	
*/
enum EmTestCaseState
{
	emNotPassed,		//����δͨ��
		emNotReady,		//û��׼����
		emPassed,		//����ͨ��
		emReady,		//׼����
		emTesting,		//���ڲ���
/*		emReTesting,	//�лظ���Ϣ�Ĳ������ز�*/
        emReceived,       //���������������յ�����ֵ
		emCmdTesting,   //cmd����������ڲ���
		emAbort         //�ж�
};

/*
	�忨����	
*/
enum EmBrdProceduer
{
	emBrdRegPending,	//�忨ע��ȴ���
	emBrdPrePending,	//�忨׼���ȴ���
	emBrdEndPending,	//�忨�����ȴ�
	emBrdTesting,		//�忨������
	emBrdTested			//�忨�Ѿ�����
};


/*
	�ò���������� IDevice::SetTestCase�Ĳ���
*/
enum EmCaseSetType
{
	emTestNext,			//��һ��������
	emTestCur			//��ǰ������
};

/*
	�豸����״̬	
*/
enum EmDeviceLoadState
{

};

/*
	��Ϣ�����ݽṹ
*/
typedef struct tagMsgParam 
{
	u16		wMsgId;			// ��Ϣ��
	void*	pData;				// ����
}TMsgParam;

/*
	�������������ṹ
*/
typedef struct tagStreamInParam
{
	u32 dwVidCount;			//��Ƶ��
	u32 dwAudCount;			//��Ƶ��
	u32 dwVidRTPPort;		//��ƵRTP�˿�
	u32	dwAudRTPPort;		//��ƵRTP�˿�
	u16	wKeyFrameMsg;		//����ؼ�֡��Ϣ

}TStreamInParam;

/*
	������������ṹ
*/
typedef struct tagStreamOutParam
{	
	u32 dwVidCount;			//��Ƶ��
	u32 dwAudCount;			//��Ƶ��
	s8	achFileName[MAX_FILE_NAME_LENTH];	//�ļ���	
}TStreamOutParam;

/*
	��������������ṹ
*/
typedef struct EncoderNetParam
{
	u32		dwVidLocalRTPPortStart;			//��Ƶ�����������RTP��ʼ�˿�
	u32		dwVidLocalInterval;				//��Ƶ������������˿ڼ��
	u32		dwVidRemoteRTPPortStart;		//��ƵԶ���������RTP��ʼ�˿�
	u32		dwVidRemoteInterval;			//��ƵԶ����������˿ڼ��
	u32		dwAudLocalRTPPortStart;			//��Ƶ�����������RTP��ʼ�˿�
	u32		dwAudLocalInterval;				//��Ƶ������������˿ڼ��
	u32		dwAudRemoteRTPPortStart;		//��ƵԶ���������RTP��ʼ�˿�
	u32		dwAudRemoteInterval;			//��ƵԶ����������˿ڼ��
}TEncoderNetParam;


/*
	�忨ע����Ϣ
*/
typedef struct tagBrdRegMsg
{	
	u32 dwRegMsgId;			//ע����ϢID
	u32 dwAckMsgId;			//Ack��ϢID
	u32 dwNackMsgId;		//Nack��ϢID	
}TBrdRegMsg;

/*
	��Ϣ���� 	
*/
enum EmQueMsgType
{
	emMsgIn,			//������Ϣ
	emMsgOut			//������Ϣ
};

/*
	��������Ϣ�ṹ
*/
typedef struct tagQueMsg
{
	EmQueMsgType	emMsgType;						//��Ϣ����		
	u16				dwMsgId;						//��Ϣ��
	String			strMsgDiscription;				//����
	u8				achMsgBody[MAX_MSG_BODY_LEN];	//��Ϣ��
}TQueMsg;


//typedef struct tagDefaultStruct
//{
//	u32	dwMsgId;						
//	String strMsgDiscription;  
//	s8  achMsgBody[MAX_MSG_BODY_LEN];
//} Td;
/*
	��ϢIOspOb�������Ϣ�ṹ	
*/
typedef struct tagObMsg
{
	//Դ���
	u32 srcnode;
	//Ŀ�Ľ��
	u32 dstnode;
	//Ŀ��Ӧ��ʵ��
	u32 dstid;
	//ԴĿ��ʵ��
	u32 srcid;
	//��Ϣ��
	u16 event;
	//��Ϣ�峤��
	u16 length;
	//��Ϣ��
	u8 *content;
}TObMsg;

/*
	������״̬��Ϣ��	
*/
typedef struct tagCaseStateMsg
{
	String			strCaseName;	//��������	
	EmTestCaseState emState;		//״̬
}TCaseStateMsg;

/*
	�忨ע��ʱ�Ľṹ	
*/
typedef struct tagDeviceLoginInfo
{
    s8          achSerial[MAX_SERIAL_LENGTH];           //���к�
    s8          achMac[MAX_MAC_LENGTH];                 //mac��ַ
    s8          achSoftVersion[MAX_VERSION_LENGTH];     //����汾
    s8          achHardVersion[MAX_VERSION_LENGTH];     //Ӳ���汾
	EmCnModel   emMtModel;                              //�豸����
    u32_ip		    dwIp;                                   //�豸ip
    u32_ip			dwSubMask;                              //��������
}TDeviceInfo;

/*
������״̬���̣��忨���ģ�
*/
enum KDM_NOTIFY_STATUS
{
    KDM_BOOT_INITIAL= 0,		/* ��ʼ��״̬*/
		KDM_BOOTINFO_SET,       /* IP/MAC ���óɹ� */
		KDM_UPDATE_E2PROM,		/* EPROM �����ɹ� */
		KDM_UPLOAD_OS,			/* OS �ϴ���� */
		KDM_UPDATE_OS,			/* OS ������� */
		KDM_UPLOAD_UBOOT,		/* BOOT �ϴ���� */
		KDM_UPDATE_UBOOT,       /* BOOT ������� */
		KDM_UPLOAD_SYS,			/* SYS �ϴ���� */
		KDM_UPDATE_SYS,			/* SYS ������� */
		KDM_UPLOAD_APP,			/* APP�ϴ����*/
		KDM_UPDATE_APP,			/* APP�������*/
		KDM_UPLOAD_USR,			/* USR�ϴ����*/
		KDM_UPDATE_USR,			/* USR�������*/
		KDM_PROCESS_OK			/*�����������*/
};

/*
֪ͨ����ļ���״̬
*/
enum EmLoadState
{
	emBootInfoSet = 1,			//IP/MAC ���óɹ�
		emUpdateE2prom,			// EPROM �����ɹ� 
		emUploadSys,			// SYS �ϴ���� 
		emUpdateSys,			// SYS ������� 
		emProcessOk				//���м������  ȫ�������ɹ�
};

/*
֪ͨ����ļ��ش�����Ϣ	
*/
enum EmLoadErr
{
	emRcvAckErr = 1,	//����IP��MAC��ַ����
		emWriteEpromErr	//дEprom����
};