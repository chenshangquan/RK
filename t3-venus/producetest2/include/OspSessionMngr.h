#ifndef _OSPSESSIONMNGR_H_
#define _OSPSESSIONMNGR_H_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class COspSessionMngr : public IOspSessionMngr, public tmplContainer<u16, IOspSession>
{
public:
	COspSessionMngr();
	~COspSessionMngr();
	virtual IOspSession* CreateSession( u16 wAppId );
	virtual IOspSession* FindSession( u16 wAppId );
	virtual bool KillSession( u16 wAppId );
};
#endif