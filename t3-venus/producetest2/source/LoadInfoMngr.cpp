#include "stdafx.h"
#include "LoadInfoMngr.h"

/*
��Ϣͷ��
ÿ����Ϣbuffer֮ǰ��Ҫ������Ϣͷ������Ϊ��Ϣ���͵�Id	
*/
#define INFO_HEADER(Opt) \
	m_pchSndBuf[m_dwSendBufLen++] = 0;\
	m_pchSndBuf[m_dwSendBufLen++] = 0;\
	m_pchSndBuf[m_dwSendBufLen++] = 0;\
	m_pchSndBuf[m_dwSendBufLen++] = Opt;\
	m_pchSndBuf[m_dwSendBufLen++] = 0;\
	m_pchSndBuf[m_dwSendBufLen++] = 0;\
	m_pchSndBuf[m_dwSendBufLen++] = 0;
/*
��Ϣ���ݺ�
���� pInfo:��Ϣָ��, len:��Ϣ����	
*/
#define INFO_CONTENT( pInfo, len ) \
	m_pchSndBuf[m_dwSendBufLen++] = (len);\
	memcpy( m_pchSndBuf + m_dwSendBufLen, (pInfo), (len) );\
	m_dwSendBufLen += len;


CLoadInfoMngr::CLoadInfoMngr(void) : m_dwSendBufLen(0), m_pchSndBuf(NULL), m_pBoard(NULL),
m_dwMacAssignCount(0)/*, m_dwIpAssignCount(0)*/
{
	RefreshStartIp();
	RefreshStartMac();
}
CLoadInfoMngr::~CLoadInfoMngr(void)
{
}
bool CLoadInfoMngr::GetLoadInfo( const u32 dwBrdIdx, s8 *pBuf, u32 &dwLen )
{
	LOGEVENT("---------------��ȡ������Ϣ---------------\n");
	m_pchSndBuf = pBuf;
	//�õ�Ҫ���صİ忨
	m_pBoard = NULL;
	IDevice *pDvc = IUserDataMngr::GetSingletonPtr()->GetDevice();
	if ( pDvc != NULL )
	{
		//���忨���أ�Ĭ��ʹ�õ�һ���忨 idx=0
		m_pBoard = pDvc->GetBoard(dwBrdIdx);
	}
	if ( m_pBoard == NULL )
	{
		LOGEVENT("�忨�����ڣ����ܻ�ȡ������Ϣ\n");
		return false;
	}
	//���buffer
	memset( m_pchSndBuf, 0, MAX_LOAD_BUF_LEN );
	m_dwSendBufLen = 0;
	SetMsgId( KDM_BOOTINFO_ACK );
	//��ȡ������Ϣ
	//��ȡ���к�
	if(GetSn() == false)
    {
        return false;
    }
	//��ȡIP
	if(GetIp() == false)
    {
        return false;
    }
	//��ȡMac
	if (GetMac() == false)
	{
		return false;
	}
	//��ȡʱ��
    if(GetDate() == false)
    {
        return false;
    }
	//��ȡ�豸����
    if(GetType() == false)
    {
        return false;
    }
	//��ȡӲ����Ϣ
    if(GetHardWare() == false)
    {
        return false;
    }
	//��ȡ���������к�
    if(GetPipeLineSn() == false)
    {
        return false;
    }
	//��ȡE2prom��Ϣ
    if(GetE2promInfo() == false)
    {
        return false;
    }
	//��ȡE2prom��־
    if(GetE2promFlag() == false)
    {
        return false;
    }
	//��ȡ�����ļ�
    if(GetTftpLoadFile() == false)
    {
        return false;
    }
	//��ȡ�û���Ϣ
	if ( GetUserData() == false )
	{
		return false;
	}
	SetMsgBodyLen(dwLen);
	LOGEVENT("---------------��ȡ������Ϣ���---------------\n");
	return true;
}


void CLoadInfoMngr::SetMsgId( u32 dwMsgId )
{	
	dwMsgId = htonl(dwMsgId);
	LOGEVENT("��ϢID: %d\n", dwMsgId );
	memcpy( m_pchSndBuf, &dwMsgId, sizeof(u32) );
	//0-3Ϊ��ϢID, 4-7Ϊ��Ϣ����
    m_dwSendBufLen = 8;
}
void CLoadInfoMngr::SetMsgBodyLen(u32 &dwLen)
{
	dwLen = m_dwSendBufLen;
	LOGEVENT("��Ϣ�ܳ��ȣ�����Ϣͷ��: %d\n", dwLen );

	//��Ϣͷ����8�ֽ�
	u32 dwMsgBodyLen = m_dwSendBufLen - 8;
	dwMsgBodyLen = htonl(dwMsgBodyLen);

	//buffer��4-7λΪ��Ϣ�峤��
	memcpy( m_pchSndBuf + 4, &dwMsgBodyLen, sizeof(u32) );
}

