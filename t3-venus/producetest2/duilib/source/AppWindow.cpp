// AppWindow.cpp: implementation of the CAppWindow class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AppWindow.h"


namespace DuiLib {

	LPCTSTR CAppWindow::GetWindowClassName() const 
	{ 
		return _T("CAppWindow"); 
	}

	UINT CAppWindow::GetClassStyle() const 
	{ 
		return CS_DBLCLKS; 
	}

	void CAppWindow::OnFinalMessage(HWND /*hWnd*/) 
	{ 
		delete this; 
	}

	void CAppWindow::Init()
	{

	}

	void CAppWindow::Prepare() 
	{

	}

	void CAppWindow::Close()
	{
		CWindowWnd::Close();
	}
	
	void CAppWindow::Notify(TNotifyUI& msg)	
	{
		
	}
	
	LRESULT CAppWindow::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		LONG styleValue = ::GetWindowLong(*this, GWL_STYLE);
		styleValue &= ~WS_CAPTION;
		::SetWindowLong(*this, GWL_STYLE, styleValue | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);

		m_pm.Init(m_hWnd);
		CDialogBuilder builder;

		CControlUI* pRoot = builder.Create( (LPCTSTR)m_strSkin, 0,  0, &m_pm);
		ASSERT(pRoot && "Failed to parse XML");
		m_pm.AttachDialog(pRoot);
		m_pm.AddNotifier(this);
		Init();
		return 0;
	}

	LRESULT CAppWindow::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{		
		bHandled = FALSE;
		return 0;
	}

	LRESULT CAppWindow::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		m_pm.SendNotify( m_pm.GetRoot(), NOTIFY_DESTROY, 0, 0 );
		bHandled = FALSE;
		return 0;
	}

	LRESULT CAppWindow::OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
        if( ::IsIconic(*this) ) bHandled = FALSE;
        return (wParam == 0) ? TRUE : FALSE;
	}

	LRESULT CAppWindow::OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		return 0;
	}
	
	LRESULT CAppWindow::OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		return 0;
	}

	LRESULT CAppWindow::OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		POINT pt; pt.x = GET_X_LPARAM(lParam); pt.y = GET_Y_LPARAM(lParam);
		::ScreenToClient(*this, &pt);

		RECT rcClient;
		::GetClientRect(*this, &rcClient);
        
		// 改变大小
		if( !::IsZoomed(*this) ) {
			RECT rcSizeBox = m_pm.GetSizeBox();
			if( pt.y < rcClient.top + rcSizeBox.top ) {
				if( pt.x < rcClient.left + rcSizeBox.left ) return HTTOPLEFT;
				if( pt.x > rcClient.right - rcSizeBox.right ) return HTTOPRIGHT;
				return HTTOP;
			}
			else if( pt.y > rcClient.bottom - rcSizeBox.bottom ) {
				if( pt.x < rcClient.left + rcSizeBox.left ) return HTBOTTOMLEFT;
				if( pt.x > rcClient.right - rcSizeBox.right ) return HTBOTTOMRIGHT;
				return HTBOTTOM;
			}
			if( pt.x < rcClient.left + rcSizeBox.left ) return HTLEFT;
			if( pt.x > rcClient.right - rcSizeBox.right ) return HTRIGHT;
		}

		// 标题栏响应
		RECT rcCaption = m_pm.GetCaptionRect();
		if( pt.x >= rcClient.left + rcCaption.left && pt.x < rcClient.right - rcCaption.right \
			&& pt.y >= rcCaption.top && pt.y < rcCaption.bottom ) {
				CControlUI* pControl = static_cast<CControlUI*>(m_pm.FindControl(pt));
				if( pControl && _tcscmp(pControl->GetClass(), _T("ButtonUI")) != 0 && 
					_tcscmp(pControl->GetClass(), _T("OptionUI")) != 0 &&
					_tcscmp(pControl->GetClass(), _T("TextUI")) != 0 )
					return HTCAPTION;
		}

		return HTCLIENT;
	}

	LRESULT CAppWindow::OnMove(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		if ( IsWindowVisible( m_hWnd ) )
		{
			m_pm.SendNotify( m_pm.GetRoot(), NOTIFY_MOVE, wParam, lParam );
		}
		return 0;
	}
	LRESULT CAppWindow::OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
        SIZE szRoundCorner = m_pm.GetRoundCorner();
        if( !::IsIconic(*this) && (szRoundCorner.cx != 0 || szRoundCorner.cy != 0) ) {
            CDirectRect rcWnd;
            ::GetWindowRect(*this, &rcWnd);
            rcWnd.Offset(-rcWnd.left, -rcWnd.top);
            rcWnd.right++; rcWnd.bottom++;
            HRGN hRgn = ::CreateRoundRectRgn(rcWnd.left, rcWnd.top, rcWnd.right, rcWnd.bottom, szRoundCorner.cx, szRoundCorner.cy);
            ::SetWindowRgn(*this, hRgn, TRUE);
            ::DeleteObject(hRgn);
        }
		if ( IsWindowVisible( m_hWnd ) )
		{
			m_pm.SendNotify( m_pm.GetRoot(), NOTIFY_SIZE, wParam, lParam );
		}
        bHandled = FALSE;
        return 0;
	}

	LRESULT CAppWindow::OnGetMinMaxInfo(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		if ( IsWindowVisible( m_hWnd ) )
		{
			m_pm.SendNotify( m_pm.GetRoot(), NOTIFY_MINMIAXINFO, 0, 0 );
		}
		bHandled = FALSE;
		return 0;
	}

	LRESULT CAppWindow::OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		LRESULT lRes = CWindowWnd::HandleMessage(uMsg, wParam, lParam);
		return lRes;
	}

	LRESULT CAppWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;
		BOOL bHandled = TRUE;
		switch( uMsg ) {
		case WM_CREATE:        lRes = OnCreate(uMsg, wParam, lParam, bHandled); break;
		case WM_CLOSE:         lRes = OnClose(uMsg, wParam, lParam, bHandled); break;
		case WM_DESTROY:       lRes = OnDestroy(uMsg, wParam, lParam, bHandled); break;
		case WM_NCACTIVATE:    lRes = OnNcActivate(uMsg, wParam, lParam, bHandled); break;
		case WM_NCCALCSIZE:    lRes = OnNcCalcSize(uMsg, wParam, lParam, bHandled); break;
		case WM_NCPAINT:       lRes = OnNcPaint(uMsg, wParam, lParam, bHandled); break;
		case WM_NCHITTEST:     lRes = OnNcHitTest(uMsg, wParam, lParam, bHandled); break;
		case WM_MOVE:          lRes = OnMove(uMsg, wParam, lParam, bHandled); break;
		case WM_SIZE:          lRes = OnSize(uMsg, wParam, lParam, bHandled); break;
		case WM_GETMINMAXINFO: lRes = OnGetMinMaxInfo(uMsg, wParam, lParam, bHandled); break;
		case WM_SYSCOMMAND:    lRes = OnSysCommand(uMsg, wParam, lParam, bHandled); break;
		default:
		bHandled = FALSE;
		}
		if( bHandled ) return lRes;
		if( m_pm.MessageHandler(uMsg, wParam, lParam, lRes) ) return lRes;
		return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
	}

	bool CAppWindow::AddNotifier( CNotifyUIImpl* pNotifier )
	{
		pNotifier->SetPaintManagerUI( &m_pm );
		m_pm.AddNotifier( pNotifier );
		return m_pm.AddMessageFilter( pNotifier );
	}

	void CAppWindow::MoveWindow( int x, int y, int nWidth, int nHeight, bool bRepaint )
	{
		::MoveWindow( m_hWnd, x, y, nWidth, nHeight, bRepaint );
	}
	
	const MSGMAP CNotifyUIImpl::messageMap =
	{
		0,
		&CNotifyUIImpl::_messageEntries[0]
	};
		
	const MSGMAP_ENTRY CNotifyUIImpl::_messageEntries[] =
	{
		{ 0,"", "", 0, 0 }     // nothing here
	};

	const MSGMAP* CNotifyUIImpl::GetMessageMap() const
	{
		return 0;
	};

	void CNotifyUIImpl::Notify(TNotifyUI& msg)
	{
		const MSGMAP* pMap = GetMessageMap();
		if ( pMap != 0 )
		{
			Invoke( pMap, msg );
		}
	}

	LRESULT CNotifyUIImpl::MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled)
	{
		const MSGMAP* pMap = GetMessageMap();
		if ( pMap != 0 )
		{
			Invoke( pMap, uMsg, wParam, lParam, bHandled );
		}
		return 0;
	}

	void CNotifyUIImpl::Invoke( const MSGMAP* pMsg, UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled )
	{
		MSGMAP_ENTRY* pBegin = const_cast<MSGMAP_ENTRY*>(pMsg->lpEntries);
		while ( pBegin->m_pfn != 0 )
		{
			// 消息查找、目前不支持继承消息，若要支持，需要建立一个hash表
			if ( uMsg == pBegin->m_dwEvent )
			{
				union MessageMapFuncs mmf;
				mmf.pfn = pBegin->m_pfn;
				
				switch ( pBegin->m_wSig )
				{
				case emFunc_bn:				
					(this->*mmf.pfn_uwlb)( wParam, lParam, bHandled );	
					break;
				default:
					break;
				}
				break;
			}
			pBegin++;
		}
		
	}

	void CNotifyUIImpl::Invoke( const MSGMAP* pMsg, TNotifyUI& msg )
	{
		if ( msg.pSender == 0 )
		{
			return;
		}
		MSGMAP_ENTRY* pBegin = const_cast<MSGMAP_ENTRY*>(pMsg->lpEntries);
		while ( pBegin->m_pfn != 0 )
		{
			// 消息查找、目前不支持继承消息，若要支持，需要建立一个hash表
			if ( msg.pSender->GetName() == pBegin->m_chControl && msg.sType == pBegin->m_chEvent )
			{
				union MessageMapFuncs mmf;
				mmf.pfn = pBegin->m_pfn;

				switch ( pBegin->m_wSig )
				{
				case emFunc_bn:				
					(this->*mmf.pfn_bn)(msg);	
					break;
				case emFunc_vv:
					(this->*mmf.pfn)();
					break;
				}
				break;
			}
			pBegin++;
		}
		
	}
}
