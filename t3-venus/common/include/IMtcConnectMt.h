#ifndef __IMTCCONNECTMT_H__
#define __IMTCCONNECTMT_H__

#include "ummessagestruct.h"// �����֤ҵ��
#include "mtstruct.h"   //�ն˿���ҵ��
#include "IMtcCam.h"
#include "IMtcAudioDevice.h"
#include "IMtcConf.h"
#include "IMtcP2PConf.h"
#include "IMtcRemoteCtrl.h"
#include "IMtcCfgMt.h"
#include "IMtcMatrix.h"
#include "IMtcUser.h"
#include "IMtcMonitor.h"
#include "IMtcAddrbook.h"
#include "IMtcVOD.h"
#include "imtcfxo.h"

#include "IMtcRecoder.h"
struct TTransFileInfo
{
	BOOL m_bSuc;        //�Ƿ�ɹ�
	u16 m_wMaxPackNum;  //������
	u16 m_wCurPackNum;  //��ǰ�����
};

struct TUpgradeResult
{
	BOOL m_bSuc;        //�Ƿ�ɹ�
	u16 m_wRes;			//������
};

struct TUpgradeSrvAddr
{
	BOOL m_IsDefault;
	s8	*m_abAddr;
};
struct TUpgradeFileList
{
	u32 m_dwFileNum;
	TVerInfo *m_ptVerInfo;
};
class IMtcConnectMt : public CDispEvent
{
public:
    /*����	��ȡ��¼�û���Ϣ���û�����IP��ַ��
	����	��
	����ֵ	��¼�û���Ϣ
	˵��	��*/
	virtual CString GetUserInfo(void) const = 0;
    /*����	��ѯ�Ƿ��ʼ�����
	����	��
	����ֵ	TRUE 	��ʼ�����
			FALSE	û�г�ʼ�����
	˵��	��*/
	virtual BOOL IsInitFinish() = 0;
	/*����	��ѯ�Ƿ��������ն�
	����	��
	����ֵ	TRUE 	�������ն�
			FALSE	û�������ն�
	˵��	��*/
	virtual BOOL IsMtcConnectedMt() = 0;
	/*����	��ѯ�����ն˵���ѡIP
	����	��
	����ֵ	u32 IP��ַ��������
	˵��	��*/
	virtual u32 GetLocalIP() const = 0;
	/*����	��ѯ�ն˵�IP��ַ
	����	��
	����ֵ	u32 IP��ַ��������
	˵��	��*/
	virtual u32 GetConnectedMtIP() const = 0;
    /*����	��ѯ�Ƿ����ն�
    ����	��
    ����ֵ	TRUE 	����س�����ն�
    FALSE	������س�����ն�
    ˵��	��*/
    virtual BOOL32 IsInnerMonitorMt() = 0;
	/*����	��ѯ���ӵ��ն�
	����	��
	����ֵ	���ӵ��ն�
	˵��	��*/
	virtual const CMtcMt& GetConnectedMt() = 0;
	/*����	��ѯ��¼���û�
	����	��
	����ֵ	��¼�û�
	˵��	��*/
	virtual const CLoginRequest& GetConnectedUser() = 0;
    /*����	��ѯ��¼���û�
	����	��
	����ֵ	��¼�û�
	˵��	��*/
	virtual const TTerStatus& GetMtStatus() = 0;
	/*����	��ȡ�ض��Ŀ��ƽӿ�
	����	ppCtrl	���ƽӿ�
	����ֵ	�ɹ�����0,ʧ�ܷ��ط�0������
	˵��	�����ӵ��ն�ʱ,���Ի�ȡ��Щ�ӿ�,�ڶϿ����Ӻ�,������Щ�ӿ�����ʧЧ*/
	virtual u16 MtcGetCtrlInterface(IMtcMonitor **ppCtrl) = 0;
	virtual u16 MtcGetCtrlInterface(IMtcCam **ppCtrl) = 0;
	virtual u16 MtcGetCtrlInterface(IMtcMatrix **ppCtrl) = 0;
	virtual u16 MtcGetCtrlInterface(IMtcAudioDevice **ppCtrl) = 0;
	virtual u16 MtcGetCtrlInterface(IMtcRemoteCtrl **ppCtrl) = 0;
	virtual u16 MtcGetCtrlInterface(IMtcCfgMt **ppCtrl) = 0;
	virtual u16 MtcGetCtrlInterface(IMtcUser **ppCtrl) = 0;
	virtual u16 MtcGetCtrlInterface(IMtcAddrbook **ppCtrl) = 0;
	virtual u16 MtcGetCtrlInterface(IMtcP2PConf **ppCtrl) = 0;
	virtual u16 MtcGetCtrlInterface(IMtcConf **ppCtrl) = 0;
	virtual u16 MtcGetCtrlInterface(IMtcVOD **ppCtrl) = 0;
	virtual u16 MtcGetCtrlInterface(IMtcFxo **ppIMtcFxo)=0;
//	virtual u16 MtcGetCtrlInterface(IMtcRecoder **ppIMtcRecoder)=0;
	/*����	����TCP���˿ں�
	����	u16		TCP�˿ں�
	����ֵ	u16		������ǰ�Ķ˿ں�*/
	virtual u16 ConfigTcpPort(u16 wPort) = 0;
	/*����	���ӵ��ն�
	����	dwIP	�������ն˵�IP��ַ��������
			strUser	�û���
			strPwd	����
	����ֵ	�ɹ�����0,ʧ�ܷ��ط�0������
	˵��	������ʧ�ܣ�����MTC_UI_CMD_FAILED��Ϣ,����WPARAMK��ΪMCS_UM_LOGIN_REQ
			LPARAM��Ϊ����ԭ��,����ԭ������umconst.h�еĶ���*/
	virtual u16 MtcConnectMt(u32 dwIP, u32 dwPort,
		const CString& strUser,
		const CString& strPwd, BOOL32 bConnect = TRUE) = 0;
	/*����	�Ͽ����ն˵�����
	����	��
	����ֵ	�ɹ�����0,ʧ�ܷ��ط�0������
	˵��	��û�����ӵ��ն�ʱ���ô˷����������κ�����*/	
	virtual u16 MtcDisconnectMt() = 0;
	/*����	ע����Ϣ���մ���
	����	hWnd	������Ϣ�Ĵ���
	����ֵ	�ɹ�����0,ʧ�ܷ��ط�0������
	˵��	��ΪhWnd����NULL,�򲻷�����Ϣ*/
	virtual u16 MtcConnectMtUIRegisterRecvWnd(HWND hWnd) = 0;
	/*����	��ȡ������Ϣ�Ĵ���
	����	��
	����ֵ	������Ϣ�Ĵ���
	˵��	��*/
	virtual HWND MtcConnectMtGetUIRecvWnd() = 0;
	/*����	��ҵ��ⷢ����Ϣ
	����	wEventId	��Ϣ��ʶ��
			pbyBuf		��Ϣ���ݻ�����
            nLen        ��Ϣ�ĳ���
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	ֱ����ҵ��ⷢ����Ϣ,��ע���ֽ�������*/
	virtual u16 DirectPost(u16 wEventId, const u8* pbyBuf, s32 nLen) = 0;
	/*����	��ȡGK״̬
	����	��
	����ֵ	TRUE	��ע��GK
			FALSE	δע��GK*/
	virtual BOOL GetGKStatus() = 0;
	/*����	��ȡ�忨����
	����	��
	����ֵ	�忨����,��0xffδ֪�忨����
	˵��	�忨���Ͷ�����MtConstDef.h�ļ���*/
	virtual EmMtModel GetMtBoardType() = 0;  
	/*����	ͨ��OSP��telnet dump�ڲ���Ϣ
	����	��
	����ֵ	��
	˵��	��*/
	virtual void Dump() = 0;
	/*����	��ȡ������Ϣ
	����	��
	����ֵ	������Ϣ
	˵��	�յ�MTC_UI_SNAPSHOT_UPDATED��Ϣ���ô˷������¿�����Ϣ*/
	virtual const TSnapInfo& GetSnapShotInfo()const = 0;
	/*����	֪ͨ�ն�osdˢ�¿�����Ϣ
	����	��
	����ֵ	�Ƿ�ɹ�
	˵��	*/
	virtual u16 UpdateShotInfoList() = 0;
	/*����	����ͬ��������Ϣ
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	����ɹ���,���յ�MTC_UI_SNAPSHOT_UPDATED֪ͨ*/
	virtual u16 ReqSnapShotInfo() = 0;
	/*����	�ն˿���
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	*/
	virtual u16 SnapShot() = 0;
	/*����	�������
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	������Ϣ���º�,����淢��MTC_UI_SNAPSHOT_UPDATED֪ͨ*/
	virtual u16 ClearSnapShot() = 0;
    /*����	�����ն���Ϣ
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	����ɹ���,���յ�MTC_UI_MTSTATUS_UPDATED֪ͨ*/
	virtual u16 ReqMtStatus() = 0;
    /*����	�����ն�
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	*/
	virtual u16 ResetMt() = 0;
	/*����	�����ն�
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	*/
    virtual u16 StartDormancyMt(u16 wDelay) = 0;
	/*����	ֹͣ�����ն�
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	*/
    virtual u16 StopDormancyMt() = 0;
	/*����	���������նˣ�����ն�æµ���������������ص���ϢΪFalse
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	*/
	virtual u16 UpdateSystemReq(const CString& strName) = 0;
	/*����	�ϴ��ļ����֪ͨ���ɹ�ΪTrue�� ʧ��ΪFalse
	����	��
	����ֵ	�ɹ�����0;ʧ�ܷ��ط�0������
	˵��	*/
	virtual u16 UpLoadFileNotify( BOOL32 bResult ) = 0;
	/*�������� GetInitTestPort
    ��    �ܣ� ��ȡ���ɲ��Զ˿ں�
    ��    ���� 
    �� �� ֵ�� virtual u16 
    ˵    ���� */
	virtual u16 GetInitTestPort() = 0;
    /*�������� GetDormancyDelay
    ��    �ܣ� ��ȡ�����ȴ�ʱ��
    ��    ���� 
    �� �� ֵ�� virtual u16 
    ˵    ���� */
    virtual u16 GetDormancyDelay() =0;
    /*�������� GetEventName
    ��    �ܣ� ��ȡ��Ϣ���֣����ڵ���
    ��    ���� u16 wEvent
    �� �� ֵ�� virtual CString 
    ˵    ���� */
    virtual CString GetEventName(u16 wEvent) = 0;   
    /*�������� TransferBigFile
    ��    �ܣ� �����ļ��ӿ�
    ��    ���� u8 nType  �ļ����� ̨�ꡢ������Ϣ����Ļ�� ��MT_OSD_TITLEΪ��Ļ
               u8 *pbyBuf = NULL �ļ�ָ��LIB�����治�����ڴ棬���ϲ��������ڴ棬lib�����ͷ��ڴ�
               u32 dwBufSize  �ļ���С
               u32 dwTimeOut  ����������Ϣ�ȴ�ʱ��
    �� �� ֵ�� void 
    ˵    ���� */
    virtual u16 TransferBigFile(u8 nType, u8 *pbyBuf = NULL,
                                u32 dwBufSize = 0, u32 dwTimeOut = 10000) = 0;   
    /*�������� IsTransfering
    ��    �ܣ� �ж��Ƿ����ڴ����ļ�
    ��    ���� 
    �� �� ֵ�� BOOL32 
    ˵    ���� ͬһ��ʱ��ֻ����һ���ļ��ڴ���*/
    virtual BOOL32 IsTransferingFile() = 0;

