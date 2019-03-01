#include "testcase.h"
class CTestCaseFactory : public ITestCaseFactory, public tmplContainer< String, ITestCase >
{
public:
	static const String strCfgFile;				//配置文件名
	static const String strCasePath;			//测试项路径
	static const String strCasePathEX;			//测试项路径	
	static const s8     chSeparater;			//分隔符
	static const String strTypeTag;			    //类型标签
	static const String strTypeMedia;			//media	
	static const String strTypeCmd;		     	//Cmd	
	static const String strTypeExe;			    //Exe
	static const String strNameTag;			    //Name标签
	static const String strRetestTag;			//重测标签
	static const String strDescTag;			    //Description标签
	static const String strEncParamTag;			//编码器参数标签
	static const String strStrInTag;			//输入码流参数标签
	static const String strStrOutTag;			//输出码流参数标签
	static const String strPreMsgTag;			//准备消息标签
	static const String strEndMsgTag;			//结束消息标签
	static const String strPathTag;				//媒体文件路径
	static const String strInVidCountTag;		//输入视频数标签
	static const String strInAudCountTag;		//输入音频数标签
	static const String strInVidRtpTag;			//输入视频RTP标签
	static const String strInAudRtpTag;			//输入音频RTP标签
	static const String strKeyFrameMsgTag;		//请求关键帧消息标签
	static const String strOutVidCountTag;		//输出视频数标签
	static const String strOutAudCountTag;		//输出音频数标签
 	static const String strOutFileTag;		    //输出码流文件标签
	static const String	strOutVidLocalRtpTag;	//输出视频本地RTP端口标签
	static const String strOutVidLocalIntTag;	//输出视频本地端口间隔标签
	static const String strOutVidRemoteRtpTag;	//输出视频远端RTP端口标签
	static const String strOutVidRemoteIntTag;	//输出视频远端端口间隔标签
	static const String strOutAudLocalRtpTag;	//输出音频本地RTP端口标签
	static const String strOutAudLocalIntTag;	//输出音频本地端口间隔标签
	static const String strOutAudRemoteRtpTag;	//输出音频远端RTP端口标签
	static const String strOutAudRemoteIntTag;	//输出音频远端端口间隔标签
	static const String strExeStrTag;			//执行命令字符串标签
	static const String strCmdMsgTag;			//命令消息标签
	static const String strPatition;            //斜杠
	static const String strCaseFilePath;		//测试项文件路径


public:
	CTestCaseFactory();
	~CTestCaseFactory();
	virtual ITestCase* CreateTestCase( const String &strName );

private:
	/**  创建不同种类的测试项
	 *  @param[in] 
	 *  @node 
	 *  @return 测试项指针
	 */
	ITestCase* CreateCmdCase( String strCaseFile, String strName );
	ITestCase* CreateExeCase( String strCaseFile, String strName );
	ITestCase* CreateMediaCase( String strCaseFile, String strName );

	/** 获取meida测试项的各种参数
	 *  @param[in] pMediaCase:测试项指针 strCaseFile:测试项文件 strName:测试项名
	 *  @node 
	 *  @return 是否成功
	 */
	bool GetMediaCaseParam( CMediaTestCase* pMediaCase, String strCaseFile, String strName );

	/**  获取media测试项消息队列
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool GetMediaCaseMsgQue( CMediaTestCase* pMediaCase, String strCaseFile, String strName );

	/**  获取cmd测试项消息队列
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	bool GetCmdCaseMsgQue( CCmdTestCase* pMediaCase, String strCaseFile, String strName );



};