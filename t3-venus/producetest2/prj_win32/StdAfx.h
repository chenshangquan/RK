// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__E273295E_89D9_4992_8884_1694D36DC265__INCLUDED_)
#define AFX_STDAFX_H__E273295E_89D9_4992_8884_1694D36DC265__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
//#include "afxwin.h"
//#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <stdio.h>
#define _CRT_SECURE_NO_DEPRECATE

#include "kdvtype.h"
//#include "kdvsys.h"
//#include "eqpservertest.h"
#include "hduautotest.h"
#include "mpuautotest.h"
//#include "eapuautotest.h"
//#include "t300autotest.h"
#pragma comment(lib, "osplib.lib") 
#pragma comment(lib, "duilib.lib")              
#pragma comment(lib, "kdvsys.lib")
#pragma warning( disable : 4786 )
#pragma warning( disable : 4503 )
#pragma warning( disable : 4800 )

#include <objbase.h>
#include <zmouse.h>
#include "osp.h"
#include "UIlib.h"
#include "UIMarkup.h"
#include <ShlObj.h>
using namespace DuiLib;

#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

#include "otherdef.h"
#include "msgdef.h"
#include "InterfaceDef.h"
#include "ICommonOp.h"
#include "Tftp.h"
#include "eventoutcnsdevice.h"
#include "tptype.h"
#include "tpsys.h"
#include "tpstruct.h"
#include "tpmsg.h"
typedef void   (CALLBACK* ComReadCallBack)();
//±à½âÂëÄ£¿é
// #include "codeclib.h"
// #pragma comment(lib, "kdvencoder.lib" )
// #pragma comment(lib, "kdvdecoder.lib" ) 
//#pragma comment(lib, "kdvmedianet.lib")
//#pragma comment(lib, "kdvencrypt.lib" )
#pragma comment(lib, "cnmsg.lib" )
#pragma comment(lib, "tpmsgmgr.lib" )
//#pragma comment(lib, "libcp.lib")
//#pragma comment(linker,"/NODEFAULTLIB:libc.lib")

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__E273295E_89D9_4992_8884_1694D36DC265__INCLUDED_)
