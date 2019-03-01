#ifndef _UDPSESSION_H_
#define _UDPSESSION_H_
#include "Udp.h"
/*
	Udp会话（加载消息处理业务类）	
*/
class CUdpSession
{
public:
	/** 构造函数 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	CUdpSession();

	/** 析构函数 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	~CUdpSession();
 
private:
	/*=============================================================================
	函 数 名： GetIdlePort
	功    能： 获取指定端口区间的一个空闲端口
	算法实现： 
	全局变量： 
	参    数： wStartPort：起始监测端口，dwIP：本地ip，wEndPort：监测结束端口
	返 回 值： 空闲端口值 
	-------------------------------------------------------------------------------
	修改纪录:
	日      期  版本    修改人  修改内容
	2012/9/27   1.0     俞锦锦    创建
	=============================================================================*/
/*	u16 GetIdlePort(u32 dwIP,  u16 wStartPort, u16 wEndPort);*/


protected:
	/** 消息处理函数 
	 *  @param[in] ip、端口、数据、数据长度
	 *  @node 
	 *  @return 
	 */
	static void ProcMsg( const char * ip, unsigned short port, const char * data, short len );
	/** 初始化 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void Init();
private:
	/*
		Udp连接的ID	
	*/
	static u32 m_dwUdpId;

	/*
		当前消息的Ip
	*/
	u32 m_dwIpAddr;
	/*
		加载信息Buffer	
	*/
	static s8 m_achLoadBuf[MAX_LOAD_BUF_LEN];
	/*
		加载信息长度	
	*/
	static u32 m_dwInfoLen;

};








//转主机序
#define MKLONG(BUF)  ( (BUF[0]<<24)+(BUF[1]<<16)+(BUF[2]<<8)+BUF[3] )



#endif