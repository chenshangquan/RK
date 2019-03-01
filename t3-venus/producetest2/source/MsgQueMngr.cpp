#include "stdafx.h"
#include "MsgQueMngr.h"
#include "TestCase.h"
#include "MsgQueFactory.h"

static u8 s_byIndex = 0;
static u32 s_adwMainOutVol[10];
static u32 s_adwCannonOutVol[6];
static u8 s_byMainOutIndex = 0;
static u8 s_byCannonIndex = 0;

CMsgQueMngr::CMsgQueMngr() : m_dwCurPos(0),m_bTestResult(FALSE),m_bZeroCannonResult(FALSE),m_bZeroMainOutResult(FALSE)
{

}

CMsgQueMngr::~CMsgQueMngr()
{
}

bool CMsgQueMngr::IsEmpty()
{
	return m_vecMsgList.size() == 0;
}

bool CMsgQueMngr::IsEnd()
{
	if ( m_dwCurPos >= m_vecMsgList.size() )
	{
		LOGEVENT("消息队列结束\n");
		return true;
	}
	return false; 
}

bool CMsgQueMngr::AddMsg( TQueMsg Msg )
{
	m_vecMsgList.push_back( Msg );
	return true;
}


void CMsgQueMngr::ProcMsg( const TObMsg &ObMsg )
{
	/*验证消息....*/
	TQueMsg *pMsg = &m_vecMsgList[m_dwCurPos];

	if ( ObMsg.event == pMsg->dwMsgId )
	{
		if ( ObMsg.event == ev_CNPRODUCETESTRESULT_NTY && m_dwCurPos > 0 )
		{
			//取上一条发的消息
			TQueMsg *pLastMsg = &m_vecMsgList[m_dwCurPos-1];
			TCnProduceTestMsg tTestMsg;
			tTestMsg = *(TCnProduceTestMsg*)pLastMsg->achMsgBody;

			TCnProduceTestMsg tCnProduceTestMsg;				
			//tCnProduceTestMsg = *(TCnProduceTestMsg*)ObMsg.content;
			memcpy(&tCnProduceTestMsg, ObMsg.content,sizeof(TCnProduceTestMsg));
		    NetToHostMsg( tCnProduceTestMsg );
			NetToHostMsg( tTestMsg );
			//恢复出厂设置回复消息处理
// 			if ( tCnProduceTestMsg.m_emProduceTestType == emProducetestTypeEnd )
// 			{
// 				if ( TRUE == tCnProduceTestMsg.m_bProduceTestReult )
// 				{
// 					LOGEVENT("恢复出厂设置成功\n");
// 					NOTIFY( EV_DVC_BRD_RESTORE_SUCCESS );
// 				}
// 				else
// 				{
// 					NOTIFY( EV_DVC_BRD_RESTORE_FAIL );
// 				}
// 								
// 			}
			if ( tTestMsg.m_emProduceTestType == tCnProduceTestMsg.m_emProduceTestType )
			{
				//串口类测试项需打印具体接口名称到超级终端相应处理
				if ( tCnProduceTestMsg.m_emProduceTestType == emTestRS485LoopbackFunc || tCnProduceTestMsg.m_emProduceTestType == emTestRS422LoopbackFunc || tCnProduceTestMsg.m_emProduceTestType == emTestRS232LoopbackFunc || tCnProduceTestMsg.m_emProduceTestType == emT300ERS232LoopbackFunc )
				{
					InitRSTestResultMsg(ObMsg);
					LOGEVENT("[msg][in]%s\n", pMsg->strMsgDiscription.c_str() );
				}
				else if ( tCnProduceTestMsg.m_emProduceTestType == emTestALMLoopBackFunc )
				{
					InitALMTestResultMsg(ObMsg);
					LOGEVENT("[msg][in]%s\n", pMsg->strMsgDiscription.c_str() );
				}
				else if ( tCnProduceTestMsg.m_emProduceTestType == emTestAudioInMain1OutCannon1In || tCnProduceTestMsg.m_emProduceTestType == emTestAudioInMain1OutCannon2In || tCnProduceTestMsg.m_emProduceTestType == emTestAudioInMain1OutCannon3In ||
					 tCnProduceTestMsg.m_emProduceTestType == emTestAudioInMain1OutCannon4In || tCnProduceTestMsg.m_emProduceTestType == emTestAudioInMain1OutCannon5In || tCnProduceTestMsg.m_emProduceTestType == emTestAudioInMain1OutCannon6In ||
					  tCnProduceTestMsg.m_emProduceTestType == emTestAudioInMain1OutCannon7In || tCnProduceTestMsg.m_emProduceTestType == emTestAudioInMain1OutCannon8In || tCnProduceTestMsg.m_emProduceTestType == emTestAudioInMain1OutCannon9In || tCnProduceTestMsg.m_emProduceTestType == emTestAudioInMain1OutCannon10In  )
				{
					InitCannonTestResultMsg(ObMsg);
					LOGEVENT("[msg][in]%s\n", pMsg->strMsgDiscription.c_str() );
				}
				else if ( tCnProduceTestMsg.m_emProduceTestType == emTestAudioOutMainL1OutCannon1In || tCnProduceTestMsg.m_emProduceTestType == emTestAudioOutMainR1OutCannon1In|| tCnProduceTestMsg.m_emProduceTestType == emTestAudioOutMainL2OutCannon1In ||
					tCnProduceTestMsg.m_emProduceTestType == emTestAudioOutMainR2OutCannon1In ||tCnProduceTestMsg.m_emProduceTestType == emTestAudioOutMainL3OutCannon1In || tCnProduceTestMsg.m_emProduceTestType == emTestAudioOutMainR3OutCannon1In )
				{
					InitMainOutTestResultMsg(ObMsg);
					LOGEVENT("[msg][in]%s\n", pMsg->strMsgDiscription.c_str() );
				}
				else if ( tCnProduceTestMsg.m_emProduceTestType == emT300ERS485Loopback_FirstFunc ||tCnProduceTestMsg.m_emProduceTestType == emT300ERS422Loopback_FirstFunc )
				{
					InitRSFirstTestResultMsg( ObMsg );
					LOGEVENT("[msg][in]%s\n", pMsg->strMsgDiscription.c_str() );
				}
				else if ( tCnProduceTestMsg.m_emProduceTestType == emT300ERS485Loopback_SecondFunc ||tCnProduceTestMsg.m_emProduceTestType == emT300ERS422Loopback_SecondFunc )
				{
					InitRSSecTestResultMsg( ObMsg );
					LOGEVENT("[msg][in]%s\n", pMsg->strMsgDiscription.c_str() );
				}
				else
				{
					InitTestResultMsg(ObMsg);
					LOGEVENT("[msg][in]%s\n", pMsg->strMsgDiscription.c_str() );
				}
			}
		}
// 		else
// 		{
// 			LOGEVENT("[msg][in]%s\n", pMsg->strMsgDiscription.c_str() );
// 			LOGEVENT("收到消息但消息类型不是nty故进这里\n");
// 			m_dwCurPos++;
// 			SendHeaderMsg();
// 		}				
	}
}

