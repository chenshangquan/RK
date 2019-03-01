#pragma once
#include "structdef.h"

/*
	单例类
*/
template<class T> class Singleton
{
protected:
	static T* ms_pSingleton;
public:
	Singleton( void )
	{
		assert( !ms_pSingleton );
		ms_pSingleton = static_cast<T*>(this);
	}
	~Singleton( void )
	{
		assert( ms_pSingleton );
		ms_pSingleton = 0;
	}
	static T& GetSingleton( void )
	{
		assert( ms_pSingleton );
		return ( *ms_pSingleton );
	}
	static T* GetSingletonPtr( void )
	{
		return ms_pSingleton;
	}
};

/*
	映射表模板类
	KEY需要满足map键值要求
*/
template<class Key, class Object> class tmplContainer
{
protected:
	/*
	对象映射表
	*/
	typedef map<Key,Object*> ObjectMap;
	ObjectMap m_mapObjects;
public:
/** 找到对应的对象 
 *  @param[in] 
 *  @node 
 *  @return 是否成功
 */
	Object* Find( Key key )
	{
		map<Key,Object*>::iterator itr = m_mapObjects.find( key );
		if ( itr != m_mapObjects.end() )
		{
			return itr->second;
		}
		return NULL;
	}

/** 添加对象 
 *  @param[in] 
 *  @node 
 *  @return 是否成功
 */
	void Add( Key key, Object* pObject )
	{
		Object* pOb = Find( key );
		if ( pOb == 0 )
		{
			m_mapObjects[key] = pObject;
		}
	}

/** 移除对象 
 *  @param[in] 
 *  @node 
 *  @return 是否成功
 */
	void Remove( Key key )
	{
		m_mapObjects.erase( key );
	}

	/** 获取容器大小 
	*  @param[in] 
	*  @node 
	*  @return 容器
	*/
	u32 Size()
	{
		return m_mapObjects.size();
	}

}; 

/*
	UI管理器，负责UI的切换和
*/
class IWindowManager : public Singleton<IWindowManager>
{
public:
	~IWindowManager(){}
public:
	virtual bool ShowWindow( const String& strName ) = 0;
	virtual bool HideWindow( const String& strName ) = 0;
	virtual bool ShowChild( const String& strName ) = 0;
	virtual bool ShowModal( const String& strName ) = 0;
	virtual bool CloseWindow( const String& strName ) = 0;
	virtual Window* GetWindow( const String& strName ) = 0;
	virtual Control* GetControl( const String& strWindow, const String& strControl ) = 0;


};

/*
	获取控件
*/
class IControlFactory : public Singleton<IControlFactory>
{
public:
	virtual CControlUI* GetControl( String strName, CControlUI *pParent = NULL, CPaintManagerUI *pm = NULL ) = 0;
};

/*
	xml文档操作管理类
	可以获取xml文本内容
*/
class IDocManager : public Singleton<IDocManager>
{
public:
	/** xml文本读取 
	 *  @param[in] strTag 标签、
	 *  @node strPath不填写标明获取根节点 默认加载了system.xml文件过后，当前目录会变成当前资源目录
	 *        
	 *  @return 是否成功
	 */
	virtual bool GetDoc( const String strFile, String strTag, String& strValue, const String strPath = _T("") ) = 0;

	/** xml节点获取 
	 *  @param[in] strFile 文件，strPath 节点路径
	 *  @node strPath不填写标明获取根节点 
	 *        
	 *  @return 是否成功
	 */
	virtual DocNode GetNode( const String strFile, const String strPath = _T("") ) = 0;


};

/*
	消息观察者
*/
class IObserver
{
public:
	virtual bool Update( TMsgParam& tMsgParma ) = 0;
};

/*
	消息处理接口
*/
class IMsgManager : public Singleton<IMsgManager>
{
public:
	IMsgManager(){}
	virtual ~IMsgManager(){}
/** 广播消息 
 *  @param[in] tMsgParam 消息结构体 
 *  @node 
 *  @return 是否成功
 */
	virtual void SendMsg( TMsgParam& tMsgParam ) = 0;

/** 添加/删除观察者 
 *  @param[in] 
 *  @node 
 *  @return 是否成功
 */
	virtual void AddObserver( IObserver* pOb ) = 0;
	virtual void RemoveObserver( IObserver* pOb ) = 0;
};

