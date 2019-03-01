#include "stdafx.h"
#include "DeviceFactory.h"
#include "Device.h"
const String CDeviceFactory::strCfgFile		= _T("testcfg.xml");
const String CDeviceFactory::strDvcPath		= _T("Device/");
const s8 CDeviceFactory::chSeparater		= '|';


CDeviceFactory::CDeviceFactory()
{

}

CDeviceFactory::~CDeviceFactory()
{

}

IDevice* CDeviceFactory::CreateDevice( const String &strName )
{
	IDevice *pDevice = Find( strName );
	if( pDevice == NULL )
	{
		pDevice = new CDevice();
		pDevice->SetName( strName );
		//创建板卡
		String strValue;
		if( !DOCMNGR->GetDoc( CDeviceFactory::strCfgFile, "board", strValue, CDeviceFactory::strDvcPath + strName) )
			return NULL;
		stringstream strBrdName( strValue ); 
		String strSingleBrd;
		while( getline( strBrdName, strSingleBrd, CDeviceFactory::chSeparater ) )					     	//创建板卡
		{
			IBoard *pBoard = IBoardFactory::GetSingletonPtr()->CreateBoard( strSingleBrd );
			if( pBoard != NULL )
			{
				LOGEVENT( "板卡%s创建成功\n",pBoard->GetBrdName().c_str() );
				pDevice->AddBoard( pBoard );			
			}
			else
			{
				LOGEVENT( "板卡创建失败\n" );
				return NULL;
			}
		}
		Add( strName, pDevice );
	}
	pDevice = pDevice->Clone();
	//给返回的设备绑定网络模块
	if( USERDATA->GetUIMode() == emModeTest )
	{
		if ( !BindNetModule( pDevice ) )
		{
			LOGEVENT("设备网络模块创建失败\n");
			return NULL;
		}
	}

	return pDevice;
}


bool CDeviceFactory::BindNetModule( IDevice* pDevice )
{
	IBoard *pBoard = NULL;
	u32 dwIdx = 0;
	while( pBoard = pDevice->GetBoard(dwIdx) )
	{
		bool bRet = IOspAppManager::GetSingletonPtr()->CreateApp( pBoard->GetAppId(), pBoard->GetBrdName().c_str() );
		if ( !bRet)
		{
			return false;
		}
		IOspSession *pSession = IOspSessionMngr::GetSingletonPtr()->CreateSession( pBoard->GetAppId() );
		if ( pSession != NULL )
		{
			LOGEVENT( "Session 创建成功\n" );
			pSession->AddOb( pBoard );
		}
		else
		{
			LOGEVENT("Session 创建失败\n");
			return false;
		}
		dwIdx++;
	}
	return true;
}







