// uifactorylib.h: interface for the CUIFactoryLib class.
//���ܣ�uifactoy�ĳ��ýӿڷ�װ��ʹ��ʱֻ��������ļ�����
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UIFACTORYLIB_H__C36DC137_FE4D_41B2_BB11_0904AD0CCAD0__INCLUDED_)
#define AFX_UIFACTORYLIB_H__C36DC137_FE4D_41B2_BB11_0904AD0CCAD0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UifactoryHeader.h" 
 

class CUIFactoryLib:public ISingleTon<CUIFactoryLib>
{
public:
	CUIFactoryLib();
virtual ~CUIFactoryLib();

static void InitUIFactory( String strSystemName );

static void UnInitUIFactory();

/** @defgroup   �������Բ���
*  @{
*/
static void UpdateUI(   IWndTree* pWndTree );

static void UpdateUI( String strWndName,   IWndTree* pWndTree = NULL);
/**	 
* ����:  ��ʾ/����ĳ������
* @param [in]  strWndName  ������
* @param [in]  bShow  �Ƿ�Ҫ��ʾ 
* @param [in]  bReDraw  �Ƿ��ػ�
* @return  u16 �ɹ�����0;ʧ�ܷ��ط�0������
* @remarks	 
*/
static short ShowWindow( String strWndName, bool bShow = true,const IWndTree* pWndTree = NULL, BOOL bReDraw = TRUE );
 

/**	 
* ����:  ���ڿ�ʼ����ģʽ״̬
* @param [in]  strWndName  ������
* @param [in]  bCenter     �����Ƿ����
* @return  int  ���ش��ڽ���modal״̬ʱ�Ľ��
* @remarks	 2012.12.6 yjj
*/
static int Domodal( String strName, const IWndTree* pWndTree = NULL, BOOL bCenter = TRUE ); 
static int Domodal( Window* pWnd  );

/**	 
* ����:  ���ڽ���ģʽ״̬
* @param [in]  nReslut Ϊ Domodal�ķ���ֵ
* @return   
* @remarks	 2012.12.6 yjj
*/
static void Endmodal( int nResult, String strName, const IWndTree* pWndTree = NULL  ); 
static void Endmodal( int nResult, Window* pWnd  );


/**  ��ȡ�ؼ���Ϣ 
 *  @param[in] strName �ؼ�����
 *  @param[in] pWndTree �ؼ��� 
 *  @return �ؼ���Ϣ
 *  @remarks ���ؼ��к��С�/�� ��ᰴ�շָ�������
 */ 
static const IWndTree* GetWindow( String strName, const IWndTree* pWndTree = NULL )  ;


/**  ��ȡ�ؼ���Ϣ
 *  @param[in] pWnd ����ָ��
 *  @param[in] pWndTree ��Ҫ��������
 *  @return �����������Ĵ���
 */
static const IWndTree* GetWindow( Window* pWnd, const IWndTree* pWndTree );


/**  ��ȡ�ؼ�ָ�� 
 *  @param[in] strName �ؼ�����
 *  @param[in] pWndTree �ؼ��� 
 *  @return �ؼ���Ϣ
 *  @remarks ���ؼ��к��С�/�� ��ᰴ�շָ�������
 */ 
static Window* GetWindowPtr( String strName, const IWndTree* pWndTree = NULL );

 /**	 
* ����:  �����÷���
* @param [in] strSchemeName ������
* @param [in] String strWndName ���ø÷����Ĵ�����
* @param[in] pWndTree �������ڵĿؼ��� 
* @return   
* @remarks	   
*/
static bool LoadScheme( String strSchemeName, IWndTree* pWndTree = NULL , String strWndName = "", bool bInvalidate = true );

 /**	 
* ����:  ����ĳ�ؼ�����ֵ
* @param [in]  strWndName  ������
* @param [in]  value Ҫ���õ�������Ϣ 
* @param[in] pWndTree �ؼ����ڵ���
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 ���ؼ��к��С�/�� ��ᰴ�շָ�������
*/
static bool SetPropertyValue( const IValue& value,   String strWndName, const IWndTree* pWndTree = NULL );

 /**	 
* ����:  ��ȡĳ�ؼ�����ֵ
* @param [in&out]  IValue  Ҫ��ȡ��������Ϣ
* @param [in]  window  Ҫ��ȡ�����ԵĴ���ָ��
* @param [in]  strWndType  Ҫ��ȡ�����ԵĴ�������
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 
*/
static bool SetPropertyValue( const IValue& value, const Window* window,  const String& strWndType );


 /**	 
* ����:  ��ȡĳ�ؼ�����ֵ
* @param [in&out]  IValue  Ҫ��ȡ��������Ϣ
* @param [in]  strWndName  ������ 
* @param[in] pWndTree �ؼ����ڵ���
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 ���ؼ��к��С�/�� ��ᰴ�շָ�������
*/
static bool GetPropertyValue( IValue& value, String strWndName, const IWndTree* pWndTree = NULL);

