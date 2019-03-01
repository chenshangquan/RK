/*=============================================================================
ģ   ��   ��: ���ܹ���ģ���
��   ��   ��: ftpctrl.cpp
�� ��  �� ��: ftpctrl.h
�ļ�ʵ�ֹ���: FTP�ϴ����ؿ���
��        ��: ���
��        ��: V4.0  Copyright(C) 2003-2005 KDC, All rights reserved.
˵        ��: ��Ҫʹ��MFC, ʹ������Ҫ����wininet.lib��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2005/09/29  4.0     ���        ����
=============================================================================*/

#include "stdafx.h"
#include "ftpctrl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//#pragma comment(lib, "wininet.lib")

#define INTERNET_STATUS_USER_INPUT_REQUIRED		0x00000040
#define INTERNET_STATUS_DETECTING_PROXY			80

#define FTP_FILE_ASCII_COUNT    (s32)11
LPCTSTR g_pszAsciiFileExt[FTP_FILE_ASCII_COUNT] =
{
    _T(".txt"),
    _T(".ini"),
    _T(".c"),
    _T(".cpp"),
    _T(".h"),
    _T(".hpp"),
    _T(".bat"),
    _T(".html"),
    _T(".java"),
    _T(".htm"),
    _T(".jav")
//    _T(".doc")
};

/*=============================================================================
�� �� ��:FtpCtrl_CallbackStatus
��    ��:����CFtpCtrl�ص���Ԫ����
��    ��:HINTERNET hInternet                [in]    �ص����
         DWORD dwContext                    [in]    CFtpCtrl
         DWORD dwInternetStatus             [in]    ����״̬
         LPVOID lpvStatusInformation        [in]    ����״̬��Ϣ
         DWORD dwStatusInformationLength    [in]    ������Ϣ����
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/09/29  4.0     ���    ����
=============================================================================*/
void CALLBACK FtpCtrl_CallbackStatus(HINTERNET hInternet,
                                     DWORD dwContext,
                                     DWORD dwInternetStatus,
                                     LPVOID lpvStatusInformation,
                                     DWORD dwStatusInformationLength)
{
    CFtpCtrl *pcFtpCtrl = reinterpret_cast<CFtpCtrl*>(dwContext);

    if ( pcFtpCtrl == NULL )
    {
        return;
    }

    LPDWORD pdwInformation(NULL);
    TRACE("FtpCtrl_CallbackStatus's Internet Status is %d\n", dwInternetStatus);

    switch ( dwInternetStatus )
    {
    case INTERNET_STATUS_RESOLVING_NAME:        //  10
        TRACE( "Looking up the IP address for %s\n", (LPCTSTR)lpvStatusInformation );
        break;
    case INTERNET_STATUS_NAME_RESOLVED:         //  11
        TRACE( "Name resolved %s\n", (LPCTSTR)lpvStatusInformation );
        break;
    case INTERNET_STATUS_CONNECTING_TO_SERVER:  //  20
        // lpvStatusInformation��һ��SOCKADDR��ָ��
        TRACE( "Connecting to server--%s...\n", (LPCTSTR)lpvStatusInformation );
        break;
    case INTERNET_STATUS_CONNECTED_TO_SERVER:   //  21
        // lpvStatusInformation��һ��SOCKADDR��ָ��
        TRACE( "Connected to server--%s\n", (LPCTSTR)lpvStatusInformation );
        break;
    case INTERNET_STATUS_SENDING_REQUEST:       //  30
        TRACE( "Sending request\n" );
        break;
    case INTERNET_STATUS_REQUEST_SENT:          //  31
        {
            //  �������ݵ�������
            if ( pcFtpCtrl->GetFtpDirect() == emFtpUpload )
            {
                //  ֻ�е������ϴ�״̬��ʱ��Ŵ���
                if ( pcFtpCtrl->m_dwFtpHead > 0 && pcFtpCtrl ->m_dwFtpHead < 5 )
                {
                    // 5���ֵ��һ������ֵ������Ϊʲô������û�������о�RFC��Э��
                    // ���Ի���֪�����������֪��ԭ�򣬿��Բ�����
                    pcFtpCtrl->m_dwFtpHead++;
                }
                else if ( pcFtpCtrl->m_dwFtpHead == 5 )
                {
                    pdwInformation = (LPDWORD)lpvStatusInformation;
                    u32 dwCurSize = pcFtpCtrl->IncreaseFtpSize(*pdwInformation);
					if ( pcFtpCtrl->isNeedUpdate( *pdwInformation) )
					{
						TRACE( "���η��͵����ݴ�СΪ: %d���ܹ�����Ϊ��%d\n",
                           *pdwInformation, dwCurSize );
						pcFtpCtrl->PostMsg( emFtpTransfer, dwCurSize );
					}
                }
            }
            break;
        }
    case INTERNET_STATUS_RESPONSE_RECEIVED:     // 41
        {
            //  �ӷ��������յ�����Ӧ
            if ( pcFtpCtrl->GetFtpDirect() == emFtpDownload )
            {
                //  ֻ�е���������״̬��ʱ�򣬲Ŵ���
                pdwInformation = (LPDWORD)lpvStatusInformation;
                if ( pcFtpCtrl->m_dwFtpHead > 0 && pcFtpCtrl->m_dwFtpHead < 6 )
                {
                    //  6���ֵ��һ������ֵ������Ϊʲô������û�������о�rfc��Э��
                    //  ���Ի���֪�����������֪��ԭ�򣬿��Բ�����
                    pcFtpCtrl->m_dwFtpHead++;
                    TRACE( "������֮���%d�ν������ݣ�%d\n",
                           pcFtpCtrl->m_dwFtpHead,
                           static_cast<DWORD>(*pdwInformation) );
                }
                else if ( pcFtpCtrl->m_dwFtpHead == 6 )
                {
                    pdwInformation = (LPDWORD)lpvStatusInformation;
                    u32 dwCurSize = pcFtpCtrl->IncreaseFtpSize(*pdwInformation);
					if ( pcFtpCtrl->isNeedUpdate( *pdwInformation) )
					{
						TRACE( "���ν��յ����ݴ�СΪ: %d���ܹ�����Ϊ��%d\n",
                           *pdwInformation, dwCurSize );
						pcFtpCtrl->PostMsg( emFtpTransfer, dwCurSize );
					}
                }
            }
            break;
        }
    case INTERNET_STATUS_RECEIVING_RESPONSE:    //  40
        TRACE( "�ȴ�����������Ӧ��\n" );
        break;
    case INTERNET_STATUS_CTL_RESPONSE_RECEIVED: //  42
    case INTERNET_STATUS_PREFETCH:              //  43
    case INTERNET_STATUS_CLOSING_CONNECTION:    //  50
        TRACE( "Closing connection\n" );
        break;
    case INTERNET_STATUS_CONNECTION_CLOSED:     //  51
        TRACE( "Connection closed\n" );
        break;
    case INTERNET_STATUS_HANDLE_CREATED:        //  60
        {
            LPINTERNET_ASYNC_RESULT ptIAR
                = reinterpret_cast<LPINTERNET_ASYNC_RESULT>(lpvStatusInformation);
            TRACE( "InternetConnect Handle Created with Error: %d, Result: %d\n",
                   ptIAR->dwError, ptIAR->dwResult );
            if ( hInternet == pcFtpCtrl->GetCurrentConnect() )
            {
                TRACE( "Connect Handle Created!\n" );
                pcFtpCtrl->m_dwFtpHead = 1;
            }
            else if ( hInternet == pcFtpCtrl->GetCurrentSession() )
            {
                TRACE( "Session handle created!\n" );
            }
            break;
        }
    case INTERNET_STATUS_HANDLE_CLOSING:        //  70
        pcFtpCtrl->m_dwFtpHead = 0;
        TRACE( "Handle closed with dif %d!\n",
               pcFtpCtrl->GetCurProcSize() - pcFtpCtrl->GetTotalFileSize() );
        break;
    case INTERNET_STATUS_DETECTING_PROXY:       //  80
        TRACE( "Detecting proxy\n" );
        break;
    case INTERNET_STATUS_REQUEST_COMPLETE:      //  100
        {
            LPINTERNET_ASYNC_RESULT ptIAR =
                reinterpret_cast<LPINTERNET_ASYNC_RESULT>(lpvStatusInformation);
            TRACE( "һ���첽������ɣ�����Ϊ��%d�����Ϊ��%d\n",
                   ptIAR->dwError, ptIAR->dwResult );
            break;
        }
    case INTERNET_STATUS_REDIRECT:              //  110
        TRACE( "HTTP request redirected to \n" );
        break;
    case INTERNET_STATUS_INTERMEDIATE_RESPONSE: //  120
        TRACE( "Received intermediate status message from the server.\n" );
        break;
    case INTERNET_STATUS_STATE_CHANGE:          //  200
        {
            TRACE( "Moved between a secure and a nonsecure site\n" );
            LPDWORD pdwRead = (LPDWORD)lpvStatusInformation;
            switch ( *pdwRead )
            {
            case INTERNET_STATE_CONNECTED:          //  0x00000001
                TRACE( "Connected state moved between secure and nonsecure site\n" );
                break;
            case INTERNET_STATE_DISCONNECTED:       //  0x00000002
                TRACE( "Disconnected from network\n" );
                break;
            case INTERNET_STATE_DISCONNECTED_BY_USER:   //  0x00000010
                TRACE( "Disconnected by user request\n" );
                break;
            case INTERNET_STATE_IDLE:               //  0x00000100
                TRACE( "No network requests are being made (by Wininet).\n" );
                break;
            case INTERNET_STATE_BUSY:               //  0x00000200
                TRACE( "Network requests are being made (by Wininet).\n" );
                break;
            case INTERNET_STATUS_USER_INPUT_REQUIRED:   //  0x00000040
                TRACE( "The request requires user input to complete\n" );
                break;
            default:
                break;
            }
            break;
        }
    default:
        break;
    }
}

