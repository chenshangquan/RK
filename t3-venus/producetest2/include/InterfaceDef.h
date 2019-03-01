#pragma once
#include "structdef.h"

/*
	������
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
	ӳ���ģ����
	KEY��Ҫ����map��ֵҪ��
*/
template<class Key, class Object> class tmplContainer
{
protected:
	/*
	����ӳ���
	*/
	typedef map<Key,Object*> ObjectMap;
	ObjectMap m_mapObjects;
public:
/** �ҵ���Ӧ�Ķ��� 
 *  @param[in] 
 *  @node 
 *  @return �Ƿ�ɹ�
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

/** ��Ӷ��� 
 *  @param[in] 
 *  @node 
 *  @return �Ƿ�ɹ�
 */
	void Add( Key key, Object* pObject )
	{
		Object* pOb = Find( key );
		if ( pOb == 0 )
		{
			m_mapObjects[key] = pObject;
		}
	}

/** �Ƴ����� 
 *  @param[in] 
 *  @node 
 *  @return �Ƿ�ɹ�
 */
	void Remove( Key key )
	{
		m_mapObjects.erase( key );
	}

	/** ��ȡ������С 
	*  @param[in] 
	*  @node 
	*  @return ����
	*/
	u32 Size()
	{
		return m_mapObjects.size();
	}

}; 

/*
	UI������������UI���л���
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
	��ȡ�ؼ�
*/
class IControlFactory : public Singleton<IControlFactory>
{
public:
	virtual CControlUI* GetControl( String strName, CControlUI *pParent = NULL, CPaintManagerUI *pm = NULL ) = 0;
};

/*
	xml�ĵ�����������
	���Ի�ȡxml�ı�����
*/
class IDocManager : public Singleton<IDocManager>
{
public:
	/** xml�ı���ȡ 
	 *  @param[in] strTag ��ǩ��
	 *  @node strPath����д������ȡ���ڵ� Ĭ�ϼ�����system.xml�ļ����󣬵�ǰĿ¼���ɵ�ǰ��ԴĿ¼
	 *        
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool GetDoc( const String strFile, String strTag, String& strValue, const String strPath = _T("") ) = 0;

	/** xml�ڵ��ȡ 
	 *  @param[in] strFile �ļ���strPath �ڵ�·��
	 *  @node strPath����д������ȡ���ڵ� 
	 *        
	 *  @return �Ƿ�ɹ�
	 */
	virtual DocNode GetNode( const String strFile, const String strPath = _T("") ) = 0;


};

/*
	��Ϣ�۲���
*/
class IObserver
{
public:
	virtual bool Update( TMsgParam& tMsgParma ) = 0;
};

/*
	��Ϣ����ӿ�
*/
class IMsgManager : public Singleton<IMsgManager>
{
public:
	IMsgManager(){}
	virtual ~IMsgManager(){}
/** �㲥��Ϣ 
 *  @param[in] tMsgParam ��Ϣ�ṹ�� 
 *  @node 
 *  @return �Ƿ�ɹ�
 */
	virtual void SendMsg( TMsgParam& tMsgParam ) = 0;

/** ���/ɾ���۲��� 
 *  @param[in] 
 *  @node 
 *  @return �Ƿ�ɹ�
 */
	virtual void AddObserver( IObserver* pOb ) = 0;
	virtual void RemoveObserver( IObserver* pOb ) = 0;
};

/*
	���һ��Observer
*/
#define REG_MSG_OBSERVER( pObserver ) \
	IMsgManager::GetSingletonPtr()->AddObserver( pObserver );

/*
	Osp��Ϣ�۲���
*/

class IOspOb
{
public:
	/** ���캯�� 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	IOspOb() : m_pDecorater(0){}
	/** �������� 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual ~IOspOb(){}

	/**  ������Ϣ
	 *  @param[in] ��Ϣ
	 *  @node 
	 *  @return 
	 */
	virtual void ProcMsg( const TObMsg &msg ) = 0;

	/**  ������Ϣ
	 *  @param[in] wEvent �¼��ţ�pContent ��Ϣ��ָ�룬wLen ��Ϣ����
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
	/**  ����װ���� 
	 *  @param[in] �۲���
	 *  @node 
	 *  @return 
	 */
	void SetDecorater( IOspOb* pMsgOb ){ m_pDecorater = pMsgOb; }

protected:
	/*
	װ����ָ��	
	*/
	IOspOb* m_pDecorater;
};


