// UIManager.cpp: implementation of the CWindowManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WindowManager.h"
#include "System.h"
#include "WndObserver.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const String CWindowManager::strIndexName	= _T("index.xml");
const String CWindowManager::strFileTag		= _T("file");
const String CWindowManager::strParentTag	= _T("parent");
const String CWindowManager::strLogicTag	= _T("logic");
CWindowManager::CWindowManager( String strFile ) 
{
	m_strFile = strFile;
	m_strFile += CWindowManager::strIndexName;
	CPaintManagerUI::SetResourcePath( strFile.c_str() );
}

CWindowManager::~CWindowManager()
{

}

bool CWindowManager::ShowWindow( const String& strName )
{
	CAppWindow* pAppWindow = Find( strName );
	if ( pAppWindow != NULL )
	{
		pAppWindow->ShowWindow();
		pAppWindow->CenterWindow();
		return true;
	}
	String strFile = _T("");
	String strParent = _T("");
	//������ȡ�����ļ�(file)
	bool bRet = DOCMNGR->GetDoc( CWindowManager::strIndexName, 
		CWindowManager::strFileTag, strFile, strName );

	if ( bRet == true )
	{	//ȡ�������ļ�(parent)	
		bRet = DOCMNGR->GetDoc( CWindowManager::strIndexName, 
			CWindowManager::strParentTag, strParent, strName );
		
		HWND hParent = NULL;
		DWORD dwStyle = UI_WNDSTYLE_FRAME;
		if ( bRet == true )
		{
			CAppWindow* pParent = Find( strParent );
			if ( pParent == NULL )
			{
				LOGEVENT( "û�и�����,�޷������Ӵ���\n" );
				return false;
			}
			hParent = pParent->GetHWND();
			dwStyle = UI_WNDSTYLE_CHILD;
		}
	
		//��ʾ����
		CAppWindow* pFrame = new CAppWindow( strFile.c_str() );
	
		if( pFrame == NULL ) return false;
	
		//��ӹ۲���
		AddNotifier( pFrame, strName );

		pFrame->Create( hParent, strName.c_str(), UI_WNDSTYLE_FRAME, UI_WNDSTYLE_EX_FRAME );

		pFrame->CenterWindow();
		

		Add( strName, pFrame );

		// ע��۲���
		REG_MSG_OBSERVER_APPWINDOW( pFrame );

		return true;
	}
	return false;
}

bool CWindowManager::HideWindow( const String& strName )
{
	CAppWindow* pWnd = Find( strName );
	if ( pWnd == NULL )
	{
		LOGEVENT( "����δ����\n" );
		return false;
	}
	pWnd->ShowWindow( false );
	return true;
}

bool CWindowManager::AddNotifier( CAppWindow* pWnd, const String& strName )
{
	if ( pWnd == NULL )
	{
		return false;
	}
	String strLogic = _T("");
	//ȡ��logic�ַ���
	bool bRet = DOCMNGR->GetDoc( CWindowManager::strIndexName, 
		CWindowManager::strLogicTag, strLogic, strName );

	if ( bRet == true )
	{
		stringstream ss( strLogic );
		string sub_str;
		//����logic�ַ�������������Ϣ������󣬲���ӵ�notifier
		while( getline( ss, sub_str, '|' ) )         
		{
			ILogic* pLogic = ILogicManager::GetSingletonPtr()->Create( sub_str );
			if ( pLogic != 0 )
			{
				pWnd->AddNotifier( pLogic );
			}
		}
	}
	return true;
}

bool CWindowManager::ShowModal( const String& strName )
{

	if( ShowWindow( strName ) )
	{
		CAppWindow *pWnd = Find(strName);
		if ( pWnd != NULL )
		{
			pWnd->ShowModal();
			return true;
		}
	}

	return false;
}

bool CWindowManager::CloseWindow( const String& strName )
{
	CAppWindow* pWnd = Find( strName );
	if ( pWnd )
	{
		pWnd->Close();
		Remove( strName );
	}
	return true;
}

Window* CWindowManager::GetWindow( const String& strName )
{
	return Find( strName );
}

Control* CWindowManager::GetControl( const String& strWindow, const String& strControl )
{
	Window* pWnd = Find( strControl );
	if ( pWnd != 0 )
	{
		return pWnd->m_pm.FindControl( strControl.c_str() );
	}
	return 0;
}

bool CWindowManager::ShowChild( const String& strName )
{
	CAppWindow* pAppWindow = Find( strName );
	if ( pAppWindow != NULL )
	{
		pAppWindow->ShowWindow();
		return true;
	}
	String strFile = _T("");
	String strParent = _T("");
	//������ȡ�����ļ�(file)
	bool bRet = DOCMNGR->GetDoc( CWindowManager::strIndexName, 
		CWindowManager::strFileTag, strFile, strName );
	
	if ( bRet == true )
	{	//ȡ�������ļ�(parent)	
		bRet = DOCMNGR->GetDoc( CWindowManager::strIndexName, 
			CWindowManager::strParentTag, strParent, strName );
		
		HWND hParent = NULL;
		DWORD dwStyle = UI_WNDSTYLE_CHILD;
		if ( bRet == true )
		{
			CAppWindow* pParent = Find( strParent );
			if ( pParent == NULL )
			{
				LOGEVENT( "û�и�����,�޷������Ӵ���\n" );
				return false;
			}
			hParent = pParent->GetHWND();
		}
		
		//��ʾ����
		CAppWindow* pFrame = new CAppWindow( strFile.c_str() );
		
		if( pFrame == NULL ) return false;
		
		//��ӹ۲���
		AddNotifier( pFrame, strName );
		
		pFrame->Create( hParent, strName.c_str(), dwStyle, UI_WNDSTYLE_EX_DIALOG);
		
		Add( strName, pFrame );
		
		// ע��۲���
		REG_MSG_OBSERVER_APPWINDOW( pFrame );
		
		return true;
	}
	return false;
	
}