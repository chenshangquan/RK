// UIManager.h: interface for the CUIManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UIMANAGER_H__564A6AE2_AB5E_4103_ADF1_2186C00697C3__INCLUDED_)
#define AFX_UIMANAGER_H__564A6AE2_AB5E_4103_ADF1_2186C00697C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/*
	���ڹ����࣬��Ҫ���𴰿ڵ���ʾ�����ء����ء�����
*/
class CWindowManager : public IWindowManager, public tmplContainer<String,CAppWindow>
{
public:
	static const String strIndexName;	// ���������ļ�����
	static const String strFileTag;		// �ļ�·����ǩ
	static const String strParentTag;	// �ļ�·����ǩ
	static const String strLogicTag;	// logic��ǩ
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
/** Ϊ�������observer 
 *  @param[in] 
 *  @node 
 *  @return �Ƿ�ɹ�
 */
	bool AddNotifier( CAppWindow* pWnd, const String& strName );

/*
	��Դ����Ŀ¼
*/
	String m_strFile;
};

#endif // !defined(AFX_UIMANAGER_H__564A6AE2_AB5E_4103_ADF1_2186C00697C3__INCLUDED_)
