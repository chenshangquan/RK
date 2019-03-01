#include "stdafx.h"
#include "Testlogic.h"
#include "testcase.h"
#include "SuperTerminalLogic.h"

#include <WINSOCK2.h>
#pragma comment(lib,"WS2_32.LIB")
BEGIN_MSG_MAP( CTestLogic, CNotifyUIImpl )
MSG_ITEMSELECTD( "CbDvcType", OnDvcSelected )
MSG_ITEMSELECTD( "LstTestCase", OnCaseSelected )
MSG_CLICK( "BtnStartTest", OnStartTest )
MSG_CLICK( "BtnStopTest", OnStopTest )
MSG_CLICK( "BtnNormal", OnNormal )
MSG_CLICK( "BtnAbnormal", OnAbnormal )
MSG_CLICK( "BtnConfig", OnCaseConfig )
MSG_CLICK( "BtnNextTest", OnNextTest )
MSG_CLICK( "BtnSysPrepare", OnSysPrepare )
MSG_INIWINDOW("MainFrame", OnIni )
MSG_SELECTCHANGE( "OptAdded", OnCaseAdded )
MSG_SELECTCHANGE( "OptSelectAll", OnSelectAll )
MSG_SELECTCHANGE( "OptRestore", OnRestoreChange )
USER_MSG( EV_USER_DEVICE_CHANGE, OnDvcChange )
USER_MSG( EV_DVC_TEST_BRD_READY, OnBrdReady )
USER_MSG( EV_DVC_TEST_BRD_END, OnBrdEnd )
USER_MSG( EV_USER_UI_MODE_CHANGE, OnUIModeChange )
USER_MSG( EV_USER_STATE_STR_UPATE, OnUpdateState )
USER_MSG( EV_USER_UI_STATE_CHANGE, OnUIStateChange )
USER_MSG( EV_DVC_CASE_STATE_CHANGE, OnCaseStateChange )
USER_MSG( EV_DVC_BRD_INFO_LOAD_SUCCESS, OnBrdInfoLoadSuccess )
USER_MSG( EV_DVC_BRD_INFO_LOAD_FAIL, OnCaseLoadFail )
USER_MSG( EV_DVC_BRD_START_RESTORE, OnStartRestore )
USER_MSG( EV_DVC_BRD_RESTORE_SUCCESS, OnRestoreSuccess )
//USER_MSG( EV_DVC_BRD_RESTORE_FAIL, OnRestoreFail )
USER_MSG( EV_DVC_TEST_ABORT, OnTestAbort )
USER_MSG( EV_DVC_DISCONNECT, OnBrdDisconnect)
USER_MSG( EV_DVC_RESULT,OnResultChange)
USER_MSG( EV_DVC_SHOWBTN, OnShowBtn)
END_MSG_MAP()

const String CTestLogic::strCaseListItem = _T("CaseListItem");
const String CTestLogic::strCaseLst      = _T("LstTestCase");
const String CTestLogic::strCbDvcType    = _T("CbDvcType");
const String CTestLogic::strCaseName     = _T("LabelCaseName");
const String CTestLogic::strCaseDesc     = _T("REditCaseDiscription");
const String CTestLogic::strBtnConfig	 = _T("BtnConfig");
const String CTestLogic::strLayoutInfo	 = _T("LayoutInfo");
const String CTestLogic::strBtnStart	 = _T("BtnStartTest");
const String CTestLogic::strBtnStop		 = _T("BtnStopTest");
const String CTestLogic::strStateDis	  = _T("LabelTestState");
const String CTestLogic::strOptAdded	  = _T("OptAdded");
const String CTestLogic::strOptSelectAll  = _T("OptSelectAll");
const String CTestLogic::strOptRestore    = _T("OptRestore");
const String CTestLogic::strCaseState     = _T("LabelState");
const String CTestLogic::strLayoutResult  = _T("LayoutResult");
const String CTestLogic::strNextTestBtn  = _T("NextTestBtn");
const String CTestLogic::strBtnNormal	  = _T("BtnNormal");
const String CTestLogic::strBtnAbnormal   = _T("BtnAbnormal");
const String CTestLogic::strSysPrepareBtn   = _T("SysPrepareBtn");
const String CTestLogic::strDvcPic        = _T("CtnrTestDvcPic");
const String CTestLogic::strLabelSn		  = _T("LabelSn");
const String CTestLogic::strLabelDvcType  = _T("LabelDvcType");
const String CTestLogic::strLabelIp		  = _T("LabelIpAddr");
const String CTestLogic::strLabelMac	  = _T("LabelMac");
const String CTestLogic::strCntnrResult   = _T("CntnrResult");
const String CTestLogic::strLabelSoftVer  = _T("LabelSoftVer");
const String CTestLogic::strLabelHardVer  = _T("LabelHardVer");
const u32 CTestLogic::dwItemHeight		  = 30;
const u32 CTestLogic::dwItemSlectedHeight = 100;


