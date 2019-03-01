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
	DOCMNGR->GetDoc( CBoardFactory::strCfgFile, strName, strBrdFile, CBoardFactory::strBrdPath );	//��ȡBoard�ļ���
	if ( strBrdFile == "")
	{
		LOGEVENT("�忨 %s �ļ���Ϊ��\n", strName.c_str() );
		return false;
	}
	else if( !CHECK_FILE_EXISTS( CBoardFactory::strBrdFilePath + strBrdFile) )
	{
		LOGEVENT("%s �ļ�������\n", strBrdFile.c_str() );
		return false;
	}
	if( pBoard == NULL )
	{
		pBoard = new CBoard();
		//����
	    if( !GetBrdAttribute( pBoard, strBrdFile ))
		{
			delete pBoard;
			pBoard = NULL;
			return NULL;              //���Դ���ʧ�ܣ��忨��Ч
		}
		Add( strName, pBoard );
	}

	return pBoard->Clone();
}

bool CBoardFactory::GetBrdAttribute( IBoard *pBoard, const String &strBrdFile )
{
	//������ж��ļ�������
	//���ڵ�
	DocNode RootNode = DOCMNGR->GetNode(strBrdFile);
	//Name
	String strValue = "";
	strValue = ICommonOp::GetNodeValueStr( RootNode, CBoardFactory::strNameTag );
	if( strValue == "" )
	{
		LOGEVENT("�忨����Ч\n");
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
		LOGEVENT("�忨AppId��Ч\n");
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
		LOGEVENT("�忨PipeLine��Ч\n");
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
		LOGEVENT("�忨SysFile��Ч\n");
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
		LOGEVENT("�忨Eprom Flag��Ч\n");
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
		LOGEVENT("�忨E2prom Info��Ч\n");
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
		LOGEVENT("�忨Pid��Ч\n");
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
		LOGEVENT("�忨Hid��Ч\n");
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
		LOGEVENT("�忨BrdPic��Ч\n");
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
		LOGEVENT("�忨��������������Ч\n");
		return false;
	}

	//RegMsg
	TBrdRegMsg RegMsg;
	DocNode subNode = DOCMNGR->GetNode( strBrdFile, CBoardFactory::strRegMsgTag );
	if( !subNode.IsValid() )
	{
		LOGEVENT("ע����Ϣ������Ч\n");
		return NULL;
	}
	u32 dwValue;
	if( ICommonOp::GetNodeValueInt( subNode, CBoardFactory::strReqMsgTag, dwValue) )
	{
		RegMsg.dwRegMsgId = dwValue ;
	}
	else
	{
		LOGEVENT("�忨ע����Ϣ��Ч\n");
		return false;
	}
	
	if( ICommonOp::GetNodeValueInt( subNode, CBoardFactory::strAckMsgTag, dwValue) )
	{
		RegMsg.dwAckMsgId = dwValue;
	}
	else
	{
		LOGEVENT("�忨ͬ����Ϣ��Ч\n");
		return false;
	}

	if( ICommonOp::GetNodeValueInt( subNode, CBoardFactory::strNackMsgTag, dwValue) )
	{
		RegMsg.dwNackMsgId = dwValue;
	}
	else
	{
		LOGEVENT("�忨�ܾ���Ϣ��Ч\n");
		return false;
	}
	pBoard->SetRegMsg( RegMsg );

	return true;

}


bool CBoardFactory::GetBrdTestCase( IBoard *pBoard )
{
	
	LOGEVENT("�忨%s ���ز�����\n", pBoard->GetBrdName().c_str() );
	String strBrdFile = "";
	//��ȡBoard�ļ���
	DOCMNGR->GetDoc( CBoardFactory::strCfgFile, pBoard->GetBrdName(), strBrdFile, CBoardFactory::strBrdPath );	
	if( strBrdFile == "" )
	{
		LOGEVENT("�޷��ҵ��ļ��� %s ��Ӧ���ļ�\n", pBoard->GetBrdName().c_str() );
		return false;
	}
	else if ( !CHECK_FILE_EXISTS( CBoardFactory::strBrdFilePath + strBrdFile) )
	{
		LOGEVENT("%s �ļ�������\n", strBrdFile.c_str() );
		return false;
	}
	//Mode�ڵ�
	DocNode Node = DOCMNGR->GetNode( strBrdFile, CBoardFactory::strModeTag );
	//�ӽڵ�
	Node = Node.GetChild();
	String strTestCase = "";
	String strModeDesc = "";

	while ( Node.IsValid() )
	{
		u32 dwModeId;
		if( !ICommonOp::GetNodeValueInt( Node, CBoardFactory::strIdTag, dwModeId ) )
		{
			LOGEVENT("��ȡģʽIDʧ��\n");
			return false;
		}
		//���������ģʽ
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
		LOGEVENT("��Ч�İ忨ģʽ\n");
	}
	pBoard->SetBrdDesc( strModeDesc );
	//û�в�����
	if ( strTestCase == "" )
	{
		return false;
	}

	stringstream ssTestCase( strTestCase );	
	String strSingleCase;
	//����������
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
			LOGEVENT( "������ %s����ʧ��\n", strSingleCase.c_str() );
			delete pTestCase;
			pTestCase = NULL;
			return false;
		}
	}
	LOGEVENT("�忨%s ���ز�����ɹ�\n", pBoard->GetBrdName().c_str() );
	return true;
}

