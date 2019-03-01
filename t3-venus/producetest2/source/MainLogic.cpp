// MainLogic.cpp: implementation of the CMainLogic class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainLogic.h"
#include "TestLogic.h"
#include "LoadLogic.h"
#include "SuperTerminalLogic.h"
#include "Tftp.h"
#include <afxwin.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


BEGIN_MSG_MAP( CMainLogic, CNotifyUIImpl )
	MSG_CLICK( "BtnClose", OnBtnClose )
	MSG_CLICK( "BtnMin", OnBtnMin )
	MSG_CLICK( "BtnMax", OnBtnMax )
	MSG_CLICK( "BtnSwitch", OnBtnSwitch )
	MSG_CLICK( "BtnRestore", OnBtnRestore )
	MSG_SIZE( "MainFrame", OnSize )
	MSG_MOVE( "MainFrame", OnMove )
	MSG_DESTORY( "MainFrame", OnDestory )
	MSG_INIWINDOW( "MainFrame", OnMainIni )
	USER_MSG( EV_USER_UI_MODE_CHANGE, OnUIModeChange )
END_MSG_MAP()

const String CMainLogic::strCfgFile		  =	_T("testcfg.xml");
const String CMainLogic::strDvcTag		  =	_T("Device");
const String CMainLogic::strCbDvcType	  = _T("CbDvcType");		//测试状态的下拉框
const String CMainLogic::strCbLoadDvc	  = _T("CbLoadDvc");		//加载状态的下拉框
const String CMainLogic::strComboItem	  = _T("ComboItem");
const String CMainLogic::strLoadPage	  = _T("PageLoadMode");
const String CMainLogic::strTestPage	  = _T("PageTestMode");
const String CMainLogic::strNormalPage	  = _T("PageNormalMode");
const String CMainLogic::strSuperTerminal = _T("SuperTerminal");
const String CMainLogic::strLabelComboItem = _T("LabelComboItem");
const String CMainLogic::strBtnRestore	   = _T("BtnRestore");
const String CMainLogic::strBtnMax         = _T("BtnMax");
const String CMainLogic::strBtnSwitch      = _T("BtnSwitch");
const String CMainLogic::strBoradTag	   = _T("board");	
const String CMainLogic::strTestTag		   = _T("test");
const String CMainLogic::strLoadTag		   = _T("load");


CMainLogic::CMainLogic() : m_pPaintMngr(NULL)
{

}

CMainLogic::~CMainLogic()
{

}

bool CMainLogic::OnBtnClose( TNotifyUI& msg )
{
	IWindowManager::GetSingletonPtr()->CloseWindow("producetest");
	return true;
}

bool CMainLogic::OnBtnMin( TNotifyUI& msg )
{
	Window *pWnd = IWindowManager::GetSingletonPtr()->GetWindow("producetest");
	::ShowWindow( pWnd->GetHWND(), SW_MINIMIZE );	
	return true;
}

bool CMainLogic::OnBtnMax( TNotifyUI& msg )
{
	Window *pWnd = IWindowManager::GetSingletonPtr()->GetWindow("producetest");
	::ShowWindow( pWnd->GetHWND(), SW_MAXIMIZE );
	return true;
}


bool CMainLogic::OnBtnRestore( TNotifyUI& msg )
{
	Window *pWnd = IWindowManager::GetSingletonPtr()->GetWindow("producetest");
	::ShowWindow( pWnd->GetHWND(), SW_RESTORE );
	return true;
}


bool CMainLogic::OnMainIni( TNotifyUI& msg )
{
	m_pPaintMngr = msg.pSender->GetManager();
	AjustMaxWnd();
	return true;
}


bool CMainLogic::OnUIModeChange( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	switch ( USERDATA->GetUIMode() )
	{
	case emModeTest:
		InitTestPage();
		break;
	case emModeLoad:
		InitLoadPage();
		break;
	case emModeNormal:
		ICommonOp::ShowControl( true, m_pPaintMngr, CMainLogic::strNormalPage );
		ICommonOp::ShowControl( false, m_pPaintMngr, CMainLogic::strLoadPage );
		ICommonOp::ShowControl( false, m_pPaintMngr, CMainLogic::strTestPage );
		break;
	default:
		break;
	}
	return true;
}

bool CMainLogic::InitTestPage()
{
	//根据模式加载页面
	ICommonOp::ShowControl( false, m_pPaintMngr, CMainLogic::strNormalPage );
	ICommonOp::ShowControl( true, m_pPaintMngr, CMainLogic::strTestPage );
	ICommonOp::ShowControl( false, m_pPaintMngr, CMainLogic::strLoadPage );
	//遍历设备列表
	CComboUI *pCombo = (CComboUI*)m_pPaintMngr->FindControl( CMainLogic::strCbDvcType.c_str() );
	CListLabelElementUI *pItem = NULL;
	pCombo->RemoveAll();
	DocNode Node = DOCMNGR->GetNode( CMainLogic::strCfgFile, CMainLogic::strDvcTag );
	Node = Node.GetChild();
	while( Node.IsValid() )
	{
		String strNeedTest = Node.GetAttributeValue( CMainLogic::strTestTag.c_str() );
		if( strNeedTest == "false")
		{
			Node = Node.GetSibling();
			continue;
		}
		pItem = (CListLabelElementUI*)IControlFactory::GetSingletonPtr()->GetControl( CMainLogic::strComboItem );
		pItem->SetText( Node.GetName() );
		pCombo->Add(pItem);		
		Node = Node.GetSibling();
	}

	pCombo->SelectItem(-1);
	USERDATA->SetDevice("");
	USERDATA->SetDispState("");
	InitST(emModeTest);
	return true;
}