/*
	添加一个Observer
*/
#define REG_MSG_OBSERVER( pObserver ) \
	IMsgManager::GetSingletonPtr()->AddObserver( pObserver );

/*
	Osp消息观察者
*/

class IOspOb
{
public:
	/** 构造函数 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	IOspOb() : m_pDecorater(0){}
	/** 析构函数 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual ~IOspOb(){}

	/**  处理消息
	 *  @param[in] 消息
	 *  @node 
	 *  @return 
	 */
	virtual void ProcMsg( const TObMsg &msg ) = 0;

	/**  发送消息
	 *  @param[in] wEvent 事件号，pContent 消息体指针，wLen 消息长度
	 *  @node 
	 *  @return 
	 */
	virtual bool SendMsg( u16 wEvent, u8 *pContent = 0, u16 wLen = 0)
	{
		if ( m_pDecorater != 0 )
		{
			m_pDecorater->SendMsg( wEvent, pContent, wLen );
		}
		return true;
	}
public:
	/**  设置装饰者 
	 *  @param[in] 观察者
	 *  @node 
	 *  @return 
	 */
	void SetDecorater( IOspOb* pMsgOb ){ m_pDecorater = pMsgOb; }

protected:
	/*
	装饰者指针	
	*/
	IOspOb* m_pDecorater;
};


class IOspObContainer : public IOspOb
{
public:
	/** 处理消息函数 
	 *  @param[in] 消息
	 *  @node 
	 *  @return 
	 */
	virtual void ProcMsg( const TObMsg &msg )
	{
	}

	/** 添加观察者 
	 *  @param[in] 观察者指针
	 *  @node 
	 *  @return 是否成功
	 */
	virtual void AddOb( IOspOb* pOb )
	{
		ObList::iterator begin = FindOb( pOb );
		if ( begin == m_observers.end() )
		{
			m_observers.push_back( pOb );
			pOb->SetDecorater( this );
		}	
		
	}

	/**  删除观察者
	 *  @param[in] 观察者指针
	 *  @node 
	 *  @return 是否成功
	 */
	virtual void RemoveOb( IOspOb* pOb )
	{
		ObList::iterator begin = FindOb( pOb );
		if ( begin != m_observers.end() )
		{
			m_observers.erase( begin );
			(*begin)->SetDecorater( NULL );
		}	
	}

	/** 清空观察者 
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool ClearOb( )
	{
		u32 dw = m_observers.size();
		ObList::iterator begin = m_observers.begin();
		while ( begin != m_observers.end() )
		{
			(*begin)->SetDecorater( NULL );
			m_observers.erase( begin );
		}
		return true;
	}
protected:
	/**  查找观察者
	 *  @param[in] 
	 *  @node 
	 *  @return 迭代器
	 */
	vector<IOspOb*>::iterator FindOb( IOspOb* pOb )
	{
		ObList::iterator begin = m_observers.begin();
		while ( begin != m_observers.end() )
		{
			if ( *begin == pOb )
			{
				return begin;
			}
			begin++;
		}
		return begin;
	}
protected:
	/*
	观察者列表	
	*/
	typedef vector<IOspOb*> ObList;
	ObList m_observers;
};



/*
	消息队列管理器
*/
class IMsgQueMngr : public IOspObContainer
{
public:
	/**  检测是否为空
	 *  @param[in] 
	 *  @node 
	 *  @return 是否为空
	 */
	virtual bool IsEmpty() = 0;

	/**  发送队列头上等待发送的所有消息
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual void SendHeaderMsg() = 0;

	/**  检测是否执行到最后
	 *  @param[in] 
	 *  @node 
	 *  @return 是否是最后
	 */
	virtual bool IsEnd() = 0;

	/**  添加消息
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool AddMsg( TQueMsg Msg ) = 0;

	/**  克隆
	 *  @param[in] 
	 *  @node 
	 *  @return 克隆对象指针
	 */

	virtual IMsgQueMngr* Clone() = 0;

