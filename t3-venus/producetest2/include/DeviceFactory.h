#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDeviceFactory : public IDeviceFactory ,public tmplContainer< String, IDevice >
{
public:
	static const String strCfgFile;				//配置文件名
	static const String strDvcPath;				//设备路径
	static const s8 chSeparater;				//分隔符

public:
	CDeviceFactory();
	~CDeviceFactory();
	virtual IDevice* CreateDevice( const String &strName ) ;
protected:
	/**给设备绑定网络模块
	 *  @param[in] 设备指针
	 *  @node 
	 *  @return 是否成功
	 */
	bool CDeviceFactory::BindNetModule( IDevice* pDevice );

};