 /**	 
* ����:  ��ȡĳ�ؼ�����ֵ
* @param [in&out]  IValue  Ҫ��ȡ��������Ϣ
* @param [in]  window  Ҫ��ȡ�����ԵĴ���ָ��
* @param [in]  strWndType  Ҫ��ȡ�����ԵĴ�������
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 
*/
static bool GetPropertyValue( IValue& value, const Window* window,  const String& strWndType );

/**	 
* ����:  ���ÿؼ��Ƿ����
* @param [in]  strWndName  �ؼ���
* @param [in]  bEnable  ״̬
* @param [in]  pWndTree �ؼ��� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 
*/
static bool EnableWindow( String strWndName, bool bEnable = true, const IWndTree* pWndTree = NULL );

/**	 
* ����:  ���ÿؼ�����
* @param [in]  strWndName  �ؼ���
* @param [in]  strCaption  ����
* @param [in]  pWndTree �ؼ��� 
* @param [in]  bReDraw  �Ƿ��ػ� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 
*/
static bool SetCaption( String strWndName, String strCaption, const IWndTree* pWndTree = NULL, BOOL bReDraw = TRUE );

/**	 
* ����:  ��ȡ�ؼ�����
* @param [in]  strWndName  �ؼ���
* @param [out] strCaption  ����
* @param [in]  pWndTree �ؼ��� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 
*/
static bool GetCaption( String strWndName, String& strCaption, const IWndTree* pWndTree = NULL );

/**	 
* ����:  ���ý���
* @param [in]  strWndName  �ؼ���
* @param [in]  pWndTree �ؼ��� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 
*/
static bool SetFocus( String strWndName, const IWndTree* pWndTree = NULL );

/**	 
* ����:  ����Button Check״̬
* @param [in]  strWndName  �ؼ���
* @param [in] nCheckState  ״̬
* @param [in]  pWndTree �ؼ��� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 
*/
static bool SetCheckState( String strWndName, int nCheckState, const IWndTree* pWndTree = NULL );

/**	 
* ����:  ��ȡButton Check״̬
* @param [in]  strWndName  �ؼ���
* @param [in] nCheckState  ״̬
* @param [in]  pWndTree �ؼ��� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 
*/
static bool GetCheckState( String strWndName, int& nCheckState, const IWndTree* pWndTree = NULL );

/**	 
* ����:  ����SwitchButton Check״̬
* @param [in]  strWndName  �ؼ���
* @param [in]  bState  ״̬
* @param [in]  pWndTree �ؼ��� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 
*/
static bool SetSwitchState( String strWndName, bool bState, const IWndTree* pWndTree = NULL );

/**	 
* ����:  ��ȡSwitchButton Check״̬
* @param [in]  strWndName  �ؼ���
* @param [out] bState  ״̬
* @param [in]  pWndTree �ؼ��� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 
*/
static bool GetSwitchState( String strWndName, bool& bState, const IWndTree* pWndTree = NULL );

/**	 
* ����:  �鿴�ؼ��Ƿ���ʾ
* @param [in]  strWndName  �ؼ��� 
* @param [in]  pWndTree �ؼ��� 
* @return  bool ��ʾ����true;δ��ʾ����false
* @remarks	 
*/
static bool IsVisible( String strWndName, const IWndTree* pWndTree = NULL );

/**	 
* ����:  ����DlgͼƬ
* @param [in]  strWndName  �ؼ���
* @param [in]  strPath  ͼƬ·��
* @param [in]  pWndTree �ؼ��� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 
*/
static bool SetTransparentDlgImage( String strWndName, String strPath, const IWndTree* pWndTree = NULL );

/**	 
* ����:  ����StaticͼƬ
* @param [in]  strWndName  �ؼ���
* @param [in]  strPath  ͼƬ·��
* @param [in]  pWndTree �ؼ��� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 
*/
static bool SetTransStaticImage( String strWndName, String strPath, const IWndTree* pWndTree = NULL );

/**	 
* ����:  ����DragButton Sel״̬
* @param [in]  strWndName  �ؼ���
* @param [out] bState  ״̬
* @param [in]  pWndTree �ؼ��� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
*/
static bool SetSelState( String strWndName, bool bState, const IWndTree* pWndTree = NULL );

/**	 
* ����:  ��ȡDragButton Sel״̬
* @param [in]  strWndName  �ؼ���
* @param [out] bState  ״̬
* @param [in]  pWndTree �ؼ��� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
*/
static bool GetSelState( String strWndName, bool& bState, const IWndTree* pWndTree = NULL );

/**	 
* ����:  ����DragButton Online״̬
* @param [in]  strWndName  �ؼ���
* @param [out] bOnline  ״̬
* @param [in]  pWndTree �ؼ��� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
*/
static bool SetDragBtnOnline( String strWndName, bool bOnline, const IWndTree* pWndTree = NULL );   
/**@} */  //�������Դ�����


/**	 
* ����:  ����windows��Ϣ
* @param [in]  pMsg Ҫ�������Ϣ��Ϣ
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	��uifactroy�ڲ�����ע�������Ϣ�Ĵ����� �Ը���Ϣ������Ӧ
*/
static bool HandleMsg( WindowMsg* pMsg );



