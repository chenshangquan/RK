#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CBoardFactory : public IBoardFactory ,public tmplContainer< String, IBoard >
{
public:
	static const String strCfgFile;				//配置文件名
	static const String strBrdPath;				//板卡路径	
	static const s8     chSeparater;			//分隔符
	static const String strNameTag;				//板卡名
	static const String strAppIdTag;			//AppId标签
	static const String strHidTag;				//Hid标签
	static const String strPidTag;				//Pid标签
	static const String strModeTag;				//Mode标签
	static const String strIdTag;				//Id标签
	static const String strDescTag;				//描述标签
	static const String strE2pFlgTag;			//E2promFlag标签
	static const String strE2pInfoTag;			//E2promInfo标签
	static const String strSysFileTag;			//SysFile标签
	static const String strEthernetCount;		//网卡数量
	static const String strPipeLineTag;			//PipeLine标签
	static const String strPreMsgTag;			//PreMsg标签
	static const String strEndMsgTag;			//EndMsg标签
	static const String strResMsgTag;			//ResMsg标签
	static const String strRegMsgTag;			//RegMsg标签
	static const String strBrdPicTag;			//板卡图片标签
	static const String strCaseTag;				//测试项标签
	static const String strReqMsgTag;			//请求消息标签
	static const String strAckMsgTag;			//同意消息标签
	static const String strNackMsgTag;			//拒绝消息标签
	static const String strBrdFilePath;			// 板卡文件路径



public:
	CBoardFactory();
	~CBoardFactory();
	virtual IBoard* CreateBoard( const String &strName );
	virtual bool GetBrdTestCase( IBoard *pBoard );
	virtual bool GetBrdMsgQue( IBoard *pBoard );


private:
	/**  获取板卡的属性
	 *  @param[in] 板卡指针，板卡文件名 
	 *  @node 
	 *  @return 是否成功
	 */
	bool GetBrdAttribute( IBoard *pBoard, const String &strBrdFile );
	
};
