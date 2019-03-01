// UserDataManager.h: interface for the CUserDataManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USERDATAMANAGER_H__060C90AE_0FA4_4467_B18C_41E30FAD3A9D__INCLUDED_)
#define AFX_USERDATAMANAGER_H__060C90AE_0FA4_4467_B18C_41E30FAD3A9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "msgdef.h"
class CUserDataMngr;
typedef bool (CUserDataMngr::*Func)( TMsgParam& tMsgParam );
class CUserDataMngr : public IUserDataMngr, public tmplContainer<u32,Func>
{
public:
	CUserDataMngr();
	virtual ~CUserDataMngr();
	virtual		bool	 	Update( TMsgParam& tParam);	
	virtual 	void		SetSartIp( const u32 dwIp );
	virtual     u32			GetStartIp() const;
	virtual 	void		SetStartMac( const s8 *pchMac );
	virtual 	s8*			GetStartMac();
	virtual 	void		SetRestore( const bool bRes );
	virtual 	bool		GetRestore() const ;
	virtual 	void		SetTftpPath( const String strPath );
	virtual		String		GetTftpPath() const ;
	virtual		void		SetUIMode( const EmUIMode emMode);
	virtual		EmUIMode	GetUIMode() const ;
	virtual		void		SetUIState( const EmUIState emState );
	virtual		EmUIState	GetUIState() const ;
	virtual		IDevice*	GetDevice() const ;
	virtual		ITestCase*	GetSelectedCase() const ;
	virtual		bool		SetDevice( const String strDvcName );
	virtual		bool		SetDevice( IDevice *pDevice );
	virtual		bool        SetSelectedCase( const String strCaseName );
	virtual		bool		SetDispState( const String strState );
	virtual		String		GetDispState() const;
	virtual		String		GetNotifyDlgStr() const;
	virtual		bool		SetNotifyDlgStr( const String &strNotify );
	virtual		bool		GetChooseDlgResult() const;
	virtual		bool		SetChooseDlgResult( const bool bOk );
	virtual		bool		AppendComDisp( LPCSTR pchContent );
	virtual		bool		ClearComDisp();
	virtual		LPCSTR		GetComDispStr();

	
protected:
	bool OnConnectedDevice( TMsgParam& TMsgParam );
	bool OnDeviceLoadReq( TMsgParam& TMsgParam );				//�豸����������Ϣ����
	bool OnDeviceLoadStateChange( TMsgParam& TMsgParam );		//�豸����״̬�仯��Ϣ����
protected:
	void RegFunc();

protected:
	IDevice		*m_pDevice;						//�����豸  
	ITestCase	*m_pSelectedCase;				//ѡ�в�����
	bool		m_bRestore;						//�Ƿ�ָ���������
	EmUIMode	m_emUIMode;						//UIģʽ
	EmUIState	m_emUIState;					//UI״̬
	String		m_strTftpPath;					//Tftp·��
	String		m_strDispState;					//������ʾ��״̬�ַ���
	String		m_strNotify;					//��ʾ�Ի����ַ���
	u32			m_dwStartIp;					//��ʼIP
	s8			m_achStartMac[MAX_MAC_LENGTH];	//��ʼMac��ַ
	String      m_strComDisp;					//�����ն���ʾ�ַ���
	bool		m_bChooseDlgResult;				//ѡ��Ի�����
};
// 
#define REG_USERDATAMANAGER_FUNC( id, func ) \
	Add( id, (Func)(bool (CUserDataMngr::*Func)( TMsgParam& tMsgParam ))&func );



#endif // !defined(AFX_USERDATAMANAGER_H__060C90AE_0FA4_4467_B18C_41E30FAD3A9D__INCLUDED_)
