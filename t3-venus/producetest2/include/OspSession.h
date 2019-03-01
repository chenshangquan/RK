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
	/** ���õ�ַ��Ϣ ���ڰ쿨ע��ʱ���ã�
	 *  @param[in] Դ��ַ��Ŀ�ĵ�ַ
	 *  @node 
	 *  @return 
	 */
	virtual bool SetAddrInfo( const u32 &dwLocalId, const u32 &dwDstId );


protected:	
	/**  ������Ϣ����
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




















