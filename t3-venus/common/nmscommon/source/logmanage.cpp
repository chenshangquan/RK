/*=============================================================================
ģ   ��   ��: ���ܹ���ģ���
��   ��   ��: logmanage.cpp
�� ��  �� ��: logmanage.h
�ļ�ʵ�ֹ���: ��־������
��        ��: �����
��        ��: V4.0  Copyright(C) 2003-2006 KDC, All rights reserved.
˵        ��: ��ҪMFC֧��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2005/04/07  3.6     �����      ����
2005/12/08  4.0     ���        ����������ļ�
=============================================================================*/

#include "stdafx.h"
#include "nmscommon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////////
//
//      ��־������
//


/*=============================================================================
�� �� ��:CLogManage
��    ��:���캯��
��    ��:CLogItem *pcLog                    [in]    ��־��¼����Ϣ
         LPCTSTR lptrFilePath               [in]    ��־�ļ���ȫ·�������������ļ���
         u32 dwBufferSize                   [in]    ��ȡ��־�ļ�ʱ��Ļ������Ĵ�С
         u32 dwLogMaxNum                    [in]    �ļ�����������־��Ŀ
         u32 dwMallocStep                   [in]    ��̬�����Ĳ���
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/04/07  3.6     �����  ����
=============================================================================*/
CLogManage::CLogManage(CLogItem *pcLog, LPCTSTR lptrFilePath,
                       u32 dwBufferSize /* = MAX_LOG_BUF_SIZE */,
		               u32 dwLogMaxNum /* = MAX_LOG_NUM */,
                       u32 dwMallocStep /* = DEFAULT_LOG_STEP */)
        : m_dwLogMaxSize(dwLogMaxNum), m_dwCount(0),
          m_dwMallocStep(dwMallocStep), m_dwMallocNum(0), m_dwNewAddCount(0),
          m_dwUsedCount(0), m_dwSn(0), m_dwBufferSize(dwBufferSize),
          m_nSummaryLen(0), m_nDetailLen(0), m_nLogLen(0), m_pchBuffer(NULL),
          m_pchSummaryData(NULL), m_pchData(NULL)
{
    ASSERT(pcLog != NULL);
    ASSERT(lptrFilePath != NULL);
    ASSERT(dwBufferSize > 0);
    ASSERT(dwLogMaxNum >  0);
    ASSERT(dwMallocStep > 0);

    if (pcLog == NULL)
    {
	    return;
    }

    m_pchBuffer = new s8 [dwBufferSize];
    ZeroMemory(m_pchBuffer, dwBufferSize);

    SetLogFilePath( lptrFilePath );
    GetSummaryLen( pcLog );
    GetDetailLen( pcLog );
    GetLogLen();

    m_csPathName = GetLogFilePath();

    m_pchData = new s8 [m_nLogLen * WRITE_NUM];
    ZeroMemory(m_pchData, m_nLogLen * WRITE_NUM);

    ReadLog();
}

/*=============================================================================
�� �� ��:~CLogManage
��    ��:��������
��    ��:��
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/04/07  3.6     �����  ����
=============================================================================*/
CLogManage::~CLogManage()
{
    WriteLog();

    DEL_PTR_ARRAY(m_pchData);
    DEL_PTR_ARRAY(m_pchSummaryData);
    DEL_PTR_ARRAY(m_pchBuffer) ;
}

