#pragma once
//#include "Coder.h"
class CMediaTestCase : public ITestCase
{
public:
	CMediaTestCase();
	~CMediaTestCase();
	
	virtual ITestCase* Clone();
	virtual	EmTestCaseState GetState();
	virtual	bool SetState( EmTestCaseState emState );
	virtual EmTestCaseType GetType();
	virtual	bool SetType( EmTestCaseType emType );
	virtual bool GetAdded() const;
	virtual	bool SetAdded( const bool bAdded );
	virtual bool ExeTestCase();
	virtual bool SetCaseName( const String strCaseName );
	virtual bool SetDescription( const String strDes );
	virtual String GetCaseName() const;
	virtual String GetCaseDesc() const;
	virtual void Print();
	virtual void Restore();
	virtual void ProcMsg( const TObMsg &msg );
	virtual void SetRetestable( const bool &bRetest );
	virtual bool IsRetestable() const ;


	/**  准备测试函数
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void PreTest() ;

	/**  结束测试函数
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void EndTest() ;

	/**  设置准备消息队列
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool SetPreMsgQue( IMsgQueMngr *pQue);

	/**  获取准备消息队列
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	IMsgQueMngr* GetPreMsgQue() const ;

		/**  设置结束消息队列
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool SetEndMsgQue( IMsgQueMngr *pQue );

	/**  获取结束消息队列
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	IMsgQueMngr* GetEndMsgQue() const ;

	/**  添加\删除输出码流参数
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool AddStreamOut( TStreamOutParam StreamOut );
	bool RemoveStreamOut ( TStreamOutParam StreamOut );

	/**  设置输入码流
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool SetStreamIn( TStreamInParam StreamIn );

	/**  找到观察者
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool SetEncNetParam( TEncoderNetParam NetParam );
	
	/**  设置/获取进度
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool SetProcedure( const EmTestCaseProcedure emProcedure );
	EmTestCaseProcedure GetProcedure() const ;

	/**  设置/获取媒体文件路径
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool SetFilePath( const String &strPath );
	String GetFilePath() const;
	//static CMediaTestCase* GetMediaTestPtr();
private:
	/**  检查当前进度与资源匹配性
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void CheckProcedure();


protected:
	IMsgQueMngr         *m_pPreMsgQue;		//准备消息队列
	IMsgQueMngr         *m_pEndMsgQue;		//结束消息队列
	String				m_strFilePath;		//媒体文件路径
	EmTestCaseProcedure m_emProcedure;		//测试项进度
	TEncoderNetParam	m_tEncoderNetParam;	//编码器网络参数
	typedef vector< TStreamOutParam > StreamOutList;
	StreamOutList		m_vecStreamOutList;	//输出码流列表
	TStreamInParam		m_tStreamInParam;	//输入码流参数
//	typedef vector< TaskId > TaskList;	
//	TaskList m_vecTaskList;					//编解码任务列表
	//static CMediaTestCase* m_pThis;
	
};
//#define  MediaTestPtr CMediaTestCase::GetMediaTestPtr()

class CCmdTestCase : public ITestCase
{
public:
	CCmdTestCase();
	~CCmdTestCase();
	virtual ITestCase* Clone();
	virtual	EmTestCaseState GetState();
	virtual	bool SetState( EmTestCaseState emState );
	virtual EmTestCaseType GetType();
	virtual	bool SetType( EmTestCaseType emType );
	virtual bool GetAdded() const;
	virtual	bool SetAdded( const bool bAdded );
	virtual bool ExeTestCase();
	virtual bool SetCaseName( const String strCaseName );
	virtual bool SetDescription( const String strDes );
	virtual String GetCaseName() const;
	virtual String GetCaseDesc() const;
	virtual void Print();
	virtual void Restore();
	virtual void ProcMsg( const TObMsg &msg );
	virtual void SetRetestable( const bool &bRetest );
	virtual bool IsRetestable() const ;

	 /**  准备测试函数
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void PreTest() ;

	/**  设置命令消息号
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool SetCmdMsgId( const u32 dwMsgId );

	/**  设置准备消息队列
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool SetPreMsgQue( IMsgQueMngr *pQue );

	/**  获取准备消息队列
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	IMsgQueMngr* GetPreMsgQue() const ;

	/**  设置/获取进度
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool SetProcedure( const EmTestCaseProcedure emProcedure );

	EmTestCaseProcedure GetProcedure() const ;

	//static CCmdTestCase* GetCmdTestPtr();


protected:
	u32	m_dwCmdMsgId;			       //命令消息Id
	IMsgQueMngr   *m_pPreMsgQue;       //准备消息队列
	EmTestCaseProcedure m_emProcedure; //测试项进度
	//static CCmdTestCase* m_pThat;

private:
	/**  检查当前进度与资源匹配性
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void CheckProcedure();
};

//#define CmdCasePtr CCmdTestCase::GetCmdTestPtr()

class CExeTestCase : public ITestCase
{
public: 
	CExeTestCase();
	~CExeTestCase();
	virtual ITestCase* Clone();
	virtual	EmTestCaseState GetState();
	virtual	bool SetState( EmTestCaseState emState );
	virtual EmTestCaseType GetType();
	virtual	bool SetType( EmTestCaseType emType );
	virtual bool GetAdded() const;
	virtual	bool SetAdded( const bool bAdded );
	virtual bool ExeTestCase();
	virtual bool SetCaseName( const String strCaseName );
	virtual bool SetDescription( const String strDes );
	virtual String GetCaseName() const;
	virtual String GetCaseDesc() const;
	virtual void Print();
	virtual void Restore();
	virtual void ProcMsg( const TObMsg &msg );
	virtual void SetRetestable( const bool &bRetest );
	virtual bool IsRetestable() const;
	/**  设置执行命令字符串
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool SetExeCmdStr( const String strCmdStr );


protected:
	String m_strExeCmd;     //执行控制台字符串
};