class IOspObContainer : public IOspOb
{
public:
	/** ������Ϣ���� 
	 *  @param[in] ��Ϣ
	 *  @node 
	 *  @return 
	 */
	virtual void ProcMsg( const TObMsg &msg )
	{
	}

	/** ��ӹ۲��� 
	 *  @param[in] �۲���ָ��
	 *  @node 
	 *  @return �Ƿ�ɹ�
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

	/**  ɾ���۲���
	 *  @param[in] �۲���ָ��
	 *  @node 
	 *  @return �Ƿ�ɹ�
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

	/** ��չ۲��� 
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
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
	/**  ���ҹ۲���
	 *  @param[in] 
	 *  @node 
	 *  @return ������
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
	�۲����б�	
	*/
	typedef vector<IOspOb*> ObList;
	ObList m_observers;
};



/*
	��Ϣ���й�����
*/
class IMsgQueMngr : public IOspObContainer
{
public:
	/**  ����Ƿ�Ϊ��
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�Ϊ��
	 */
	virtual bool IsEmpty() = 0;

	/**  ���Ͷ���ͷ�ϵȴ����͵�������Ϣ
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual void SendHeaderMsg() = 0;

	/**  ����Ƿ�ִ�е����
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ������
	 */
	virtual bool IsEnd() = 0;

	/**  �����Ϣ
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool AddMsg( TQueMsg Msg ) = 0;

	/**  ��¡
	 *  @param[in] 
	 *  @node 
	 *  @return ��¡����ָ��
	 */

	virtual IMsgQueMngr* Clone() = 0;

	/**  ��Ϣ����״̬��ԭ
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */	
	virtual void Restore() = 0;

	/**  ��ӡ��Ϣ������Ϣ
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */	
	virtual void Print() = 0;
	/**  ��������
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual ~IMsgQueMngr(){};
};


/*
	������ӿ���
*/
class ITestCase : public IOspObContainer
{
public:
	/**  ��¡
	 *  @param[in] 
	 *  @node 
	 *  @return ��¡�����ָ��
	 */
	virtual ITestCase* Clone() = 0;

	/**  ��ȡ������״̬
	 *  @param[in] 
	 *  @node 
	 *  @return ������״̬ö��
	 */
	virtual	EmTestCaseState GetState() = 0;

	/**  ���ò�����״̬
	 *  @param[in] ״̬ö��
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual	bool SetState(EmTestCaseState emState) = 0;

	/**  ��ȡ����������
	 *  @param[in] 
	 *  @node 
	 *  @return ����������
	 */
	virtual EmTestCaseType GetType() = 0;

	/**  ���ò���������
	 *  @param[in] ����ö��
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual	bool SetType(EmTestCaseType emType) = 0;

	/**  ��ȡ�������������
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ����
	 */
	virtual bool GetAdded() const = 0;

	/**  ���ò������������
	 *  @param[in] �Ƿ����
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual	bool SetAdded(const bool bAdded) = 0;

	/**  ִ�в�����
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool ExeTestCase() = 0;

	/**  ���ò�������
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetCaseName( const String strCaseName ) = 0;

	/**  ���ò���������
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetDescription( const String strDes ) = 0;
	
	/**  ��ȡ��������
	 *  @param[in] 
	 *  @node 
	 *  @return ��������
	 */
	virtual String GetCaseName() const = 0;

	/**  ��ȡ����������
	 *  @param[in] 
	 *  @node 
	 *  @return ����������
	 */
	virtual String GetCaseDesc() const = 0;

	/**  ��ӡ��������Ϣ
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual void Print() = 0;

	/**  ������ָ�ԭ״̬
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual void Restore() = 0;
	/**  �Ƿ���ز�
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual bool IsRetestable() const = 0;
	/** ���ÿ��ز����� 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual void SetRetestable( const bool &bRetest ) = 0;


protected:
	/*
		��������	
	*/
	String			m_strName;			//��������
	/*
		����������	
	*/
	String			m_strDescription;	//����������
	/*
		�Ƿ���ӽ�����
	*/
	bool			m_bAdded;			
	/*
		����������	
	*/
	EmTestCaseType	m_emType;			
	/*
		������״̬	
	*/
	EmTestCaseState	m_emState;			
	/*
		�Ƿ���ز�	
	*/
	bool			m_bRetestable;		

};
/*
	������Ϣ������	
*/
class ILoadInfoMngr : public Singleton<ILoadInfoMngr>, public IObserver
{
public:
	~ILoadInfoMngr(){};
	/**��ȡ������Ϣ  
	 *  @param[in] dwBrdIdx:���ذ忨������, pBuf:������Ϣ��ŵ�bufferָ��, dwLen:ʵ�ʼ�����Ϣ�ĳ���[out]
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool GetLoadInfo( const u32 dwBrdIdx, s8 *pBuf, u32 &dwLen ) = 0;
	virtual bool Update( TMsgParam& tMsgParma ){ return true; }

};
/*
	�����������ӿ���
*/
class ITestCaseContainer
{
public:

