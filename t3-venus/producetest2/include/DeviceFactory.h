#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDeviceFactory : public IDeviceFactory ,public tmplContainer< String, IDevice >
{
public:
	static const String strCfgFile;				//�����ļ���
	static const String strDvcPath;				//�豸·��
	static const s8 chSeparater;				//�ָ���

public:
	CDeviceFactory();
	~CDeviceFactory();
	virtual IDevice* CreateDevice( const String &strName ) ;
protected:
	/**���豸������ģ��
	 *  @param[in] �豸ָ��
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	bool CDeviceFactory::BindNetModule( IDevice* pDevice );

};
