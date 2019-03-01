#include "StdAfx.h"
#include "PlayerLogic.h"
BEGIN_MSG_MAP( CPlayerLogic, CNotifyUIImpl )
MSG_INIWINDOW( "VidPlayer", OnInit )
MSG_DBLCLICK("VidPlayer", OnDblClick )
USER_MSG( EV_MAIN_WND_SIZE_CHANGE, OnParentSize )
USER_MSG( EV_MAIN_WND_MOVE, OnParentMove )
END_MSG_MAP()

const String CPlayerLogic::strPlayerWinwow = _T("mediaplayer");

const String CPlayerLogic::strMainWindow = _T("producetest");

const String CPlayerLogic::strDvcPic = _T("CtnrTestDvcPic");

CPlayerLogic::CPlayerLogic() : m_pPaintMngr(NULL)
{
	
}

bool CPlayerLogic::OnParentSize( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	return AjustPlayer();
}

bool CPlayerLogic::OnParentMove( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	return AjustPlayer();
}


bool CPlayerLogic::OnInit( TNotifyUI& msg )
{
	m_pPaintMngr = msg.pSender->GetManager();
	AjustPlayer();
	return true;
	
}

bool CPlayerLogic::AjustPlayer()
{
	Window *pParentWnd = IWindowManager::GetSingletonPtr()->GetWindow(_T("producetest"));
	Window *pPlayerWnd = IWindowManager::GetSingletonPtr()->GetWindow(_T("mediaplayer"));
	if( pParentWnd == NULL || pPlayerWnd == NULL )
	{
		return false;
	}
	RECT rcParentRect;
	RECT rcDvcPic;
	::GetWindowRect( pParentWnd->GetHWND(), &rcParentRect );
	CControlUI *pDvcPic = ICommonOp::FindControl( &(pParentWnd->m_pm), CPlayerLogic::strDvcPic );
	rcDvcPic = pDvcPic->GetPos();
	u32 dwHeight = rcParentRect.bottom - rcParentRect.top - ( WND_TOP_LEN + WND_BOTTOM_LEN );
	u32 dwWidth = rcParentRect.right - rcParentRect.left - ( WND_LEFT_LEN + WND_RIGHT_LEN );
	u32 dwX = rcParentRect.left+ WND_LEFT_LEN;								
	u32 dwY = rcParentRect.top + WND_TOP_LEN;							
	pPlayerWnd->MoveWindow( dwX, dwY, dwWidth, dwHeight );
	return true;
}

bool CPlayerLogic::OnDblClick( TNotifyUI& msg )
{
	Window *pPlayerWnd = IWindowManager::GetSingletonPtr()->GetWindow(_T("mediaplayer"));
	if( pPlayerWnd == NULL )
	{
		return false;
	}
	if ( ::IsZoomed(pPlayerWnd->GetHWND()))
	{
		::ShowWindow( pPlayerWnd->GetHWND(), SW_RESTORE );
	}
	else
	{
		::ShowWindow( pPlayerWnd->GetHWND(), SW_MAXIMIZE );
	}
	return true;	
}




