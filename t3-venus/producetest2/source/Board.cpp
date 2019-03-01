#include "stdafx.h"
#include "Board.h"
#include "MsgQueMngr.h"

CBoard::CBoard() : m_bActivated(false), m_dwAppId(0), m_dwIpAddr(0), m_strSysFile(""),
m_dwSubMsk(0), m_wHid(0), m_wPid(0), m_emProcedure(emBrdRegPending), m_pPreMsgQue(NULL), 
m_pEndMsgQue(NULL), m_pResMsgQue(NULL), m_strBrdName(""), m_strBrdDesc(""),m_dwEthernetCount(0),
m_byMode(0)
{	
	memset( m_achDate, 0, sizeof(m_achDate) );
	memset( m_achPipeLine, 0, sizeof(m_achPipeLine) );
	memset( m_achMac, 0, sizeof( m_achMac ) );	
	memset( m_achHardVersion, 0, sizeof( m_achHardVersion ) );
	memset( m_achSoftVersion, 0, sizeof(m_achSoftVersion) );
	memset( m_achSerialNo, 0, sizeof( m_achSerialNo ) );	
}
CBoard::~CBoard()
{
	//释放资源
	if( m_pPreMsgQue != NULL )
	{
		delete m_pPreMsgQue;
		m_pPreMsgQue = NULL;
	}
	if ( m_pEndMsgQue != NULL )
	{
		delete m_pEndMsgQue;
		m_pEndMsgQue = NULL;
	}
	if ( m_pResMsgQue != NULL)
	{
		delete m_pResMsgQue;
		m_pResMsgQue = NULL;
	}
	/*在这里释放板卡对应的网络资源*/
	SendMsg( OSP_DISCONNECT );	//先断开连接
	IOspSessionMngr::GetSingletonPtr()->KillSession( m_dwAppId );
}

bool CBoard::SetActivated( const bool bActivated )
{
	m_bActivated = bActivated;
	return true;
}

bool CBoard::GetActivated()  const
{
	return m_bActivated;
}

bool CBoard::SetAppId( const u32 dwAppId )
{
	m_dwAppId = dwAppId;
	return true;
}

u32	CBoard::GetAppId() const
{
	return m_dwAppId;
}

bool CBoard::SetE2promFlag( const u32 dwFlag )
{
	m_dwE2promFlag = dwFlag;
	return true;
}

bool CBoard::SetE2promInfo( const u32 dwInfo )
{
	m_dwE2promInfo = dwInfo;	
	return true;
}

u32 CBoard::GetE2promInfo()  const
{
	return m_dwE2promInfo;
}



u32 CBoard::GetE2promFlag()  const
{
	return m_dwE2promFlag;
}

bool CBoard::SetEndMsgQue( IMsgQueMngr *MsgQue )
{
	m_pEndMsgQue = MsgQue;
	return true;
}

IMsgQueMngr* CBoard::GetEndMsgQue() 
{
	return m_pEndMsgQue;
}

s8* CBoard::GetHardVersion()  
{
	return m_achHardVersion;
}

bool CBoard::SetHardVersion( const s8* pchHardVer )
{
	memset( m_achHardVersion, 0, sizeof(m_achHardVersion) );
	strcpy( m_achHardVersion, pchHardVer );
	return true;
}

u16	CBoard::GetHid() const
{
	return m_wHid;
}

bool CBoard::SetHid( const u16 &wHid )
{
	m_wHid = wHid;
	return true;
}


u16 CBoard::GetPid()  const
{
	return m_wPid;
}

bool CBoard::SetPid( const u16 &wPid )
{
	m_wPid = wPid;
	return true;
}

s8* CBoard::GetPipeLine()
{
	return m_achPipeLine;
}

bool CBoard::SetPipeLine( const s8* achPipeLine )
{
	memset( m_achPipeLine, 0, sizeof(m_achPipeLine) );
	strcpy( m_achPipeLine, achPipeLine );
	return true;
}

IMsgQueMngr* CBoard::GetPreMsgQue() const
{
	return m_pPreMsgQue;
}

