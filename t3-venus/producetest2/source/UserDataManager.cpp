// UserDataManager.cpp: implementation of the CUserDataManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UserDataManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CUserDataMngr::CUserDataMngr():m_pDevice( 0 ), m_pSelectedCase( 0 ), m_bRestore(true),
 m_emUIMode( emModeNormal), m_emUIState( (EmUIState)0 ), m_strTftpPath(""), m_strDispState(""), m_dwStartIp(0),
 m_strNotify(""), m_strComDisp(""), m_bChooseDlgResult(false)
{

}

CUserDataMngr::~CUserDataMngr()
{

}

bool CUserDataMngr::Update(TMsgParam& tParam)
{
	return false;
}

void CUserDataMngr::RegFunc()
{
	//Add( 1, &(OnConnectedDevice) );
	//REG_USERDATAMANAGER_FUNC( EV_DVC_LOAD_REQ, CUserDataMngr::OnDeviceLoadReq )
	//REG_USERDATAMANAGER_FUNC( EV_DVC_LOAD_STATE_CHANGE, CUserDataMngr::OnDeviceLoadStateChange)
}

bool CUserDataMngr::OnConnectedDevice( TMsgParam& TMsgParam )
{
	return false;
}

bool CUserDataMngr::GetRestore()  const 
{
	return m_bRestore;
}



u32 CUserDataMngr::GetStartIp() const 
{
	return m_dwStartIp;
}


s8* CUserDataMngr::GetStartMac()  
{
	return m_achStartMac;
}


 
String CUserDataMngr::GetTftpPath()  const 
{
	return m_strTftpPath;
}



EmUIMode CUserDataMngr::GetUIMode()  const 
{
	return m_emUIMode;
}



EmUIState CUserDataMngr::GetUIState()  const 
{
	return m_emUIState;
}



bool CUserDataMngr::SetDevice( const String strDvcName )
{

	if ( m_pDevice != NULL )
	{
		//不用改变
		if( m_pDevice->GetName() == strDvcName )
		{
			LOGEVENT("设备无变化\n");
			LOGEVENT("------------------------------\n");
			return true;
		}
		//删除上一次的
		delete m_pDevice;
		m_pDevice = NULL;
	}
	else
	{
		if ( strDvcName == "" )
		{
			LOGEVENT("当前设备无效\n");
			LOGEVENT("------------------------------\n");
			return true;
		}
	}

	if( strDvcName == "" )
	{
		NOTIFY( EV_USER_DEVICE_CHANGE );
		return true;	
	}

	//创建设备
	m_pDevice = IDeviceFactory::GetSingletonPtr()->CreateDevice( strDvcName );
	if ( m_pDevice != NULL )
	{
		LOGEVENT("设备创建成功\n");
		LOGEVENT("------------------------------\n");
		NOTIFY( EV_USER_DEVICE_CHANGE );
		return true;
	}
	//创建设备失败
	LOGEVENT("设备创建失败\n");
	LOGEVENT("------------------------------\n");
	NOTIFY( EV_USER_DEVICE_CHANGE );
	return false;
}

bool CUserDataMngr::SetDevice( IDevice *pDevice )
{
	//如果是同一个设备，直接返回
	if ( m_pDevice != NULL && pDevice != NULL )
	{
		if( m_pDevice->GetName() == pDevice->GetName() )
		{
			LOGEVENT("设备无变化\n");
			return true;
		}
	}
	//如果不是同一个设备，将当前设备更新
	if( m_pDevice != NULL )
	{
		delete m_pDevice;
		m_pDevice = NULL;
	}

	if ( pDevice == NULL )
	{
		LOGEVENT("设备清空\n");
	}
	else
	{
		m_pDevice = pDevice;
		LOGEVENT("设置当前设备为 %s\n", pDevice->GetName().c_str() );
	}
	NOTIFY( EV_USER_DEVICE_CHANGE );
	return true;
	
}


void CUserDataMngr::SetRestore( const bool bRes )
{
	if(m_bRestore == bRes)
		return;
	m_bRestore = bRes;
}


void CUserDataMngr::SetSartIp( const u32 dwIp )
{
	if (m_dwStartIp == dwIp)
		return;
	m_dwStartIp = dwIp;
	NOTIFY( EV_USER_START_IP_CHANGE );
}



bool CUserDataMngr::SetSelectedCase( const String strCaseName )
{
	ITestCase *pTestCase = ICommonOp::GetTestCase( m_pDevice, strCaseName );
	if ( pTestCase != NULL )
	{
		m_pSelectedCase = pTestCase;
		return true;
	}
	return false;
}




