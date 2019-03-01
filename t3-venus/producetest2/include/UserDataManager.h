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
	bool OnDeviceLoadReq( TMsgParam& TMsgParam );				//设备加载请求消息处理
	bool OnDeviceLoadStateChange( TMsgParam& TMsgParam );		//设备加载状态变化消息处理
protected:
	void RegFunc();

protected:
	IDevice		*m_pDevice;						//被测设备  
	ITestCase	*m_pSelectedCase;				//选中测试项
	bool		m_bRestore;						//是否恢复出厂设置
	EmUIMode	m_emUIMode;						//UI模式
	EmUIState	m_emUIState;					//UI状态
	String		m_strTftpPath;					//Tftp路径
	String		m_strDispState;					//界面显示的状态字符串
	String		m_strNotify;					//提示对话框字符串
	u32			m_dwStartIp;					//起始IP
	s8			m_achStartMac[MAX_MAC_LENGTH];	//起始Mac地址
	String      m_strComDisp;					//超级终端显示字符串
	bool		m_bChooseDlgResult;				//选择对话框结果
};
// 
#define REG_USERDATAMANAGER_FUNC( id, func ) \
	Add( id, (Func)(bool (CUserDataMngr::*Func)( TMsgParam& tMsgParam ))&func );



#endif // !defined(AFX_USERDATAMANAGER_H__060C90AE_0FA4_4467_B18C_41E30FAD3A9D__INCLUDED_)