    /*�������� IsUsedMC
    ��    �ܣ� �Ƿ�����MC
    ��    ���� 
    �� �� ֵ�� virtual BOOL32&
    ˵    ���� */
    virtual BOOL32& IsUsedMC() = 0;

    /*�������� GetMCMode
    ��    �ܣ� MC����ģʽ
    ��    ���� 
    �� �� ֵ�� virtual EmMCMode&
    ˵    ���� */
    virtual EmMCMode& GetMCMode() = 0;
	/*�������� ReqMTSysTime
    ��    �ܣ������ѯ�ն�ϵͳʱ��
    ��    ���� 
    �� �� ֵ�� virtual u16
    ˵    ���� */
	virtual u16   ReqMTSysTime()=0;    

	virtual u16 UploadLicenseFile(const CString& strFilePath) = 0;
	/*�������� SendSrvAddrCfg
    ��    �ܣ� ���������������ĵ�ַ��Ϣ
    ��    ���� 
    �� �� ֵ�� virtual u16
    ˵    ���� */
	virtual u16 SendSrvAddrCfg(BOOL bflag, s8 *pAddr, int length) = 0; 
	/*�������� ConnectUpgradeSrv
    ��    �ܣ� ��������������
    ��    ���� 
    �� �� ֵ�� virtual u16
    ˵    ���� */
	virtual u16 ConnectUpgradeSrv() = 0;
	/*�������� CancelUpgrade
    ��    �ܣ� ȡ������
    ��    ���� 
    �� �� ֵ�� virtual u16
    ˵    ���� */
	virtual u16 CancelUpgrade() = 0; 
	/*�������� StartupUpgrade
    ��    �ܣ� ��ʼ����
    ��    ���� �����ļ����
    �� �� ֵ�� virtual u16
    ˵    ���� */
	virtual u16 StartupUpgrade(u8 byFileNum) = 0;	  //��ʼ����

	/*�������� ResumeUpgrade
    ��    �ܣ� �ϵ��ش�
    ��    ���� 
    �� �� ֵ�� virtual u16
    ˵    ���� */
    virtual u16 ResumeUpgrade() = 0;  
	
	virtual u16 DisconnectUpgradeSrv() = 0; //�Ͽ�����������
	virtual TVerInfo &GetVerInfo() = 0; //��ȡ�����ļ�
	virtual TUpgradeFileList &GetVerList() = 0; //�ļ������б�
	virtual TTransFileInfo &GetFileTransferInfo() = 0; //��ǰ�����ļ�Ƭ��Ϣ
	virtual BOOL GetConnectResult() = 0;



	//Log ��־
	virtual u16 UpdateWriteLog(BOOL32 bWriteLog) = 0;
	virtual BOOL32 GetIsLog() = 0;
	
	//ExportLog ������־
	virtual u16 UpdateExportLog( u8 Param = 0) = 0;
	virtual u32 GetExportLog() = 0;
	//����log����������
	virtual u16 ReqDownloadLogToLocal(EmMtFile filetype) = 0;
	//��ɵ���������
	virtual u16 FinishDownloadLog() = 0;
}; // IMtcConnect

#endif