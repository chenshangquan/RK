#include "stdafx.h"
#include "TestCaseContainer.h"

CTestCaseContainer::CTestCaseContainer() : m_dwCurCasePos(0)
{

}

CTestCaseContainer::~CTestCaseContainer()
{
	//�ͷ���Դ
	for ( u32 dwIdx = 0; dwIdx < m_vecCaseList.size(); dwIdx++ )
	{
		if ( m_vecCaseList[dwIdx] != NULL )
		{
			delete m_vecCaseList[dwIdx];
		}
	}

}

bool CTestCaseContainer::AddTestCase( ITestCase *pTestCase )
{
	m_vecCaseList.push_back( pTestCase );
	return true;
}

bool CTestCaseContainer::RemoveTestCase( ITestCase *pTestCase )
{
	TestCaseList::iterator begin = m_vecCaseList.begin();
	while( begin != m_vecCaseList.end() )
	{
		if( pTestCase == *begin)
			m_vecCaseList.erase( begin );
		begin++;
	}
	return true;
}

ITestCase* CTestCaseContainer::GetTestCase( u32 dwIdx )
{
	if( dwIdx >= m_vecCaseList.size() )
		return NULL;
	return m_vecCaseList[dwIdx];
}

ITestCase* CTestCaseContainer::GetCurCase() 
{
	while( m_dwCurCasePos < m_vecCaseList.size() )
	{
		m_dwCurCasePos++;											
		//������λ�õĲ������ѡ��ӣ��򷵻�
		if( m_vecCaseList[m_dwCurCasePos - 1]->GetAdded() == true )
			return m_vecCaseList[m_dwCurCasePos - 1];
	}
	return NULL;

}



u32 CTestCaseContainer::GetCaseCount()
{
	return m_vecCaseList.size();
}


ITestCase* CTestCaseContainer::GetTestCase( String strCaseName )
{
	for ( u32 dwIdx = 0; dwIdx < m_vecCaseList.size(); dwIdx++ )
	{
		if( m_vecCaseList[dwIdx]->GetCaseName() == strCaseName )
		{
			return m_vecCaseList[dwIdx];
		}
	}
	return NULL;
} 


bool CTestCaseContainer::RemoveAll()
{
	//���ͷ�..�����..
	for ( u32 dwIdx = 0; dwIdx < m_vecCaseList.size(); dwIdx++ )
	{
		ITestCase *pCase = m_vecCaseList[dwIdx];
		if ( pCase != NULL )
		{
			delete pCase;
			pCase = NULL;
		}
	}
	m_vecCaseList.clear();
	m_dwCurCasePos = 0;
	return true;
}

bool CTestCaseContainer::Restore()
{
	m_dwCurCasePos = 0;
	return true;
}
