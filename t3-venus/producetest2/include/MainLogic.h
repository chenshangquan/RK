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

	/** 关闭按钮事件 
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnBtnClose( TNotifyUI& msg );

	/** 最小化按钮事件 
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnBtnMin( TNotifyUI& msg );

	/** 最大化按钮事件 
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnBtnMax( TNotifyUI& msg );

	/** 切换模式按钮
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/	
	bool OnBtnSwitch( TNotifyUI& msg );

	/**恢复按键  
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnBtnRestore( TNotifyUI& msg );
	/** 窗口大小变化 
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnSize( TNotifyUI& msg );
	/** 窗口移动事件 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnMove( TNotifyUI& msg );


	/** 主框架初始化事件 
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnMainIni( TNotifyUI& msg );
	/** 窗口销毁事件  
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnDestory( TNotifyUI& msg );
	/** UI模式改变消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnUIModeChange( WPARAM wParam, LPARAM lParam, bool& bHandle );
	/** 初始化测试页面 
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool InitTestPage();
	/** 初始化加载页面
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool InitLoadPage();
	/** 初始化超级终端 
	 *  @param[in] 模式
	 *  @node 
	 *  @return 
	 */
	bool InitST( EmUIMode emMode );
	/** 根据屏幕状态 调整最大化窗口 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void AjustMaxWnd();

public:
	static const String strCfgFile;			//配置文件名
	static const String strDvcTag;			//设备标签
	static const String strCbDvcType;		//测试设备种类下拉框
	static const String strCbLoadDvc;		//加载设备种类下拉框
	static const String strComboItem;		//下拉框单元	
	static const String strNormalPage;		//正常页面
	static const String strTestPage;		//测试页面
	static const String strLoadPage;		//加载页面
	static const String strSuperTerminal;	//超级终端
	static const String strLabelComboItem;	//Item的Label
	static const String strBtnMax;			//最大化按键
	static const String strBtnRestore;		//恢复按键
	static const String strBtnSwitch;			//最大化按键
	static const String strBoradTag;			//板卡标签
	static const String strTestTag;				//测试标签
	static const String strLoadTag;				//加载标签

private:
	CPaintManagerUI *m_pPaintMngr;			
	DECLARE_MSG_MAP()
};



#endif // !defined(AFX_MAINLOGIC_H__D2D7F34D_34EC_4A78_9C9F_4A11AD89D464__INCLUDED_)