	/**  消息队列状态还原
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */	
	virtual void Restore() = 0;

	/**  打印消息队列信息
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */	
	virtual void Print() = 0;
	/**  析构函数
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual ~IMsgQueMngr(){};
};


/*
	测试项接口类
*/
class ITestCase : public IOspObContainer
{
public:
	/**  克隆
	 *  @param[in] 
	 *  @node 
	 *  @return 克隆对象的指针
	 */
	virtual ITestCase* Clone() = 0;

	/**  获取测试项状态
	 *  @param[in] 
	 *  @node 
	 *  @return 测试项状态枚举
	 */
	virtual	EmTestCaseState GetState() = 0;

	/**  设置测试项状态
	 *  @param[in] 状态枚举
	 *  @node 
	 *  @return 是否成功
	 */
	virtual	bool SetState(EmTestCaseState emState) = 0;

	/**  获取测试项类型
	 *  @param[in] 
	 *  @node 
	 *  @return 测试项类型
	 */
	virtual EmTestCaseType GetType() = 0;

	/**  设置测试项类型
	 *  @param[in] 类型枚举
	 *  @node 
	 *  @return 是否成功
	 */
	virtual	bool SetType(EmTestCaseType emType) = 0;

	/**  获取测试项添加属性
	 *  @param[in] 
	 *  @node 
	 *  @return 是否添加
	 */
	virtual bool GetAdded() const = 0;

	/**  设置测试项添加属性
	 *  @param[in] 是否添加
	 *  @node 
	 *  @return 是否成功
	 */
	virtual	bool SetAdded(const bool bAdded) = 0;

	/**  执行测试项
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool ExeTestCase() = 0;

	/**  设置测试项名
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetCaseName( const String strCaseName ) = 0;

	/**  设置测试项描述
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetDescription( const String strDes ) = 0;
	
	/**  获取测试项名
	 *  @param[in] 
	 *  @node 
	 *  @return 测试项名
	 */
	virtual String GetCaseName() const = 0;

	/**  获取测试项描述
	 *  @param[in] 
	 *  @node 
	 *  @return 测试项描述
	 */
	virtual String GetCaseDesc() const = 0;

	/**  打印测试项信息
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual void Print() = 0;

	/**  测试项恢复原状态
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual void Restore() = 0;
	/**  是否可重测
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual bool IsRetestable() const = 0;
	/** 设置可重测属性 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual void SetRetestable( const bool &bRetest ) = 0;


protected:
	/*
		测试项名	
	*/
	String			m_strName;			//测试项名
	/*
		测试项描述	
	*/
	String			m_strDescription;	//测试项描述
	/*
		是否添加进测试
	*/
	bool			m_bAdded;			
	/*
		测试项类型	
	*/
	EmTestCaseType	m_emType;			
	/*
		测试项状态	
	*/
	EmTestCaseState	m_emState;			
	/*
		是否可重测	
	*/
	bool			m_bRetestable;		

};
/*
	加载信息管理类	
*/
class ILoadInfoMngr : public Singleton<ILoadInfoMngr>, public IObserver
{
public:
	~ILoadInfoMngr(){};
	/**获取加载信息  
	 *  @param[in] dwBrdIdx:加载板卡的索引, pBuf:加载信息存放的buffer指针, dwLen:实际加载信息的长度[out]
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool GetLoadInfo( const u32 dwBrdIdx, s8 *pBuf, u32 &dwLen ) = 0;
	virtual bool Update( TMsgParam& tMsgParma ){ return true; }

};
/*
	测试项容器接口类
*/
class ITestCaseContainer
{
public:

	/**  添加/删除测试项
	 *  @param[in] 
	 *  @node 
	 *  @return 克隆对象的指针
	 */
		virtual bool AddTestCase( ITestCase *pTestCase ) = 0;

		virtual bool RemoveTestCase( ITestCase *pTestCase ) = 0;

		/**  根据索引获取测试项
		 *  @param[in] 
		 *  @node 
		 *  @return 测试项
		 */
		virtual ITestCase* GetTestCase( u32 dwIdx ) = 0;

		/**  清空测试项列表
		 *  @param[in] 
		 *  @node 
		 *  @return 是否成功
		 */
		virtual bool RemoveAll() = 0;

