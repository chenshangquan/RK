//��Ϣ�����ļ�
#pragma once

//�û�������������Ϣ
#define USER_MSG_BGN				WM_USER
#define EV_USER_DEVICE_CHANGE		(u16)( USER_MSG_BGN + 0 )		//�豸�����仯 ����Ϣ��
#define EV_USER_START_IP_CHANGE		(u16)( USER_MSG_BGN + 1 )		//��ʼIP��ַ�仯 ����Ϣ��
#define EV_USER_START_MAC_CHANGE	(u16)( USER_MSG_BGN + 2 )		//��ʼMac��ַ�仯 ����Ϣ��
#define EV_USER_UI_MODE_CHANGE		(u16)( USER_MSG_BGN + 3 )		//UIģʽ�仯 ����Ϣ��
#define EV_USER_UI_STATE_CHANGE		(u16)( USER_MSG_BGN + 4 )		//UI״̬�仯 ����Ϣ��
#define EV_USER_STATE_STR_UPATE     (u16)( USER_MSG_BGN + 5 )		//״̬�ַ������� ����Ϣ��
#define EV_USER_INIT_ST				(u16)( USER_MSG_BGN + 6 )		//��ʼ�������ն���Ϣ ��Ϣ��:���ƹ�����ָ��
#define EV_USER_TFTP_PATH_CHANGE	(u16)( USER_MSG_BGN + 7 )		//tftp·���仯��Ϣ
#define EV_MAIN_WND_SIZE_CHANGE		(u16)( USER_MSG_BGN + 8 )		//�����ڴ�С�仯
#define EV_MAIN_WND_MOVE			(u16)( USER_MSG_BGN + 9 )		//�������ƶ�



//�豸�����ϲ����Ϣ
#define DVC_MSG_BGN					WM_USER + 100
//�������
#define	EV_DVC_LOAD_REQ				(u16)( DVC_MSG_BGN + 0 )        //�豸�������� ����Ϣ��
#define	EV_DVC_LOAD_STATE_CHANGE	(u16)( DVC_MSG_BGN + 1 )		//�豸����״̬�仯 ��Ϣ�壺EmDeviceLoadState
#define EV_DVC_TEST_BRD_READY		(u16)( DVC_MSG_BGN + 2 )		//�忨׼������ ����Ϣ��
#define EV_DVC_TEST_BRD_END  		(u16)( DVC_MSG_BGN + 3 )		//�忨���� ����Ϣ��
#define EV_DVC_CASE_STATE_CHANGE	(u16)( DVC_MSG_BGN + 4 )		//������״̬�仯 ��Ϣ�� TCaseStateMsg
#define EV_DVC_BRD_INFO_LOAD_SUCCESS (u16)( DVC_MSG_BGN + 5 )		//�忨��Ϣ���سɹ���Ϣ ��Ϣ�� �忨����String��
#define EV_DVC_BRD_INFO_LOAD_FAIL   (u16)( DVC_MSG_BGN + 6 )		//�忨��Ϣ����ʧ����Ϣ ��Ϣ�� �忨����String��
#define EV_DVC_BRD_START_RESTORE	(u16)( DVC_MSG_BGN + 7 )		//�忨�ָ��������óɹ� ��Ϣ�� ��
#define EV_DVC_BRD_RESTORE_SUCCESS  (u16)( DVC_MSG_BGN + 8 )		//�忨�ָ��������óɹ� ��Ϣ�� �忨����String��
#define EV_DVC_TEST_ABORT           (u16)( DVC_MSG_BGN + 9 )		//�豸������ֹ
#define EV_DVC_DISCONNECT           (u16)( DVC_MSG_BGN + 10 )		//�豸����
#define EV_DVC_RESULT               (u16)( DVC_MSG_BGN + 11 )       //֪ͨ���浯����Ϣ
#define EV_DVC_SHOWBTN              (u16)( DVC_MSG_BGN + 12 )       //�����յ�����Ϣ��ʾ������һ����԰�ť
//���������Ϣ
#define EV_LOAD_START_REQ			(u16)( DVC_MSG_BGN + 13 )
#define EV_LOAD_STATE_UPDATE		(u16)( DVC_MSG_BGN + 14 )		//����״̬�仯  ��Ϣ�� EmLoadState��״̬��
#define EV_LOAD_ERR					(u16)( DVC_MSG_BGN + 15 )		//���ش�����Ϣ	��Ϣ�� EmLoadErr
#define EV_COM_DATA_READY			(u16)( DVC_MSG_BGN + 16 )		//���������ݿɹ���ȡ
#define EV_COM_UPDATE				(u16)( DVC_MSG_BGN + 17 )		//�����ն���ʾˢ��
#define EV_COMM_PORT_AVAILABLE      (u16)( DVC_MSG_BGN + 18 )		//�˿ڿ���

//����������Ϣ
/*
MSG TYPE
��������
*/
enum KDM_MESSAGE_TYPE
{
	/*
	���ܣ�
		�忨������IP��MAC
	����
		PU->������
	˵����
		����Ϣ��
	*/
	KDM_BOOTINFO_REQ = 0,

	/*
	���ܣ�
		������Ӧ��IP��MAC
	����
		������->�忨
	*/
	KDM_BOOTINFO_ACK,

	/*
	���ܣ�
		�忨ȷ�ϻ��IP��MAC������
	����
		�忨->������
	˵����
		�����ļ�����״̬�ı���
	*/
	KDM_NOTIFY
};

//֪ͨ��Ϣ
#define		KDM_NOTIFY_OPT		14
#define		NET_NOTIFY_OPT		20
//������Ϣ
#define KDM_ERR_RCV_ACK_ERR     0x01
#define KDM_ERR_WRITE_EPROM     0x02