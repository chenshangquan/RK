// MainLogic.h: interface for the CMainLogic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINLOGIC_H__D2D7F34D_34EC_4A78_9C9F_4A11AD89D464__INCLUDED_)
#define AFX_MAINLOGIC_H__D2D7F34D_34EC_4A78_9C9F_4A11AD89D464__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainLogic : public CNotifyUIImpl
{
public:
	CMainLogic();
	virtual ~CMainLogic();

protected:

	/** �رհ�ť�¼� 
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnBtnClose( TNotifyUI& msg );

	/** ��С����ť�¼� 
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnBtnMin( TNotifyUI& msg );

	/** ��󻯰�ť�¼� 
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnBtnMax( TNotifyUI& msg );

	/** �л�ģʽ��ť
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/	
	bool OnBtnSwitch( TNotifyUI& msg );

	/**�ָ�����  
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnBtnRestore( TNotifyUI& msg );
	/** ���ڴ�С�仯 
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnSize( TNotifyUI& msg );
	/** �����ƶ��¼� 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnMove( TNotifyUI& msg );


	/** ����ܳ�ʼ���¼� 
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnMainIni( TNotifyUI& msg );
	/** ���������¼�  
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnDestory( TNotifyUI& msg );
	/** UIģʽ�ı���Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnUIModeChange( WPARAM wParam, LPARAM lParam, bool& bHandle );
	/** ��ʼ������ҳ�� 
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool InitTestPage();
	/** ��ʼ������ҳ��
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool InitLoadPage();
	/** ��ʼ�������ն� 
	 *  @param[in] ģʽ
	 *  @node 
	 *  @return 
	 */
	bool InitST( EmUIMode emMode );
	/** ������Ļ״̬ ������󻯴��� 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void AjustMaxWnd();

public:
	static const String strCfgFile;			//�����ļ���
	static const String strDvcTag;			//�豸��ǩ
	static const String strCbDvcType;		//�����豸����������
	static const String strCbLoadDvc;		//�����豸����������
	static const String strComboItem;		//������Ԫ	
	static const String strNormalPage;		//����ҳ��
	static const String strTestPage;		//����ҳ��
	static const String strLoadPage;		//����ҳ��
	static const String strSuperTerminal;	//�����ն�
	static const String strLabelComboItem;	//Item��Label
	static const String strBtnMax;			//��󻯰���
	static const String strBtnRestore;		//�ָ�����
	static const String strBtnSwitch;			//��󻯰���
	static const String strBoradTag;			//�忨��ǩ
	static const String strTestTag;				//���Ա�ǩ
	static const String strLoadTag;				//���ر�ǩ

private:
	CPaintManagerUI *m_pPaintMngr;			
	DECLARE_MSG_MAP()
};



#endif // !defined(AFX_MAINLOGIC_H__D2D7F34D_34EC_4A78_9C9F_4A11AD89D464__INCLUDED_)
