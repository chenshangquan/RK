#ifndef _LOADINFOMNGR_H_
#define _LOADINFOMNGR_H_
//�����������͵�ID
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
	/** ������ϢId 
	 *  @param[in] ��ϢId 
	 *  @node 
	 *  @return 
	 */
    void SetMsgId( u32 chMsgId );
	/**������Ϣ����  
	 *  @param[out] dwLen:��Ϣ�峤��
	 *  @node 
	 *  @return 
	 */
    void SetMsgBodyLen(u32 &dwLen);
	/**��ȡIP  
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
    bool GetIp(void);
	/**��ȡMac 
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool GetMac(void); 
	/**��ȡ���к�  
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
    bool GetSn(void);
	/**��ȡӲ����Ϣ  
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
    bool GetHardWare(void);
	/**��ȡ����  
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
    bool GetDate(void);
	/**��ȡ�豸���� 
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
    bool GetType(void);
	/**��ȡ������Ϣ  
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
    bool GetTftpLoadFile(void);
	/**��ȡ��������Ϣ  
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
    bool GetPipeLineSn(void);
	/**��ȡE2prom��Ϣ
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
    bool GetE2promInfo(void);
	/**��ȡE2prom��־  
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
    bool GetE2promFlag(void);
	/**��ȡ�û���Ϣ  
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool GetUserData(void);
	/** ˢ����ʼIP 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void RefreshStartIp();
	/** ˢ����ʼMac
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void RefreshStartMac();
	/** ����һ���µ�Mac��ַ
	 *  @param[in] ���Mac��ַbuffer��ָ��
	 *  @node 
	 *  @return �Ƿ�ɹ� 
	 */
	bool AssignNewMac( u8 *pBuf );
private:
	/*
	�������ݵĳ���	
	*/
	u32  m_dwSendBufLen;
	/*
	�������ݵ�ָ��	
	*/
	s8 *m_pchSndBuf;
	/*
	���ذ忨��ָ��	
	*/
	IBoard *m_pBoard;
	/*
	��ʼIP��ַ ������
	*/
	u32 m_dwStartIp;
	/*
	��ʼMac��ַ	
	*/
	u64 m_uStartMac;
	/*
	Mac��ַ��������	
	*/
	u32 m_dwMacAssignCount;
	/*
	IP��������	
	*/
/*	u32 m_dwIpAssignCount;*/
};

#endif 