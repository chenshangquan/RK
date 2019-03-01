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
	//�ͷ���Դ
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
	/*�������ͷŰ忨��Ӧ��������Դ*/
	SendMsg( OSP_DISCONNECT );	//�ȶϿ�����
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
	//ת���ɴ�д��
	ICommonOp::ConvertToUpper(m_achMac);
	LOGEVENT( "ת��֮���Mac:%s\n", m_achMac );
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
	//����Ĭ��Copy���캯��
	//����¡���ݳ�Ա�����������������Ϣ����
	IBoard *pBoard =  new CBoard( *this );
	//���Decorater
	pBoard->SetDecorater( NULL );
	return  pBoard;
}


void CBoard::RegBrd( const TObMsg &ObMsg )
{
	if ( ObMsg.event != m_RegMsg.dwRegMsgId )
	{
		LOGEVENT("�忨 %s ��½��Ϣ��Ч\n", m_strBrdName.c_str() );
		return;
	}
	LOGEVENT("�忨 %s �����½\n", m_strBrdName.c_str() );
	//�����ַ��Ϣ
	((IOspSession*)m_pDecorater)->SetAddrInfo(ObMsg.dstid, ObMsg.srcid);
	/*�忨ע�ᣬ��ʼ��һЩ��Ա��������֪ͨ����*/
	//��ʼ���忨����
	if ( InitTestInfo( ObMsg ) )
	{
		//���ݳ�ʼ��� ����ģʽ �������������Ϣ���� 
		if ( !LoadTestContent() )
		{
			LOGEVENT("�忨ע��ʧ��!\n");
			m_byMode = INVALD_MODE;
			return;
		}
	}

	//���������
	for ( u32 dwIdx = 0; dwIdx < m_CaseContainer.GetCaseCount(); dwIdx++ )
	{
		ITestCase *pCase = m_CaseContainer.GetTestCase( dwIdx );
		if(pCase != NULL )
		{
			pCase->SetState( emReady );
		}
	}
	LOGEVENT("�忨 %s ע��ɹ�!\n", m_strBrdName.c_str() );
	LOGEVENT("�忨 %s �ȴ�׼����Ϣ\n", m_strBrdName.c_str() );
	LOGEVENT("------------------------------\n");

	//����֪ͨע��
//  OspNodeDiscCBReg(ObMsg->srcnode, AID_PRODUCETEST_APP, 1);
	//ack
	SendMsg( m_RegMsg.dwAckMsgId, NULL, 0 );
	//����忨
	m_bActivated = true;
	//�忨�ȴ�׼����Ϣ
	SetProcedure( emBrdPrePending );
	CMsgQueMngr::DataClear();
}

//�յ��豸��ȫ������Ϣ����ÿ�ʼ���԰�ť����
// void CBoard::BtnCtrl( const TObMsg &ObMsg )
// {
// 	LOGEVENT("�յ�T300���������Ϣ \n");
// 	NOTIFY( EV_DVC_ONLINE );
// 	//�忨�ȴ�׼����Ϣ
// 	SetProcedure( emBrdPrePending );
// }


bool CBoard::LoadTestContent()
{
	//������еĹ۲���
	ClearOb();
	if( !IBoardFactory::GetSingletonPtr()->GetBrdTestCase( this ) || \
		!IBoardFactory::GetSingletonPtr()->GetBrdMsgQue( this ))
	{
		LOGEVENT("�忨��Ϣ����ʧ��\n");
		//֪ͨ������������ʧ��
		NOTIFY( EV_DVC_BRD_INFO_LOAD_FAIL, &m_strBrdName );
		m_CaseContainer.RemoveAll();
		ClearOb();
		return false;	//���������
	}
	else
	{
		//֪ͨ�����������سɹ�
		NOTIFY( EV_DVC_BRD_INFO_LOAD_SUCCESS, &m_strBrdName );
		return true;
	}
}


