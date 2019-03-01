#include "stdafx.h"
#include "BoardFactory.h"
#include "Board.h"
#include "structdef.h"
const String CBoardFactory::strNameTag = _T( "Name" );
const String CBoardFactory::strAppIdTag = _T( "AppId" );
const String CBoardFactory::strCaseTag  = _T( "TestCase" );
const String CBoardFactory::strCfgFile  = _T( "testcfg.xml" );
const String CBoardFactory::strPreMsgTag = _T( "/PreMsg" );
const String CBoardFactory::strBrdPath = _T( "Board/" );
const s8 CBoardFactory::chSeparater = '|';
const String CBoardFactory::strModeTag = _T( "Mode" );
const String CBoardFactory::strBrdPicTag = _T( "BrdPic" );
const String CBoardFactory::strHidTag = _T( "Hid" );
const String CBoardFactory::strPidTag = _T( "Pid" );
const String CBoardFactory::strE2pFlgTag = _T( "E2promFlag" );
const String CBoardFactory::strE2pInfoTag = _T( "E2promInfo" );
const String CBoardFactory::strSysFileTag = _T( "SysFile" );
const String CBoardFactory::strEthernetCount = _T("EthernetCount");
const String CBoardFactory::strPipeLineTag = _T( "PipeLine" );
const String CBoardFactory::strEndMsgTag = _T( "/EndMsg" );
const String CBoardFactory::strRegMsgTag = _T( "RegMsg" );
const String CBoardFactory::strResMsgTag = _T("/ResMsg");	
const String CBoardFactory::strReqMsgTag = _T( "ReqMsgId" );
const String CBoardFactory::strAckMsgTag = _T( "AckMsgId" );
const String CBoardFactory::strNackMsgTag = _T( "NackMsgId" );
const String CBoardFactory::strIdTag = _T( "Id" );				
const String CBoardFactory::strDescTag = _T( "Description" );
const String CBoardFactory::strBrdFilePath = _T("skin/");			



CBoardFactory::CBoardFactory()
{

}

CBoardFactory::~CBoardFactory()
{

}
IBoard* CBoardFactory::CreateBoard( const String &strName )
{
	IBoard *pBoard = Find( strName );
	String strBrdFile;
	DOCMNGR->GetDoc( CBoardFactory::strCfgFile, strName, strBrdFile, CBoardFactory::strBrdPath );	//获取Board文件名
	if ( strBrdFile == "")
	{
		LOGEVENT("板卡 %s 文件名为空\n", strName.c_str() );
		return false;
	}
	else if( !CHECK_FILE_EXISTS( CBoardFactory::strBrdFilePath + strBrdFile) )
	{
		LOGEVENT("%s 文件不存在\n", strBrdFile.c_str() );
		return false;
	}
	if( pBoard == NULL )
	{
		pBoard = new CBoard();
		//属性
	    if( !GetBrdAttribute( pBoard, strBrdFile ))
		{
			delete pBoard;
			pBoard = NULL;
			return NULL;              //属性创建失败，板卡无效
		}
		Add( strName, pBoard );
	}

	return pBoard->Clone();
}

