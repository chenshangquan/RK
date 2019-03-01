#include "stdafx.h"
#include "MsgQueFactory.h"
#include "MsgQueMngr.h"

const String CMsgQueFactory::strDescTag = _T( "Description" );
const String CMsgQueFactory::strMsgBodyTag = _T( "MsgBody" );
const String CMsgQueFactory::strMsgIdTag = _T( "MsgId" );
const String CMsgQueFactory::strTypeTag = _T( "type" );
const String CMsgQueFactory::strTypeValIn = _T( "In" );
const String CMsgQueFactory::strTypeValOut = _T( "Out" );
const String CMsgQueFactory::strValueTag = _T( "Value" );
const String CMsgQueFactory::strItemTypeU8 = _T( "u8" );
const String CMsgQueFactory::strItemTypeU16 = _T( "u16" );
const String CMsgQueFactory::strItemTypeU32 = _T( "u32" );
const String CMsgQueFactory::strItemTypeEmpty = _T("empty");






CMsgQueFactory* CMsgQueFactory::m_pThis = NULL;
CMsgQueFactory::CMsgQueFactory()
{

}
CMsgQueFactory::~CMsgQueFactory()
{
	
}
IMsgQueMngr* CMsgQueFactory::CreateMsgQue( String strFileName, String strNodePath )
{
	IMsgQueMngr *pMsgQue = Find( strFileName + strNodePath );
	if( pMsgQue == NULL )
	{
		LOGEVENT("消息队列:%s\n", strNodePath.c_str() );
		pMsgQue = new CMsgQueMngr();
		DocNode Node = DOCMNGR->GetNode( strFileName, strNodePath );
		//没有配置这个节点，返回一个空的消息队列
		if( !Node.IsValid() )
		{
			LOGEVENT("消息队列为空\n");
			return pMsgQue;
		}
		Node = Node.GetChild();          //Msg节点
		//拿到一条消息
		while( Node.IsValid() )
		{
			LOGEVENT("新的消息:");
			TQueMsg *pMsg = new TQueMsg;
			memset( pMsg, 0, sizeof(TQueMsg) );
			/*生成属性*/
			String strMsgType = ICommonOp::GetNodeValueStr( Node, CMsgQueFactory::strTypeTag );
			//消息类型
			if( strMsgType == strTypeValIn )
			{
				pMsg->emMsgType = emMsgIn;
			}
			else if ( strMsgType == strTypeValOut )
			{
				pMsg->emMsgType = emMsgOut;
			}
			else
			{
				delete pMsgQue;
				return 0;                     //无效消息类型
			}
			//消息Id
			u32 dwValue;
			if( !ICommonOp::GetNodeValueInt( Node, CMsgQueFactory::strMsgIdTag, dwValue ) )
			{
 				delete pMsgQue;
				pMsgQue = NULL;
				return NULL;                      //必须要有MsgId
			}
			pMsg->dwMsgId = dwValue;
			LOGEVENT("[%d]",dwValue);
			//消息描述
			String strMsgDis = ICommonOp::GetNodeValueStr( Node, CMsgQueFactory::strDescTag );
			pMsg->strMsgDiscription = strMsgDis;

			//创建消息体
			DocNode subNode = Node.GetChild( CMsgQueFactory::strMsgBodyTag.c_str() );     //MsgBody节点
			//没有消息体
			if ( !subNode.IsValid() )
			{
				Node = Node.GetSibling();
				pMsgQue->AddMsg( *pMsg );							//添加消息
				continue;
			}
			subNode = subNode.GetChild();              //Item节点
			u8 achBuf[MAX_MSG_BODY_LEN];
			memset( achBuf, 0, sizeof(achBuf) );
			u32 dwBufLen = NULL;
			//创建消息体
			while( subNode.IsValid() )
			{
				String strItemType = ICommonOp::GetNodeValueStr( subNode, CMsgQueFactory::strTypeTag );
				u32 dwItemValue = 0;
				bool bRet = ICommonOp::GetNodeValueInt( subNode, CMsgQueFactory::strValueTag, dwItemValue ); 
				//类型和值都有效
				if( strItemType != _T("") && bRet )        
				{
					if( strItemType == CMsgQueFactory::strItemTypeU8 )
					{
						memcpy( achBuf + dwBufLen, &dwItemValue, sizeof( u8 ) );
						dwBufLen = dwBufLen + sizeof( u8 );
					}
					else if( strItemType == CMsgQueFactory::strItemTypeU16 )
					{
						memcpy( achBuf + dwBufLen, &dwItemValue, sizeof( u16 ) );
						dwBufLen = dwBufLen + sizeof( u16 );	
					}
					else if( strItemType == CMsgQueFactory::strItemTypeU32 )
					{
						memcpy( achBuf + dwBufLen, &dwItemValue, sizeof( u32 ) );
						dwBufLen = dwBufLen + sizeof( u32 );
					}
					else if( strItemType ==CMsgQueFactory::strItemTypeEmpty )
					{
						u32 dwVal = dwItemValue;
						memset( achBuf + dwBufLen, 0, dwVal*sizeof(u8) );
						dwBufLen = dwBufLen + dwVal;
					}
					else
					{
						//unknow type
						delete pMsgQue;
						pMsgQue = NULL;
						return NULL;
					}
				}
				else
				{
					//cfg err.
					delete pMsgQue;
					pMsgQue = NULL;
					return NULL;
				}
				subNode = subNode.GetSibling();                //下一个
			}//消息体
			LOGEVENT("[消息体]");
			TCnProduceTestMsg tProducetestMsg;
			memset(&tProducetestMsg, 0, sizeof(TCnProduceTestMsg));
			tProducetestMsg.m_wVersionNum = *(u16*)achBuf;
			tProducetestMsg.m_emProduceTestType = (EmProducetestType)*(u32*)( achBuf + sizeof(u16) );
			tProducetestMsg.m_bProduceTestStart = *(u32*)( achBuf + sizeof(u16) + sizeof(u32) );
			//memcpy(&tProducetestMsg.m_wVersionNum, achBuf, sizeof(u16));
			//memcpy(&tProducetestMsg.m_emProduceTestType, achBuf + sizeof(u16), sizeof(EmProducetestType));
			//memcpy(&tProducetestMsg.m_bProduceTestStart, achBuf + sizeof(u16) + sizeof(EmProducetestType), sizeof(BOOL));
			//memcpy( pMsg->achMsgBody, achBuf, dwBufLen );
			m_tProducetestMsg = tProducetestMsg;
			HostToNetMsg( m_tProducetestMsg );
			memcpy(pMsg->achMsgBody, &m_tProducetestMsg, sizeof(TCnProduceTestMsg));
			pMsgQue->AddMsg( *pMsg );							//添加消息
			LOGEVENT("[OK]\n");
			Node = Node.GetSibling();
		}//消息
		Add( strFileName + strNodePath, pMsgQue );
		LOGEVENT("保存队列\n");
	}
	IMsgQueMngr *pQue = pMsgQue->Clone();
	LOGEVENT("消息队列创建成功\n");
	return pQue;
}

