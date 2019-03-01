#ifndef _PLAYERLOGIC_H_
#define _PLAYERLOGIC_H_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//显示区域离上下左右固定的长度(与界面同步)
#define WND_LEFT_LEN		310				
#define WND_RIGHT_LEN		40
#define WND_TOP_LEN			159
#define WND_BOTTOM_LEN		136




class CPlayerLogic : public CNotifyUIImpl
{
public:
	/*
		测试时设备图片容器名
	*/
	static const String strDvcPic;
	/*
		主窗口名	
	*/
	static const String strMainWindow;
	/*
		播放器窗口名	
	*/
	static const String strPlayerWinwow;

public:
	CPlayerLogic();
	~CPlayerLogic();
protected:
	/** 父窗口尺寸变化消息 
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool OnParentSize( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/**  父窗口移动
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnParentMove( WPARAM wParam, LPARAM lParam, bool& bHandle );
	/** 父窗口尺寸变化消息 
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool OnInit( TNotifyUI& msg );
	/**双击事件  
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnDblClick( TNotifyUI& msg );
	/** 调整播放器区域(与父窗口同步)
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
