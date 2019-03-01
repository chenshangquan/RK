#ifndef _LOADLOGIC_H_
#define _LOADLOGIC_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CLoadLogic : public CNotifyUIImpl
{
public:
	/*
		�豸ѡ����������
	*/
	const static String strCbLoadDvc;	
	/*
		hw�༭����	
	*/			
	const static String strREditHw;
	/*
		��ʼIP�༭����	
	*/
	const static String strREditStartIp;
	/*
		��ʼMac�༭����	
	*/
	const static String strREditStartMac;
	/*
		Tftp·���༭����	
	*/
	const static String strREditTftpPath;
	/*
		��·��������	
	*/
	const static String strBtnBrowsePath;
	/*
		����༭���򰴼���	
	*/
	const static String strBtnSaveEdit;
	/*
		ȡ���༭���򰴼���
	*/
	const static String strBtnCancelEdit;
	/*
		�޸ı༭���򰴼���	
	*/
	const static String strBtnChangeEdit;
	/*
		PID	
	*/
	const static String strLabelPid;
	/*
		HID	
	*/
	const static String strLabelHid;
	/*
		���к�	
	*/
	const static String strEditSn;
	/*
		������	
	*/
	const static String strProgressLoad;
	/*
		��ʾ��״̬�ַ���	
	*/
	const static String strStateDis;
	/*
		�����IP	
	*/
	const static String strLoadIp;
	/*
		�����Mac	
	*/
	const static String strLoadMac;
	/*
		�忨��������	
	*/
	const static String strLoadDate;
	/*
		�忨ͼƬ	
	*/
	const static String strLoadPic;
	/*
		���ؽ��	
	*/
	const static String strLoadResult;
public:
	CLoadLogic();
	~CLoadLogic();
	/**��ʼ����Ϣ  
	 *  @param[in] ��Ϣ
	 *  @node 
	 *  @return 
	 */
	bool OnInit( TNotifyUI& msg );

	/**����༭������Ϣ
	 *  @param[in] ��Ϣ
	 *  @node 
	 *  @return 
	 */
	bool OnBtnSaveEdit( TNotifyUI& msg );

	/**�޸ı༭������Ϣ
	 *  @param[in] ��Ϣ
	 *  @node 
	 *  @return 
	 */
	bool OnBtnChangeEdit( TNotifyUI& msg );

	/**ȡ���༭������Ϣ
	 *  @param[in] ��Ϣ
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool OnBtnCancelEdit( TNotifyUI& msg );

	/**ѡ���豸��Ϣ
	 *  @param[in] ��Ϣ
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool OnDvcSelected( TNotifyUI& msg );

	/**ѡ���豸��Ϣ
	 *  @param[in] ��Ϣ
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool OnBrowsePath( TNotifyUI& msg );

	/**���кű仯��Ϣ
	 *  @param[in] ��Ϣ
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool OnSerialChange( TNotifyUI& msg );

	/** RichEditʧȥ���㴦��
	 *  @param[in] ��Ϣ
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool OnREditLoseFocus( TNotifyUI& msg );

	/** ����״̬�仯��Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnLoadStateChange( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** UI״̬�仯��Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnUIStateChange( WPARAM wParam, LPARAM lParam, bool& bHandle );


	/** ������ʾ��״̬
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnUpdateState( WPARAM wParam, LPARAM lParam, bool& bHandle );
	/** �豸�仯��Ϣ 
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool OnDvcChange( WPARAM wParam, LPARAM lParam, bool& bHandle );
	/** ��ʼ�������� 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnStartLoadReq( WPARAM wParam, LPARAM lParam, bool& bHandle );
	/** ���ش���
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnLoadErr( WPARAM wParam, LPARAM lParam, bool& bHandle );
	/** tftp·���仯
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnTftpPathChange( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** ����ģʽ�仯
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnUIModeChange( WPARAM wParam, LPARAM lParam, bool& bHandle );
	/** ˢ�����༭����ؼ���״̬
	*  @param[in] bEnabled ����/����
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool RefreshCtrlState( bool bEnabled );

	/** �������༭��������
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool SaveEditData();

	/** ˢ�����༭��������
	*  @param[in] 
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool RefreshEditData();

	/** ������༭����Ϸ���
	*  @param[out] ������Ϣ 
	*  @node 
	*  @return �Ƿ�Ϸ�
	*/
	bool CheckEditLegal( String &strErrMsg );
	/**  ���Mac��ַ��ʽ
	 *  @param[in] Mac��ַ�ַ���
	 *  @node 
	 *  @return ��ȷ/����
	 */
	bool CheckMacFormat( const s8* pchMac );


	/**  ���IP��ַ��ʽ
	 *  @param[in] IP��ַ�ַ���
	 *  @node 
	 *  @return ��ȷ/����
	 */
	bool CheckHardVerFormat( const s8* pchHardVer );

	/**  ���Ӳ���汾��ʽ
	 *  @param[in] IP��ַ�ַ���
	 *  @node 
	 *  @return ��ȷ/����
	 */
	bool CheckIpFormat( const s8* pchIp );

	/**  ���IP��ַ��ʽ
	 *  @param[in] IP��ַ�ַ���
	 *  @node 
	 *  @return ��ȷ/����
	 */
	bool CheckUIState();
	/** ���ؽ��� 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnLoadEnd();

	/** ���ڼ���
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnLoading();

	DECLARE_MSG_MAP()
private:
	/*
		���ƹ�����	
	*/
	CPaintManagerUI *m_pPaintMngr;

	/*
		�޸�֮ǰ���豸ָ��
		���"�޸�"ʱ����
		"����"��"ȡ��"ʱ�ͷ�
	*/
	IDevice *m_pPreviousDvc;

	/*
		�޸�֮ǰ��combobox��ѡ��
	*/
	u32		m_dwPreviousSelIdx;
};
#endif