/*=============================================================================
�� �� ��:FtpCtrlDownloadThread
��    ��:FTP�����̻߳ص�����
��    ��:LPVOID pParam                      [in]    CFtpCtrl
ע    ��:��
�� �� ֵ:�ɹ�: 0    ʧ��: -1
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/10/08  4.0     ���    ����
=============================================================================*/
DWORD WINAPI FtpCtrlDownloadThread(LPVOID pParam)
{
    CFtpCtrl *pcFtpCtrl = reinterpret_cast<CFtpCtrl*>(pParam);
    if ( pcFtpCtrl == NULL )
    {
        return -1;
    }
    
    //  ��ȡ�ļ�
    BOOL32 bRet = FtpGetFile( pcFtpCtrl->GetCurrentConnect(),
                              pcFtpCtrl->GetCurrentRemoteFile(),
                              pcFtpCtrl->GetCurrentLocalFile(),
                              FALSE,
                              FILE_ATTRIBUTE_NORMAL,
                              pcFtpCtrl->GetCurrentFileType()
                                | INTERNET_FLAG_RELOAD
                                | INTERNET_FLAG_RESYNCHRONIZE,
                              (u32)pcFtpCtrl );
    if ( ! bRet )
    {
        LPTSTR pszMsg = NULL;
        DWORD dwErrorId = GetLastError();
        CFtpCtrl::FormatFtpError( dwErrorId, &pszMsg );
        TRACE( "FtpGetFile Error with %d--%s\n", dwErrorId, pszMsg );
        LocalFree( pszMsg );
        pszMsg = NULL;
    }

    pcFtpCtrl->PostMsg( emFtpEnd, bRet ? 0 : GetLastError() );

    if ( pcFtpCtrl->IsDelRemoteFileAfterDownload() )
    {
        FtpDeleteFile( pcFtpCtrl->GetCurrentConnect(),
                       pcFtpCtrl->GetCurrentRemoteFile() );
    }

	if ( !pcFtpCtrl->m_bIsConnect )
	{
		pcFtpCtrl->EndFtpFile();
		TRACE( "FtpGetFile Thread with id 0x%x end!\n", GetCurrentThreadId() );
	}

    return bRet ? 0 : -1;
}