TCnProduceTestMsg CMsgQueFactory::GetSurProduceTestMsg()
{
	return m_tProducetestMsg;
}

CMsgQueFactory* CMsgQueFactory::GetMsgQuePtr()
{
	if ( NULL != m_pThis )
	{
		return m_pThis;
	}
	m_pThis	= new CMsgQueFactory;
	
	return m_pThis;		
}

/*====================================================================
函 数 名： HostToNetMsg
功    能： 本机字节序转换为网络字节序
算法实现： 
全局变量： 
参    数： TCnProduceTestMsg
返 回 值： void
--------------------------------------------------------------------
修改记录：
日  期		版本		修改人		走读人    修改内容
2013/02/20  1.0		    吴蒨蒨                  创建
======================================================================*/
void CMsgQueFactory::HostToNetMsg( TCnProduceTestMsg &tTestMsg )
{
	for( u8 byChanId = 0; byChanId < MT_MAX_E1UNIT_NUM; byChanId++ )
	{
		tTestMsg.m_adwDstIp[byChanId] = htonl(tTestMsg.m_adwDstIp[byChanId]);
		tTestMsg.m_adwLocalIp[byChanId] = htonl(tTestMsg.m_adwLocalIp[byChanId]);
	}
	tTestMsg.m_bProduceTestReult = htonl( tTestMsg.m_bProduceTestReult );
	tTestMsg.m_bProduceTestStart = htonl( tTestMsg.m_bProduceTestStart );
	tTestMsg.m_byErrorReason = htonl( tTestMsg.m_byErrorReason );
	tTestMsg.m_emProduceTestType = (EmProducetestType)htonl( tTestMsg.m_emProduceTestType );
	tTestMsg.m_wVersionNum = htons( tTestMsg.m_wVersionNum );
}