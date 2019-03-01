#ifndef __IMTCP2PCONF_H__
#define __IMTCP2PCONF_H__

#include "dispevent.h"
#include "mtcmt.h"
//#include "mtctrllib.h"

class IMtcP2PConf : public CDispEvent
{
public:
	/*����	�Ƿ����ڵ�Ե������
	����	pMt	���ز��������ڵ�Ե�����У�����*pMt�����������һ���ն�
	����ֵ	TRUE	���ڵ�Ե������
			FALSE	���ڵ�Ե������
	˵��	��*/
	virtual BOOL IsInP2PConf(CMtcMt *pMt) const = 0;
	/*����	�Ƿ����ں��������ն�
	����	pMt	���ز����������ں��������նˣ�����*pMt����䱻���е��ն�
	����ֵ	TRUE	���ں��������ն�
			FALSE	û�ں��������ն�
	˵��	��*/
	virtual BOOL IsCalling(CMtcMt *pMt) const = 0;
	/*����	���������ն�
	����	const TMtAddr& tMtAddr		�ն˵ĵ�ַ
			u16 wCallRate				���е�����
	����ֵ	�ɹ�����0
	˵��	��*/
	virtual u16 MakeCall(const TMtAddr& tMtAddr, u16 wCallRate = 768) = 0;
	/*����	�ӵ�ַ�����������ն�,�����ն���Ӻ�����¼
	����	const TMtAddr& tMtAddr		   [in]     �ն˵ĵ�ַ
			u16 wCallRate				   [in]     ���е�����
			const CString& strEntryName    [in]     �ӵ�ַ������ʱ����Ŀ����

	����ֵ	�ɹ�����0
	˵��	��*/
	virtual u16 MakeCall(const TMtAddr& tMtAddr,const CString& strEntryName,u16 wCallRate = 768) = 0;

	/*����	�ش����
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ش�����
	˵��	*/
	virtual u16 Accept(BOOL32 bAccept) = 0;
	/*����	ȡ������
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	������ڻ�����,���к��н���,ʹ��Reject�ܾ��º���*/
	virtual u16 CancelCalling() = 0;
	/*����	������Ե����
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	������չΪ�����飬�����ô˷�����������*/
	virtual u16 EndP2PConf() = 0;
	/*����	�Ƿ����ն�
	����	��
	����ֵ	TRUE	���ն�
			FALSE	���ն�
	˵��	���ն˿�����չ��Ե���鵽������*/
	virtual BOOL IsMasterMt() const = 0;
	/*����	�����º��ж�ʹ������չ
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	ӵ�л�����չ�����Żᷢ������*/
	virtual u16 AcceptEx() = 0;
    /*����	���Ͷ���Ϣ
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	*/
	virtual u16 SendShortMessage(const CString &strMsg, EmSMSType emType = emSMSSingleLine,
		 u8 byRollSpeed = 3, u8 byTimes=1) = 0;
    /*����	��Ե�����л�ȡ�Զ��ն�����
	����ֵ	EmMtModel
	˵��	*/
	virtual EmMtModel& GetOtherMtModelInP2P() = 0;	
	/*����	��Ե�����н����кŷ��͸��Զ��ն�
	����ֵ	void
	˵��	*/
//	virtual void SendSerialNumber(const CString &strSerialNumber) = 0;

	/*����	��Ե�����з��͸��Զ����ݻ�������
	����ֵ	void
	˵��	*/
	virtual u16  SendPcmtDataConfReq() = 0;

	/*����	��Ե�����з��͸��Զ����ݻ����Ӧ
	����ֵ	void
	˵��	*/
	virtual u16  SendPcmtDataConfRsp(BOOL bAccept) = 0;
}; // IMtcP2PConf

#endif