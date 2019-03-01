#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CBoardFactory : public IBoardFactory ,public tmplContainer< String, IBoard >
{
public:
	static const String strCfgFile;				//�����ļ���
	static const String strBrdPath;				//�忨·��	
	static const s8     chSeparater;			//�ָ���
	static const String strNameTag;				//�忨��
	static const String strAppIdTag;			//AppId��ǩ
	static const String strHidTag;				//Hid��ǩ
	static const String strPidTag;				//Pid��ǩ
	static const String strModeTag;				//Mode��ǩ
	static const String strIdTag;				//Id��ǩ
	static const String strDescTag;				//������ǩ
	static const String strE2pFlgTag;			//E2promFlag��ǩ
	static const String strE2pInfoTag;			//E2promInfo��ǩ
	static const String strSysFileTag;			//SysFile��ǩ
	static const String strEthernetCount;		//��������
	static const String strPipeLineTag;			//PipeLine��ǩ
	static const String strPreMsgTag;			//PreMsg��ǩ
	static const String strEndMsgTag;			//EndMsg��ǩ
	static const String strResMsgTag;			//ResMsg��ǩ
	static const String strRegMsgTag;			//RegMsg��ǩ
	static const String strBrdPicTag;			//�忨ͼƬ��ǩ
	static const String strCaseTag;				//�������ǩ
	static const String strReqMsgTag;			//������Ϣ��ǩ
	static const String strAckMsgTag;			//ͬ����Ϣ��ǩ
	static const String strNackMsgTag;			//�ܾ���Ϣ��ǩ
	static const String strBrdFilePath;			// �忨�ļ�·��



public:
	CBoardFactory();
	~CBoardFactory();
	virtual IBoard* CreateBoard( const String &strName );
	virtual bool GetBrdTestCase( IBoard *pBoard );
	virtual bool GetBrdMsgQue( IBoard *pBoard );


private:
	/**  ��ȡ�忨������
	 *  @param[in] �忨ָ�룬�忨�ļ��� 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool GetBrdAttribute( IBoard *pBoard, const String &strBrdFile );
	
};