void CMsgQueMngr::InitTestResultMsg( const TObMsg &ObMsg )
{
	TCnProduceTestMsg tCnProduceTestMsg;
	tCnProduceTestMsg = *(TCnProduceTestMsg*)ObMsg.content;
	NetToHostMsg( tCnProduceTestMsg );
	LOGEVENT("收到的测试项结果为:%d\n", tCnProduceTestMsg.m_bProduceTestReult );
	if ( tCnProduceTestMsg.m_bProduceTestReult == TRUE )
	{
		TCnProduceTestMsg *pMsg = new TCnProduceTestMsg;
		pMsg->m_bProduceTestReult = tCnProduceTestMsg.m_bProduceTestReult;
		NOTIFY( EV_DVC_RESULT,pMsg );
// 		if ( tCnProduceTestMsg.m_emProduceTestType == emTestLAN1Func )
// 		{
// 			ICommonOp::ShowNotifyDlg("为当前测试项搭建测试环境，完成后点确定");
// 		}
		m_dwCurPos++;
		SendHeaderMsg();
	}
	else
	{
		TCnProduceTestMsg *pMsg = new TCnProduceTestMsg;
		pMsg->m_bProduceTestReult = tCnProduceTestMsg.m_bProduceTestReult;
		NOTIFY( EV_DVC_RESULT,pMsg );
	}
}