CTestLogic::CTestLogic():m_pPaintMngr(NULL)
{
}


CTestLogic::~CTestLogic()
{

}


bool CTestLogic::OnDvcSelected( TNotifyUI& msg )
{
	CHECKMANAGER
	if ( !CreateDvc() )
	{
		return false;
	}
	//��ʾ״̬
	USERDATA->SetDispState(_T("�ȴ��豸����"));
	return true;
	

}

bool CTestLogic::CreateDvc()
{
	String strDvcName = ICommonOp::GetControlText( m_pPaintMngr, CTestLogic::strCbDvcType );
	ICommonOp::EnableControl( false, m_pPaintMngr, CTestLogic::strOptSelectAll );
	ICommonOp::EnableControl( false, m_pPaintMngr, CTestLogic::strOptRestore );
	//�����豸
	if( USERDATA->SetDevice( strDvcName ) )
	{
		//��������豸�ɹ� ȫѡ���ָ��������ù�ѡ��
		ICommonOp::OptionSelect( true, m_pPaintMngr, CTestLogic::strOptSelectAll );
		ICommonOp::OptionSelect( true, m_pPaintMngr, CTestLogic::strOptRestore );
		USERDATA->SetUIState( emUITestPre );
		return true;
	}
	else
	{
		ICommonOp::OptionSelect( false, m_pPaintMngr, CTestLogic::strOptSelectAll );
		ICommonOp::OptionSelect( false, m_pPaintMngr, CTestLogic::strOptRestore );
		return false;
	}
}
bool CTestLogic::OnDvcChange( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	if ( USERDATA->GetUIMode() != emModeTest )
	{
		return false;
	}
	CHECKMANAGER
	//����豸��Ϣ
	ClearDvcInfo();
	//���ز������б�
	LoadCaseList();
	return true;
}

bool CTestLogic::LoadCaseList()
{
	if( m_pCaseList == NULL )
	{
		return false;
	}
	//�����
	if ( m_pCaseList->GetCount() != 0 )
	{
		m_pCaseList->RemoveAll();
	}
	IDevice *pDvc = USERDATA->GetDevice();
	if( pDvc == NULL )
	{
		String strDvcName = ICommonOp::GetControlText( m_pPaintMngr, CTestLogic::strCbDvcType );
		if ( strDvcName != "" )
		{
			ICommonOp::ShowNotifyDlg(_T("��ǰ�豸��ʧ�ܣ����������ļ�"));
		}
		return false;
	}
	//����������
	IBoard *pBoard;
	ITestCase *pTestCase;
	u32 dwBrdIdx = 0;
	while( pBoard = pDvc->GetBoard(dwBrdIdx) )
	{   
		u32 dwCaseIdx = 0;
		while( pTestCase = ICommonOp::GetTestCase( pBoard, dwCaseIdx ))
		{
			CListContainerElementUI *pListContainer = 
				(CListContainerElementUI*)IControlFactory::GetSingletonPtr()->GetControl( CTestLogic::strCaseListItem );
			//��������
			ICommonOp::SetControlText( pTestCase->GetCaseName(), m_pPaintMngr, CTestLogic::strCaseName, pListContainer);
			//����������
			ICommonOp::SetControlText( pTestCase->GetCaseDesc(), m_pPaintMngr, CTestLogic::strCaseDesc, pListContainer);
			//���״̬
			ICommonOp::OptionSelect( pTestCase->GetAdded(), m_pPaintMngr, CTestLogic::strOptAdded, pListContainer);
			//������״̬
			ICommonOp::SetControlText( _T(""), m_pPaintMngr, CTestLogic::strCaseState, pListContainer);

			m_pCaseList->Add( pListContainer );
			dwCaseIdx++;
		}
		dwBrdIdx++;
	}
	return true;
}



