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
		�ļ�·���༭��		
	*/
	static const String strEditFilePath;	
	/*
		ȡ������
	*/
	static const String strBtnCancel;	

protected:
	/** ȷ��������Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnOk( TNotifyUI& msg );
	
	/** ȡ��������Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnCancel( TNotifyUI& msg );

	/** ȡ��������Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool OnBrowseDir( TNotifyUI& msg );
	/** ·���ı�  
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	bool OnPathChange( TNotifyUI& msg );
	/** ��ʼ����Ϣ
	*  @param[in] ��Ϣ
	*  @node 
	*  @return �Ƿ�ɹ�
	*/
	bool Ini( TNotifyUI& msg );

	DECLARE_MSG_MAP()
};

#endif