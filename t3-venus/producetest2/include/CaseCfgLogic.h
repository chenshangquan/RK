#ifndef _CASECFGLOGIC_H_
#define _CASECFGLOGIC_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCaseCfgLogic : public CNotifyUIImpl
{
public:
	CCaseCfgLogic();
	~CCaseCfgLogic();

public:
	/*
		文件路径编辑框		
	*/
	static const String strEditFilePath;	
	/*
		取消按键
	*/
	static const String strBtnCancel;	

protected:
	/** 确定按键消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnOk( TNotifyUI& msg );
	
	/** 取消按键消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnCancel( TNotifyUI& msg );

	/** 取消按键消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnBrowseDir( TNotifyUI& msg );
	/** 路径改变  
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnPathChange( TNotifyUI& msg );
	/** 初始化消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool Ini( TNotifyUI& msg );

	DECLARE_MSG_MAP()
};

#endif