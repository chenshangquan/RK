#ifndef _OSPINSTANCE_H_
#define _OSPINSTANCE_H_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class COspInstance : public CInstance
{
public:
	COspInstance();
	~COspInstance();
protected:
    virtual void InstanceEntry( CMessage *const pMsg);

};

#endif