bool CTestLogic::OnCaseSelected( TNotifyUI& msg )
{
	CHECKMANAGER
	EmUIState emState = USERDATA->GetUIState(); 

	IDevice *pDvc = USERDATA->GetDevice();
	if ( pDvc == NULL )
	{
		return false;
	}
	//ѡ������
	CContainerUI *pCurSel = (CContainerUI*)m_pCaseList->GetItemAt( m_pCaseList->GetCurSel() );
	//��������
	String strName = ICommonOp::GetControlText( m_pPaintMngr, strCaseName, pCurSel );
	//���õ�ǰ������
	bool bRet = USERDATA->SetSelectedCase( strName );
	if ( !bRet )
	{
		LOGEVENT("���õ�ǰѡ����ʧ��");
		return false;
	}

	//����ʱ������Ӧ
	if ( emState == emUITesting )
	{
		ExpandCase( strName, false );
		return false;
	}

	//չ��
	if ( emState == emUITestPre )
	{
		//pre��ʱ��ֻ��չ������������
		ExpandCase( strName, false );
	}
	else
	{
		ExpandCase( strName, true );
	}
	return true;
}


bool CTestLogic::ExpandCase( const String &strName, bool bSet /*= true*/)
{

	if ( m_pCaseList->GetCount() == 0 )
	{
		LOGEVENT("�б�û�в��������ѡ����ʧ��");
		return false;
	}
	//��ԭ�б�
	RestoreList(bSet);
	//�õ�ָ������������
	CControlUI *pSel = GetCaseContainer( strName );
	if ( pSel == NULL )
	{
		return false;
	} 
	IDevice *pDvc = USERDATA->GetDevice();
	if ( pDvc == NULL )
	{
		LOGEVENT("��ȡ�豸ʧ��");
		return false;
	}
	ITestCase *pTestCase = ICommonOp::GetTestCase( pDvc, strName );
	if (pTestCase == NULL )
	{
		LOGEVENT("��ȡѡ�в�����ʧ��");
		return false;
	}
	//ֻ��media���������ʾ���ð���
	if ( pTestCase->GetType() == emMediaCase && bSet )
	{
		ICommonOp::ShowControl( /*true*/false, m_pPaintMngr, CTestLogic::strBtnConfig, pSel );
	}
	//��ʾ��Ϣ��������
	ICommonOp::ShowControl( true, m_pPaintMngr, CTestLogic::strLayoutInfo, pSel );
	//���
	pSel->SetFixedHeight( dwItemSlectedHeight );
	return true;
}

bool CTestLogic::OnBrdReady( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	CHECKMANAGER
	IDevice *pDvc = USERDATA->GetDevice();
	if ( pDvc == NULL )
	{
		LOGEVENT("�豸��Ч\n");
		return false;
	}
	static u32 dwReadyCount = 0;
	dwReadyCount++;
	//���а忨��׼������
	if ( dwReadyCount == pDvc->GetBrdCount() )
	{
		LOGEVENT("�忨׼������\n");
		USERDATA->SetUIState( emUITestReady );
		dwReadyCount = 0;
	}
	return true;
}

bool CTestLogic::LoadDvcInfo()
{
	IDevice *pDvc = USERDATA->GetDevice();
	//�豸��
	IBoard *pBoard = pDvc->GetBoard( 0 );
	if ( pBoard != NULL )
	{
		//�豸����
		ICommonOp::SetControlText( pBoard->GetBrdDesc(), m_pPaintMngr, CTestLogic::strLabelDvcType );
		//ͼƬ
		ICommonOp::SetControlBkImg( pBoard->GetBrdPic(), m_pPaintMngr, CTestLogic::strDvcPic );
		//Sn
		ICommonOp::SetControlText( pBoard->GetSerialNo(), m_pPaintMngr, CTestLogic::strLabelSn );
		//SoftVer
		ICommonOp::SetControlText( pBoard->GetSoftVersion(), m_pPaintMngr, CTestLogic::strLabelSoftVer );
		//HardVer
		ICommonOp::SetControlText( pBoard->GetHardVersion(), m_pPaintMngr, CTestLogic::strLabelHardVer );
		//Mac
		ICommonOp::SetControlText( pBoard->GetMac(), m_pPaintMngr, CTestLogic::strLabelMac );
		//Ip
		struct in_addr IpAddr;
		u32 dwIp = pBoard->GetIpAddr();
		memcpy( &IpAddr, &dwIp, sizeof(dwIp) );
		String strIpAddr = inet_ntoa( IpAddr );
		ICommonOp::SetControlText( strIpAddr, m_pPaintMngr, CTestLogic::strLabelIp );
	}
	return true;
}