bool CBoardFactory::GetBrdMsgQue( IBoard *pBoard )
{
	pBoard->ClearMsgQue();
	LOGEVENT("�忨%s ������Ϣ����\n", pBoard->GetBrdName().c_str() );
	String strBrdFile;
	//��ȡBoard�ļ���
	DOCMNGR->GetDoc( CBoardFactory::strCfgFile, pBoard->GetBrdName(), strBrdFile, CBoardFactory::strBrdPath );	
	if( strBrdFile == "" )
	{
		LOGEVENT("�޷��ҵ��ļ��� %s ��Ӧ���ļ�", pBoard->GetBrdName().c_str() );
		return false;
	}
	else if ( !CHECK_FILE_EXISTS( CBoardFactory::strBrdFilePath + strBrdFile) )
	{
		LOGEVENT("%s �ļ�������\n", strBrdFile.c_str() );
		return false;
	}
	//Mode�ڵ�
	DocNode Node = DOCMNGR->GetNode( strBrdFile, CBoardFactory::strModeTag );
	//�ӽڵ�
	Node = Node.GetChild();
	String strTestCase = "";
	String strModeDesc = "";
	while ( Node.IsValid() )
	{
		u32 dwModeId;
		if( !ICommonOp::GetNodeValueInt( Node, CBoardFactory::strIdTag, dwModeId ) )
		{
			LOGEVENT("��ȡģʽIDʧ��\n");
			return false;
		}
		//���������ģʽ
		if ( (u8)dwModeId == pBoard->GetMode() )
		{
			break;
		}
		Node = Node.GetSibling();
	}

	if ( !Node.IsValid() )
	{
		LOGEVENT("��Ч�İ忨ģʽ\n");
		return false;
	}
	String strNodeName = Node.GetName();
	strNodeName = _T("Mode/") + strNodeName;
	//׼����Ϣ����
	IMsgQueMngr	*pPreQue = IMsgQueFactory::GetSingletonPtr()->\
		CreateMsgQue( strBrdFile, strNodeName + CBoardFactory::strPreMsgTag );
	if ( pPreQue != NULL )
	{
		pBoard->SetPreMsgQue( pPreQue );
		pBoard->AddOb( pPreQue );
	}
	else
	{
		LOGEVENT( "�忨׼����Ϣ���д���ʧ��\n" );
		return false;
	}
	//������Ϣ����
	IMsgQueMngr	*pEndQue = IMsgQueFactory::GetSingletonPtr()->\
		CreateMsgQue( strBrdFile, strNodeName + CBoardFactory::strEndMsgTag );
	if ( pEndQue != NULL )
	{
		pBoard->SetEndMsgQue( pEndQue );
		pBoard->AddOb( pEndQue );
	}
	else
	{
		LOGEVENT("�忨������Ϣ���д���ʧ��\n");
		return false;
	}
	//�ָ�����������Ϣ����
	IMsgQueMngr	*pResQue = IMsgQueFactory::GetSingletonPtr()->\
		CreateMsgQue( strBrdFile, strNodeName + CBoardFactory::strResMsgTag );
	if ( pResQue != NULL )
	{
		pBoard->SetResMsgQue( pResQue );
		pBoard->AddOb( pResQue );
	}
	else
	{
		LOGEVENT("�忨�ָ���Ϣ���д���ʧ��\n");
		return false;
	}
	LOGEVENT("�忨%s ������Ϣ���гɹ�\n", pBoard->GetBrdName().c_str() );
	return true;
}