bool CBoardFactory::GetBrdAttribute( IBoard *pBoard, const String &strBrdFile )
{
	//最好先判定文件存在性
	//根节点
	DocNode RootNode = DOCMNGR->GetNode(strBrdFile);
	//Name
	String strValue = "";
	strValue = ICommonOp::GetNodeValueStr( RootNode, CBoardFactory::strNameTag );
	if( strValue == "" )
	{
		LOGEVENT("板卡名无效\n");
		return false;
	}
	pBoard->SetBrdName( strValue );
	strValue = "";
	//AppId
	u32 dwAppId = 0;
	bool bRet = ICommonOp::GetNodeValueInt( RootNode, CBoardFactory::strAppIdTag, dwAppId );
	if( bRet )
	{
		pBoard->SetAppId( dwAppId );
	}
	else 
	{
		LOGEVENT("板卡AppId无效\n");
		return false;
	}
	//PipeLine
	String strPipeLine = "";
	strPipeLine = ICommonOp::GetNodeValueStr( RootNode, CBoardFactory::strPipeLineTag );
	if ( strPipeLine != _T("") )
	{
		pBoard->SetPipeLine( strPipeLine.c_str() );
	}
	else 
	{
		LOGEVENT("板卡PipeLine无效\n");
		return false;
	}
	//SysFile
	strValue = ICommonOp::GetNodeValueStr( RootNode, CBoardFactory::strSysFileTag );
	if ( strValue != "" )
	{
		pBoard->SetSysFile( strValue.c_str() );
		strValue = "";
	}
	else 
	{
		LOGEVENT("板卡SysFile无效\n");
		return false;
	}
	//E2promFlag
	u32 dwE2promFlag = 0;
	bRet = ICommonOp::GetNodeValueInt( RootNode, CBoardFactory::strE2pFlgTag, dwE2promFlag );
	if ( bRet )
	{
		pBoard->SetE2promFlag( dwE2promFlag );
	}
	else 
	{
		LOGEVENT("板卡Eprom Flag无效\n");
		return false;
	}
	//E2promInfo
	u32 dwE2promInfo = 0;
	bRet = ICommonOp::GetNodeValueInt( RootNode, CBoardFactory::strE2pInfoTag, dwE2promInfo );
	if ( bRet )
	{
		pBoard->SetE2promInfo( dwE2promInfo );
	}
	else 
	{
		LOGEVENT("板卡E2prom Info无效\n");
		return false;
	}
	//Pid
	u32 dwPid = 0;
	bRet = (u16)ICommonOp::GetNodeValueInt( RootNode, CBoardFactory::strPidTag, dwPid );
	if ( bRet )
	{
		pBoard->SetPid( (u16)dwPid );
	}
	else 
	{
		LOGEVENT("板卡Pid无效\n");
		return false;
	}
	//Hid
	u32 dwHid = 0;
	bRet = (u16)ICommonOp::GetNodeValueInt( RootNode, CBoardFactory::strHidTag, dwHid );
	if ( bRet )
	{
		pBoard->SetHid( (u16)dwHid );
	}
	else 
	{
		LOGEVENT("板卡Hid无效\n");
		return false;
	}
	//BrPic
	strValue = ICommonOp::GetNodeValueStr( RootNode, CBoardFactory::strBrdPicTag );
	if ( strValue != "" )
	{
		pBoard->SetBrdPic( strValue );
		strValue = "";
	}
	else
	{
		LOGEVENT("板卡BrdPic无效\n");
		return false;
	}
	//EthernetCount
	u32 dwEthernetCount = 0;
	bRet = ICommonOp::GetNodeValueInt( RootNode, CBoardFactory::strEthernetCount, dwEthernetCount );
	if ( bRet )
	{
		pBoard->SetEthernetCount( dwEthernetCount );
	}
	else 
	{
		LOGEVENT("板卡网卡数量配置无效\n");
		return false;
	}

	//RegMsg
	TBrdRegMsg RegMsg;
	DocNode subNode = DOCMNGR->GetNode( strBrdFile, CBoardFactory::strRegMsgTag );
	if( !subNode.IsValid() )
	{
		LOGEVENT("注册消息配置无效\n");
		return NULL;
	}
	u32 dwValue;
	if( ICommonOp::GetNodeValueInt( subNode, CBoardFactory::strReqMsgTag, dwValue) )
	{
		RegMsg.dwRegMsgId = dwValue ;
	}
	else
	{
		LOGEVENT("板卡注册消息无效\n");
		return false;
	}
	
	if( ICommonOp::GetNodeValueInt( subNode, CBoardFactory::strAckMsgTag, dwValue) )
	{
		RegMsg.dwAckMsgId = dwValue;
	}
	else
	{
		LOGEVENT("板卡同意消息无效\n");
		return false;
	}

	if( ICommonOp::GetNodeValueInt( subNode, CBoardFactory::strNackMsgTag, dwValue) )
	{
		RegMsg.dwNackMsgId = dwValue;
	}
	else
	{
		LOGEVENT("板卡拒绝消息无效\n");
		return false;
	}
	pBoard->SetRegMsg( RegMsg );

	return true;

}


