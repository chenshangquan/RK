#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDevice : public IDevice
{
public:
	CDevice();
	/** 拷贝构造函数 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	CDevice( const CDevice& Dvc );
	~CDevice();
	virtual IDevice* Clone();
	virtual bool SetTestCase( EmCaseSetType emType );
	virtual	ITestCase* GetCurTestCase();
	virtual IBoard* GetBoard( u32 dwIdx );
	virtual bool AddBoard(IBoard *pBoard);
	virtual bool RemoveBoard(IBoard *pBoard);
	virtual u32	 GetBrdCount() const;
	virtual	void Print();
	virtual void EndTest( bool bNormal = true );
	virtual String GetName() const;
	virtual bool SetName( const String &strName );
	virtual bool IsEnd() const;
	virtual void Restore();

private:
	/**  执行当前测试项
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool ExeCurCase();
private:
	String m_strDvcName;							//设备名
	ITestCase *m_pCurTestCase;						//设备当前测试项
	typedef vector< IBoard* > BrdList;
	BrdList m_vecBrdList;							//板卡列表
	bool m_bIsEnd;									//是否已经结束

};