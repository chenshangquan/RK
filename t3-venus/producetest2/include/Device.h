#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDevice : public IDevice
{
public:
	CDevice();
	/** �������캯�� 
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
	/**  ִ�е�ǰ������
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool ExeCurCase();
private:
	String m_strDvcName;							//�豸��
	ITestCase *m_pCurTestCase;						//�豸��ǰ������
	typedef vector< IBoard* > BrdList;
	BrdList m_vecBrdList;							//�忨�б�
	bool m_bIsEnd;									//�Ƿ��Ѿ�����

};