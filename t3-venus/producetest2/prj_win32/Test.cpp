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
	/******************************�����豸****************************************/
	LOGEVENT("�����豸��: ");
	s8 *pchCmd = new s8;
	IDevice *pDvc;
	while( gets( pchCmd ) )
	{
		pDvc = IDeviceFactory::GetSingletonPtr()->CreateDevice( pchCmd );  //CreateDevice
		if ( pDvc != NULL )
		{
			pDvc->Print();
			NOTIFY("�豸�����ɹ�!\n");
			break;
		}
		WARN("�豸����ʧ��!\n");
		LOGEVENT("�����豸��: ");
	}
	/******************************�豸ע��****************************************/
	NOTIFY("�������ע��忨...\n");
	getch();
	for ( u32 dwIdx = 0; ; dwIdx++)
	{
		IBoard *pBoard = pDvc->GetBoard(dwIdx);
		if ( pBoard == 0 )
		{
			break;
		}
		TObMsg msg;
		pBoard->ProcMsg(msg);       //ע����Ϣ
	}

	/******************************����****************************************/
	NOTIFY("���а忨׼�����������������ʼ����...");
	getch();
	LOGEVENT("\n");
	if( !pDvc->SetTestCase( emTestNext ))		//���ȡ����������򷵻�
		return;
	
	while( gets(pchCmd) )
	{
		if ( ISCMD("y") )
		{
			//media������������⴦��
			if ( pDvc->GetCurTestCase()->GetType() == emMediaCase )
			{
				CMediaTestCase *pMediaCase = (CMediaTestCase*)pDvc->GetCurTestCase();
				pMediaCase->SetProcedure( emCaseEndPending );
			}
			pDvc->GetCurTestCase()->SetState(emPassed);				//������
			if( !pDvc->SetTestCase( emTestNext ) )					//��һ��
			{
				NOTIFY("**********���в��������!************\n");
				break;
			}
		}
		else if( ISCMD("n") )
		{
			//media������������⴦��
			if ( pDvc->GetCurTestCase()->GetType() == emMediaCase )
			{
				CMediaTestCase *pMediaCase = (CMediaTestCase*)pDvc->GetCurTestCase();
				pMediaCase->SetProcedure( emCaseEndPending );
			}
			pDvc->GetCurTestCase()->SetState(emNotPassed);       //������
			NOTIFY("1=�ز� | 2=���� | other=��ֹ :");
			gets( pchCmd );
			if ( ISCMD("1") )
				pDvc->SetTestCase(emTestCur);
			else if( ISCMD("2") )
			{
				if( !pDvc->SetTestCase(emTestNext) )			//��һ��
				{
					NOTIFY("**********���в��������!************\n");
					break;
				}
			}
			else
			{
				WARN("���Ա���ֹ\n");
				break;
			}
		}
		else
		{
			printf( "'%s'  Unknown command!\n", pchCmd );
		}
	}

	/******************************���Խ��****************************************/
	LOGEVENT("**********Result********\n");
	u32 dwBrdIdx = 0;
	IBoard *pBoard = 0;
	ITestCase *pTestCase = 0;
	//����������
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

