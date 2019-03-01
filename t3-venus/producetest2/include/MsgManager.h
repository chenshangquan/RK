// MsgManager.h: interface for the CMsgManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MSGMANAGER_H__E8EC0DCD_D913_4433_81A2_296403F52F07__INCLUDED_)
#define AFX_MSGMANAGER_H__E8EC0DCD_D913_4433_81A2_296403F52F07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMsgManager : public IMsgManager
{
public:
	CMsgManager(){}
	virtual ~CMsgManager(){}
	virtual void SendMsg( TMsgParam& tMsgParam );
	virtual void AddObserver( IObserver* pOb );
	virtual void RemoveObserver( IObserver* pOb );
protected:
/** 找到观察者 
 *  @param[in] 
 *  @node 
 *  @return 迭代器
 */
	vector<IObserver*>::iterator FindObserver( IObserver* pObserver );

/*
	ob队列
*/
	typedef vector<IObserver*> ObserverList;
	ObserverList m_observers;
};

#endif // !defined(AFX_MSGMANAGER_H__E8EC0DCD_D913_4433_81A2_296403F52F07__INCLUDED_)