bool CTestLogic::ClearDvcInfo()
{

	//�豸����
	ICommonOp::SetControlText( "", m_pPaintMngr, CTestLogic::strLabelDvcType );
	//ͼƬ
	ICommonOp::SetControlBkImg( "", m_pPaintMngr, CTestLogic::strDvcPic );
	//Sn
	ICommonOp::SetControlText( "", m_pPaintMngr, CTestLogic::strLabelSn );
	//SoftVer
	ICommonOp::SetControlText( "", m_pPaintMngr, CTestLogic::strLabelSoftVer );
	//HardVer
	ICommonOp::SetControlText( "", m_pPaintMngr, CTestLogic::strLabelHardVer );
	//Mac
	ICommonOp::SetControlText( "", m_pPaintMngr, CTestLogic::strLabelMac );
	//Ip
	ICommonOp::SetControlText( "", m_pPaintMngr, CTestLogic::strLabelIp );
	return true;
}

bool CTestLogic::OnBrdEnd( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	IDevice *pDvc = USERDATA->GetDevice();
	static u32 dwReadyCount = 0;
	dwReadyCount++;
	//���а忨�������Ѿ�����
	if ( dwReadyCount == pDvc->GetBrdCount() )
	{
		USERDATA->SetUIState( emUITestPre );
		USERDATA->SetDispState( "�������" );
		dwReadyCount = 0;
	}
	return true;
}

bool CTestLogic::OnUpdateState( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	if ( USERDATA->GetUIMode() != emModeTest )
	{
		return false;
	}
	CHECKMANAGER
	return ICommonOp::SetControlText( USERDATA->GetDispState(), m_pPaintMngr, CTestLogic::strStateDis );
}

bool CTestLogic::OnStartTest( TNotifyUI& msg )
{
	CHECKMANAGER
	m_pCaseList->SelectItem(-1);
	IDevice *pDvc = USERDATA->GetDevice();
	if ( pDvc == NULL ) 
	{
		return false;
	}
	//UI״̬
	USERDATA->SetUIState(emUITesting);
	//ȡ������
	if ( !pDvc->SetTestCase(emTestNext) )
	{
		ICommonOp::ShowNotifyDlg("�豸û�в����");
	}
	return true;
}

bool CTestLogic::OnStopTest( TNotifyUI& msg )
{
	CHECKMANAGER
	bool bRet = ICommonOp::ShowChooseDlg("�Ƿ�ֹͣ��ǰ���� ?");
	if( !bRet )
	{
		return false;
	}
	IDevice *pDvc = USERDATA->GetDevice();
	if ( pDvc == NULL ) 
	{
		return false;
	}
	pDvc->EndTest( false );
	USERDATA->SetDispState("������ֹ"); 
	return true;
}


bool CTestLogic::OnUIStateChange( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	CHECKMANAGER		
	EmUIState emState = USERDATA->GetUIState();
	switch( emState )
	{
	case emUITestPre: 
		{
			OnUIPre();
			break;
		}
	case emUITesting:
		{
			OnUITesting();
			break;
		}
	case emUITestReady:
		{
			OnUIRready();
			break;
		}
	default:
		{
			//����״̬
		}
	}
	return true;
}
void CTestLogic::OnUIPre()
{
	//��ֹȫѡ��ѡ��
	ICommonOp::EnableControl( false, m_pPaintMngr, CTestLogic::strOptSelectAll );
	//���ûָ��������ù�ѡ
	ICommonOp::EnableControl( false, m_pPaintMngr, CTestLogic::strOptRestore );
	//��ԭ�б�״̬ ���ܹ�ѡ
	RestoreList(false);
	//����ѡ���豸
	ICommonOp::EnableControl( true, m_pPaintMngr, CTestLogic::strCbDvcType );
	//����ֹͣ���԰���
	ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strBtnStop );
	//��ʾ��ʼ���԰���
	ICommonOp::EnableControl( false, m_pPaintMngr, CTestLogic::strBtnStart );
	ICommonOp::ShowControl( true, m_pPaintMngr, CTestLogic::strBtnStart );
	//�����������쳣
	ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strLayoutResult );
	//�豸ͼƬΪ��
	ICommonOp::SetControlBkImg( "", m_pPaintMngr, CTestLogic::strDvcPic );
	//���ͼƬ
	ICommonOp::SetControlBkImg( "", m_pPaintMngr, CTestLogic::strCntnrResult );
	//�����л�״̬---��ֹ�л�״̬
	ICommonOp::ShowControl( false, m_pPaintMngr, "BtnSwitch" );
}