/*=============================================================================
�� �� ��:FtpCtrlUploadThread
��    ��:FTP�ϴ��̻߳ص�����
��    ��:LPVOID pParam                      [in]    CFtpCtrl
ע    ��:��
�� �� ֵ:�ɹ�: 0    ʧ��: -1
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/10/08  4.0     ���    ����
=============================================================================*/
DWORD WINAPI FtpCtrlUploadThread(LPVOID pParam)
{
    CFtpCtrl *pcFtpCtrl = reinterpret_cast<CFtpCtrl*>(pParam);
    if ( pcFtpCtrl == NULL )
    {
        return -1;
    }

    FtpDeleteFile( pcFtpCtrl->GetCurrentConnect(),
                   pcFtpCtrl->GetCurrentRemoteFile() );
    //  �ϴ��ļ�
    BOOL32 bRet = FtpPutFile( pcFtpCtrl->GetCurrentConnect(),
                              pcFtpCtrl->GetCurrentLocalFile(),
                              pcFtpCtrl->GetCurrentRemoteFile(),
                              pcFtpCtrl->GetCurrentFileType()
                                | INTERNET_FLAG_RESYNCHRONIZE,
                              (DWORD)pcFtpCtrl );
    if ( ! bRet )
    {
        LPTSTR pszMsg = NULL;
        DWORD dwErrorId = GetLastError();
        CFtpCtrl::FormatFtpError( dwErrorId, &pszMsg );
        TRACE( "FtpPutFile Error with %d--%s\n", dwErrorId, pszMsg );
        LocalFree( pszMsg );
        pszMsg = NULL;
    }

    pcFtpCtrl->PostMsg( (WPARAM)emFtpEnd, bRet ? 0 : GetLastError() );

	if ( !pcFtpCtrl->GetIsRenameTransFile() && pcFtpCtrl->GetAutoEndFtpFile() )  //  ���������������������   �������������ٹر�FTP   by ldy 2013.01.22
	{
		pcFtpCtrl->EndFtpFile();
		TRACE( "FtpPutFile Thread with id 0x%x end!\n", GetCurrentThreadId() );
	}

    return bRet ? 0 : -1;
}

//////////////////////////////////////////////////////////////////////////
//
//      CFtpCtrl
//

/*=============================================================================
�� �� ��:CFtpCtrl
��    ��:���캯��
��    ��:��
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/09/29  4.0     ���    ����
=============================================================================*/
CFtpCtrl::CFtpCtrl() : m_hSession( NULL )
                       ,m_hConnect( NULL )
                       ,m_wFtpSrvPort( INTERNET_DEFAULT_FTP_PORT )
                       ,m_hFtpThread( NULL )
                       ,m_pszAgent( NULL )
                       ,m_dwFtpThreadId( 0 )
                       ,m_hWnd( NULL )
                       ,m_dwFileType( FTP_TRANSFER_TYPE_UNKNOWN )
                       ,m_dwCurrentFtpSize( 0 )
                       ,m_dwTotalFileSize( TRUE )
                       ,m_dwEventId( 0 )
                       ,m_dwFtpHead( 0 )
                       ,m_bTransfering( FALSE )
                       ,m_bDelRemoteFile( FALSE )
                       ,m_byFtpDirect( emFtpDownload )
					   ,m_bIsRenameTransFile( FALSE )
					   ,m_bIsConnect( FALSE )
					   ,m_bAutoEndFtpFile( TRUE )
{
    ZeroMemory( m_aszFtpSrvIp,      sizeof (m_aszFtpSrvIp) );
    ZeroMemory( m_aszFtpSrvUser,    sizeof (m_aszFtpSrvUser) );
    ZeroMemory( m_aszFtpSrvPwd,     sizeof (m_aszFtpSrvPwd) );
    ZeroMemory( m_aszProxyName,     sizeof (m_aszProxyName) );
    ZeroMemory( m_aszProxyPwd,      sizeof (m_aszProxyPwd) );
    ZeroMemory( m_aszRemoteFile,    sizeof (m_aszRemoteFile) );
    ZeroMemory( m_aszLocalFile,     sizeof (m_aszLocalFile) );
}

/*=============================================================================
�� �� ��:~CFtpCtrl
��    ��:��������
��    ��:��
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/09/29  4.0     ���    ����
=============================================================================*/
CFtpCtrl::~CFtpCtrl()
{
    if ( m_pszAgent != NULL )
    {
        delete [] m_pszAgent;
        m_pszAgent = NULL;
    }
    EndFtpFile();
}

/*=============================================================================
�� �� ��:IsFileAscii
��    ��:�ж�һ��Ҫ�����ļ�������ļ��Ƿ���ASCII��ʽ��
��    ��:LPCTSTR pszFileName                [in]    �ļ���
ע    ��:��
�� �� ֵ:�Ƿ�ASCII��ʽ
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/09/29  4.0     ���    ����
=============================================================================*/
BOOL32 CFtpCtrl::IsFileAscii(LPCTSTR pszFileName)
{
    if ( pszFileName == NULL )
    {
        return FALSE;
    }

    LPCTSTR pszExt = _tcsrchr( pszFileName, '.' );
    if ( pszExt == NULL )
    {
        return FALSE;
    }

    for ( s32 nIndex = 0; nIndex < FTP_FILE_ASCII_COUNT; nIndex ++ )
    {
        if ( _tcsicmp( pszExt, g_pszAsciiFileExt[nIndex] ) == 0 )
        {
            return TRUE;
        }
    }

    return FALSE;
}


/*=============================================================================
�� �� ��:FormatFtpError
��    ��:��ȡϵͳ�Ĵ�������
��    ��:u32 dwErrorCode                    [in]    ������
         LPTSTR *ppszMsg                    [out]   ������Ϣ
ע    ��:ppszMsgʹ�ý����������LocalFree���ͷŸÿռ�
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/09/29  4.0     ���    ����
=============================================================================*/
void CFtpCtrl::FormatFtpError(DWORD dwErrorCode, LPTSTR *ppszMsg)
{
    if ( ppszMsg != NULL )
    {
        if ( dwErrorCode > INTERNET_ERROR_BASE )// ����Internet�Ĵ���Ҫ���⴦��
        {
            DWORD dwBufLen = 0;
            InternetGetLastResponseInfo( &dwErrorCode, NULL, &dwBufLen );
            LPTSTR pszMsg = (LPTSTR)LocalAlloc( LMEM_ZEROINIT, dwBufLen + 1 );
            InternetGetLastResponseInfo( &dwErrorCode, pszMsg, &dwBufLen );
            *ppszMsg = pszMsg;
        }
        else        // ��ѯ��ͨ�Ĵ���
        {
            FormatMessage(  FORMAT_MESSAGE_ALLOCATE_BUFFER |
                                FORMAT_MESSAGE_IGNORE_INSERTS |
                                FORMAT_MESSAGE_FROM_SYSTEM,
                            NULL, dwErrorCode,
                            MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),
                            (LPTSTR)ppszMsg, 0, NULL);
        }
    }
}

