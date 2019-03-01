#include "stdafx.h"
#include "TestCase.h"


//CMediaTestCase��Ա����

CMediaTestCase::CMediaTestCase() : m_pPreMsgQue(0), m_pEndMsgQue(0)
{
	SetProcedure( emCaseWaiting );
	SetState( emNotReady );
//	m_vecTaskList.clear();
	m_bAdded = true;
	m_bRetestable = true;
}

CMediaTestCase::~CMediaTestCase()
{
	//�ͷ���Դ
	if( m_pPreMsgQue != NULL )
	{
		delete m_pPreMsgQue;
	}
	if ( m_pEndMsgQue != NULL )
	{
		delete m_pEndMsgQue;
	}
}

bool CMediaTestCase::SetType(EmTestCaseType emType)
{
	m_emType = emType;
	return true;
}

ITestCase* CMediaTestCase::Clone()
{
	return new CMediaTestCase( *this );
}

EmTestCaseState CMediaTestCase::GetState()
{
	return m_emState;
}

bool CMediaTestCase::SetState(EmTestCaseState emState)
{
	if ( m_emState == emState )
	{
		return false;
	}
	m_emState = emState;
	//֪ͨ
	TCaseStateMsg *pMsg = new TCaseStateMsg;
	pMsg->strCaseName = m_strName;
	pMsg->emState = emState;
	NOTIFY( EV_DVC_CASE_STATE_CHANGE, pMsg );
	return true;
}

EmTestCaseType CMediaTestCase::GetType()
{
	return m_emType;
}
bool CMediaTestCase::GetAdded() const
{
	return m_bAdded;
}
bool CMediaTestCase::SetAdded(const bool bAdded)
{
	m_bAdded = bAdded;
	return true;
}
bool CMediaTestCase::ExeTestCase()
{
	USERDATA->SetDispState( m_strName );
	SetState( emTesting );

	return true;
}

void CMediaTestCase::PreTest() 
{
	LOGEVENT("PreTest׼�������\n");


	SetProcedure( emCasePrePending );	//Pre���� �л�״̬Ϊ prepending
}

void CMediaTestCase::CheckProcedure()
{
	switch( m_emProcedure )
	{
	case emCasePrePending:
		assert( m_pPreMsgQue != NULL );
		if( m_pPreMsgQue->IsEmpty() )
		{
			LOGEVENT("׼����Ϣ����Ϊ��\n");			
		}
		else
		{
			SetProcedure( emCaseTesting );
		}
		break;
	case emCaseTesting:
		m_pPreMsgQue->SendHeaderMsg();
		ExeTestCase();
// 		if ( m_pPreMsgQue->IsEnd() )
// 		{
// 			SetProcedure( emCaseEndPending );
// 		}
		break;
	case emCaseEndPending:			
		assert( m_pEndMsgQue != NULL );
		if( m_pEndMsgQue->IsEmpty() )
		{
			LOGEVENT("������Ϣ����Ϊ��\n");
			SetProcedure(emCaseTested);
			LOGEVENT("���������\n");
		}
		else
		{
			OspDelay(200);
			m_pEndMsgQue->SendHeaderMsg();
			if ( m_pEndMsgQue->IsEnd() )
			{
				SetProcedure(emCaseTested);
			}
		}
		break;
	case emCaseTested:
		{

		}
	default:
		break;
	}
}
void CMediaTestCase::EndTest() 
{
	IWindowManager::GetSingletonPtr()->CloseWindow(_T("mediaplayer"));
}

void CMediaTestCase::Restore()
{
	//����Ҫ��ԭ
	if (m_emState == emReady && m_emProcedure == emCaseWaiting )
	{
		return;
	}
	//��Ϣ���л�ԭ
	if( m_pEndMsgQue != NULL )
	{
		m_pEndMsgQue->Restore();
	}
	if( m_pPreMsgQue != NULL )
	{
		m_pPreMsgQue->Restore();
	}

	//�������û����� ��Ҫ������Դ
	if ( m_emProcedure != emCaseTested )
	{
		EndTest();
	}
	//״̬���Ȼ�ԭ
	if ( m_emState == emTesting)
	{
		SetState( emAbort );
	}
	SetState( emReady );
	SetProcedure( emCaseWaiting );
//	m_vecTaskList.clear();
}

