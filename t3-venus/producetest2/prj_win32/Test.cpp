#include "stdafx.h"
#include "Test.h"
#include "System.h"
#include "TestCase.h"
#include "Board.h"
#include "Device.h"
#include "ICommonOp.h"
#include <conio.h> 
#include <stdio.h> 
#include <windows.h> 

//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"") 
void setcolor(unsigned short ForeColor,unsigned short BackGroundColor) 
{ 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(ForeColor%16)|(BackGroundColor%16*16)); 
} 

#define ISCMD(x)		!strcmp( pchCmd, x) 
#define NOTIFY(x) 		setcolor( 3, 0 );\
						LOGEVENT(x);\
						setcolor( 7, 0 );
#define WARN(x) 		setcolor( 4, 0 );\
						LOGEVENT(x);\
						setcolor( 7, 0 );


void Test() 
{ 
	/******************************创建设备****************************************/
	LOGEVENT("输入设备名: ");
	s8 *pchCmd = new s8;
	IDevice *pDvc;
	while( gets( pchCmd ) )
	{
		pDvc = IDeviceFactory::GetSingletonPtr()->CreateDevice( pchCmd );  //CreateDevice
		if ( pDvc != NULL )
		{
			pDvc->Print();
			NOTIFY("设备创建成功!\n");
			break;
		}
		WARN("设备创建失败!\n");
		LOGEVENT("输入设备名: ");
	}
	/******************************设备注册****************************************/
	NOTIFY("按任意键注册板卡...\n");
	getch();
	for ( u32 dwIdx = 0; ; dwIdx++)
	{
		IBoard *pBoard = pDvc->GetBoard(dwIdx);
		if ( pBoard == 0 )
		{
			break;
		}
		TObMsg msg;
		pBoard->ProcMsg(msg);       //注册消息
	}

	/******************************测试****************************************/
	NOTIFY("所有板卡准备就绪，按任意键开始测试...");
	getch();
	LOGEVENT("\n");
	if( !pDvc->SetTestCase( emTestNext ))		//如果取不到测试项，则返回
		return;
	
	while( gets(pchCmd) )
	{
		if ( ISCMD("y") )
		{
			//media测试项结束特殊处理
			if ( pDvc->GetCurTestCase()->GetType() == emMediaCase )
			{
				CMediaTestCase *pMediaCase = (CMediaTestCase*)pDvc->GetCurTestCase();
				pMediaCase->SetProcedure( emCaseEndPending );
			}
			pDvc->GetCurTestCase()->SetState(emPassed);				//保存结果
			if( !pDvc->SetTestCase( emTestNext ) )					//下一项
			{
				NOTIFY("**********所有测试项完成!************\n");
				break;
			}
		}
		else if( ISCMD("n") )
		{
			//media测试项结束特殊处理
			if ( pDvc->GetCurTestCase()->GetType() == emMediaCase )
			{
				CMediaTestCase *pMediaCase = (CMediaTestCase*)pDvc->GetCurTestCase();
				pMediaCase->SetProcedure( emCaseEndPending );
			}
			pDvc->GetCurTestCase()->SetState(emNotPassed);       //保存结果
			NOTIFY("1=重测 | 2=忽略 | other=终止 :");
			gets( pchCmd );
			if ( ISCMD("1") )
				pDvc->SetTestCase(emTestCur);
			else if( ISCMD("2") )
			{
				if( !pDvc->SetTestCase(emTestNext) )			//下一项
				{
					NOTIFY("**********所有测试项完成!************\n");
					break;
				}
			}
			else
			{
				WARN("测试被终止\n");
				break;
			}
		}
		else
		{
			printf( "'%s'  Unknown command!\n", pchCmd );
		}
	}

	/******************************测试结果****************************************/
	LOGEVENT("**********Result********\n");
	u32 dwBrdIdx = 0;
	IBoard *pBoard = 0;
	ITestCase *pTestCase = 0;
	//遍历测试项
	while( pBoard = pDvc->GetBoard(dwBrdIdx) )
	{   
		LOGEVENT("------%s--------\n", pBoard->GetBrdName().c_str() );
		u32 dwCaseIdx = 0;
		while( pTestCase = ICommonOp::GetTestCase( pBoard, dwCaseIdx ))
		{
			LOGEVENT("%s", pTestCase->GetCaseName().c_str());
			if ( pTestCase->GetState() == emPassed )
			{
				NOTIFY("\t\tPass\n");
			}
			else if( pTestCase->GetState() == emNotReady )
			{
				WARN("\t\tNot Test\n");
			}
			else
			{
				WARN("\t\tNot Pass\n");
			}
			dwCaseIdx++;
		}
		dwBrdIdx++;
	}
	delete pDvc;
	getch();
}

