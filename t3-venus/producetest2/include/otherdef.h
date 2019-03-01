
//�����궨���ļ�
#pragma once
#define MAX_SERIAL_LENGTH	(u32)32				//���к���󳤶�
#define MAX_SERIAL_INPUT_LEN (u32)10			//��������к���󳤶�	
#define MAX_MAC_LENGTH		(u32)32				//MAC��ַ�ַ�����󳤶�
#define MAX_VERSION_LENGTH	(u32)32				//�汾����
#define MAX_SYSFILE_NAME_LENGTH	(u32)32			//Sysfile����󳤶�
#define PIPELINE_SN_LEN     (u32)6				//�����ߺų���
#define MAX_DATE_LEN		(u32)20				//���ڳ��� yyyy/mm/dd hh:mm:ss
#define MAX_FILE_NAME_LENTH	(u32)256			//����ļ�������
#define MAX_PATH_LENTH		(u32)1024			//���·������
#define MAX_LOAD_BUF_LEN    (u32)800	        //���ػ���Ĵ�С
#define MAC_SIZE			(u32)6				//Mac 6�ֽ�
#define IP_SIZE				(u32)4				//IP 4�ֽ�
#define IP_STR_LEN			(u32)15				//ip�ַ�����󳤶�15
#define MAX_HW_LEN			(u32)4				//����HW����
#define LOGIN_MODE_LENTH    (u32)32				//��¼ʱģʽ��Ϣbuffer�ĳ���
#define USER_INFO_SIZE		(u32)152			//��¼ʱ���������û���Ϣ�ṹ����
#define MAX_COM_DISP_LEN    (u32)3000			//�����ն���ʾ����
//������Ϣ���
#define MAX_MSG_BODY_LEN	10000				//��Ϣ�峤��
//�˿�
#define SERVRT_PORT			60000				//OSP�����˿�
#define LOAD_UDP_PORT		6000				//����Udp�˿�
//��ɫ
#define COLOR_RED		0XFFFF0000
#define COLOR_BLUE		0XFF0000FF
#define COLOR_GREEN		0XFF009966
#define COLOR_BLACK		0xFF000000
#define COLOR_WHITE		0xFFFFFFFF
#define COLOR_GRAY		0xFFEEEEEE		
//����
#define VERSION_NUM     0X0100                      //�汾��
#define APP_PRIO		80							//App���ȼ�
#define DEFAULT_INS_ID	1							//Ĭ��Instance��	
#define INVALD_MODE		0xff
typedef std::string String;							//String
typedef DuiLib::CMarkupNode DocNode;				//DocNode
typedef DuiLib::CAppWindow Window;					//����
typedef DuiLib::CControlUI Control;					//�ؼ�
#define DOCMNGR IDocManager::GetSingletonPtr()		//�ĵ�����
#define USERDATA (IUserDataMngr::GetSingletonPtr())	//�û�����
#define CHECK_FILE_EXISTS ICommonOp::CheckFileExists
#define NOTIFY	ICommonOp::Notify
//�˿ڶ���
#define PRODUCETEST_SENDBASEPORT	(u32)12050
//��������������˿�
//��һ��HDU  video send
#define HDU_SNDRTPPORT1_vid		PRODUCETEST_SENDBASEPORT  + 0
//��һ��HDU  audeo send
#define HDU_SNDRTPPORT1_aud		PRODUCETEST_SENDBASEPORT  + 2
//�ڶ���HDU video send
#define HDU_SNDRTPPORT2_vid		PRODUCETEST_SENDBASEPORT  + 4
//�ڶ���HDU audeo send
#define HDU_SNDRTPPORT2_aud		PRODUCETEST_SENDBASEPORT  + 6
//������HDU video send
#define HDU_SNDRTPPORT3_vid		PRODUCETEST_SENDBASEPORT  + 8
//������HDU audeo send
#define HDU_SNDRTPPORT3_aud		PRODUCETEST_SENDBASEPORT  + 10
//EAPU����������RTP�˿�
#define	EAPU_SNDRTPPORT1_aud	PRODUCETEST_SENDBASEPORT  + 50
//EAPU�忨����������ʼRTP�˿�
#define EAPU_RCVRTPPORT			EAPU_LOCALRCVPORT + 2
//EAPU����������RTP�˿�
#define EAPU_DEC_LOCAL_RTPPORT	SERVER_RCVPORT + 2
//MPU/MPU2����������ʼRTP�˿�
#define MPU_SND_RTPPORT			PRODUCETEST_SENDBASEPORT + 8
//MPU/MPU2 VMPģʽ������RTP�˿�
#define MPU_DEC_LOCAL_RTPPORT	39000
//MPU-BASģʽ����RTP�˿�(4������ͨ��)
#define MPU_BAS_SNDRTPPORT_1	PRODUCETEST_SENDBASEPORT + 18
#define MPU_BAS_SNDRTPPORT_2	PRODUCETEST_SENDBASEPORT + 20
#define MPU_BAS_SNDRTPPORT_3	PRODUCETEST_SENDBASEPORT + 22
#define MPU_BAS_SNDRTPPORT_4	PRODUCETEST_SENDBASEPORT + 24
//MPU-BASģʽԶ��RTP�˿�(4������ͨ��)
#define MPUTEST_BAS_RECVBASEPORT_1	MPUTEST_BAS_RECVBASEPORT
#define MPUTEST_BAS_RECVBASEPORT_2	MPUTEST_BAS_RECVBASEPORT + 20
#define MPUTEST_BAS_RECVBASEPORT_3	MPUTEST_BAS_RECVBASEPORT + 40
#define MPUTEST_BAS_RECVBASEPORT_4	MPUTEST_BAS_RECVBASEPORT + 60
//MPU-BASģʽ������RTP�˿�(4������ͨ��)
#define MPUTEST_BAS_SENDSVRPORT_1	MPUTEST_BAS_SENDSVRPORT
#define MPUTEST_BAS_SENDSVRPORT_2	MPUTEST_BAS_SENDSVRPORT + 20
#define MPUTEST_BAS_SENDSVRPORT_3	MPUTEST_BAS_SENDSVRPORT + 40
#define MPUTEST_BAS_SENDSVRPORT_4	MPUTEST_BAS_SENDSVRPORT + 60


