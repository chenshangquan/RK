/*=============================================================================
ģ   ��   ��: ��
��   ��   ��: TraceRT.cpp
�� ��  �� ��: TraceRT.h
�ļ�ʵ�ֹ���: tracert����
��        ��: ���
��        ��: V4.0  Copyright(C) 2003-2006 Kedacom, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2006/06/06  4.0     ���        ����
=============================================================================*/

#include "stdafx.h"
#include "icmpstruct.h"
#include "tracert.h"

#ifdef WIN32
#include <ws2tcpip.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif  //  _DEBUG
#endif  //  WIN32

#define TRACERT_PACKSIZE        (s32)64     //�������Ͱ���Ϊ64�ֽ�

CTraceRoute::CTraceRoute() : m_dwHostIP(0), m_pfnResult(NULL), m_pcbData(NULL)
{
}

CTraceRoute::~CTraceRoute()
{
}

/*=============================================================================
�� �� ��:SetParam
��    ��:���ò���
��    ��:u32 dwHostIP                   [in]    �Զ�IP��ַ(������)
         PFNTraceRTResult pfnResult     [in]    �ص�����
         void *pcbData                  [in]    �ص�����
ע    ��:��
�� �� ֵ:���������
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2006/06/06  4.0     ���    ����
=============================================================================*/
BOOL32 CTraceRoute::SetParam(u32 dwHostIP, PFNTraceRTResult pfnResult,
                             void *pcbData)
{
    if ( ! CheckParam( dwHostIP, pfnResult ) )
    {
        return FALSE;
    }

    m_dwHostIP = dwHostIP;
    m_pfnResult = pfnResult;
    m_pcbData = pcbData;

    return TRUE;
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
2006/06/06  4.0     ���    ����
=============================================================================*/
BOOL32 CTraceRoute::Start(void)
{
    BOOL32 bStop = FALSE;
    if ( ! CheckParam(m_dwHostIP, m_pfnResult) )
    {
        return FALSE;
    }

    sockaddr_in tDst = {0},tSrc;
    tDst.sin_family = AF_INET;
    tDst.sin_port = 0;
    tDst.sin_addr.s_addr = htonl( m_dwHostIP );

    for ( s32 nIndex = 0; nIndex < MAX_GW_NUM; nIndex ++ )
    {
        u32 dwGWIPAddr = 0;
        TTraceRtRst tTraceRst;

        for ( s32 nTestIdx = 0; nTestIdx < TEST_PER_GW; nTestIdx ++ )
        {
            SOCKET s = socket( AF_INET, SOCK_RAW, IPPROTO_ICMP );
            if ( s == INVALID_SOCKET )
            {
                s = NULL;
                tTraceRst.m_byTraceRt = emTraceRtUnreachable;
                m_pfnResult( m_pcbData, tTraceRst );
                return FALSE;
            }

            u32 dwSendTime = GetTickCount();
            BOOL32 bRet = SendReq( s, static_cast<u16>(nIndex) + 1 );
            if ( ! bRet )
            {
                closesocket( s );
                s = NULL;
                tTraceRst.m_byTraceRt = emTraceRtUnreachable;
                m_pfnResult( m_pcbData, tTraceRst );
                return FALSE;
            }


			struct timeval tTimeVal;
			tTimeVal.tv_sec = 4 ; 
			tTimeVal.tv_usec=0 ;

			fd_set  readSet;
			FD_ZERO(&readSet);
			FD_SET(s,&readSet);
			if (select(0,&readSet,NULL,NULL,&tTimeVal)==0)
			{
				closesocket( s );
				if (nTestIdx+1==TEST_PER_GW)
				{
					tTraceRst.m_byTraceRt = emTraceRtUnreachable;
					m_pfnResult( m_pcbData, tTraceRst );
					return FALSE;
				}
				else
				{
					continue;
				}
				
			}

            IICMPMsg tRcvMsg;
            int nFromLen = sizeof (tSrc);
            int nRet = recvfrom( s, reinterpret_cast<s8*>(&tRcvMsg),
                                 sizeof (tRcvMsg), 0,
                                 reinterpret_cast<SOCKADDR*>(&tSrc),
                                 &nFromLen );
            u32 dwEchoTime = GetTickCount();
            if ( nRet == SOCKET_ERROR )     //���մ���, ��Ϊ�ǶԶ˲��ɼ�
            {
                closesocket( s );
                s = NULL;
                tTraceRst.m_byTraceRt = emTraceRtUnreachable;
                m_pfnResult( m_pcbData, tTraceRst );
                return FALSE;
            }

            switch ( tRcvMsg.m_tIPHdr.GetType() )
            {
            case emDstUnreachable:
//                if ( tRcvMsg.m_tIPHdr.GetCode() == emUnreachHost )   //�Զ˲��ɼ�
//                {
                    closesocket( s );
                    s = NULL;
                    tTraceRst.m_byTraceRt = emTraceRtUnreachable;
                    m_pfnResult( m_pcbData, tTraceRst );
                    return FALSE;
//                }
//                else        //  �˿�����Ӧ, �������в��ɼ���Ϣ, ֪ͨ�ϲ�, ������
//                {
//                    while ( nTestIdx < MAX_GW_NUM )
//                    {
//                        recvfrom( s, reinterpret_cast<s8*>(&tRcvMsg),
//                                  sizeof (tRcvMsg), 0,
//                                  reinterpret_cast<SOCKADDR*>(&tDst),
//                                  &nFromLen );
//                        nTestIdx ++;
//                    }
//                    tTraceRst.m_byTraceRt = emTraceRtGW;
//                    tTraceRst.m_dwGWIP = tRcvMsg.m_tIPHdr.m_tIPHdr.GetSrcIPAddr();
//                    bStop = ! m_pfnResult( m_pcbData, tTraceRst );
//                    if ( bStop )
//                    {
//                        closesocket( s );
//                        s = NULL;
//                        return FALSE;
//                    }
//                }
                break;
            case emTimeExceeded:
                dwGWIPAddr = tRcvMsg.m_tIPHdr.m_tIPHdr.GetSrcIPAddr();
                closesocket( s );
                s = NULL;
                tTraceRst.m_byTraceRt = emTraceRtEcho;
                tTraceRst.m_dwEchoTime = dwEchoTime - dwSendTime;
                bStop = ! m_pfnResult( m_pcbData, tTraceRst );
                if ( bStop )
                {
                    return FALSE;
                }
                break;
            case emEchoReply:
                closesocket( s );
                s = NULL;
                tTraceRst.m_byTraceRt = emTraceRtEnd;
                m_pfnResult( m_pcbData, tTraceRst );
                return TRUE;
            default:
                tTraceRst.m_byTraceRt = emTraceRtOtherMsg;
                bStop = ! m_pfnResult( m_pcbData, tTraceRst );
                if ( bStop )
                {
                    closesocket( s );
                    s = NULL;
                    return FALSE;
                }
                break;
            }
        }

        if ( dwGWIPAddr > 0 )
        {
            tTraceRst.m_byTraceRt = emTraceRtGW;
            tTraceRst.m_dwGWIP = dwGWIPAddr;
            bStop = ! m_pfnResult( m_pcbData, tTraceRst );
        }
    }

    return FALSE;
}

/*=============================================================================
�� �� ��:CheckParam
��    ��:������
��    ��:u32 dwHostIP                   [in]    �Զ�IP��ַ(������)
         PFNTraceRTResult pfnResult     [in]    �ص�����
ע    ��:��
�� �� ֵ:�����Ϸ�: TRUE; �����Ƿ�: FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2006/06/06  4.0     ���    ����
=============================================================================*/
BOOL32 CTraceRoute::CheckParam(u32 dwHostIP, PFNTraceRTResult pfnResult)
{
    if ( pfnResult != NULL )
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*=============================================================================
�� �� ��:SendReq
��    ��:��������
��    ��:SOCKET s                       [in]    socket
         u16 wSN                        [in]    ���к�
ע    ��:��
�� �� ֵ:���ͳɹ�: TRUE; ����ʧ��: FALSE
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���  �޸�����
2006/06/06  4.0     ���    ����
=============================================================================*/
BOOL32 CTraceRoute::SendReq(SOCKET s, u16 wSN)
{
    sockaddr_in tDst = {0};
    tDst.sin_family = AF_INET;
    tDst.sin_port = 0;
    tDst.sin_addr.s_addr = htonl( m_dwHostIP );

    s32 nTTL = static_cast<s32>(wSN);
    int nRet = setsockopt( s, IPPROTO_IP, IP_TTL, reinterpret_cast<s8*>(&nTTL),
                           sizeof (nTTL) );
    if ( nRet ==  SOCKET_ERROR )    //����socket����ʱ��ʧ��, ��Ϊ�Զ˲��ɼ�
    {
        return FALSE;
    }

    IIcmpSendMsg tIcmpReq;
    u8 abyBuf[TRACERT_PACKSIZE] = {0};
    memset( abyBuf, 0, sizeof (abyBuf) );
    memcpy( tIcmpReq.m_abyBuf, abyBuf, sizeof (abyBuf) );
    s32 nLen = sizeof (tIcmpReq) - sizeof (tIcmpReq.m_abyBuf) + TRACERT_PACKSIZE;
    TTraceRtRst tTraceRst;

    tIcmpReq.SetID( static_cast<u16>(GetCurrentProcessId()) );
    tIcmpReq.SetSerialNo( wSN );
    tIcmpReq.SetCheckSum( 0 );
    s32 nSendTime = GetTickCount();
    tIcmpReq.SetTimeStamp( nSendTime );
    u16 wCheckSum = MakeCheckSum( reinterpret_cast<u8*>(&tIcmpReq), nLen );
    tIcmpReq.SetCheckSum( wCheckSum );

    nRet = sendto( s, reinterpret_cast<s8*>(&tIcmpReq), nLen, 0,
                   reinterpret_cast<SOCKADDR*>(&tDst), sizeof (tDst) );
    if ( nRet == SOCKET_ERROR )     //���ʹ���, ��Ϊ�ǶԶ˲��ɼ�
    {
        return FALSE;
    }

    return TRUE;
}