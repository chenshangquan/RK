#include "StdAfx.h"
#include "ChooseDlgLogic.h"
BEGIN_MSG_MAP( CChooseDlgLogic, CNotifyUIImpl )
MSG_CLICK( "BtnOk", OnBtnOk )
MSG_CLICK( "BtnCancel", OnBtnCancel )
END_MSG_MAP()
const String CChooseDlgLogic::strLabelDesc = _T("LabelDescription");

bool CChooseDlgLogic::OnDlgIni( TNotifyUI& msg )
{
	String strText = USERDATA->GetNotifyDlgStr();
	ICommonOp::SetControlText( strText, msg.pSender->GetManager(), CChooseDlgLogic::strLabelDesc );
	return true;
	
}

bool CChooseDlgLogic::OnBtnOk( TNotifyUI& msg )
{
	USERDATA->SetChooseDlgResult(true);
	IWindowManager::GetSingletonPtr()->CloseWindow("choosedialog");
	return true;
}

bool CChooseDlgLogic::OnBtnCancel( TNotifyUI& msg )
{
	USERDATA->SetChooseDlgResult(false);
	IWindowManager::GetSingletonPtr()->CloseWindow("choosedialog");	
	return true;
}


