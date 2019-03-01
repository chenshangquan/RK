#include "stdafx.h"
#include "Tftp.h"
#include "LoadLogic.h"
BEGIN_MSG_MAP( CLoadLogic, CNotifyUIImpl )
	MSG_INIWINDOW( "MainFrame", OnInit )
	MSG_CLICK( "BtnSaveEdit", OnBtnSaveEdit )
	MSG_CLICK( "BtnCancelEdit", OnBtnCancelEdit )
	MSG_CLICK( "BtnChangeEdit", OnBtnChangeEdit )
	MSG_CLICK( "BtnBrowsePath", OnBrowsePath )
	MSG_ITEMSELECTD( "CbLoadDvc", OnDvcSelected )
	MSG_TEXTCHANGED( "EditBrdSerial", OnSerialChange )
//	MSG_KILLFOCUS("REditTftpPath", OnREditLoseFocus)
	USER_MSG( EV_USER_DEVICE_CHANGE, OnDvcChange )
	USER_MSG( EV_LOAD_ERR, OnLoadErr )
	USER_MSG( EV_USER_UI_MODE_CHANGE, OnUIModeChange )
	USER_MSG( EV_USER_UI_STATE_CHANGE, OnUIStateChange )
	USER_MSG( EV_LOAD_STATE_UPDATE, OnLoadStateChange )
	USER_MSG( EV_USER_TFTP_PATH_CHANGE, OnTftpPathChange )
	USER_MSG( EV_USER_STATE_STR_UPATE, OnUpdateState )
	USER_MSG( EV_LOAD_START_REQ, OnStartLoadReq )
END_MSG_MAP()

const String CLoadLogic::strCbLoadDvc = _T( "CbLoadDvc" );
const String CLoadLogic::strREditHw = _T( "REditHw" );
const String CLoadLogic::strREditStartIp = _T( "REditStartIp" );
const String CLoadLogic::strREditStartMac = _T( "REditStartMac" );
const String CLoadLogic::strREditTftpPath = _T( "REditTftpPath" );
const String CLoadLogic::strBtnBrowsePath = _T( "BtnBrowsePath" );
const String CLoadLogic::strBtnSaveEdit = _T( "BtnSaveEdit" );
const String CLoadLogic::strBtnCancelEdit = _T( "BtnCancelEdit" );
const String CLoadLogic::strBtnChangeEdit = _T( "BtnChangeEdit" );
const String CLoadLogic::strLabelPid = _T("LabelPid");
const String CLoadLogic::strLabelHid = _T("LabelHid");
const String CLoadLogic::strEditSn = _T("EditBrdSerial");
const String CLoadLogic::strProgressLoad = _T("ProgressLoad");
const String CLoadLogic::strStateDis = _T("LabelLoadState");
const String CLoadLogic::strLoadIp = _T("LabelLoadIp");
const String CLoadLogic::strLoadMac = _T("LabelLoadMac");
const String CLoadLogic::strLoadDate = _T("LabelLoadDate");
const String CLoadLogic::strLoadPic = _T("CntrLoadDvcPic");
const String CLoadLogic::strLoadResult = _T("LoadResult");




CLoadLogic::CLoadLogic() : m_pPaintMngr(NULL), m_pPreviousDvc(NULL)
{

}

CLoadLogic::~CLoadLogic()
{
	CTftpOp::KillTftpProcess();
}

bool CLoadLogic::OnInit( TNotifyUI& msg )
{
	m_pPaintMngr = msg.pSender->GetManager();
	CEditUI *pSerial = (CEditUI*)ICommonOp::FindControl(m_pPaintMngr, strEditSn);
	if ( pSerial != NULL)
	{
		pSerial->SetMaxChar(MAX_SERIAL_INPUT_LEN);
	}
	CProgressUI *pProgress = (CProgressUI*)ICommonOp::FindControl( m_pPaintMngr, strProgressLoad );
	pProgress->SetMaxValue(	emProcessOk );
	pProgress->SetValue(0);
	if ( true /*��ѡ��*/ )
	{
		if ( !CTftpOp::Open() )
		{
			ICommonOp::ShowNotifyDlg("Tftp����ʧ��");
			return false;
		}
		String strPath = ICommonOp::GetControlText( m_pPaintMngr, CLoadLogic::strREditTftpPath );
		CTftpOp::SetTftpPath( strPath.c_str() );

	}
	return true;
}

