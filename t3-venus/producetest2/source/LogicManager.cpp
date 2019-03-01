// LogicManager.cpp: implementation of the CLogicManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LogicManager.h"
#include "MainLogic.h"
#include "TestLogic.h"
#include "NormalLogic.h"
#include "AbnormalLogic.h"
#include "CaseCfgLogic.h"
#include "NotifyDlgLogic.h"
#include "LoadLogic.h"
#include "SuperTerminalLogic.h"
#include "PlayerLogic.h"
#include "ChooseDlgLogic.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLogicManager::CLogicManager()
{

}

CLogicManager::~CLogicManager()
{

}

ILogic* CLogicManager::Create( const String& strLogic )
{
	ILogic* pLogic = Find( strLogic );
	if ( pLogic == NULL )
	{
		// 先就这样写死，后面改，如果要添加其他logic，就在下面加else if
		if ( strLogic == "mainlogic" )
		{
			pLogic = new CMainLogic();
		}
		else if ( strLogic == "testlogic")
		{
			pLogic = new CTestLogic();
		}
		else if( strLogic == "abnormallogic")
		{
			pLogic = new CAbnormalLogic();
		}
		else if( strLogic == "casecfglogic")
		{
			pLogic = new CCaseCfgLogic();
		}
		else if( strLogic == "notifydlglogic" )
		{
			pLogic = new CNotifyDlgLogic();
		}
		else if( strLogic == "loadlogic")
		{
			pLogic = new CLoadLogic();
		}
		else if ( strLogic == "normallogic")
		{
			pLogic = new CNormalLogic();
		}
		else if ( strLogic == "superterminallogic")
		{
			pLogic = new CSuperTerminalLogic();
		}
		else if( strLogic == "playerlogic")
		{
			pLogic = new CPlayerLogic();
		}
		else if( strLogic == "choosedlglogic")
		{
			pLogic = new CChooseDlgLogic();
		}
		else if ( strLogic == "superterminallogic")
		{
			pLogic = new CSuperTerminalLogic();
		}
		if ( pLogic != 0 )
		{
			Add( strLogic, pLogic );
		}
	}
	return pLogic;
}
