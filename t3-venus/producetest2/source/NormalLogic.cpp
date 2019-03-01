#include "stdafx.h"
#include "NormalLogic.h"
BEGIN_MSG_MAP( CNormalLogic, CNotifyUIImpl )
MSG_CLICK( "BtnLoad", OnBtnLoad )
MSG_CLICK( "BtnTest", OnBtnTest )
END_MSG_MAP()


bool CNormalLogic::OnBtnTest( TNotifyUI& msg )
{
	USERDATA->SetUIMode( emModeTest );
	return true;
}


bool CNormalLogic::OnBtnLoad( TNotifyUI& msg )
{
	USERDATA->SetUIMode( emModeLoad );
	return true;
}