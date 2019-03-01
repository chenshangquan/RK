#ifndef _SUPERTERMINALLOGIC_H_
#define _SUPERTERMINALLOGIC_H_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CComm.h"
#ifndef _CHILD_POS
//显示区域离上下左右固定的长度(与界面同步)
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
		显示超级终端按键	
	*/
	const static String strBtnShowST;
	/*
		超级终端页面	
	*/
	const static String strPageST;
	/*
		端口选择框	
	*/
	const static String strCbComPort;
	/*
		combo单元	
	*/
	const static String strComboItem;
	/*
		超级终端显示内容
	*/
	const static String strREditST;

	/*
		测试时设备图片容器名
	*/
	static const String strDvcPic;
	/*
		主窗口名	
	*/
	static const String strMainWindow;
	/*
		超级终端窗口名	
	*/
	static const String strStWindow;
	/*
		超级终端显示
	*/
	static	CRichEditUI *pREditDisp;

protected:
	/** 显示超级终端按键消息
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool OnBtnShowSt( TNotifyUI& msg );
	/** 选择串口消息 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnPortSelected( TNotifyUI& msg );
	/** 输入消息 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnInput( TNotifyUI& msg );

	/** 点击RichEdit 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnReditClick( TNotifyUI& msg );

	/** 输入消息 特殊按键处理
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnSpecialKey( TNotifyUI& msg );
	
	/**  超级终端初始化消息
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功Z
	 */
	bool OnInit( TNotifyUI& msg );

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

	/**  窗口数据可用
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnCommAvailable( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/**  刷新超级终端显示消息
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool UpdateComDisp( WPARAM wParam, LPARAM lParam, bool& bHandle );

	bool OnKillFocus( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/**  适配超级终端位置
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool AjustPos();

	/**  枚举串口到combobox
	 *  @param[in] combo指针
	 *  @node 
	 *  @return 是否成功
	 */
	bool GetAllComPort( CComboUI *pCombo );

	/**	粘贴  
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void Paste();

	void SelectAll();

	/*
		串口读取数据回调函数	
	*/
	static 	void CALLBACK CbReadCallback();


	DECLARE_MSG_MAP()

private:
	/*
		绘制管理器	
	*/
	CPaintManagerUI *m_pPaintMngr;
	/*
		串口选择框	
	*/
	CComboUI *m_pCombo;
	/*
	    初始化标志
	*/
	bool m_bInit;

	/*
		串口指针	
	*/
	static CComm *s_pCom;
	/*
		超级终端显示
	*/
	static  bool s_PrintFlag;

	bool m_bExpand;

};




#endif