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
			LOGEVENT("App �����ɹ�\n");
			return true;
		}
		else
		{
			LOGEVENT("App ����ʧ��\n");
			return false;
		}
	}
	LOGEVENT("App �Ѵ���\n");
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
	//���������ڵ�
	u32 dwNode  = ::OspCreateTcpNode( 0, CNS_PRODUCETEST_LISTION ); // ��SERVRT_PORT�˿��ϴ������
	if ( dwNode == INVALID_NODE )
	{
		LOGEVENT("�����ڵ㴴��ʧ��\n");
		ICommonOp::ShowNotifyDlg(_T("�����ʼ��ʧ�ܣ���ȷ�϶˿�60010δ��ռ��!"));
		return false;
	}
	else
	{
		LOGEVENT("�����ڵ㴴���ɹ�\n");
		return true;
	}
}