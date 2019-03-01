#ifndef __IMTCADDRBOOK_H__
#define __IMTCADDRBOOK_H__

#include "dispevent.h"
#include "Addrbook.h"		// ��ַ��ҵ��

class IMtcAddrbook : public CDispEvent
{
public:
	/*����	���ص�ַ������
	����	��
	����ֵ	��ַ������
	˵��	�μ���Խ���addrbook.h*/
	virtual CAddrBook& GetAddrBook() = 0;
	/*����	��ɾ����Ŀ�����飩
	����	entry	��Ŀ
			group	��
			dwIndex	��Ŀ�����飩������
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	ModifyGroup�������޸����а�������Ŀ�б�,Ҫ�޸���Ŀ�б�ʹ��
			AddEntryToGroup��DelEntryFromGroup*/
	virtual u16 AddEntry(const CAddrEntry& entry) = 0;
	virtual u16 ModifyEntry(const CAddrEntry& entry) = 0;
	virtual u16 DeleteEntry(u32 dwIndex) = 0;
	virtual u16 AddGroup(const CAddrMultiSetEntry& group) = 0;
	virtual u16 ModifyGroup(const CAddrMultiSetEntry& group) = 0;
	virtual u16 DeleteGroup(u32 dwIndex) = 0;
	/*����	�޸���Ŀ���е���Ŀ
	����	tGroupEntry	���а�����Ŀ���б�
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
	virtual u16 AddEntryToGroup(const TADDRMULTISETENTRY& tGroupEntry) = 0;
	virtual u16 DelEntryFromGroup(const TADDRMULTISETENTRY& tGroupEntry) = 0;

	/*����	��ַ���ϴ�����
	����	const CString strFilePath   [in]     �ϴ��ļ�����·��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��*/
	virtual u16 UploadAddrbook(const CString &strFilePath) = 0;
	/*�������� AddCallOutEntryCmd
    ��    �ܣ����Ӻ�����¼   
    ��    ���� 
    �� �� ֵ�� virtual u16
    ˵    ���� ����Ϣ���͸��ն˴��������͵���ַ��*/
	virtual u16   AddCallOutEntryCmd(const TAddrEntry& tAddrEntry)=0;    

}; // IMtcAddrbook

#endif