	/**  ���/ɾ��������
	 *  @param[in] 
	 *  @node 
	 *  @return ��¡�����ָ��
	 */
		virtual bool AddTestCase( ITestCase *pTestCase ) = 0;

		virtual bool RemoveTestCase( ITestCase *pTestCase ) = 0;

		/**  ����������ȡ������
		 *  @param[in] 
		 *  @node 
		 *  @return ������
		 */
		virtual ITestCase* GetTestCase( u32 dwIdx ) = 0;

		/**  ��ղ������б�
		 *  @param[in] 
		 *  @node 
		 *  @return �Ƿ�ɹ�
		 */
		virtual bool RemoveAll() = 0;

		/**  ����������ȡ������
		 *  @param[in] ����������
		 *  @node 
		 *  @return ������ָ��
		 */
		virtual ITestCase* GetTestCase( String strCaseName ) = 0;

		/**  ��ȡ����������
		 *  @param[in] �������� 
		 *  @node 
		 *  @return ������ָ��
		 */
		virtual u32 GetCaseCount() = 0;
		
		/**  ���������ǰ������
		 *  @param[in] 
		 *  @node 
		 *  @return ��ǰ������ָ��
		 */
		virtual ITestCase* GetCurCase() = 0;
		/**  �ָ�״̬
		 *  @param[in] 
		 *  @node 
		 *  @return 
		 */
		virtual bool Restore() = 0;

		/**  ��������
		 *  @param[in] 
		 *  @node 
		 *  @return 
		 */
		virtual ~ITestCaseContainer(){} ;

	
};

/*
	�忨�ӿ���
*/
class IBoard : public IOspObContainer
{
public:

	/**  ���ð忨��������
	 *  @param[in] �Ƿ񼤻�
	 *  @node 
	 *  @return 
	 */
	virtual bool SetActivated( const bool bActivated ) = 0;

	/**  ��ȡ�忨��������
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ񼤻�
	 */
	virtual bool GetActivated()  const = 0;

	/**  ����IP��ַ
	 *  @param[in] AppId
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetIpAddr(const u32 &dwIp ) = 0;

	/**  ��ȡ�忨IP
	 *  @param[in] 
	 *  @node 
	 *  @return IP��ַ
	 */
	virtual u32 GetIpAddr() const = 0;

	/**  ����AppId
	 *  @param[in] AppId
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual	bool SetAppId( const u32 dwAppId ) = 0;

	/**  ��ȡAppId
	 *  @param[in] 
	 *  @node 
	 *  @return AppId
	 */
	virtual u32	GetAppId() const = 0;

	/**  ����E2prom��־
	 *  @param[in] E2prom��־
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual	bool SetE2promFlag( const u32 dwFlag ) = 0;

	/**  ��ȡE2prom��־
	 *  @param[in] 
	 *  @node 
	 *  @return E2prom��־
	 */
	virtual u32 GetE2promFlag()  const = 0;

		/**  ����E2prom��־
	 *  @param[in] E2prom��־
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual	bool SetE2promInfo( const u32 dwInfo ) = 0;

	/**  ��ȡE2prom��־
	 *  @param[in] 
	 *  @node 
	 *  @return E2prom��־
	 */
	virtual u32 GetE2promInfo()  const = 0;

	/**  ���ý�����Ϣ����
	 *  @param[in] ������Ϣ���й�����
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetEndMsgQue( IMsgQueMngr *MsgQue ) = 0;

	/**  ��ȡ������Ϣ����
	 *  @param[in] 
	 *  @node 
	 *  @return ������Ϣ���й�����
	 */
	virtual IMsgQueMngr* GetEndMsgQue() = 0;

