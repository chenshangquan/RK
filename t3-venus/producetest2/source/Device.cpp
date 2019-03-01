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
	//�ͷŰ忨
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
	//����Cpoy���캯������¡�豸����+�忨����
	return new CDevice( *this );
}

bool CDevice::SetTestCase( EmCaseSetType emType )
{
	//��ȷ����һ���������Ѿ���ɻ�ԭ����ȡ�µĲ�����
	if ( m_pCurTestCase != NULL )
	{
		//Media���������ȴ���ǰ���������
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
	//��һ��
	if( emTestNext == emType )
	{
		for( u32 dwIdx = 0; dwIdx < m_vecBrdList.size(); dwIdx++ )
		{
			//�忨���뱻����
			if( !m_vecBrdList[dwIdx]->GetActivated() )     
			{
				continue;
			}
			//�ҵ�ǰ�忨�õ�ǰ������
			ITestCaseContainer *pContainer = m_vecBrdList[dwIdx]->GetCaseContainer();
			ITestCase *pCase = pContainer->GetCurCase();
			//��ǰ���в�����
			if ( pCase != NULL )                              
			{
				m_pCurTestCase = pCase;
				LOGEVENT("--------------------------------------\n");
				LOGEVENT("һ���µĲ����� [ name:%s | type:%d ]\n",
					m_pCurTestCase->GetCaseName().c_str(), m_pCurTestCase->GetType());
				break;
			}
			//��ǰ��û�в�����
			else
			{
				if ( dwIdx == m_vecBrdList.size() - 1 ) //���һ���忨
				{
					LOGEVENT( "\nû�и���Ĳ����� ! \n" );
					EndTest();
					return false;    //û�в�������
				}
			}
		}
	}
	//��ǰ��
	else
	{

		if( m_pCurTestCase == NULL )
		{
			LOGEVENT( "\n��ǰ���������\n" );
			return false;
		}
		LOGEVENT("--------------------------------------\n");
		LOGEVENT("�ز⵱ǰ��\n");
	}
	//ִ�е�ǰ������
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
	//��������:�߰忨��������
	if( bNormal )
	{
		LOGEVENT("�����������\n");
		m_pCurTestCase = NULL;
		for( u32 dwIdx = 0; dwIdx < m_vecBrdList.size(); dwIdx++ )
		{
			m_vecBrdList[dwIdx]->SetProcedure( emBrdEndPending );
		}
	}
	//�쳣����:ֱ�ӶϿ����忨��ԭ
	else
	{
		NOTIFY( EV_DVC_TEST_ABORT );
		LOGEVENT("������ֹ\n");
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
	//�����ʼ
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
