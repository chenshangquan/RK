#ifndef _TESTLOGIC_H_
#define _TESTLOGIC_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define CHECKMANAGER if( m_pPaintMngr == NULL){\
						LOGEVENT("绘制管理器为空\n");\
						return false;\
						}

class CTestLogic : public CNotifyUIImpl
{
public:
	CTestLogic();
	~CTestLogic();

public:
	static const String strCaseListItem;	//测试项列表单元
	static const String strCaseLst;			//测试项列表
	static const String strCbDvcType;		//设备种类下拉框
	static const String strCaseName;		//测试项名
	static const String strCaseDesc;		//测试项描述
	static const String strBtnConfig;		//设置按键
	static const String strLayoutInfo;		//信息描述布局
	static const String strBtnStart;		//开始测试按键
	static const String strBtnStop;			//开始测试按键
	static const String strStateDis;		//显示状态
	static const String strOptAdded;		//添加勾选框
	static const String strOptSelectAll;	//全选勾选框
	static const String strCaseState;		//测试项状态
	static const String strLayoutResult;	//测试结果布局（正常、异常）
	static const String strNextTestBtn;     //音量值测试项特有布局（下一项）
	static const String strSysPreBtn;   //系统准备按键
	static const String strBtnNormal;		//正常按键
	static const String strBtnAbnormal;		//异常按键
	static const String strSysPrepareBtn;   //系统准备按键
	static const String strOptRestore;		//回复出厂设置
	static const String strDvcPic;			//设备图片
	static const String strLabelSn;			//序列号
	static const String strLabelDvcType;	//设备类型
	static const String strLabelIp;			//IP地址
	static const String strLabelMac;		//Mac地址
	static const String strLabelSoftVer;	//软件版本
	static const String strLabelHardVer;	//硬件版本
	static const String strCntnrResult;		//测试结果

	static const u32 dwItemHeight;			//单元高度
	static const u32 dwItemSlectedHeight;	//单元选中高度

	string m_strText;

protected:

	/** 选择设备消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnDvcSelected( TNotifyUI& msg );    

	/** 选中测试项消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnCaseSelected( TNotifyUI& msg );    

	/** 开始测试消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnStartTest( TNotifyUI& msg );

	/** 停止测试消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
    bool OnStopTest( TNotifyUI& msg );
	/** 正常按键消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnNormal( TNotifyUI& msg );  
	/** 异常按键消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnAbnormal( TNotifyUI& msg );  
	
	/** 测试项添加勾选消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnCaseAdded( TNotifyUI& msg );   

	/** 全选勾选
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnSelectAll( TNotifyUI& msg );

	/** 恢复出厂设置勾选消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnRestoreChange( TNotifyUI& msg );

	/** 测试项设置按键消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnCaseConfig( TNotifyUI& msg );

	/** 初始化消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnIni( TNotifyUI& msg );
	bool OnNextTest( TNotifyUI& msg );
	bool OnSysPrepare( TNotifyUI& msg );
	//用户消息
		/** 设备变化消息
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
	bool OnDvcChange( WPARAM wParam, LPARAM lParam, bool& bHandle );
	
	/** 板卡准备好消息
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
	bool OnBrdReady( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** 板卡结束消息
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
	bool OnBrdEnd( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** 状态字符串更新消息
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
	bool OnUpdateState( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** UI状态改变消息
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
	bool OnUIStateChange( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** UI模式改变消息
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
	bool OnUIModeChange( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** 设备断链消息处理
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
	bool OnBrdDisconnect( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** 测试项状态变化
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
	bool OnCaseStateChange( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** 板卡信息加载成功消息
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
	bool OnBrdInfoLoadSuccess( WPARAM wParam, LPARAM lParam, bool& bHandle );

	/** 板卡测试项加载失败消息
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
	bool OnCaseLoadFail( WPARAM wParam, LPARAM lParam, bool& bHandle );
	/** 开始恢复出厂设置消息 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnStartRestore( WPARAM wParam, LPARAM lParam, bool& bHandle );
    /** 板卡恢复成功
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
	bool OnRestoreSuccess( WPARAM wParam, LPARAM lParam, bool& bHandle );

    /** 板卡恢复失败
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
//	bool OnRestoreFail( WPARAM wParam, LPARAM lParam, bool& bHandle );

    /** 测试中止消息
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
	bool OnTestAbort( WPARAM wParam, LPARAM lParam, bool& bHandle );
	bool OnResultChange( WPARAM wParam, LPARAM lParam, bool& bHandle );
    /** 显示是否测试下一项按钮消息
	*  @param[in] 
	*  @node 
	*  @return 是否显示
	*/
	bool OnShowBtn( WPARAM wParam, LPARAM lParam, bool& bHandle );
    /** 开始测试按钮是否可用 6/24 
	*  @param[in] 
	*  @node 
	*  @return 
	*/
//	bool OnStartBtnEnable( WPARAM wParam, LPARAM lParam, bool& bHandle );
	//操作函数

	/** 加载测试项列表
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
	bool LoadCaseList();

	/** 创建设备
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
	bool CreateDvc();

	/** 加载设备信息
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
	bool LoadDvcInfo();

	/** 清空设备信息
	*  @param[in] 
	*  @node 
	*  @return 是否成功
	*/
	bool ClearDvcInfo();
	/** 展开某测试项
	*  @param[in] strName测试项名, bSet是否可以设置
	*  @node 
	*  @return 是否成功
	*/
	bool ExpandCase( const String &strName , bool bSet = true );


	/** 根据测试项名获取单元容器
	*  @param[in] 测试项名
	*  @node 
	*  @return 是否成功
	*/
	CControlUI* GetCaseContainer( const String &strName );

	/** 还原测试项列表状态
	*  @param[in] 是否能勾选测试项
	*  @node 
	*  @return 
	*/
	void RestoreList( bool bSelectable = true );

	/** UI准备状态
	*  @param[in] 
	*  @node 
	*  @return 
	*/
	void OnUIPre();

	/** UI准备好状态
	*  @param[in] 
	*  @node 
	*  @return 
	*/
	void OnUIRready();

	/** UI测试状态
	*  @param[in] 
	*  @node 
	*  @return 
	*/
	void OnUITesting();

	/** 结束测试项(用户选择结论后调用)
	*  @param[in] 测试项指针
	*  @node 
	*  @return 
	*/
	void EndCase( ITestCase *pTestCase );

public:


private:
	CPaintManagerUI *m_pPaintMngr;	
	CListUI *m_pCaseList;
//	CTestCaseContainer m_CaseContainer;						//测试项容器
	DECLARE_MSG_MAP()
};

#endif