#include "testcase.h"
class CTestCaseFactory : public ITestCaseFactory, public tmplContainer< String, ITestCase >
{
public:
	static const String strCfgFile;				//�����ļ���
	static const String strCasePath;			//������·��
	static const String strCasePathEX;			//������·��	
	static const s8     chSeparater;			//�ָ���
	static const String strTypeTag;			    //���ͱ�ǩ
	static const String strTypeMedia;			//media	
	static const String strTypeCmd;		     	//Cmd	
	static const String strTypeExe;			    //Exe
	static const String strNameTag;			    //Name��ǩ
	static const String strRetestTag;			//�ز��ǩ
	static const String strDescTag;			    //Description��ǩ
	static const String strEncParamTag;			//������������ǩ
	static const String strStrInTag;			//��������������ǩ
	static const String strStrOutTag;			//�������������ǩ
	static const String strPreMsgTag;			//׼����Ϣ��ǩ
	static const String strEndMsgTag;			//������Ϣ��ǩ
	static const String strPathTag;				//ý���ļ�·��
	static const String strInVidCountTag;		//������Ƶ����ǩ
	static const String strInAudCountTag;		//������Ƶ����ǩ
	static const String strInVidRtpTag;			//������ƵRTP��ǩ
	static const String strInAudRtpTag;			//������ƵRTP��ǩ
	static const String strKeyFrameMsgTag;		//����ؼ�֡��Ϣ��ǩ
	static const String strOutVidCountTag;		//�����Ƶ����ǩ
	static const String strOutAudCountTag;		//�����Ƶ����ǩ
 	static const String strOutFileTag;		    //��������ļ���ǩ
	static const String	strOutVidLocalRtpTag;	//�����Ƶ����RTP�˿ڱ�ǩ
	static const String strOutVidLocalIntTag;	//�����Ƶ���ض˿ڼ����ǩ
	static const String strOutVidRemoteRtpTag;	//�����ƵԶ��RTP�˿ڱ�ǩ
	static const String strOutVidRemoteIntTag;	//�����ƵԶ�˶˿ڼ����ǩ
	static const String strOutAudLocalRtpTag;	//�����Ƶ����RTP�˿ڱ�ǩ
	static const String strOutAudLocalIntTag;	//�����Ƶ���ض˿ڼ����ǩ
	static const String strOutAudRemoteRtpTag;	//�����ƵԶ��RTP�˿ڱ�ǩ
	static const String strOutAudRemoteIntTag;	//�����ƵԶ�˶˿ڼ����ǩ
	static const String strExeStrTag;			//ִ�������ַ�����ǩ
	static const String strCmdMsgTag;			//������Ϣ��ǩ
	static const String strPatition;            //б��
	static const String strCaseFilePath;		//�������ļ�·��


public:
	CTestCaseFactory();
	~CTestCaseFactory();
	virtual ITestCase* CreateTestCase( const String &strName );

private:
	/**  ������ͬ����Ĳ�����
	 *  @param[in] 
	 *  @node 
	 *  @return ������ָ��
	 */
	ITestCase* CreateCmdCase( String strCaseFile, String strName );
	ITestCase* CreateExeCase( String strCaseFile, String strName );
	ITestCase* CreateMediaCase( String strCaseFile, String strName );

	/** ��ȡmeida������ĸ��ֲ���
	 *  @param[in] pMediaCase:������ָ�� strCaseFile:�������ļ� strName:��������
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool GetMediaCaseParam( CMediaTestCase* pMediaCase, String strCaseFile, String strName );

	/**  ��ȡmedia��������Ϣ����
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool GetMediaCaseMsgQue( CMediaTestCase* pMediaCase, String strCaseFile, String strName );

	/**  ��ȡcmd��������Ϣ����
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool GetCmdCaseMsgQue( CCmdTestCase* pMediaCase, String strCaseFile, String strName );



};