bool CMainLogic::InitLoadPage()
{
	ICommonOp::ShowControl( false, m_pPaintMngr, CMainLogic::strNormalPage );
	ICommonOp::ShowControl( true, m_pPaintMngr, CMainLogic::strLoadPage );
	ICommonOp::ShowControl( false, m_pPaintMngr, CMainLogic::strTestPage );
	USERDATA->SetUIState( emUILoadEdit );
	//遍历设备列表
	CComboUI *pCombo = (CComboUI*)m_pPaintMngr->FindControl( CMainLogic::strCbLoadDvc.c_str() );
	CListLabelElementUI *pItem = NULL;
	pCombo->RemoveAll();
	DocNode Node = DOCMNGR->GetNode( CMainLogic::strCfgFile, CMainLogic::strDvcTag );
	Node = Node.GetChild();
	while( Node.IsValid() )
	{
		String strNeedLoad = Node.GetAttributeValue( CMainLogic::strLoadTag.c_str() );
		if( strNeedLoad == "false")
		{
			Node = Node.GetSibling();
			continue;
		}
		pItem = (CListLabelElementUI*)IControlFactory::GetSingletonPtr()->GetControl( CMainLogic::strComboItem );
		pItem->SetText( Node.GetName() );
		pCombo->Add(pItem);
		Node = Node.GetSibling();
	}
	USERDATA->SetDevice("");
	USERDATA->SetDispState("");
	pCombo->SelectItem(-1);
	InitST(emModeLoad);
	return true;	
}

bool CMainLogic::InitST( EmUIMode emMode )
{
	Window *pWnd = IWindowManager::GetSingletonPtr()->GetWindow("superterminal");
	if( pWnd != NULL )
	{
		return false;
	}
    IWindowManager::GetSingletonPtr()->ShowChild("superterminal");
// 	CControlUI *pSuperTerminal = ICommonOp::FindControl( m_pPaintMngr, "PageST" );
// 	if ( pSuperTerminal != NULL )
// 	{
// 		CContainerUI *pParent = (CContainerUI*)pSuperTerminal->GetParent();
// 		pParent->Remove(pSuperTerminal);
// 	}
// 	//超级终端页面
// 	pSuperTerminal = IControlFactory::GetSingletonPtr()->GetControl( CMainLogic::strSuperTerminal, 0, m_pPaintMngr );
// 	CContainerUI *pStContainer = NULL;
// 	if( emMode == emModeTest )
// 	{
// 		pStContainer = (CContainerUI*)ICommonOp::FindControl( m_pPaintMngr, CTestLogic::strDvcPic );
// 	}
// 	else if ( emMode == emModeLoad )
// 	{
// 		pStContainer = (CContainerUI*)ICommonOp::FindControl( m_pPaintMngr, CLoadLogic::strLoadPic );
// 	}
// 	if ( pStContainer != NULL )
// 	{
// 		pStContainer->Add(pSuperTerminal);
// 		NOTIFY( EV_USER_INIT_ST, m_pPaintMngr );
// 	}
// 	else
// 	{
// 		//如果是普通模式
// 	}
	return true;
}

bool CMainLogic::OnSize( TNotifyUI& msg )
{
	CHECKMANAGER
	AjustMaxWnd();
	Window *pWnd = IWindowManager::GetSingletonPtr()->GetWindow("producetest");
	if ( pWnd == NULL )
	{
		return false;
	}
	if ( ::IsZoomed( pWnd->GetHWND()) )
	{
		ICommonOp::ShowControl( true, m_pPaintMngr, CMainLogic::strBtnRestore );
		ICommonOp::ShowControl( false, m_pPaintMngr, CMainLogic::strBtnMax );
	}
	else
	{
		ICommonOp::ShowControl( false, m_pPaintMngr, CMainLogic::strBtnRestore );
		ICommonOp::ShowControl( true, m_pPaintMngr, CMainLogic::strBtnMax );
	}
	NOTIFY(EV_MAIN_WND_SIZE_CHANGE);
	return true;
}

bool CMainLogic::OnMove( TNotifyUI& msg )
{
	NOTIFY(EV_MAIN_WND_MOVE);
	return true;
}

bool CMainLogic::OnDestory( TNotifyUI& msg )
{ 
	CTftpOp::Close();
	PostQuitMessage(0);
	return true;	
}

void CMainLogic::AjustMaxWnd()
{
	CRect rcWorkArea;
	SystemParametersInfo( SPI_GETWORKAREA, 0, &rcWorkArea, 0 );
	m_pPaintMngr->SetMaxInfo(rcWorkArea.right - rcWorkArea.left + 3,rcWorkArea.bottom - rcWorkArea.top + 3);
	Window *pWnd = IWindowManager::GetSingletonPtr()->GetWindow("producetest");
	if ( pWnd == NULL )
	{
		return;
	}
	if ( ::IsZoomed( pWnd->GetHWND()) )
	{
		pWnd->MoveWindow( rcWorkArea.left, rcWorkArea.top, rcWorkArea.right - rcWorkArea.left + 3,rcWorkArea.bottom - rcWorkArea.top + 3 );
	}	
}

bool CMainLogic::OnBtnSwitch( TNotifyUI& msg )
{
	if ( USERDATA->GetUIMode() == emModeLoad )
	{
		USERDATA->SetUIMode( emModeTest );
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
	else if ( USERDATA->GetUIMode() == emModeTest )
	{
		USERDATA->SetUIMode( emModeLoad );
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
	USERDATA->SetDevice("");
	return true;
}