	/**  ��ȡ�ָ�����������Ϣ����
	 *  @param[in] 
	 *  @node 
	 *  @return �ָ�����������Ϣ����
	 */
	virtual IMsgQueMngr* GetResMsgQue() = 0;

	/**  ���ûָ�����������Ϣ����
	 *  @param[in] �ָ�����������Ϣ���й�����
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetResMsgQue( IMsgQueMngr *MsgQue ) = 0;

	/**  ����ģʽ
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetMode(const u8 byMode) = 0;

	/**  ��ȡģʽ
	 *  @param[in] 
	 *  @node 
	 *  @return �忨ģʽ
	 */
	virtual u8   GetMode() const = 0;

	/**  ��ȡӲ���汾
	 *  @param[in] 
	 *  @node 
	 *  @return Ӳ���汾
	 */
	virtual	s8* GetHardVersion()  = 0;

	/**  ���ð忨ͼƬ�ļ�
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */

	virtual bool SetBrdPic(const String &strBrdPic ) = 0;

	/**  ��ȡ�忨ͼƬ�ļ�
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual String GetBrdPic() const = 0;

	/**  ������������
	 *  @param[in] dwCount:��������
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetEthernetCount( const u32 &dwCount ) = 0;

	/**  ��ȡ��������
	 *  @param[in] 
	 *  @node 
	 *  @return ��������
	 */
	virtual u32 GetEthernetCount() const = 0;


	/**  ����Ӳ���汾
	 *  @param[in] Ӳ���汾
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetHardVersion( const s8* pchHardVer ) = 0;

	/**  ��ȡHID
	 *  @param[in] 
	 *  @node 
	 *  @return HID
	 */
	virtual u16	GetHid() const = 0;

	/**  ����HID
	 *  @param[in] HID
	 *  @node 
	 *  @return HID
	 */
	virtual bool SetHid( const u16 &wHid ) = 0;


	/**  ��ȡPID
	 *  @param[in] 
	 *  @node 
	 *  @return PID
	 */
	virtual u16 GetPid()  const = 0;

	/**  ����PID
	 *  @param[in] PID
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetPid( const u16 &wPid ) = 0;

	/**  ��ȡ��ˮ��
	 *  @param[in] 
	 *  @node 
	 *  @return ��ˮ���ַ���ָ��
	 */
	virtual s8* GetPipeLine() = 0;

	/**  ������ˮ��
	 *  @param[in] ��ˮ�� 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetPipeLine( const s8* achPipeLine ) = 0;

	/**  ��ȡ׼����Ϣ����
	 *  @param[in] 
	 *  @node 
	 *  @return ��Ϣ����ָ��
	 */
	virtual IMsgQueMngr* GetPreMsgQue() const = 0;
	
	/**  ����׼����Ϣ����
	 *  @param[in] 
	 *  @node 
	 *  @return ��Ϣ����ָ��
	 */
	virtual bool SetPreMsgQue( IMsgQueMngr *MsgQue ) = 0;

	/**  ����ע����Ϣ
	 *  @param[in] ע����Ϣ
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetRegMsg( TBrdRegMsg RegMsg ) = 0;

	/**  �������к�
	 *  @param[in] ���к�
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetSerialNo(const s8 *pchSn) = 0;

	/**  ��ȡ���к�
	 *  @param[in] 
	 *  @node 
	 *  @return ���к��ַ���
	 */
	virtual s8* GetSerialNo() = 0;

	/**  ���ð忨Mac��ַ
	 *  @param[in] Mac��ַ
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetMac( const s8 *pchMac ) = 0;

	/**  ��ȡ�忨Mac��ַ
	 *  @param[in] 
	 *  @node 
	 *  @return Mac��ַ
	 */
	virtual s8* GetMac() = 0;

	/**  ��ȡ����汾
	 *  @param[in] 
	 *  @node 
	 *  @return ����汾
	 */
	virtual	s8* GetSoftVersion() = 0;

	/**  ��������汾
	 *  @param[in] ����汾
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetSoftVersion( const s8 *pchSoftVer ) = 0;

	/**  ������������
	 *  @param[in] �������� 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetSubMsk( const u32 dwSubMsk ) = 0;

	/**  ��ȡ��������
	 *  @param[in] 
	 *  @node 
	 *  @return ��������
	 */
	virtual u32 GetSubMsk() const = 0;

	/**  ��ȡ����
	 *  @param[in] 
	 *  @node 
	 *  @return �����ַ���ָ�� 
	 */
	virtual LPCSTR GetDate() = 0;

