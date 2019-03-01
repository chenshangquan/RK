#include "stdafx.h"
#include "TestCaseFactory.h"
#include "TestCase.h"
const String CTestCaseFactory::strCfgFile  = _T("testcfg.xml");
const String CTestCaseFactory::strCasePath = _T("TestCase/");
const String CTestCaseFactory::strCasePathEX = _T("TestCaseEx");
const String CTestCaseFactory::strPatition = _T("/");
const s8	CTestCaseFactory::chSeparater = '|';
const String CTestCaseFactory::strTypeTag = _T("type");
const String CTestCaseFactory::strTypeMedia = _T("media");
const String CTestCaseFactory::strTypeCmd = _T("cmd");
const String CTestCaseFactory::strTypeExe = _T("exe");
const String CTestCaseFactory::strNameTag = _T("Name");
const String CTestCaseFactory::strRetestTag = _T("Retestable");
const String CTestCaseFactory::strDescTag = _T("Description");
const String CTestCaseFactory::strExeStrTag = _T("ExeString");
const String CTestCaseFactory::strCmdMsgTag = _T("CmdMsgId");			
const String CTestCaseFactory::strEncParamTag = _T( "EncoderNetParam" );	
const String CTestCaseFactory::strStrInTag = _T( "StreamIn" );			
const String CTestCaseFactory::strStrOutTag = _T( "StreamOut" );		
const String CTestCaseFactory::strPreMsgTag = _T( "PreMsg" );
const String CTestCaseFactory::strPathTag = _T( "Path" );
const String CTestCaseFactory::strEndMsgTag = _T( "EndMsg" );	
const String CTestCaseFactory::strInVidCountTag = _T( "VidCount" );
const String CTestCaseFactory::strInAudCountTag = _T( "AudCount" );
const String CTestCaseFactory::strInVidRtpTag = _T( "VidRTPPort" );
const String CTestCaseFactory::strInAudRtpTag = _T( "AudRTPPort" );
const String CTestCaseFactory::strKeyFrameMsgTag = _T( "KeyFrameMsg" );
const String CTestCaseFactory::strOutVidCountTag = _T( "VidCount" );
const String CTestCaseFactory::strOutAudCountTag = _T( "AudCount" );
const String CTestCaseFactory::strOutFileTag = _T( "file" );
const String CTestCaseFactory::strCaseFilePath = _T("skin/");




CTestCaseFactory::CTestCaseFactory()
{

}

CTestCaseFactory::~CTestCaseFactory()
{

}

ITestCase* CTestCaseFactory::CreateTestCase( const String &strName )
{
	String strCaseFile;
	DOCMNGR->GetDoc( CTestCaseFactory::strCfgFile, strName, \
		strCaseFile, CTestCaseFactory::strCasePath );	                         //获取TestCase文件名
	if ( strCaseFile == "" )
	{
		DOCMNGR->GetDoc( CTestCaseFactory::strCfgFile, strName, \
		strCaseFile, CTestCaseFactory::strCasePathEX);
		if ( strCaseFile == "" )
		{
			LOGEVENT("测试项 %s 文件名为空\n", strName.c_str() );
			return false;
		}		
	}
	else if ( !CHECK_FILE_EXISTS( CTestCaseFactory::strCaseFilePath + strCaseFile) )
	{
		LOGEVENT("%s 文件不存在\n");
		return NULL;
	}
	LOGEVENT("读取配置文件 %s\n", strCaseFile.c_str());
	String strType;
	DocNode CaseNode = DOCMNGR->GetNode( strCaseFile, strName );
	if( !CaseNode.IsValid() )
	{
		LOGEVENT("测试项文件配置错误\n");
		return NULL;
	}
	strType = ICommonOp::GetNodeValueStr( CaseNode, strTypeTag );
	if( strType == CTestCaseFactory::strTypeMedia )
	{
		return CreateMediaCase( strCaseFile, strName );
	}
	else if( strType == CTestCaseFactory::strTypeCmd )
	{
		return CreateCmdCase( strCaseFile, strName );
	}
	else if(strType == CTestCaseFactory::strTypeExe )
	{
		return CreateExeCase( strCaseFile, strName );
	}
	else 
	{
		LOGEVENT("未知测试项\n");
		return NULL;
		//unknown case
	}
	return NULL;

}

