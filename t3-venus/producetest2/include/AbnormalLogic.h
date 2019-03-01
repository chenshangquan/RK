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
	/** ����������Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnContinue( TNotifyUI& msg );
	/** ��ʼ����Ϣ 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnInit( TNotifyUI& msg );
	/** ���²��԰�����Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnRetest( TNotifyUI& msg );

	/** ��ֹ���԰�����Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnStop( TNotifyUI& msg );
	DECLARE_MSG_MAP()
};

#endif