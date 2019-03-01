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
	//显示状态
	USERDATA->SetDispState(_T("等待设备连接"));
	return true;
	

}

bool CTestLogic::CreateDvc()
{
	String strDvcName = ICommonOp::GetControlText( m_pPaintMngr, CTestLogic::strCbDvcType );
	ICommonOp::EnableControl( false, m_pPaintMngr, CTestLogic::strOptSelectAll );
	ICommonOp::EnableControl( false, m_pPaintMngr, CTestLogic::strOptRestore );
	//创建设备
	if( USERDATA->SetDevice( strDvcName ) )
	{
		//如果创建设备成功 全选、恢复出场设置勾选框
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
	//清空设备信息
	ClearDvcInfo();
	//加载测试项列表
	LoadCaseList();
	return true;
}

bool CTestLogic::LoadCaseList()
{
	if( m_pCaseList == NULL )
	{
		return false;
	}
	//先清空
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
			ICommonOp::ShowNotifyDlg(_T("当前设备打开失败，请检查配置文件"));
		}
		return false;
	}
	//遍历测试项
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
			//测试项名
			ICommonOp::SetControlText( pTestCase->GetCaseName(), m_pPaintMngr, CTestLogic::strCaseName, pListContainer);
			//测试项描述
			ICommonOp::SetControlText( pTestCase->GetCaseDesc(), m_pPaintMngr, CTestLogic::strCaseDesc, pListContainer);
			//添加状态
			ICommonOp::OptionSelect( pTestCase->GetAdded(), m_pPaintMngr, CTestLogic::strOptAdded, pListContainer);
			//测试项状态
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
	//选中容器
	CContainerUI *pCurSel = (CContainerUI*)m_pCaseList->GetItemAt( m_pCaseList->GetCurSel() );
	//测试项名
	String strName = ICommonOp::GetControlText( m_pPaintMngr, strCaseName, pCurSel );
	//设置当前测试项
	bool bRet = USERDATA->SetSelectedCase( strName );
	if ( !bRet )
	{
		LOGEVENT("设置当前选中项失败");
		return false;
	}

	//测试时不做响应
	if ( emState == emUITesting )
	{
		ExpandCase( strName, false );
		return false;
	}

	//展开
	if ( emState == emUITestPre )
	{
		//pre的时候只能展开，不能设置
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
		LOGEVENT("列表没有测试项，设置选中项失败");
		return false;
	}
	//还原列表
	RestoreList(bSet);
	//拿到指定测试项容器
	CControlUI *pSel = GetCaseContainer( strName );
	if ( pSel == NULL )
	{
		return false;
	} 
	IDevice *pDvc = USERDATA->GetDevice();
	if ( pDvc == NULL )
	{
		LOGEVENT("获取设备失败");
		return false;
	}
	ITestCase *pTestCase = ICommonOp::GetTestCase( pDvc, strName );
	if (pTestCase == NULL )
	{
		LOGEVENT("获取选中测试项失败");
		return false;
	}
	//只有media测试项才显示设置按键
	if ( pTestCase->GetType() == emMediaCase && bSet )
	{
		ICommonOp::ShowControl( /*true*/false, m_pPaintMngr, CTestLogic::strBtnConfig, pSel );
	}
	//显示信息描述布局
	ICommonOp::ShowControl( true, m_pPaintMngr, CTestLogic::strLayoutInfo, pSel );
	//变高
	pSel->SetFixedHeight( dwItemSlectedHeight );
	return true;
}

bool CTestLogic::OnBrdReady( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	CHECKMANAGER
	IDevice *pDvc = USERDATA->GetDevice();
	if ( pDvc == NULL )
	{
		LOGEVENT("设备无效\n");
		return false;
	}
	static u32 dwReadyCount = 0;
	dwReadyCount++;
	//所有板卡都准备就绪
	if ( dwReadyCount == pDvc->GetBrdCount() )
	{
		LOGEVENT("板卡准备就绪\n");
		USERDATA->SetUIState( emUITestReady );
		dwReadyCount = 0;
	}
	return true;
}

