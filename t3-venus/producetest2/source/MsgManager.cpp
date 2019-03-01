// MsgManager.cpp: implementation of the CMsgManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MsgManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

vector<IObserver*>::iterator CMsgManager::FindObserver( IObserver* pObserver )
{
	ObserverList::iterator begin = m_observers.begin();
	while ( begin != m_observers.end() )
	{
		if ( *begin == pObserver )
		{
			return begin;
		}
		begin++;
	}
	return begin;
}

void CMsgManager::AddObserver( IObserver* pObserver )
{
	ObserverList::iterator begin = FindObserver( pObserver );
	if ( begin == m_observers.end() )
	{
		m_observers.push_back( pObserver );
	}	
}

void CMsgManager::RemoveObserver( IObserver* pObserver )
{
	ObserverList::iterator begin = FindObserver( pObserver );
	if ( begin != m_observers.end() )
	{
		m_observers.erase( begin );
	}	
}

void CMsgManager::SendMsg( TMsgParam& tMsgParam )
{
	ObserverList::iterator begin = m_observers.begin();
	while ( begin != m_observers.end() )
	{
		IObserver* pObserver = *begin;
		if ( pObserver != 0 )
		{
			pObserver->Update( tMsgParam );
		}
		begin++;
	}
}