	/**  ��������
	 *  @param[in] �����ַ���ָ�� 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetDate( LPCSTR pchDate ) = 0;
	
	/**  ��ȡ�����ļ���
	 *  @param[in] 
	 *  @node 
	 *  @return �ļ���
	 */
	virtual String GetSysFile() const = 0;

	/**  ���������ļ���
	 *  @param[in] �ļ��� 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetSysFile( const String &strFileName ) = 0;

	/**  ��¡
	 *  @param[in] 
	 *  @node 
	 *  @return ��¡�����ָ��
	 */
	virtual IBoard* Clone() = 0;

	/**  ���ð忨����
	 *  @param[in] �忨��
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetBrdName( const String strBrdName ) = 0;
	
	/**  ��ȡ�忨����
	 *  @param[in] 
	 *  @node 
	 *  @return �忨��
	 */
	virtual String GetBrdName() const = 0;


	/**  ��ӡ�忨��Ϣ
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual void Print() = 0;

	/**  ��ȡ����������ָ��
	 *  @param[in] 
	 *  @node 
	 *  @return ����������ָ��
	 */
	virtual ITestCaseContainer* GetCaseContainer() = 0;

	/**  ���ð忨����
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetProcedure( const EmBrdProceduer emProcedure ) = 0;

	/**  �忨��ԭ����ʼ״̬
	 *  @param[in] �Ƿ񼤻�
	 *  @node 
	 *  @return 
	 */
	virtual void Restore() = 0;

	/**  ���ð忨����
	 *  @param[in] �忨�����ַ���
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetBrdDesc( const String &strDesc ) = 0;

	/**  ��ȡ�忨����
	 *  @param[in] 
	 *  @node 
	 *  @return �忨�����ַ���
	 */
	virtual String GetBrdDesc() = 0;
	/**  ������е���Ϣ����
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual void ClearMsgQue() = 0;
	/**  ��������
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual ~IBoard(){};
};


/*
	�豸�ӿ���
*/
class IDevice 
{
public:
	/**  ��¡
	 *  @param[in] 
	 *  @node 
	 *  @return ��¡�����ָ��
	 */
	virtual IDevice* Clone() = 0;

	/**  �ò�����
	 *  @param[in] ��һ��/��ǰ��
	 *  @node 
	 *  @return ��¡�����ָ��
	 */
	virtual bool SetTestCase( EmCaseSetType emType ) = 0;

	/**  ��ȡ��ǰ�Ĳ�����
	 *  @param[in] 
	 *  @node 
	 *  @return ������ָ��
	 */
	virtual	ITestCase* GetCurTestCase() = 0;
	
	/**  ��ȡ�忨ָ��
	 *  @param[in] �忨����
	 *  @node 
	 *  @return �忨ָ��
	 */
	virtual IBoard* GetBoard(u32 dwIdx) = 0;

	/**  ���ɾ���忨
	 *  @param[in] �忨����
	 *  @node 
	 *  @return �忨ָ��
	 */
	virtual bool AddBoard(IBoard *pBoard) = 0;

	/**  ��ȡ�忨����
	 *  @param[in] �忨����
	 *  @node 
	 *  @return �忨ָ��
	 */
	virtual u32	 GetBrdCount()	const		  = 0;

	virtual bool RemoveBoard(IBoard *pBoard) = 0;

	/**  ��ӡ�豸��Ϣ
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual void Print() = 0;

	/**  ��ȡ�豸��
	 *  @param[in] 
	 *  @node 
	 *  @return �豸��
	 */
	virtual String GetName() const = 0;

	/**  �����豸��
	 *  @param[in] �豸���ַ���
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetName( const String &strName ) = 0;

	/**  ��������
	 *  @param[in] �Ƿ���������
	 ������;��: 1.����������� 2.�û���ֹ 3.���豸����
	 *  @node 
	 *  @return 
	 */
	virtual void EndTest( bool bNormal = true ) = 0;

	/** �Ƿ��Ѿ����� 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual bool IsEnd() const = 0;
	/** �ָ� 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual void Restore() = 0;
	
	/**  ��������
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual ~IDevice(){};
};
/*
	UI����
*/
class IUserDataMngr : public IObserver, public Singleton<IUserDataMngr>
{
public:
	/**  ������Ϣ����
	 *  @param[in] ��Ϣ
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual		bool	Update( TMsgParam& tMsgParma )	= 0;
	
	/**  ������ʼIP
	 *  @param[in] IP
	 *  @node 
	 *  @return 
	 */
	virtual void SetSartIp( const u32 dwIp )			= 0;
 	
