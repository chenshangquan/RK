// System.h: interface for the CSystem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYSTEM_H__4784FC43_AFB7_4047_B835_04B5785FEC0E__INCLUDED_)
#define AFX_SYSTEM_H__4784FC43_AFB7_4047_B835_04B5785FEC0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSystem : public Singleton<CSystem>
{
public:
/*
	xml��ǩ����
*/
	static const String strMainWindow;	//������
	static const String strSkin;		//����·��
public:
	CSystem( String strFile );
	virtual ~CSystem();
/** ϵͳ���� 
 *  @param[in] ��xml�ļ� 
 *  @node 
 *  @return �Ƿ�ɹ�
 */
	bool Launch();

protected:
/** ��ʼ��ϵͳ 
 *  @param[in] 
 *  @node ��Ҫ�Ƕ�ȡxml������Ϣ
 *  @return �Ƿ�ɹ�
 */
	bool IniSystem();

protected:
/*
	���ļ�·��
*/
	String m_strFile;
	
};

#endif // !defined(AFX_SYSTEM_H__4784FC43_AFB7_4047_B835_04B5785FEC0E__INCLUDED_)