/*=============================================================================
�� �� ��:SetServerParam
��    ��:����FTP�����������Ӳ���
��    ��:LPCTSTR pszIpAddr                  [in]    ������IP��ַ
         LPCTSTR pszUser                    [in]    ��¼�û�����
         LPCTSTR pszPwd                     [in]    ��¼����
         u16 wPort                          [in]    FTP�������˿�
         LPCTSTR pszProxyName               [in]    ��������
         LPCTSTR pszProxyPwd                [in]    �������
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/09/29  4.0     ���    ����
=============================================================================*/
BOOL32 CFtpCtrl::SetServerParam(LPCTSTR pszIpAddr, LPCTSTR pszUser,
                                LPCTSTR pszPwd,
                                u16 wPort /* = INTERNET_DEFAULT_FTP_PORT */,
                                LPCTSTR pszProxyName /* = NULL */,
                                LPCTSTR pszProxyPwd /* = NULL */)
{
    if ( pszIpAddr == NULL || pszUser == NULL || pszPwd == NULL )
    {
        return FALSE;
    }

    ZeroMemory( m_aszFtpSrvIp,      sizeof (m_aszFtpSrvIp) );
    ZeroMemory( m_aszFtpSrvUser,    sizeof (m_aszFtpSrvUser) );
    ZeroMemory( m_aszFtpSrvPwd,     sizeof (m_aszFtpSrvPwd) );
    ZeroMemory( m_aszProxyName,     sizeof (m_aszProxyName) );
    ZeroMemory( m_aszProxyPwd,      sizeof (m_aszProxyPwd) );

    _tcsncpy( m_aszFtpSrvIp, pszIpAddr, sizeof (m_aszFtpSrvIp) - 1 );
    _tcsncpy( m_aszFtpSrvUser, pszUser, sizeof (m_aszFtpSrvUser) - 1 );
    _tcsncpy( m_aszFtpSrvPwd, pszPwd, sizeof (m_aszFtpSrvPwd) - 1 );

    if ( pszProxyName != NULL )
    {
        _tcsncpy( m_aszProxyName, pszProxyName, sizeof (m_aszProxyName) - 1 );
    }
    if ( pszProxyPwd != NULL )
    {
        _tcsncpy( m_aszProxyPwd, pszProxyPwd, sizeof (m_aszProxyPwd) - 1 );
    }

    return TRUE;
}

/*=============================================================================
�� �� ��:BeginDownload
��    ��:��ʼ�����ļ�
��    ��:HWND hWnd                          [in]    ������Ϣ�Ĵ��ھ��
         LPCTSTR pszRemoteFile              [in]    Զ���ļ�����
         LPCTSTR pszLocalFile               [in]    ���汾�ص��ļ�����
         u32 dwFileType                     [in]    �ļ���������
         LPCTSTR pszAgent                   [in]    InternetOpen��һ������
         BOOL32 bDeleteRemoteFile           [in]    ������Ϻ��Ƿ�ɾ��Զ���ļ�
ע    ��:��
�� �� ֵ:�Ƿ�ɹ�
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/09/29  4.0     ���    ����
=============================================================================*/
BOOL32 CFtpCtrl::BeginDownload(HWND hWnd, LPCTSTR pszRemoteFile,
                               LPCTSTR pszLocalFile,
                               u32 dwFileType /* = FTP_TRANSFER_TYPE_UNKNOWN */,
                               LPCTSTR pszAgent /* = FTP_AGENT */,
                               BOOL32 bDeleteRemoteFile /* = TRUE */)
{
    if ( ! CheckParam( pszRemoteFile, pszLocalFile, dwFileType ) )
    {
        return FALSE;
    }

    m_hWnd = hWnd;
    m_bDelRemoteFile = bDeleteRemoteFile;

    return DownloadFile( pszRemoteFile, pszLocalFile, dwFileType, pszAgent );
}

/*=============================================================================
�� �� ��:BeginUpload
��    ��:��ʼ�ϴ��ļ�
��    ��:HWND hWnd                          [in]    ������Ϣ�Ĵ��ھ��
         LPCTSTR pszRemoteFile              [in]    Զ���ļ�����
         LPCTSTR pszLocalFile               [in]    ���汾�ص��ļ�����
         u32 dwFileType                     [in]    �ļ���������
         LPCTSTR pszAgent                   [in]    InternetOpen��һ������
ע    ��:��
�� �� ֵ:�Ƿ�ɹ�
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/09/29  4.0     ���    ����
=============================================================================*/
BOOL32 CFtpCtrl::BeginUpload(HWND hWnd, LPCTSTR pszRemoteFile,
                             LPCTSTR pszLocalFile,
                             u32 dwFileType /* = FTP_TRANSFER_TYPE_UNKNOWN */,
                             LPCTSTR pszAgent /* = FTP_AGENT */)
{
    if ( ! CheckParam( pszRemoteFile, pszLocalFile, dwFileType ) )
    {
        return FALSE;
    }

	if ( hWnd == NULL )
	{
		return FALSE;
	}
    m_hWnd = hWnd;

    return UploadFile( pszRemoteFile, pszLocalFile, dwFileType, pszAgent );
}

/*=============================================================================
�� �� ��:CheckParam
��    ��:��鿪ʼ�ϴ�������ʱ����Ĳ����Ƿ���ȷ
��    ��:LPCTSTR pszRemoteFile              [in]    Զ���ļ�����
         LPCTSTR pszLocalFile               [in]    ���汾�ص��ļ�����
         u32 dwFileType                     [in]    �ļ���������
ע    ��:��
�� �� ֵ:�����Ƿ���ȷ
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/09/29  4.0     ���    ����
=============================================================================*/
BOOL32 CFtpCtrl::CheckParam(LPCTSTR pszRemoteFile, LPCTSTR pszLocalFile,
                            u32 dwFileType)
{
    if ( pszRemoteFile == NULL || pszLocalFile == NULL
         || ( dwFileType != FTP_TRANSFER_TYPE_UNKNOWN
              && dwFileType != FTP_TRANSFER_TYPE_ASCII
              && dwFileType != FTP_TRANSFER_TYPE_BINARY ) )
    {
        return FALSE;
    }

    return !m_bTransfering;
}

