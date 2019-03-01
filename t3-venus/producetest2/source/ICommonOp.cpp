// ICommonOp.cpp: implementation of the ICommonOp class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ICommonOp.h"
#include "io.h"
#include "eventid.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

bool ICommonOp::GetNodeValueInt( DocNode Node, String Tag, u32 &dwValue )
{
	String strValue;
	strValue = GetNodeValueStr( Node, Tag );
	if ( strValue == _T("") )
	{
		return false;
	}
	if( IsDigit(strValue) )                                                 
	{
		dwValue = atoi( strValue.c_str() );
	}
	else                                                                      //如果不是数字
	{
		if( !IMacroMngr::GetSingletonPtr()->Translate( strValue, dwValue ) )  //也不是宏
		{
			return false;  //返回false
		}
	}
	return true;
}

String ICommonOp::GetNodeValueStr( DocNode Node, String Tag)
{
	if ( !Node.IsValid() )
	{
		return _T("");
	}
	return Node.GetAttributeValue( Tag.c_str() );
}

bool ICommonOp::IsDigit( String strDig )
{
	if( strDig.length() == 0 )
	{
		return false;
	}
	for( u32 dwIdx = 0; dwIdx < strDig.length(); dwIdx++ )
	{
		if( strDig[dwIdx] < '0' || strDig[dwIdx] > '9')
			return false;
	}
	return true;
}

ITestCase* ICommonOp::GetTestCase( IBoard *pBoard, u32 dwIdx )
{
	ITestCaseContainer *pContainer = pBoard->GetCaseContainer();
	return pContainer->GetTestCase( dwIdx );
}

ITestCase* ICommonOp::GetTestCase( IDevice *pDvc, String strCaseName )
{
	u32 dwIdx = 0;
	IBoard *pBoard = NULL;
	while( pBoard = pDvc->GetBoard(dwIdx) )
	{	
		ITestCaseContainer *pContainer = pBoard->GetCaseContainer();
		ITestCase *pTestCase = pContainer->GetTestCase( strCaseName );
		if ( pTestCase != NULL )
		{
			return pTestCase;
		}
		dwIdx++;
	}
	return NULL;
}

CControlUI* ICommonOp::FindControl( CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent /*= NULL*/ )
{
	if ( pManager == NULL )
	{
		return NULL;
	}
	if ( pParent == NULL )
	{
		return pManager->FindControl( strControlName.c_str() );
	}
	else
	{
		return pManager->FindSubControlByName( pParent, strControlName.c_str() );
	}
}

bool ICommonOp::EnableControl( bool bEnabled, CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent /*= NULL*/ )
{
	CControlUI *pControl = FindControl( pManager, strControlName, pParent );
	if ( pControl != NULL )
	{
		pControl->SetEnabled ( bEnabled );
		return true;
	}
	return false;
}

bool ICommonOp::ShowControl( bool bVisible, CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent /*= NULL*/ )
{
	CControlUI *pControl = FindControl( pManager, strControlName, pParent );
	if ( pControl != NULL )
	{
		pControl->SetVisible(bVisible);
		return true;
	}
	return false;

}

bool ICommonOp::SetControlText( String strText, CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent  /*= NULL*/ )
{
	CControlUI *pControl = FindControl( pManager, strControlName, pParent );
	if ( pControl != NULL )
	{
		pControl->SetText( strText.c_str() );
		return true;
	}
	return false;
}

String ICommonOp::GetControlText( CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent /*= NULL*/ )
{
	CControlUI *pControl = FindControl( pManager, strControlName, pParent );
	if ( pControl != NULL )
	{
		return pControl->GetText().GetData();
	}
	return _T("");
}

bool ICommonOp::OptionSelect( bool bSelect, CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent  /*= NULL*/ )
{
	COptionUI *pOpt = (COptionUI*)FindControl( pManager, strControlName, pParent );
	if ( pOpt != NULL )
	{
		pOpt->Selected( bSelect );
		return true;
	}
	return false;
}

bool ICommonOp::SetControlBkImg( String strFile, CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent /* = NULL */ )
{
	CControlUI *pControl = FindControl( pManager, strControlName, pParent );
	if ( pControl != NULL )
	{
		pControl->SetBkImage( strFile.c_str() );
		return true;
	}
	return false;
}