void CMsgQueMngr::InitRSTestResultMsg( const TObMsg &ObMsg )
{
	BOOL abResult[5] = { TRUE };
	u8 abyTemp[sizeof(TCnProduceTestMsg) + 5 * sizeof(BOOL)];
	memcpy( &abyTemp, ObMsg.content, sizeof(abyTemp) );
	TCnProduceTestMsg tCnProduceTestMsg;
	memset( &tCnProduceTestMsg, 0, sizeof(TCnProduceTestMsg) );
	memcpy( &tCnProduceTestMsg, abyTemp, sizeof(tCnProduceTestMsg) );
	NetToHostMsg( tCnProduceTestMsg );
	u8 byIndex = 0;
	for ( byIndex = 0; byIndex < 5; byIndex++ )
	{
		memcpy( &abResult[byIndex], abyTemp+sizeof(tCnProduceTestMsg)+sizeof(BOOL)*byIndex, sizeof(BOOL) );
		abResult[byIndex] = ntohl(abResult[byIndex]);
	}
	LOGEVENT("收到的测试项结果为:%d\n", tCnProduceTestMsg.m_bProduceTestReult );
	if ( tCnProduceTestMsg.m_bProduceTestReult == TRUE )
	{
		TCnProduceTestMsg *pMsg = new TCnProduceTestMsg;
		pMsg->m_bProduceTestReult = tCnProduceTestMsg.m_bProduceTestReult;
		NOTIFY( EV_DVC_RESULT,pMsg );
		LOGEVENT("已将正确结果反馈至界面\n");
		m_dwCurPos++;
		SendHeaderMsg();
	}
	else
	{
		for ( byIndex = 0; byIndex < 5; byIndex++ )
		{
			if (abResult[byIndex] == FALSE)
			{
				switch ( byIndex )
				{
				case 0:
					{
						LOGEVENT("CONSOLE与CAM300硬环回串口功能测试失败\n");
						USERDATA->AppendComDisp(_T("CONSOLE与CAM300硬环回串口功能测试失败\n"));
						break;
					}
				case 1:
					{
						LOGEVENT("CAMPTZ与DISP 1硬环回串口功能测试失败\n");
						USERDATA->AppendComDisp(_T("CAMPTZ与DISP 1硬环回串口功能测试失败\n"));
						break;
					}
				case 2:
					{
						LOGEVENT("DISP 2与DISP 3硬环回串口功能测试失败\n");
						USERDATA->AppendComDisp(_T("DISP 2与DISP 3硬环回串口功能测试失败\n"));
						break;
					}
				case 3:
					{
						LOGEVENT("DOCCam与COM 1硬环回串口功能测试失败\n");
						USERDATA->AppendComDisp(_T("DOCCam与COM 1硬环回串口功能测试失败\n"));
						break;
					}
				case 4:
					{
						LOGEVENT("COM 2与COM 3硬环回串口功能测试失败\n");
						USERDATA->AppendComDisp(_T("COM 2与COM 3硬环回串口功能测试失败\n"));
						break;
					}
				default:
					break;
				}
			}
		
		}
		TCnProduceTestMsg *pMsg = new TCnProduceTestMsg;
		pMsg->m_bProduceTestReult = tCnProduceTestMsg.m_bProduceTestReult;
		NOTIFY( EV_DVC_RESULT,pMsg );
	}
}