bool CMediaTestCase::SetPreMsgQue( IMsgQueMngr *pQue)
{
	m_pPreMsgQue = pQue;
	return true;
}

IMsgQueMngr* CMediaTestCase::GetPreMsgQue() const 
{
	return m_pPreMsgQue;
}

bool CMediaTestCase::SetEndMsgQue( IMsgQueMngr *pQue )
{
	m_pEndMsgQue = pQue;
	return true;
}

IMsgQueMngr* CMediaTestCase::GetEndMsgQue() const
{
	return m_pEndMsgQue;
}

void CMediaTestCase::ProcMsg( const TObMsg &msg )
{
	switch( m_emProcedure )
	{
	//�ȴ�׼��״̬����Ϣ����׼����Ϣ���д���
	case emCasePrePending:
		{
			if ( m_pPreMsgQue == NULL )
			{
				LOGEVENT("������׼����Ϣ����ָ��Ϊ��\n");
				return;
			}
			m_pPreMsgQue->ProcMsg(msg);
			if ( m_pPreMsgQue->IsEnd() )
			{
				SetProcedure( emCaseTesting );
			}
			break;
		}
	//�ȴ�����״̬����Ϣ����������Ϣ���д���
	case emCaseEndPending:
		{
			if ( m_pEndMsgQue == NULL )
			{
				LOGEVENT("�����������Ϣ����ָ��Ϊ��\n");
				return;
			}
			m_pEndMsgQue->ProcMsg(msg);
			if ( !m_pEndMsgQue->IsEmpty() && m_pEndMsgQue->IsEnd() )
			{
				EndTest();               
			}
			break;
		}
	default:
		//�����ǰ״̬��������Ϣ
		break;
	}
}


bool CMediaTestCase::SetCaseName( const String strCaseName )
{
	m_strName = strCaseName;
	return true;
}

bool CMediaTestCase::SetDescription( const String strDes )
{
	m_strDescription = strDes;
	return true;
}

String CMediaTestCase::GetCaseName() const
{
	return m_strName;
}

String CMediaTestCase::GetCaseDesc() const
{
	return m_strDescription;
}

void CMediaTestCase::Print()
{
	LOGEVENT("\tTestCase : %s\n", m_strName.c_str() );
	LOGEVENT("\ttype : %s\n", "media" );
	if ( m_pPreMsgQue != NULL )
	{
		LOGEVENT("\t---------------PreMsgQue------------------\n");
		m_pPreMsgQue->Print();
	}
	if ( m_pEndMsgQue != NULL )
	{
		LOGEVENT("\t---------------EndMsgQue------------------\n");
		m_pEndMsgQue->Print();
	}


}

bool CMediaTestCase::SetStreamIn( TStreamInParam StreamIn )
{
	memcpy( &m_tStreamInParam, &StreamIn, sizeof( TStreamInParam ) );
	return true;
}

bool CMediaTestCase::AddStreamOut( TStreamOutParam StreamOut )
{
	m_vecStreamOutList.push_back( StreamOut );
	return true;
}

bool CMediaTestCase::SetEncNetParam( TEncoderNetParam NetParam )
{
	memcpy( &m_tEncoderNetParam, &NetParam, sizeof(TEncoderNetParam) );
	return true;
}

bool CMediaTestCase::RemoveStreamOut( TStreamOutParam StreamOut )
{
	return false;
}

bool CMediaTestCase::SetProcedure(const EmTestCaseProcedure emProcedure )
{
	if ( m_emProcedure == emProcedure )
	{
		return false;
	}
	m_emProcedure = emProcedure;
	CheckProcedure();
	return true;
}

EmTestCaseProcedure CMediaTestCase::GetProcedure() const
{
	return m_emProcedure;
}

bool CMediaTestCase::SetFilePath( const String &strPath )
{
	m_strFilePath = strPath;
	return true;
}
String CMediaTestCase::GetFilePath() const
{
	return m_strFilePath;
}

void CMediaTestCase::SetRetestable( const bool &bRetest )
{
	m_bRetestable = bRetest;
}

bool CMediaTestCase::IsRetestable() const 
{
	return m_bRetestable;
}

// CMediaTestCase* CMediaTestCase::GetMediaTestPtr()
// {
// 	if ( NULL != m_pThis)
// 	{
// 		return m_pThis;
// 	}
// 	m_pThis = new CMediaTestCase;
// 	return m_pThis;
// }