bool CBoard::SetPreMsgQue( IMsgQueMngr *MsgQue )
{
	m_pPreMsgQue = MsgQue;
	return true;
}

bool CBoard::SetRegMsg( TBrdRegMsg RegMsg )
{
	memcpy( &m_RegMsg, &RegMsg, sizeof(TBrdRegMsg) );
	return true;
}

bool CBoard::SetSerialNo(const s8 *pchSn)
{
	memset( m_achSerialNo, 0, sizeof(m_achSerialNo) );
	strncpy( m_achSerialNo,pchSn,sizeof(m_achSerialNo));
//	strcpy( m_achSerialNo, pchSn );
	return true;
}

s8* CBoard::GetSerialNo()
{
	return m_achSerialNo;
}

bool CBoard::SetMac( const s8 *pchMac )
{
	memset( m_achMac, 0, sizeof(m_achMac) );
	strncpy( m_achMac, pchMac,sizeof(m_achMac));
	s32 nIdx = 0;
	for ( nIdx = 0; nIdx < sizeof(m_achMac); nIdx++ )
	{
		if ( m_achMac[nIdx] == '-')
		{
			m_achMac[nIdx] = ':';
		}
	}
	//转换成大写的
	ICommonOp::ConvertToUpper(m_achMac);
	LOGEVENT( "转换之后的Mac:%s\n", m_achMac );
	return true;
}

s8* CBoard::GetMac()
{
	return m_achMac;
}

s8* CBoard::GetSoftVersion()  
{
	return m_achSoftVersion;
}

bool CBoard::SetSoftVersion( const s8 *pchSoftVer )
{
	memset( m_achSoftVersion, 0, sizeof(m_achSoftVersion) );
	strcpy( m_achSoftVersion, pchSoftVer );
	return true;
}

bool CBoard::SetSubMsk( const u32 dwSubMsk )
{
	m_dwSubMsk = dwSubMsk;
	return true;
}

u32 CBoard::GetSubMsk() const
{
	return m_dwSubMsk;
}

LPCSTR CBoard::GetDate()
{
	return m_achDate;
}

bool CBoard::SetDate( LPCSTR pchDate )
{
	ZeroMemory( m_achDate, sizeof(m_achDate) );
	memcpy( m_achDate, pchDate, sizeof(m_achDate) );
	return true;
}

String CBoard::GetSysFile() const
{
	return m_strSysFile;
}

bool CBoard::SetSysFile( const String &strFileName )
{
	m_strSysFile = strFileName;
	return true;
}

IBoard* CBoard::Clone()
{
	//调用默认Copy构造函数
	//仅克隆数据成员，不包括测试项和消息队列
	IBoard *pBoard =  new CBoard( *this );
	//清除Decorater
	pBoard->SetDecorater( NULL );
	return  pBoard;
}


void CBoard::RegBrd( const TObMsg &ObMsg )
{
	if ( ObMsg.event != m_RegMsg.dwRegMsgId )
	{
		LOGEVENT("板卡 %s 登陆消息无效\n", m_strBrdName.c_str() );
		return;
	}
	LOGEVENT("板卡 %s 请求登陆\n", m_strBrdName.c_str() );
	//保存地址信息
	((IOspSession*)m_pDecorater)->SetAddrInfo(ObMsg.dstid, ObMsg.srcid);
	/*板卡注册，初始化一些成员变量，并通知界面*/
	//初始化板卡数据
	if ( InitTestInfo( ObMsg ) )
	{
		//数据初始完成 根据模式 创建测试项和消息队列 
		if ( !LoadTestContent() )
		{
			LOGEVENT("板卡注册失败!\n");
			m_byMode = INVALD_MODE;
			return;
		}
	}

	//测试项就绪
	for ( u32 dwIdx = 0; dwIdx < m_CaseContainer.GetCaseCount(); dwIdx++ )
	{
		ITestCase *pCase = m_CaseContainer.GetTestCase( dwIdx );
		if(pCase != NULL )
		{
			pCase->SetState( emReady );
		}
	}
	LOGEVENT("板卡 %s 注册成功!\n", m_strBrdName.c_str() );
	LOGEVENT("板卡 %s 等待准备消息\n", m_strBrdName.c_str() );
	LOGEVENT("------------------------------\n");

	//断链通知注册
//  OspNodeDiscCBReg(ObMsg->srcnode, AID_PRODUCETEST_APP, 1);
	//ack
	SendMsg( m_RegMsg.dwAckMsgId, NULL, 0 );
	//激活板卡
	m_bActivated = true;
	//板卡等待准备消息
	SetProcedure( emBrdPrePending );
	CMsgQueMngr::DataClear();
}

