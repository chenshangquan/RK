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
		LOGEVENT("��Ϣ����:%s\n", strNodePath.c_str() );
		pMsgQue = new CMsgQueMngr();
		DocNode Node = DOCMNGR->GetNode( strFileName, strNodePath );
		//û����������ڵ㣬����һ���յ���Ϣ����
		if( !Node.IsValid() )
		{
			LOGEVENT("��Ϣ����Ϊ��\n");
			return pMsgQue;
		}
		Node = Node.GetChild();          //Msg�ڵ�
		//�õ�һ����Ϣ
		while( Node.IsValid() )
		{
			LOGEVENT("�µ���Ϣ:");
			TQueMsg *pMsg = new TQueMsg;
			memset( pMsg, 0, sizeof(TQueMsg) );
			/*��������*/
			String strMsgType = ICommonOp::GetNodeValueStr( Node, CMsgQueFactory::strTypeTag );
			//��Ϣ����
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
				return 0;                     //��Ч��Ϣ����
			}
			//��ϢId
			u32 dwValue;
			if( !ICommonOp::GetNodeValueInt( Node, CMsgQueFactory::strMsgIdTag, dwValue ) )
			{
 				delete pMsgQue;
				pMsgQue = NULL;
				return NULL;                      //����Ҫ��MsgId
			}
			pMsg->dwMsgId = dwValue;
			LOGEVENT("[%d]",dwValue);
			//��Ϣ����
			String strMsgDis = ICommonOp::GetNodeValueStr( Node, CMsgQueFactory::strDescTag );
			pMsg->strMsgDiscription = strMsgDis;

			//������Ϣ��
			DocNode subNode = Node.GetChild( CMsgQueFactory::strMsgBodyTag.c_str() );     //MsgBody�ڵ�
			//û����Ϣ��
			if ( !subNode.IsValid() )
			{
				Node = Node.GetSibling();
				pMsgQue->AddMsg( *pMsg );							//�����Ϣ
				continue;
			}
			subNode = subNode.GetChild();              //Item�ڵ�
			u8 achBuf[MAX_MSG_BODY_LEN];
			memset( achBuf, 0, sizeof(achBuf) );
			u32 dwBufLen = NULL;
			//������Ϣ��
			while( subNode.IsValid() )
			{
				String strItemType = ICommonOp::GetNodeValueStr( subNode, CMsgQueFactory::strTypeTag );
				u32 dwItemValue = 0;
				bool bRet = ICommonOp::GetNodeValueInt( subNode, CMsgQueFactory::strValueTag, dwItemValue ); 
				//���ͺ�ֵ����Ч
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
				subNode = subNode.GetSibling();                //��һ��
			}//��Ϣ��
			LOGEVENT("[��Ϣ��]");
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
			pMsgQue->AddMsg( *pMsg );							//�����Ϣ
			LOGEVENT("[OK]\n");
			Node = Node.GetSibling();
		}//��Ϣ
		Add( strFileName + strNodePath, pMsgQue );
		LOGEVENT("�������\n");
	}
	IMsgQueMngr *pQue = pMsgQue->Clone();
	LOGEVENT("��Ϣ���д����ɹ�\n");
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
�� �� ���� HostToNetMsg
��    �ܣ� �����ֽ���ת��Ϊ�����ֽ���
�㷨ʵ�֣� 
ȫ�ֱ����� 
��    ���� TCnProduceTestMsg
�� �� ֵ�� void
--------------------------------------------------------------------
�޸ļ�¼��
��  ��		�汾		�޸���		�߶���    �޸�����
2013/02/20  1.0		    ���`�`                  ����
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