//CCmdTestCase��Ա����
//CCmdTestCase* CCmdTestCase::m_pThat = NULL;
CCmdTestCase::CCmdTestCase() 
{
	SetState( emReady );
	m_bAdded = true;
	m_bRetestable = true;
}
CCmdTestCase::~CCmdTestCase()
{
	
}

ITestCase* CCmdTestCase::Clone()
{
	return new CCmdTestCase( *this );
}

EmTestCaseState CCmdTestCase::GetState()
{
	return m_emState;
}

bool CCmdTestCase::SetState(const EmTestCaseState emState)
{
	m_emState = emState;
	//֪ͨ
	TCaseStateMsg *pMsg = new TCaseStateMsg;
	pMsg->strCaseName = m_strName;
	pMsg->emState = emState;
	NOTIFY( EV_DVC_CASE_STATE_CHANGE, pMsg );
	return true;
}

EmTestCaseType CCmdTestCase::GetType()
{
	return m_emType;
}

void CCmdTestCase::Restore()
{
	//����Ҫ��ԭ
	if (m_emState == emReady && m_emProcedure == emCaseWaiting )
	{
		return;
	}
	//��Ϣ���л�ԭ
	if( m_pPreMsgQue != NULL )
	{
		m_pPreMsgQue->Restore();
	}
	
	//״̬���Ȼ�ԭ
	if ( m_emState == emCmdTesting)
	{
		SetState( emAbort );
	}
	SetState( emReady );
	SetProcedure( emCaseWaiting );
}

IMsgQueMngr* CCmdTestCase::GetPreMsgQue() const 
{
	return m_pPreMsgQue;
}

bool CCmdTestCase::SetPreMsgQue( IMsgQueMngr *pQue )
{
	m_pPreMsgQue = pQue;
	return true;
}

bool CCmdTestCase::SetType(EmTestCaseType emType)
{
	m_emType = emType;
	return true;
}

bool CCmdTestCase::GetAdded() const
{
	return m_bAdded;
}

bool CCmdTestCase::SetAdded(const bool bAdded)
{
	m_bAdded = bAdded;
	return true;
}
bool CCmdTestCase::ExeTestCase()
{
	USERDATA->SetDispState( m_strName );
	//SendMsg( m_dwCmdMsgId );
	SetState( emCmdTesting );
	return true;
}

void CCmdTestCase::PreTest() 
{	
	SetProcedure( emCasePrePending );	//Pre���� �л�״̬Ϊ prepending
}

void CCmdTestCase::ProcMsg( const TObMsg &msg)
{
	switch( m_emProcedure )
	{
		//�ȴ�׼��״̬����Ϣ����׼����Ϣ���д���
// 	case emCasePrePending:
// 		{
// 			if ( m_pPreMsgQue == NULL )
// 			{
// 				LOGEVENT("������׼����Ϣ����ָ��Ϊ��\n");
// 				return;
// 			}
// 			m_pPreMsgQue->ProcMsg(msg);
// 			if ( m_pPreMsgQue->IsEnd() )
// 			{
// 				SetProcedure( emCaseTesting );
// 			}
// 			break;
// 		}
	case emCaseTesting:
		{
			if ( m_pPreMsgQue == NULL )
			{
				LOGEVENT("������׼����Ϣ����ָ��Ϊ��\n");
				return;
			}
			m_pPreMsgQue->ProcMsg(msg);
//			CheckProcedure();
		}
		break;
	default:
		//�����ǰ״̬��������Ϣ
		break;
	}
}

bool CCmdTestCase::SetProcedure(const EmTestCaseProcedure emProcedure )
{
	if ( m_emProcedure == emProcedure )
	{
		return false;
	}
	m_emProcedure = emProcedure;
	CheckProcedure();
	return true;
}

void CCmdTestCase::CheckProcedure()
{
	switch( m_emProcedure )
	{
	case emCasePrePending:
		assert( m_pPreMsgQue != NULL );
		if( m_pPreMsgQue->IsEmpty() )
		{
			LOGEVENT("׼����Ϣ����Ϊ��\n");			
		}
		else
		{
			SetProcedure( emCaseTesting );			
		}
		break;
	case emCaseTesting:		
		m_pPreMsgQue->SendHeaderMsg();
		ExeTestCase();
		if ( m_pPreMsgQue->IsEnd() )
		{
			SetProcedure( emCaseTested );
		}
		break;
	case emCaseTested:
		{
			//m_pPreMsgQue->TestOver();
		}
		break;
	default:
		break;
	}
}