bool ICommonOp::Notify( u16 wMsgId, void *pData )
{
	TMsgParam Msg;
	Msg.wMsgId = wMsgId;
	Msg.pData = pData;
	IMsgManager::GetSingletonPtr()->SendMsg( Msg );
	return true;
}


bool ICommonOp::ShowNotifyDlg( const String &strNotify )
{
	USERDATA->SetNotifyDlgStr( strNotify );
	IWindowManager::GetSingletonPtr()->ShowModal("notifydialog");
	return true;
}

bool ICommonOp::ShowChooseDlg( const String &strNotify )
{
	USERDATA->SetNotifyDlgStr( strNotify );
	IWindowManager::GetSingletonPtr()->ShowModal("choosedialog");
	return USERDATA->GetChooseDlgResult();
}

String ICommonOp::GetFolderDir(const String strNotify )
{
	static String strPre = "";					//上一次的路径
	s8 achDir[MAX_PATH_LENTH];
	memset( achDir, 0, sizeof(achDir) );
	BROWSEINFO bInfo = {0};  
	bInfo.hwndOwner = GetForegroundWindow();	//父窗口  
	bInfo.lpszTitle = strNotify.c_str();  
	bInfo.pidlRoot = 0;
	bInfo.ulFlags = BIF_RETURNONLYFSDIRS; 
	if ( strPre != "" )
	{
		bInfo.lParam = (LPARAM)(strPre.c_str());	//初始化路径
		bInfo.lpfn = BrowseCallbackProc;
	}
	//关于更多的 ulFlags 参考 http://msdn.microsoft.com/en-us/library/bb773205(v=vs.85).aspx  
	LPITEMIDLIST lpDlist;  
	lpDlist = SHBrowseForFolder( &bInfo );  
	if ( lpDlist != NULL )						//单击了确定按钮  
	{  
		SHGetPathFromIDList( lpDlist, achDir ); 
	}
	strPre = achDir;
	return achDir;
};

bool ICommonOp::CheckFileExists( const String &strFilePath )
{
	return ( _access( strFilePath.c_str(), 0 ) != -1 );
}