/*=============================================================================
�� �� ��:DownloadFile
��    ��:�����ļ�
��    ��:LPCTSTR pszRemoteFile              [in]    Զ���ļ�����
         LPCTSTR pszLocalFile               [in]    ���汾�ص��ļ�����
         u32 dwFileType                     [in]    �ļ���������
         LPCTSTR pszAgent                   [in]    InternetOpen��һ������
ע    ��:��
�� �� ֵ:�����Ƿ�ɹ�
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/09/29  4.0     ���    ����
=============================================================================*/
BOOL32 CFtpCtrl::DownloadFile(LPCTSTR pszRemoteFile, LPCTSTR pszLocalFile,
                              u32 dwFileType, LPCTSTR pszAgent)
{
    ZeroMemory( m_aszRemoteFile,    sizeof (m_aszRemoteFile) );
    ZeroMemory( m_aszLocalFile,     sizeof (m_aszLocalFile) );

    _tcsncpy( m_aszRemoteFile, pszRemoteFile, sizeof (m_aszRemoteFile) - 1 );
    _tcsncpy( m_aszLocalFile, pszLocalFile, sizeof (m_aszLocalFile) - 1 );

    m_dwFileType = dwFileType & FTP_TRANSFER_TYPE_MASK;
    m_dwFtpHead = 0;
	m_LastTimeSendMesFileSize = 0;
    m_byFtpDirect = emFtpDownload;

    if ( pszAgent != NULL )
    {
        delete [] m_pszAgent;
        m_pszAgent = new TCHAR [_tcslen(pszAgent) + 1];
        _tcscpy( m_pszAgent, pszAgent );
    }

    //  �����ļ����䷽ʽ
    if ( dwFileType == FTP_TRANSFER_TYPE_UNKNOWN )
    {
        m_dwFileType = IsFileAscii( pszRemoteFile )
                        ? FTP_TRANSFER_TYPE_ASCII : FTP_TRANSFER_TYPE_BINARY;
    }

    // ��ȡԶ���ļ��Ĵ�С, �е�ʱ���ܳɹ�
    m_dwTotalFileSize = GetRemoteFileSize();
    TRACE("Remote File size is %d\n", m_dwTotalFileSize);

    m_dwCurrentFtpSize = 0;

	if ( !m_bIsConnect )
	{
		if ( ! ConnectSrv() )
		{
			EndFtpFile();
			return FALSE;
		}
		m_bIsConnect = TRUE;
	}

    PostMsg( (WPARAM)emFtpBegin, (LPARAM)m_dwTotalFileSize );

    //  �����ļ������߳�
    m_hFtpThread = CreateThread( NULL, 0, FtpCtrlDownloadThread, this,
                                 0, &m_dwFtpThreadId );
    if ( m_hFtpThread == NULL )
    {
        LPTSTR pszMsg = NULL;
        FormatFtpError( GetLastError(), &pszMsg );
        TRACE( "CreateThread Error with %s\n", pszMsg );
        LocalFree( pszMsg );
        InternetCloseHandle( m_hConnect );
        InternetCloseHandle( m_hSession );
        return FALSE;
    }

    //  ���ʹ����̵߳����ȼ�
    SetThreadPriority( m_hFtpThread, THREAD_PRIORITY_BELOW_NORMAL );    
	if ( !m_bIsConnect )
	{
		m_bTransfering = TRUE;
	}
    return TRUE;
}

/*=============================================================================
�� �� ��:UploadFile
��    ��:�ϴ��ļ�
��    ��:LPCTSTR pszRemoteFile              [in]    Զ���ļ�����
         LPCTSTR pszLocalFile               [in]    ���汾�ص��ļ�����
         u32 dwFileType                     [in]    �ļ���������
         LPCTSTR pszAgent                   [in]    InternetOpen��һ������
ע    ��:��
�� �� ֵ:�ϴ��Ƿ�ɹ�
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/09/29  4.0     ���    ����
=============================================================================*/
BOOL32 CFtpCtrl::UploadFile(LPCTSTR pszRemoteFile, LPCTSTR pszLocalFile,
                            u32 dwFileType, LPCTSTR pszAgent)
{
    ZeroMemory( m_aszRemoteFile,    sizeof (m_aszRemoteFile) );
    ZeroMemory( m_aszLocalFile,     sizeof (m_aszLocalFile) );

    _tcsncpy( m_aszRemoteFile, pszRemoteFile, sizeof (m_aszRemoteFile) - 1 );
    _tcsncpy( m_aszLocalFile, pszLocalFile, sizeof (m_aszLocalFile) - 1 );

    m_dwFtpHead = 0;
	m_LastTimeSendMesFileSize = 0;
    m_byFtpDirect = emFtpUpload;
    m_dwFileType = dwFileType & FTP_TRANSFER_TYPE_MASK;

    if ( pszAgent != NULL )
    {
        delete [] m_pszAgent;
        m_pszAgent = new TCHAR [_tcslen(pszAgent) + 1];
        _tcscpy( m_pszAgent, pszAgent );
    }

    //  �����ļ����䷽ʽ
    if ( dwFileType == FTP_TRANSFER_TYPE_UNKNOWN )
    {
        m_dwFileType = IsFileAscii( pszRemoteFile )
                        ? FTP_TRANSFER_TYPE_ASCII : FTP_TRANSFER_TYPE_BINARY;
    }

    //  ���㱾���ļ��Ĵ�С, ֻҪ���ļ�����, ���ܹ��õ���С
    m_dwTotalFileSize = GetLocalFileSize();
    if ( m_dwTotalFileSize == (u32)-1 )
    {
        m_dwTotalFileSize = 0;
        return FALSE;
    }
    TRACE( "Local File size is %d\n", m_dwTotalFileSize );

	m_dwCurrentFtpSize = 0;

    if ( ! ConnectSrv() )
    {
        EndFtpFile();
        return FALSE;
    }

    //  ������Ϣ��֪ͨ���濪ʼ������
    PostMsg( (WPARAM)emFtpBegin, (LPARAM)m_dwTotalFileSize );

    //  �����ļ��ϴ��߳�
    m_hFtpThread = CreateThread( NULL, 0, FtpCtrlUploadThread, this,
                                 0, &m_dwFtpThreadId );
    if ( m_hFtpThread == NULL )
    {
        LPTSTR pszMsg = NULL;
        FormatFtpError( GetLastError(), &pszMsg );
        TRACE( "CreateThread Error with %s\n", pszMsg );
        LocalFree( pszMsg );
        InternetCloseHandle( m_hConnect );
        InternetCloseHandle( m_hSession );
        return FALSE;
    }

    //  ���ʹ����̵߳����ȼ�
    SetThreadPriority( m_hFtpThread, THREAD_PRIORITY_BELOW_NORMAL );
    m_bTransfering = TRUE;
    return TRUE;
}

