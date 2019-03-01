// DocManager.h: interface for the CDocManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOCMANAGER_H__C8280F2F_CBC4_4C18_B4AC_D8900ADB767D__INCLUDED_)
#define AFX_DOCMANAGER_H__C8280F2F_CBC4_4C18_B4AC_D8900ADB767D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDocMngr : public IDocManager, public tmplContainer< String, DuiLib::CMarkup >
{
public:
	static const char chPartitionChar;
public:
	CDocMngr();
	virtual ~CDocMngr();
	virtual bool GetDoc( const String strFile, String strTag, String& strValue, const String strPath = _T("") );
	virtual DocNode GetNode( const String strFile, const String strPath = _T("") ) ;
protected:
/** 获得文件句柄 
 *  @param[in] 文件名
 *  @node 
 *  @return 文件句柄
 */
	CMarkup* GetDoc( const String strFile );
};

#endif // !defined(AFX_DOCMANAGER_H__C8280F2F_CBC4_4C18_B4AC_D8900ADB767D__INCLUDED_)