/*=============================================================================
�� �� ��:AddLog
��    ��:�������ӵ���־д���ڴ棬���ڴ��е���־�ﵽһ������Ŀʱ��д����־�ļ���
��    ��:CLogItem *pcLog                    [in]    ���ӵ���־��¼
         void *pcbData                      [in]    ����IsAddʱ���������
ע    ��:�����CLogItem��IsAdd�ж��Ƿ���Ҫд���ڴ�
�� �� ֵ:��־��¼����ˮ��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/04/07  3.6     �����  ����
2005/05/23  3.6     ���    д��m_pchSummaryData��λ��Ӧ����m_dwSn����λ
=============================================================================*/
u32 CLogManage::AddLog(CLogItem *pcLog, void *pcbData /* = NULL */)
{
	ASSERT(pcLog != NULL);

	if ( pcLog == NULL || ! pcLog->IsAdd( pcbData ) )
	{
		return 0;
	}

	LPCTSTR lpszSummary = pcLog->GetSummary();
	LPCTSTR lpszDetail = pcLog->GetDetail();

	//�����־����ϢΪ�ղ���¼
	if ( NULL == lpszSummary )
	{
		return 0;
	}

	m_dwCount++;
    m_dwUsedCount++;
	m_dwSn++;
	m_dwNewAddCount++;
	time( &m_tOccurTime );

	//�������ӵ���־д���ڴ�����
	if ( m_dwCount > m_dwLogMaxSize )
	{
		s8 *pchStartPos = m_pchSummaryData + ((m_dwSn - 1) % 
			m_dwLogMaxSize) * (sizeof(u32) + sizeof(time_t) + m_nSummaryLen);
		ZeroMemory(pchStartPos, sizeof(u32) + sizeof(time_t) + m_nSummaryLen);
		memcpy( pchStartPos, &m_dwSn,sizeof (u32) );
		memcpy( pchStartPos + sizeof (u32), &m_tOccurTime, sizeof (time_t) );
		memcpy( pchStartPos + sizeof (u32) + sizeof (time_t), lpszSummary,
			    _tcslen( lpszSummary ) );
	}
	else
	{
		if ( m_dwMallocNum == 0 )
		{
			s8 *pchOldData = m_pchSummaryData;
			m_pchSummaryData = NULL;
			MallocBuffer();
			memcpy( m_pchSummaryData, pchOldData, (m_dwCount- 1) * 
				        (sizeof(time_t) + sizeof(u32) + m_nSummaryLen) );
			m_dwMallocNum = m_dwMallocStep;
			DEL_PTR_ARRAY (pchOldData);
		}
		m_dwMallocNum--;
        //  wanghao 2005/05/23  ��m_dwSn����λ
		s8 *pchStartPos = m_pchSummaryData + (m_dwSn - 1)
			* (sizeof (time_t) + sizeof (u32) + m_nSummaryLen);
		memcpy( pchStartPos, &m_dwSn, sizeof (u32) );
		memcpy( pchStartPos + sizeof (u32), &m_tOccurTime, sizeof (time_t) );
		memcpy( pchStartPos + sizeof (u32) + sizeof (time_t),
			    lpszSummary, _tcslen(lpszSummary) );
		
	}

	//д��ϸ����Ϣ
	s8 *pStartPos = m_pchData + (m_dwNewAddCount-1) * m_nLogLen;
	//������Ϣ
	memcpy( pStartPos, &m_dwSn, sizeof (u32) );
	memcpy( pStartPos + sizeof (u32), &m_tOccurTime, sizeof (time_t) );
	memcpy( pStartPos + sizeof (u32) + sizeof (time_t), lpszSummary,
		    _tcslen(lpszSummary) );
	memcpy( pStartPos + sizeof (u32) + sizeof (time_t) + 
		            m_nSummaryLen, lpszDetail, _tcslen(lpszDetail) );

	//��־�ļ��ﵽ100�ͼ�¼
	if (m_dwNewAddCount == WRITE_NUM)
	{
		WriteLog();
	}

	return m_dwSn;
}

