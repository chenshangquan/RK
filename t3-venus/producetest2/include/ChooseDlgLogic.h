#ifndef _CHOOSEDLGLOGIC_H_
#define _CHOOSEDLGLOGIC_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CChooseDlgLogic : public CNotifyUIImpl
{
public:
	CChooseDlgLogic(){};
	~CChooseDlgLogic(){};

public:
	static const String strLabelDesc;			//提示字符串控件名
protected:
	/** 确定按键消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnBtnOk( TNotifyUI& msg );

	/** 取消按键消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnBtnCancel( TNotifyUI& msg );
	/** 初始化消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnDlgIni( TNotifyUI& msg );
	DECLARE_MSG_MAP()
};

#endif