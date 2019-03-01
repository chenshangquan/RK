#include "stdafx.h"
#include "OspInstance.h"
#define CPYMSG( a, b ) a.srcnode = b->srcnode;\
					a.content = b->content;\
					a.dstid = b->dstid;\
					a.srcid = b->srcid;\
					a.dstnode = b->dstnode;\
					a.event = b->event;\
					a.length = b->length;

COspInstance::COspInstance()
{

}

COspInstance::~COspInstance()
{

}
#define EXCEPTION_FILE_PATH _T("exception.log")
void COspInstance::InstanceEntry( CMessage *const pMsg)
{
	IOspSession *pSession = IOspSessionMngr::GetSingletonPtr()->FindSession( GetAppID() );
	if ( pSession != NULL )
	{
		TObMsg ObMsg;
		CPYMSG( ObMsg, pMsg )
 		pSession->ProcMsg( ObMsg );
	}
	else
	{
		OspDisconnectTcpNode( pMsg->srcnode );
		LOGEVENT("找不到对应Session 断开该节点\n");
	}

}

