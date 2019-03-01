// cncaddrbookif.h: interface for the CCncAddrbookIF class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CNCADDRBOOKIF_H__F143B4A9_10C5_4BE6_9966_DB271533149A__INCLUDED_)
#define AFX_CNCADDRBOOKIF_H__F143B4A9_10C5_4BE6_9966_DB271533149A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "kdvdispevent.h"
#include "addrbook.h"
#include <vector>

class CCncAddrbookIF : public CKdvDispEvent  
{
public:

	/** ��ȡ��ַ������ 
	 *  @return ��ַ������
	 *  @remarks 
	 */
	virtual CAddrBook& GetAddrBook() = 0;

	/** ����  ��ɾ����Ŀ�����飩 
	 *  @param[in] entry ��Ŀ
	 *  @param[in] group ��
	 *  @param[in] dwIndex	��Ŀ�����飩������
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks ModifyGroup�������޸����а�������Ŀ�б�,Ҫ�޸���Ŀ�б�ʹ��AddEntryToGroup��DelEntryFromGroup
	 */
 	virtual u16 AddEntry( const CAddrEntry& entry ) = 0;

 	virtual u16 ModifyEntry( const CAddrEntry& entry ) = 0;

 	virtual u16 DeleteEntry( u32 dwIndex ) = 0;

	virtual u16 AddGroup( const CAddrMultiSetEntry& group ) = 0;

	virtual u16 ModifyGroup( const CAddrMultiSetEntry& group ) = 0;

	virtual u16 DeleteGroup( u32 dwIndex ) = 0;

    virtual u16 DeleteMultiEntry( vector<u32> vctEntry ) = 0;

    virtual u16 DeleteMultiGroup( vector<u32> vctGroup ) = 0;

	/** ����  �޸���Ŀ���е���Ŀ 
	 *  @param[in] tGroupEntry ���а�����Ŀ���б�
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 */
	virtual u16 AddEntryToGroup(const TADDRMULTISETENTRY& tGroupEntry) = 0;
	virtual u16 DelEntryFromGroup(const TADDRMULTISETENTRY& tGroupEntry) = 0;

	/** ����  ����/ɾ����Ŀ���ϵ 
	 *  @param[in] dwGroupIndex ������
	 *  @param[in] dwGroupIndex �ϼ�������
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 */
	virtual u16 AddGroupToGroup( u32 dwGroupIndex, u32 dwUpGroupIndex ) = 0;
	virtual u16 DelGroupFromGroup( u32 dwGroupIndex, u32 dwUpGroupIndex ) = 0;

	/*�������� AddCallOutEntryCmd
    ��    �ܣ����Ӻ�����¼   
    ��    ���� 
    �� �� ֵ�� virtual u16
    ˵    ���� ����Ϣ���͸��ն˴��������͵���ַ��*/
	//virtual u16  AddCallOutEntryCmd(const TAddrEntry& tAddrEntry)=0;  

	virtual BOOL GetAddrLoadingState() = 0;
	virtual void SetAddrLoadingState(BOOL bAddrLoading) = 0;

};

#endif // !defined(AFX_CNCADDRBOOKIF_H__F143B4A9_10C5_4BE6_9966_DB271533149A__INCLUDED_)
