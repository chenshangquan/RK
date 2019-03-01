// System.cpp: implementation of the CSystem class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "System.h"
#include "DocManager.h"
#include "MsgManager.h"
#include "MacroMngr.h"
#include "WindowManager.h"
#include "UserDataManager.h"
#include "LogicManager.h"
#include "Logger.h"
#include "DeviceFactory.h"
#include "BoardFactory.h"
#include "TestCaseFactory.h"
#include "MsgQueFactory.h"
#include "ControlFactory.h"
#include "OspAppManager.h"
#include "OspSessionMngr.h"
#include "LoadInfoMngr.h"
#include "UdpSession.h"
#include "LoadInfoMngr.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
template<> CSystem* Singleton<CSystem>::ms_pSingleton  = 0;
const String CSystem::strMainWindow		= _T("producetest");
const String CSystem::strSkin			= _T("skin");
CSystem::CSystem( String strFile ) : m_strFile( strFile )
{
	bool bRet = IniSystem();
}

CSystem::~CSystem()
{
	if( ::IsOspInitd() )
	{
		OspQuit();
	}
}

bool CSystem::IniSystem()
{
	//初始化Osp
	bool bRet;
	if( !::IsOspInitd() )                
	{
	#ifdef _DEBUG 
		bRet = ::OspInit( TRUE );
	#else
		bRet = ::OspInit(FALSE);
	#endif
	}
	// 初始化xml文本管理器
	if ( IDocManager::GetSingletonPtr() == 0 ) new CDocMngr();

	// 初始化消息管理器
	if ( IMsgManager::GetSingletonPtr() == 0 ) new CMsgManager();

	// 初始化用户数据管理器
	if ( IUserDataMngr::GetSingletonPtr() == 0 ) new CUserDataMngr();

	// 逻辑管理器
	if ( ILogicManager::GetSingletonPtr() == 0 ) new CLogicManager();

	// 打印信息类
	if ( ILogger::GetSingletonPtr() == 0 ) new CLogger();

	//设备工厂
	if( IDeviceFactory::GetSingletonPtr() == 0) new CDeviceFactory();

	//板卡工厂
	if( IBoardFactory::GetSingletonPtr() == 0) new CBoardFactory();

	//测试项工厂
	if( ITestCaseFactory::GetSingletonPtr() == 0) new CTestCaseFactory();

	//消息队列工厂
	if( IMsgQueFactory::GetSingletonPtr() == 0) new CMsgQueFactory();

	//宏管理器
	if( IMacroMngr::GetSingletonPtr() == 0 )  new CMacroMngr();

	//控件工厂
	if ( IControlFactory::GetSingletonPtr() == 0 ) new CControlFactory();

	//OspApp管理器
	if ( IOspAppManager::GetSingletonPtr() == 0 ) new COspAppManager();

	//OspSession管理器
	if ( IOspSessionMngr::GetSingletonPtr() == 0 ) new COspSessionMngr();

	//加载信息管理器
	if ( ILoadInfoMngr::GetSingletonPtr() == 0 ) new CLoadInfoMngr();

	//编解码器模块
//	if ( ICodeTaskMngr::GetSingletonPtr() == 0 ) new CCodeTaskMngr();


	
	// 初始化窗口管理器
	if ( IWindowManager::GetSingletonPtr() == 0 )
	{
		String strValue = _T("");
		bool bRet = DOCMNGR->GetDoc( m_strFile, strSkin, strValue );
		new CWindowManager( strValue );
		assert( IWindowManager::GetSingletonPtr() );
	}


	//注册宏
	ICommonOp::RegMacros();
	//注册观察者
	ICommonOp::RegObservers();
	return true;
}

bool CSystem::Launch()
{

	bool bRet;
	bRet = IWindowManager::GetSingletonPtr()->ShowWindow( CSystem::strMainWindow );

	if ( bRet == true )
	{
		//Udp会话
	    new CUdpSession();
		CPaintManagerUI::MessageLoop();
		CTftpOp::Close();
	}
	else
	{
		LOGEVENT( "创建主程序窗口失败\n" );
	}
	
	return false;
}