/*=============================================================================
�� �� ��:GetLog
��    ��:�õ�һ����־��¼,��������ϸ,�����Ǽ�,Ҳ������ȫ������Ϣ
��    ��:u32 dwSn                           [in]    Ҫ���ҵ���־��¼����ˮ��
         CLogItem *pcLog                    [out]   ��־��¼
         u32 dwType                         [in]    TYPE_SUMMARY �õ�����Ϣ
                                                    TYPE_DETAIL  �õ���ϸ��Ϣ
                                                    TYPE_ALL	 �õ���־��ȫ����Ϣ
ע    ��:��
�� �� ֵ:�ɹ����� TRUE��ʧ�ܷ��� FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/04/07  3.6     �����  ����
=============================================================================*/
BOOL32 CLogManage::GetLog(u32 dwSn, CLogItem *pcLog,
                          u32 dwType /* = TYPE_SUMMARY */)
{
	ASSERT(dwSn >= 0);
	ASSERT(pcLog != NULL);

	if ( pcLog == NULL || dwSn <= 0 )
	{
		return FALSE;
	}

	BOOL32 bFlag = FALSE;
	switch ( dwType ) 
	{
	case TYPE_SUMMARY:
		bFlag = GetSummary( dwSn, pcLog );
		break;
	case TYPE_DETAIL:
		bFlag = GetDetail( dwSn, pcLog );
		break;
	case TYPE_ALL:
		bFlag = GetSummary( dwSn, pcLog );
		if ( !bFlag )
        {
            break;
        }
		bFlag = GetDetail( dwSn, pcLog );
		break;
	default:
		break;
	}

	return bFlag;
}

/*=============================================================================
�� �� ��:GetLog
��    ��:�õ�һ����־��¼�ļ���Ϣ, ��Ϣֻ���Ǽ���Ϣ
��    ��:u32 dwSn                           [in]    Ҫ���ҵ���־��¼����ˮ��
         CLogItem *pcLog                    [out]   ��־��¼
         u32 dwOffSet                       [in]    ָ���ƫ��������������Ĵ�С 
         u32 dwNum						    [in]    Ҫ���ҵ���־����Ŀ
         u32 &dwNum                         [in/out]    Ҫ���ҵ���־����Ŀ/ʵ����Ŀ
ע    ��:������ҵ���־����ˮ��С����־�ļ�����С����ˮ��,�����С����ˮ�ſ�ʼ����
�� �� ֵ:���ҵ���¼: �����ҵ����һ����¼����һ����¼����ˮ��;
         û���ҵ���¼: ����0;
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/04/07  3.6     �����  ����
=============================================================================*/
u32 CLogManage::GetLog(u32 dwSn, CLogItem *pcLog, u32 dwOffset, u32 &dwNum) const
{
	if ( pcLog == NULL || dwSn > m_dwSn )
	{
        dwNum = 0;
		return 0;
	}

	if ( dwSn < GetMinSn() )
	{
		dwSn = GetMinSn();
	}

	for ( u32 dwCount = 0; dwCount < dwNum; dwSn ++ )
	{
		BOOL32 bFlag = FALSE;
		bFlag = GetSummary( dwSn,
                            (CLogItem*)((u8*)(pcLog) + dwOffset * dwCount) );
		if ( bFlag )
		{
			dwCount++;
		}

		if ( dwSn > m_dwSn )
		{
			break;
		}
	}

    dwNum = dwCount;
	return dwSn;
}