bool CLoadLogic::OnLoadStateChange( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	if ( USERDATA->GetUIMode() != emModeLoad )
	{
		return false;
	}
	u32 *pdwStateId = (u32*)wParam;
	if( *pdwStateId <= emProcessOk )
	{
		CProgressUI *pProgress = (CProgressUI*)ICommonOp::FindControl( m_pPaintMngr, strProgressLoad );
		pProgress->SetValue( *pdwStateId );
	}
	switch ( *pdwStateId )
	{
	case emBootInfoSet:
		{
			USERDATA->SetDispState(_T("IP/MAC ���óɹ�"));
		}
		break;
	case emUpdateE2prom:
		{
			USERDATA->SetDispState(_T("EPROM �����ɹ�"));

		}
		break;
	case emUploadSys:
		{
			USERDATA->SetDispState(_T("��ʼ�ϴ� SYS"));
		}
		break;
	case emUpdateSys:
		{
			USERDATA->SetDispState(_T("�������� SYS"));
		}
		break;
	case emProcessOk:	
		{
			USERDATA->SetDispState(_T("���м������  ȫ�������ɹ�"));
			ICommonOp::SetControlBkImg( "skinres/pass.bmp", m_pPaintMngr, CLoadLogic::strLoadResult );			
			OnLoadEnd();
		}
		break;
	default:
		break;
	}
	delete pdwStateId;			//�ͷ�
	return true;
}

bool CLoadLogic::OnLoadErr( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	ICommonOp::SetControlBkImg( "skinres/nopass.bmp", m_pPaintMngr, CLoadLogic::strLoadResult );			
	u32 *pdwErrId = (u32*)wParam;
	switch ( *pdwErrId )
	{
	case emRcvAckErr:
		{
			USERDATA->SetDispState(_T("����IP��MAC��ַ����"));		
		}
		break;
	case emWriteEpromErr:
		{
			USERDATA->SetDispState(_T("дEprom����"));		
		}
		break;
	}
	delete pdwErrId;			//�ͷ�
	OnLoadEnd();
	return true;
}

bool CLoadLogic::OnBtnSaveEdit( TNotifyUI& msg )
{
	//���Ϸ���
	String strErrMsg = _T("");
	if ( CheckEditLegal( strErrMsg ) )
	{
		SaveEditData();					//����
		RefreshCtrlState(false);		//�ؼ�״̬
		RefreshEditData();				//ˢ��
		delete m_pPreviousDvc;
		m_pPreviousDvc = NULL;
		CheckUIState();
		CEditUI *pEditSn = (CEditUI*)ICommonOp::FindControl( m_pPaintMngr, strEditSn );
		pEditSn->SetFocus();
		return true;
	}
	else
	{
		ICommonOp::ShowNotifyDlg( strErrMsg.c_str() );
		return false;
	}
}
bool CLoadLogic::OnBtnChangeEdit( TNotifyUI& msg )
{
	//����
	IDevice *pDvc =  USERDATA->GetDevice();
	m_pPreviousDvc = pDvc->Clone();
	CComboUI *pCombo = (CComboUI*)ICommonOp::FindControl( m_pPaintMngr, strCbLoadDvc );
	m_dwPreviousSelIdx = pCombo->GetCurSel();
	RefreshCtrlState(true);		//�ؼ�״̬
	CheckUIState();
	return true;
}

bool CLoadLogic::OnBtnCancelEdit( TNotifyUI& msg )
{
	if ( USERDATA->GetStartIp() == 0 )
	{
		//Bug00184442 ���ε�½ʱ��Ĭ��û�����豸���޸���֮�󲻵㱣��ֱ��ȡ������ѳ�ʼֵ����һ��
		//HW
		String strHw = "1.11";
		ICommonOp::SetControlText( strHw, m_pPaintMngr, strREditHw );

		//IP
		String strIp = "10.1.1.2";
		ICommonOp::SetControlText( strIp, m_pPaintMngr, strREditStartIp );

		//Mac
		String strMac = "00:1f:3c:13:c1:1f";
		ICommonOp::SetControlText( strMac, m_pPaintMngr, strREditStartMac );
		
		//Tftp Path
		String strPath = "C:\\";
		ICommonOp::SetControlText( strPath, m_pPaintMngr, strREditTftpPath );
		return true;
	}

	//ȡ����ʱ���豸��ԭ
	USERDATA->SetDevice( m_pPreviousDvc->Clone() );
	if ( m_pPreviousDvc != NULL )
	{
		delete m_pPreviousDvc;
		m_pPreviousDvc = NULL;
	}
	
	CComboUI *pCombo = (CComboUI*)ICommonOp::FindControl( m_pPaintMngr, strCbLoadDvc );
	pCombo->SelectItem( m_dwPreviousSelIdx );
	RefreshCtrlState(false);//�ؼ�״̬
	RefreshEditData();		//ˢ������
	CheckUIState();
	return true;
}