void CTestLogic::OnUIRready()
{
	//�����豸��Ϣ
	LoadDvcInfo();
	//��ղ�����״̬����ʾ
	CContainerUI *pContainer = NULL;
	for ( u32 dwIdx = 0; dwIdx < m_pCaseList->GetCount(); dwIdx++ )
	{
		pContainer = (CContainerUI*)m_pCaseList->GetItemAt( dwIdx );
		ICommonOp::SetControlText( "", m_pPaintMngr, CTestLogic::strCaseState, pContainer );
	}
	//����ȫѡ��ѡ��
	ICommonOp::EnableControl( true, m_pPaintMngr, CTestLogic::strOptSelectAll );
	//���ûָ��������ù�ѡ
	ICommonOp::EnableControl( true, m_pPaintMngr, CTestLogic::strOptRestore );
	//��ʼ���԰�������
	ICommonOp::EnableControl( true, m_pPaintMngr, CTestLogic::strBtnStart );
	RestoreList(true);			//�ָ��б�,�ɱ༭
	//ȡ���б�ѡ����
	m_pCaseList->SelectItem(-1);
	USERDATA->SetDispState("�豸׼�����������Կ�ʼ����");
}

void CTestLogic::OnUITesting()
{
	//��ʼ��ֹͣ���԰���
	ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strBtnStart );
	ICommonOp::ShowControl( true, m_pPaintMngr, CTestLogic::strBtnStop );
	//��ԭ�ܲ������б� ���ܹ�ѡ
	RestoreList(false);
	//��ֹȫѡ��ѡ��
	ICommonOp::EnableControl( false, m_pPaintMngr, CTestLogic::strOptSelectAll );
	//��ֹ�ָ��������ù�ѡ�� 14/7/4 ����֮ǰ���߼���ȷ���Ƿ��ύ
	//ICommonOp::EnableControl( false, m_pPaintMngr, CTestLogic::strOptRestore );
	//��ֹ�豸ѡ���
	ICommonOp::EnableControl( false, m_pPaintMngr, CTestLogic::strCbDvcType );
	//��ֹ�л�״̬
	ICommonOp::ShowControl( false, m_pPaintMngr, "BtnSwitch" );
}

void CTestLogic::RestoreList( bool bSelectable /*= true*/)
{
	if ( m_pCaseList == NULL )
	{
		return;
	}
	CControlUI *pControl = NULL;
	//��ԭ��ʾ
	for( u32 dwIdx = 0; dwIdx < m_pCaseList->GetCount(); dwIdx++ )
	{
		pControl = m_pCaseList->GetItemAt(dwIdx);
		//�߶Ȼ�ԭ
		pControl->SetFixedHeight( dwItemHeight );
		//�������ð���
		ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strBtnConfig, pControl );
		//������Ϣ��������
		ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strLayoutInfo, pControl );
		//�Ƿ���Թ�ѡ
		ICommonOp::EnableControl( bSelectable, m_pPaintMngr, CTestLogic::strOptAdded, pControl );
	}
}
bool CTestLogic::OnCaseStateChange( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	CHECKMANAGER
	TCaseStateMsg *pMsg = (TCaseStateMsg*)wParam;
	CListContainerElementUI *pContainer = (CListContainerElementUI*)GetCaseContainer( pMsg->strCaseName );
	if( pContainer != NULL )
	{
		//������״̬
		CLabelUI *pStateLabel = (CLabelUI*)ICommonOp::FindControl( m_pPaintMngr, CTestLogic::strCaseState, pContainer );
		pStateLabel->SetVisible(true);
		switch( pMsg->emState )
		{
		case emNotReady:
			{
				//...
				break;
			}
		case emReady:
			{
				//...
				break;
			}
		case emPassed:
			{
				pStateLabel->SetText("����");
				pStateLabel->SetTextColor( COLOR_GREEN );
				break;
			}
		case emNotPassed:
			{
				pStateLabel->SetText("�쳣");
				pStateLabel->SetTextColor( COLOR_RED );
				break;
			}
		case emTesting:
			{
				pContainer->Select( true );
				pStateLabel->SetText("���ڲ���...");
				pStateLabel->SetTextColor( COLOR_BLUE );
				ICommonOp::SetControlBkImg( "skinres/testing.bmp", m_pPaintMngr, CTestLogic::strCntnrResult );
				ExpandCase( pMsg->strCaseName, false );  //��һ��չ������				
				//��ʾ�������쳣����
				Control *pCtrl = ICommonOp::FindControl( m_pPaintMngr, CTestLogic::strLayoutResult );
				pCtrl->SetFocus();
				ICommonOp::ShowControl( true, m_pPaintMngr, CTestLogic::strLayoutResult );				
				break;
			}
		case emReceived:
			{
				pContainer->Select( true );
				pStateLabel->SetText("ͨ��");
				pStateLabel->SetTextColor( COLOR_GREEN );
				ExpandCase( pMsg->strCaseName, false );  
				break;
			}
		case emCmdTesting:
			{
				pContainer->Select( true );
				pStateLabel->SetText("���ڲ���...");
				pStateLabel->SetTextColor( COLOR_BLUE );
				ICommonOp::SetControlBkImg( "skinres/testing.bmp", m_pPaintMngr, CTestLogic::strCntnrResult );
				ExpandCase( pMsg->strCaseName, false );		
				break;
			}
		case emAbort:
			{				
				pStateLabel->SetText("�����ж�");
				pStateLabel->SetTextColor( COLOR_RED );
				break;
			}
		default:
			break;
		}
	}
	delete pMsg;
	return true;
}

