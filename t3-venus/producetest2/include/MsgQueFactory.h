#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CMsgQueFactory : public IMsgQueFactory, public tmplContainer< String, IMsgQueMngr >
{
public:
	const static String strTypeTag;			//���ͱ�ǩ
	const static String strMsgBodyTag;      //��Ϣ���ǩ		
	const static String strMsgIdTag;        //��ϢId��ǩ
	const static String strDescTag;         //������ǩ
	const static String strTypeValIn;       //������Ϣ
	const static String strTypeValOut;		//�����Ϣ
	const static String strValueTag;        //��Ϣ�� ֵ��ǩ
	const static String strItemTypeU8;        //u8
	const static String strItemTypeU16;       //u16
	const static String strItemTypeU32;       //u32
	const static String strItemTypeEmpty;	  //��


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