bool CLoadLogic::RefreshCtrlState( bool bEnabled )
{
	ICommonOp::EnableControl( bEnabled, m_pPaintMngr, CLoadLogic::strCbLoadDvc );
	ICommonOp::EnableControl( bEnabled, m_pPaintMngr, CLoadLogic::strREditHw );
	ICommonOp::EnableControl( bEnabled, m_pPaintMngr, CLoadLogic::strREditStartIp );
	ICommonOp::EnableControl( bEnabled, m_pPaintMngr, CLoadLogic::strREditStartMac );
	ICommonOp::EnableControl( bEnabled, m_pPaintMngr, CLoadLogic::strBtnBrowsePath );
	ICommonOp::EnableControl( bEnabled, m_pPaintMngr, CLoadLogic::strREditTftpPath );
	ICommonOp::ShowControl( bEnabled, m_pPaintMngr, CLoadLogic::strBtnSaveEdit );
	ICommonOp::ShowControl( bEnabled, m_pPaintMngr, CLoadLogic::strBtnCancelEdit );
	ICommonOp::ShowControl( !bEnabled, m_pPaintMngr, CLoadLogic::strBtnChangeEdit );
// 	if ( USERDATA->GetDevice() != NULL )
// 	{
// 		ICommonOp::EnableControl( true, m_pPaintMngr, CLoadLogic::strBtnCancelEdit );
// 	}
// 	else
// 	{
// 		ICommonOp::EnableControl( false, m_pPaintMngr, CLoadLogic::strBtnCancelEdit );
// 	}
	return true;
}


bool CLoadLogic::SaveEditData()
{
	//Device
	String strDvc = ICommonOp::GetControlText( m_pPaintMngr, strCbLoadDvc );

	//IP
	String strIp = ICommonOp::GetControlText( m_pPaintMngr, strREditStartIp );
	USERDATA->SetSartIp( inet_addr(strIp.c_str()) );

	//Mac
	String strMac = ICommonOp::GetControlText( m_pPaintMngr, strREditStartMac );
	USERDATA->SetStartMac( strMac.c_str() );

	IBoard *pBoard = USERDATA->GetDevice()->GetBoard(0);
	//HW
	String strHw = ICommonOp::GetControlText( m_pPaintMngr, strREditHw );
	pBoard->SetHardVersion( strHw.c_str() );
	//TftpPath
	String strPath = ICommonOp::GetControlText( m_pPaintMngr, strREditTftpPath );
	USERDATA->SetTftpPath( strPath.c_str() );
	return true;
}


bool CLoadLogic::RefreshEditData()
{
	//IP
	u32 dwStartIp = USERDATA->GetStartIp();
	struct in_addr IpAddr;
	memcpy( &IpAddr, &dwStartIp, sizeof(dwStartIp) );
	String strIp = inet_ntoa( IpAddr );
	ICommonOp::SetControlText( strIp, m_pPaintMngr, strREditStartIp );
	
	//Mac
	String strMac = USERDATA->GetStartMac();
	ICommonOp::SetControlText( strMac, m_pPaintMngr, strREditStartMac );

	IBoard *pBoard = USERDATA->GetDevice()->GetBoard(0);
	//HW
	String strHw = pBoard->GetHardVersion();
	ICommonOp::SetControlText( strHw, m_pPaintMngr, strREditHw );
	//Tftp Path
	String strPath = USERDATA->GetTftpPath();
	ICommonOp::SetControlText( strPath, m_pPaintMngr, strREditTftpPath );
	return true;
}


