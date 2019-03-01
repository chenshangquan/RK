#include "StdAfx.h"
#include "OspInstance.h"
#include "OspAppManager.h"

COspAppManager::COspAppManager()
{
	StartOsp();
}

COspAppManager::~COspAppManager()
{

}

bool COspAppManager::CreateApp( u16 wAppId, const s8 *pchAppName )
{
	OspApp *pApp = Find(wAppId);
	if ( pApp == NULL )
	{
		pApp = new OspApp();
		Add( wAppId, pApp );
		u32 dwRet;
		s8 *pName = new s8;
		strcpy( pName, pchAppName );
		dwRet = pApp->CreateApp( pName, wAppId, APP_PRIO );
		if ( dwRet == OSP_OK )
		{
			LOGEVENT("App 创建成功\n");
			return true;
		}
		else
		{
			LOGEVENT("App 创建失败\n");
			return false;
		}
	}
	LOGEVENT("App 已存在\n");
	return true;
}

bool COspAppManager::KillApp( u16 wAppId )
{
	OspApp *pApp = Find( wAppId );
	if ( pApp != NULL )
	{
		pApp->QuitApp();
		delete pApp;
		pApp = NULL;
		Remove( wAppId );
		return true;
	}
	return false;
}

bool COspAppManager::StartOsp()
{
	//创建监听节点
	u32 dwNode  = ::OspCreateTcpNode( 0, CNS_PRODUCETEST_LISTION ); // 在SERVRT_PORT端口上创建结点
	if ( dwNode == INVALID_NODE )
	{
		LOGEVENT("监听节点创建失败\n");
		ICommonOp::ShowNotifyDlg(_T("网络初始化失败，请确认端口60010未被占用!"));
		return false;
	}
	else
	{
		LOGEVENT("监听节点创建成功\n");
		return true;
	}
}