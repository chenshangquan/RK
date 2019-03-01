#ifndef _OSPAPPMANAGER_H_
#define _OSPAPPMANAGER_H_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "OspInstance.h"
typedef zTemplate< COspInstance, 1 > OspApp;

class COspAppManager : public IOspAppManager, public tmplContainer< u16, OspApp >
{
public:
	COspAppManager();
	~COspAppManager();
	virtual bool CreateApp( u16 wAppId, const s8 *pchAppName );
	virtual bool KillApp( u16 wAppId );
private:
	/**  启动osp
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool StartOsp();
};
#endif