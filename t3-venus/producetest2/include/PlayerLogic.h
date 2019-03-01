#ifndef _PLAYERLOGIC_H_
#define _PLAYERLOGIC_H_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//��ʾ�������������ҹ̶��ĳ���(�����ͬ��)
#define WND_LEFT_LEN		310				
#define WND_RIGHT_LEN		40
#define WND_TOP_LEN			159
#define WND_BOTTOM_LEN		136




class CPlayerLogic : public CNotifyUIImpl
{
public:
	/*
		����ʱ�豸ͼƬ������
	*/
	static const String strDvcPic;
	/*
		��������	
	*/
	static const String strMainWindow;
	/*
		������������	
	*/
	static const String strPlayerWinwow;

public:
	CPlayerLogic();
	~CPlayerLogic();
protected:
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
	/** �����ڳߴ�仯��Ϣ 
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool OnInit( TNotifyUI& msg );
	/**˫���¼�  
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnDblClick( TNotifyUI& msg );
	/** ��������������(�븸����ͬ��)
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool AjustPlayer();
protected:
	CPaintManagerUI *m_pPaintMngr;
	DECLARE_MSG_MAP()

};
#endif
