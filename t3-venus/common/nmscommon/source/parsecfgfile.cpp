// parsecfgfile.cpp: implementation of the CParseCfgfile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "parsecfgfile.h"

#include <algorithm>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#define MAX_DATA_BUF_LEN    32

CParseCfgfile::CParseCfgfile()
{
    Clear();
}

CParseCfgfile::~CParseCfgfile()
{

}

/*=============================================================================
�� �� ��:ReadData
��    ��:���ڴ�����pData����m_vctData��,
��    ��:const char *pData                [in]    ����

ע    ��:������pData���������������ļ���ʽ�����ݣ��磺("[1]\n\n\nk1=abc\nk2=123\n\n[2]\nk1=ghi\nk2=jkl\n")
        ����Ҫ��[section]��key����val��������֮�䶼Ӧ���Իس����ֿ�

�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2009/06/15  1.0     �½���    ����
=============================================================================*/
void CParseCfgfile::ReadData(const char *pData)
{
    string strData( pData );
   
    int ncount = count( pData, pData + strlen(pData), '[' );

    int nBgn = 0, nEnd = 0;
    

    for ( int i = 0; i < ncount; i++ )
    {
        nBgn = strData.find('[', nBgn );
        nEnd = strData.find(']', nEnd );
        string strSection = ("");
        strSection = strData.substr( nBgn + 1, nEnd - nBgn - 1 );

        strData.erase( nBgn, nEnd - nBgn + 1 + 1 );//add another 1 to remove '\n' symbol
        while( strData[0]  != '[' && strData != ("") )
        {
            int nIndxS = 0, nIndxE = 0;

            //find = symbol
            nIndxE = strData.find( '=', nIndxS );
            string strkey = strData.substr( nIndxS, nIndxE - nIndxS );

            //find '\n' symbol
            nIndxS = nIndxE + 1;
            nIndxE = strData.find('\n', nIndxS );
            if ( nIndxE == string::npos )//not find means read over, copy the left string and return
            {
                string strValue = strData.substr( nIndxS, -1 );
            
                TCfgFileData tData( strSection, strkey, strValue );
                m_vctData.push_back( tData );
                return;
            }

            string strValue = strData.substr( nIndxS, nIndxE - nIndxS );
            
            TCfgFileData tData( strSection, strkey, strValue );
            m_vctData.push_back( tData );
          
            nIndxE = strData.find_first_not_of('\n', nIndxE );
            strData.erase( 0, nIndxE );
        }
    }
}

/*=============================================================================
�� �� ��:GetProfileString
��    ��:�õ���Ӧ�ֶε��ַ���
��    ��:const char *lpAppName                [in]    �ֶ���
         const char *lpKeyName                [in]     Key��
         const char *lpDefault                [in]     Ĭ�Ϸ���ֵ
         char *lpReturnedString               [out]    keyֵ
         int nSize                            [in]     lpReturnedString����
ע    ��:ʹ��ǰҪ����ReadData��������
�� �� ֵ:������lpReturnedString�е��ַ�������
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2009/06/15  1.0     �½���    ����
=============================================================================*/
int CParseCfgfile::GetProfileString(const char *lpAppName, const char *lpKeyName, const char *lpDefault, 
                                    char *lpReturnedString, int nSize)
{
    vector<TCfgFileData>::iterator itr = m_vctData.begin();
    for ( ;itr != m_vctData.end(); itr++ )
    {
        PTCfgFileData ptData = itr;
        if ( ptData->m_strSec == lpAppName && ptData->m_strKey == lpKeyName )
        {
            if ( nSize > ptData->m_strVal.size() )
            {
                ptData->m_strVal.copy( lpReturnedString, ptData->m_strVal.size(), 0 );
                return ptData->m_strVal.size();
            } 
            else
            {
                strcpy( lpReturnedString, lpDefault );
                return strlen( lpDefault ); 
            }
            
        }
    }

    if ( itr == m_vctData.end() )
    {
        strcpy( lpReturnedString, lpDefault );
        return strlen( lpDefault );
    }

    return 0;
}

/*=============================================================================
�� �� ��:GetProfileInt
��    ��:�õ���Ӧ�ֶε�ֵ
��    ��:const char *lpAppName                [in]    �ֶ���
         const char *lpKeyName                [in]     Key��
         int nDefault                         [in]     Ĭ�Ϸ���ֵ
         
ע    ��:ʹ��ǰҪ����ReadData��������
�� �� ֵ:��Ӧ�ֶε�ֵ
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2009/06/15  1.0     �½���    ����
=============================================================================*/
int CParseCfgfile::GetProfileInt(const char *lpAppName, const char *lpKeyName, int nDefault)
{
    vector<TCfgFileData>::iterator itr = m_vctData.begin();
    for ( ;itr != m_vctData.end(); itr++ )
    {
        PTCfgFileData ptData = itr;
        if ( ptData->m_strSec == lpAppName && ptData->m_strKey == lpKeyName )
        {
            char aszTemp[MAX_DATA_BUF_LEN] = {0};
            ptData->m_strVal.copy( aszTemp, ptData->m_strVal.size(), 0 );
            int nRet = atoi( aszTemp );
            return nRet;
        }
    }

    if ( itr == m_vctData.end() )
    {
        
        return nDefault;
    }

    return nDefault;
}