ITestCase* CTestCaseFactory::CreateMediaCase( String strCaseFile, String strName )
{
	LOGEVENT("媒体测试项\n");
	CMediaTestCase *pMediaCase = (CMediaTestCase*)Find( strCaseFile + strName );
	//容器里保存的只含参数，不包括指针
	if( pMediaCase == NULL )
	{
		pMediaCase = new CMediaTestCase();
		pMediaCase->SetType( emMediaCase );
		LOGEVENT("测试项参数\n");
		//各种属性参数
		if( !GetMediaCaseParam( pMediaCase, strCaseFile, strName ) )
		{
			delete pMediaCase;
			pMediaCase = NULL;
			return NULL;
		}
		LOGEVENT("测试项参数OK\n");
		Add( strCaseFile + strName, pMediaCase );
	}
	pMediaCase = (CMediaTestCase*)pMediaCase->Clone();
	LOGEVENT("开始配置消息队列\n");
	//消息队列
	if( !GetMediaCaseMsgQue( pMediaCase, strCaseFile, strName ))
	{
		delete pMediaCase;
		pMediaCase = NULL;
		return NULL;
	}
	return pMediaCase;

}

ITestCase* CTestCaseFactory::CreateCmdCase( String strCaseFile, String strName )
{	
	CCmdTestCase *pCmdCase =  (CCmdTestCase*)Find( strCaseFile + strName );
	if( pCmdCase == NULL )
	{
		String strPath = strName + strPatition;
		pCmdCase = new CCmdTestCase();
		pCmdCase->SetType( emCmdCase );
		//Case名
		String strCaseName = "";
		DOCMNGR->GetDoc( strCaseFile, CTestCaseFactory::strNameTag, strCaseName, strPath );
		if (strCaseName == "")
		{
			LOGEVENT( "测试项名字无效" );
			return NULL;
		}
		pCmdCase->SetCaseName( strCaseName );
		//是否可重测
		String strRetestable = "";
		DOCMNGR->GetDoc( strCaseFile, CTestCaseFactory::strRetestTag, strRetestable, strName );
		if ( strRetestable == "false")
		{
			pCmdCase->SetRetestable(false);
		}
		//Case描述
		String strCaseDesc;
		DOCMNGR->GetDoc( strCaseFile, CTestCaseFactory::strDescTag, strCaseDesc, strPath );
		pCmdCase->SetDescription( strCaseDesc );
		Add( strCaseFile + strName, pCmdCase );
	}
	pCmdCase = (CCmdTestCase*)pCmdCase->Clone();
	LOGEVENT("开始配置消息队列\n");
	//消息队列
	if( !GetCmdCaseMsgQue( pCmdCase, strCaseFile, strName ))
	{
		delete pCmdCase;
		pCmdCase = NULL;
		return NULL;
	}
	return pCmdCase;

}

ITestCase* CTestCaseFactory::CreateExeCase( String strCaseFile, String strName )
{
	CExeTestCase *pExeCase =  (CExeTestCase*)Find( strCaseFile );
	if( pExeCase == NULL )
	{
		String strPath = strName + strPatition;
		pExeCase = new CExeTestCase();		
		pExeCase->SetType( emExeCase );
		//Case名
		String strCaseName = "";
		DOCMNGR->GetDoc( strCaseFile, CTestCaseFactory::strNameTag, strCaseName, strPath );
		pExeCase->SetCaseName( strCaseName );
		//是否可重测
		String strRetestable = "";
		DOCMNGR->GetDoc( strCaseFile, CTestCaseFactory::strRetestTag, strRetestable, strName );
		if ( strRetestable == "false")
		{
			pExeCase->SetRetestable(false);
		}
		//Case描述
		String strCaseDesc;
		DOCMNGR->GetDoc( strCaseFile, CTestCaseFactory::strDescTag, strCaseDesc, strPath );
		pExeCase->SetDescription( strCaseDesc );
		//ExeString
		String strExeStr = "";
		DOCMNGR->GetDoc( strCaseFile, CTestCaseFactory::strExeStrTag, strExeStr, strPath );
		if ( strExeStr == "" )       //命令字符串不能为空
		{
			delete pExeCase;
			pExeCase = NULL;
			return NULL;
		}
		pExeCase->SetExeCmdStr( strExeStr );
		Add( strCaseFile + strNameTag, pExeCase );
	}
	return pExeCase->Clone();
}