bool CTestLogic::LoadDvcInfo()
{
	IDevice *pDvc = USERDATA->GetDevice();
	//设备名
	IBoard *pBoard = pDvc->GetBoard( 0 );
	if ( pBoard != NULL )
	{
		//设备类型
		ICommonOp::SetControlText( pBoard->GetBrdDesc(), m_pPaintMngr, CTestLogic::strLabelDvcType );
		//图片
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

	//设备类型
	ICommonOp::SetControlText( "", m_pPaintMngr, CTestLogic::strLabelDvcType );
	//图片
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
	//所有板卡都测试已经结束
	if ( dwReadyCount == pDvc->GetBrdCount() )
	{
		USERDATA->SetUIState( emUITestPre );
		USERDATA->SetDispState( "测试完成" );
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
	//UI状态
	USERDATA->SetUIState(emUITesting);
	//取测试项
	if ( !pDvc->SetTestCase(emTestNext) )
	{
		ICommonOp::ShowNotifyDlg("设备没有测试项！");
	}
	return true;
}

bool CTestLogic::OnStopTest( TNotifyUI& msg )
{
	CHECKMANAGER
	bool bRet = ICommonOp::ShowChooseDlg("是否停止当前测试 ?");
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
	USERDATA->SetDispState("测试终止"); 
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
			//其他状态
		}
	}
	return true;
}
void CTestLogic::OnUIPre()
{
	//禁止全选勾选框
	ICommonOp::EnableControl( false, m_pPaintMngr, CTestLogic::strOptSelectAll );
	//启用恢复出厂设置勾选
	ICommonOp::EnableControl( false, m_pPaintMngr, CTestLogic::strOptRestore );
	//还原列表状态 不能勾选
	RestoreList(false);
	//可以选择设备
	ICommonOp::EnableControl( true, m_pPaintMngr, CTestLogic::strCbDvcType );
	//隐藏停止测试按键
	ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strBtnStop );
	//显示开始测试按键
	ICommonOp::EnableControl( false, m_pPaintMngr, CTestLogic::strBtnStart );
	ICommonOp::ShowControl( true, m_pPaintMngr, CTestLogic::strBtnStart );
	//隐藏正常、异常
	ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strLayoutResult );
	//设备图片为空
	ICommonOp::SetControlBkImg( "", m_pPaintMngr, CTestLogic::strDvcPic );
	//结果图片
	ICommonOp::SetControlBkImg( "", m_pPaintMngr, CTestLogic::strCntnrResult );
	//可以切换状态---禁止切换状态
	ICommonOp::ShowControl( false, m_pPaintMngr, "BtnSwitch" );
}

void CTestLogic::OnUIRready()
{
	//加载设备信息
	LoadDvcInfo();
	//清空测试项状态的显示
	CContainerUI *pContainer = NULL;
	for ( u32 dwIdx = 0; dwIdx < m_pCaseList->GetCount(); dwIdx++ )
	{
		pContainer = (CContainerUI*)m_pCaseList->GetItemAt( dwIdx );
		ICommonOp::SetControlText( "", m_pPaintMngr, CTestLogic::strCaseState, pContainer );
	}
	//启用全选勾选框
	ICommonOp::EnableControl( true, m_pPaintMngr, CTestLogic::strOptSelectAll );
	//启用恢复出场设置勾选
	ICommonOp::EnableControl( true, m_pPaintMngr, CTestLogic::strOptRestore );
	//开始测试按键亮起
	ICommonOp::EnableControl( true, m_pPaintMngr, CTestLogic::strBtnStart );
	RestoreList(true);			//恢复列表,可编辑
	//取消列表选中项
	m_pCaseList->SelectItem(-1);
	USERDATA->SetDispState("设备准备就绪，可以开始测试");
}

void CTestLogic::OnUITesting()
{
	//开始、停止测试按键
	ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strBtnStart );
	ICommonOp::ShowControl( true, m_pPaintMngr, CTestLogic::strBtnStop );
	//还原能测试项列表 不能勾选
	RestoreList(false);
	//禁止全选勾选框
	ICommonOp::EnableControl( false, m_pPaintMngr, CTestLogic::strOptSelectAll );
	//禁止恢复出厂设置勾选框 14/7/4 试下之前的逻辑再确定是否提交
	//ICommonOp::EnableControl( false, m_pPaintMngr, CTestLogic::strOptRestore );
	//禁止设备选择框
	ICommonOp::EnableControl( false, m_pPaintMngr, CTestLogic::strCbDvcType );
	//禁止切换状态
	ICommonOp::ShowControl( false, m_pPaintMngr, "BtnSwitch" );
}