		/**  根据索引获取测试项
		 *  @param[in] 测试项索引
		 *  @node 
		 *  @return 测试项指针
		 */
		virtual ITestCase* GetTestCase( String strCaseName ) = 0;

		/**  获取测试项数量
		 *  @param[in] 测试项名 
		 *  @node 
		 *  @return 测试项指针
		 */
		virtual u32 GetCaseCount() = 0;
		
		/**  获得容器当前测试项
		 *  @param[in] 
		 *  @node 
		 *  @return 当前测试项指针
		 */
		virtual ITestCase* GetCurCase() = 0;
		/**  恢复状态
		 *  @param[in] 
		 *  @node 
		 *  @return 
		 */
		virtual bool Restore() = 0;

		/**  析构函数
		 *  @param[in] 
		 *  @node 
		 *  @return 
		 */
		virtual ~ITestCaseContainer(){} ;

	
};

/*
	板卡接口类
*/
class IBoard : public IOspObContainer
{
public:

	/**  设置板卡激活属性
	 *  @param[in] 是否激活
	 *  @node 
	 *  @return 
	 */
	virtual bool SetActivated( const bool bActivated ) = 0;

	/**  获取板卡激活属性
	 *  @param[in] 
	 *  @node 
	 *  @return 是否激活
	 */
	virtual bool GetActivated()  const = 0;

	/**  设置IP地址
	 *  @param[in] AppId
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetIpAddr(const u32 &dwIp ) = 0;

	/**  获取板卡IP
	 *  @param[in] 
	 *  @node 
	 *  @return IP地址
	 */
	virtual u32 GetIpAddr() const = 0;

	/**  设置AppId
	 *  @param[in] AppId
	 *  @node 
	 *  @return 是否成功
	 */
	virtual	bool SetAppId( const u32 dwAppId ) = 0;

	/**  获取AppId
	 *  @param[in] 
	 *  @node 
	 *  @return AppId
	 */
	virtual u32	GetAppId() const = 0;

	/**  设置E2prom标志
	 *  @param[in] E2prom标志
	 *  @node 
	 *  @return 是否成功
	 */
	virtual	bool SetE2promFlag( const u32 dwFlag ) = 0;

	/**  获取E2prom标志
	 *  @param[in] 
	 *  @node 
	 *  @return E2prom标志
	 */
	virtual u32 GetE2promFlag()  const = 0;

		/**  设置E2prom标志
	 *  @param[in] E2prom标志
	 *  @node 
	 *  @return 是否成功
	 */
	virtual	bool SetE2promInfo( const u32 dwInfo ) = 0;

	/**  获取E2prom标志
	 *  @param[in] 
	 *  @node 
	 *  @return E2prom标志
	 */
	virtual u32 GetE2promInfo()  const = 0;

	/**  设置结束消息队列
	 *  @param[in] 结束消息队列管理器
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetEndMsgQue( IMsgQueMngr *MsgQue ) = 0;

	/**  获取结束消息队列
	 *  @param[in] 
	 *  @node 
	 *  @return 结束消息队列管理器
	 */
	virtual IMsgQueMngr* GetEndMsgQue() = 0;

	/**  获取恢复出厂设置消息队列
	 *  @param[in] 
	 *  @node 
	 *  @return 恢复出厂设置消息队列
	 */
	virtual IMsgQueMngr* GetResMsgQue() = 0;

	/**  设置恢复出厂设置消息队列
	 *  @param[in] 恢复出厂设置消息队列管理器
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetResMsgQue( IMsgQueMngr *MsgQue ) = 0;

	/**  设置模式
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetMode(const u8 byMode) = 0;

	/**  获取模式
	 *  @param[in] 
	 *  @node 
	 *  @return 板卡模式
	 */
	virtual u8   GetMode() const = 0;

	/**  获取硬件版本
	 *  @param[in] 
	 *  @node 
	 *  @return 硬件版本
	 */
	virtual	s8* GetHardVersion()  = 0;

	/**  设置板卡图片文件
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */

	virtual bool SetBrdPic(const String &strBrdPic ) = 0;