 /**  �������д���
*  @param[in]  
*  @return �Ƿ����سɹ�
*/
static bool HideAllWindow();


/**	 
* ����:  ���ٴ���	 
* @param [in]  strWndName Ҫ���ٵĴ�����
* @return  u16 �ɹ�����0��ʧ�ܷ��ش���
* @remarks	   
*/ 
static bool DestoryWnd( String strWndName );


/**  ���ٴ��ڣ���������CWnd��Destory
*  @param[in] pWnd ����ָ��
*  @return �Ƿ����ٳɹ�
*/
static bool DestoryWnd( Window* pWnd );


/**  ���ٴ��ڣ���������CWnd��Destory
*  @param[in] pWnd ����ָ��,ֻ���ٷ�child���� �� �޸����ڵ�window
*  @return �Ƿ����ٳɹ�
*  @auth yjj 2012.12.12
*/
static bool DestoryWnd(   IWndTree* pWndTree );

 
/**  �������д��ڴ��ڣ���������CWnd��Destory
*  @param[in] pWndTree ������
*  @return �Ƿ����ٳɹ�
*  @auth yjj 2011.11.30
*/
static bool DestoryAllWnd();



/**  ��С������
*  @return �Ƿ���С���ɹ�
*  @auth yjj 2012.12.12
*/
static bool MinmizeWnd();


/**@} */  //wnd������

/**	 
* ����:  �Ѵ��ڷ��ĸı��¼���ļ��� 
* @param [in]   String strWndName������
*  @param[in] strSavePropertyName Ҫ�����������
*  @param[in] bForceSave ���Ҫ��������Բ��ڵ�ǰ�����У��Ƿ�ǿ�Ʊ���
* @return   
* @remarks	   
*/
static bool  SaveToFile( String strWndName, string strSaveWndName = "" ,string strSavePropertyName = "" , BOOL bForceSave = FALSE );

static String GetImagePath(); 


/**	 
* ����:  ����Combobox �༭���ı���ʾ����
* @param [in]  strWndName  �ؼ���
* @param [in]  strText  �ı�
* @param [in]  pWndTree �ؼ��� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 
*/
static bool SetComboText( String strWndName, String strText, const IWndTree* pWndTree /* = NULL */ );

/**	 
* ����:  �õ�Combobox �༭���ı���ʾ����
* @param [in]  strWndName  �ؼ���
* @param [in]  strText  �ı�����
* @param [in]  pWndTree �ؼ��� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 
*/
static bool GetComboText( String strWndName, String& strText, const IWndTree* pWndTree /* = NULL */ );

/**	 
* ����:  ����Combobox �б�����
* @param [in]  strWndName  �ؼ���
* @param [in]  strText  �ı�
* @param [in]  pWndTree �ؼ��� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 
*/
static bool SetComboListData( String strWndName, std::vector<CString> vecListData, const IWndTree* pWndTree /* = NULL */ );

/**	 
* ����:  ���Combobox �б�����
* @param [in]  strWndName  �ؼ���
* @param [in]  strDefText  comboxĬ����ʾ������
* @param [in]  pWndTree �ؼ��� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 
*/
static bool CleanComboListData( String strWndName, const IWndTree* pWndTree /* = NULL */, String strDefText = "��" );


/**	 
* ����:  ��ȡ�汾��
*
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 
*/
static string GetVersion();

/**	 
* ����:  ���ô���λ��
* @param [in]  pt  λ��
* @param [in]  strWndName Ҫ���õĴ�����
* @param [in]  pWndTree �ؼ��� 
* @param [in]  strRelativeWnd ����ò�����Ϊ�������õ�λ��Ϊ��Ըô���λ�� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	2013.1.10 yjj 
*/
static void SetWndPos(  POINT pt, String strWndName,   IWndTree* pWndTree = NULL,  String strRelativeWnd = "" );
 
/**	 
* ����:  ���ñ༭�򽹵��ú�
* @param [in]  strWndName  �ؼ���
* @param [in]  pWndTree �ؼ��� 
* @param [in]  bReDraw  �Ƿ��ػ� 
* @return  bool �ɹ�����true;ʧ�ܷ���false
* @remarks	 
*/
static bool SetEditFocusEnd( String strEditWndName, const IWndTree* pWndTree = NULL, BOOL bReDraw = FALSE ); 
/**	 
* ����:  ͨ��·��ɾ��ռ�õ�ͼƬ��Դ
* @param [in]  strPath  ͼƬ����·��
* @remarks	 
*/
static void  ReleaseSingleImage( String strPath );
};

#define UIFACTORYMGR_PTR CUIFactoryLib::GetSingletonPtr()

#endif // !defined(AFX_UIFACTORYLIB_H__C36DC137_FE4D_41B2_BB11_0904AD0CCAD0__INCLUDED_)
 