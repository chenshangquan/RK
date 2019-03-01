#include "StdAfx.h"
#include "CComm.h"
#include "SuperTerminalLogic.h"

BEGIN_MSG_MAP( CSuperTerminalLogic, CNotifyUIImpl )
MSG_INIWINDOW( "PageST", OnInit )
MSG_CLICK( "BtnShowST", OnBtnShowSt )
MSG_CLICK( "REditST", OnReditClick )
MSG_ITEMSELECTD( "CbComPort", OnPortSelected )
MSG_CHAR("REditST", OnInput )
MSG_KEYUP("REditST", OnSpecialKey )
//MSG_KILLFOCUS("REditST",OnKillFocus)
USER_MSG( EV_COM_UPDATE, UpdateComDisp )
USER_MSG( EV_MAIN_WND_SIZE_CHANGE, OnParentSize )
USER_MSG( EV_MAIN_WND_MOVE, OnParentMove )
USER_MSG( EV_COMM_PORT_AVAILABLE, OnCommAvailable )
USER_MSG( WM_KILLFOCUS, OnKillFocus)
END_MSG_MAP()
#define MAX_NAME_LEN 25				//串口名最大长度
#define READ_BUF_LEN 512			//串口读取缓冲区长度
//一些键值
#define CTRL_V	22
#define CTRLED 0x80
#define CTRL_C 0x03
#define CTRL_A 0x01
#define CTRL_S 18
#define CTRL_R 19



const String CSuperTerminalLogic::strBtnShowST = _T("BtnShowST");
const String CSuperTerminalLogic::strPageST	= _T("PageST");
const String CSuperTerminalLogic::strCbComPort = _T("CbComPort");
const String CSuperTerminalLogic::strComboItem	 = _T("ComboItem");
const String CSuperTerminalLogic::strREditST	 = _T("REditST");
const String CSuperTerminalLogic::strStWindow = _T("mediaplayer");
const String CSuperTerminalLogic::strMainWindow = _T("producetest");
const String CSuperTerminalLogic::strDvcPic = _T("CtnrTestDvcPic");

CComm* CSuperTerminalLogic::s_pCom	 = NULL;
bool CSuperTerminalLogic::s_PrintFlag = false;
CRichEditUI* CSuperTerminalLogic::pREditDisp	 = NULL;

CSuperTerminalLogic::CSuperTerminalLogic():m_pCombo(NULL),m_pPaintMngr(NULL),m_bInit(false),m_bExpand(true)
{

}

CSuperTerminalLogic::~CSuperTerminalLogic()
{
	
}

bool CSuperTerminalLogic::OnBtnShowSt( TNotifyUI& msg )
{
	CControlUI *pCtrl = ICommonOp::FindControl( msg.pSender->GetManager(), strPageST);
	Window *pWnd = IWindowManager::GetSingletonPtr()->GetWindow("superterminal");
	if ( pWnd == NULL )
	{
		return false;
	}
	RECT rcWnd = { 0 };
	::GetWindowRect(pWnd->GetHWND(), &rcWnd);
	CControlUI *pBtn = ICommonOp::FindControl( msg.pSender->GetManager(), strBtnShowST );
	if ( pBtn->GetText() == _T("↖") )
	{

		m_bExpand = false;
		pBtn->SetText(_T("↘"));
	}
	else
	{
		m_bExpand = true;
		pBtn->SetText(_T("↖"));		
	}
	AjustPos();
	return true;
	
}

bool CSuperTerminalLogic::OnInit( TNotifyUI& msg )
{
	AjustPos();
// 	{
// 		超级终端待优化
//  		HANDLE hTread = CreateThread (NULL, 0, ComDispThr, (PVOID)&s_PrintFlag, 0, 0);  
//  		CloseHandle(hTread);
// 	}
	m_pPaintMngr = msg.pSender->GetManager();
	pREditDisp = (CRichEditUI*)ICommonOp::FindControl( m_pPaintMngr, strREditST );
	//枚举串口
	m_pCombo = (CComboUI*)ICommonOp::FindControl( m_pPaintMngr, strCbComPort );
	GetAllComPort( m_pCombo );
	m_bInit = true;
	return true;
}