/*=============================================================================
�� �� ��:DeleteLog
��    ��:ɾ��ָ����ˮ�ŵ���־��¼
��    ��:u32 dwSn                           [in]    Ҫɾ������־��¼����ˮ��
ע    ��:��
�� �� ֵ:�ɹ�����TRUE, ʧ�ܷ���FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/04/07  3.6     �����  ����
=============================================================================*/
BOOL32 CLogManage::DeleteLog(u32 dwSn)
{
	ASSERT(dwSn > 0);
	if ( dwSn <= 0 || dwSn > m_dwSn )
	{
		return FALSE;
	}

	//ɾ���ڴ�����ļ���Ϣ
	u32 dwSequence = (dwSn - 1) % m_dwLogMaxSize;
    s32 nLogLen = sizeof (u32) + sizeof (time_t) + m_nSummaryLen;
	s8 *pchStartPos = m_pchSummaryData + dwSequence * nLogLen;
	memcpy(&dwSequence, pchStartPos, sizeof(u32) );
	if ( dwSequence != dwSn )
	{
		return FALSE;
	}

    m_dwUsedCount--;

    //  ��ռ�¼
    ZeroMemory(pchStartPos, nLogLen);

	//ɾ�����ڴ��ﵫ�ǻ�û��д���ļ��������־ȫ����Ϣ
	dwSequence = 0;
	for ( u32 dwLoopNum = 0; dwLoopNum < WRITE_NUM; dwLoopNum ++ )
	{
		s8 *pchStartPosition = m_pchData + dwLoopNum * m_nLogLen;
		memcpy( &dwSequence, pchStartPosition, sizeof (u32) );
		if ( dwSequence == dwSn )	
		{
            ZeroMemory(pchStartPosition, m_nLogLen);
			return TRUE;
		}
	}

	//ɾ���ļ��������־��¼
	CFile cFile;
	BOOL bOpen = cFile.Open( m_csPathName,
                             CFile::modeReadWrite| CFile::shareExclusive );
	if ( ! bOpen )
	{
		return FALSE;
	}

	u32 dwRead = cFile.Read( &dwSequence, sizeof (u32) );
	if (dwRead == 0)
	{
		cFile.Close();
		return FALSE;
	}

	dwSequence = 0;
	dwSequence = (dwSn - 1) % m_dwLogMaxSize;
	cFile.Seek( sizeof (u32) + dwSequence * m_nLogLen, CFile::current );
	cFile.Read( &dwSequence, sizeof (u32) );
	if ( dwSequence != dwSn )
	{
		cFile.Close();
		return FALSE;
	}

	s8 *pchBuffer = new s8 [m_nLogLen];
	ZeroMemory(pchBuffer, m_nLogLen);
	//ɾ����־����ˮ��
	LONG lSeek = -static_cast<LONG>(sizeof (u32));
	cFile.Seek( lSeek, CFile::current );
	cFile.Write( pchBuffer, m_nLogLen );
	cFile.Close();
	DEL_PTR_ARRAY(pchBuffer);

	return TRUE;
}

/*=============================================================================
�� �� ��:ClearLog
��    ��:�����־��¼
��    ��:��
ע    ��:��
�� �� ֵ:�ɹ�ɾ������TRUE, ʧ�ܷ���FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/04/07  3.6     �����  ����
=============================================================================*/
BOOL32 CLogManage::ClearLog(void)
{
	CFile cFile;
	BOOL bOpen = cFile.Open( m_csPathName,
                             CFile::modeCreate | CFile::modeWrite |
		                        CFile::shareDenyNone);
	if ( ! bOpen )
	{
		return FALSE;
	}

	m_dwCount = 0;
	m_dwSn = 0;
	m_dwNewAddCount = 0;
    m_dwUsedCount = 0;
	cFile.Write( &m_dwCount, sizeof (u32) );
	cFile.Write( &m_dwSn, sizeof (u32) );
	cFile.Close();
	DEL_PTR_ARRAY(m_pchSummaryData);

	return TRUE;
}

/*=============================================================================
�� �� ��:GetMinSn
��    ��:�õ���־����С���õ���ˮ��
��    ��:��
ע    ��:��
�� �� ֵ:��С���õ���ˮ��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/04/07  3.6     �����  ����
2005/05/23  3.6     ���    ��ˮ�ű�������С��, �Ҵ��ڵ�
=============================================================================*/
u32 CLogManage::GetMinSn(void) const
{
    u32 dwOffsetNum = 0;
    s32 nLen = sizeof (u32) + sizeof (time_t) + m_nSummaryLen;
    s8 *pEmptyBuf = new s8 [nLen];
    ZeroMemory(pEmptyBuf, nLen);
    while (memcmp(pEmptyBuf, m_pchSummaryData + dwOffsetNum * nLen, nLen) == 0)
    {
        dwOffsetNum++;
    }
    memcpy(&dwOffsetNum, m_pchSummaryData + dwOffsetNum * nLen, sizeof (u32));
    DEL_PTR_ARRAY( pEmptyBuf );
    return dwOffsetNum;
}

