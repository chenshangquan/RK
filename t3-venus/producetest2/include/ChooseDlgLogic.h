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
	static const String strLabelDesc;			//��ʾ�ַ����ؼ���
protected:
	/** ȷ��������Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnBtnOk( TNotifyUI& msg );

	/** ȡ��������Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnBtnCancel( TNotifyUI& msg );
	/** ��ʼ����Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnDlgIni( TNotifyUI& msg );
	DECLARE_MSG_MAP()
};

#endif