bool CSuperTerminalLogic::GetAllComPort( CComboUI *pCombo )
{
	if ( pCombo == NULL)
	{
		return false;
	}
	CListLabelElementUI *pItem = (CListLabelElementUI*)IControlFactory::GetSingletonPtr()\
		->GetControl( strComboItem );
	pItem->SetText( _T("选择") );
	pCombo->Add(pItem);		
	HKEY hKey;
	LPCTSTR data_Set=_T("HARDWARE\\DEVICEMAP\\SERIALCOMM\\");
	u32 dwRet = (::RegOpenKeyEx(HKEY_LOCAL_MACHINE, data_Set, 0, KEY_READ, &hKey));
	if( dwRet != ERROR_SUCCESS )
	{
		return false;
	}
	s8 achName[MAX_NAME_LEN] = {0};
	u8 abyPortName[MAX_NAME_LEN] = {0};
	s32  Status = 0;
	u32 dwIndex = 0;
	DWORD dwName = sizeof(achName);
	DWORD dwSizeofPortName;
	DWORD Type;
	dwName = sizeof(achName);
	dwSizeofPortName = sizeof(abyPortName);
	while(true)
	{
		ZeroMemory( abyPortName, sizeof(abyPortName) );
		ZeroMemory( achName, sizeof(achName) );
		dwName = sizeof(achName);
		dwSizeofPortName = sizeof(abyPortName);
		//读取注册表
		//参数 1:注册表键句柄 2.索引 3.名称 4.名称长度 5.未用 6.类型代码 7.数据 8.数据长度
		Status = RegEnumValue(hKey, dwIndex, achName, &dwName, NULL, &Type,
			abyPortName, &dwSizeofPortName );
		if((Status == ERROR_SUCCESS)||(Status == ERROR_MORE_DATA))	
		{
			CListLabelElementUI *pItem = (CListLabelElementUI*)IControlFactory::GetSingletonPtr()\
				->GetControl( strComboItem );
			s8 achPortName[MAX_NAME_LEN] = {0};
			memcpy( achPortName, abyPortName, MAX_NAME_LEN );
			pItem->SetText( achPortName );
			pCombo->Add(pItem);		
		}
		else
		{
			break;
		}
		dwIndex++;
	} 
	RegCloseKey(hKey);
	pCombo->SelectItem(0);
	return true;
}

bool CSuperTerminalLogic::UpdateComDisp( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	LPCSTR pDisp = USERDATA->GetComDispStr();
	try
	{
		pREditDisp->SetText(pDisp);
		pREditDisp->ScrollCaret();
	}
	catch (...)
	{
		LOGEVENT("SuperTerminal Expection, ignored.\n");
		
	}
	return true;
}

void CALLBACK CSuperTerminalLogic::CbReadCallback()
{
	Window *pWnd = IWindowManager::GetSingletonPtr()->GetWindow("superterminal");
	//异步，防止卡界面
	if ( pWnd != NULL )
	{
		::PostMessage( pWnd->GetHWND(), EV_COMM_PORT_AVAILABLE, NULL, NULL);
	}
	//s_PrintFlag = true;
}

bool CSuperTerminalLogic::OnPortSelected( TNotifyUI& msg )
{
	//先关掉上次的
	if (s_pCom != NULL)
	{
		USERDATA->ClearComDisp();
		s_pCom->CloseComm();
		delete s_pCom;
		s_pCom = NULL;
	}	
	s_pCom = new CComm( CbReadCallback );
	String strComName = m_pCombo->GetText().GetData();
	if( strComName == _T("选择") )
	{
		return false;
	}
	if( s_pCom->OpenComm(strComName.c_str()) )
	{
		
		USERDATA->AppendComDisp(_T("打开串口成功\r"));
		s_pCom->SetCommParam();
		s_pCom->WriteComm( "\n", 1 );
		pREditDisp->SetFocus();
	}
	else
	{
		USERDATA->AppendComDisp(_T("打开串口失败\r"));
		LOGEVENT("CreateProcess failed (%d).\n", GetLastError());
	}
	return true;
}

bool CSuperTerminalLogic::OnInput( TNotifyUI& msg )
{
	s8 chInput = (s8)msg.wParam;
//	LOGEVENT("[CSuperTerminalLogic::OnInput]s_pCom:%d,%c\n", s_pCom, chInput );
	if ( chInput == CTRL_V || chInput == CTRL_A || chInput ==CTRL_S || chInput == CTRL_R )
	{
		return false;
	}
	if ( s_pCom != NULL )
	{
		s_pCom->WriteComm( &chInput, 1 );
	}
	return true;
	
}

bool CSuperTerminalLogic::OnSpecialKey( TNotifyUI& msg )
{
	//BACKSPACE
	if ( msg.wParam == VK_BACK )
	{
		s8 chInput = (s8)msg.wParam;
		if ( s_pCom != NULL )
		{
			s_pCom->WriteComm( &chInput, 1 );
		}
	}
	//ctrl + c
	u16 wCtrled = GetKeyState(VK_CONTROL);
	if ( msg.wParam == 'C' && (wCtrled &  CTRLED) )
	{
 		s8 chInput = CTRL_C;
 		if ( s_pCom != NULL )
 		{
 			s_pCom->WriteComm( &chInput, 1 );
 		}
   	}
	//ctrl + v
	if ( msg.wParam == 'V' && (wCtrled &  CTRLED) )
	{
		Paste();
	}
	//ctrl + a
	if ( msg.wParam == 'A' && (wCtrled &  CTRLED) )
	{
		SelectAll();
	}
	//ctrl + s
	if ( msg.wParam == 'S' && (wCtrled &  CTRLED) )
	{
		String strCmd = "bootupdate ";
		IDevice *pDvc = USERDATA->GetDevice();
		if ( pDvc != NULL )
		{
			strCmd += pDvc->GetBoard(0)->GetBrdName();
		}
		else 
		{
			return true;
		}
		strCmd += "manuboot.bin\n";
		s_pCom->WriteComm( (char *const )strCmd.c_str(), strCmd.length() );
	}
	//ctrl + r
	if ( msg.wParam == 'R' && (wCtrled &  CTRLED) )
	{
		String strCmd = "reboot\n";
		s_pCom->WriteComm( (char *const )strCmd.c_str(), strCmd.length() );
	}
	return true;
}