/*=============================================================================
�� �� ��:GetLogFilePath
��    ��:�õ���־�ļ���·��
��    ��:��
ע    ��:·���Ǿ���·��, �����ļ���
�� �� ֵ:��־�ļ���·��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/04/07  3.6     �����  ����
=============================================================================*/
CString& CLogManage::GetLogFilePath(void)
{
	CFile cFile( m_csPathName, CFile::modeCreate | CFile::modeNoTruncate );
	m_csPathName = cFile.GetFilePath();
	return m_csPathName;
}

/*=============================================================================
�� �� ��:GetLogFileName
��    ��:�õ���־�ļ����ļ���
��    ��:��
ע    ��:��
�� �� ֵ:�ļ���
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/04/07  3.6     �����  ����
=============================================================================*/
CString CLogManage::GetLogFileName(void)
{
	CString csFileName = _T("");
	CFile cFile( LPCTSTR(m_csPathName),
                 CFile::modeCreate | CFile::modeNoTruncate);
	csFileName = cFile.GetFileName();
	return csFileName;
}

/*=============================================================================
�� �� ��:ReadLog
��    ��:���ļ�������־��¼�ļ���Ϣ�����ڴ�����
��    ��:��
ע    ��:��
�� �� ֵ:�ɹ�: TRUE; ʧ��: FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/04/07  3.6     �����  ����
2005/05/23  3.6     ���    �����ֵ���
=============================================================================*/
BOOL32 CLogManage::ReadLog(void)
{
	CFile cFile;
	BOOL bOpen = cFile.Open( m_csPathName,
                             CFile::modeRead | CFile::shareDenyNone );
	if ( ! bOpen )
	{
		cFile.Open( m_csPathName,
                    CFile::modeCreate| CFile::modeWrite| CFile::shareDenyNone );
		cFile.Write( &m_dwCount,sizeof (u32) );
		cFile.Write( &m_dwSn,sizeof (u32) );
		cFile.Close();
		return FALSE;
	}

    UINT dwRead = cFile.Read( &m_dwCount, sizeof (u32) );
	cFile.Read( &m_dwSn, sizeof (u32) );
	if ( dwRead == 0 )
	{
		cFile.Close();
		return FALSE;
	}

	if ( m_dwCount == 0 )
	{
		cFile.Close();
		return FALSE;
	}

    u32 dwGetNum = static_cast<s32>(m_dwBufferSize / m_nLogLen);
    u32 dwRealNum = 0;
    u32 dwReadNum = 0;
    s32 nOffset = 0;
    MallocBuffer();

    s8 *pEmptyBuf = new s8 [sizeof (u32) + sizeof (time_t) + m_nSummaryLen];

    while (dwReadNum < m_dwCount)
    {
        s32 nNumThisTime = m_dwCount - dwRealNum;
        nNumThisTime = nNumThisTime > (s32)dwGetNum ? dwGetNum : nNumThisTime;
        dwReadNum += nNumThisTime;

        u32 dwRealLen = nNumThisTime * m_nLogLen;
        cFile.Read( m_pchBuffer, dwRealLen );

        //�������ݵ�m_pchSummaryData
		u32 dwCopyLength = sizeof (u32) + sizeof (time_t) + m_nSummaryLen;
		for ( s32 nNum = 0; nNum < nNumThisTime; nNum ++ )
		{
            s8 *pBuf = m_pchBuffer + nNum * (dwCopyLength + m_nDetailLen);
            memcpy( m_pchSummaryData + nOffset, pBuf, dwCopyLength );
            nOffset += dwCopyLength;
            //  wanghao 2005/05/23  ��־�ļ�ĳ��λ�ÿ���Ϊ��, ��Ҫ����
            if ( memcmp(m_pchBuffer, pEmptyBuf, dwCopyLength) != 0 )
            {
                dwRealNum++;
            }
		}
		ZeroMemory( m_pchBuffer, m_dwBufferSize );
    }

    m_dwUsedCount = dwRealNum;

	cFile.Close();
    DEL_PTR_ARRAY(pEmptyBuf);

	return TRUE;
}

