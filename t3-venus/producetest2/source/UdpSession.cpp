#include "StdAfx.h"
#include "UdpSession.h"
//121204 ������
CUdpSession::CUdpSession() : m_dwIpAddr(0)
{
	Init();
}
s8 CUdpSession::m_achLoadBuf[MAX_LOAD_BUF_LEN] = {0};
u32 CUdpSession::m_dwInfoLen = 0;
u32 CUdpSession::m_dwUdpId = 0;


CUdpSession::~CUdpSession()
{
	UdpClose( m_dwUdpId );
}


void CUdpSession::Init()
{
	//����Udp Socket
	//u32 dwLocalIP = 0;
	//u16 wUdpPort = GetIdlePort( dwLocalIP,LOAD_UDP_PORT, LOAD_UDP_PORT + 2000 );
	m_dwUdpId = UdpOpen( LOAD_UDP_PORT, ProcMsg );
	if ( CUdpSession::m_dwUdpId == 0 )
	{
		String strNotify = "����Udp�˿ڰ�ʧ��";
		//LOGEVENT("����Udp�˿ڰ�ʧ��\n");
		ICommonOp::ShowNotifyDlg( strNotify );
		return;
	}
	LOGEVENT("����Udp�˿ڰ󶨳ɹ�\n");

}
/*
���ĸ�ʽ��
    [IP][UDP][MESSAGE]
˵����
    UDPԴĿ�Ķ˿ڶ�Ϊ6000
[MESSAGE]�ڲ���ʽ��
    [TYPE][LENGTH][TLV][TVL]����
˵����
    TYPE[4 bytes]���������ͣ���KDM_IPMACADDR_REQ��KDM_IPMACADDR_ACK��KDM_IPMACADDR_SET�ȣ�
    LENGTH[4 bytes]�����ĳ��ȣ���������TLV��ѡ����ܳ��ȣ�������TYPE��LENGTH����ĳ��ȣ�
    TLV������-����-ֵ��
    һ�����Ŀ��԰���0�������TLV��ϣ�
*/

