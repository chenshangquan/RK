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


	/**  ׼�����Ժ���
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void PreTest() ;

	/**  �������Ժ���
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void EndTest() ;

	/**  ����׼����Ϣ����
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool SetPreMsgQue( IMsgQueMngr *pQue);

	/**  ��ȡ׼����Ϣ����
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	IMsgQueMngr* GetPreMsgQue() const ;

		/**  ���ý�����Ϣ����
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool SetEndMsgQue( IMsgQueMngr *pQue );

	/**  ��ȡ������Ϣ����
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	IMsgQueMngr* GetEndMsgQue() const ;

	/**  ���\ɾ�������������
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool AddStreamOut( TStreamOutParam StreamOut );
	bool RemoveStreamOut ( TStreamOutParam StreamOut );

	/**  ������������
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool SetStreamIn( TStreamInParam StreamIn );

	/**  �ҵ��۲���
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool SetEncNetParam( TEncoderNetParam NetParam );
	
	/**  ����/��ȡ����
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool SetProcedure( const EmTestCaseProcedure emProcedure );
	EmTestCaseProcedure GetProcedure() const ;

	/**  ����/��ȡý���ļ�·��
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool SetFilePath( const String &strPath );
	String GetFilePath() const;
	//static CMediaTestCase* GetMediaTestPtr();
private:
	/**  ��鵱ǰ��������Դƥ����
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void CheckProcedure();


protected:
	IMsgQueMngr         *m_pPreMsgQue;		//׼����Ϣ����
	IMsgQueMngr         *m_pEndMsgQue;		//������Ϣ����
	String				m_strFilePath;		//ý���ļ�·��
	EmTestCaseProcedure m_emProcedure;		//���������
	TEncoderNetParam	m_tEncoderNetParam;	//�������������
	typedef vector< TStreamOutParam > StreamOutList;
	StreamOutList		m_vecStreamOutList;	//��������б�
	TStreamInParam		m_tStreamInParam;	//������������
//	typedef vector< TaskId > TaskList;	
//	TaskList m_vecTaskList;					//����������б�
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

	 /**  ׼�����Ժ���
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void PreTest() ;

	/**  ����������Ϣ��
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool SetCmdMsgId( const u32 dwMsgId );

	/**  ����׼����Ϣ����
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool SetPreMsgQue( IMsgQueMngr *pQue );

	/**  ��ȡ׼����Ϣ����
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	IMsgQueMngr* GetPreMsgQue() const ;

	/**  ����/��ȡ����
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool SetProcedure( const EmTestCaseProcedure emProcedure );

	EmTestCaseProcedure GetProcedure() const ;

	//static CCmdTestCase* GetCmdTestPtr();


protected:
	u32	m_dwCmdMsgId;			       //������ϢId
	IMsgQueMngr   *m_pPreMsgQue;       //׼����Ϣ����
	EmTestCaseProcedure m_emProcedure; //���������
	//static CCmdTestCase* m_pThat;

private:
	/**  ��鵱ǰ��������Դƥ����
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
	/**  ����ִ�������ַ���
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool SetExeCmdStr( const String strCmdStr );


protected:
	String m_strExeCmd;     //ִ�п���̨�ַ���
};