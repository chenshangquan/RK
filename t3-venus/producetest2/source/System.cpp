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
	//��ʼ��Osp
	bool bRet;
	if( !::IsOspInitd() )                
	{
	#ifdef _DEBUG 
		bRet = ::OspInit( TRUE );
	#else
		bRet = ::OspInit(FALSE);
	#endif
	}
	// ��ʼ��xml�ı�������
	if ( IDocManager::GetSingletonPtr() == 0 ) new CDocMngr();

	// ��ʼ����Ϣ������
	if ( IMsgManager::GetSingletonPtr() == 0 ) new CMsgManager();

	// ��ʼ���û����ݹ�����
	if ( IUserDataMngr::GetSingletonPtr() == 0 ) new CUserDataMngr();

	// �߼�������
	if ( ILogicManager::GetSingletonPtr() == 0 ) new CLogicManager();

	// ��ӡ��Ϣ��
	if ( ILogger::GetSingletonPtr() == 0 ) new CLogger();

	//�豸����
	if( IDeviceFactory::GetSingletonPtr() == 0) new CDeviceFactory();

	//�忨����
	if( IBoardFactory::GetSingletonPtr() == 0) new CBoardFactory();

	//�������
	if( ITestCaseFactory::GetSingletonPtr() == 0) new CTestCaseFactory();

	//��Ϣ���й���
	if( IMsgQueFactory::GetSingletonPtr() == 0) new CMsgQueFactory();

	//�������
	if( IMacroMngr::GetSingletonPtr() == 0 )  new CMacroMngr();

	//�ؼ�����
	if ( IControlFactory::GetSingletonPtr() == 0 ) new CControlFactory();

	//OspApp������
	if ( IOspAppManager::GetSingletonPtr() == 0 ) new COspAppManager();

	//OspSession������
	if ( IOspSessionMngr::GetSingletonPtr() == 0 ) new COspSessionMngr();

	//������Ϣ������
	if ( ILoadInfoMngr::GetSingletonPtr() == 0 ) new CLoadInfoMngr();

	//�������ģ��
//	if ( ICodeTaskMngr::GetSingletonPtr() == 0 ) new CCodeTaskMngr();


	
	// ��ʼ�����ڹ�����
	if ( IWindowManager::GetSingletonPtr() == 0 )
	{
		String strValue = _T("");
		bool bRet = DOCMNGR->GetDoc( m_strFile, strSkin, strValue );
		new CWindowManager( strValue );
		assert( IWindowManager::GetSingletonPtr() );
	}


	//ע���
	ICommonOp::RegMacros();
	//ע��۲���
	ICommonOp::RegObservers();
	return true;
}

bool CSystem::Launch()
{

	bool bRet;
	bRet = IWindowManager::GetSingletonPtr()->ShowWindow( CSystem::strMainWindow );

	if ( bRet == true )
	{
		//Udp�Ự
	    new CUdpSession();
		CPaintManagerUI::MessageLoop();
		CTftpOp::Close();
	}
	else
	{
		LOGEVENT( "���������򴰿�ʧ��\n" );
	}
	
	return false;
}