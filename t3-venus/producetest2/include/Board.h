#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "TestCase.h"
#include "TestCaseContainer.h"
class CBoard : public IBoard
{
public:
	CBoard();
	~CBoard();
	virtual bool SetActivated( const bool bActivated );
	virtual bool GetActivated()  const;
	virtual	bool SetAppId( const u32 dwAppId );
	virtual u32	GetAppId() const;
	virtual	bool SetE2promFlag( const u32 dwFlag );
	virtual u32 GetE2promFlag()  const;
	virtual	bool SetE2promInfo( const u32 dwInfo );
	virtual u32 GetE2promInfo()  const;
	virtual bool SetEndMsgQue( IMsgQueMngr *MsgQue );
	virtual IMsgQueMngr* GetEndMsgQue();
	virtual	s8* GetHardVersion();
	virtual bool SetHardVersion( const s8* pchHardVer );
	virtual u16	GetHid() const;
	virtual bool SetHid( const u16 &dwHid );
	virtual u16 GetPid()  const;
	virtual bool SetPid( const u16 &wPid );
	virtual s8* GetPipeLine();
	virtual bool SetPipeLine( const s8* achPipeLine );
	virtual IMsgQueMngr* GetPreMsgQue() const;
	virtual bool SetPreMsgQue( IMsgQueMngr *MsgQue );
	virtual bool SetRegMsg( TBrdRegMsg RegMsg );
	virtual bool SetSerialNo(const s8 *pchSn);
	virtual s8* GetSerialNo();
	virtual bool SetMac( const s8 *pchMac );
	virtual s8* GetMac();
	virtual bool SetEthernetCount( const u32 &dwCount );
	virtual u32 GetEthernetCount() const;
	virtual bool SetIpAddr(const u32 &dwIp );
	virtual u32 GetIpAddr() const;
	virtual	s8* GetSoftVersion()  ;
	virtual bool SetSoftVersion( const s8 *pchSoftVer );
	virtual bool SetSubMsk( const u32 dwSubMsk );
	virtual u32 GetSubMsk() const;
	virtual LPCSTR GetDate();
	virtual bool SetDate( LPCSTR pchDate );	
	virtual String GetSysFile() const;
	virtual bool SetSysFile( const String &strFileName );
	virtual IBoard* Clone();
	virtual bool SetMode( const u8 byMode) ;
	virtual u8 GetMode() const;
	virtual bool SetBrdPic(const String &strBrdPic );
	virtual String GetBrdPic() const;
	virtual void Print();
	virtual ITestCaseContainer* GetCaseContainer();
	virtual bool SetBrdName( const String strBrdName );
	virtual String GetBrdName() const;
	virtual bool SetProcedure( const EmBrdProceduer emProcedure );  
	virtual IMsgQueMngr* GetResMsgQue();
	virtual bool SetResMsgQue( IMsgQueMngr *MsgQue );
	virtual void Restore();
	virtual bool SetBrdDesc( const String &strDesc );
	virtual String GetBrdDesc();
	virtual void ProcMsg( const TObMsg &msg ) ;
	virtual void ClearMsgQue();
	
// 	virtual void setType(EmCnModel emMtType);
// 	virtual u32  getType() const;


private: 
	/**  注册板卡
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	void RegBrd( const TObMsg &ObMsg );
	
	/**  检查进度，置进度之后调用，进度与对应消息队列匹配，自动更新为最新的进度
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	 void CheckProcedure();

	 /**  加载测试内容（包括测试项和消息队列）
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	 bool LoadTestContent();

	 /**  根据注册信息，初始化板卡数据
	 *  @param[in] 注册信息
	 *  @node 
	 *  @return 模式是否改变
	 */
	 bool InitTestInfo( const TObMsg &ObMsg );




private:
	s8			m_achDate[MAX_DATE_LEN];					//生产日期	YYYY/MM/DD HH:MM:SS	
	s8			m_achMac[MAX_MAC_LENGTH];					//MAC地址 xx:xx:xx:xx:xx:xx
	bool		m_bActivated;								//激活状态
	u32			m_dwAppId;									//APP ID
	u32			m_byMode;									//板卡模式
	u32			m_dwIpAddr;									//IP地址  网络序
	u32			m_dwSubMsk;									//子网掩码
	u32			m_dwE2promFlag;								//E2prom标志
	u32			m_dwE2promInfo;								//E2prom信息
	IMsgQueMngr *m_pResMsgQue;								//恢复出厂设置消息队列
	IMsgQueMngr *m_pEndMsgQue;								//结束消息队列
	IMsgQueMngr *m_pPreMsgQue;								//准备消息队列
	s8			m_achHardVersion[MAX_VERSION_LENGTH];		//硬件版本 
	s8			m_achSoftVersion[MAX_VERSION_LENGTH];		//软件版本
	u16			m_wHid;									    //硬件ID
	u16			m_wPid;									    //产品ID 
	u32			m_dwEthernetCount;							//网卡数量
	s8			m_achPipeLine[PIPELINE_SN_LEN];				//生产线
	EmBrdProceduer m_emProcedure;							//板卡进度
	TBrdRegMsg	m_RegMsg;									//注册消息
	s8			m_achSerialNo[MAX_SERIAL_LENGTH];			//序列号
	String		m_strSysFile;								//加载文件
	String		m_strBrdPic;								//板卡图片文件
	String		m_strBrdName;								//板卡名
	String		m_strBrdDesc;								//板卡描述
	CTestCaseContainer m_CaseContainer;						//测试项容器
};