//收到设备完全启动消息后才让开始测试按钮高亮
// void CBoard::BtnCtrl( const TObMsg &ObMsg )
// {
// 	LOGEVENT("收到T300启动完毕消息 \n");
// 	NOTIFY( EV_DVC_ONLINE );
// 	//板卡等待准备消息
// 	SetProcedure( emBrdPrePending );
// }


bool CBoard::LoadTestContent()
{
	//清掉所有的观察者
	ClearOb();
	if( !IBoardFactory::GetSingletonPtr()->GetBrdTestCase( this ) || \
		!IBoardFactory::GetSingletonPtr()->GetBrdMsgQue( this ))
	{
		LOGEVENT("板卡信息加载失败\n");
		//通知界面测试项加载失败
		NOTIFY( EV_DVC_BRD_INFO_LOAD_FAIL, &m_strBrdName );
		m_CaseContainer.RemoveAll();
		ClearOb();
		return false;	//不允许测试
	}
	else
	{
		//通知界面测试项加载成功
		NOTIFY( EV_DVC_BRD_INFO_LOAD_SUCCESS, &m_strBrdName );
		return true;
	}
}


bool CBoard::InitTestInfo( const TObMsg &ObMsg )
{	
	TDeviceInfo DeviceInfo;
	DeviceInfo = *(TDeviceInfo*)ObMsg.content;
	//初次收到的MAC打印
	LOGEVENT("收到传输过来的Mac:%s\n", DeviceInfo.achMac );
	//memcpy( &DeviceInfo, ObMsg.content, sizeof(DeviceInfo) );
	SetIpAddr( DeviceInfo.dwIp );
	SetSubMsk( DeviceInfo.dwSubMask );
	SetSoftVersion( DeviceInfo.achSoftVersion );
	String strHw =  ICommonOp::ConvertHardVer( DeviceInfo.achHardVersion );
	SetHardVersion( strHw.c_str() );
	SetMac( DeviceInfo.achMac );
	SetSerialNo( DeviceInfo.achSerial );
	return true;
}

void CBoard::ProcMsg( const TObMsg &ObMsg )
{
	switch ( m_emProcedure )
	{
	//等待注册状态，消息交给RegBrd函数
	case emBrdRegPending:
		{
			RegBrd( ObMsg );
		}
		break;
	//等待准备，消息交给准备消息队列
	case emBrdPrePending:
		{
			if ( m_pPreMsgQue == NULL )
			{
				LOGEVENT("准备消息队列无效");
				return;
			}
			m_pPreMsgQue->ProcMsg( ObMsg );
			if ( m_pPreMsgQue->IsEnd() )    //消息队列结束
			{
				SetProcedure( emBrdTesting );
				//通知
				NOTIFY( EV_DVC_TEST_BRD_READY );
			}
		}
		break;
	//等待结束，消息交给结束消息队列
	case emBrdEndPending:
		{
			assert( m_pEndMsgQue != NULL );
			m_pEndMsgQue->ProcMsg( ObMsg );
			if ( m_pEndMsgQue->IsEnd() )    //消息队列结束
			{
				SetProcedure( emBrdTested );
			}
		}
		break;
	case emBrdTested:
		{
			assert( m_pResMsgQue != NULL );
			m_pResMsgQue->ProcMsg( ObMsg );
			if ( m_pResMsgQue->IsEnd() )    //消息队列结束
			{
				//通知板卡测试完毕
				NOTIFY( EV_DVC_BRD_RESTORE_SUCCESS, &m_strBrdName );
				NOTIFY( EV_DVC_TEST_BRD_END );
				Restore();	
			}
			break;
		}
		break;
	//正在测试，消息转给测试项
	case emBrdTesting:
		{
			for ( u32 dwIdx = 0; dwIdx < m_CaseContainer.GetCaseCount(); dwIdx++ )
			{
				m_CaseContainer.GetTestCase(dwIdx)->ProcMsg(ObMsg);
			}
		}
		break;
	default:
		LOGEVENT("板卡当前状态不处理消息\n");
		break;
	}
}


