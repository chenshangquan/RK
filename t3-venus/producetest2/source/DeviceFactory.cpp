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
		//�����忨
		String strValue;
		if( !DOCMNGR->GetDoc( CDeviceFactory::strCfgFile, "board", strValue, CDeviceFactory::strDvcPath + strName) )
			return NULL;
		stringstream strBrdName( strValue ); 
		String strSingleBrd;
		while( getline( strBrdName, strSingleBrd, CDeviceFactory::chSeparater ) )					     	//�����忨
		{
			IBoard *pBoard = IBoardFactory::GetSingletonPtr()->CreateBoard( strSingleBrd );
			if( pBoard != NULL )
			{
				LOGEVENT( "�忨%s�����ɹ�\n",pBoard->GetBrdName().c_str() );
				pDevice->AddBoard( pBoard );			
			}
			else
			{
				LOGEVENT( "�忨����ʧ��\n" );
				return NULL;
			}
		}
		Add( strName, pDevice );
	}
	pDevice = pDevice->Clone();
	//�����ص��豸������ģ��
	if( USERDATA->GetUIMode() == emModeTest )
	{
		if ( !BindNetModule( pDevice ) )
		{
			LOGEVENT("�豸����ģ�鴴��ʧ��\n");
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
			LOGEVENT( "Session �����ɹ�\n" );
			pSession->AddOb( pBoard );
		}
		else
		{
			LOGEVENT("Session ����ʧ��\n");
			return false;
		}
		dwIdx++;
	}
	return true;
}







