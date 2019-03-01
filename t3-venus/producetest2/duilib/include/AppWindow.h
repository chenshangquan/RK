#ifndef __APPWINDOW_H__
#define __APPWINDOW_H__

#pragma once

namespace DuiLib {
class CNotifyUIImpl;
class CAppWindow : public CWindowWnd, public INotifyUI
{
public:
	CAppWindow( CStdString strUI ) : m_strSkin(strUI){ };
	LPCTSTR GetWindowClassName() const;
	UINT GetClassStyle() const;
	void OnFinalMessage(HWND /*hWnd*/);

	virtual void Init();
	virtual void Prepare();
	virtual void Close();

	virtual void Notify(TNotifyUI& msg);
	void	MoveWindow( int x, int y, int nWidth, int nHeight, bool bRepaint = true );
	bool	AddNotifier( CNotifyUIImpl* pNotifier );


	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnMove(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnGetMinMaxInfo(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT OnSysCommand(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);


	CPaintManagerUI m_pm;
	CStdString		m_strSkin;
}; 

typedef void (CNotifyUIImpl::*MSG_FUNC)(void);

union MessageMapFuncs
{
	MSG_FUNC pfn;   // generic member function pointer
	bool (CNotifyUIImpl::*pfn_bn)(TNotifyUI& msg);
	bool (CNotifyUIImpl::*pfn_uwlb)( WPARAM wParam, LPARAM lParam, bool& bHandled);
};

enum EMFuncType
{
	emFunc_vv = 0,		//返回void 参数void
	emFunc_bn,			//返回bool 参数TNOTIFYUI
	emFunc_uwlb			//返回UINT 参数WAPRAM LPARAM bool
};

#define MAX_EVENT_NAME_LEN		100
#define MAX_CONTROL_NAME_LEN	255
#define MAX_FUNC_NAME_LEN		255
struct MSGMAP_ENTRY
{
	unsigned int	m_dwEvent;	// 非自定义消息，此变量为0
	char			m_chEvent[MAX_EVENT_NAME_LEN];
	char			m_chControl[MAX_CONTROL_NAME_LEN];
	char			m_chFunc[MAX_FUNC_NAME_LEN];
	unsigned int	m_wSig;
	MSG_FUNC		m_pfn;   
};

struct MSGMAP
{
	const MSGMAP* pBaseMap;
	const MSGMAP_ENTRY* lpEntries;
};

class CNotifyUIImpl : public INotifyUI, public IMessageFilterUI
{
public:
	CNotifyUIImpl() : m_pm(0) {}
	virtual void Notify(TNotifyUI& msg);
	virtual void SetPaintManagerUI( CPaintManagerUI* pPaintManagerUI ){ m_pm = pPaintManagerUI; }
public:
    virtual LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled);
protected:
	virtual const MSGMAP* GetMessageMap() const;
	void Invoke( const MSGMAP* pMsg, TNotifyUI& msg );
	void Invoke( const MSGMAP* pMsg, UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled );
private: 
	static const MSGMAP_ENTRY _messageEntries[];
protected: 
	static const MSGMAP messageMap;
	CPaintManagerUI* m_pm;
};

// 变量定义
#define DECLARE_MSG_MAP() \
private: \
	static const MSGMAP_ENTRY _messageEntries[]; \
protected: \
	static const MSGMAP messageMap; \
virtual const MSGMAP* GetMessageMap() const; \


// 消息数组初始化 同 END_MSG_MAP配套使用 
#define BEGIN_MSG_MAP(theClass, baseClass) \
	const MSGMAP* theClass::GetMessageMap() const \
{ return &theClass::messageMap; } \
	const MSGMAP theClass::messageMap = \
{ &baseClass::messageMap, &theClass::_messageEntries[0] }; \
	const MSGMAP_ENTRY theClass::_messageEntries[] = \
{ \
	

#define END_MSG_MAP() \
{ \
	0,"","", 0,  0 } \
}; \

// 点击消息
#define MSG_CLICK( name, func ) \
	{ 0, NOTIFY_CLICK, name, #func, emFunc_bn, (MSG_FUNC)(bool (CNotifyUIImpl::*)(TNotifyUI&))&func },
// keydown事件
#define MSG_KEYDOWN( name, func ) \
	{ 0, NOTIFY_KEYDOWN, name, #func, emFunc_bn, (MSG_FUNC)(bool (CNotifyUIImpl::*)(TNotifyUI&))&func },

// keydown事件
#define MSG_KEYUP( name, func ) \
	{ 0, NOTIFY_KEYUP, name, #func, emFunc_bn, (MSG_FUNC)(bool (CNotifyUIImpl::*)(TNotifyUI&))&func },

//keychar事件
#define MSG_CHAR( name, func ) \
	{ 0, NOTIFY_CHAR, name, #func, emFunc_bn, (MSG_FUNC)(bool (CNotifyUIImpl::*)(TNotifyUI&))&func },


#define MSG_SIZE( name, func ) \
	{ 0, NOTIFY_SIZE, name, #func, emFunc_bn, (MSG_FUNC)(bool (CNotifyUIImpl::*)(TNotifyUI&))&func },

//双击事件
#define MSG_DBLCLICK( name, func ) \
{ 0, NOTIFY_DBLCLICK, name, #func, emFunc_bn, (MSG_FUNC)(bool (CNotifyUIImpl::*)(TNotifyUI&))&func },

#define MSG_MINMAXINFO( name, func ) \
	{ 0, NOTIFY_MINMIAXINFO, name, #func, emFunc_bn, (MSG_FUNC)(bool (CNotifyUIImpl::*)(TNotifyUI&))&func },

#define MSG_MOVE( name, func ) \
	{ 0, NOTIFY_MOVE, name, #func, emFunc_bn, (MSG_FUNC)(bool (CNotifyUIImpl::*)(TNotifyUI&))&func },
//点击元素事件
#define MSG_ITEMCLICK( name, func )\
{ 0, NOTIFY_ITEMCLICK, name, #func, emFunc_bn, (MSG_FUNC)(bool (CNotifyUIImpl::*)(TNotifyUI&))&func},

// 初始化消息
#define MSG_INIWINDOW( name, func ) \
	{ 0, NOTIFY_INIWINDOW, name, #func, emFunc_bn, (MSG_FUNC)(bool (CNotifyUIImpl::*)(TNotifyUI&))&func },

//	选中元素消息
#define MSG_ITEMSELECTD( name, func ) \
	{ 0, NOTIFY_ITEMSELECT, name, #func, emFunc_bn, (MSG_FUNC)(bool (CNotifyUIImpl::*)(TNotifyUI&))&func },

//	文字变化消息
#define MSG_TEXTCHANGED( name, func ) \
{ 0, NOTIFY_TEXTCHANGED, name, #func, emFunc_bn, (MSG_FUNC)(bool (CNotifyUIImpl::*)(TNotifyUI&))&func },

//	失去焦点
#define MSG_KILLFOCUS( name, func ) \
{ 0, NOTIFY_KILLFOCUS, name, #func, emFunc_bn, (MSG_FUNC)(bool (CNotifyUIImpl::*)(TNotifyUI&))&func },

//	选择改变消息
#define MSG_SELECTCHANGE( name, func ) \
{ 0, NOTIFY_SELECTCHANGED, name, #func, emFunc_bn, (MSG_FUNC)(bool (CNotifyUIImpl::*)(TNotifyUI&))&func },

//	窗口销毁
#define MSG_DESTORY( name, func ) \
{ 0, NOTIFY_DESTROY, name, #func, emFunc_bn, (MSG_FUNC)(bool (CNotifyUIImpl::*)(TNotifyUI&))&func },

#define USER_MSG( name, func ) \
	{ name, _T(""), _T(""), #func, emFunc_bn, (MSG_FUNC)(bool (CNotifyUIImpl::*)(WPARAM,LPARAM,bool&))&func },
#define MSG_TIMER( name, func ) \
	{ 0, NOTIFY_TIMER, name, #func, emFunc_bn, (MSG_FUNC)(bool (CNotifyUIImpl::*)(TNotifyUI&))&func },
}

#endif // __UIACTIVEX_H__