// UIManager.h: interface for the CUIManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UIMANAGER_H__564A6AE2_AB5E_4103_ADF1_2186C00697C3__INCLUDED_)
#define AFX_UIMANAGER_H__564A6AE2_AB5E_4103_ADF1_2186C00697C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/*
	窗口管理类，主要负责窗口的显示、隐藏、加载、销毁
*/
class CWindowManager : public IWindowManager, public tmplContainer<String,CAppWindow>
{
public:
	static const String strIndexName;	// 窗口索引文件名称
	static const String strFileTag;		// 文件路径标签
	static const String strParentTag;	// 文件路径标签
	static const String strLogicTag;	// logic标签
public:
	CWindowManager( String strFile );
	virtual ~CWindowManager();
public:
	virtual bool ShowWindow( const String& strName );
	virtual bool HideWindow( const String& strName );
	virtual bool ShowChild( const String& strName );
	virtual bool ShowModal( const String& strName ) ;
	virtual Window* GetWindow( const String& strName );
	virtual Control* GetControl( const String& strWindow, const String& strControl );
	virtual bool CloseWindow( const String& strName );
protected:
/** 为窗口添加observer 
 *  @param[in] 
 *  @node 
 *  @return 是否成功
 */
	bool AddNotifier( CAppWindow* pWnd, const String& strName );

/*
	资源所在目录
*/
	String m_strFile;
};

#endif // !defined(AFX_UIMANAGER_H__564A6AE2_AB5E_4103_ADF1_2186C00697C3__INCLUDED_)
