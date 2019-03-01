#include "stdafx.h"
#include "LoadInfoMngr.h"

/*
信息头宏
每种信息buffer之前需要加入信息头，参数为信息类型的Id	
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
信息内容宏
参数 pInfo:信息指针, len:信息长度	
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
	LOGEVENT("---------------获取加载信息---------------\n");
	m_pchSndBuf = pBuf;
	//拿到要加载的板卡
	m_pBoard = NULL;
	IDevice *pDvc = IUserDataMngr::GetSingletonPtr()->GetDevice();
	if ( pDvc != NULL )
	{
		//单板卡加载，默认使用第一个板卡 idx=0
		m_pBoard = pDvc->GetBoard(dwBrdIdx);
	}
	if ( m_pBoard == NULL )
	{
		LOGEVENT("板卡不存在，不能获取加载信息\n");
		return false;
	}
	//清空buffer
	memset( m_pchSndBuf, 0, MAX_LOAD_BUF_LEN );
	m_dwSendBufLen = 0;
	SetMsgId( KDM_BOOTINFO_ACK );
	//获取各种信息
	//获取序列号
	if(GetSn() == false)
    {
        return false;
    }
	//获取IP
	if(GetIp() == false)
    {
        return false;
    }
	//获取Mac
	if (GetMac() == false)
	{
		return false;
	}
	//获取时间
    if(GetDate() == false)
    {
        return false;
    }
	//获取设备类型
    if(GetType() == false)
    {
        return false;
    }
	//获取硬件信息
    if(GetHardWare() == false)
    {
        return false;
    }
	//获取生产线序列号
    if(GetPipeLineSn() == false)
    {
        return false;
    }
	//获取E2prom信息
    if(GetE2promInfo() == false)
    {
        return false;
    }
	//获取E2prom标志
    if(GetE2promFlag() == false)
    {
        return false;
    }
	//获取加载文件
    if(GetTftpLoadFile() == false)
    {
        return false;
    }
	//获取用户信息
	if ( GetUserData() == false )
	{
		return false;
	}
	SetMsgBodyLen(dwLen);
	LOGEVENT("---------------获取加载信息完毕---------------\n");
	return true;
}


void CLoadInfoMngr::SetMsgId( u32 dwMsgId )
{	
	dwMsgId = htonl(dwMsgId);
	LOGEVENT("消息ID: %d\n", dwMsgId );
	memcpy( m_pchSndBuf, &dwMsgId, sizeof(u32) );
	//0-3为消息ID, 4-7为消息长度
    m_dwSendBufLen = 8;
}
void CLoadInfoMngr::SetMsgBodyLen(u32 &dwLen)
{
	dwLen = m_dwSendBufLen;
	LOGEVENT("消息总长度（含消息头）: %d\n", dwLen );

	//消息头长度8字节
	u32 dwMsgBodyLen = m_dwSendBufLen - 8;
	dwMsgBodyLen = htonl(dwMsgBodyLen);

	//buffer第4-7位为消息体长度
	memcpy( m_pchSndBuf + 4, &dwMsgBodyLen, sizeof(u32) );
}

void CLoadInfoMngr::RefreshStartIp()
{	//初始化起始IP
	m_dwStartIp = USERDATA->GetStartIp();
	//还原分配数
/*	m_dwIpAssignCount = 0;*/
}

void CLoadInfoMngr::RefreshStartMac()
{
	//初始化起始Mac
	s8 *pchMac = USERDATA->GetStartMac();
	u8 achMac[MAC_SIZE] = { 0 }; 

	//读入起始Mac字符串
	sscanf( pchMac, "%2x:%2x:%2x:%2x:%2x:%2x", 
		&achMac[0], &achMac[1], &achMac[2], 
		&achMac[3], &achMac[4], &achMac[5] );

	//计算起始Mac地址(u64)
	m_uStartMac = ((u64)achMac[5] \
		+ (((u64)achMac[4]) << 8) \
		+ (((u64)achMac[3]) << 16) \
		+ (((u64)achMac[2]) << 24) \
		+ (((u64)achMac[1]) << 32) \
		+ (((u64)achMac[0]) << 40) \
		);

	//还原分配数
	m_dwMacAssignCount = 0;

}


