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
	static const String strLabelNotify;			//��ʾ�ַ����ؼ���
	static const String strBtnNotifyOk;			//ȷ������

protected:
	/** ȷ��������Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnNotifyOk( TNotifyUI& msg );
	/** ��ʼ����Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnDlgIni( TNotifyUI& msg );


private:
	CPaintManagerUI *m_pPaintMngr;
	DECLARE_MSG_MAP()
};

#endif