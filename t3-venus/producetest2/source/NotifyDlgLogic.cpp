#include "StdAfx.h"
#include "NotifyDlgLogic.h"
BEGIN_MSG_MAP( CNotifyDlgLogic, CNotifyUIImpl )
MSG_CLICK( "BtnNotifyOk", OnNotifyOk )
MSG_INIWINDOW( "NotifyDlg", OnDlgIni )
END_MSG_MAP()

const String CNotifyDlgLogic::strLabelNotify = _T("LabelNotify");
const String CNotifyDlgLogic::strBtnNotifyOk = _T("BtnNotifyOk");

bool CNotifyDlgLogic::OnNotifyOk( TNotifyUI& msg )
{
//	String strText = ICommonOp::GetControlText( m_pm, strLabelNotify );	

	IWindowManager::GetSingletonPtr()->CloseWindow("notifydialog");
// 	if ( strText == "为当前测试项搭建测试环境，完成后点确定" )
// 	{
// 		IDevice *pDvc = USERDATA->GetDevice();
// 		if( pDvc != NULL )
// 		{
// 			pDvc->SetTestCase( emTestNext );
// 		}
// 	}
	return true;
}

bool CNotifyDlgLogic::OnDlgIni( TNotifyUI& msg )
{
	String strText = USERDATA->GetNotifyDlgStr();
	ICommonOp::SetControlText( strText, msg.pSender->GetManager(), CNotifyDlgLogic::strLabelNotify );
	return true;
}

CNotifyDlgLogic::CNotifyDlgLogic()
{
}

CNotifyDlgLogic::~CNotifyDlgLogic()
{

}