// bool CCmdTestCase::SetCmdMsgId( const u32 dwMsgId )
// {
// 	m_dwCmdMsgId = dwMsgId;
// 	return true;
// }

bool CCmdTestCase::SetCaseName( const String strCaseName )
{
	m_strName = strCaseName;
	return true;
}

bool CCmdTestCase::SetDescription( const String strDes )
{
	m_strDescription = strDes;
	return true;
}

String CCmdTestCase::GetCaseName() const
{
	return m_strName;
}

String CCmdTestCase::GetCaseDesc() const
{
	return m_strDescription;
}

void CCmdTestCase::Print()
{
	LOGEVENT("\tTestCase : %s\n", m_strName.c_str() );
	LOGEVENT("\ttype : %s\n", "cmd" );
	LOGEVENT("\tCmdMsgId : %d\n", m_dwCmdMsgId );
}

void CCmdTestCase::SetRetestable( const bool &bRetest )
{
	m_bRetestable = bRetest;
}

bool CCmdTestCase::IsRetestable() const
{
	return m_bRetestable;	
}

// CCmdTestCase* CCmdTestCase::GetCmdTestPtr()
// {
// 	if ( NULL != m_pThat )
// 	{
// 		return m_pThat;
// 	}
// 	m_pThat	= new CCmdTestCase;
// 
// 	return m_pThat;	
// }

EmTestCaseProcedure CCmdTestCase::GetProcedure() const
{
	return m_emProcedure;
}

//CExeTestCase��Ա����

CExeTestCase::CExeTestCase() 
{
	SetState(emNotReady);
	m_bAdded = true;
	m_bRetestable = true;
}

CExeTestCase::~CExeTestCase()
{
	
}

ITestCase* CExeTestCase::Clone()
{
	return new CExeTestCase( *this );
}

EmTestCaseState CExeTestCase::GetState()
{
	return m_emState;
}

bool CExeTestCase::SetState(const EmTestCaseState emState)
{
	m_emState = emState;
	//֪ͨ
	TCaseStateMsg *pMsg = new TCaseStateMsg;
	pMsg->strCaseName = m_strName;
	pMsg->emState = emState;
	NOTIFY( EV_DVC_CASE_STATE_CHANGE, pMsg );
	return true;
}

EmTestCaseType CExeTestCase::GetType()
{
	return m_emType;
}

bool CExeTestCase::SetType(EmTestCaseType emType)
{
	m_emType = emType;
	return true;
}
bool CExeTestCase::GetAdded() const
{
	return m_bAdded;
}

bool CExeTestCase::SetAdded(const bool bAdded)
{
	m_bAdded = bAdded;
	return true;
}
bool CExeTestCase::ExeTestCase()
{
	SetState( emTesting );
	USERDATA->SetDispState( m_strName );
	LOGEVENT("ִ�п���=̨����: %s\n", m_strExeCmd.c_str() );
	//system( m_strExeCmd.c_str() );
	return true;
} 

void CExeTestCase::ProcMsg( const TObMsg &msg )
{
}

bool CExeTestCase::SetExeCmdStr( const String strExeStr )
{
	m_strExeCmd = strExeStr;
	return true;
}

void CExeTestCase::Restore()
{
	if ( m_emState == emReady )
	{
		return;
	}
	if ( m_emState == emTesting)
	{
		SetState( emAbort );
	}
	SetState( emReady );
}

bool CExeTestCase::SetCaseName( const String strCaseName )
{
	m_strName = strCaseName;
	return true;
}

bool CExeTestCase::SetDescription( const String strDes )
{
	m_strDescription = strDes;
	return true;
}

String CExeTestCase::GetCaseName() const
{
	return m_strName;
}

String CExeTestCase::GetCaseDesc() const
{
	return m_strDescription;
}

void CExeTestCase::Print()
{
	LOGEVENT("\tTestCase : %s\n", m_strName.c_str() );
	LOGEVENT("\ttype : %s\n", "exe" );	
	LOGEVENT("\tExe String : %s\n", m_strExeCmd.c_str() );
}

void CExeTestCase::SetRetestable( const bool &bRetest )
{
	m_bRetestable = bRetest;
}

bool CExeTestCase::IsRetestable() const
{
	return m_bRetestable;
}
