#include "stdafx.h"
#include "CaseCfgLogic.h"
#include "TestCase.h"
BEGIN_MSG_MAP( CCaseCfgLogic, CNotifyUIImpl )
MSG_INIWINDOW( "CaseCfgDlg", Ini )
MSG_CLICK( "BtnOk", OnOk )
MSG_CLICK( "BtnCancel", OnCancel )
MSG_CLICK( "BtnBrowse", OnBrowseDir )
MSG_TEXTCHANGED( "EditFilePath", OnPathChange )
END_MSG_MAP()
const String CCaseCfgLogic::strEditFilePath = _T( "EditFilePath" );
const String CCaseCfgLogic::strBtnCancel = _T( "BtnCancel" );
CCaseCfgLogic::CCaseCfgLogic()
{

}

CCaseCfgLogic::~CCaseCfgLogic()
{

}

bool CCaseCfgLogic::OnOk( TNotifyUI& msg )
{
	CMediaTestCase *pCase = (CMediaTestCase*)USERDATA->GetSelectedCase();
	if( pCase != NULL )
	{
		String strDir = ICommonOp::GetControlText(msg.pSender->GetManager(), CCaseCfgLogic::strEditFilePath );
		if ( ICommonOp::CheckFileExists(strDir.c_str()) )
		{
			pCase->SetFilePath( strDir.c_str() );
		}
		else
		{
			ICommonOp::SetControlBorderFormat( COLOR_RED, 1, msg.pSender->GetManager(), CCaseCfgLogic::strEditFilePath );
			return false;
		}
	}
	IWindowManager::GetSingletonPtr()->CloseWindow( "caseconfigwindow" );
	return true;
}

bool CCaseCfgLogic::OnCancel( TNotifyUI& msg )
{
	IWindowManager::GetSingletonPtr()->CloseWindow( "caseconfigwindow" );
	return true;
}

bool CCaseCfgLogic::Ini( TNotifyUI& msg )
{
	//获取测试项路径
	CMediaTestCase *pCase = (CMediaTestCase*)USERDATA->GetSelectedCase();
	if( pCase != NULL )
	{
		String strPath = pCase->GetFilePath();
		ICommonOp::SetControlText( strPath, msg.pSender->GetManager(), CCaseCfgLogic::strEditFilePath );
	}
	return true;
}

bool CCaseCfgLogic::OnBrowseDir( TNotifyUI& msg )
{
	String strDir = ICommonOp::GetFolderDir("媒体文件路径");
	if ( strDir != "" )
	{
		ICommonOp::SetControlText(strDir, msg.pSender->GetManager(), CCaseCfgLogic::strEditFilePath );
		return true;
	}
	return false;
}

bool CCaseCfgLogic::OnPathChange( TNotifyUI& msg )
{
	return ICommonOp::SetControlBorderFormat( COLOR_WHITE, 1, msg.pSender->GetManager(), CCaseCfgLogic::strEditFilePath );
}