void CSuperTerminalLogic::Paste()
{
	Window *pWnd = IWindowManager::GetSingletonPtr()->GetWindow("producetest");
	::OpenClipboard(pWnd->GetHWND());
	HANDLE hClip = GetClipboardData(CF_TEXT);
	LPSTR pBuf = NULL;
	pBuf = (LPSTR)GlobalLock(hClip);
	GlobalUnlock(pBuf);
	if ( pBuf != NULL )
	{
		s_pCom->WriteComm(pBuf,strlen(pBuf));
	}
	::CloseClipboard();
	
}

void CSuperTerminalLogic::SelectAll()
{
	pREditDisp->SetSelAll();
}

bool CSuperTerminalLogic::OnParentSize( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	AjustPos();
	return true;
}

bool CSuperTerminalLogic::OnParentMove( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	AjustPos();
	return true;
}

bool CSuperTerminalLogic::AjustPos()
{

	Window *pParentWnd = IWindowManager::GetSingletonPtr()->GetWindow(_T("producetest"));
	Window *pSt = IWindowManager::GetSingletonPtr()->GetWindow(_T("superterminal"));
	if( pParentWnd == NULL || pSt == NULL )
	{
		return false;
	}
	RECT rcParentRect;
	RECT rcDvcPic;
	::GetWindowRect( pParentWnd->GetHWND(), &rcParentRect );
	CControlUI *pDvcPic = ICommonOp::FindControl( &(pParentWnd->m_pm), CSuperTerminalLogic::strDvcPic );
	rcDvcPic = pDvcPic->GetPos();
	u32 dwHeight;
	u32 dwWidth;
	if ( m_bExpand )
	{
		dwHeight = rcParentRect.bottom - rcParentRect.top - ( WND_TOP_LEN + WND_BOTTOM_LEN );
		dwWidth = rcParentRect.right - rcParentRect.left - ( WND_LEFT_LEN + WND_RIGHT_LEN );
	}
	else
	{
		dwWidth = 20;
		dwHeight = 20;
	}

	u32 dwX = WND_LEFT_LEN;								
	u32 dwY = WND_TOP_LEN;							
	pSt->MoveWindow( dwX, dwY, dwWidth, dwHeight );
	//播放模式不能挡住播放器
	Window *pWnd = IWindowManager::GetSingletonPtr()->GetWindow("superterminal");
	if ( pWnd != NULL )
	{
		if ( ::IsWindowVisible(pWnd->GetHWND()))
		{
			::SetFocus(pWnd->GetHWND());
		}
	}
	return true;
}

bool CSuperTerminalLogic::OnCommAvailable( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	s8 achReadbuffer[READ_BUF_LEN];
	memset(achReadbuffer, 0, READ_BUF_LEN);
	u32 dwReadCout = s_pCom->ReadComm(achReadbuffer, READ_BUF_LEN);   //读
	if ( dwReadCout != 0 )
	{
		USERDATA->AppendComDisp(achReadbuffer);
	}
	else
	{
		
	}
	return true;
}

bool CSuperTerminalLogic::OnReditClick( TNotifyUI& msg )
{
//	pREditDisp->SetFocus();
	Window *pWnd = IWindowManager::GetSingletonPtr()->GetWindow("superterminal");
	if ( pWnd != NULL )
	{
		if ( ::IsWindowVisible(pWnd->GetHWND()))
		{			
			::SetFocus(pWnd->GetHWND());
			pREditDisp->SetFocus();
//			LOGEVENT("已进入该函数\n");
		}
	}
	return true;
}

//控件自身的killfocus消息响应不到，因为超级终端跟主界面是两个窗口
// bool CSuperTerminalLogic::OnKillFocus( TNotifyUI& msg )
// {
// 	LOGEVENT("超级终端窗口已失去焦点 \n");
// 	return true;
// }

bool CSuperTerminalLogic::OnKillFocus( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
//	LOGEVENT("超级终端窗口已失去焦点 \n");

	//失去焦点时，将焦点转移至combo上

	CComboUI *pCombo = (CComboUI*)ICommonOp::FindControl( m_pPaintMngr, strCbComPort );

	if ( pCombo != NULL )
	{
		pCombo->SetFocus();
	}

	return true;
}