bool CBoard::InitTestInfo( const TObMsg &ObMsg )
{	
	TDeviceInfo DeviceInfo;
	DeviceInfo = *(TDeviceInfo*)ObMsg.content;
	//�����յ���MAC��ӡ
	LOGEVENT("�յ����������Mac:%s\n", DeviceInfo.achMac );
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
	//�ȴ�ע��״̬����Ϣ����RegBrd����
	case emBrdRegPending:
		{
			RegBrd( ObMsg );
		}
		break;
	//�ȴ�׼������Ϣ����׼����Ϣ����
	case emBrdPrePending:
		{
			if ( m_pPreMsgQue == NULL )
			{
				LOGEVENT("׼����Ϣ������Ч");
				return;
			}
			m_pPreMsgQue->ProcMsg( ObMsg );
			if ( m_pPreMsgQue->IsEnd() )    //��Ϣ���н���
			{
				SetProcedure( emBrdTesting );
				//֪ͨ
				NOTIFY( EV_DVC_TEST_BRD_READY );
			}
		}
		break;
	//�ȴ���������Ϣ����������Ϣ����
	case emBrdEndPending:
		{
			assert( m_pEndMsgQue != NULL );
			m_pEndMsgQue->ProcMsg( ObMsg );
			if ( m_pEndMsgQue->IsEnd() )    //��Ϣ���н���
			{
				SetProcedure( emBrdTested );
			}
		}
		break;
	case emBrdTested:
		{
			assert( m_pResMsgQue != NULL );
			m_pResMsgQue->ProcMsg( ObMsg );
			if ( m_pResMsgQue->IsEnd() )    //��Ϣ���н���
			{
				//֪ͨ�忨�������
				NOTIFY( EV_DVC_BRD_RESTORE_SUCCESS, &m_strBrdName );
				NOTIFY( EV_DVC_TEST_BRD_END );
				Restore();	
			}
			break;
		}
		break;
	//���ڲ��ԣ���Ϣת��������
	case emBrdTesting:
		{
			for ( u32 dwIdx = 0; dwIdx < m_CaseContainer.GetCaseCount(); dwIdx++ )
			{
				m_CaseContainer.GetTestCase(dwIdx)->ProcMsg(ObMsg);
			}
		}
		break;
	default:
		LOGEVENT("�忨��ǰ״̬��������Ϣ\n");
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
	CheckProcedure();		//�޸�����ȣ��Զ����
	return true;
}

void CBoard::CheckProcedure()
{
	switch( m_emProcedure )
	{
	case emBrdPrePending:
		if( m_pPreMsgQue == NULL )
		{
			LOGEVENT("׼����Ϣ������Ч\n");
			return;
		}
		if( m_pPreMsgQue->IsEmpty() )
		{
			LOGEVENT("�忨 %s ׼����Ϣ����Ϊ��\n", m_strBrdName.c_str() );
			//֪ͨ
			NOTIFY( EV_DVC_TEST_BRD_READY );
			LOGEVENT("�忨 %s ���Կ�ʼ����\n", m_strBrdName.c_str());
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
		//Ŀǰֻ��MPU������EndMsgQue,Ϊ�л�ģʽ��Ϣ
		//�������Ҫ�ָ���������,����EndMsgQue,����ֱ�ӻָ���������
		if ( !USERDATA->GetRestore() )
		{
			if( m_pEndMsgQue->IsEmpty() )
			{
				LOGEVENT("�忨 %s ������Ϣ����Ϊ��\n", m_strBrdName.c_str());
				LOGEVENT("�忨 %s �������\n", m_strBrdName.c_str() );
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
			//�������Ҫ�ָ���������
			if ( !USERDATA->GetRestore() )
			{
				LOGEVENT("����Ҫ�ָ���������\n");
				//֪ͨ���Խ���
				NOTIFY( EV_DVC_TEST_BRD_END );
				Restore();
			}
			else
			{
				if( m_pResMsgQue->IsEmpty() )
				{
					LOGEVENT("�忨 %s �ָ�����������Ϣ����Ϊ��\n", m_strBrdName.c_str());
					NOTIFY( EV_DVC_BRD_RESTORE_SUCCESS, &m_strBrdName );
					NOTIFY( EV_DVC_TEST_BRD_END );
					Restore();
				}
				else
				{
					::OspDelay(200);
					m_pResMsgQue->SendHeaderMsg();
					NOTIFY( EV_DVC_BRD_START_RESTORE );
					USERDATA->SetDispState( "�豸���ڻָ���������,����NIP��sheģʽ����hwinfo����鿴�ɹ����" ); 
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
	//�Ͽ�����
	SendMsg( OSP_DISCONNECT );

	m_CaseContainer.Restore();
	//�忨״̬�ָ�
	SetProcedure( emBrdRegPending );
	//�ָ���Ϣ����
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
	//ɾ����Ϣ����
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

