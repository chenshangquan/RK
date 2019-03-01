// WndObserver.h: interface for the CWndObserver class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WNDOBSERVER_H__33732688_7A3B_430B_A809_05A6DE2085DC__INCLUDED_)
#define AFX_WNDOBSERVER_H__33732688_7A3B_430B_A809_05A6DE2085DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/*
	�������͵�Ob����Ϣ�������SendMessage/PostMessage
*/
class CWndObserver : public IObserver
{
public:
	CWndObserver( HWND hWnd ) : m_hWnd(hWnd){}
	virtual ~CWndObserver(){}
	virtual bool Update( TMsgParam& tMsgParma );
protected:
	HWND m_hWnd;
};

/*
	���һ��HWND��Ob
*/
#define REG_MSG_OBSERVER_HWND( hWnd ) \
	IMsgManager::GetSingletonPtr()->AddObserver( new CWndObserver(hWnd) );

/*
	���һ��AppWindow��Ob
*/
#define REG_MSG_OBSERVER_APPWINDOW( pAppWindow ) \
	IMsgManager::GetSingletonPtr()->AddObserver( new CWndObserver( pAppWindow->GetHWND() ) );

#endif // !defined(AFX_WNDOBSERVER_H__33732688_7A3B_430B_A809_05A6DE2085DC__INCLUDED_)