	/**  ��ȡ��ʼIP
	 *  @param[in] 
	 *  @node 
	 *  @return IP
	 */
	virtual u32	GetStartIp() const = 0;

	/**  ������ʼMac
	 *  @param[in] Mac��ַ�ַ���ָ��
	 *  @node 
	 *  @return 
	 */
 	virtual void SetStartMac( const s8 *pchMac ) = 0;

	/** ��ȡ��ʼMac
	 *  @param[in] 
	 *  @node 
	 *  @return Mac��ַ�ַ���ָ��
	 */
 	virtual s8*	GetStartMac() = 0;

	/**  ���ûָ�������������
	 *  @param[in] ��/��ָ���������
	 *  @node 
	 *  @return 
	 */
 	virtual void SetRestore( const bool bRes ) = 0;

	/**  ��ȡ�ָ�������������
	 *  @param[in] 
	 *  @node 
	 *  @return ��/��ָ���������
	 */
 	virtual bool GetRestore() const	= 0;

	/**  ����Tftp·��
	 *  @param[in] ·���ַ���
	 *  @node 
	 *  @return 
	 */
 	virtual void SetTftpPath( const String strPath ) = 0;

	/**  ��ȡTftp·��
	 *  @param[in] 
	 *  @node 
	 *  @return ·���ַ���
	 */
 	virtual	String GetTftpPath() const = 0;

	/**  ����UIģʽ
	 *  @param[in] UIģʽö��
	 *  @node 
	 *  @return 
	 */
 	virtual	void SetUIMode( const EmUIMode emMode ) = 0;

	/**  ��ȡUIģʽ
	 *  @param[in] 
	 *  @node 
	 *  @return UIģʽö��
	 */
 	virtual	EmUIMode GetUIMode() const = 0;

	/**  ����UI״̬
	 *  @param[in] UI״̬ö�� 
	 *  @node 
	 *  @return 
	 */
 	virtual	void SetUIState( const EmUIState emMode ) = 0;

	/**  ��ȡUI״̬  
	 *  @param[in] 
	 *  @node 
	 *  @return UI״̬ö��
	 */
 	virtual	EmUIState GetUIState() const = 0;

	/**  ��ȡ�豸ָ��
	 *  @param[in] 
	 *  @node 
	 *  @return �豸ָ��
	 */
 	virtual	IDevice* GetDevice() const = 0;

	/** ��ȡѡ�еĲ�����ָ��
	 *  @param[in] 
	 *  @node 
	 *  @return ѡ�в�����ָ��
	 */
 	virtual	ITestCase*	GetSelectedCase() const = 0;
	

	/** �����豸
	 *  @param[in] �豸��
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
 	virtual	bool SetDevice( const String strDvcName ) = 0;

	/** �����豸
	 *  @param[in] �豸ָ�� 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual	bool SetDevice( IDevice *pDevice ) = 0;


	/**  ����ѡ�в�����
	 *  @param[in] ѡ�в��������ַ���
	 *  @node 
	 *  @return 
	 */
 	virtual	bool SetSelectedCase( const String strCaseName ) = 0;


	/** ������ʾ״̬
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual	bool SetDispState( const String strState ) = 0;

	/** ��ȡ��ʾ״̬
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual	String GetDispState() const = 0;

	/** ��ȡ��ʾ�Ի����ַ���
	 *  @param[in] 
	 *  @node 
	 *  @return �ַ���
	 */
	virtual String GetNotifyDlgStr() const = 0;

	/** ������ʾ�Ի����ַ���
	 *  @param[in] �ַ���
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool SetNotifyDlgStr( const String &strNotify ) = 0;

	/** ��ȡѡ��Ի�����
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ȷ��
	 */
	virtual		bool		GetChooseDlgResult() const = 0;

