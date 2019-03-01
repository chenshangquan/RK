#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CMsgQueFactory : public IMsgQueFactory, public tmplContainer< String, IMsgQueMngr >
{
public:
	const static String strTypeTag;			//类型标签
	const static String strMsgBodyTag;      //消息体标签		
	const static String strMsgIdTag;        //消息Id标签
	const static String strDescTag;         //描述标签
	const static String strTypeValIn;       //输入消息
	const static String strTypeValOut;		//输出消息
	const static String strValueTag;        //消息体 值标签
	const static String strItemTypeU8;        //u8
	const static String strItemTypeU16;       //u16
	const static String strItemTypeU32;       //u32
	const static String strItemTypeEmpty;	  //空


public:	
	CMsgQueFactory();
	~CMsgQueFactory();
	virtual IMsgQueMngr* CreateMsgQue( String strFileName, String strNodePath );
	TCnProduceTestMsg GetSurProduceTestMsg();
	static CMsgQueFactory* GetMsgQuePtr();
private:
	void HostToNetMsg( TCnProduceTestMsg &tTestMsg );
private:
	TCnProduceTestMsg m_tProducetestMsg;

protected:
	static CMsgQueFactory* m_pThis;
};
#define MsgQuePtr CMsgQueFactory::GetMsgQuePtr()