bool CBoard::SetMode( u8 byMode )
{
	if ( m_byMode == byMode)
	{
		return false;
	}
	m_byMode = byMode;
	return true;
}

u8 CBoard::GetMode() const 
{
	return m_byMode;
}

bool CBoard::SetBrdPic(const String &strBrdPic )
{
	m_strBrdPic = strBrdPic;
	return true;
}

String CBoard::GetBrdPic() const
{
	return m_strBrdPic;
}

void CBoard::Print()
{
	String strProceduer = _T("");
	switch( m_emProcedure )
	{
	case emBrdRegPending:
		strProceduer = _T("RegPending");
		break;	
	case emBrdPrePending:
		strProceduer = _T("PrePending");
		break;
	case emBrdEndPending:
		strProceduer = _T("EndPending");
		break;
	case emBrdTesting:	
		strProceduer = _T("Testing");
		break;
	case emBrdTested:
		strProceduer = _T("Tested");
		break;
	default:
		break;
	}
	LOGEVENT("\tName : %s", m_strBrdName.c_str() );
	LOGEVENT("\tAppId : %d\n", m_dwAppId );
	LOGEVENT("\tPid : %d\n", m_wPid );
	LOGEVENT("\tHid : %d\n", m_wHid );
	LOGEVENT("\tMac : %s\n", m_achMac );
	LOGEVENT("\tProceduer:%s\n", strProceduer.c_str() );
	LOGEVENT("\tTestCase Count : %d\n", m_CaseContainer.GetCaseCount() );
	LOGEVENT("\n");
}

ITestCaseContainer* CBoard::GetCaseContainer() 
{
	return &m_CaseContainer;
}

bool CBoard::SetBrdName( const String strBrdName )
{
	m_strBrdName = strBrdName;
	return true;
}

String CBoard::GetBrdName() const
{
	return m_strBrdName;
}

bool CBoard::SetProcedure( const EmBrdProceduer emProcedure )
{
	m_emProcedure = emProcedure;
	CheckProcedure();		//修改完进度，自动检测
	return true;
}

