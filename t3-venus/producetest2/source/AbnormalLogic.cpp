#include "stdafx.h"
#include "AbnormalLogic.h"

BEGIN_MSG_MAP( CAbnormalLogic, CNotifyUIImpl )
MSG_INIWINDOW( "AbnormalWindow", OnInit )
MSG_CLICK( "BtnStop", OnStop )
MSG_CLICK( "BtnRetest", OnRetest )
MSG_CLICK( "BtnContinue", OnContinue )
END_MSG_MAP()

CAbnormalLogic::CAbnormalLogic()
{

}

CAbnormalLogic::~CAbnormalLogic()
{

}

bool CAbnormalLogic::OnContinue( TNotifyUI& msg )
{
	IDevice *pDvc = USERDATA->GetDevice();
	if( pDvc != NULL )
	{
		if( !pDvc->SetTestCase( emTestNext ) )
		{
			USERDATA->SetDispState( "²âÊÔÏîÍê³É" );
		}
	}
	IWindowManager::GetSingletonPtr()->CloseWindow( "abnormalwindow" );
	return true;
}

bool CAbnormalLogic::OnStop( TNotifyUI& msg )
{
	IDevice *pDvc = USERDATA->GetDevice();
	if ( pDvc != NULL ) 
	{
		pDvc->EndTest( false );
	}
	USERDATA->SetDispState( "²âÊÔÖÕÖ¹" );
	IWindowManager::GetSingletonPtr()->CloseWindow( "abnormalwindow" );
	return true;
}

bool CAbnormalLogic::OnRetest( TNotifyUI& msg )
{
	IDevice *pDvc = USERDATA->GetDevice();
	if( pDvc != NULL )
	{
		pDvc->SetTestCase( emTestCur );
	}
	IWindowManager::GetSingletonPtr()->CloseWindow("abnormalwindow");
	return true;
}

bool CAbnormalLogic::OnInit( TNotifyUI& msg )
{
	IDevice *pDvc = USERDATA->GetDevice();
	ITestCase *pCurCase = pDvc->GetCurTestCase();
	if( !pCurCase->IsRetestable() )
	{
		ICommonOp::EnableControl( false, msg.pSender->GetManager(), "BtnRetest" );
	}
	return true;
}