bool CLoadLogic::CheckEditLegal( String &strErrMsg )
{
	strErrMsg = _T("");
	//Device
	String strDvc = ICommonOp::GetControlText( m_pPaintMngr, strCbLoadDvc );
	if ( strDvc == _T("") )
	{
		strErrMsg += _T("��ѡ���豸!");
		return false;
	}
	IDevice *pCurDvc = USERDATA->GetDevice();
	if ( pCurDvc == NULL )
	{
		strErrMsg += _T("��ǰѡ���豸������!���������ļ���");
		return false;	
	}
	//HW
	String strHw = ICommonOp::GetControlText( m_pPaintMngr, strREditHw );
	if( !CheckHardVerFormat(strHw.c_str()) )
	{
		strErrMsg += _T("Ӳ���汾��ʽ����ȷ");
		return false;
	}
	//IP
	String strIp = ICommonOp::GetControlText( m_pPaintMngr, strREditStartIp );
	if ( !CheckIpFormat( strIp.c_str() ) )
	{
		strErrMsg += _T("IP��ַ��ʽ����ȷ ");
		return false;
	}
	//Mac
	String strMac = ICommonOp::GetControlText( m_pPaintMngr, strREditStartMac );
	if ( !CheckMacFormat(strMac.c_str()) )
	{
		strErrMsg += _T("Mac��ַ��ʽ����ȷ ");
		return false;
	}
	//Tftp path
	String strPath = ICommonOp::GetControlText( m_pPaintMngr, strREditTftpPath );
	if ( !ICommonOp::CheckFileExists(strPath) )
	{
		strErrMsg += _T("�ļ�·��������");
		return false;
	}

	return true;
}

bool CLoadLogic::CheckMacFormat( const s8* pchMac )
{
	if ( strlen(pchMac) == 0 )
	{
		return false;
	}
	u8 achMac[MAC_SIZE] = {0};
	CStdString strOrigin = pchMac;
	//ȫ��תΪ��д
	strOrigin.MakeUpper();
	//����ʽת��
	sscanf( strOrigin.GetData(), "%2X:%2X:%2X:%2X:%2X:%2X", 
		&achMac[0], &achMac[1], &achMac[2],
		&achMac[3], &achMac[4], &achMac[5] );
	u32 dwLen = strOrigin.GetLength();
	s8 achNew[MAX_MAC_LENGTH];
	memset( achNew, 0, sizeof(achNew) );
	//����ʽת����
	sprintf(achNew,"%02X:%02X:%02X:%02X:%02X:%02X", 
		achMac[0], achMac[1], achMac[2], 
		achMac[3], achMac[4], achMac[5] );
	if ( strcmp( strOrigin.GetData(), achNew ))
	{
		return false;
	}
	return true;
}

bool CLoadLogic::CheckIpFormat( const s8* pchIp )
{
	if ( strlen(pchIp) == 0 )
	{
		return false;
	}
	u8 abyIp[IP_SIZE] = {0};
	//����ʽת��
	sscanf( pchIp, "%d.%d.%d.%d", 
		&abyIp[0], &abyIp[1], &abyIp[2],
		&abyIp[3] );
	u32 dwLen = strlen( pchIp );
	s8 achNew[IP_STR_LEN]; 
	memset( achNew, 0, sizeof(achNew) );
	//����ʽת����
	sprintf( achNew,"%d.%d.%d.%d", 
		abyIp[0], abyIp[1], abyIp[2], 
		abyIp[3] );
	if ( strcmp( pchIp, achNew ) )
	{
		return false;
	}
	//�޶�10.1.1.x
	if ( abyIp[0] != 10 || abyIp[1] != 1 || abyIp[2] != 1 )
	{
		return false;
	}
	return true;

}

bool CLoadLogic::CheckHardVerFormat( const s8* pchHardVer )
{
	if ( strlen(pchHardVer) != 4 )
	{
		return false;
	}
	u8 achHard[2] = {0};
	//����ʽת��
	sscanf( pchHardVer, "%d.%d", 
		&achHard[0], &achHard[1] );
	u32 dwLen = strlen( pchHardVer );
	s8 achNew[ MAX_HW_LEN ]; 
	memset( achNew, 0, sizeof(achNew) );
	//����ʽת����
	sprintf( achNew,"%d.%02d", 
		achHard[0], achHard[1] );
	if ( strcmp( pchHardVer, achNew ) )
	{
		return false;
	}
	return true;
	
}