bool CTestCaseFactory::GetMediaCaseParam( CMediaTestCase* pMediaCase, String strCaseFile, String strName  )
{
	strName += strPatition;
	//case名字
	String strCaseName = "";
	DOCMNGR->GetDoc( strCaseFile, CTestCaseFactory::strNameTag, strCaseName, strName );
	if ( strCaseName.length() == NULL)
	{
		LOGEVENT("测试项名字无效");
		return false;
	}
	pMediaCase->SetCaseName( strCaseName );
	//是否可重测
	String strRetestable = "";
	DOCMNGR->GetDoc( strCaseFile, CTestCaseFactory::strRetestTag, strRetestable, strName );
	if ( strRetestable == "false")
	{
		pMediaCase->SetRetestable(false);
	}
	//Case描述
	String strCaseDesc;
	DOCMNGR->GetDoc( strCaseFile, CTestCaseFactory::strDescTag, strCaseDesc, strName );
	pMediaCase->SetDescription( strCaseDesc );
	//媒体文件路径
	String strCasePath;
	DOCMNGR->GetDoc( strCaseFile, CTestCaseFactory::strPathTag, strCasePath, strName );
	pMediaCase->SetFilePath( strCasePath );
	return true;
}

bool CTestCaseFactory::GetMediaCaseMsgQue( CMediaTestCase* pMediaCase, String strCaseFile, String strName  )
{
	if ( pMediaCase == NULL )
	{
		LOGEVENT("测试项无效\n");
		return false;
	}
	strName += strPatition;
	//PreMsg
	IMsgQueMngr *pPreQue = IMsgQueFactory::GetSingletonPtr()->CreateMsgQue( strCaseFile,
		strName + CTestCaseFactory::strPreMsgTag );
	if( pPreQue != NULL )
	{
		LOGEVENT("准备消息队列创建成功\n");
		pMediaCase->AddOb( pPreQue );
		LOGEVENT("测试项观察者\n");
		pMediaCase->SetPreMsgQue( pPreQue );
		LOGEVENT("准备消息队列添加成功\n");

	}
	else
	{	
		LOGEVENT("测试项%s准备消息队列无效\n", strName.c_str());
		return false;
	}
	//EndMsg
	IMsgQueMngr *pEndQue = IMsgQueFactory::GetSingletonPtr()->CreateMsgQue(  strCaseFile,
		strName + CTestCaseFactory::strEndMsgTag  );
	if( pEndQue != NULL )
	{
		LOGEVENT("结束消息队列创建成功\n");
		pMediaCase->AddOb( pEndQue );
		pMediaCase->SetEndMsgQue( pEndQue );
	}
	else
	{
		LOGEVENT("测试项%s结束消息队列无效\n", strName.c_str());
		return false;
	}
	return true;
}

bool CTestCaseFactory::GetCmdCaseMsgQue( CCmdTestCase* pCmdCase, String strCaseFile, String strName )
{
	if ( pCmdCase == NULL )
	{
		LOGEVENT("测试项无效\n");
		return false;
	}
	strName += strPatition;
	//PreMsg
	IMsgQueMngr *pPreQue = IMsgQueFactory::GetSingletonPtr()->CreateMsgQue( strCaseFile,
		strName + CTestCaseFactory::strPreMsgTag );
	if( pPreQue != NULL )
	{
		LOGEVENT("准备消息队列创建成功\n");
		pCmdCase->AddOb( pPreQue );
		LOGEVENT("测试项观察者\n");
		pCmdCase->SetPreMsgQue( pPreQue );
		LOGEVENT("准备消息队列添加成功\n");
		
	}
	else
	{	
		LOGEVENT("测试项%s准备消息队列无效\n", strName.c_str());
		return false;
	}
	return true;
}