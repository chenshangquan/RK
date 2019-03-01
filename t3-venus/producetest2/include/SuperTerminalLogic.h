#ifndef _SUPERTERMINALLOGIC_H_
#define _SUPERTERMINALLOGIC_H_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CComm.h"
#ifndef _CHILD_POS
//��ʾ�������������ҹ̶��ĳ���(�����ͬ��)
#define WND_LEFT_LEN		310				
#define WND_RIGHT_LEN		40
#define WND_TOP_LEN			159
#define WND_BOTTOM_LEN		136
#endif

class CSuperTerminalLogic : public CNotifyUIImpl
{
public:
	CSuperTerminalLogic();
	~CSuperTerminalLogic();
public:

	/*
		��ʾ�����ն˰���	
	*/
	const static String strBtnShowST;
	/*
		�����ն�ҳ��	
	*/
	const static String strPageST;
	/*
		�˿�ѡ���	
	*/
	const static String strCbComPort;
	/*
		combo��Ԫ	
	*/
	const static String strComboItem;
	/*
		�����ն���ʾ����
	*/
	const static String strREditST;

	/*
		����ʱ�豸ͼƬ������
	*/
	static const String strDvcPic;
	/*
		��������	
	*/
	static const String strMainWindow;
	/*
		�����ն˴�����	
	*/
	static const String strStWindow;
	/*
		�����ն���ʾ
	*/
	static	CRichEditUI *pREditDisp;

protected:
	/** ��ʾ�����ն˰�����Ϣ
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool OnBtnShowSt( TNotifyUI& msg );
	/** ѡ�񴮿���Ϣ 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnPortSelected( TNotifyUI& msg );
	/** ������Ϣ 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnInput( TNotifyUI& msg );

	/** ���RichEdit 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnReditClick( TNotifyUI& msg );

	/** ������Ϣ ���ⰴ������
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnSpecialKey( TNotifyUI& msg );
	
	/**  �����ն˳�ʼ����Ϣ
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�Z
	 */
	bool OnInit( TNotifyUI& msg );

	/** �����ڳߴ�仯��Ϣ 
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool OnParentSize( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/**  �������ƶ�
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnParentMove( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/**  �������ݿ���
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnCommAvailable( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/**  ˢ�³����ն���ʾ��Ϣ
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool UpdateComDisp( WPARAM wParam, LPARAM lParam, bool& bHandle );

	bool OnKillFocus( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/**  ���䳬���ն�λ��
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool AjustPos();

	/**  ö�ٴ��ڵ�combobox
	 *  @param[in] comboָ��
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool GetAllComPort( CComboUI *pCombo );

	/**	ճ��  
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void Paste();

	void SelectAll();

	/*
		���ڶ�ȡ���ݻص�����	
	*/
	static 	void CALLBACK CbReadCallback();


	DECLARE_MSG_MAP()

private:
	/*
		���ƹ�����	
	*/
	CPaintManagerUI *m_pPaintMngr;
	/*
		����ѡ���	
	*/
	CComboUI *m_pCombo;
	/*
	    ��ʼ����־
	*/
	bool m_bInit;

	/*
		����ָ��	
	*/
	static CComm *s_pCom;
	/*
		�����ն���ʾ
	*/
	static  bool s_PrintFlag;

	bool m_bExpand;

};




#endif