void CMsgQueMngr::InitALMTestResultMsg( const TObMsg &ObMsg )
{
	BOOL abResult[8] = { TRUE };
	u8 abyTemp[sizeof(TCnProduceTestMsg) + 8 * sizeof(BOOL)];
	memcpy( &abyTemp, ObMsg.content, sizeof(abyTemp) );
	TCnProduceTestMsg tCnProduceTestMsg;
	memset( &tCnProduceTestMsg, 0, sizeof(TCnProduceTestMsg) );
	memcpy( &tCnProduceTestMsg, abyTemp, sizeof(tCnProduceTestMsg) );
	NetToHostMsg( tCnProduceTestMsg );
	u8 byIndex = 0;
	for ( byIndex = 0; byIndex < 8; byIndex++ )
	{
		memcpy( &abResult[byIndex], abyTemp+sizeof(tCnProduceTestMsg)+sizeof(BOOL)*byIndex, sizeof(BOOL) );
		abResult[byIndex] = ntohl(abResult[byIndex]);
	}
	LOGEVENT("收到的测试项结果为:%d\n", tCnProduceTestMsg.m_bProduceTestReult );
	if ( tCnProduceTestMsg.m_bProduceTestReult == TRUE )
	{
		TCnProduceTestMsg *pMsg = new TCnProduceTestMsg;
		pMsg->m_bProduceTestReult = tCnProduceTestMsg.m_bProduceTestReult;
		NOTIFY( EV_DVC_RESULT,pMsg );
		LOGEVENT("已将正确结果反馈至界面\n");
		m_dwCurPos++;
		SendHeaderMsg();
	}
	else
	{
		for ( byIndex = 0; byIndex < 8; byIndex++  )
		{
			if ( abResult[byIndex] == FALSE )
			{
				switch( byIndex )
				{
				case 0:
					{
						LOGEVENT("ALM OUT 1口接收到的与ALM IN 1口输入的不一致\n");
						USERDATA->AppendComDisp(_T("ALM OUT 1口接收到的与ALM IN 1口输入的不一致\n"));
						break;
					}
				case 1:
					{
						LOGEVENT("ALM OUT 2口接收到的与ALM IN 2口输入的不一致\n");
						USERDATA->AppendComDisp(_T("ALM OUT 2口接收到的与ALM IN 2口输入的不一致\n"));
						break;
					}
				case 2:
					{
						LOGEVENT("ALM OUT 3口接收到的与ALM IN 3口输入的不一致\n");
						USERDATA->AppendComDisp(_T("ALM OUT 3口接收到的与ALM IN 3口输入的不一致\n"));
						break;
					}
				case 3:
					{
						LOGEVENT("ALM OUT 4口接收到的与ALM IN 4口输入的不一致\n");
						USERDATA->AppendComDisp(_T("ALM OUT 4口接收到的与ALM IN 4口输入的不一致\n"));
						break;
					}
				case 4:
					{
						LOGEVENT("ALM OUT 5口接收到的与ALM IN 5口输入的不一致\n");
						USERDATA->AppendComDisp(_T("ALM OUT 5口接收到的与ALM IN 5口输入的不一致\n"));
						break;
					}
				case 5:
					{
						LOGEVENT("ALM OUT 6口接收到的与ALM IN 6口输入的不一致\n");
						USERDATA->AppendComDisp(_T("ALM OUT 6口接收到的与ALM IN 6口输入的不一致\n"));
						break;
					}
				case 6:
					{
						LOGEVENT("ALM OUT 7口接收到的与ALM IN 7口输入的不一致\n");
						USERDATA->AppendComDisp(_T("ALM OUT 7口接收到的与ALM IN 7口输入的不一致\n"));
						break;
					}
				case 7:
					{
						LOGEVENT("ALM OUT 8口接收到的与ALM IN 8口输入的不一致\n");
						USERDATA->AppendComDisp(_T("ALM OUT 8口接收到的与ALM IN 8口输入的不一致\n"));
						break;
					}
				default:
					break;
				}
			}
		}
		TCnProduceTestMsg *pMsg = new TCnProduceTestMsg;
		pMsg->m_bProduceTestReult = tCnProduceTestMsg.m_bProduceTestReult;
		NOTIFY( EV_DVC_RESULT,pMsg );
	}
}


IMsgQueMngr* CMsgQueMngr::Clone()
{
	return new CMsgQueMngr( *this );
}

void CMsgQueMngr::SendHeaderMsg()
{
	if ( IsEnd() )
	{
		return;
	}
	TQueMsg *pMsg = &m_vecMsgList[m_dwCurPos];
	//如果消息类型为“发送”，则发送
	if( pMsg->emMsgType == emMsgOut) 
	{
		//发送消息
		SendMsg( pMsg->dwMsgId, pMsg->achMsgBody, sizeof(pMsg->achMsgBody) );
		LOGEVENT("[msg][out]%s\n", pMsg->strMsgDiscription.c_str() );
		m_dwCurPos++;	
	}
}


void CMsgQueMngr::Restore()
{
	if ( m_dwCurPos != 0 )
	{
		m_dwCurPos = 0;
	}
}

