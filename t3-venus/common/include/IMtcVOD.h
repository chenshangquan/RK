#ifndef  __IMTCVOD_H_
#define	 __IMTCVOD_H_

#include "DispEvent.h"
#include "mtstruct.h"
#include "vector"

using namespace std;

class IMtcVOD : public CDispEvent
{
public:
	/*����	��ȡ�ļ��б�����
	����	const CString& csDirName   �����Ŀ¼����		
	����ֵ	�ɹ�����0
	˵��	*/
	virtual u16 ReqFileList(const CString& csDirName) = 0;
	/*����	��ȡ��ǰĿ¼��������е��ļ���
	����	��			
	����ֵ	�㲥���������ļ��б�
	˵��	*/
	virtual const vector<TVODFileNameInfo>& GetFilelist() const = 0;
	/*����	����ĳһ�ļ���Ϣ
	����	const CString& csFileName   ������ļ�����			
	����ֵ	�ɹ�����0
	˵��	*/
	virtual u16 ReqFileInfo(const CString& csFileName) = 0;
	/*����	��ȡ�ļ����ļ���Ϣ
	����	��			
	����ֵ	TVODFileInfo  VOD�ļ���Ϣ
	˵��	*/
	virtual const TVODFileInfo& GetFileInfo() const = 0;
	/*����	��ȡ�ļ����Ƶ���Ϣ
	����	��			
	����ֵ	TVODFileNameInfo  VOD�ļ����ơ���С��Ϣ
	˵��	*/
    virtual const TVODFileNameInfo& GetFileNameInfo() const = 0;
	/*����	��ȡ�ļ��Ĳ���״̬
	����	��			
	����ֵ	EmAction  �ļ��Ĳ���״̬
	˵��	*/
	virtual EmAction GetPlayState() const = 0;
	/*����	��ȡ�ļ�������ʱ��
	����	��			
	����ֵ	u32 �ļ��Ĳ��ų���(��)
	˵��	*/
	virtual u32 GetDuration() = 0;
	/*����	��ȡ�ļ������Ѿ����ŵĳ���
	����	��			
	����ֵ	u32 �ļ��Ѿ����ŵĳ���
	˵��	*/
	virtual u32 GetPlayTime() = 0;
	/*����	����VOD������			
	����	u32 dwLoginIP    ��������IP��ַ(������)
			u16 wPort	     ��½�Ķ˿�
			const CString &csUserName	�û�����
			const CString& csPwd		����
	˵��	*/
	virtual u16 LoginVODServer(u32 dwLoginIP, u16 wPort, const CString &csUserName,
		const CString& csPwd) = 0;
	/*����	�˳�VOD������
	����	��			
	����ֵ	�ɹ�����0
	˵��	*/
	virtual u16 LogoutVODServer() = 0;
	//�ļ���������
	virtual u16 PlayFile(const CString& csFileName) = 0;
	//�ļ�ֹͣ��������
	virtual u16 StopPlayFile() = 0;
	//������Ϣ����
	virtual u16 ReqPlayInfo() = 0;
	//������תָʾ
	virtual u16 RandomPlay(u32 dwStartPoint) = 0;
	//������ͣ����
	virtual u16 PausePlay() = 0;
	//���Żָ�����
	virtual u16 ResumePlay() = 0;
	//�Ƿ���VOD�㲥��
	virtual BOOL IsInVod() = 0;
	

};

#endif