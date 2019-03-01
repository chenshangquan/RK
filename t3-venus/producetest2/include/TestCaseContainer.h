class CTestCaseContainer : public ITestCaseContainer
{
private:
	typedef vector<ITestCase*> TestCaseList;
	TestCaseList m_vecCaseList;								//测试项列表
	u32 m_dwCurCasePos;										//记录当前测试项位置

public:
	virtual bool AddTestCase( ITestCase *pTestCase );
	virtual bool RemoveTestCase( ITestCase *pTestCase );
	virtual bool RemoveAll();
	virtual ITestCase* GetTestCase( u32 dwIdx );
	virtual ITestCase* GetTestCase( String strCaseName );
	virtual ITestCase* GetCurCase();
	virtual u32 GetCaseCount();
	virtual bool Restore();
	CTestCaseContainer();
	~CTestCaseContainer();


};