	/**  获取板卡图片文件
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual String GetBrdPic() const = 0;

	/**  设置网卡数量
	 *  @param[in] dwCount:网卡数量
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetEthernetCount( const u32 &dwCount ) = 0;

	/**  获取网卡数量
	 *  @param[in] 
	 *  @node 
	 *  @return 网卡数量
	 */
	virtual u32 GetEthernetCount() const = 0;


	/**  设置硬件版本
	 *  @param[in] 硬件版本
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetHardVersion( const s8* pchHardVer ) = 0;

	/**  获取HID
	 *  @param[in] 
	 *  @node 
	 *  @return HID
	 */
	virtual u16	GetHid() const = 0;

	/**  设置HID
	 *  @param[in] HID
	 *  @node 
	 *  @return HID
	 */
	virtual bool SetHid( const u16 &wHid ) = 0;


	/**  获取PID
	 *  @param[in] 
	 *  @node 
	 *  @return PID
	 */
	virtual u16 GetPid()  const = 0;

	/**  设置PID
	 *  @param[in] PID
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetPid( const u16 &wPid ) = 0;

	/**  获取流水线
	 *  @param[in] 
	 *  @node 
	 *  @return 流水线字符串指针
	 */
	virtual s8* GetPipeLine() = 0;

	/**  设置流水线
	 *  @param[in] 流水线 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetPipeLine( const s8* achPipeLine ) = 0;

	/**  获取准备消息队列
	 *  @param[in] 
	 *  @node 
	 *  @return 消息队列指针
	 */
	virtual IMsgQueMngr* GetPreMsgQue() const = 0;
	
	/**  设置准备消息队列
	 *  @param[in] 
	 *  @node 
	 *  @return 消息队列指针
	 */
	virtual bool SetPreMsgQue( IMsgQueMngr *MsgQue ) = 0;

	/**  设置注册消息
	 *  @param[in] 注册消息
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetRegMsg( TBrdRegMsg RegMsg ) = 0;

	/**  设置序列号
	 *  @param[in] 序列号
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetSerialNo(const s8 *pchSn) = 0;

	/**  获取序列号
	 *  @param[in] 
	 *  @node 
	 *  @return 序列号字符串
	 */
	virtual s8* GetSerialNo() = 0;

	/**  设置板卡Mac地址
	 *  @param[in] Mac地址
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetMac( const s8 *pchMac ) = 0;

	/**  获取板卡Mac地址
	 *  @param[in] 
	 *  @node 
	 *  @return Mac地址
	 */
	virtual s8* GetMac() = 0;

	/**  获取软件版本
	 *  @param[in] 
	 *  @node 
	 *  @return 软件版本
	 */
	virtual	s8* GetSoftVersion() = 0;

	/**  设置软件版本
	 *  @param[in] 软件版本
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetSoftVersion( const s8 *pchSoftVer ) = 0;

	/**  设置子网掩码
	 *  @param[in] 子网掩码 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetSubMsk( const u32 dwSubMsk ) = 0;

	/**  获取子网掩码
	 *  @param[in] 
	 *  @node 
	 *  @return 子网掩码
	 */
	virtual u32 GetSubMsk() const = 0;

	/**  获取日期
	 *  @param[in] 
	 *  @node 
	 *  @return 日期字符串指针 
	 */
	virtual LPCSTR GetDate() = 0;

	/**  设置日期
	 *  @param[in] 日期字符串指针 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetDate( LPCSTR pchDate ) = 0;
	
	/**  获取升级文件名
	 *  @param[in] 
	 *  @node 
	 *  @return 文件名
	 */
	virtual String GetSysFile() const = 0;

	/**  设置升级文件名
	 *  @param[in] 文件名 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetSysFile( const String &strFileName ) = 0;

	/**  克隆
	 *  @param[in] 
	 *  @node 
	 *  @return 克隆对象的指针
	 */
	virtual IBoard* Clone() = 0;

	/**  设置板卡名字
	 *  @param[in] 板卡名
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetBrdName( const String strBrdName ) = 0;
	
	/**  获取板卡名字
	 *  @param[in] 
	 *  @node 
	 *  @return 板卡名
	 */
	virtual String GetBrdName() const = 0;


