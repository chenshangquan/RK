#ifndef __DISPEVENT_H__
#define __DISPEVENT_H__

#include "kdvtype.h"
#include "kdvsys.h"
#include <map>
#include "nmscommon.h"
#include "nmsmtevent.h"
using namespace std;

#define TYPE_CMESSAGE  0         // һ���CMessage��Ϣ
#define TYPE_MTMSG     1         // �շ�����ϢΪCMtMsg,��Ҫ������Ϣ���͵�ת��

//////////////////////////////////////////////////////////////////////////
// ���ӿڻ��࣬��Ҫ���ڷַ���Ϣ
class CDispEvent
{
public:
    typedef void(CDispEvent::*DISPEVENT_PFUN)(const CMessage & cMsg);
public:
    CDispEvent();
    virtual ~CDispEvent();
    // �ж�һ��Ϣ�Ƿ��ڱ�����ע���
    BOOL HasRegEvent(u16 wEvent) const;
    // �ַ���Ϣ���������Ӧ����ĺ����ĵ��ã�������������ѵĵ���
    virtual void DispEvent(const CMessage &cMsg) = 0;
    // ��Ϣ��ʱ����Ӧ
    virtual void OnTimeOut(u16 wEvent) = 0;
    // �õ�֪ͨ���ھ��
    HWND GetNotifyWnd() { return m_hWnd; }
    // �趨֪ͨ���ھ��
    void SetNotifyWnd(HWND hWnd) { m_hWnd = hWnd; }
protected:
    // ��һ����Ϣ���䴦����ע�����
    void RegDispFunPointer(u16 wEvent, DISPEVENT_PFUN pFun);
    // ��յ�����ע�����Ϣ
    void ClearDisp();
    // ��ע��Ľ��洰�ڷ���ָ������Ϣ
    BOOL PostEvent(u32 dwEvent, WPARAM wParam = 0, LPARAM lParam = 0);
protected:
	// 4.0 �޸�Ϊֻ�����¼���Id
    map<u16, DISPEVENT_PFUN> m_mappFun;
    HWND        m_hWnd;         // ��Ϣ���ͽ���Ĵ��ھ��
};
//ע����Ϣӳ��
#define REG_PFUN(event, fun)        \
    RegDispFunPointer(event, (void(CDispEvent::*)(const CMessage &cMsg))fun);

//�ַ���Ϣӳ��
#define DISP_FUN(clsName, cMsg)                                 \
	if(m_mappFun.find(cMsg.event) != m_mappFun.end())			\
	{															\
	   (this->*(void(clsName::*)(const CMessage &cMsg))(m_mappFun[cMsg.event]))(cMsg);	\
	}
#endif