#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "TestCase.h"
#include "TestCaseContainer.h"
class CBoard : public IBoard
{
public:
	CBoard();
	~CBoard();
	virtual bool SetActivated( const bool bActivated );
	virtual bool GetActivated()  const;
	virtual	bool SetAppId( const u32 dwAppId );
	virtual u32	GetAppId() const;
	virtual	bool SetE2promFlag( const u32 dwFlag );
	virtual u32 GetE2promFlag()  const;
	virtual	bool SetE2promInfo( const u32 dwInfo );
	virtual u32 GetE2promInfo()  const;
	virtual bool SetEndMsgQue( IMsgQueMngr *MsgQue );
	virtual IMsgQueMngr* GetEndMsgQue();
	virtual	s8* GetHardVersion();
	virtual bool SetHardVersion( const s8* pchHardVer );
	virtual u16	GetHid() const;
	virtual bool SetHid( const u16 &dwHid );
	virtual u16 GetPid()  const;
	virtual bool SetPid( const u16 &wPid );
	virtual s8* GetPipeLine();
	virtual bool SetPipeLine( const s8* achPipeLine );
	virtual IMsgQueMngr* GetPreMsgQue() const;
	virtual bool SetPreMsgQue( IMsgQueMngr *MsgQue );
	virtual bool SetRegMsg( TBrdRegMsg RegMsg );
	virtual bool SetSerialNo(const s8 *pchSn);
	virtual s8* GetSerialNo();
	virtual bool SetMac( const s8 *pchMac );
	virtual s8* GetMac();
	virtual bool SetEthernetCount( const u32 &dwCount );
	virtual u32 GetEthernetCount() const;
	virtual bool SetIpAddr(const u32 &dwIp );
	virtual u32 GetIpAddr() const;
	virtual	s8* GetSoftVersion()  ;
	virtual bool SetSoftVersion( const s8 *pchSoftVer );
	virtual bool SetSubMsk( const u32 dwSubMsk );
	virtual u32 GetSubMsk() const;
	virtual LPCSTR GetDate();
	virtual bool SetDate( LPCSTR pchDate );	
	virtual String GetSysFile() const;
	virtual bool SetSysFile( const String &strFileName );
	virtual IBoard* Clone();
	virtual bool SetMode( const u8 byMode) ;
	virtual u8 GetMode() const;
	virtual bool SetBrdPic(const String &strBrdPic );
	virtual String GetBrdPic() const;
	virtual void Print();
	virtual ITestCaseContainer* GetCaseContainer();
	virtual bool SetBrdName( const String strBrdName );
	virtual String GetBrdName() const;
	virtual bool SetProcedure( const EmBrdProceduer emProcedure );  
	virtual IMsgQueMngr* GetResMsgQue();
	virtual bool SetResMsgQue( IMsgQueMngr *MsgQue );
	virtual void Restore();
	virtual bool SetBrdDesc( const String &strDesc );
	virtual String GetBrdDesc();
	virtual void ProcMsg( const TObMsg &msg ) ;
	virtual void ClearMsgQue();
	
// 	virtual void setType(EmCnModel emMtType);
// 	virtual u32  getType() const;


private: 
	/**  ע��忨
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	void RegBrd( const TObMsg &ObMsg );
	
	/**  �����ȣ��ý���֮����ã��������Ӧ��Ϣ����ƥ�䣬�Զ�����Ϊ���µĽ���
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	 void CheckProcedure();

	 /**  ���ز������ݣ��������������Ϣ���У�
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	 bool LoadTestContent();

	 /**  ����ע����Ϣ����ʼ���忨����
	 *  @param[in] ע����Ϣ
	 *  @node 
	 *  @return ģʽ�Ƿ�ı�
	 */
	 bool InitTestInfo( const TObMsg &ObMsg );




private:
	s8			m_achDate[MAX_DATE_LEN];					//��������	YYYY/MM/DD HH:MM:SS	
	s8			m_achMac[MAX_MAC_LENGTH];					//MAC��ַ xx:xx:xx:xx:xx:xx
	bool		m_bActivated;								//����״̬
	u32			m_dwAppId;									//APP ID
	u32			m_byMode;									//�忨ģʽ
	u32			m_dwIpAddr;									//IP��ַ  ������
	u32			m_dwSubMsk;									//��������
	u32			m_dwE2promFlag;								//E2prom��־
	u32			m_dwE2promInfo;								//E2prom��Ϣ
	IMsgQueMngr *m_pResMsgQue;								//�ָ�����������Ϣ����
	IMsgQueMngr *m_pEndMsgQue;								//������Ϣ����
	IMsgQueMngr *m_pPreMsgQue;								//׼����Ϣ����
	s8			m_achHardVersion[MAX_VERSION_LENGTH];		//Ӳ���汾 
	s8			m_achSoftVersion[MAX_VERSION_LENGTH];		//����汾
	u16			m_wHid;									    //Ӳ��ID
	u16			m_wPid;									    //��ƷID 
	u32			m_dwEthernetCount;							//��������
	s8			m_achPipeLine[PIPELINE_SN_LEN];				//������
	EmBrdProceduer m_emProcedure;							//�忨����
	TBrdRegMsg	m_RegMsg;									//ע����Ϣ
	s8			m_achSerialNo[MAX_SERIAL_LENGTH];			//���к�
	String		m_strSysFile;								//�����ļ�
	String		m_strBrdPic;								//�忨ͼƬ�ļ�
	String		m_strBrdName;								//�忨��
	String		m_strBrdDesc;								//�忨����
	CTestCaseContainer m_CaseContainer;						//����������
};