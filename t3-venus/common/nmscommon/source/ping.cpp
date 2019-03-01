/*=============================================================================
ģ   ��   ��: ��
��   ��   ��: Ping.cpp
�� ��  �� ��: Ping.h
�ļ�ʵ�ֹ���: ping����
��        ��: ���
��        ��: V4.0  Copyright(C) 2003-2006 Kedacom, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2006/05/31  4.0     ���        ����
=============================================================================*/

#include "stdafx.h"
#include "icmpstruct.h"
#include "ping.h"
#include <math.h>

#ifdef WIN32
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif  //  _DEBUG
#endif  //  WIN32

#define TRANSLATE(text, lan) strcmp(lan, "chinese") == 0 ? text##CHN : text##ENG

    #define TIMES_ERR_CHN           (LPCSTR)"���Դ����������1-255֮�䣡"
    #define TIMES_ERR_ENG           (LPCSTR)"Test times should between t1 and 255!"
#define TIMES_ERR(lan)          TRANSLATE(TIMES_ERR_, lan)
    #define PACKSIZE_ERR_CHN        (LPCSTR)"���԰����������0-10K�ֽ�֮�䣡"
    #define PACKSIZE_ERR_ENG        (LPCSTR)"Package size should between 0 and 10K bytes!"
#define PACKSIZE_ERR(lan)       TRANSLATE(PACKSIZE_ERR_, lan)
    #define RESTART_CHN             (LPCSTR)"�ڲ���������������"
    #define RESTART_ENG             (LPCSTR)"Internal error! Please restart the service!"
#define RESTART(lan)            TRANSLATE(RESTART_, lan)
    #define NO_ERR_CHN              (LPCSTR)"�����ɹ�"
    #define NO_ERR_ENG              (LPCSTR)"Operation Success"
#define NO_ERR(lan)             TRANSLATE(NO_ERR_, lan)

//��������
enum enumPingErr
{
    emTimesErr          = (u8)1,//��������
    emPackSizeErr       = (u8)2,//��������
    emRestart           = (u8)3,//�ڲ�����, ��Ҫ����
    emNetErr            = (u8)4,//�������
    emNoErr             = (u8)5 //�ɹ�
};

#define ICMP_TIME_OUT           (u8)3   //��ʱʱ��3��

/*=============================================================================
�� �� ��:CPing
��    ��:���캯��
��    ��:��
ע    ��:��
�� �� ֵ:��
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2006/06/02  4.0     ���    ����
=============================================================================*/
CPing::CPing() : m_dwHostIP(0), m_nTimes(0), m_nPackSize(0), m_pfnResult(NULL),
                 m_pcbData(NULL), m_byErrCode(0)
{
    memset( m_aszErrStr, 0, sizeof (m_aszErrStr) );
}

CPing::~CPing()
{
}

/*=============================================================================
�� �� ��:SetParam
��    ��:���ò���
��    ��:u32 dwHostIP                   [in]    �Զ�IP��ַ(������)
         s32 nTimes                     [in]    ���Դ���
         s32 nPackSize                  [in]    ���԰���
         PFNPingResult pfnRst           [in]    �ص�����
         void *pcbData                  [in]    �ص�����
ע    ��:��
�� �� ֵ:���������
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2006/06/05  4.0     ���    ����
=============================================================================*/
BOOL32 CPing::SetParam(u32 dwHostIP, s32 nTimes, s32 nPackSize,
                       PFNPingResult pfnRst, void *pcbData)
{
    if ( ! CheckParam( nTimes, nPackSize, pfnRst ) )
    {
        return FALSE;
    }
    else
    {
        m_dwHostIP = dwHostIP;
        m_nTimes = nTimes;
        m_nPackSize = nPackSize;
        m_pfnResult = pfnRst;
        m_pcbData = pcbData;
        return TRUE;
    }
}