bool CLoadInfoMngr::GetIp(void)
{
	//暂时所有网卡都分配10.1.1.2
	u32 dwIp = ntohl(m_dwStartIp);
/*	m_dwIpAssignCount++;*/
	//转为网络序
	dwIp = htonl(dwIp);
	//存到板卡
	m_pBoard->SetIpAddr(dwIp);
	//写到buffer
	INFO_HEADER( IP_OPT );
	INFO_CONTENT( &dwIp, sizeof(u32) );
	s8 *pchIp = (s8*)&dwIp;
	LOGEVENT("分配新的IP: %d.%d.%d.%d\n", pchIp[0], pchIp[1], pchIp[2], pchIp[3]);
	return true;
}
bool CLoadInfoMngr::AssignNewMac( u8 *pBuf )
{
	//分配Mac = 首地址 + 分配数
	u64 uAssignMac = m_uStartMac + m_dwMacAssignCount;
	m_dwMacAssignCount++;
	u8 achAssignMac[MAC_SIZE] = {0};
	//转为网络序
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
	//分配一个新的Mac地址
	AssignNewMac( achAssignMac );
	//存到板卡
	s8 achBrdMac[MAX_MAC_LENGTH] = {0};
	sprintf( achBrdMac, "%02x:%02x:%02x:%02x:%02x:%02x",
		achAssignMac[0], achAssignMac[1], achAssignMac[2],
		achAssignMac[3], achAssignMac[4], achAssignMac[5] );
	m_pBoard->SetMac(achBrdMac);
	LOGEVENT("分配新的Mac:%s\n", achBrdMac );

	/*如果是双网卡*/
	u32 dwEthernetCount = m_pBoard->GetEthernetCount();
	if (  dwEthernetCount == 2 )
	{
		//再分配一个
		AssignNewMac( achAssignMac + MAC_SIZE );
		//存到板卡
		s8 achBrdMac2[MAX_MAC_LENGTH] = {0};
		sprintf( achBrdMac2, "%02x:%02x:%02x:%02x:%02x:%02x",
			achAssignMac[6], achAssignMac[7], achAssignMac[8],
			achAssignMac[9], achAssignMac[10], achAssignMac[11] );
		//m_pBoard->SetMac2(achBrdMac);
		//写到buffer
		INFO_HEADER( MAC_OPT );
		INFO_CONTENT( achAssignMac, MAC_SIZE*2 );
		LOGEVENT("分配新的Mac:%s\n", achBrdMac2 );
		return true;
	}
	//写到buffer
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
		LOGEVENT("无效序列号\n");
		return false;
	}
	INFO_HEADER( SN_OPT );
	INFO_CONTENT( achSn, dwSnlen );
	LOGEVENT( "序列号: %s\n", achSn );
	return true;
}

bool CLoadInfoMngr::GetHardWare(void)
{
	//Hardware Version
	String strHardVer =  m_pBoard->GetHardVersion();
	//转换为数字
	strHardVer.erase(1,1);
	u32 dwHwVer = atoi(strHardVer.c_str());
	LOGEVENT("硬件版本号: %d\n", dwHwVer );
	//只将低2个字节转为网络序
	dwHwVer = htons( dwHwVer );
	INFO_HEADER( HARDWARE_OPT );
	INFO_CONTENT( &dwHwVer, sizeof(u32) );

	//Sub Hardware Version
	//暂时不用


	//Hid
	u32 wHid = m_pBoard->GetHid();
	LOGEVENT("硬件ID: %d\n", wHid );
	//转为网络序
	wHid = htons( wHid );
	INFO_HEADER( HWID_OPT );
	INFO_CONTENT( &wHid, sizeof(u32) );
	return true;

}
bool CLoadInfoMngr::GetDate(void)
{
	//获取系统日期
	SYSTEMTIME Time={0};
	GetLocalTime(&Time);
	//YYYYMMDD
	u32 dwDate = Time.wYear * 10000 + Time.wMonth * 100 + Time.wDay;
	LOGEVENT( "日期: %d\n", dwDate );
	//写到设备里的是YYMMDD  显示到界面是YYYY/MM/DD HH:MM:SS
	s8 achDate[MAX_DATE_LEN] = {0};
	sprintf( achDate, "%04d/%02d/%02d %02d:%02d:%02d", Time.wYear, Time.wMonth, Time.wDay, Time.wHour, Time.wMinute, Time.wSecond );
	//存到板卡
	m_pBoard->SetDate(achDate);
	//写到buffer
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
	LOGEVENT("加载SysFile: %s\n", strSysFileName.c_str() );
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
	LOGEVENT("生产线: %s\n", achPipeLine );
	INFO_HEADER( PIPELINE_SN_OPT );
	INFO_CONTENT( achPipeLine, strlen(achPipeLine) );
	return true;
}
bool CLoadInfoMngr::GetE2promInfo(void)
{
	u32 dwE2promInfo = m_pBoard->GetE2promInfo();
	LOGEVENT( "E2prom信息: %d\n", dwE2promInfo );
	dwE2promInfo = htonl(dwE2promInfo);
	INFO_HEADER( E2PROMINFO_OPT );
	INFO_CONTENT( &dwE2promInfo, sizeof(u32) );
	return true;

}
bool CLoadInfoMngr::GetE2promFlag(void)
{
	u32 dwE2promFlag = m_pBoard->GetE2promFlag();
	LOGEVENT( "E2prom标志: %d\n", dwE2promFlag );
	//dwE2promFlag = htonl(dwE2promFlag);
	INFO_HEADER( E2PROMFLAG0_OPT );
	INFO_CONTENT( &dwE2promFlag, sizeof(u32) );
	return true;
}
bool CLoadInfoMngr::GetUserData(void)
{
	//用户信息 64*0
	s8 achUserData[64] = {0};
	INFO_HEADER( BOOT_USERDATA_OPT );
	INFO_CONTENT( achUserData, 64 );
	return true;
}

bool CLoadInfoMngr::Update( TMsgParam& tMsgParma )
{
	//刷新资源
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