bool ICommonOp::RegMacros()
{
	//注册宏
	REGMACRO( TRUE )
	REGMACRO( FALSE )

//	REGMACRO( C_S_REG_REQ )
//	REGMACRO( S_C_REG_ACK )
//	REGMACRO( S_C_REG_NACK )
                				
	//t300相关
	REGMACRO( AID_PRODUCETEST_APP )
	REGMACRO( ev_CNPRODUCETESTLOGIN_REQ )
	REGMACRO( ev_CNPRODUCETESTLOGIN_ACK )
	REGMACRO( ev_CNPRODUCETESTLOGIN_NACK )
	REGMACRO( ev_CNPRODUCETEST_CMD )
	REGMACRO( emTestVideoMAIN1InOut )
	REGMACRO( emTestVideoMAIN2InOut )
	REGMACRO( emTestVideoMAIN3InOut )
	REGMACRO( emTestVideoSUB1InMAIN3AUX12Out )
	REGMACRO( emTestDualSUB2InTurnHDMIAUX1Out )
	REGMACRO( emTestDualAUX1InTurnHDMIAUX1Out )
	REGMACRO( emTestDualAUX2InTurnHDMIAUX1Out )
	REGMACRO( emTestDualAUX3InTurnHDMIAUX1Out )
	REGMACRO( emTestDualAUX4InTurnHDMIAUX2Out )
	REGMACRO( emTestDualAUX5InTurnHDMIAUX2Out )
	REGMACRO( emTestDualAUX6InTurnHDMIAUX2Out )
//	REGMACRO( emTestDualSUB2InTurnVGAAUX1Out )
	REGMACRO( emTestDualAUX1InTurnVGAAUX1Out )
	REGMACRO( emTestDualAUX2InTurnVGAAUX1Out )
	REGMACRO( emTestDualAUX3InTurnVGAAUX1Out )
	REGMACRO( emTestDualAUX4InTurnVGAAUX2Out )
	REGMACRO( emTestDualAUX5InTurnVGAAUX2Out )
	REGMACRO( emTestDualAUX6InTurnVGAAUX2Out )
	REGMACRO( emTestAudioMIC1InMAIN1Out )
	REGMACRO( emTestAudioMIC2InMAIN2Out )
	REGMACRO( emTestAudioMIC3InMAIN3Out )
	REGMACRO( emTestAudioCANNON1InMAIN1Out )
	REGMACRO( emTestAudioCANNON2InMAIN1Out )
	REGMACRO( emTestAudioCANNON3InMAIN1Out )
	REGMACRO( emTestAudioCANNON4InMAIN2Out )
	REGMACRO( emTestAudioCANNON5InMAIN2Out )
	REGMACRO( emTestAudioCANNON6InMAIN2Out )
	REGMACRO( emTestAudioCANNON7InMAIN3Out )
	REGMACRO( emTestAudioCANNON8InMAIN3Out )
	REGMACRO( emTestAudioCANNON9InMAIN3Out )
	REGMACRO( emTestAudioCANNON10InMAIN2Out )
	REGMACRO( emTestAudioAUX1InAUX1Out )
	REGMACRO( emTestAudioAUX2InAUX1Out )
	REGMACRO( emTestAudioAUX3InAUX1Out )
	REGMACRO( emTestAudioAUX4InAUX2Out )
	REGMACRO( emTestAudioAUX5InAUX2Out )
	REGMACRO( emTestAudioAUX6InAUX2Out )
	REGMACRO( emTestLightFunc )
	REGMACRO( emTestRTCFunc )
	REGMACRO( emTestUSB1Func )
	REGMACRO( emTestUSB2Func )
	REGMACRO( emTestRS232LoopbackFunc )
	REGMACRO( emTestRS422LoopbackFunc )
	REGMACRO( emTestRS485LoopbackFunc )
	REGMACRO( emTestALMLoopBackFunc )
	REGMACRO( emTestLAN1Func)
	REGMACRO( emTestLAN2Func )
	REGMACRO( emTestInfraredSendFunc )
	REGMACRO( emTestAudioInMain1OutCannon1In )
	REGMACRO( emTestAudioInMain1OutCannon2In )
	REGMACRO( emTestAudioInMain1OutCannon3In )
	REGMACRO( emTestAudioInMain1OutCannon4In )
	REGMACRO( emTestAudioInMain1OutCannon5In )
	REGMACRO( emTestAudioInMain1OutCannon6In )
	REGMACRO( emTestAudioInMain1OutCannon7In )
	REGMACRO( emTestAudioInMain1OutCannon8In )	
	REGMACRO( emTestAudioInMain1OutCannon9In )
	REGMACRO( emTestAudioInMain1OutCannon10In )	
	REGMACRO( emTestAudioOutMainL1OutCannon1In )
	REGMACRO( emTestAudioOutMainR1OutCannon1In )
	REGMACRO( emTestAudioOutMainL2OutCannon1In )
	REGMACRO( emTestAudioOutMainR2OutCannon1In )
	REGMACRO( emTestAudioOutMainL3OutCannon1In )
	REGMACRO( emTestAudioOutMainR3OutCannon1In )
	REGMACRO( ev_CNPRODUCETESTRESULT_NTY )
	REGMACRO( ev_CNPRODUCETESTDEFAULT_CMD )

	REGMACRO( emVidMAINIn1_HDMI_MAINOut1_Priom )
	REGMACRO( emVidMAINIn1_HDMI_MAINOut1_Mini )
	REGMACRO( emVidSUBIn1_HDMI_MAINOut1_Priom )
	REGMACRO( emVidSUBIn1_HDMI_MAINOut1_Mini )
	REGMACRO( emVidMAINIn2_HDMI_MAINOut2_Priom )
	REGMACRO( emVidMAINIn2_HDMI_MAINOut2_Mini )
	REGMACRO( emVidSUBIn2_HDMI_MAINOut2_Priom )
	REGMACRO( emVidSUBIn2_HDMI_MAINOut2_Mini )
	REGMACRO( emVidMAINIn3_HDMI_MAINOut3_Priom )
	REGMACRO( emVidMAINIn3_HDMI_MAINOut3_Mini )
	REGMACRO( emVidSUBIn3_HDMI_MAINOut3_Priom )
	REGMACRO( emVidSUBIn3_HDMI_MAINOut3_Mini )
	REGMACRO( emVidAuxIn4_HDMI_MAINOut2_Priom )
	REGMACRO( emVidAuxIn4_HDMI_MAINOut2_Mini )
	REGMACRO( emVidSUBIn1_VGA_MAINOut1_Priom )
	REGMACRO( emVidSUBIn1_VGA_MAINOut1_Mini )
	REGMACRO( emVidSUBIn2_VGA_MAINOut2_Priom )
	REGMACRO( emVidSUBIn2_VGA_MAINOut2_Mini )
	REGMACRO( emVidSUBIn3_VGA_MAINOut3_Priom )
	REGMACRO( emVidSUBIn3_VGA_MAINOut3_Mini )
//	REGMACRO( emVidAuxIn4_VGA_MAINOut2_Priom )
//	REGMACRO( emVinAuxIn4_VGA_MAINOut2_Mini )
	REGMACRO( emDualAuxIn1_HDMI_AUXOut1 )
	REGMACRO( emDualAuxIn2_HDMI_AUXOut1 )
	REGMACRO( emDualAuxIn3_HDMI_AUXOut2 )
	REGMACRO( emDualAuxIn4_HDMI_AUXOut2 )
	REGMACRO( emDualSDIIn_HDMI_AUXOut2 )
	REGMACRO( emDualAuxIn1_VGA_AUXOut1_VGA )
	REGMACRO( emDualAuxIn2_VGA_AUXOut1_VGA )
	REGMACRO( emDualAuxIn3_VGA_AUXOut2_VGA )
	REGMACRO( emDualAuxIn4_HDMI_AUXOut2_VGA )

	REGMACRO( emT300ERS485Loopback_FirstFunc )
	REGMACRO( emT300ERS485Loopback_SecondFunc )
	REGMACRO( emT300ERS422Loopback_FirstFunc )
	REGMACRO( emT300ERS422Loopback_SecondFunc )
	REGMACRO( emT300ERS232LoopbackFunc )

//	REGMACRO( ev_CNPRODUCETESTDEFAULT_NTY )
	REGMACRO( VERSION_NUM)
	return true;

}