bool CLoadLogic::OnDvcSelected( TNotifyUI& msg )
{
	String strSelectedName = ICommonOp::GetControlText( m_pPaintMngr , strCbLoadDvc );
	USERDATA->SetDevice( strSelectedName );
	return true;
}

bool CLoadLogic::OnDvcChange( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	if ( USERDATA->GetUIMode() != emModeLoad )
	{
		return false;
	}
	//ˢ��PID��HID
	IDevice *pDvc = USERDATA->GetDevice();
	if ( pDvc != NULL )
	{
		IBoard *pBrd = pDvc->GetBoard(0);
		u16 dwPid = pBrd->GetPid();
		s8 achPid[10] = {0};	//��ʱ�ַ������10���ַ�
		itoa( dwPid,achPid, 16 );
		s8 chTemp[10] = {NULL};
		sprintf(chTemp,"%#06X",dwPid);							//6λ��0x0000 ��O��ȫ  Ҳ������%.4x
		ICommonOp::SetControlText( chTemp, m_pPaintMngr, strLabelPid );

		memset(chTemp,0,sizeof(chTemp));
		u16 dwHid = pBrd->GetHid(); 
		s8 achHid[10] = {0};	//��ʱ�ַ������10���ַ�
		itoa( dwHid, achHid, 16 );
		sprintf(chTemp,"%#06X",dwHid);
		ICommonOp::SetControlText( chTemp, m_pPaintMngr, strLabelHid );
		return true;
	}
	else
	{
		String strDvcName = ICommonOp::GetControlText( m_pPaintMngr , strCbLoadDvc );
		if ( strDvcName != "" )
		{
			ICommonOp::ShowNotifyDlg(_T("��ǰ�豸��ʧ�ܣ����������ļ�"));
		}
		ICommonOp::SetControlText( "", m_pPaintMngr, strLabelPid );
		ICommonOp::SetControlText( "", m_pPaintMngr, strLabelHid );
		return false;
	}
	
}

bool CLoadLogic::OnSerialChange( TNotifyUI& msg )
{
	CEditUI *pSerial = (CEditUI*)ICommonOp::FindControl( m_pPaintMngr, strEditSn );
	u32 dwLen = strlen( pSerial->GetText().GetData() );
	if(  dwLen >= MAX_SERIAL_INPUT_LEN )
	{
		pSerial->SetReadOnly(true);
		CheckUIState();
		//pSerial->SetBkColor( COLOR_GRAY );
	}
	return true;
}



bool CLoadLogic::CheckUIState()
{
	CControlUI *pBtnChange = ICommonOp::FindControl( m_pPaintMngr, strBtnChangeEdit ); 
	CEditUI *pEditSn = (CEditUI*)ICommonOp::FindControl( m_pPaintMngr, strEditSn );
	//������"�޸�"�������ɼ������кű༭����ֻ������ǰ�Ǳ༭ģʽ
	//��"�޸�","ȡ��","����"���������к��������
	if ( !pBtnChange->IsVisible() || !pEditSn->IsReadOnly() )
	{
		USERDATA->SetUIState( emUILoadEdit );
	}
	else
	{
		//������ڼ��أ��򲻽������в���
		EmUIState emState = USERDATA->GetUIState();
		if ( emState == emUILoading )
		{
			return false;
		}
		//�������к�
		IDevice *pDvc = USERDATA->GetDevice();
		IBoard *pBoard = pDvc->GetBoard(0);
		pBoard->SetSerialNo( ICommonOp::GetControlText(m_pPaintMngr, strEditSn).c_str() );
		USERDATA->SetUIState( emUILoadNormal );
	}
	return true;
}

bool CLoadLogic::OnUpdateState( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	if ( USERDATA->GetUIMode() != emModeLoad )
	{
		return false;
	}
	return ICommonOp::SetControlText( USERDATA->GetDispState(), m_pPaintMngr, CLoadLogic::strStateDis );
}

//�������� ��
//���ش��� ��
//*�쳣�Ͽ�* û�ж��������ƣ�Ŀǰδʵ��
bool CLoadLogic::OnLoadEnd()
{
	//���sn ��ԭ״̬
	CEditUI *pSerial = (CEditUI*)ICommonOp::FindControl( m_pPaintMngr, strEditSn );
	pSerial->SetReadOnly(false);
	pSerial->SetText(_T(""));
	pSerial->SetBkColor(COLOR_WHITE);
	//����
	ICommonOp::EnableControl( true, m_pPaintMngr, strBtnChangeEdit );

	CheckUIState();
	pSerial->SetFocus();
	return true;
}