	/** ����ѡ��Ի����� 
	 *  @param[in] bOk �Ƿ�ȷ�� 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual		bool		SetChooseDlgResult( const bool bOk ) = 0;

	/** ��ӳ����ն���ʾ
	 *  @param[in] �ַ���
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool AppendComDisp( LPCSTR pchContent ) = 0;

	/** ��ճ����ն���ʾ 
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool ClearComDisp() = 0;

	/** ��ȡ�����ն���ʾ�ַ��� 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual LPCSTR GetComDispStr() = 0;

	/**  ��������
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual	~IUserDataMngr(){};


};
	



typedef CNotifyUIImpl ILogic;
/*
	logic���������ڴ����͹���logic
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
	���Դ�ӡ��Ϣ�����
*/
class ILogger : public Singleton<ILogger>
{
public:
	virtual bool LogEvent( LPCTSTR pstrFormat, ... ) = 0;
	virtual ~ILogger(){}
};

/*
	�豸����
*/
class IDeviceFactory : public Singleton<IDeviceFactory>
{
public:
	/**  �����豸
	 *  @param[in] �豸���ַ���
	 *  @node 
	 *  @return �豸
	 */
	virtual IDevice* CreateDevice( const String &strName ) = 0;
};

/*
	�忨����
*/
class IBoardFactory : public Singleton<IBoardFactory>
{
public:
	/**  �����忨
	 *  @param[in] �忨���ַ���
	 *  @node 
	 *  @return �忨
	 */
	virtual IBoard* CreateBoard( const String &strName ) = 0;
	/**  ��ȡ�忨������
	 *  @param[in] �忨ָ��
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool GetBrdTestCase( IBoard *pBoard ) = 0;

	/**  ��ȡ�忨������
	 *  @param[in] �忨ָ��
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool GetBrdMsgQue( IBoard *pBoard ) = 0;

};

/*
	�������
*/
class ITestCaseFactory : public Singleton<ITestCaseFactory>
{
public:
	/**  ����������
	 *  @param[in] ���������ַ���
	 *  @node 
	 *  @return ������
	 */
	virtual ITestCase* CreateTestCase( const String &strName ) = 0;
};

/*
	��Ϣ�������
*/
class IMsgQueFactory : public Singleton<IMsgQueFactory>
{
public:
	/**  ������Ϣ����
	 *  @param[in] ���нڵ�
	 *  @node 
	 *  @return ��Ϣ���У����ļ����÷Ƿ���������0
	 */
	virtual IMsgQueMngr* CreateMsgQue( String strFileName, String strNodePath ) = 0;
};

/*
	������������������ַ�����ӳ���ϵ	
*/
class IMacroMngr : public Singleton<IMacroMngr>
{
public:
	/**  ������ַ���
	 *  @param[in] 
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool Translate( const String strMarco, u32 &dwMacro ) = 0;

	/**  ע���ӳ���ϵ
	 *  @param[in] ���ַ�������ֵ
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool RegMacro( const String strMacro, const u32 dwMacro ) = 0;
}; 

/*
	Osp App������	
*/
class IOspAppManager : public Singleton<IOspAppManager>
{
public:
	/**  ����App
	 *  @param[in] App��,App��
	 *  @node 
	 *  @return 
	 */
	virtual bool CreateApp( u16 wAppId, const s8 *pchAppName ) = 0;

	/**  ɾ��App
	 *  @param[in] App��
	 *  @node 
	 *  @return �Ƿ�ɹ�
	 */
	virtual bool KillApp( u16 wAppId ) = 0;

	/**��������  
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
Osp�Ự������	
*/
class IOspSessionMngr : public Singleton<IOspSessionMngr>
{
public:
	/**  �����Ự
	 *  @param[in] App��
	 *  @node 
	 *  @return �Ựָ��
	 */
	virtual IOspSession* CreateSession( u16 wAppId ) = 0;

	/**  ���һỰ
	 *  @param[in] App��
	 *  @node 
	 *  @return �Ựָ��
	 */
	virtual IOspSession* FindSession( u16 wAppId ) = 0;

	/**  ɾ���Ự 
	 *  @param[in] App��
	 *  @node 
	 *  @return �Ƿ�ɹ� 
	 */
	virtual bool KillSession( u16 wAppId ) = 0;

	/**  ��������
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	virtual ~IOspSessionMngr(){}
};

/*
	ע���ӳ��
*/
#define REGMACRO(Macro)  IMacroMngr::GetSingletonPtr()->RegMacro( #Macro, Macro );
/*
	ע���ӳ��(�Զ�תΪ������)
*/
#define REGHTONLMACRO(Macro) IMacroMngr::GetSingletonPtr()->RegMacro( #Macro, htonl(Macro) );

/*
	��ӡ��
*/
#define LOGEVENT ILogger::GetSingletonPtr()->LogEvent