	/**  打印板卡信息
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual void Print() = 0;

	/**  获取测试项容器指针
	 *  @param[in] 
	 *  @node 
	 *  @return 测试项容器指针
	 */
	virtual ITestCaseContainer* GetCaseContainer() = 0;

	/**  设置板卡进度
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetProcedure( const EmBrdProceduer emProcedure ) = 0;

	/**  板卡还原到初始状态
	 *  @param[in] 是否激活
	 *  @node 
	 *  @return 
	 */
	virtual void Restore() = 0;

	/**  设置板卡描述
	 *  @param[in] 板卡描述字符串
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetBrdDesc( const String &strDesc ) = 0;

	/**  获取板卡描述
	 *  @param[in] 
	 *  @node 
	 *  @return 板卡描述字符串
	 */
	virtual String GetBrdDesc() = 0;
	/**  清除所有的消息队列
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual void ClearMsgQue() = 0;
	/**  析构函数
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual ~IBoard(){};
};


/*
	设备接口类
*/
class IDevice 
{
public:
	/**  克隆
	 *  @param[in] 
	 *  @node 
	 *  @return 克隆对象的指针
	 */
	virtual IDevice* Clone() = 0;

	/**  置测试项
	 *  @param[in] 下一项/当前项
	 *  @node 
	 *  @return 克隆对象的指针
	 */
	virtual bool SetTestCase( EmCaseSetType emType ) = 0;

	/**  获取当前的测试项
	 *  @param[in] 
	 *  @node 
	 *  @return 测试项指针
	 */
	virtual	ITestCase* GetCurTestCase() = 0;
	
	/**  获取板卡指针
	 *  @param[in] 板卡索引
	 *  @node 
	 *  @return 板卡指针
	 */
	virtual IBoard* GetBoard(u32 dwIdx) = 0;

	/**  添加删除板卡
	 *  @param[in] 板卡索引
	 *  @node 
	 *  @return 板卡指针
	 */
	virtual bool AddBoard(IBoard *pBoard) = 0;

	/**  获取板卡数量
	 *  @param[in] 板卡索引
	 *  @node 
	 *  @return 板卡指针
	 */
	virtual u32	 GetBrdCount()	const		  = 0;

	virtual bool RemoveBoard(IBoard *pBoard) = 0;

	/**  打印设备信息
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual void Print() = 0;

	/**  获取设备名
	 *  @param[in] 
	 *  @node 
	 *  @return 设备名
	 */
	virtual String GetName() const = 0;

	/**  设置设备名
	 *  @param[in] 设备名字符串
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetName( const String &strName ) = 0;

	/**  结束测试
	 *  @param[in] 是否正常结束
	 结束的途径: 1.测试正常完成 2.用户中止 3.与设备断链
	 *  @node 
	 *  @return 
	 */
	virtual void EndTest( bool bNormal = true ) = 0;

	/** 是否已经结束 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual bool IsEnd() const = 0;
	/** 恢复 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual void Restore() = 0;
	
	/**  析构函数
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual ~IDevice(){};
};
/*
	UI数据
*/
class IUserDataMngr : public IObserver, public Singleton<IUserDataMngr>
{
public:
	/**  根据消息更新
	 *  @param[in] 消息
	 *  @node 
	 *  @return 是否成功
	 */
	virtual		bool	Update( TMsgParam& tMsgParma )	= 0;
	
	/**  设置起始IP
	 *  @param[in] IP
	 *  @node 
	 *  @return 
	 */
	virtual void SetSartIp( const u32 dwIp )			= 0;
 	
	/**  获取起始IP
	 *  @param[in] 
	 *  @node 
	 *  @return IP
	 */
	virtual u32	GetStartIp() const = 0;

	/**  设置起始Mac
	 *  @param[in] Mac地址字符串指针
	 *  @node 
	 *  @return 
	 */
 	virtual void SetStartMac( const s8 *pchMac ) = 0;

	/** 获取起始Mac
	 *  @param[in] 
	 *  @node 
	 *  @return Mac地址字符串指针
	 */
 	virtual s8*	GetStartMac() = 0;