/*=============================================================================
�� �� ��:Start
��    ��:��ʼ����
��    ��:��
ע    ��:��
�� �� ֵ:�ɹ�: TRUE; ʧ��: FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2006/06/05  4.0     ���    ����
2006/08/17  4.0     �Է���  ���ӳ�ʱ��������
=============================================================================*/
BOOL32 CPing::Start(void)
{
    BOOL32 bStop = FALSE;
    SOCKET s = NULL;
    SOCKADDR_IN tDst = {0},tSrc;

    tDst.sin_family = AF_INET;
    tDst.sin_port = 0;
    tDst.sin_addr.s_addr = htonl( m_dwHostIP );
    IIcmpSendMsg tIcmpReq;
    u8 abyBuf[sizeof (tIcmpReq.m_abyBuf)] = {0};
    memset( abyBuf, 'T', sizeof (abyBuf) );
    memcpy( tIcmpReq.m_abyBuf, abyBuf, m_nPackSize );
    s32 nLen = sizeof (tIcmpReq) - sizeof (tIcmpReq.m_abyBuf) + m_nPackSize;
    TPingRst tTestEnd;
    tTestEnd.m_bEnd = TRUE;
    tTestEnd.m_byPingRt = emPingRtEnd;
    bool bBeginCall = true;

	s32  nJitterSum=0;   //�����
	s32  nSum=0;         //��Ӧʱ���ܺ�
    for ( s32 nIndex = 0; nIndex < m_nTimes; nIndex ++ )
    {
        s = socket( AF_INET, SOCK_RAW, IPPROTO_ICMP );
        if ( s == INVALID_SOCKET )
        {
            m_byErrCode = emNetErr;
            return FALSE;
        }

        TPingRst tPingRst;
        tPingRst.m_nTimeCount = nIndex + 1;
        if ( bBeginCall )
        {
            bStop = !m_pfnResult( m_pcbData, tPingRst );
            if ( bStop )
            {
                break;
            }
            Sleep( 1000 );  //���β���֮����1��
        }
        bBeginCall = true;

        tIcmpReq.SetID( static_cast<u16>(GetCurrentProcessId()) );
        tIcmpReq.SetSerialNo( static_cast<u8>(nIndex) );
        tIcmpReq.SetCheckSum( 0 );
        s32 nSendTime = GetTickCount();
        tIcmpReq.SetTimeStamp( nSendTime );
        u16 wCheckSum = MakeCheckSum( reinterpret_cast<u8*>(&tIcmpReq), nLen );
        tIcmpReq.SetCheckSum( wCheckSum );

        int nRet = sendto( s, reinterpret_cast<s8*>(&tIcmpReq), nLen, 0,
                           reinterpret_cast<SOCKADDR*>(&tDst), sizeof (tDst) );
        if ( nRet == SOCKET_ERROR )     //���ʹ���, ��Ϊ�ǶԶ˲��ɼ�
        {
            m_byErrCode = emNetErr;
            tPingRst.m_byPingRt = emPingRtUnreachable;
            bStop = !m_pfnResult( m_pcbData, tPingRst );
            if ( bStop )
            {
                nIndex ++;
                break;
            }
            else
            {
                closesocket(s);
                s = NULL;
                continue;
            }
        }


		//zhaofajie  20060817 ��ⳬʱ
		struct timeval tTimeVal;
		tTimeVal.tv_sec = 4 ; 
		tTimeVal.tv_usec=0 ;
		fd_set  readSet;
		FD_ZERO(&readSet);
		FD_SET(s,&readSet);
		if (select(0,&readSet,NULL,NULL,&tTimeVal)==0)//��ʱ
		{
			tPingRst.m_bEnd=TRUE;
			tPingRst.m_byPingRt = emPingRtTimeOut;
			bStop = !m_pfnResult( m_pcbData, tPingRst );
			closesocket(s);
			continue;
		}
		
		
		
        IICMPMsg tRcvMsg;
        int nFromLen = sizeof (tSrc);
        nRet = recvfrom( s, reinterpret_cast<s8*>(&tRcvMsg),
                         sizeof (tRcvMsg),
                         0, reinterpret_cast<SOCKADDR*>(&tSrc),
                         &nFromLen );
        s32 nReplyTime = GetTickCount();

        if ( nRet == SOCKET_ERROR )     //���մ���, ��Ϊ�ǶԶ˲��ɼ�
        {
            m_byErrCode = emNetErr;
            tPingRst.m_byPingRt = emPingRtUnreachable;
            bStop = !m_pfnResult( m_pcbData, tPingRst );
            if ( bStop )
            {
                nIndex ++;
                break;
            }
            else
            {
                closesocket(s);
                s = NULL;
                continue;
            }
        }

        tPingRst.m_bEnd = TRUE;
        if ( tRcvMsg.m_tIPHdr.GetType() != emEchoReply )    //���صĲ���Ӧ����Ϣ
        {
            switch ( tRcvMsg.m_tIPHdr.GetType() )
            {
            case emTimeExceeded:
                tPingRst.m_byPingRt = emPingRtTimeOut;
                bStop = !m_pfnResult( m_pcbData, tPingRst );
                break;
            case emDstUnreachable:
                tPingRst.m_byPingRt = emPingRtUnreachable;
                bStop = !m_pfnResult( m_pcbData, tPingRst );
                break;
            default:    //����ԭ��, ����Ϊ�Ǵ���, ���²���
                nIndex --;
                bBeginCall = false;
                break;
            }

            if ( bStop )
            {
                nIndex ++;
                break;
            }
            else
            {
                closesocket(s);
                s = NULL;
                continue;
            }
        }

        tagIcmpEchoReplyMsg tEchoReply;
        memcpy( &tEchoReply, &tRcvMsg, sizeof (tEchoReply) );

        //֡��Ŵ���������ݴ�����Ϊ�ǳ�ʱ
        if ( tEchoReply.GetID() != GetCurrentProcessId()
             || tEchoReply.GetSerialNo() != static_cast<u16>(nIndex)
             || memcmp( tEchoReply.m_abyData + 4, abyBuf, m_nPackSize ) != 0 )
        {
            tPingRst.m_byPingRt = emPingRtTimeOut;
            bStop = !m_pfnResult( m_pcbData, tPingRst );
            if ( bStop )
            {
                nIndex ++;
                break;
            }
            else
            {
                closesocket(s);
                s = NULL;
                continue;
            }
        }

        tPingRst.m_byPingRt = emPingRtNoError;
        tPingRst.m_byTTL = tEchoReply.m_tIPHdr.m_tIPHdr.GetTimeToLive();

        if ( tTestEnd.m_nSucCount == 0 )
        {
            tTestEnd.m_nMinEchoTime = tPingRst.m_nEchoTime;
            tTestEnd.m_nMaxEchoTime = tPingRst.m_nEchoTime;
        }
        tTestEnd.m_nMinEchoTime = tTestEnd.m_nMinEchoTime > tPingRst.m_nEchoTime
            ? tPingRst.m_nEchoTime : tTestEnd.m_nMinEchoTime;
        tTestEnd.m_nMaxEchoTime = tTestEnd.m_nMaxEchoTime > tPingRst.m_nEchoTime
            ? tTestEnd.m_nMaxEchoTime : tPingRst.m_nEchoTime;
		nSum+=tPingRst.m_nEchoTime;
		tTestEnd.m_nSucCount ++;
        tTestEnd.m_nAvrEchoTime = nSum/tTestEnd.m_nSucCount;       
		
		nJitterSum+=(tPingRst.m_nEchoTime-tTestEnd.m_nAvrEchoTime)*
			(tPingRst.m_nEchoTime-tTestEnd.m_nAvrEchoTime);
		tTestEnd.m_nJitter=(s32)sqrt(nJitterSum/tTestEnd.m_nSucCount);
        bStop = ! m_pfnResult( m_pcbData, tPingRst );
        if ( bStop )
        {
            nIndex ++;
            break;
        }
    }

    if ( s != NULL && s != INVALID_SOCKET )
    {
        closesocket(s);
        s = NULL;
    }
    tTestEnd.m_nTotalCount = nIndex;
    if ( tTestEnd.m_nSucCount > 0 )
    {
        tTestEnd.m_nAvrEchoTime /= tTestEnd.m_nSucCount;
    }
    else
    {
        tTestEnd.m_nAvrEchoTime = 0;
    }
    m_pfnResult( m_pcbData, tTestEnd );

    m_nPackSize = 0;
    m_nTimes    = 0;
    m_byErrCode = 0;
    m_pfnResult = NULL;
    m_pcbData   = NULL;

    return TRUE;
}

