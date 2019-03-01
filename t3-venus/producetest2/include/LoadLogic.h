#ifndef _LOADLOGIC_H_
#define _LOADLOGIC_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CLoadLogic : public CNotifyUIImpl
{
public:
	/*
		设备选择下拉框名
	*/
	const static String strCbLoadDvc;	
	/*
		hw编辑框名	
	*/			
	const static String strREditHw;
	/*
		起始IP编辑框名	
	*/
	const static String strREditStartIp;
	/*
		起始Mac编辑框名	
	*/
	const static String strREditStartMac;
	/*
		Tftp路径编辑框名	
	*/
	const static String strREditTftpPath;
	/*
		打开路径按键名	
	*/
	const static String strBtnBrowsePath;
	/*
		保存编辑区域按键名	
	*/
	const static String strBtnSaveEdit;
	/*
		取消编辑区域按键名
	*/
	const static String strBtnCancelEdit;
	/*
		修改编辑区域按键名	
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
		序列号	
	*/
	const static String strEditSn;
	/*
		进度条	
	*/
	const static String strProgressLoad;
	/*
		显示的状态字符串	
	*/
	const static String strStateDis;
	/*
		分配的IP	
	*/
	const static String strLoadIp;
	/*
		分配的Mac	
	*/
	const static String strLoadMac;
	/*
		板卡生产日期	
	*/
	const static String strLoadDate;
	/*
		板卡图片	
	*/
	const static String strLoadPic;
	/*
		加载结果	
	*/
	const static String strLoadResult;
public:
	CLoadLogic();
	~CLoadLogic();
	/**初始化消息  
	 *  @param[in] 消息
	 *  @node 
	 *  @return 
	 */
	bool OnInit( TNotifyUI& msg );

	/**保存编辑按键消息
	 *  @param[in] 消息
	 *  @node 
	 *  @return 
	 */
	bool OnBtnSaveEdit( TNotifyUI& msg );

	/**修改编辑按键消息
	 *  @param[in] 消息
	 *  @node 
	 *  @return 
	 */
	bool OnBtnChangeEdit( TNotifyUI& msg );

	/**取消编辑按键消息
	 *  @param[in] 消息
	 *  @node 
	 *  @return 是否成功
	 */
	bool OnBtnCancelEdit( TNotifyUI& msg );

	/**选择设备消息
	 *  @param[in] 消息
	 *  @node 
	 *  @return 是否成功
	 */
	bool OnDvcSelected( TNotifyUI& msg );

	/**选择设备消息
	 *  @param[in] 消息
	 *  @node 
	 *  @return 是否成功
	 */
	bool OnBrowsePath( TNotifyUI& msg );

	/**序列号变化消息
	 *  @param[in] 消息
	 *  @node 
	 *  @return 是否成功
	 */
	bool OnSerialChange( TNotifyUI& msg );

	/** RichEdit失去焦点处理
	 *  @param[in] 消息
	 *  @node 
	 *  @return 是否成功
	 */
	bool OnREditLoseFocus( TNotifyUI& msg );

	/** 加载状态变化消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnLoadStateChange( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** UI状态变化消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnUIStateChange( WPARAM wParam, LPARAM lParam, bool& bHandle );


	/** 更新显示的状态
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnUpdateState( WPARAM wParam, LPARAM lParam, bool& bHandle );
	/** 设备变化消息 
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool OnDvcChange( WPARAM wParam, LPARAM lParam, bool& bHandle );
	/** 开始加载请求 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnStartLoadReq( WPARAM wParam, LPARAM lParam, bool& bHandle );
	/** 加载错误
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnLoadErr( WPARAM wParam, LPARAM lParam, bool& bHandle );
	/** tftp路径变化
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnTftpPathChange( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** 界面模式变化
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnUIModeChange( WPARAM wParam, LPARAM lParam, bool& bHandle );
	/** 刷新左侧编辑区域控件的状态
	*  @param[in] bEnabled 启用/禁用
	*  @node 
	*  @return 是否成功
	*/
	bool RefreshCtrlState( bool bEnabled );

	/** 保存左侧编辑区域数据
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
	bool SaveEditData();

	/** 刷新左侧编辑区域数据
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
	bool RefreshEditData();

	/** 检查左侧编辑区域合法性
	*  @param[out] 错误消息 
	*  @node 
	*  @return 是否合法
	*/
	bool CheckEditLegal( String &strErrMsg );
	/**  检查Mac地址格式
	 *  @param[in] Mac地址字符串
	 *  @node 
	 *  @return 正确/错误
	 */
	bool CheckMacFormat( const s8* pchMac );


	/**  检查IP地址格式
	 *  @param[in] IP地址字符串
	 *  @node 
	 *  @return 正确/错误
	 */
	bool CheckHardVerFormat( const s8* pchHardVer );

	/**  检查硬件版本格式
	 *  @param[in] IP地址字符串
	 *  @node 
	 *  @return 正确/错误
	 */
	bool CheckIpFormat( const s8* pchIp );

	/**  检查IP地址格式
	 *  @param[in] IP地址字符串
	 *  @node 
	 *  @return 正确/错误
	 */
	bool CheckUIState();
	/** 加载结束 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnLoadEnd();

	/** 正在加载
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnLoading();

	DECLARE_MSG_MAP()
private:
	/*
		绘制管理器	
	*/
	CPaintManagerUI *m_pPaintMngr;

	/*
		修改之前的设备指针
		点击"修改"时创建
		"保存"和"取消"时释放
	*/
	IDevice *m_pPreviousDvc;

	/*
		修改之前的combobox的选择
	*/
	u32		m_dwPreviousSelIdx;
};
#endif