	/**  设置恢复出产设置属性
	 *  @param[in] 是/否恢复出厂设置
	 *  @node 
	 *  @return 
	 */
 	virtual void SetRestore( const bool bRes ) = 0;

	/**  获取恢复出厂设置属性
	 *  @param[in] 
	 *  @node 
	 *  @return 是/否恢复出厂设置
	 */
 	virtual bool GetRestore() const	= 0;

	/**  设置Tftp路径
	 *  @param[in] 路径字符串
	 *  @node 
	 *  @return 
	 */
 	virtual void SetTftpPath( const String strPath ) = 0;

	/**  获取Tftp路径
	 *  @param[in] 
	 *  @node 
	 *  @return 路径字符串
	 */
 	virtual	String GetTftpPath() const = 0;

	/**  设置UI模式
	 *  @param[in] UI模式枚举
	 *  @node 
	 *  @return 
	 */
 	virtual	void SetUIMode( const EmUIMode emMode ) = 0;

	/**  获取UI模式
	 *  @param[in] 
	 *  @node 
	 *  @return UI模式枚举
	 */
 	virtual	EmUIMode GetUIMode() const = 0;

	/**  设置UI状态
	 *  @param[in] UI状态枚举 
	 *  @node 
	 *  @return 
	 */
 	virtual	void SetUIState( const EmUIState emMode ) = 0;

	/**  获取UI状态  
	 *  @param[in] 
	 *  @node 
	 *  @return UI状态枚举
	 */
 	virtual	EmUIState GetUIState() const = 0;

	/**  获取设备指针
	 *  @param[in] 
	 *  @node 
	 *  @return 设备指针
	 */
 	virtual	IDevice* GetDevice() const = 0;

	/** 获取选中的测试项指针
	 *  @param[in] 
	 *  @node 
	 *  @return 选中测试项指针
	 */
 	virtual	ITestCase*	GetSelectedCase() const = 0;
	

	/** 设置设备
	 *  @param[in] 设备名
	 *  @node 
	 *  @return 是否成功
	 */
 	virtual	bool SetDevice( const String strDvcName ) = 0;

	/** 设置设备
	 *  @param[in] 设备指针 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual	bool SetDevice( IDevice *pDevice ) = 0;


	/**  设置选中测试项
	 *  @param[in] 选中测试项名字符串
	 *  @node 
	 *  @return 
	 */
 	virtual	bool SetSelectedCase( const String strCaseName ) = 0;


	/** 设置显示状态
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual	bool SetDispState( const String strState ) = 0;

	/** 获取显示状态
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual	String GetDispState() const = 0;

	/** 获取提示对话框字符串
	 *  @param[in] 
	 *  @node 
	 *  @return 字符串
	 */
	virtual String GetNotifyDlgStr() const = 0;

	/** 设置提示对话框字符串
	 *  @param[in] 字符串
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool SetNotifyDlgStr( const String &strNotify ) = 0;

	/** 获取选择对话框结果
	 *  @param[in] 
	 *  @node 
	 *  @return 是否确定
	 */
	virtual		bool		GetChooseDlgResult() const = 0;

