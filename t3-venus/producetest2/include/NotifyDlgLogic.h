#ifndef _NOTIFYDLGLOGIC_H_
#define _NOTIFYDLGLOGIC_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CNotifyDlgLogic : public CNotifyUIImpl
{
public:
	CNotifyDlgLogic();
	~CNotifyDlgLogic();

public:
	static const String strLabelNotify;			//提示字符串控件名
	static const String strBtnNotifyOk;			//确定按键

protected:
	/** 确定按键消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnNotifyOk( TNotifyUI& msg );
	/** 初始化消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnDlgIni( TNotifyUI& msg );


private:
	CPaintManagerUI *m_pPaintMngr;
	DECLARE_MSG_MAP()
};

#endif