/*=============================================================================
�� �� ��:ConnectSrv
��    ��:���ӷ�����
��    ��:��
ע    ��:��
�� �� ֵ:�����Ƿ�ɹ�
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/09/29  4.0     ���    ����
=============================================================================*/
BOOL32 CFtpCtrl::ConnectSrv(void)
{
    LPTSTR pszMsg = NULL;
    // ��Internet����
    m_hSession = InternetOpen( m_pszAgent, INTERNET_OPEN_TYPE_DIRECT,
                               m_aszProxyName[0] == 0 ? NULL : m_aszProxyName,
                               m_aszProxyPwd[0] == 0 ? NULL : m_aszProxyPwd,
                               INTERNET_FLAG_NO_CACHE_WRITE);
    if ( m_hSession == NULL )
    {
        FormatFtpError( GetLastError(), &pszMsg );
        TRACE( "InternetOpen Error with %s\n", pszMsg );
        LocalFree( pszMsg );
        return FALSE;
    }

    // ����״̬�ص�����
    if ( InternetSetStatusCallback( m_hSession, FtpCtrl_CallbackStatus )
                == INTERNET_INVALID_STATUS_CALLBACK )
    {
        FormatFtpError( GetLastError(), &pszMsg );
        TRACE( "InternetSetStatusCallback Error with %s\n", pszMsg );
        LocalFree( pszMsg );
        pszMsg = NULL;
        InternetCloseHandle( m_hSession );
        return FALSE;
    }

    //  ���ӵ��Է�
    m_hConnect = InternetConnect( m_hSession, m_aszFtpSrvIp,
                                  m_wFtpSrvPort, m_aszFtpSrvUser,
                                  m_aszFtpSrvPwd, INTERNET_SERVICE_FTP,
                                  /*INTERNET_FLAG_PASSIVE
                                        |*/ INTERNET_FLAG_EXISTING_CONNECT,
                                  (DWORD)this );
    if ( m_hConnect == NULL )
    {
        DWORD dwErrorId = GetLastError();
        FormatFtpError( dwErrorId, &pszMsg );
        TRACE( "InternetConnect Error with %s\n", pszMsg );
        LocalFree( pszMsg );
        pszMsg = NULL;
        InternetCloseHandle( m_hSession );
        //  ֪ͨ���ضԻ�������ʧ��
        PostMsg( (WPARAM)emFtpEnd, dwErrorId );
        return FALSE;
    }

    //����ftp���ͺͽ��յĳ�ʱʱ��
    u32 dwMisSec = FTP_TIMEOUT;
    InternetSetOption( m_hConnect, INTERNET_OPTION_CONTROL_SEND_TIMEOUT,
                       &dwMisSec, sizeof (u32) );
    InternetSetOption( m_hConnect, INTERNET_OPTION_CONTROL_RECEIVE_TIMEOUT,
                       &dwMisSec, sizeof (u32) );
    InternetSetOption( m_hConnect, INTERNET_OPTION_DATA_SEND_TIMEOUT,
                       &dwMisSec, sizeof (u32) );
    InternetSetOption( m_hConnect, INTERNET_OPTION_DATA_RECEIVE_TIMEOUT,
                       &dwMisSec, sizeof (u32) );

    return TRUE;
}

/*=============================================================================
�� �� ��:EndFtpFile
��    ��:ֹͣFTP����
��    ��:��
ע    ��:��
�� �� ֵ:�Ƿ�ɹ�
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/10/08  4.0     ���    ����
=============================================================================*/
BOOL32 CFtpCtrl::EndFtpFile(void)
{
    if ( m_hConnect != NULL )
    {
        InternetCloseHandle(m_hConnect);
        m_hConnect = NULL;
    }
    if ( m_hSession != NULL )
    {
        InternetCloseHandle(m_hSession);
        m_hSession = NULL;
    }
    if ( m_hFtpThread != NULL )
    {
        CloseHandle( m_hFtpThread );
        m_hFtpThread = NULL;
    }
    m_hWnd = NULL;
    m_bTransfering = FALSE;
    m_bIsConnect = FALSE;
	m_bIsRenameTransFile = FALSE;
	m_bAutoEndFtpFile = TRUE;
    return TRUE;
}

/*=============================================================================
�� �� ��:IncreaseFtpSize
��    ��:���ļ����������, ����ʵ���Ѿ�������ļ���С
��    ��:u32 dwProcSize             [in]    ����ɴ�С
ע    ��:��
�� �� ֵ:����ɴ�С
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/10/08  4.0     ���    ����
=============================================================================*/
u32 CFtpCtrl::IncreaseFtpSize(u32 dwProcSize)
{
    if (m_dwCurrentFtpSize < m_dwTotalFileSize)
    {
        m_dwCurrentFtpSize += dwProcSize;
    }
    return m_dwCurrentFtpSize;
}

/*=============================================================================
�� �� ��:GetRemoteFileSize
��    ��:��ȡԶ���ļ��Ĵ�С
��    ��:��
ע    ��:��
�� �� ֵ:Զ���ļ��Ĵ�С
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/09/29  4.0     ���    ����
=============================================================================*/
u32	CFtpCtrl::GetRemoteFileSize(void)
{
    u32 dwRemoteFileSize = GetVaxRemoteFileSize();
    if ( dwRemoteFileSize != -1 && dwRemoteFileSize != 0 )
    {
        return dwRemoteFileSize;
    }

    dwRemoteFileSize = GetWinRemoteFileSize();
    if ( dwRemoteFileSize != -1 && dwRemoteFileSize != 0 )
    {
        return dwRemoteFileSize;
    }

    return 0;
}

/*=============================================================================
�� �� ��:GetLocalFileSize
��    ��:��ȡ�����ļ��Ĵ�С
��    ��:��
ע    ��:��
�� �� ֵ:�����ļ��Ĵ�С
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/09/29  4.0     ���    ����
=============================================================================*/
u32	CFtpCtrl::GetLocalFileSize(void)
{
    //�ж��ļ��Ƿ����
    HANDLE hFile = CreateFile( m_aszLocalFile, 0, 0, NULL, OPEN_EXISTING,
                               FILE_ATTRIBUTE_NORMAL, NULL );
    if ( hFile == INVALID_HANDLE_VALUE )
    {
        return 0;
    }
    //��ȡ�ļ���С
    u32 dwSize = GetFileSize( hFile, NULL );
    CloseHandle( hFile );
    hFile = NULL;

    return dwSize;
}

