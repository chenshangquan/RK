#include "StdAfx.h"
#include "OspSession.h"
#include "OspSessionMngr.h"

COspSessionMngr::COspSessionMngr()
{

}

COspSessionMngr::~COspSessionMngr()
{

}

IOspSession* COspSessionMngr::CreateSession( u16 wAppId )
{
	IOspSession *pSession = Find( wAppId );
	if ( pSession == NULL )
	{
		pSession = new COspSession();
		Add( wAppId, pSession );
	}
	return pSession;
}

IOspSession* COspSessionMngr::FindSession( u16 wAppId )
{
	return Find( wAppId );
}

bool COspSessionMngr::KillSession( u16 wAppId )
{
	IOspSession *pSession = Find( wAppId );
	if ( pSession != NULL )
	{
		delete pSession;
		Remove(wAppId);
		return true;
	}
	return false;
}