	/** 设置选择对话框结果 
	 *  @param[in] bOk 是否确定 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual		bool		SetChooseDlgResult( const bool bOk ) = 0;

	/** 添加超级终端显示
	 *  @param[in] 字符串
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool AppendComDisp( LPCSTR pchContent ) = 0;

	/** 清空超级终端显示 
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool ClearComDisp() = 0;

	/** 获取超级终端显示字符串 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual LPCSTR GetComDispStr() = 0;

	/**  析构函数
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual	~IUserDataMngr(){};


};
	



typedef CNotifyUIImpl ILogic;
/*
	logic工厂，用于创建和管理logic
*/
class ILogicManager : public Singleton<ILogicManager>
{
public:
	virtual ~ILogicManager(){}
	virtual ILogic* Create( const String& strLogic ) = 0;
};

enum LogLevel
{
	Errors,
		Warnings,
		Standard,
		Informative,
		Insane			
};


/*
	调试打印信息输出类
*/
class ILogger : public Singleton<ILogger>
{
public:
	virtual bool LogEvent( LPCTSTR pstrFormat, ... ) = 0;
	virtual ~ILogger(){}
};

/*
	设备工厂
*/
class IDeviceFactory : public Singleton<IDeviceFactory>
{
public:
	/**  创建设备
	 *  @param[in] 设备名字符串
	 *  @node 
	 *  @return 设备
	 */
	virtual IDevice* CreateDevice( const String &strName ) = 0;
};

/*
	板卡工厂
*/
class IBoardFactory : public Singleton<IBoardFactory>
{
public:
	/**  创建板卡
	 *  @param[in] 板卡名字符串
	 *  @node 
	 *  @return 板卡
	 */
	virtual IBoard* CreateBoard( const String &strName ) = 0;
	/**  获取板卡测试项
	 *  @param[in] 板卡指针
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool GetBrdTestCase( IBoard *pBoard ) = 0;

	/**  获取板卡测试项
	 *  @param[in] 板卡指针
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool GetBrdMsgQue( IBoard *pBoard ) = 0;

};

/*
	测试项工厂
*/
class ITestCaseFactory : public Singleton<ITestCaseFactory>
{
public:
	/**  创建测试项
	 *  @param[in] 测试项名字符串
	 *  @node 
	 *  @return 测试项
	 */
	virtual ITestCase* CreateTestCase( const String &strName ) = 0;
};

/*
	消息队列项工厂
*/
class IMsgQueFactory : public Singleton<IMsgQueFactory>
{
public:
	/**  创建消息队列
	 *  @param[in] 队列节点
	 *  @node 
	 *  @return 消息队列，若文件配置非法，将返回0
	 */
	virtual IMsgQueMngr* CreateMsgQue( String strFileName, String strNodePath ) = 0;
};

/*
	宏管理器，描述宏与字符串的映射关系	
*/
class IMacroMngr : public Singleton<IMacroMngr>
{
public:
	/**  翻译宏字符串
	 *  @param[in] 
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool Translate( const String strMarco, u32 &dwMacro ) = 0;

	/**  注册宏映射关系
	 *  @param[in] 宏字符串，宏值
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool RegMacro( const String strMacro, const u32 dwMacro ) = 0;
}; 

/*
	Osp App管理器	
*/
class IOspAppManager : public Singleton<IOspAppManager>
{
public:
	/**  创建App
	 *  @param[in] App号,App名
	 *  @node 
	 *  @return 
	 */
	virtual bool CreateApp( u16 wAppId, const s8 *pchAppName ) = 0;

	/**  删除App
	 *  @param[in] App号
	 *  @node 
	 *  @return 是否成功
	 */
	virtual bool KillApp( u16 wAppId ) = 0;

	/**析构函数  
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */	
	virtual ~IOspAppManager(){}
};



class IOspSession : public IOspObContainer
{
public:
	~IOspSession(){}
	virtual bool SetAddrInfo( const u32 &dwLocalId, const u32 &dwDstId ) = 0;
};

/*
Osp会话管理器	
*/
class IOspSessionMngr : public Singleton<IOspSessionMngr>
{
public:
	/**  创建会话
	 *  @param[in] App号
	 *  @node 
	 *  @return 会话指针
	 */
	virtual IOspSession* CreateSession( u16 wAppId ) = 0;

	/**  查找会话
	 *  @param[in] App号
	 *  @node 
	 *  @return 会话指针
	 */
	virtual IOspSession* FindSession( u16 wAppId ) = 0;

	/**  删除会话 
	 *  @param[in] App号
	 *  @node 
	 *  @return 是否成功 
	 */
	virtual bool KillSession( u16 wAppId ) = 0;

	/**  析构函数
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual ~IOspSessionMngr(){}
};

/*
	注册宏映射
*/
#define REGMACRO(Macro)  IMacroMngr::GetSingletonPtr()->RegMacro( #Macro, Macro );
/*
	注册宏映射(自动转为网络序)
*/
#define REGHTONLMACRO(Macro) IMacroMngr::GetSingletonPtr()->RegMacro( #Macro, htonl(Macro) );

/*
	打印宏
*/
#define LOGEVENT ILogger::GetSingletonPtr()->LogEvent