CControlUI* CTestLogic::GetCaseContainer( const String &strName )
{
	CControlUI *pControl = NULL;
	if ( m_pCaseList == NULL )
	{
		return NULL;
	}
	if( m_pCaseList->GetCount() == 0 )
	{
		return NULL;
	}
	for ( u32 dwIdx = 0; dwIdx < m_pCaseList->GetCount(); dwIdx++ )
	{
		pControl = m_pCaseList->GetItemAt( dwIdx );
		if ( pControl != NULL )
		{
			//��ǰ������������
			String strIdxName = ICommonOp::GetControlText( m_pPaintMngr, CTestLogic::strCaseName, pControl );
			if(strcmp( strIdxName.c_str(), strName.c_str() ) == 0 ) 
			{
				return pControl;
			}
		}
	}
	return NULL;
}


bool CTestLogic::OnNormal( TNotifyUI& msg )
{
	CHECKMANAGER
	//�����ʾ
	ICommonOp::SetControlBkImg( "skin/pass.bmp", m_pPaintMngr, CTestLogic::strCntnrResult );
	IDevice *pDvc = USERDATA->GetDevice();
	ITestCase *pTestCase = NULL;
	if ( pDvc != NULL)
	{
		pTestCase = pDvc->GetCurTestCase();
	}
	if ( pTestCase == 0 )
	{
		LOGEVENT("��ȡ��ǰ������ʧ��");
		return false;
	}
	//ͨ��
	pTestCase->SetState( emPassed );
	LOGEVENT("������%s-----ͨ��\n",pTestCase->GetCaseName().c_str());
	EndCase( pTestCase );				//�ֶ�����

	//��һ��
	if ( !pDvc->SetTestCase( emTestNext ) )
	{
		//û�в�������
	}

	//�����������쳣
	ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strLayoutResult );
	return true;
}

bool CTestLogic::OnAbnormal( TNotifyUI& msg )
{
	//�����ʾ
	CHECKMANAGER
	ICommonOp::SetControlBkImg( "skinres/nopass.bmp", m_pPaintMngr, CTestLogic::strCntnrResult );
	IDevice *pDvc = USERDATA->GetDevice();
	ITestCase *pTestCase = NULL;
	if ( pDvc != NULL)
	{
		pTestCase = pDvc->GetCurTestCase();
	}
	if ( pTestCase == 0 )
	{
		LOGEVENT("��ȡ��ǰ������ʧ��");
		return false;
	}
	//��ͨ��
	pTestCase->SetState( emNotPassed );
	EndCase( pTestCase );				//�ֶ�����
	//�����������쳣
	ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strLayoutResult );	
	//����...
	IWindowManager::GetSingletonPtr()->ShowModal("abnormalwindow");
	return true;
}

bool CTestLogic::OnCaseAdded( TNotifyUI& msg )
{
	CHECKMANAGER
	COptionUI *pOpt = (COptionUI*)msg.pSender;
	IDevice *pDvc = USERDATA->GetDevice();
	if ( pDvc != NULL )
	{
		//�õ���������
		String strName = ICommonOp::GetControlText( m_pPaintMngr, CTestLogic::strCaseName, pOpt->GetParent() );
		ITestCase *pTestCase = ICommonOp::GetTestCase( pDvc, strName );
		if ( pTestCase != NULL )
		{
			pTestCase->SetAdded( pOpt->IsSelected() ); 
			return true;
		}
	}
	return false;
	
}  

bool CTestLogic::OnSelectAll( TNotifyUI& msg )
{
	CHECKMANAGER
	COptionUI *pOptSelectAll = (COptionUI*)msg.pSender;
	if ( m_pCaseList->GetCount() != 0 )
	{
		for( u32 dwIdx = 0; dwIdx < m_pCaseList->GetCount(); dwIdx++ )
		{
			CContainerUI *pContainer = (CContainerUI*)m_pCaseList->GetItemAt( dwIdx );
			ICommonOp::OptionSelect( pOptSelectAll->IsSelected(), m_pPaintMngr, CTestLogic::strOptAdded, pContainer );
			Window *pWnd = IWindowManager::GetSingletonPtr()->GetWindow("superterminal");
			if ( pWnd != NULL )
			{
				if ( ::IsWindowVisible(pWnd->GetHWND()))
				{
					::SetFocus(pWnd->GetHWND());
					CSuperTerminalLogic::pREditDisp->SetFocus();
				}
			}
		}
	}
	return true;
}


