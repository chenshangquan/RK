/*=======================================================================
ģ����      :NmsCommon.lib��Ԫ����
�ļ���      : testnmscommonlib.h
����ļ�    :
�ļ�ʵ�ֹ��� :
����        : ���ǿ
�汾        : V3.6  Copyright(C) 2003-2005 Suzhou Keda Technology Co.Ltd
                    All rights reserved.
--------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2005/01/25  3.6         ���ǿ      ����
=======================================================================*/
// TestNmsCommonLib.h : main header file for the TESTNMSCOMMONLIB application
//

#if !defined(AFX_TESTNMSCOMMONLIB_H__216F77D1_673B_4715_8CB2_30AC953EC962__INCLUDED_)
#define AFX_TESTNMSCOMMONLIB_H__216F77D1_673B_4715_8CB2_30AC953EC962__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#include <cppunit\ui\mfc\TestRunner.h>
using namespace CppUnit;

/////////////////////////////////////////////////////////////////////////////
// CTestNmsCommonLibApp:
// See TestNmsCommonLib.cpp for the implementation of this class
//

class CTestNmsCommonLibApp : public CWinApp
{
public:
	CTestNmsCommonLibApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestNmsCommonLibApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestNmsCommonLibApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
        
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTNMSCOMMONLIB_H__216F77D1_673B_4715_8CB2_30AC953EC962__INCLUDED_)