#define		MSG_ID		0	//buf[0]	msgid(u32)
#define		MSG_LEN		4	//buf[4]	msglen(u32)
#define		TLV1		8	//buf[8]	tlv1(u32)
#define		TLVLEN		12	//buf[12]	tlvlen1(u32)
#define		STATE		16	//buf[16]	state(u32)
#define		ERR_CODE	20	//buf[20]	err code(u32)
void CUdpSession::ProcMsg( const s8 *ip, u16 port, const s8 *buf, s16 len )
{
	//����ģʽ����UDP��Ϣ
	if( USERDATA->GetUIMode() == emModeTest )
	{
		return;
	}
	LOGEVENT( "�յ�Udp��Ϣ,ip: %s, port: %d,len: %d\n", ip, port, len);
	if( USERDATA->GetUIState() == emUILoadEdit )
	{
		LOGEVENT("���滹�ڱ༭״̬�����ܿ�ʼ����!\n");
		return;
	}
    u32 dwMsgId, dwMsgLen, dwTvl1, dwTlvLen1;
    const s8 *cbuf = NULL;
    dwMsgId = MKLONG( (buf + MSG_ID) );
    cbuf = &buf[MSG_LEN];
    dwMsgLen = MKLONG( cbuf );
    switch ( dwMsgId )
    {
		//���������Ϣ
        case KDM_BOOTINFO_REQ:  
			{
				LOGEVENT( "KDM_BOOTINFO_REQ\n");
				NOTIFY( EV_LOAD_START_REQ );
				m_dwInfoLen = 0;
				memset( m_achLoadBuf, 0, sizeof(m_achLoadBuf) );
				if( ILoadInfoMngr::GetSingletonPtr()->GetLoadInfo( 0, m_achLoadBuf, m_dwInfoLen ) )
				{
					UdpWrite( CUdpSession::m_dwUdpId , ip, port, m_achLoadBuf, m_dwInfoLen );
				}
				//��ʼ����
				USERDATA->SetUIState( emUILoading );
			}
            break;
		//ȷ������ϵͳ����Ϣ
        case KDM_NOTIFY:  
			{
				LOGEVENT( "KDM_NOTIFY\n");
				if(dwMsgLen < 4)
				{
					break;
				}
				cbuf = &buf[TLV1];
				dwTvl1 = MKLONG(cbuf);
				OspPrintf(true,false,"updata rcv tlv1 %d\n",dwTvl1);
				if ( NET_NOTIFY_OPT == dwTvl1)
				{
					dwTvl1 = KDM_NOTIFY_OPT;
				}

				switch ( dwTvl1 )
				{
				//����״̬Ӧ��
				case KDM_NOTIFY_OPT:  
					{
						cbuf = &buf[TLVLEN];
						dwTlvLen1 = MKLONG(cbuf);
						LOGEVENT("updata rcv tlv1len  %d\n",dwTlvLen1);
						if( dwTlvLen1 < 1 )
						{
							break;
						}
						cbuf = &buf[STATE];
						LOGEVENT("updata state  %d\n",MKLONG(cbuf));
						//����״̬
						switch ( MKLONG(cbuf) )
						{
						// IP/MAC ���óɹ�
						case KDM_BOOTINFO_SET:    
							{
								LOGEVENT("KDM_BOOTINFO_SET\n");
								u32 *pdwStateId = new u32;			//��Ϣ�������ͷ�
								*pdwStateId = emBootInfoSet;
								NOTIFY( EV_LOAD_STATE_UPDATE, pdwStateId );
							}
							break;
						// EPROM �����ɹ� 
						case KDM_UPDATE_E2PROM:    
							{
								LOGEVENT("KDM_UPDATE_E2PROM\n");
								u32 *pdwStateId = new u32;			//��Ϣ�������ͷ�
								*pdwStateId = emUpdateE2prom;
								NOTIFY( EV_LOAD_STATE_UPDATE, pdwStateId );				
							}
							break;
						// SYS ��ʼ�ϴ�
						case KDM_UPLOAD_SYS:		
							{
								LOGEVENT("KDM_UPLOAD_SYS\n");
								u32 *pdwStateId = new u32;			//��Ϣ�������ͷ�
								*pdwStateId = emUploadSys;
								NOTIFY( EV_LOAD_STATE_UPDATE, pdwStateId );
							}
							break;
						// SYS ��ʼ���� 
						case KDM_UPDATE_SYS:		
							{
								LOGEVENT("KDM_UPDATE_SYS\n");
								u32 *pdwStateId = new u32;			//��Ϣ�������ͷ�
								*pdwStateId = emUpdateSys;
								NOTIFY( EV_LOAD_STATE_UPDATE, pdwStateId );
							}
							break;
						//���м������  ȫ�������ɹ�
						case KDM_PROCESS_OK:   
							{
								LOGEVENT( "KDM_PROCESS_OK\n" );
								u32 *pdwStateId = new u32;			//��Ϣ�������ͷ�
								*pdwStateId = emProcessOk;
								NOTIFY( EV_LOAD_STATE_UPDATE, pdwStateId );
							}
							break;
						default :
							break;
						}	//switch(buf[STATE])

						//������
						cbuf = &buf[ERR_CODE];
						LOGEVENT("updata error code %d\n",MKLONG(cbuf));
						switch (MKLONG(cbuf))  
						{
						//����IP��MAC��ַ
						case KDM_ERR_RCV_ACK_ERR:
							{
								u32 *pdwErrId = new u32;			//��Ϣ�������ͷ�
								*pdwErrId = emRcvAckErr;
								NOTIFY( EV_LOAD_ERR, pdwErrId );
							}
							
							break;
						//"дE2PROM"
						case KDM_ERR_WRITE_EPROM:
							{
								u32 *pdwErrId = new u32;			//��Ϣ�������ͷ�
								*pdwErrId = emWriteEpromErr;
								NOTIFY( EV_LOAD_ERR, pdwErrId );
							}
							
							break;
						default :
							break;
						}//switch(buf[ERR_CODE])
					} //case KDM_NOTIFY_OPT
					break;
				default:
					break;
				}//swtich( tvl1 )

			} //case KDM_NOTIFY
			break;
        default :
            break;
	} //switch (dwMsgId)
}