/*=============================================================================
�� �� ��:GetSummary
��    ��:�õ�ָ����ˮ�ŵ���־��¼�ļ���Ϣ
��    ��:u32 dwSn                           [in]    Ҫ���ҵ���־��¼����ˮ��
         CLogItem *pcLog                    [out]   ��־��¼
ע    ��:��
�� �� ֵ:�ɹ�: TRUE; ʧ��: FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/04/07  3.6     �����  ����
=============================================================================*/
BOOL32 CLogManage::GetSummary(u32 dwSn, CLogItem *pcLog) const
{
	if ( pcLog == NULL || dwSn > m_dwSn )
	{
		return FALSE;
	}

	u32 dwPos = (dwSn - 1) % m_dwLogMaxSize;
	u32 dwSquence = 0;
	memcpy( &dwSquence, (m_pchSummaryData + dwPos * 
		                    (sizeof (u32) + sizeof (time_t)+ m_nSummaryLen)),
            sizeof (u32) );
	if ( dwSquence != dwSn )
	{
		return FALSE;
	}

	s8 *pchBuffer = new s8[m_nSummaryLen]; 
	ZeroMemory(pchBuffer,m_nSummaryLen);
	time_t tOccurTime;
	memcpy( &tOccurTime, m_pchSummaryData + sizeof(u32) + m_nSummaryLen
                            + dwPos * (sizeof (s32) + sizeof (time_t)),
            sizeof (time_t) );
	memcpy( pchBuffer,
            m_pchSummaryData + sizeof (u32) + sizeof (time_t) + m_nSummaryLen
		                    + dwPos * (sizeof (s32) + sizeof (time_t)),
            m_nSummaryLen);
	pcLog->SetTimeDate( tOccurTime );
	pcLog->SetSquence( dwSquence );
	pcLog->SetSummary( pchBuffer );
	DEL_PTR_ARRAY (pchBuffer);

	return TRUE;
}

/*=============================================================================
�� �� ��:GetDetail
��    ��:�õ�ָ����ˮ�ŵ���־��¼����ϸ��Ϣ
��    ��:u32 dwSn                           [in]    Ҫ���ҵ���־��¼����ˮ��
         CLogItem *pcLog                    [out]   ��־��¼
ע    ��:��
�� �� ֵ:�ɹ�: TRUE; ʧ��: FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/04/07  3.6     �����  ����
=============================================================================*/
BOOL32 CLogManage::GetDetail(u32 dwSn, CLogItem *pcLog)
{
	if ( pcLog == NULL )
	{
		return FALSE;
	}
	CFile cFile;
	u32 dwSquence1 = 0;

	//��ȡ��־��¼����
	for ( u32 dwCount1 = 0; dwCount1 < WRITE_NUM; dwCount1 ++ )
	{
		s8 *pchStart = m_pchData + dwCount1 * m_nLogLen;
		memcpy( &dwSquence1, pchStart, sizeof (u32) );
		if ( dwSquence1 == dwSn )
		{
			s8 *pchBuffer1 = new s8 [m_nDetailLen];
			ZeroMemory(pchBuffer1, m_nDetailLen);
			memcpy( pchBuffer1,
                    pchStart + (sizeof(u32) + sizeof (time_t) + m_nSummaryLen),
                    m_nDetailLen );
			pcLog->SetDetail( pchBuffer1 );
			DEL_PTR_ARRAY (pchBuffer1);
			return TRUE;
		}
	}

	BOOL bOpen = cFile.Open( m_csPathName,
                             CFile::modeRead | CFile::shareDenyWrite );
	if ( ! bOpen )
	{
		return FALSE;
	}

	UINT dwRead = cFile.Read(&m_dwCount, sizeof(u32));
	if (dwRead == 0)
	{
		cFile.Close();
		return FALSE;
	}

	//�ڶ���u32��¼���ļ�����ˮ�ŵ�������ֵ
	cFile.Read( &m_dwSn, sizeof (u32) );
	if ( dwSn > m_dwSn )
	{	
		cFile.Close();
		return FALSE;
	}

	u32 dwSquence = (dwSn - 1) % m_dwLogMaxSize;
	cFile.Seek( (dwSquence) * m_nLogLen, CFile::current );
	cFile.Read( &dwSquence, sizeof (u32) );
	if ( dwSquence != dwSn )
	{
		cFile.Close();
		return FALSE;
	}

	s8 *pchBuffer = new s8 [m_nDetailLen];
	ZeroMemory(pchBuffer , m_nDetailLen);

	cFile.Seek( sizeof (time_t) + m_nSummaryLen, CFile::current );
	cFile.Read( pchBuffer, m_nDetailLen );
	pcLog->SetDetail( pchBuffer );

	DEL_PTR_ARRAY (pchBuffer);
	cFile.Close();

	return TRUE;
}

