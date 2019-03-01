// ICommonOp.h: interface for the ICommonOp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICOMMONOP_H__DBC77325_3262_4246_BCB1_51CF05288BE7__INCLUDED_)
#define AFX_ICOMMONOP_H__DBC77325_3262_4246_BCB1_51CF05288BE7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/*
	常用操作类，都是一些静态函数
*/
class ICommonOp  
{
public:

	/**  查找控件
	 *  @param[in] 绘制管理器，控件名，启用/禁用
	 *  @node 
	 *  @return 控件指针
	 */
	static CControlUI* FindControl( CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent = NULL );

	/**  启用/禁用控件
	 *  @param[in] 启用/禁用，绘制管理器，控件名，父控件
	 *  @node 
	 *  @return 是否成功
	 */
	static bool ShowControl( bool bVisible, CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent = NULL );

	/**  显示/隐藏控件
	 *  @param[in] 显示/隐藏，绘制管理器，控件名，父控件
	 *  @node 
	 *  @return 是否成功
	 */
	static bool EnableControl( bool bEnabled, CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent = NULL );

	/**  设置控件文字
	 *  @param[in] 文字，绘制管理器，控件名，父控件
	 *  @node 
	 *  @return 是否成功
	 */
	static bool SetControlText( String strText, CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent = NULL );

	/**  获取控件文字
	 *  @param[in] 绘制管理器，控件名，父控件
	 *  @node 
	 *  @return 文字字符串
	 */
	static String GetControlText( CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent = NULL );
	/** 设置控件边框格式 
	 *  @param[in] dwColor:颜色 dwSize:宽度
	 *  @node 
	 *  @return 
	 */
	static bool SetControlBorderFormat( u32 dwColor, u32 dwSize, CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent = NULL );

	/**  设置控件背景图片
	 *  @param[in] 背景图片文件名，绘制管理器，控件名，父控件
	 *  @node 
	 *  @return 文字字符串
	 */
	static bool SetControlBkImg( String strFile, CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent = NULL );

	/**  设置Option控件选择状态
	 *  @param[in] 是否选中，绘制管理器，控件名，父控件
	 *  @node 
	 *  @return 是否成功
	 */
	static bool OptionSelect( bool bSelect, CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent = NULL );

	/**  获取XML节点属性，并转换为整形
	 *  @param[in] 节点，标签，值引用
	 *  @node 
	 *  @return 属性值（整形）
	 */
	static bool GetNodeValueInt( DocNode Node, String Tag, u32 &dwValue );
	
	/**  获取XML节点属性字符串
	 *  @param[in] 节点，标签
	 *  @node 
	 *  @return 属性字符串
	 */
	static String GetNodeValueStr( DocNode Node, String Tag );

	/**  判断字符串是否为数字
	 *  @param[in] 字符串
	 *  @node 
	 *  @return 是否为数字
	 */
	static bool IsDigit( String strDig );

	/**  根据名字在设备中获取测试项
	 *  @param[in] 
	 *  @node 
	 *  @return 测试项指针
	 */
	static ITestCase* GetTestCase( IDevice *pDvc, String strCaseName);

	/**  根据索引获取测试项
	 *  @param[in] 
	 *  @node 
	 *  @return 测试项指针
	 */
	static ITestCase* GetTestCase( IBoard *pBoard, u32 dwIdx );

	/**  发送界面消息
	 *  @param[in] 消息Id，消息内容指针
	 *  @node 
	 *  @return 是否成功
	 */
	static bool Notify( u16 wMsgId, void *pData = NULL );

	/**  显示提示对话框
	 *  @param[in] 提示字符串
	 *  @node 
	 *  @return 是否成功
	 */
	static bool ShowNotifyDlg( const String &strNotify );

	/**  显示选择对话框
	 *  @param[in] 提示字符串
	 *  @node 
	 *  @return 选择结果
	 */
	static bool ShowChooseDlg( const String &strNotify );
	/**  获取文件路径
	 *  @param[in] 提示字符串
	 *  @node 
	 *  @return 文件路径字符串
	 */
	static String GetFolderDir(const String strNotify = "选择文件" );

	/** 检查文件/路径是否存在 
	 *  @param[in] strFilePath : 文件/文件夹路径
	 *  @node 
	 *  @return 是否存在
	 */
	static bool CheckFileExists( const String &strFilePath );
	/** 注册字符串宏映射 
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	static bool RegMacros();

	/** 注册观察者  
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	static bool RegObservers();
	/** 新需求：将XXX格式的硬件版本号转换为X.XX 
	 *  @param[in] 原始格式
	 *  @node 
	 *  @return 转换后的格式
	 */
	static String ConvertHardVer( const s8 *pchHardVer );
	/** 将字符串转换为大写
	 *  @param[in] 字符串指针
	 *  @node 
	 *  @return 
	 */
	static bool ConvertToUpper( LPSTR pchStr );
protected:
	/** 获取路径对话框回调函数 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	static s32 CALLBACK BrowseCallbackProc(HWND hwnd,UINT uMsg,LPARAM lParam,LPARAM lpData);

};

#endif // !defined(AFX_ICOMMONOP_H__DBC77325_3262_4246_BCB1_51CF05288BE7__INCLUDED_)