void CTestLogic::RestoreList( bool bSelectable /*= true*/)
{
	if ( m_pCaseList == NULL )
	{
		return;
	}
	CControlUI *pControl = NULL;
	//还原显示
	for( u32 dwIdx = 0; dwIdx < m_pCaseList->GetCount(); dwIdx++ )
	{
		pControl = m_pCaseList->GetItemAt(dwIdx);
		//高度还原
		pControl->SetFixedHeight( dwItemHeight );
		//隐藏设置按键
		ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strBtnConfig, pControl );
		//隐藏信息描述布局
		ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strLayoutInfo, pControl );
		//是否可以勾选
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
		//测试项状态
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
				pStateLabel->SetText("正常");
				pStateLabel->SetTextColor( COLOR_GREEN );
				break;
			}
		case emNotPassed:
			{
				pStateLabel->SetText("异常");
				pStateLabel->SetTextColor( COLOR_RED );
				break;
			}
		case emTesting:
			{
				pContainer->Select( true );
				pStateLabel->SetText("正在测试...");
				pStateLabel->SetTextColor( COLOR_BLUE );
				ICommonOp::SetControlBkImg( "skinres/testing.bmp", m_pPaintMngr, CTestLogic::strCntnrResult );
				ExpandCase( pMsg->strCaseName, false );  //第一个展不开？				
				//显示正常、异常按键
				Control *pCtrl = ICommonOp::FindControl( m_pPaintMngr, CTestLogic::strLayoutResult );
				pCtrl->SetFocus();
				ICommonOp::ShowControl( true, m_pPaintMngr, CTestLogic::strLayoutResult );				
				break;
			}
		case emReceived:
			{
				pContainer->Select( true );
				pStateLabel->SetText("通过");
				pStateLabel->SetTextColor( COLOR_GREEN );
				ExpandCase( pMsg->strCaseName, false );  
				break;
			}
		case emCmdTesting:
			{
				pContainer->Select( true );
				pStateLabel->SetText("正在测试...");
				pStateLabel->SetTextColor( COLOR_BLUE );
				ICommonOp::SetControlBkImg( "skinres/testing.bmp", m_pPaintMngr, CTestLogic::strCntnrResult );
				ExpandCase( pMsg->strCaseName, false );		
				break;
			}
		case emAbort:
			{				
				pStateLabel->SetText("测试中断");
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
			//当前索引测试项名
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
	//结果显示
	ICommonOp::SetControlBkImg( "skin/pass.bmp", m_pPaintMngr, CTestLogic::strCntnrResult );
	IDevice *pDvc = USERDATA->GetDevice();
	ITestCase *pTestCase = NULL;
	if ( pDvc != NULL)
	{
		pTestCase = pDvc->GetCurTestCase();
	}
	if ( pTestCase == 0 )
	{
		LOGEVENT("获取当前测试项失败");
		return false;
	}
	//通过
	pTestCase->SetState( emPassed );
	LOGEVENT("测试项%s-----通过\n",pTestCase->GetCaseName().c_str());
	EndCase( pTestCase );				//手动结束

	//下一项
	if ( !pDvc->SetTestCase( emTestNext ) )
	{
		//没有测试项了
	}

	//隐藏正常、异常
	ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strLayoutResult );
	return true;
}

bool CTestLogic::OnAbnormal( TNotifyUI& msg )
{
	//结果显示
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
		LOGEVENT("获取当前测试项失败");
		return false;
	}
	//不通过
	pTestCase->SetState( emNotPassed );
	EndCase( pTestCase );				//手动结束
	//隐藏正常、异常
	ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strLayoutResult );	
	//弹框...
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
		//拿到测试项名
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
		pCase->SetProcedure( emCaseEndPending );   //等待结束消息队列
	}

	if ( pTestCase->GetType() ==emCmdCase )
	{
		CCmdTestCase *pCase = (CCmdTestCase*)pTestCase;
		pCase->SetProcedure( emCaseEndPending );
	}
}

bool CTestLogic::OnBrdInfoLoadSuccess( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	//加载设备信息
	LoadDvcInfo();
	USERDATA->SetDispState( *(String*)wParam + " 登陆成功，板卡正在准备...");
	LoadCaseList();
	//Bug00184687 界面不重启时,重启t300,防止全选跟恢复出厂设置上一次去除勾选无法恢复勾选
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
	ICommonOp::ShowNotifyDlg("板卡 "+ *(String*)wParam + "加载失败！请检查配置文件。");//弹框通知测试项加载失败...
	return true;
}