/*=============================================================================
�� �� ��:GetWinRemoteFileSize
��    ��:��ȡԶ��windows�ļ���С
��    ��:��
ע    ��:��
�� �� ֵ:Զ��windows�ļ���С
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/09/29  4.0     ���    ����
=============================================================================*/
u32 CFtpCtrl::GetWinRemoteFileSize(void)
{
    u32 dwSize          = 0;
    DWORD dwErrorId     = ERROR_SUCCESS;
    LPTSTR pszMsg       = NULL;
    HINTERNET hSession  = NULL;
    HINTERNET hConnect  = NULL;
    HINTERNET hFile     = NULL;
    HINSTANCE hLibrary  = NULL;
    typedef DWORD (WINAPI *FtpGetFileSize_Proc)(HINTERNET, LPDWORD);

    __try
    {
        if ( m_aszRemoteFile[0] == 0 )
        {
            dwSize = 0;
            __leave;
        }

        hSession = InternetOpen( m_pszAgent, INTERNET_OPEN_TYPE_DIRECT,
                                 m_aszProxyName[0] == 0 ? NULL : m_aszProxyName,
                                 m_aszProxyPwd[0] == 0 ? NULL : m_aszProxyPwd,
                                 INTERNET_FLAG_NO_CACHE_WRITE );
        if ( hSession == NULL )
        {
            dwErrorId = GetLastError();
            FormatFtpError( dwErrorId, &pszMsg );
            TRACE( "InternetOpen Error With %d--%s\n", dwErrorId, pszMsg );
            LocalFree( pszMsg );
            dwSize = -1;
            __leave;
        }

        hConnect = InternetConnect( hSession, m_aszFtpSrvIp, m_wFtpSrvPort,
                                    m_aszFtpSrvUser, m_aszFtpSrvPwd,
                                    INTERNET_SERVICE_FTP,
                                    /*INTERNET_FLAG_PASSIVE |*/ INTERNET_FLAG_EXISTING_CONNECT,
                                    0 );
        if ( hConnect == NULL )
        {
            dwErrorId = GetLastError();
            FormatFtpError( dwErrorId, &pszMsg );
            TRACE( "InternetConnect Error With %d--%s\n", dwErrorId, pszMsg );
            LocalFree( pszMsg );
            dwSize = -1;
            __leave;
        }

        hFile = FtpOpenFile( hConnect, m_aszRemoteFile, GENERIC_READ,
                             m_dwFileType | INTERNET_FLAG_RELOAD | INTERNET_FLAG_RESYNCHRONIZE,
                             NULL );
        if ( hFile == NULL )
        {
            dwErrorId = GetLastError();
            FormatFtpError( dwErrorId, &pszMsg );
            TRACE( "FtpOpen Error With %d--%s\n", dwErrorId, pszMsg );
            LocalFree( pszMsg );
            dwSize = -1;
            __leave;
        }

        //ֱ�Ӵ�dll�еõ�FtpGetFileSize��������ȡ�ļ���С
        hLibrary = LoadLibrary("wininet.dll");
        if ( hLibrary == NULL )
        {
            TRACE( "Load Library failed!\n" );
            dwErrorId = GetLastError();
            dwSize = 0;
            __leave;
        }

        FtpGetFileSize_Proc pfnFtpGetFileSize = 
		    (FtpGetFileSize_Proc)GetProcAddress( hLibrary, "FtpGetFileSize" );
        if ( pfnFtpGetFileSize == NULL )
        {
            TRACE( "Get Proc FtpGetFileSize Failed!\n" );
            dwErrorId = GetLastError();
            dwSize = 0;
            __leave;
        }

        dwSize = pfnFtpGetFileSize( hFile, NULL );
    }
    __finally
    {
        if ( hFile != NULL )
        {
            InternetCloseHandle( hFile );
//            hFile = NULL;
        }

        if ( hConnect != NULL )
        {
            InternetCloseHandle( hConnect );
//            hConnect = NULL;
        }

        if ( hSession != NULL )
        {
            InternetCloseHandle( hSession );
//            hSession = NULL;
        }

        if ( hLibrary != NULL )
        {
            FreeLibrary( hLibrary );
//            hLibrary = NULL;
        }

        if ( dwErrorId != ERROR_SUCCESS )
        {
            PostMsg( emFtpEnd, dwErrorId );
        }

        return dwSize;
    }
}

/*=============================================================================
�� �� ��:GetVaxRemoteFileSize
��    ��:��ȡԶ��VAX�ļ���С
��    ��:��
ע    ��:��
�� �� ֵ:Զ��VAX�ļ���С
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/09/29  4.0     ���    ����
=============================================================================*/
u32 CFtpCtrl::GetVaxRemoteFileSize(void)
{
    if ( m_aszRemoteFile[0] == 0 )
    {
        return 0;
    }

    CString cstrRemoteFile( m_aszRemoteFile );
    CString cstrPath( _T("/*.*") );
    s32 nIndex = cstrRemoteFile.ReverseFind( '/' );
    if ( nIndex != -1 )
    {
        cstrPath = cstrRemoteFile.Left( nIndex + 1 );
    }
    else
    {
        nIndex = cstrRemoteFile.ReverseFind( '\\' );
        if ( nIndex != -1 )
        {
            cstrPath = cstrRemoteFile.Left( nIndex + 1 );
        }
    }

    CString cstrFile = cstrRemoteFile.Mid( nIndex + 1 );
    cstrFile.MakeLower();

    LPTSTR pszMsg = NULL;
    HINTERNET hSession = InternetOpen( m_pszAgent, INTERNET_OPEN_TYPE_DIRECT,
									   m_aszProxyName[0] == 0
                                            ? NULL : m_aszProxyName,
									   m_aszProxyPwd[0] == 0
                                            ? NULL : m_aszProxyPwd,
									   INTERNET_FLAG_NO_CACHE_WRITE );
    if ( hSession == NULL )
    {
        u32 dwErrorId = GetLastError();
        FormatFtpError( dwErrorId, &pszMsg );
        TRACE( "InternetOpen Error With %d--%s\n", dwErrorId, pszMsg );
        LocalFree( pszMsg );
        PostMsg( emFtpEnd, dwErrorId );
        return -1;
    }

    HINTERNET hConnect = InternetConnect( hSession, m_aszFtpSrvIp,
                                          m_wFtpSrvPort, m_aszFtpSrvUser,
                                          m_aszFtpSrvPwd, INTERNET_SERVICE_FTP,
                                          /*INTERNET_FLAG_PASSIVE
                                            | */INTERNET_FLAG_EXISTING_CONNECT,
                                          0 );
    if ( hConnect == NULL )
    {
        u32 dwErrorId = GetLastError();
        FormatFtpError( dwErrorId, &pszMsg );
        TRACE( "InternetOpen Error With %d--%s\n", dwErrorId, pszMsg );
        LocalFree( pszMsg );
        PostMsg( emFtpEnd, dwErrorId );
        InternetCloseHandle( hSession );
        return -1;
    }

    WIN32_FIND_DATA sWFD; 
    ZeroMemory( &sWFD, sizeof (sWFD) );
    BOOL32 bResult = TRUE;

    HINTERNET hFileConnection = FtpFindFirstFile( hConnect, cstrPath, &sWFD,
                                                  INTERNET_FLAG_RESYNCHRONIZE
                                                    | INTERNET_FLAG_RELOAD,
                                                  NULL);
    if ( hFileConnection == NULL )
    {
        u32 dwErrorId = GetLastError();
        FormatFtpError( dwErrorId, &pszMsg );
        TRACE( "FtpFindFirstFile Error With %d--%s\n", dwErrorId, pszMsg );
        LocalFree( pszMsg );
        PostMsg( emFtpEnd, dwErrorId );
        InternetCloseHandle( hSession );
        InternetCloseHandle( hSession );
        return -1;
    }

    //���ڴ�vax�ϻ�ȡ�ļ��б�ʱ����ʱ������ԣ�������Ҫ����
    while ( bResult )
    {
        bResult = InternetFindNextFile( hFileConnection, &sWFD );
        CString cstrDir = sWFD.cFileName;
        cstrDir.MakeLower();
        if ( cstrDir.Find( cstrFile ) == -1 )
        {
            continue;
        }

        cstrDir.TrimLeft();
        cstrDir.TrimRight();

        CString cstrSize, cstrDate, cstrTime, cstrName, cstrType;
        //1
        s32 nIndex = cstrDir.Find( ' ' );
        if ( nIndex != -1 )
        {
            cstrSize = cstrDir.Left( nIndex );
            cstrDir = cstrDir.Mid( nIndex );
        }
        else
        {
            continue;
        }

        //2
        cstrDir.TrimLeft();
        nIndex = cstrDir.Find(' ');
        if ( nIndex != -1 )
        {
            cstrDir = cstrDir.Mid( nIndex );
        }
        else
        {
            continue;
        }

        //3
        cstrDir.TrimLeft();
        nIndex = cstrDir.Find(' ');
        if ( nIndex != -1 )
        {
            cstrDir = cstrDir.Mid( nIndex );
        }
        else
        {
            continue;
        }

        //4
        cstrDir.TrimLeft();
        nIndex = cstrDir.Find(' ');
        if ( nIndex != -1 )
        {
	        cstrName = cstrDir.Left( nIndex );
        }
        else
        {
	        cstrName = cstrDir;
        }

        if ( cstrName  == '.' || cstrName == ".." )
        {
            continue;
        }

        if ( cstrRemoteFile.Find( cstrName ) != -1 )
        {			
            InternetCloseHandle( hFileConnection );
            InternetCloseHandle( hConnect );
            InternetCloseHandle( hSession );
            return _ttol( cstrSize );
        }
	}

    InternetCloseHandle( hFileConnection );
    InternetCloseHandle( hConnect );
    InternetCloseHandle( hSession );

    return -1;
}

