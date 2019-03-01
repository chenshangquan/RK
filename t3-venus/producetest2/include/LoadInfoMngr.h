#ifndef _LOADINFOMNGR_H_
#define _LOADINFOMNGR_H_
//加载内容类型的ID
enum LOAD_TYPE_ID
{
	IP_OPT = 0,				//IP
		MAC_OPT = 1,				//Mac
		SN_OPT = 2,					//Serial Number
		DATE_OPT = 3,				//Date
		HWID_OPT = 4,				//HID
		HARDWARE_OPT = 5,			//HardVersion
		HWSUBVER_OPT = 6,			//HardSubVer
		PRODUCT_OPT = 7,			//PID
		PIPELINE_SN_OPT = 8,		//Pipeline Number
		E2PROMFLAG0_OPT = 9,		//E2promFlag0
		E2PROMINFO_OPT = 10,		//E2promInfo
		E2PROMFLAG1_OPT = 11,		//E2promFlag1
		SYS_FILENAME_OPT = 14,	//SysFile
		BOOT_USERDATA_OPT = 18,	//UserDate
};

class CLoadInfoMngr : public ILoadInfoMngr
{
public:
	CLoadInfoMngr(void);
	~CLoadInfoMngr(void);
	virtual bool GetLoadInfo( const u32 dwBrdIdx, s8 *pBuf, u32 &dwLen );
	virtual bool Update( TMsgParam& tMsgParma );
private:
	/** 设置消息Id 
	 *  @param[in] 消息Id 
	 *  @node 
	 *  @return 
	 */
    void SetMsgId( u32 chMsgId );
	/**设置消息长度  
	 *  @param[out] dwLen:消息体长度
	 *  @node 
	 *  @return 
	 */
    void SetMsgBodyLen(u32 &dwLen);
	/**获取IP  
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
    bool GetIp(void);
	/**获取Mac 
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool GetMac(void); 
	/**获取序列号  
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
    bool GetSn(void);
	/**获取硬件信息  
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
    bool GetHardWare(void);
	/**获取日期  
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
    bool GetDate(void);
	/**获取设备类型 
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
    bool GetType(void);
	/**获取加载信息  
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
    bool GetTftpLoadFile(void);
	/**获取生产线信息  
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
    bool GetPipeLineSn(void);
	/**获取E2prom信息
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
    bool GetE2promInfo(void);
	/**获取E2prom标志  
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
    bool GetE2promFlag(void);
	/**获取用户信息  
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool GetUserData(void);
	/** 刷新起始IP 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void RefreshStartIp();
	/** 刷新起始Mac
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void RefreshStartMac();
	/** 分配一个新的Mac地址
	 *  @param[in] 存放Mac地址buffer的指针
	 *  @node 
	 *  @return 是否成功 
	 */
	bool AssignNewMac( u8 *pBuf );
private:
	/*
	发送内容的长度	
	*/
	u32  m_dwSendBufLen;
	/*
	发送内容的指针	
	*/
	s8 *m_pchSndBuf;
	/*
	加载板卡的指针	
	*/
	IBoard *m_pBoard;
	/*
	起始IP地址 网络序
	*/
	u32 m_dwStartIp;
	/*
	起始Mac地址	
	*/
	u64 m_uStartMac;
	/*
	Mac地址分配数量	
	*/
	u32 m_dwMacAssignCount;
	/*
	IP分配数量	
	*/
/*	u32 m_dwIpAssignCount;*/
};

#endif 