void CMsgQueMngr::Print()
{
	for( u32 dwIdx = 0; dwIdx < m_vecMsgList.size(); dwIdx++ )
	{
		TQueMsg *pMsg = &m_vecMsgList[dwIdx];
		String strType = ( pMsg->emMsgType == emMsgIn ) ? "In" : "Out";
		LOGEVENT( "\tMsgType:%s\tDescription:%s",strType.c_str(), pMsg->strMsgDiscription.c_str() );
		if ( m_dwCurPos == dwIdx )
		{
			LOGEVENT(" ←");
		}
		LOGEVENT("\n");
	}
	LOGEVENT("\n");
}

/*====================================================================
函 数 名： NetToHostMsg
功    能： 网络字节序转换为本机字节序
算法实现： 
全局变量： 
参    数： TCnProduceTestMsg
返 回 值： void
--------------------------------------------------------------------
修改记录：
日  期		版本		修改人		走读人    修改内容
2013/05/30  1.0		    吴蒨蒨                  创建
======================================================================*/
void CMsgQueMngr::NetToHostMsg( TCnProduceTestMsg &tTestMsg )
{
	for( u8 byChanId = 0; byChanId < MT_MAX_E1UNIT_NUM; byChanId++ )
	{
		tTestMsg.m_adwDstIp[byChanId] = ntohl(tTestMsg.m_adwDstIp[byChanId]);
		tTestMsg.m_adwLocalIp[byChanId] = ntohl(tTestMsg.m_adwLocalIp[byChanId]);
	}
	tTestMsg.m_bProduceTestReult = ntohl( tTestMsg.m_bProduceTestReult );
	tTestMsg.m_bProduceTestStart = ntohl( tTestMsg.m_bProduceTestStart );
	tTestMsg.m_byErrorReason = ntohl( tTestMsg.m_byErrorReason );
	tTestMsg.m_emProduceTestType = (EmProducetestType)ntohl( tTestMsg.m_emProduceTestType );
	tTestMsg.m_wVersionNum = ntohs( tTestMsg.m_wVersionNum );
}

void CMsgQueMngr::InitCannonTestResultMsg( const TObMsg &ObMsg )
{
	//u8 abyTemp[sizeof(TCnProduceTestMsg) + sizeof(float)];
	if ( 0 == s_byIndex )
	{
		memset(s_adwMainOutVol, 0, sizeof(u32) * 10);
	}
	u32 dwAudioVoice = 0;
	memcpy( &dwAudioVoice, ObMsg.content + sizeof(TCnProduceTestMsg), sizeof(u32) );
	dwAudioVoice = ntohl(dwAudioVoice);
	//memcpy( &m_bMainOutVol[s_byIndex], &dwAudioPower, sizeof(u32) );
	s_adwMainOutVol[s_byIndex] = dwAudioVoice;

	LOGEVENT( "s_adwMainOutVol[%d]:%d\n",s_byIndex, s_adwMainOutVol[s_byIndex] );
	s_byIndex++;
//	LOGEVENT("111111   %d\n", s_byIndex);
// 	TCnProduceTestMsg tCnProduceTestMsg;
// 	memset( &tCnProduceTestMsg, 0, sizeof(TCnProduceTestMsg) );
// 	memcpy( &tCnProduceTestMsg, abyTemp, sizeof(tCnProduceTestMsg) );
// 	NetToHostMsg( tCnProduceTestMsg ); 
	if ( s_byIndex < 10 )
	{		
		NOTIFY( EV_DVC_SHOWBTN );
	}	
	if ( 10 == s_byIndex )
	{
		for(u8 byIndex = 0; byIndex < s_byIndex; byIndex++)
		{
			LOGEVENT("第 %d 测试结果为：%d\n", byIndex, s_adwMainOutVol[byIndex]);
			if ( s_adwMainOutVol[byIndex] == 0  )
			{
				s_byMainOutIndex++;
				LOGEVENT("第%d次进 \n",s_byMainOutIndex);
				if ( s_byMainOutIndex == 10 )
				{
					m_bZeroCannonResult = TRUE;
					break;
				}
			}
		}
		CalAverageValue();
		s_byIndex = 0;
	}
}

