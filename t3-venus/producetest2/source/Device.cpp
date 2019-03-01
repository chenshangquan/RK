#include "stdafx.h"
#include "Device.h"
#include "TestCase.h"
CDevice::CDevice() : m_pCurTestCase(NULL), m_bIsEnd(false)
{

}

CDevice::CDevice( const CDevice& Dvc )
{
	m_vecBrdList.clear();
	for( u32 dwIdx = 0; dwIdx < Dvc.GetBrdCount(); dwIdx++ )
	{
		IBoard *pBoard = Dvc.m_vecBrdList[dwIdx];
		AddBoard( pBoard->Clone() );
	}
	m_pCurTestCase = 0;
	m_bIsEnd = false;
	m_strDvcName = Dvc.m_strDvcName;
}

CDevice::~CDevice()
{
	//释放板卡
	for ( u32 dwIdx = 0; dwIdx < m_vecBrdList.size(); dwIdx++ )
	{
		if ( m_vecBrdList[dwIdx] != NULL )
		{
			delete m_vecBrdList[dwIdx];
		}
	}

}

IDevice* CDevice::Clone()
{
	//调用Cpoy构造函数，克隆设备数据+板卡数据
	return new CDevice( *this );
}

bool CDevice::SetTestCase( EmCaseSetType emType )
{
	//先确保上一个测试项已经完成还原，再取新的测试项
	if ( m_pCurTestCase != NULL )
	{
		//Media测试项必须等待当前测试项结束
		if ( m_pCurTestCase->GetType() == emMediaCase )
		{
			CMediaTestCase *pCase = (CMediaTestCase*)m_pCurTestCase;
			pCase->SetProcedure(emCaseEndPending);
			while( true )
			{
				if( pCase->GetProcedure() == emCaseTested )
				{
					break;
				}
			}
		}
		m_pCurTestCase->Restore();
	}
	//下一项
	if( emTestNext == emType )
	{
		for( u32 dwIdx = 0; dwIdx < m_vecBrdList.size(); dwIdx++ )
		{
			//板卡必须被激活
			if( !m_vecBrdList[dwIdx]->GetActivated() )     
			{
				continue;
			}
			//找当前板卡拿当前测试项
			ITestCaseContainer *pContainer = m_vecBrdList[dwIdx]->GetCaseContainer();
			ITestCase *pCase = pContainer->GetCurCase();
			//当前板有测试项
			if ( pCase != NULL )                              
			{
				m_pCurTestCase = pCase;
				LOGEVENT("--------------------------------------\n");
				LOGEVENT("一个新的测试项 [ name:%s | type:%d ]\n",
					m_pCurTestCase->GetCaseName().c_str(), m_pCurTestCase->GetType());
				break;
			}
			//当前板没有测试项
			else
			{
				if ( dwIdx == m_vecBrdList.size() - 1 ) //最后一个板卡
				{
					LOGEVENT( "\n没有更多的测试项 ! \n" );
					EndTest();
					return false;    //没有测试项了
				}
			}
		}
	}
	//当前项
	else
	{

		if( m_pCurTestCase == NULL )
		{
			LOGEVENT( "\n当前测试项不可用\n" );
			return false;
		}
		LOGEVENT("--------------------------------------\n");
		LOGEVENT("重测当前项\n");
	}
	//执行当前测试项
	return ExeCurCase();
}

ITestCase* CDevice::GetCurTestCase()
{
	return m_pCurTestCase;
}

IBoard* CDevice::GetBoard( u32 dwIdx )
{
	if( dwIdx >= m_vecBrdList.size() )
		return NULL;
	return m_vecBrdList[dwIdx];
}

bool CDevice::AddBoard(IBoard *pBoard)
{
	m_vecBrdList.push_back( pBoard );
	return true;
}

bool CDevice::RemoveBoard(IBoard *pBoard)
{
	BrdList::iterator begin = m_vecBrdList.begin();
	while( begin != m_vecBrdList.end() )
	{
		if( pBoard == *begin)
			m_vecBrdList.erase( begin );
		begin++;
	}
	return true;
}

void CDevice::Print()
{
	LOGEVENT("Device\n");
	LOGEVENT("Board Count : %d\n " , m_vecBrdList.size());
	for( u32 dwIdx = 0 ; dwIdx < m_vecBrdList.size(); dwIdx++ )
	{
		LOGEVENT( "\tBoard %d \n", dwIdx + 1 );
		m_vecBrdList[dwIdx]->Print();
	}
}


void CDevice::EndTest( bool bNormal /*= true*/ )
{
	//正常结束:走板卡结束流程
	if( bNormal )
	{
		LOGEVENT("测试正常完成\n");
		m_pCurTestCase = NULL;
		for( u32 dwIdx = 0; dwIdx < m_vecBrdList.size(); dwIdx++ )
		{
			m_vecBrdList[dwIdx]->SetProcedure( emBrdEndPending );
		}
	}
	//异常结束:直接断开，板卡还原
	else
	{
		NOTIFY( EV_DVC_TEST_ABORT );
		LOGEVENT("测试中止\n");
		if ( m_pCurTestCase != NULL )
		{
			m_pCurTestCase->Restore();
			m_pCurTestCase = NULL;
		}
		for( u32 dwIdx = 0; dwIdx < m_vecBrdList.size(); dwIdx++ )
		{
			m_vecBrdList[dwIdx]->Restore();
		}		
	}
	m_bIsEnd = true;
}

u32 CDevice::GetBrdCount() const
{
	return m_vecBrdList.size();
}

bool CDevice::SetName( const String &strName )
{
	if ( m_strDvcName != strName )
	{
		m_strDvcName = strName;
	}
	return true;
}

String CDevice::GetName() const
{
	return m_strDvcName;
}

bool CDevice::ExeCurCase()
{
	LOGEVENT("EXE\n\n");
	if ( m_pCurTestCase->GetState() != emReady )
	{
		return false;
	}
	if ( m_pCurTestCase == NULL )
	{
		return false;
	}
	//测试项开始
	EmTestCaseType emCaseType = m_pCurTestCase->GetType();
	if ( emMediaCase == emCaseType )
	{
		CMediaTestCase *pMediaCase = (CMediaTestCase*)m_pCurTestCase;
		pMediaCase->PreTest();
	}
	else if ( emCmdCase == emCaseType )
	{
		CCmdTestCase *pCmdCase = (CCmdTestCase*)m_pCurTestCase;
		pCmdCase->PreTest();
		//m_pCurTestCase->ExeTestCase();
	}
	else if( emExeCase == emCaseType )
	{
		m_pCurTestCase->ExeTestCase();
	}	
	else
	{

	}
	return true;
}

bool CDevice::IsEnd() const
{
	return m_bIsEnd;	
}

void CDevice::Restore()
{
	m_bIsEnd = false;
}
