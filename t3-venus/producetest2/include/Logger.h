// Logger.h: interface for the CLogger class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGGER_H__8CCFF54C_F2BB_4FDA_AC8B_DD7522FC03E3__INCLUDED_)
#define AFX_LOGGER_H__8CCFF54C_F2BB_4FDA_AC8B_DD7522FC03E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/*
	��ӡ�࣬�����ú�LOGEVENT
*/
class CLogger : public ILogger
{
public:
	CLogger();
	virtual ~CLogger();
	virtual bool LogEvent( LPCTSTR pstrFormat, ... );
};

#endif // !defined(AFX_LOGGER_H__8CCFF54C_F2BB_4FDA_AC8B_DD7522FC03E3__INCLUDED_)