void CMsgQueMngr::CalAverageValue()
{
	u32 Sum = 0;
	int TestNum = s_byIndex;
	for( int i = 0; i < TestNum; i++ )
	{
		Sum += s_adwMainOutVol[i];
	}
	float Agv = (float)Sum/TestNum;

	m_bTestResult = TRUE;

	for( int Index =0; Index < TestNum; Index++ )
	{
		float Compare = (float)s_adwMainOutVol[Index]- Agv;
		float FinalResult = Compare/Agv ;

		if ( abs(FinalResult) > 0.01 || m_bZeroCannonResult )
		{
			m_bTestResult = FALSE;
			break;
		}
	}

	TCnProduceTestMsg *pMsg = new TCnProduceTestMsg;
	pMsg->m_bProduceTestReult = m_bTestResult;
	NOTIFY( EV_DVC_RESULT,pMsg );
}

void CMsgQueMngr::InitMainOutTestResultMsg( const TObMsg &ObMsg )
{
	u32 dwCannonVoice = 0;
	memcpy( &dwCannonVoice, ObMsg.content + sizeof(TCnProduceTestMsg), sizeof(u32) );
	dwCannonVoice = ntohl(dwCannonVoice);
//	LOGEVENT("0000000     %d\n", dwCannonVoice);
	s_adwCannonOutVol[s_byIndex] = dwCannonVoice;
	LOGEVENT( "s_adwCannonOutVol[%d]:%d\n",s_byIndex, s_adwCannonOutVol[s_byIndex] );
	s_byIndex++;
//	LOGEVENT("111111   %d\n", s_byIndex);
	if ( s_byIndex < 6 )
	{		
		NOTIFY( EV_DVC_SHOWBTN );
	}	
	if ( 6 == s_byIndex )
	{
		for(u8 byIndex = 0; byIndex < s_byIndex; byIndex++)
		{
			LOGEVENT("第 %d 测试结果为：%d\n", byIndex, s_adwCannonOutVol[byIndex]);
			if ( s_adwCannonOutVol[byIndex] == 0  )
			{
				s_byCannonIndex++;
				LOGEVENT("第%d次进 \n",s_byCannonIndex);
				if ( s_byCannonIndex == 6 )
				{
					m_bZeroMainOutResult = TRUE;
					break;
				}
			}
		}
		CalMainoutAverageValue();
		s_byIndex = 0;
	}	
}

void CMsgQueMngr::CalMainoutAverageValue()
{
	u32 Sum = 0;
	int TestNum = s_byIndex;
	for( int i = 0; i < TestNum; i++ )
	{
		Sum += s_adwCannonOutVol[i];
	}
	float Agv = (float)Sum/TestNum;
	
	m_bTestResult = TRUE;
	
	for( int Index =0; Index < TestNum; Index++ )
	{
		float Compare = (float)s_adwCannonOutVol[Index]- Agv;
		float FinalResult = Compare/Agv ;
		
		if ( abs(FinalResult) > 0.01 || m_bZeroMainOutResult )
		{
			m_bTestResult = FALSE;
			break;
		}
	}
	
	TCnProduceTestMsg *pMsg = new TCnProduceTestMsg;
	pMsg->m_bProduceTestReult = m_bTestResult;
	NOTIFY( EV_DVC_RESULT,pMsg );	
}

void CMsgQueMngr::DataClear()
{
	if ( s_byIndex != 0 )
	{
		s_byIndex = 0;
	}
}