/*=============================================================================
�� �� ��:GetErrStr
��    ��:��ȡ��������
��    ��:LPCSTR lptrLan                 [in]    "english"/"chinese"
ע    ��:��
�� �� ֵ:���������ַ���
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2006/06/05  4.0     ���    ����
=============================================================================*/
LPCSTR CPing::GetErrStr(LPCTSTR lptrLan)
{
    switch ( m_byErrCode )
    {
    case emTimesErr:
        return TIMES_ERR(lptrLan);
    case emPackSizeErr:
        return PACKSIZE_ERR(lptrLan);
    case emRestart:
        return RESTART(lptrLan);
    case emNetErr:
        {
            LPVOID lpMsgBuf = NULL;
            DWORD dwLangID = 0;
            if ( strcmp(lptrLan, "chinese") == 0 )
            {
                dwLangID = MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED);
            }
            else
            {
                dwLangID = MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US);
            }
            if ( FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | 
                                    FORMAT_MESSAGE_FROM_SYSTEM | 
                                    FORMAT_MESSAGE_IGNORE_INSERTS,
                                NULL,
                                static_cast<DWORD>(WSAGetLastError()),
                                dwLangID,
                                reinterpret_cast<LPSTR>(&lpMsgBuf),
                                0,
                                NULL ) > 0 )
            {
                strncpy( m_aszErrStr, reinterpret_cast<s8*>(lpMsgBuf),
                         sizeof (m_aszErrStr) - 1 );
                m_aszErrStr[sizeof (m_aszErrStr) - 1] = '\0';
                LocalFree( lpMsgBuf );
                return m_aszErrStr;
            }
            else
            {
                return NO_ERR(lptrLan);
            }
        }
    default:
        return NO_ERR(lptrLan);
    }
}

/*=============================================================================
�� �� ��:CheckParam
��    ��:������
��    ��:s32 nTimes                     [in]    ���Դ���
         s32 nPackSize                  [in]    ���԰���
         PFNPingResult pfnRst           [in]    �ص�����
ע    ��:��
�� �� ֵ:�����Ϸ�: TRUE; �����Ƿ�: FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2006/06/05  4.0     ���    ����
=============================================================================*/
BOOL32 CPing::CheckParam(s32 nTimes, s32 nPackSize, PFNPingResult pfnRst)
{
    if ( nTimes <= 0 || nTimes > 1000 )
    {
        m_byErrCode = emTimesErr;
        return FALSE;
    }
    else if ( nPackSize <= 0 || nPackSize >= MAX_ICMP_SENDMSG_LEN )
    {
        m_byErrCode = emPackSizeErr;
        return FALSE;
    }
    else if ( pfnRst == NULL )
    {
        m_byErrCode = emRestart;
        return FALSE;
    }

    return TRUE;
}