void CUserDataMngr::SetStartMac( const s8 *pchMac )
{
	memcpy(m_achStartMac, pchMac, sizeof(m_achStartMac));
	NOTIFY( EV_USER_START_MAC_CHANGE );
}



void CUserDataMngr::SetTftpPath(String strPath)
{
	if ( !strcmp( strPath.c_str(), m_strTftpPath.c_str()) )
		return;	
	m_strTftpPath = strPath;
	NOTIFY( EV_USER_TFTP_PATH_CHANGE );
}


void CUserDataMngr::SetUIMode(EmUIMode emMode)
{
	if( emMode == m_emUIMode )
		return;
	m_emUIMode = emMode;
	NOTIFY( EV_USER_UI_MODE_CHANGE );
}


void CUserDataMngr::SetUIState(EmUIState emState)
{
	if( emState == m_emUIState )
	{
		return;
	}
	m_emUIState = emState;
	NOTIFY( EV_USER_UI_STATE_CHANGE );
}

IDevice* CUserDataMngr::GetDevice()  const 
{
	return m_pDevice;
}

ITestCase* CUserDataMngr::GetSelectedCase()  const 
{
	return m_pSelectedCase;
}

bool CUserDataMngr::SetDispState( const String strState )
{
	m_strDispState = strState;
	NOTIFY( EV_USER_STATE_STR_UPATE );
	return true;
}

String CUserDataMngr::GetDispState() const
{
	return m_strDispState;
}

String CUserDataMngr::GetNotifyDlgStr() const
{
	String strTmp = m_strNotify;
	//每次取之后就清空这个字符串
	m_strNotify.empty();
	return strTmp;
}

bool CUserDataMngr::SetNotifyDlgStr( const String &strNotify )
{
	m_strNotify = strNotify;
	return true;
}

bool CUserDataMngr::AppendComDisp( LPCSTR pchContent )
{
	String strAppContent = pchContent;
	u32 dwBkSpaceIdx = 0;
	//特殊键值处理
	//BackSpace
	while(true)
	{
		//从前往后找
		dwBkSpaceIdx = strAppContent.find_first_of('\b');
		if (dwBkSpaceIdx == String::npos)
		{
			break;
		}
		if ( dwBkSpaceIdx == 0)
		{
			if ( m_strComDisp.length() >= 1 )
			{
				m_strComDisp.erase(m_strComDisp.length() - 1, 1);
			}
			strAppContent.erase( 0, 1 );
		}
		else
		{
			strAppContent.erase(dwBkSpaceIdx - 1, 2);
		}
		
	}
	//一个无需显示的特殊字符 0x07
	while ( true )
	{
		u32 dwCharIdx = 0;
		dwCharIdx = strAppContent.find( 0x07 );		
		if (dwCharIdx != String::npos)
		{
			strAppContent.erase(dwCharIdx);
		}
		else
		{
			break;
		}
	}
	//换行符
	while ( true )
	{
		u32 dwCharIdx = 0;
		dwCharIdx = strAppContent.find( 0x0d );		
		if (dwCharIdx != String::npos)
		{
			strAppContent.erase(dwCharIdx, 1);
		}
		else
		{
			break;
		}
	}
	m_strComDisp.append(strAppContent);
	//保证最大长度
	if ( m_strComDisp.length() >= MAX_COM_DISP_LEN )
	{
		m_strComDisp.erase( 0, m_strComDisp.length() - MAX_COM_DISP_LEN );
	}
	//定向 时间频繁，用MsgManager效率低，阻塞界面
	Window *pStWnd = IWindowManager::GetSingletonPtr()->GetWindow("superterminal");
	if ( pStWnd != NULL )
	{
		::PostMessage( pStWnd->GetHWND(), EV_COM_UPDATE, NULL, NULL);
	}
	return true;
}

bool CUserDataMngr::ClearComDisp()
{
	m_strComDisp = "";
	NOTIFY(EV_COM_UPDATE);
	return true;
}

LPCSTR CUserDataMngr::GetComDispStr()
{
	return m_strComDisp.c_str();
}

bool CUserDataMngr::GetChooseDlgResult() const
{
	return m_bChooseDlgResult;	
}

bool CUserDataMngr::SetChooseDlgResult( const bool bOk )
{
	m_bChooseDlgResult = bOk;
	return true;
}
