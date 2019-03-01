#include "StdAfx.h"
#include "UdpSession.h"
//121204 多网卡
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
	//创建Udp Socket
	//u32 dwLocalIP = 0;
	//u16 wUdpPort = GetIdlePort( dwLocalIP,LOAD_UDP_PORT, LOAD_UDP_PORT + 2000 );
	m_dwUdpId = UdpOpen( LOAD_UDP_PORT, ProcMsg );
	if ( CUdpSession::m_dwUdpId == 0 )
	{
		String strNotify = "加载Udp端口绑定失败";
		//LOGEVENT("加载Udp端口绑定失败\n");
		ICommonOp::ShowNotifyDlg( strNotify );
		return;
	}
	LOGEVENT("加载Udp端口绑定成功\n");

}
/*
报文格式：
    [IP][UDP][MESSAGE]
说明：
    UDP源目的端口都为6000
[MESSAGE]内部格式：
    [TYPE][LENGTH][TLV][TVL]……
说明：
    TYPE[4 bytes]：报文类型，如KDM_IPMACADDR_REQ，KDM_IPMACADDR_ACK，KDM_IPMACADDR_SET等；
    LENGTH[4 bytes]：报文长度，包含所有TLV子选项的总长度，不包含TYPE，LENGTH本身的长度；
    TLV：类型-长度-值；
    一个报文可以包含0个到多个TLV组合；
*/

#define		MSG_ID		0	//buf[0]	msgid(u32)
#define		MSG_LEN		4	//buf[4]	msglen(u32)
#define		TLV1		8	//buf[8]	tlv1(u32)
#define		TLVLEN		12	//buf[12]	tlvlen1(u32)
#define		STATE		16	//buf[16]	state(u32)
#define		ERR_CODE	20	//buf[20]	err code(u32)
void CUdpSession::ProcMsg( const s8 *ip, u16 port, const s8 *buf, s16 len )
{
	//测试模式屏蔽UDP消息
	if( USERDATA->GetUIMode() == emModeTest )
	{
		return;
	}
	LOGEVENT( "收到Udp消息,ip: %s, port: %d,len: %d\n", ip, port, len);
	if( USERDATA->GetUIState() == emUILoadEdit )
	{
		LOGEVENT("界面还在编辑状态，不能开始加载!\n");
		return;
	}
    u32 dwMsgId, dwMsgLen, dwTvl1, dwTlvLen1;
    const s8 *cbuf = NULL;
    dwMsgId = MKLONG( (buf + MSG_ID) );
    cbuf = &buf[MSG_LEN];
    dwMsgLen = MKLONG( cbuf );
    switch ( dwMsgId )
    {
		//请求加载信息
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
				//开始加载
				USERDATA->SetUIState( emUILoading );
			}
            break;
		//确认升级系统的信息
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
				//升级状态应答
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
						//升级状态
						switch ( MKLONG(cbuf) )
						{
						// IP/MAC 设置成功
						case KDM_BOOTINFO_SET:    
							{
								LOGEVENT("KDM_BOOTINFO_SET\n");
								u32 *pdwStateId = new u32;			//消息处理完释放
								*pdwStateId = emBootInfoSet;
								NOTIFY( EV_LOAD_STATE_UPDATE, pdwStateId );
							}
							break;
						// EPROM 升级成功 
						case KDM_UPDATE_E2PROM:    
							{
								LOGEVENT("KDM_UPDATE_E2PROM\n");
								u32 *pdwStateId = new u32;			//消息处理完释放
								*pdwStateId = emUpdateE2prom;
								NOTIFY( EV_LOAD_STATE_UPDATE, pdwStateId );				
							}
							break;
						// SYS 开始上传
						case KDM_UPLOAD_SYS:		
							{
								LOGEVENT("KDM_UPLOAD_SYS\n");
								u32 *pdwStateId = new u32;			//消息处理完释放
								*pdwStateId = emUploadSys;
								NOTIFY( EV_LOAD_STATE_UPDATE, pdwStateId );
							}
							break;
						// SYS 开始升级 
						case KDM_UPDATE_SYS:		
							{
								LOGEVENT("KDM_UPDATE_SYS\n");
								u32 *pdwStateId = new u32;			//消息处理完释放
								*pdwStateId = emUpdateSys;
								NOTIFY( EV_LOAD_STATE_UPDATE, pdwStateId );
							}
							break;
						//所有加载完成  全部升级成功
						case KDM_PROCESS_OK:   
							{
								LOGEVENT( "KDM_PROCESS_OK\n" );
								u32 *pdwStateId = new u32;			//消息处理完释放
								*pdwStateId = emProcessOk;
								NOTIFY( EV_LOAD_STATE_UPDATE, pdwStateId );
							}
							break;
						default :
							break;
						}	//switch(buf[STATE])

						//错误码
						cbuf = &buf[ERR_CODE];
						LOGEVENT("updata error code %d\n",MKLONG(cbuf));
						switch (MKLONG(cbuf))  
						{
						//分配IP、MAC地址
						case KDM_ERR_RCV_ACK_ERR:
							{
								u32 *pdwErrId = new u32;			//消息处理完释放
								*pdwErrId = emRcvAckErr;
								NOTIFY( EV_LOAD_ERR, pdwErrId );
							}
							
							break;
						//"写E2PROM"
						case KDM_ERR_WRITE_EPROM:
							{
								u32 *pdwErrId = new u32;			//消息处理完释放
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


