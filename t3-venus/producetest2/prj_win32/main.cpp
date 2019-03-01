#include "stdafx.h"
#include "System.h"
#include "exceptioncatch.h"
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

int  main()
{
	//��ǰ��ȷ��tftp��������
	CTftpOp::KillTftpProcess();
	CExceptionCatch::Start();
	HWND hWnd = ::FindWindow( 0, _T("producetest") );
	if ( hWnd != NULL )
	{
		::SetForegroundWindow(hWnd);
		exit(0);
	}

	new CSystem( _T("system.xml") );

	CSystem::GetSingletonPtr()->Launch();

	CExceptionCatch::Free();
    return 0; 
}