/*=============================================================================
�� �� ��:WriteProfileString
��    ��:���������ݰ��������ļ���ʽд��m_strData��
��    ��:const char *lpAppName                [in]    �ֶ���
         const char *lpKeyName                [in]     Key��
         const char *lpString                 [in]     keyֵ
ע    ��:��
�� �� ֵ:�ɹ�:TRUE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2009/06/15  1.0     �½���    ����
=============================================================================*/
bool CParseCfgfile::WriteProfileString(const char *lpAppName, const char *lpKeyName, const char *lpString)
{
    if ( strcmp( lpAppName, "") == 0 || strcmp( lpKeyName, "") == 0 )
    {
        return false;
    }

    string strSec(lpAppName);
    strSec = '[' + strSec + "]\n";
    string strKey(lpKeyName);
    strKey += '=';
    string strVal(lpString);
    strVal += '\n';

    int nSecIndx = m_strData.find( strSec, 0 );
    int nKeyIndx = m_strData.find( strKey, nSecIndx );
    if ( nSecIndx != string::npos )
    {
        int nNextSecIndx = m_strData.find( '[', nSecIndx + 1 );
        if ( nKeyIndx > nNextSecIndx )      //lpKeyName is in the next section and means the lpAppName doesn't has the key , add it 
        {
            goto Add_Key;
        }

        if ( nKeyIndx != string::npos ) //has exist key and then delete the old one and renew the value of the key
        {
            nKeyIndx += strKey.size();
            int nValIndx = m_strData.find( '\n', nKeyIndx );
            m_strData.erase( nKeyIndx, nValIndx - nKeyIndx + 1 );
            m_strData.insert( nKeyIndx, strVal );
        } 
        else
        {
Add_Key:    nSecIndx = m_strData.find( '[', nSecIndx + 1 ); //find the next section index

            if ( nSecIndx != string::npos ) //the next section exist and then insert before the index
            {
                m_strData.insert( nSecIndx, strKey + strVal );
            } 
            else    //not find then put the data at the end of m_strData
            {
                m_strData += strKey + strVal;
            }
        }
    } 
    else
    {
        m_strData += strSec + strKey + strVal;
    }
    return true;
}

/*=============================================================================
�� �� ��:WriteProfileInt
��    ��:���������ݰ��������ļ���ʽд��m_strData��
��    ��:const char *lpAppName                [in]    �ֶ���
         const char *lpKeyName                [in]     Key��
         int nVal                             [in]     keyֵ
ע    ��:��
�� �� ֵ:�ɹ�:TRUE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2009/06/15  1.0     �½���    ����
=============================================================================*/
bool CParseCfgfile::WriteProfileInt(const char *lpAppName, const char *lpKeyName, int nVal)
{
    if ( strcmp( lpAppName, "") == 0 || strcmp( lpKeyName, "") == 0 )
    {
        return false;
    }

    string strSec(lpAppName);
    strSec = '[' + strSec + "]\n";
    string strKey(lpKeyName);
    strKey += '=';

    char aszTemp[MAX_DATA_BUF_LEN] = {0};
    itoa( nVal, aszTemp, 10 );
    string strVal(aszTemp);
    strVal += '\n';

    int nSecIndx = m_strData.find( strSec, 0 );
    int nKeyIndx = m_strData.find( strKey, nSecIndx );
    if ( nSecIndx != string::npos )
    {
        int nNextSecIndx = m_strData.find( '[', nSecIndx + 1 );
        if ( nKeyIndx > nNextSecIndx )      //lpKeyName is in the next section and means the lpAppName doesn't has the key , add it 
        {
            goto Add_Key;
        }

        if ( nKeyIndx != string::npos ) //has exist key and then delete the old one and renew the value of the key
        {
            nKeyIndx += strKey.size();
            int nValIndx = m_strData.find( '\n', nKeyIndx );
            m_strData.erase( nKeyIndx, nValIndx - nKeyIndx + 1 );
            m_strData.insert( nKeyIndx, strVal );
        } 
        else
        {
Add_Key:    nSecIndx = m_strData.find( '[', nSecIndx + 1 ); //find the next section index

            if ( nSecIndx != string::npos ) //the next section exist and then insert before the index
            {
                m_strData.insert( nSecIndx, strKey + strVal );
            } 
            else    //not find then put the data at the end of m_strData
            {
                m_strData += strKey + strVal;
            }
        }
    } 
    else
    {
        m_strData += strSec + strKey + strVal;
    }
    return true;
}