void CMsgQueMngr::InitRSFirstTestResultMsg( const TObMsg &ObMsg )
{
	BOOL abResult[3] = { TRUE };
	u8 abyTemp[sizeof(TCnProduceTestMsg) + 3 * sizeof(BOOL)];
	memcpy( &abyTemp, ObMsg.content, sizeof(abyTemp) );
	TCnProduceTestMsg tCnProduceTestMsg;
	memset( &tCnProduceTestMsg, 0, sizeof(TCnProduceTestMsg) );
	memcpy( &tCnProduceTestMsg, abyTemp, sizeof(tCnProduceTestMsg) );
	NetToHostMsg( tCnProduceTestMsg );
	u8 byIndex = 0;
	for ( byIndex = 0; byIndex < 3; byIndex++ )
	{
		memcpy( &abResult[byIndex], abyTemp+sizeof(tCnProduceTestMsg)+sizeof(BOOL)*byIndex, sizeof(BOOL) );
		abResult[byIndex] = ntohl(abResult[byIndex]);
	}
	LOGEVENT("收到的测试项结果为:%d\n", tCnProduceTestMsg.m_bProduceTestReult );
	if ( tCnProduceTestMsg.m_bProduceTestReult == TRUE )
	{
		TCnProduceTestMsg *pMsg = new TCnProduceTestMsg;
		pMsg->m_bProduceTestReult = tCnProduceTestMsg.m_bProduceTestReult;
		NOTIFY( EV_DVC_RESULT,pMsg );
		LOGEVENT("已将正确结果反馈至界面\n");
		m_dwCurPos++;
		SendHeaderMsg();
	}
	else
	{
		for ( byIndex = 0; byIndex < 3; byIndex++ )
		{
			if (abResult[byIndex] == FALSE)
			{
				switch ( byIndex )
				{
				case 0:
					{
						LOGEVENT("CAM300与CAMPTZ硬环回串口功能测试失败\n");
						USERDATA->AppendComDisp(_T("CAM300与CAMPTZ硬环回串口功能测试失败\n"));
						break;
					}
				case 1:
					{
						LOGEVENT("DISP 1与DISP 2硬环回串口功能测试失败\n");
						USERDATA->AppendComDisp(_T("DISP 1与DISP 2硬环回串口功能测试失败\n"));
						break;
					}
				case 2:
					{
						LOGEVENT("DISP 3与DOCCam硬环回串口功能测试失败\n");
						USERDATA->AppendComDisp(_T("DISP 3与DOCCam硬环回串口功能测试失败\n"));
						break;
					}
				default:
					break;
				}
			}
			
		}
		TCnProduceTestMsg *pMsg = new TCnProduceTestMsg;
		pMsg->m_bProduceTestReult = tCnProduceTestMsg.m_bProduceTestReult;
		NOTIFY( EV_DVC_RESULT,pMsg );
	}
}

void CMsgQueMngr::InitRSSecTestResultMsg( const TObMsg &ObMsg )
{
	BOOL abResult[2] = { TRUE };
	u8 abyTemp[sizeof(TCnProduceTestMsg) + 2 * sizeof(BOOL)];
	memcpy( &abyTemp, ObMsg.content, sizeof(abyTemp) );
	TCnProduceTestMsg tCnProduceTestMsg;
	memset( &tCnProduceTestMsg, 0, sizeof(TCnProduceTestMsg) );
	memcpy( &tCnProduceTestMsg, abyTemp, sizeof(tCnProduceTestMsg) );
	NetToHostMsg( tCnProduceTestMsg );
	u8 byIndex = 0;
	for ( byIndex = 0; byIndex < 2; byIndex++ )
	{
		memcpy( &abResult[byIndex], abyTemp+sizeof(tCnProduceTestMsg)+sizeof(BOOL)*byIndex, sizeof(BOOL) );
		abResult[byIndex] = ntohl(abResult[byIndex]);
	}
	LOGEVENT("收到的测试项结果为:%d\n", tCnProduceTestMsg.m_bProduceTestReult );
	if ( tCnProduceTestMsg.m_bProduceTestReult == TRUE )
	{
		TCnProduceTestMsg *pMsg = new TCnProduceTestMsg;
		pMsg->m_bProduceTestReult = tCnProduceTestMsg.m_bProduceTestReult;
		NOTIFY( EV_DVC_RESULT,pMsg );
		LOGEVENT("已将正确结果反馈至界面\n");
		m_dwCurPos++;
		SendHeaderMsg();
	}
	else
	{
		for ( byIndex = 0; byIndex < 2; byIndex++ )
		{
			if (abResult[byIndex] == FALSE)
			{
				switch ( byIndex )
				{
				case 0:
					{
						LOGEVENT("DOCCam与COM 1硬环回串口功能测试失败\n");
						USERDATA->AppendComDisp(_T("DOCCam与COM 1硬环回串口功能测试失败\n"));
						break;
					}
				case 1:
					{
						LOGEVENT("COM 2与COM 3硬环回串口功能测试失败\n");
						USERDATA->AppendComDisp(_T("COM 2与COM 3硬环回串口功能测试失败\n"));
						break;
					}
				default:
					break;
				}
			}
			
		}
		TCnProduceTestMsg *pMsg = new TCnProduceTestMsg;
		pMsg->m_bProduceTestReult = tCnProduceTestMsg.m_bProduceTestReult;
		NOTIFY( EV_DVC_RESULT,pMsg );
	}
}
