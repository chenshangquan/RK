// DocManager.cpp: implementation of the CDocManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DocManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const char CDocMngr::chPartitionChar = '/';
CDocMngr::CDocMngr()
{

}

CDocMngr::~CDocMngr()
{

}

bool CDocMngr::GetDoc(const String strFile, String strTag, 
						 String& strValue, const String strPath /* = _T */)
{
	DuiLib::CMarkup* pDoc = GetDoc( strFile );
	if ( pDoc == NULL )
	{
		return false;
	}
	DuiLib::CMarkupNode pNode = pDoc->GetRoot();
	
	stringstream ss( strPath );
	string sub_str;
	bool bRet = false;
	int nIndex = 0;
	while( getline( ss, sub_str, CDocMngr::chPartitionChar ) )         
	{
		pNode = pNode.GetChild( sub_str.c_str() );
		if ( pNode.IsValid() == false )
		{
			return false;
		}
	}
	if ( pNode.IsValid() )
	{
		strValue = pNode.GetAttributeValue( strTag.c_str() );
		
		return !strValue.empty() ;
	}

	return false;
}

CMarkup* CDocMngr::GetDoc( const String strFile )
{
	LOGEVENT("GetDoc [%s]----", strFile.c_str());
	DuiLib::CMarkup* pDoc = Find( strFile );
	LOGEVENT("GetDoc[%d] OK\n", pDoc );
	if ( pDoc == NULL )
	{
		pDoc = new DuiLib::CMarkup();
		bool bRet = pDoc->LoadFromFile( strFile.c_str() );
		if ( bRet == true )
		{
			Add( strFile, pDoc );
			return pDoc;
			LOGEVENT("GetDoc[%d] OK\n", pDoc );
		}
		else
		{
			delete pDoc;
			pDoc = 0;
		}
	}
	return pDoc;
}

DocNode CDocMngr::GetNode(const String strFile, const String strPath )
{
	DuiLib::CMarkup* pDoc = GetDoc( strFile );
	assert( pDoc != 0 );
	DuiLib::CMarkupNode Node = pDoc->GetRoot();
	stringstream ss( strPath );
	string sub_str;
	bool bRet = false;
	int nIndex = 0;
	while( getline( ss, sub_str, CDocMngr::chPartitionChar ) )         
	{
		if ( Node.IsValid())
		{
			Node = Node.GetChild( sub_str.c_str() );
		}
		else
		{
			LOGEVENT("节点无效\n");
			break;
		}
	}
	return Node;
}