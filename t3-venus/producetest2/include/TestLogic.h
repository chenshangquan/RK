#ifndef _TESTLOGIC_H_
#define _TESTLOGIC_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define CHECKMANAGER if( m_pPaintMngr == NULL){\
						LOGEVENT("���ƹ�����Ϊ��\n");\
						return false;\
						}

class CTestLogic : public CNotifyUIImpl
{
public:
	CTestLogic();
	~CTestLogic();

public:
	static const String strCaseListItem;	//�������б�Ԫ
	static const String strCaseLst;			//�������б�
	static const String strCbDvcType;		//�豸����������
	static const String strCaseName;		//��������
	static const String strCaseDesc;		//����������
	static const String strBtnConfig;		//���ð���
	static const String strLayoutInfo;		//��Ϣ��������
	static const String strBtnStart;		//��ʼ���԰���
	static const String strBtnStop;			//��ʼ���԰���
	static const String strStateDis;		//��ʾ״̬
	static const String strOptAdded;		//��ӹ�ѡ��
	static const String strOptSelectAll;	//ȫѡ��ѡ��
	static const String strCaseState;		//������״̬
	static const String strLayoutResult;	//���Խ�����֣��������쳣��
	static const String strNextTestBtn;     //����ֵ���������в��֣���һ�
	static const String strSysPreBtn;   //ϵͳ׼������
	static const String strBtnNormal;		//��������
	static const String strBtnAbnormal;		//�쳣����
	static const String strSysPrepareBtn;   //ϵͳ׼������
	static const String strOptRestore;		//�ظ���������
	static const String strDvcPic;			//�豸ͼƬ
	static const String strLabelSn;			//���к�
	static const String strLabelDvcType;	//�豸����
	static const String strLabelIp;			//IP��ַ
	static const String strLabelMac;		//Mac��ַ
	static const String strLabelSoftVer;	//����汾
	static const String strLabelHardVer;	//Ӳ���汾
	static const String strCntnrResult;		//���Խ��

	static const u32 dwItemHeight;			//��Ԫ�߶�
	static const u32 dwItemSlectedHeight;	//��Ԫѡ�и߶�

	string m_strText;

protected:

	/** ѡ���豸��Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnDvcSelected( TNotifyUI& msg );    

	/** ѡ�в�������Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnCaseSelected( TNotifyUI& msg );    

	/** ��ʼ������Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnStartTest( TNotifyUI& msg );

	/** ֹͣ������Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
    bool OnStopTest( TNotifyUI& msg );
	/** ����������Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnNormal( TNotifyUI& msg );  
	/** �쳣������Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnAbnormal( TNotifyUI& msg );  
	
	/** ��������ӹ�ѡ��Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnCaseAdded( TNotifyUI& msg );   

	/** ȫѡ��ѡ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnSelectAll( TNotifyUI& msg );

	/** �ָ��������ù�ѡ��Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnRestoreChange( TNotifyUI& msg );

	/** ���������ð�����Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnCaseConfig( TNotifyUI& msg );

	/** ��ʼ����Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnIni( TNotifyUI& msg );
	bool OnNextTest( TNotifyUI& msg );
	bool OnSysPrepare( TNotifyUI& msg );
	//�û���Ϣ
		/** �豸�仯��Ϣ
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnDvcChange( WPARAM wParam, LPARAM lParam, bool& bHandle );
	
	/** �忨׼������Ϣ
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnBrdReady( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** �忨������Ϣ
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnBrdEnd( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** ״̬�ַ���������Ϣ
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnUpdateState( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** UI״̬�ı���Ϣ
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnUIStateChange( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** UIģʽ�ı���Ϣ
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnUIModeChange( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** �豸������Ϣ����
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnBrdDisconnect( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** ������״̬�仯
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnCaseStateChange( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** �忨��Ϣ���سɹ���Ϣ
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnBrdInfoLoadSuccess( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** �忨���������ʧ����Ϣ
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnCaseLoadFail( WPARAM wParam, LPARAM lParam, bool& bHandle );
	/** ��ʼ�ָ�����������Ϣ 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnStartRestore( WPARAM wParam, LPARAM lParam, bool& bHandle );
    /** �忨�ָ��ɹ�
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnRestoreSuccess( WPARAM wParam, LPARAM lParam, bool& bHandle );

    /** �忨�ָ�ʧ��
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
//	bool OnRestoreFail( WPARAM wParam, LPARAM lParam, bool& bHandle );

    /** ������ֹ��Ϣ
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnTestAbort( WPARAM wParam, LPARAM lParam, bool& bHandle );
	bool OnResultChange( WPARAM wParam, LPARAM lParam, bool& bHandle );
    /** ��ʾ�Ƿ������һ�ť��Ϣ
	*  @param[in] 
	*  @node 
	*  @return �Ƿ���ʾ
	*/
	bool OnShowBtn( WPARAM wParam, LPARAM lParam, bool& bHandle );
    /** ��ʼ���԰�ť�Ƿ���� 6/24 
	*  @param[in] 
	*  @node 
	*  @return 
	*/
//	bool OnStartBtnEnable( WPARAM wParam, LPARAM lParam, bool& bHandle );
	//��������

	/** ���ز������б�
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool LoadCaseList();

	/** �����豸
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool CreateDvc();

	/** �����豸��Ϣ
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool LoadDvcInfo();

	/** ����豸��Ϣ
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool ClearDvcInfo();
	/** չ��ĳ������
	*  @param[in] strName��������, bSet�Ƿ��������
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool ExpandCase( const String &strName , bool bSet = true );


	/** ���ݲ���������ȡ��Ԫ����
	*  @param[in] ��������
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	CControlUI* GetCaseContainer( const String &strName );

	/** ��ԭ�������б�״̬
	*  @param[in] �Ƿ��ܹ�ѡ������
	*  @node 
	*  @return 
	*/
	void RestoreList( bool bSelectable = true );

	/** UI׼��״̬
	*  @param[in] 
	*  @node 
	*  @return 
	*/
	void OnUIPre();

	/** UI׼����״̬
	*  @param[in] 
	*  @node 
	*  @return 
	*/
	void OnUIRready();

	/** UI����״̬
	*  @param[in] 
	*  @node 
	*  @return 
	*/
	void OnUITesting();

	/** ����������(�û�ѡ����ۺ����)
	*  @param[in] ������ָ��
	*  @node 
	*  @return 
	*/
	void EndCase( ITestCase *pTestCase );

public:


private:
	CPaintManagerUI *m_pPaintMngr;	
	CListUI *m_pCaseList;
//	CTestCaseContainer m_CaseContainer;						//����������
	DECLARE_MSG_MAP()
};

#endif