// ControlFactory.cpp: implementation of the CControlFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "structdef.h"
#include "ControlFactory.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

const String CControlFactory::strSubControl = _T("subcontrol.xml");
CControlUI* CControlFactory::GetControl( String strName,  CControlUI *pParent /* = NULL*/,  CPaintManagerUI *pm /* = NULL*/)
{
	DocNode xmlNode = DOCMNGR->GetNode( CControlFactory::strSubControl, strName );
	if ( xmlNode.IsValid() )
	{		
		CDialogBuilder cBuilder;
		CControlUI* pControl = cBuilder.Create( &xmlNode, pParent, pm);
		return pControl;
	}
	return NULL;
}
