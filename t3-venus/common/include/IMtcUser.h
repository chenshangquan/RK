#ifndef __IMTCUSER_H__
#define __IMTCUSER_H__

#include "dispevent.h"

class IMtcUser : public CDispEvent
{
public:
	/*����	�޸��û�
	����	user	�û�
			bAdmin	�Ƿ����û����й���ԱȨ��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	�����޸ĵ�ǰ��¼���û�*/
	virtual u16 Modify(const CUserFullInfo& user) = 0;
	/*����	�����û�
	����	user	�û�
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��Ҫ����ԱȨ��*/
	virtual u16 Add(const CUserFullInfo& user) = 0; 
	/*����	ɾ���û�
	����	user	�û�
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	��Ҫ����ԱȨ��*/
	virtual u16 Delete(const CUserFullInfo& user) = 0;
	/*����	����ȫ���û��б�
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	MTC_UI_USERS_UPDATED��Ϣ�����GetUsers��ȡ�û��б�*/
	virtual u16 ReqUsers() = 0;
	/*����	��ȡ�û��б�
	����	��
	����ֵ	�û��б�
	˵��	�μ�ReqUsers*/
	virtual const vector<CUserFullInfo>& GetUsers()const = 0;
}; // IMtcUser

#endif