void CBoard::CheckProcedure()
{
	switch( m_emProcedure )
	{
	case emBrdPrePending:
		if( m_pPreMsgQue == NULL )
		{
			LOGEVENT("准备消息队列无效\n");
			return;
		}
		if( m_pPreMsgQue->IsEmpty() )
		{
			LOGEVENT("板卡 %s 准备消息队列为空\n", m_strBrdName.c_str() );
			//通知
			NOTIFY( EV_DVC_TEST_BRD_READY );
			LOGEVENT("板卡 %s 可以开始测试\n", m_strBrdName.c_str());
			SetProcedure( emBrdTesting );
		}
		else
		{
			m_pPreMsgQue->SendHeaderMsg();
			if ( m_pPreMsgQue->IsEnd() )
			{
				NOTIFY( EV_DVC_TEST_BRD_READY );
				SetProcedure( emBrdTesting );
			}
		}
		break;
	case emBrdEndPending:
		assert( m_pEndMsgQue != NULL );
		//目前只有MPU配置了EndMsgQue,为切换模式消息
		//如果不需要恢复出厂设置,就走EndMsgQue,否则直接恢复出厂设置
		if ( !USERDATA->GetRestore() )
		{
			if( m_pEndMsgQue->IsEmpty() )
			{
				LOGEVENT("板卡 %s 结束消息队列为空\n", m_strBrdName.c_str());
				LOGEVENT("板卡 %s 测试完成\n", m_strBrdName.c_str() );
				SetProcedure( emBrdTested );

			}
			else
			{
				m_pEndMsgQue->SendHeaderMsg();
				if ( m_pEndMsgQue->IsEnd() )
				{
					SetProcedure( emBrdTested );
				}
			}
		}
		else
		{
			SetProcedure( emBrdTested );
		}
		break;
	case emBrdTested:
		{
			assert( m_pResMsgQue != NULL );
			//如果不需要恢复出厂设置
			if ( !USERDATA->GetRestore() )
			{
				LOGEVENT("不需要恢复出厂设置\n");
				//通知测试结束
				NOTIFY( EV_DVC_TEST_BRD_END );
				Restore();
			}
			else
			{
				if( m_pResMsgQue->IsEmpty() )
				{
					LOGEVENT("板卡 %s 恢复出厂设置消息队列为空\n", m_strBrdName.c_str());
					NOTIFY( EV_DVC_BRD_RESTORE_SUCCESS, &m_strBrdName );
					NOTIFY( EV_DVC_TEST_BRD_END );
					Restore();
				}
				else
				{
					::OspDelay(200);
					m_pResMsgQue->SendHeaderMsg();
					NOTIFY( EV_DVC_BRD_START_RESTORE );
					USERDATA->SetDispState( "设备正在恢复出厂设置,请在NIP的she模式下用hwinfo命令查看成功与否" ); 
					if ( m_pResMsgQue->IsEnd())
					{
						NOTIFY( EV_DVC_BRD_RESTORE_SUCCESS, &m_strBrdName );
						NOTIFY( EV_DVC_TEST_BRD_END );
						Restore();
					}
				}
			}
		}
		break;
	default:
		break;
	}
}

void CBoard::Restore()
{
	if ( m_emProcedure == emBrdRegPending )
	{
		return;
	}
	//断开连接
	SendMsg( OSP_DISCONNECT );

	m_CaseContainer.Restore();
	//板卡状态恢复
	SetProcedure( emBrdRegPending );
	//恢复消息队列
	if ( m_pPreMsgQue != NULL)
	{
		m_pPreMsgQue->Restore();
	}
	if ( m_pEndMsgQue != NULL)
	{
		m_pEndMsgQue->Restore();
	}
	if ( m_pResMsgQue != NULL)
	{
		m_pResMsgQue->Restore();
	}
}

bool CBoard::SetIpAddr(const u32 &dwIp )
{
	if ( m_dwIpAddr != dwIp )
	{
		m_dwIpAddr = dwIp;
	}
	return true;
}

u32 CBoard::GetIpAddr() const
{
	return m_dwIpAddr;
}

IMsgQueMngr* CBoard::GetResMsgQue()
{
	return m_pResMsgQue;
}


bool CBoard::SetResMsgQue( IMsgQueMngr *MsgQue )
{
	m_pResMsgQue = MsgQue;
	return true;
}

bool CBoard::SetBrdDesc( const String &strDesc )
{
	m_strBrdDesc = strDesc;
	return true;
}

String CBoard::GetBrdDesc()
{
	return m_strBrdDesc;
}

bool CBoard::SetEthernetCount( const u32 &dwCount )
{
	m_dwEthernetCount = dwCount;	
	return true;
}

u32 CBoard::GetEthernetCount() const
{
	return m_dwEthernetCount;	
}

// void CBoard::setType(EmCnModel emMtType)
// {
// 	EmCnModel emMtModel;
// 	emMtModel = (EmCnModel)htonl((u32)emMtType);
// } 
// 
// u32 CBoard::getType() const
// {
// 	return (EmCnModel)ntohl((u32)emMtModel);
// } 

void CBoard::ClearMsgQue()
{
	//删除消息队列
	if ( m_pPreMsgQue != NULL)
	{
		delete m_pPreMsgQue;
		m_pPreMsgQue = NULL;
	}
	if ( m_pEndMsgQue != NULL)
	{
		delete m_pEndMsgQue;
		m_pEndMsgQue = NULL;
	}
	if ( m_pResMsgQue != NULL)
	{
		delete m_pResMsgQue;
		m_pResMsgQue = NULL;
	}
}