bool CTestLogic::OnRestoreChange( TNotifyUI& msg )
{
	CHECKMANAGER
	COptionUI *pOpt = (COptionUI*)msg.pSender;
	USERDATA->SetRestore( pOpt->IsSelected() );
	Window *pWnd = IWindowManager::GetSingletonPtr()->GetWindow("superterminal");
	if ( pWnd != NULL )
	{
		if ( ::IsWindowVisible(pWnd->GetHWND()))
		{
			::SetFocus(pWnd->GetHWND());
			CSuperTerminalLogic::pREditDisp->SetFocus();
		}
	}
	return true;
}

bool CTestLogic::OnCaseConfig( TNotifyUI& msg )
{
	IWindowManager::GetSingletonPtr()->ShowModal( "caseconfigwindow" );
	return true;
}

bool CTestLogic::OnIni( TNotifyUI& msg )
{
	m_pPaintMngr = msg.pSender->GetManager();
	m_pCaseList = (CListUI*)ICommonOp::FindControl( m_pPaintMngr, CTestLogic::strCaseLst );
	return true;
}


void CTestLogic::EndCase( ITestCase *pTestCase )
{
	if ( pTestCase == NULL )
	{
		return;
	}
	if( pTestCase->GetType() ==emMediaCase )
	{
		CMediaTestCase *pCase = (CMediaTestCase*)pTestCase;
		pCase->SetProcedure( emCaseEndPending );   //�ȴ�������Ϣ����
	}

	if ( pTestCase->GetType() ==emCmdCase )
	{
		CCmdTestCase *pCase = (CCmdTestCase*)pTestCase;
		pCase->SetProcedure( emCaseEndPending );
	}
}

bool CTestLogic::OnBrdInfoLoadSuccess( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	//�����豸��Ϣ
	LoadDvcInfo();
	USERDATA->SetDispState( *(String*)wParam + " ��½�ɹ����忨����׼��...");
	LoadCaseList();
	//Bug00184687 ���治����ʱ,����t300,��ֹȫѡ���ָ�����������һ��ȥ����ѡ�޷��ָ���ѡ
	COptionUI *pOptionAllSel = (COptionUI*)ICommonOp::FindControl( m_pPaintMngr, CTestLogic::strOptSelectAll );
	bool bIsAllSel = pOptionAllSel->IsSelected();
	if ( !bIsAllSel )
	{
		ICommonOp::OptionSelect( true, m_pPaintMngr, CTestLogic::strOptSelectAll );
	}
	COptionUI *pOptionRestore = (COptionUI*)ICommonOp::FindControl( m_pPaintMngr, CTestLogic::strOptRestore );
	bool bIsRestore = pOptionRestore->IsSelected();
	if ( !bIsRestore )
	{
		ICommonOp::OptionSelect( true, m_pPaintMngr, CTestLogic::strOptRestore );
	}
	return true;
}

bool CTestLogic::OnCaseLoadFail( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	ICommonOp::ShowNotifyDlg("�忨 "+ *(String*)wParam + "����ʧ�ܣ����������ļ���");//����֪ͨ���������ʧ��...
	return true;
}

bool CTestLogic::OnRestoreSuccess( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
//	USERDATA->SetDispState("�忨 " +*(String*)wParam + " �ָ��������óɹ�");
	USERDATA->SetDispState("�豸���ڻָ���������,����������鿴�ɹ����");
	ICommonOp::ShowNotifyDlg("�豸�ѻָ���������,����������鿴�ָ��ɹ����");
	LOGEVENT("�ѻָ������������\n");
	return true;
}

bool CTestLogic::OnTestAbort( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	USERDATA->SetDispState( "������ֹ" );
	USERDATA->SetUIState( emUITestPre );
	//last 2������ û�������������� ��һ�ť����
	Control *pCtrl = ICommonOp::FindControl( m_pPaintMngr, CTestLogic::strNextTestBtn );
	pCtrl->SetFocus();
	if ( pCtrl->IsVisible() )
	{
		ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strNextTestBtn );	
	}
	return true;
}

