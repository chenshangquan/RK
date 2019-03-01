// ICommonOp.h: interface for the ICommonOp class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ICOMMONOP_H__DBC77325_3262_4246_BCB1_51CF05288BE7__INCLUDED_)
#define AFX_ICOMMONOP_H__DBC77325_3262_4246_BCB1_51CF05288BE7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/*
	���ò����࣬����һЩ��̬����
*/
class ICommonOp  
{
public:

	/**  ���ҿؼ�
	 *  @param[in] ���ƹ��������ؼ���������/����
	 *  @node 
	 *  @return �ؼ�ָ��
	 */
	static CControlUI* FindControl( CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent = NULL );

	/**  ����/���ÿؼ�
	 *  @param[in] ����/���ã����ƹ��������ؼ��������ؼ�
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	static bool ShowControl( bool bVisible, CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent = NULL );

	/**  ��ʾ/���ؿؼ�
	 *  @param[in] ��ʾ/���أ����ƹ��������ؼ��������ؼ�
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	static bool EnableControl( bool bEnabled, CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent = NULL );

	/**  ���ÿؼ�����
	 *  @param[in] ���֣����ƹ��������ؼ��������ؼ�
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	static bool SetControlText( String strText, CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent = NULL );

	/**  ��ȡ�ؼ�����
	 *  @param[in] ���ƹ��������ؼ��������ؼ�
	 *  @node 
	 *  @return �����ַ���
	 */
	static String GetControlText( CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent = NULL );
	/** ���ÿؼ��߿��ʽ 
	 *  @param[in] dwColor:��ɫ dwSize:���
	 *  @node 
	 *  @return 
	 */
	static bool SetControlBorderFormat( u32 dwColor, u32 dwSize, CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent = NULL );

	/**  ���ÿؼ�����ͼƬ
	 *  @param[in] ����ͼƬ�ļ��������ƹ��������ؼ��������ؼ�
	 *  @node 
	 *  @return �����ַ���
	 */
	static bool SetControlBkImg( String strFile, CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent = NULL );

	/**  ����Option�ؼ�ѡ��״̬
	 *  @param[in] �Ƿ�ѡ�У����ƹ��������ؼ��������ؼ�
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	static bool OptionSelect( bool bSelect, CPaintManagerUI *pManager ,String strControlName, CControlUI *pParent = NULL );

	/**  ��ȡXML�ڵ����ԣ���ת��Ϊ����
	 *  @param[in] �ڵ㣬��ǩ��ֵ����
	 *  @node 
	 *  @return ����ֵ�����Σ�
	 */
	static bool GetNodeValueInt( DocNode Node, String Tag, u32 &dwValue );
	
	/**  ��ȡXML�ڵ������ַ���
	 *  @param[in] �ڵ㣬��ǩ
	 *  @node 
	 *  @return �����ַ���
	 */
	static String GetNodeValueStr( DocNode Node, String Tag );

	/**  �ж��ַ����Ƿ�Ϊ����
	 *  @param[in] �ַ���
	 *  @node 
	 *  @return �Ƿ�Ϊ����
	 */
	static bool IsDigit( String strDig );

	/**  �����������豸�л�ȡ������
	 *  @param[in] 
	 *  @node 
	 *  @return ������ָ��
	 */
	static ITestCase* GetTestCase( IDevice *pDvc, String strCaseName);

	/**  ����������ȡ������
	 *  @param[in] 
	 *  @node 
	 *  @return ������ָ��
	 */
	static ITestCase* GetTestCase( IBoard *pBoard, u32 dwIdx );

	/**  ���ͽ�����Ϣ
	 *  @param[in] ��ϢId����Ϣ����ָ��
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	static bool Notify( u16 wMsgId, void *pData = NULL );

	/**  ��ʾ��ʾ�Ի���
	 *  @param[in] ��ʾ�ַ���
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	static bool ShowNotifyDlg( const String &strNotify );

	/**  ��ʾѡ��Ի���
	 *  @param[in] ��ʾ�ַ���
	 *  @node 
	 *  @return ѡ����
	 */
	static bool ShowChooseDlg( const String &strNotify );
	/**  ��ȡ�ļ�·��
	 *  @param[in] ��ʾ�ַ���
	 *  @node 
	 *  @return �ļ�·���ַ���
	 */
	static String GetFolderDir(const String strNotify = "ѡ���ļ�" );

	/** ����ļ�/·���Ƿ���� 
	 *  @param[in] strFilePath : �ļ�/�ļ���·��
	 *  @node 
	 *  @return �Ƿ����
	 */
	static bool CheckFileExists( const String &strFilePath );
	/** ע���ַ�����ӳ�� 
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	static bool RegMacros();

	/** ע��۲���  
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	static bool RegObservers();
	/** �����󣺽�XXX��ʽ��Ӳ���汾��ת��ΪX.XX 
	 *  @param[in] ԭʼ��ʽ
	 *  @node 
	 *  @return ת����ĸ�ʽ
	 */
	static String ConvertHardVer( const s8 *pchHardVer );
	/** ���ַ���ת��Ϊ��д
	 *  @param[in] �ַ���ָ��
	 *  @node 
	 *  @return 
	 */
	static bool ConvertToUpper( LPSTR pchStr );
protected:
	/** ��ȡ·���Ի���ص����� 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	static s32 CALLBACK BrowseCallbackProc(HWND hwnd,UINT uMsg,LPARAM lParam,LPARAM lpData);

};

#endif // !defined(AFX_ICOMMONOP_H__DBC77325_3262_4246_BCB1_51CF05288BE7__INCLUDED_)