void CLoadInfoMngr::RefreshStartIp()
{	//��ʼ����ʼIP
	m_dwStartIp = USERDATA->GetStartIp();
	//��ԭ������
/*	m_dwIpAssignCount = 0;*/
}

void CLoadInfoMngr::RefreshStartMac()
{
	//��ʼ����ʼMac
	s8 *pchMac = USERDATA->GetStartMac();
	u8 achMac[MAC_SIZE] = { 0 }; 

	//������ʼMac�ַ���
	sscanf( pchMac, "%2x:%2x:%2x:%2x:%2x:%2x", 
		&achMac[0], &achMac[1], &achMac[2], 
		&achMac[3], &achMac[4], &achMac[5] );

	//������ʼMac��ַ(u64)
	m_uStartMac = ((u64)achMac[5] \
		+ (((u64)achMac[4]) << 8) \
		+ (((u64)achMac[3]) << 16) \
		+ (((u64)achMac[2]) << 24) \
		+ (((u64)achMac[1]) << 32) \
		+ (((u64)achMac[0]) << 40) \
		);

	//��ԭ������
	m_dwMacAssignCount = 0;

}


bool CLoadInfoMngr::GetIp(void)
{
	//��ʱ��������������10.1.1.2
	u32 dwIp = ntohl(m_dwStartIp);
/*	m_dwIpAssignCount++;*/
	//תΪ������
	dwIp = htonl(dwIp);
	//�浽�忨
	m_pBoard->SetIpAddr(dwIp);
	//д��buffer
	INFO_HEADER( IP_OPT );
	INFO_CONTENT( &dwIp, sizeof(u32) );
	s8 *pchIp = (s8*)&dwIp;
	LOGEVENT("�����µ�IP: %d.%d.%d.%d\n", pchIp[0], pchIp[1], pchIp[2], pchIp[3]);
	return true;
}
bool CLoadInfoMngr::AssignNewMac( u8 *pBuf )
{
	//����Mac = �׵�ַ + ������
	u64 uAssignMac = m_uStartMac + m_dwMacAssignCount;
	m_dwMacAssignCount++;
	u8 achAssignMac[MAC_SIZE] = {0};
	//תΪ������
	achAssignMac[0] = (u8)(uAssignMac >> 40);
	achAssignMac[1] = (u8)(uAssignMac >> 32);
	achAssignMac[2] = (u8)(uAssignMac >> 24);
	achAssignMac[3] = (u8)(uAssignMac >> 16);
	achAssignMac[4] = (u8)(uAssignMac >> 8);
    achAssignMac[5] = (u8)uAssignMac;
	memcpy( pBuf, achAssignMac, sizeof(achAssignMac) );
	return true;
}

bool CLoadInfoMngr::GetMac(void)
{
	u8 achAssignMac[MAC_SIZE * 2] = {0};
	//����һ���µ�Mac��ַ
	AssignNewMac( achAssignMac );
	//�浽�忨
	s8 achBrdMac[MAX_MAC_LENGTH] = {0};
	sprintf( achBrdMac, "%02x:%02x:%02x:%02x:%02x:%02x",
		achAssignMac[0], achAssignMac[1], achAssignMac[2],
		achAssignMac[3], achAssignMac[4], achAssignMac[5] );
	m_pBoard->SetMac(achBrdMac);
	LOGEVENT("�����µ�Mac:%s\n", achBrdMac );

	/*�����˫����*/
	u32 dwEthernetCount = m_pBoard->GetEthernetCount();
	if (  dwEthernetCount == 2 )
	{
		//�ٷ���һ��
		AssignNewMac( achAssignMac + MAC_SIZE );
		//�浽�忨
		s8 achBrdMac2[MAX_MAC_LENGTH] = {0};
		sprintf( achBrdMac2, "%02x:%02x:%02x:%02x:%02x:%02x",
			achAssignMac[6], achAssignMac[7], achAssignMac[8],
			achAssignMac[9], achAssignMac[10], achAssignMac[11] );
		//m_pBoard->SetMac2(achBrdMac);
		//д��buffer
		INFO_HEADER( MAC_OPT );
		INFO_CONTENT( achAssignMac, MAC_SIZE*2 );
		LOGEVENT("�����µ�Mac:%s\n", achBrdMac2 );
		return true;
	}
	//д��buffer
	INFO_HEADER( MAC_OPT );
	INFO_CONTENT( achAssignMac, MAC_SIZE );
	return true;
}

bool CLoadInfoMngr::GetSn(void)
{
	s8 achSn[MAX_SERIAL_LENGTH + 1] = { 0 };
	memcpy( achSn, m_pBoard->GetSerialNo(), MAX_SERIAL_LENGTH );
	u32 dwSnlen = strlen(achSn);
	if (  dwSnlen == 0 )
	{
		LOGEVENT("��Ч���к�\n");
		return false;
	}
	INFO_HEADER( SN_OPT );
	INFO_CONTENT( achSn, dwSnlen );
	LOGEVENT( "���к�: %s\n", achSn );
	return true;
}