/*=============================================================================
�� �� ��:PostMsg
��    ��:��Ϣ����
��    ��:WPARAM wParam                  [in]    ��Ϣ������
         LPARAM lParam                  [in]    ��Ϣ����
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2005/10/08  4.0     ���    ����
=============================================================================*/
void CFtpCtrl::PostMsg(WPARAM wParam, LPARAM lParam /* = 0 */)
{
    if ( m_hWnd != NULL )
    {
        PostMessage( m_hWnd, m_dwEventId, wParam, lParam );
    }
}

/*=============================================================================
�� �� ��:DeleteFile
��    ��:��Ϣ����
��    ��:LPCSTR lpszFileName                 [in]    �ļ�����
ע    ��:��
�� �� ֵ:TRUE:�ļ�ɾ���ɹ�	FALSE:�ļ�ɾ��ʧ��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2011/03/21  5.0     ������    ����
=============================================================================*/
BOOL32 CFtpCtrl::DeleteFile(LPCSTR lpszFileName)
{
	if (lpszFileName == NULL)
		return false;
    if ( ! ConnectSrv() )
    {
        EndFtpFile();
        return FALSE;
    }
	BOOL32 bRet = FtpDeleteFile(GetCurrentConnect(), lpszFileName);
	EndFtpFile();
	return bRet;
}

BOOL32 CFtpCtrl::CreateDir( LPCTSTR strDir )
{
	if ( NULL == GetCurrentConnect() )
	{
		if ( !ConnectSrv() )
		{
			return FALSE;
		}
	}

	FtpCreateDirectory( GetCurrentConnect(), strDir );

	EndFtpFile();

	return TRUE;
}

BOOL32 CFtpCtrl::RenameFtpFile( LPCTSTR pszRemoteTempFile, LPCTSTR pszRemoteFile )
{
	HINTERNET nRet = GetCurrentConnect();
	BOOL32 bRet = FtpRenameFile( GetCurrentConnect(), pszRemoteTempFile, pszRemoteFile );

	if ( NULL == GetCurrentConnect() )
	{
		EndFtpFile();
	}

	return bRet;
}

BOOL32 CFtpCtrl::ConnectServer()
{
	if ( ! ConnectSrv() )
    {
        EndFtpFile();
        return FALSE;
    }
	m_bIsConnect = TRUE;
	return TRUE;
}

BOOL32 CFtpCtrl::FindfFtpFile( LPCTSTR pszRemotePath, LPCTSTR pstrRemoteName )
{
	BOOL bRe = FtpSetCurrentDirectory( m_hConnect, pszRemotePath );
	if ( !bRe )
	{
		return FALSE;	
	}

	WIN32_FIND_DATA pData;
	HINTERNET hFind;

	hFind = FtpFindFirstFile( m_hConnect, /*"*.*"*/pstrRemoteName, &pData, 0, 0 );
	if (!hFind)   
	{
		InternetCloseHandle(hFind);
		return FALSE;
	}

	InternetCloseHandle(hFind);
	return TRUE;
}

//���Ʒ�����Ϣ�Ĵ���
BOOL32 CFtpCtrl::isNeedUpdate( u32 dwProcSize )
{
	u32 dwSize = m_dwTotalFileSize/30;
	if ( dwProcSize > dwSize )
	{
		return TRUE;
	}
	else
	{
		if ( m_dwCurrentFtpSize >( m_LastTimeSendMesFileSize +dwSize ))
		{
			m_LastTimeSendMesFileSize = m_dwCurrentFtpSize;
			return TRUE;
		}
	}
	return FALSE;
}

//����Զ���ļ����֣����ڻ�ȡԶ���ļ���С
void CFtpCtrl::SetRemoteFileName(LPCTSTR pszRemoteFileName)
{
	_tcsncpy( m_aszRemoteFile, pszRemoteFileName, sizeof (m_aszRemoteFile) - 1 );
}