bool CLoadLogic::OnUIStateChange( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	EmUIState emState = USERDATA->GetUIState();
	switch( emState )
	{
	case emUILoadEdit:
		{
			LOGEVENT("����༭ģʽ\n");
			ICommonOp::ShowControl( true, m_pPaintMngr, "BtnSwitch" );
			ICommonOp::EnableControl( true, m_pPaintMngr, strBtnChangeEdit );			
		}
		break;
	case emUILoadNormal:
		{
			USERDATA->SetDispState("�ȴ��豸����...");
			ICommonOp::ShowControl( true, m_pPaintMngr, "BtnSwitch" );
			LOGEVENT("׼������\n");
		}
		break;
	case emUILoading:
		{
			USERDATA->SetDispState("���ڼ���...");
			ICommonOp::ShowControl( false, m_pPaintMngr, "BtnSwitch" );
			LOGEVENT("��ʼ����\n");
			OnLoading();
		}
		break;
	default:
		break;
	}
	return true;
}

bool CLoadLogic::OnLoading()
{
	//�����޸�
	ICommonOp::EnableControl( false, m_pPaintMngr, strBtnChangeEdit );
	//��ʾ�忨��Ϣ
	IDevice *pDvc = USERDATA->GetDevice();
	IBoard *pBoard = pDvc->GetBoard( 0 );
	if ( pBoard != NULL )
	{
		//��������
		ICommonOp::SetControlText( pBoard->GetDate(), m_pPaintMngr, CLoadLogic::strLoadDate );
		//ͼƬ
		ICommonOp::SetControlBkImg( pBoard->GetBrdPic(), m_pPaintMngr, CLoadLogic::strLoadPic );
		//Mac
		ICommonOp::SetControlText( pBoard->GetMac(), m_pPaintMngr, CLoadLogic::strLoadMac );
		//Ip
		struct in_addr IpAddr;
		u32 dwIp = pBoard->GetIpAddr();
		memcpy( &IpAddr, &dwIp, sizeof(dwIp) );
		String strIpAddr = inet_ntoa( IpAddr );
		ICommonOp::SetControlText( strIpAddr, m_pPaintMngr, CLoadLogic::strLoadIp );
	}
	return true;
}

bool CLoadLogic::OnBrowsePath( TNotifyUI& msg )
{
	String strPath = ICommonOp::GetFolderDir("TFTP�����ļ�·��");
	if ( strPath != "" )
	{
		ICommonOp::SetControlText(strPath, m_pPaintMngr, CLoadLogic::strREditTftpPath );
		return true;
	}
	return false;
}

bool CLoadLogic::OnTftpPathChange( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	String strPath = USERDATA->GetTftpPath();
	CTftpOp::SetTftpPath(strPath.c_str());
	//DHCP
	IDevice *pDvc = USERDATA->GetDevice();
	if( pDvc != NULL)
	{
		String strDvcName = pDvc->GetName();
		strDvcName += "manuboot.bin";
		CTftpOp::SetDhcpBootFile(strDvcName.c_str());
	}
	return true;
}

bool CLoadLogic::OnStartLoadReq( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	ICommonOp::SetControlBkImg( "", m_pPaintMngr, CLoadLogic::strLoadResult );
	IDevice *pDvc = USERDATA->GetDevice();
	IBoard *pBrd = pDvc->GetBoard(0);
	String strBrdPic = pBrd->GetBrdPic();
	ICommonOp::SetControlBkImg( strBrdPic, m_pPaintMngr, strLoadPic );
	return true;
	
}

bool CLoadLogic::OnUIModeChange( WPARAM wParam, LPARAM lParam, bool& bHandle )
{
	if ( USERDATA->GetUIMode() == emModeLoad )
	{
		RefreshCtrlState(true);		//�ؼ�״̬
		CheckUIState();
	}
	return true;
}

bool CLoadLogic::OnREditLoseFocus( TNotifyUI& msg )
{
	CRichEditUI *pEdit = (CRichEditUI*)msg.pSender;
	if ( pEdit != NULL )
	{
		for ( u32 dwLen = 0; dwLen < pEdit->GetTextLength(); dwLen++ )
		{
			pEdit->LineLeft();
		}
	}
	return true;
}