bool ICommonOp::RegObservers()
{
	// 注册观察者
	REG_MSG_OBSERVER( IUserDataMngr::GetSingletonPtr() )
	REG_MSG_OBSERVER( ILoadInfoMngr::GetSingletonPtr() )
	return true;
	
}

s32 CALLBACK ICommonOp::BrowseCallbackProc( HWND hwnd,UINT uMsg,LPARAM lParam,LPARAM lpData )
{
	if(uMsg == BFFM_INITIALIZED)
	{  
		SendMessage(hwnd, BFFM_SETSELECTION, TRUE, lpData);
	}
	return 0;
}

bool ICommonOp::SetControlBorderFormat( u32 dwColor, u32 dwSize, CPaintManagerUI *pManager ,
									   String strControlName, CControlUI *pParent /*= NULL */ )
{
	CControlUI *pCtrl = FindControl( pManager, strControlName, pParent );
	if ( pCtrl != NULL )
	{
		pCtrl->SetBorderColor(dwColor);
		pCtrl->SetBorderSize(dwSize);
		return true;
	}
	return false;
}

String ICommonOp::ConvertHardVer( const s8 *pchHardVer )
{
	String csHardVer = pchHardVer;
	if ( csHardVer.length() == 3 )
	{
		csHardVer.insert(1, ".");
	}
	return csHardVer;
}

bool ICommonOp::ConvertToUpper( LPSTR pchStr )
{
	u32 dwIdx = 0;
	while ( true )
	{
		if ( pchStr[dwIdx] == 0 )
		{
			break;
		}
		if ( pchStr[dwIdx] <= 'z' && pchStr[dwIdx] >= 'a')
		{
			pchStr[dwIdx] = ::toupper(pchStr[dwIdx]);
		}
		dwIdx++;
	}
	return true;
}
