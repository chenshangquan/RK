#ifndef _ABNORMALLOGIC_H_
#define _ABNORMALLOGIC_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAbnormalLogic : public CNotifyUIImpl
{
public:
	CAbnormalLogic();
	~CAbnormalLogic();
protected:
	/** 继续按键消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnContinue( TNotifyUI& msg );
	/** 初始化消息 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnInit( TNotifyUI& msg );
	/** 重新测试按键消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnRetest( TNotifyUI& msg );

	/** 终止测试按键消息
	*  @param[in] 消息
	*  @node 
	*  @return 是否成功
	*/
	bool OnStop( TNotifyUI& msg );
	DECLARE_MSG_MAP()
};

#endif