bool CTestLogic::OnRestoreSuccess( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
//	USERDATA->SetDispState("板卡 " +*(String*)wParam + " 恢复出厂设置成功");
	USERDATA->SetDispState("设备正在恢复出厂设置,请输入命令查看成功与否");
	ICommonOp::ShowNotifyDlg("设备已恢复出厂设置,请输入命令查看恢复成功与否");
	LOGEVENT("已恢复出厂设置完毕\n");
	return true;
}

bool CTestLogic::OnTestAbort( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	USERDATA->SetDispState( "测试中止" );
	USERDATA->SetUIState( emUITestPre );
	//last 2测试项 没完整测完重启后 下一项按钮隐藏
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
		//如果设备测试还没有结束
		if ( !pDvc->IsEnd())
		{
			pDvc->EndTest( false );
			// unknown add 14/7/4
			IWindowManager::GetSingletonPtr()->CloseWindow("notifydialog");
		}
		pDvc->Restore();
	}
	USERDATA->SetUIState( emUITestPre );
	USERDATA->SetDispState( "设备断开，等待新的设备登陆" );
	m_pCaseList->SelectItem(-1);
	return true;
}

bool CTestLogic::OnStartRestore( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	USERDATA->SetDispState( "设备正在恢复出厂设置,请输入命令查看成功与否" );
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
		//结果显示
		ICommonOp::SetControlBkImg( "skin/pass.bmp", m_pPaintMngr, CTestLogic::strCntnrResult );
		IDevice *pDvc = USERDATA->GetDevice();
		ITestCase *pTestCase = NULL;
		if ( pDvc != NULL)
		{
			pTestCase = pDvc->GetCurTestCase();
		}
		if ( pTestCase == 0 )
		{
			LOGEVENT("获取当前测试项失败");
			return false;
		}
		//通过
		pTestCase->SetState( emPassed );
		LOGEVENT("测试项%s-----通过\n",pTestCase->GetCaseName().c_str());
	    EndCase( pTestCase );
		//隐藏正常、异常
		ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strLayoutResult );
		//显示系统准备
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
	//显示下一项按键
	Control *pCtrl = ICommonOp::FindControl( m_pPaintMngr, CTestLogic::strNextTestBtn );
	pCtrl->SetFocus();
	ICommonOp::ShowControl( true, m_pPaintMngr, CTestLogic::strNextTestBtn );	
	return false;	
}

// bool CTestLogic::OnStartBtnEnable( WPARAM wParam, LPARAM lParam, bool& bHandle )
// {
// 	//开始测试按键可用
// 	ICommonOp::EnableControl( true, m_pPaintMngr, CTestLogic::strBtnStart );
// 	return false;
// }

bool CTestLogic::OnNextTest( TNotifyUI& msg )
{
	CHECKMANAGER
	// 清空上次正在测试显示 14/7/4
	//ICommonOp::SetControlBkImg( "", m_pPaintMngr, CTestLogic::strCntnrResult );
	IDevice *pDvc = USERDATA->GetDevice();
	ITestCase *pTestCase = NULL;
	if ( pDvc != NULL)
	{
		pTestCase = pDvc->GetCurTestCase();
	}
	if ( pTestCase == 0 )
	{
		LOGEVENT("获取当前测试项失败");
		return false;
	}
	//通过
	pTestCase->SetState( emReceived );
	LOGEVENT("测试项%s-----通过\n",pTestCase->GetCaseName().c_str());
	EndCase( pTestCase );				//手动结束
	
	//下一项
	if ( !pDvc->SetTestCase( emTestNext ) )
	{
		//没有测试项了
	}
	
	//隐藏下一项按钮
	ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strNextTestBtn );
	return false;
}

bool CTestLogic::OnSysPrepare( TNotifyUI& msg )
{
	IDevice *pDvc = USERDATA->GetDevice();
	//下一项
	if ( !pDvc->SetTestCase( emTestNext ) )
	{
		//没有测试项了
	}
	//隐藏系统准备按钮
	ICommonOp::ShowControl( false, m_pPaintMngr, CTestLogic::strSysPrepareBtn );
	return false;
}