bool CBoardFactory::GetBrdTestCase( IBoard *pBoard )
{
	
	LOGEVENT("板卡%s 加载测试项\n", pBoard->GetBrdName().c_str() );
	String strBrdFile = "";
	//获取Board文件名
	DOCMNGR->GetDoc( CBoardFactory::strCfgFile, pBoard->GetBrdName(), strBrdFile, CBoardFactory::strBrdPath );	
	if( strBrdFile == "" )
	{
		LOGEVENT("无法找到文件名 %s 对应的文件\n", pBoard->GetBrdName().c_str() );
		return false;
	}
	else if ( !CHECK_FILE_EXISTS( CBoardFactory::strBrdFilePath + strBrdFile) )
	{
		LOGEVENT("%s 文件不存在\n", strBrdFile.c_str() );
		return false;
	}
	//Mode节点
	DocNode Node = DOCMNGR->GetNode( strBrdFile, CBoardFactory::strModeTag );
	//子节点
	Node = Node.GetChild();
	String strTestCase = "";
	String strModeDesc = "";

	while ( Node.IsValid() )
	{
		u32 dwModeId;
		if( !ICommonOp::GetNodeValueInt( Node, CBoardFactory::strIdTag, dwModeId ) )
		{
			LOGEVENT("获取模式ID失败\n");
			return false;
		}
		//如果是这种模式
		if ( (u8)dwModeId == pBoard->GetMode() )
		{
			strTestCase = ICommonOp::GetNodeValueStr( Node, CBoardFactory::strCaseTag );
			strModeDesc =  ICommonOp::GetNodeValueStr( Node, CBoardFactory::strDescTag );
			break;
		}
		Node = Node.GetSibling();
	}
	if ( !Node.IsValid() )
	{
		LOGEVENT("无效的板卡模式\n");
	}
	pBoard->SetBrdDesc( strModeDesc );
	//没有测试项
	if ( strTestCase == "" )
	{
		return false;
	}

	stringstream ssTestCase( strTestCase );	
	String strSingleCase;
	//创建测试项
	ITestCaseContainer *pContainer = pBoard->GetCaseContainer();
	pContainer->RemoveAll();
	while( getline( ssTestCase, strSingleCase, CBoardFactory::chSeparater ) )   
	{
		ITestCase *pTestCase = ITestCaseFactory::GetSingletonPtr()->CreateTestCase( strSingleCase );
		if(pTestCase != NULL)
		{
			pContainer->AddTestCase( pTestCase );
			pBoard->AddOb( pTestCase );
		}
		else
		{
			LOGEVENT( "测试项 %s创建失败\n", strSingleCase.c_str() );
			delete pTestCase;
			pTestCase = NULL;
			return false;
		}
	}
	LOGEVENT("板卡%s 加载测试项成功\n", pBoard->GetBrdName().c_str() );
	return true;
}

bool CBoardFactory::GetBrdMsgQue( IBoard *pBoard )
{
	pBoard->ClearMsgQue();
	LOGEVENT("板卡%s 加载消息队列\n", pBoard->GetBrdName().c_str() );
	String strBrdFile;
	//获取Board文件名
	DOCMNGR->GetDoc( CBoardFactory::strCfgFile, pBoard->GetBrdName(), strBrdFile, CBoardFactory::strBrdPath );	
	if( strBrdFile == "" )
	{
		LOGEVENT("无法找到文件名 %s 对应的文件", pBoard->GetBrdName().c_str() );
		return false;
	}
	else if ( !CHECK_FILE_EXISTS( CBoardFactory::strBrdFilePath + strBrdFile) )
	{
		LOGEVENT("%s 文件不存在\n", strBrdFile.c_str() );
		return false;
	}
	//Mode节点
	DocNode Node = DOCMNGR->GetNode( strBrdFile, CBoardFactory::strModeTag );
	//子节点
	Node = Node.GetChild();
	String strTestCase = "";
	String strModeDesc = "";
	while ( Node.IsValid() )
	{
		u32 dwModeId;
		if( !ICommonOp::GetNodeValueInt( Node, CBoardFactory::strIdTag, dwModeId ) )
		{
			LOGEVENT("获取模式ID失败\n");
			return false;
		}
		//如果是这种模式
		if ( (u8)dwModeId == pBoard->GetMode() )
		{
			break;
		}
		Node = Node.GetSibling();
	}

	if ( !Node.IsValid() )
	{
		LOGEVENT("无效的板卡模式\n");
		return false;
	}
	String strNodeName = Node.GetName();
	strNodeName = _T("Mode/") + strNodeName;
	//准备消息队列
	IMsgQueMngr	*pPreQue = IMsgQueFactory::GetSingletonPtr()->\
		CreateMsgQue( strBrdFile, strNodeName + CBoardFactory::strPreMsgTag );
	if ( pPreQue != NULL )
	{
		pBoard->SetPreMsgQue( pPreQue );
		pBoard->AddOb( pPreQue );
	}
	else
	{
		LOGEVENT( "板卡准备消息队列创建失败\n" );
		return false;
	}
	//结束消息队列
	IMsgQueMngr	*pEndQue = IMsgQueFactory::GetSingletonPtr()->\
		CreateMsgQue( strBrdFile, strNodeName + CBoardFactory::strEndMsgTag );
	if ( pEndQue != NULL )
	{
		pBoard->SetEndMsgQue( pEndQue );
		pBoard->AddOb( pEndQue );
	}
	else
	{
		LOGEVENT("板卡结束消息队列创建失败\n");
		return false;
	}
	//恢复出厂设置消息队列
	IMsgQueMngr	*pResQue = IMsgQueFactory::GetSingletonPtr()->\
		CreateMsgQue( strBrdFile, strNodeName + CBoardFactory::strResMsgTag );
	if ( pResQue != NULL )
	{
		pBoard->SetResMsgQue( pResQue );
		pBoard->AddOb( pResQue );
	}
	else
	{
		LOGEVENT("板卡恢复消息队列创建失败\n");
		return false;
	}
	LOGEVENT("板卡%s 加载消息队列成功\n", pBoard->GetBrdName().c_str() );
	return true;
}