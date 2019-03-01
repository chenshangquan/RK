#include "stdafx.h"
#include "OspSession.h"
#include "tpmsg.h"

COspSession::COspSession():	m_dwDstId(0), m_dwDstNode(INVALID_NODE), m_dwLocalId(0)
{
}

COspSession::~COspSession()
{

}     

void COspSession::ProcMsg( const TObMsg &msg )
{
	LOGEVENT("RCV MSG:Node:%d    Event:%d\n", msg.srcnode, msg.event );
	//保存地址信息

	if ( m_dwDstNode != msg.srcnode )
	{
		m_dwDstNode = msg.srcnode;
		u16 wAppId = ( msg.dstid - DEFAULT_INS_ID )>>16;
		OspSetHBParam( msg.srcnode, 5, 2 );	//10秒
		OspNodeDiscCBRegQ( msg.srcnode, wAppId, DEFAULT_INS_ID );
	}
	//特殊消息处理
	switch ( msg.event )
	{
	case OSP_DISCONNECT:
		Ondisconnect();
		return;
	default:
		break;
	}
	//广播消息
	ObList::iterator begin = m_observers.begin();
	while ( begin != m_observers.end() )
	{
		IOspOb *pOb = *begin;
		if ( pOb != 0 )
		{
			pOb->ProcMsg( msg );
		}
		begin++;
	}
}

bool COspSession::SendMsg( u16 wEvent, u8 *pContent, u16 wLen )
{
	LOGEVENT("SND MSG:Node:%d    Id:%d\n", m_dwDstNode, wEvent );
	if ( wEvent == OSP_DISCONNECT )
	{
		return ::OspDisconnectTcpNode( m_dwDstNode );
	}
	return ::OspPost( m_dwDstId, wEvent, pContent, wLen, m_dwDstNode, m_dwLocalId );
	//return::OspPost(MAKEIID(AID_PRODUCETEST_APP, 1), wEvent, pContent, wLen, 0);
}

void COspSession::Ondisconnect()
{
	//通知界面
	NOTIFY( EV_DVC_DISCONNECT );
}

bool COspSession::SetAddrInfo( const u32 &dwLocalId, const u32 &dwDstId )
{
	m_dwLocalId = dwLocalId;
	m_dwDstId = dwDstId;
	return true;
}
