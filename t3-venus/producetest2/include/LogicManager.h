// LogicManager.h: interface for the CLogicManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGICMANAGER_H__ABF252B5_153E_42CE_BF88_AF7A88EE9E7B__INCLUDED_)
#define AFX_LOGICMANAGER_H__ABF252B5_153E_42CE_BF88_AF7A88EE9E7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLogicManager : public ILogicManager ,public tmplContainer<String, ILogic>
{
public:
	CLogicManager();
	virtual ~CLogicManager();
	ILogic* Create( const String& strLogic );
};

#endif // !defined(AFX_LOGICMANAGER_H__ABF252B5_153E_42CE_BF88_AF7A88EE9E7B__INCLUDED_)
