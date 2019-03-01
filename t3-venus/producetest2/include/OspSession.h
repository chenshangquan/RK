#ifndef _OSPSESSION_H_
#define _OSPSESSION_H_
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class COspSession : public IOspSession
{
public:
	COspSession();
	virtual ~COspSession();
	virtual void ProcMsg( const TObMsg &msg );
	virtual bool SendMsg( u16 wEvent, u8 *pContent = 0, u16 wLen = 0);
	/** 设置地址信息 （在办卡注册时设置）
	 *  @param[in] 源地址，目的地址
	 *  @node 
	 *  @return 
	 */
	virtual bool SetAddrInfo( const u32 &dwLocalId, const u32 &dwDstId );


protected:	
	/**  断链消息处理
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void Ondisconnect();

private:
	u32 m_dwDstId;
	u32 m_dwDstNode;
	u32 m_dwLocalId;
};
#endif




















