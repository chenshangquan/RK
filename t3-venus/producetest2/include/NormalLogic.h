#ifndef _NORMAL_LOGIC_
#define _NORMAL_LOGIC_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CNormalLogic : public CNotifyUIImpl
{
public:
	CNormalLogic(){};
	~CNormalLogic(){};

protected:
	/** ���ذ�����Ϣ 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnBtnLoad( TNotifyUI& msg );
	/** ���԰�����Ϣ 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnBtnTest( TNotifyUI& msg );
	DECLARE_MSG_MAP()
};
#endif