bool CLoadInfoMngr::GetHardWare(void)
{
	//Hardware Version
	String strHardVer =  m_pBoard->GetHardVersion();
	//ת��Ϊ����
	strHardVer.erase(1,1);
	u32 dwHwVer = atoi(strHardVer.c_str());
	LOGEVENT("Ӳ���汾��: %d\n", dwHwVer );
	//ֻ����2���ֽ�תΪ������
	dwHwVer = htons( dwHwVer );
	INFO_HEADER( HARDWARE_OPT );
	INFO_CONTENT( &dwHwVer, sizeof(u32) );

	//Sub Hardware Version
	//��ʱ����


	//Hid
	u32 wHid = m_pBoard->GetHid();
	LOGEVENT("Ӳ��ID: %d\n", wHid );
	//תΪ������
	wHid = htons( wHid );
	INFO_HEADER( HWID_OPT );
	INFO_CONTENT( &wHid, sizeof(u32) );
	return true;

}
bool CLoadInfoMngr::GetDate(void)
{
	//��ȡϵͳ����
	SYSTEMTIME Time={0};
	GetLocalTime(&Time);
	//YYYYMMDD
	u32 dwDate = Time.wYear * 10000 + Time.wMonth * 100 + Time.wDay;
	LOGEVENT( "����: %d\n", dwDate );
	//д���豸�����YYMMDD  ��ʾ��������YYYY/MM/DD HH:MM:SS
	s8 achDate[MAX_DATE_LEN] = {0};
	sprintf( achDate, "%04d/%02d/%02d %02d:%02d:%02d", Time.wYear, Time.wMonth, Time.wDay, Time.wHour, Time.wMinute, Time.wSecond );
	//�浽�忨
	m_pBoard->SetDate(achDate);
	//д��buffer
	dwDate = htonl( dwDate );
	INFO_HEADER( DATE_OPT );
	INFO_CONTENT( &dwDate, sizeof(u32) );
	return true;
}

bool CLoadInfoMngr::GetType(void)
{
	//PID
	u32 wPid = m_pBoard->GetPid();
	LOGEVENT( "Pid: %d\n", wPid );
	INFO_HEADER( PRODUCT_OPT );
	wPid = htons( wPid );
	INFO_CONTENT( &wPid, sizeof(u32) );
	return true;
}
bool CLoadInfoMngr::GetTftpLoadFile(void)
{
	String strSysFileName = m_pBoard->GetSysFile();
	LOGEVENT("����SysFile: %s\n", strSysFileName.c_str() );
	s8 achFileName[MAX_SYSFILE_NAME_LENGTH];
	strcpy( achFileName, strSysFileName.c_str() );
	INFO_HEADER( SYS_FILENAME_OPT );
	INFO_CONTENT( achFileName, MAX_SYSFILE_NAME_LENGTH );
	return true;
}

bool CLoadInfoMngr::GetPipeLineSn(void)
{
	s8 achPipeLine[PIPELINE_SN_LEN + 1] = {0};
	memcpy( achPipeLine, m_pBoard->GetPipeLine(), PIPELINE_SN_LEN );
	LOGEVENT("������: %s\n", achPipeLine );
	INFO_HEADER( PIPELINE_SN_OPT );
	INFO_CONTENT( achPipeLine, strlen(achPipeLine) );
	return true;
}
bool CLoadInfoMngr::GetE2promInfo(void)
{
	u32 dwE2promInfo = m_pBoard->GetE2promInfo();
	LOGEVENT( "E2prom��Ϣ: %d\n", dwE2promInfo );
	dwE2promInfo = htonl(dwE2promInfo);
	INFO_HEADER( E2PROMINFO_OPT );
	INFO_CONTENT( &dwE2promInfo, sizeof(u32) );
	return true;

}
bool CLoadInfoMngr::GetE2promFlag(void)
{
	u32 dwE2promFlag = m_pBoard->GetE2promFlag();
	LOGEVENT( "E2prom��־: %d\n", dwE2promFlag );
	//dwE2promFlag = htonl(dwE2promFlag);
	INFO_HEADER( E2PROMFLAG0_OPT );
	INFO_CONTENT( &dwE2promFlag, sizeof(u32) );
	return true;
}
bool CLoadInfoMngr::GetUserData(void)
{
	//�û���Ϣ 64*0
	s8 achUserData[64] = {0};
	INFO_HEADER( BOOT_USERDATA_OPT );
	INFO_CONTENT( achUserData, 64 );
	return true;
}

bool CLoadInfoMngr::Update( TMsgParam& tMsgParma )
{
	//ˢ����Դ
	switch ( tMsgParma.wMsgId )
	{
	case EV_USER_START_IP_CHANGE:
		RefreshStartIp();
		break;
	case EV_USER_START_MAC_CHANGE:
		RefreshStartMac();
		break;
	default:
		break;
	}
	return true;
}

