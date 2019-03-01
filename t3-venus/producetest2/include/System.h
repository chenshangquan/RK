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
	xml标签定义
*/
	static const String strMainWindow;	//主界面
	static const String strSkin;		//界面路径
public:
	CSystem( String strFile );
	virtual ~CSystem();
/** 系统启动 
 *  @param[in] 主xml文件 
 *  @node 
 *  @return 是否成功
 */
	bool Launch();

protected:
/** 初始化系统 
 *  @param[in] 
 *  @node 主要是读取xml配置信息
 *  @return 是否成功
 */
	bool IniSystem();

protected:
/*
	主文件路径
*/
	String m_strFile;
	
};

#endif // !defined(AFX_SYSTEM_H__4784FC43_AFB7_4047_B835_04B5785FEC0E__INCLUDED_)