bool CTestLogic::OnBrdDisconnect( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	EmUIMode emMode = USERDATA->GetUIMode();
	if ( emMode != emModeTest )
	{
		return false;
	}
	IDevice *pDvc = USERDATA->GetDevice();
	if ( pDvc != NULL )
	{
		//����豸���Ի�û�н���
		if ( !pDvc->IsEnd())
		{
			pDvc->EndTest( false );
			// unknown add 14/7/4
			IWindowManager::GetSingletonPtr()->CloseWindow("notifydialog");
		}
		pDvc->Restore();
	}
	USERDATA->SetUIState( emUITestPre );
	USERDATA->SetDispState( "�豸�Ͽ����ȴ��µ��豸��½" );
	m_pCaseList->SelectItem(-1);
	return true;
}

bool CTestLogic::OnStartRestore( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	USERDATA->SetDispState( "�豸���ڻָ���������,����������鿴�ɹ����" );
	return true;
}

bool CTestLogic::OnUIModeChange( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	if ( USERDATA->GetUIMode() == emModeTest )
	{
		m_pCaseList->RemoveAll();
		USERDATA->SetUIState(emUITestPre);
	}
	return true;
	
}

bool CTestLogic::OnResultChange( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	TCnProduceTestMsg *pMsg = (TCnProduceTestMsg*)wParam;
	CControlUI *pControl = NULL;
	TNotifyUI msg;
	if ( pMsg->m_bProduceTestReult == TRUE )
	{		
//		OnNormal( msg );
		CHECKMANAGER
		//�����ʾ
		ICommonOp::SetControlBkImg( "skin/pass.bmp", m_pPaintMngr, CTestLogic::strCntnrResult );
		IDevice *pDvc = USERDATA->GetDevice();
		ITestCase *pTestCase = NULL;
		if ( pDvc != NULL)
		{
			pTestCase = pDvc->GetCurTestCase();
		}
		if ( pTestCase == 0 )
		{
			LOGEVENT("��ȡ��ǰ������ʧ��");
			return false;
		}
		//ͨ��
		pTestCase->SetState( emPassed );
		LOGEVENT("������%s-----ͨ��\n",pTestCase->GetCaseName().c_str());
	    EndCase( pTestCase );
		//�����������쳣
		ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strLayoutResult );
		//��ʾϵͳ׼��
		Control *pCtrl = ICommonOp::FindControl( m_pPaintMngr, CTestLogic::strSysPrepareBtn );
	    pCtrl->SetFocus();
		ICommonOp::ShowControl( true, m_pPaintMngr, CTestLogic::strSysPrepareBtn );
		return true;
	}
	else
	{
		OnAbnormal( msg );
		return false;
	}
	delete pMsg;
}

bool CTestLogic::OnShowBtn( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	//��ʾ��һ���
	Control *pCtrl = ICommonOp::FindControl( m_pPaintMngr, CTestLogic::strNextTestBtn );
	pCtrl->SetFocus();
	ICommonOp::ShowControl( true, m_pPaintMngr, CTestLogic::strNextTestBtn );	
	return false;	
}

// bool CTestLogic::OnStartBtnEnable( WPARAM wParam, LPARAM lParam, bool& bHandle )
// {
// 	//��ʼ���԰�������
// 	ICommonOp::EnableControl( true, m_pPaintMngr, CTestLogic::strBtnStart );
// 	return false;
// }

bool CTestLogic::OnNextTest( TNotifyUI& msg )
{
	CHECKMANAGER
	// ����ϴ����ڲ�����ʾ 14/7/4
	//ICommonOp::SetControlBkImg( "", m_pPaintMngr, CTestLogic::strCntnrResult );
	IDevice *pDvc = USERDATA->GetDevice();
	ITestCase *pTestCase = NULL;
	if ( pDvc != NULL)
	{
		pTestCase = pDvc->GetCurTestCase();
	}
	if ( pTestCase == 0 )
	{
		LOGEVENT("��ȡ��ǰ������ʧ��");
		return false;
	}
	//ͨ��
	pTestCase->SetState( emReceived );
	LOGEVENT("������%s-----ͨ��\n",pTestCase->GetCaseName().c_str());
	EndCase( pTestCase );				//�ֶ�����
	
	//��һ��
	if ( !pDvc->SetTestCase( emTestNext ) )
	{
		//û�в�������
	}
	
	//������һ�ť
	ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strNextTestBtn );
	return false;
}

bool CTestLogic::OnSysPrepare( TNotifyUI& msg )
{
	IDevice *pDvc = USERDATA->GetDevice();
	//��һ��
	if ( !pDvc->SetTestCase( emTestNext ) )
	{
		//û�в�������
	}
	//����ϵͳ׼����ť
	ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strSysPrepareBtn );
	return false;
}