/*=============================================================================
�� �� ��:MallocBuffer
��    ��:��̬�����ڴ�
��    ��:��
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/04/07  3.6     �����  ����
=============================================================================*/
void CLogManage::MallocBuffer(void)
{
	DEL_PTR_ARRAY(m_pchSummaryData) ;

	u32 dwStep = sizeof (time_t) + sizeof (u32) + m_nSummaryLen;
	m_pchSummaryData = new s8 [(m_dwCount + m_dwMallocStep) * dwStep];

	ZeroMemory( m_pchSummaryData, (m_dwCount + m_dwMallocStep) * dwStep );
}

/*=============================================================================
�� �� ��:WriteLog
��    ��:���ڴ��������־��¼д����־�ļ�����ȥ
��    ��:��
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/04/07  3.6     �����  ����
=============================================================================*/
void CLogManage::WriteLog()
{
	CFile cFile;
	BOOL bOpen = cFile.Open( m_csPathName,
                             CFile::modeCreate | CFile::modeNoTruncate
		                        | CFile::modeWrite | CFile::shareExclusive );
	if ( ! bOpen )
	{
		return;
	}

	//����־�ļ���Ŀ����10000��ʱ���µ���־������ɵ���־
	if ( m_dwCount > m_dwLogMaxSize )
	{	
		m_dwCount = m_dwLogMaxSize;
		cFile.Write( &m_dwCount, sizeof (u32) );
		cFile.Write( &m_dwSn, sizeof (u32) );
		u32 dwStartPos = 0;
		if ( (m_dwSn-m_dwNewAddCount) % m_dwLogMaxSize
                > m_dwSn % m_dwLogMaxSize )
		{
			dwStartPos = (m_dwSn - m_dwNewAddCount) % m_dwLogMaxSize;
			cFile.Seek(2 * sizeof(u32) + dwStartPos * m_nLogLen, CFile::begin);
			cFile.Write( m_pchData, (m_dwLogMaxSize - dwStartPos)*m_nLogLen );
			cFile.Seek( 2 * sizeof (u32), CFile::begin );
			cFile.Write( m_pchData + (m_dwLogMaxSize -dwStartPos) * m_nLogLen,
			             (m_dwNewAddCount - (m_dwLogMaxSize - dwStartPos))
                                * m_nLogLen );
		}
		else
		{
			dwStartPos = (m_dwSn-m_dwNewAddCount) % m_dwLogMaxSize;
			cFile.Seek(2 * sizeof(u32) + dwStartPos * m_nLogLen, CFile::begin);
			cFile.Write( m_pchData, m_dwNewAddCount * m_nLogLen );
		}
		cFile.Close();
	}
	else
	{
		cFile.Write( &m_dwCount, sizeof (u32) );
		cFile.Write( &m_dwSn, sizeof (u32) );
		cFile.SeekToEnd();
		cFile.Write(m_pchData, m_dwNewAddCount * m_nLogLen);
		cFile.Close();
	}

	//ɨβ����
	ZeroMemory(m_pchData, m_nDetailLen * WRITE_NUM);
	m_dwNewAddCount = 0;
}