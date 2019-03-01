// cmsstruct.h: interface for the cmsstruct class.
//
//////////////////////////////////////////////////////////////////////
#ifndef _h_cmsstruct_h__
#define _h_cmsstruct_h__

#include "tpstruct.h"
#include "addrbook.h"
#include "cmsconst.h"
typedef struct tagCMSCnsInfo : public TCnsInfo
{
    EmCnsCallReason m_emCallReasonBk;

    tagCMSCnsInfo():TCnsInfo()
    {
        m_emCallReasonBk = EmCnsCallReason_success;
    }

    void Clear()
    {
        TCnsInfo::Clear();
        m_emCallReasonBk = EmCnsCallReason_success;
    }

    BOOL32 operator == (const tagTCnsInfo& tRhs)
    {
        return TCnsInfo::operator == ( tRhs );
	}
 

    tagCMSCnsInfo& operator = (const tagTCnsInfo& tRhs)
    {
        TCnsInfo::operator = ( tRhs );
        m_emCallReasonBk = tRhs.m_emCallReason;
        return *this;
	}
 


}TCMSCnsInfo,*PTCMSCnsInfo; 


//��������
enum EM_ConfType
{
	emConfMulti = 0,      //������
	emConfCascade,        //��������
	emConfP2P,            //��Ե����
	emConfOtherUms,       //��UMS���飨������UMS���ߣ�
	emConfUnKnown
};


//������Ϣ
typedef struct tagCMSConf : public TTPConfInfo
{
    EmCallType         m_emConfType;//��������
    
	TplArray<TCnsInfo>	    m_tplCnsList;
	TAuxMixList	            m_tAudmixList;
	TplArray<u16>	        m_tplPollList;
    
	BOOL32		        m_bStartAudmix;//�Ƿ�������
    //BOOL32              m_bCascadeConf;//�Ƿ��Ǽ�������
    TChairConfInfo      m_tCascadeConfInfo;  //����������Ϣ
    
    TTPAlias	m_tChairName;		//��ϯ����

    u16  GetChairCnsID()
    {   
        if ( strlen(m_tChairName.m_abyAlias) > 0  )
        {
            return GetCnsIDByAlias( m_tChairName.m_abyAlias ) ;
        }
        return INVALID_WORD;
    }


    tagCMSConf& operator = (const TTPConfInfo &tConf)
    {
        if(this == &tConf)
         return *this;  

        TTPConfInfo::operator = (tConf); 
        return *this;
	}
	
 
	BOOL32 operator == (const tagCMSConf& tRhs)
	{	
		return TTPConfInfo::m_wConfID == tRhs.m_wConfID;
	}
	
	void Clear()
	{  
		m_emConfType = emCallType_Invalid;
		m_tplCnsList.Clear();
	//	m_tplAudmixList.Clear();
        m_tplPollList.Clear(); 
		m_bStartAudmix = FALSE;
        //m_bCascadeConf = FALSE;
		TTPConfInfo::Clear();
        m_tCascadeConfInfo.Clear();

        ZeroMemory( &m_tChairName,sizeof(TTPAlias ) );
	}


	tagCMSConf()
    {      
		tagCMSConf::Clear();
	}

    tagCMSConf( TTPConfInfo &tConf)
    {
        tagCMSConf::Clear();
		m_emConfType = emCallType_Invalid;
        m_tCascadeConfInfo.Clear();
		m_bStartAudmix = FALSE;
        //m_bCascadeConf = FALSE;
        TTPConfInfo::operator = (tConf);
        
	}

    void SetChairInfo( TTPAlias &tChair  )
    {
	   //memcpy( &m_tChairName, &tChair,sizeof(TTPAlias) ) ;

		m_tChairName = tChair;

		m_wDefaultChairMan = GetCnsIDByAlias( m_tChairName.m_abyAlias );
	 
    }
   
    void ClearCascadeInfo()
    {
        m_tCascadeConfInfo.Clear();
		m_emConfType = emCallType_Invalid;
        //m_bCascadeConf = FALSE;
    }
 
    s8 *GetSpeakerAliars()
    {
        TCnsInfo* p = GetCnsInfoByID( m_wSpeaker );
        if ( p != NULL )
        {
            return p->m_achRoomName;
        }

        return "";
    }


    s8 *GetChairManAliars()
    {
        TCnsInfo* p = GetCnsInfoByID( m_wDefaultChairMan );
        if ( p != NULL )
        {
            return p->m_achRoomName;
        }
        
        return "";
    }


    s8 *GetDualAliars()
    {
        TCnsInfo* p = GetCnsInfoByID( m_wDual );
        if ( p != NULL )
        {
            return p->m_achRoomName;
        }
        
        return "";
    }

    //����cns�Ļ᳡ID����ȡ�����cns��Ϣ
    TCnsInfo* GetCnsInfoByID( u16 wCnsID )
    {
        s32 nCont = m_tplCnsList.Size();
        for ( s32 i = 0; i< nCont; i++ )
        {
            if ( m_tplCnsList.GetAt(i).m_wEpID == wCnsID ) 
            {
                return &(m_tplCnsList.GetAt(i));
            }
	   }
        return NULL;
    }

	//���ݻ᳡������ȡcns��Ϣ
	TCnsInfo* GetCnsInfoByAlias( s8* strAlias )
	{
		s32 nCont = m_tplCnsList.Size();
		for ( s32 i = 0; i< nCont; i++ )
		{
			if ( strcmp( m_tplCnsList.GetAt(i).m_achRoomName, strAlias) == 0 ) 
			{
				return &m_tplCnsList.GetAt(i);
			}
		}
		return NULL;
	}

   
	//����cns�Ļ᳡ID���������ڻ᳡�б�����к�
	s32 GetCnsIndexFrmCnsLst( u16 wCnsID )
	{
       s32 nCont = m_tplCnsList.Size();
	   for ( s32 i = 0; i< nCont; i++ )
	   {
		   if ( m_tplCnsList.GetAt(i).m_wEpID == wCnsID) 
		   {
			   return i;
		   }
	   }

	   return -1;
	}


    //����cns������ȡcns��ID
    u16 GetCnsIDByAlias( s8* strAlias )
    {
        s32 nCont = m_tplCnsList.Size();
        for ( s32 i = 0; i< nCont; i++ )
        {
            if ( strcmp( m_tplCnsList.GetAt(i).m_achRoomName, strAlias) == 0 ) 
            {
                return m_tplCnsList.GetAt(i).m_wEpID;
            }
	   }
        
        return INVALID_WORD;
    }

 
   TCnsInfo *GetCnsInfoFrmCnsLst( u16 wCnsID )
   {
       s32 nCont = m_tplCnsList.Size();
       for ( s32 i = 0; i< nCont; i++ )
       {
           if ( m_tplCnsList.GetAt(i).m_wEpID == wCnsID) 
           {
               return &m_tplCnsList.GetAt(i);
           }
	   }
       return NULL;
   }
 

   //����cns�Ļ᳡ID���������ڻ����б�����к�
	s32 GetCnsIndexFrmAuxLst( u16 wCnsID )
	{
		//s32 nCont = m_tplAudmixList.Size();
		for ( u16 i = 0; i< TP_CONF_MAX_AUDMIXNUM; i++ )
		{
			if ( m_tAudmixList.m_awList[i] == wCnsID) 
			{
				return i;
			}
		}
		
		return -1;
	}

	//����cns�Ļ᳡ID������������ѯ�б�����к�
	s32 GetCnsIndexFrmPollLst( u16 wCnsID )
	{
		s32 nCont = m_tplPollList.Size();
		for ( s32 i = 0; i< nCont; i++ )
		{
			if ( m_tplPollList.GetAt(i) == wCnsID) 
			{
				return i;
			}
		}
		
		return -1;
	}

	BOOL32 IsCnsInConf( s8* achRoomName )
	{
		for ( int i = 0; i < m_tplCnsList.Size(); i++ )
		{
			if ( strcmp( achRoomName, m_tplCnsList.GetAt(i).m_achRoomName ) == 0 )
			{
				if ( m_tplCnsList.GetAt(i).m_bOnline )
				{
					return TRUE;
				}
				else
				{
					return FALSE;
				}
			}
		}
		return FALSE;
	}
	
	BOOL32 IsStartAudMix()
	{
		return m_bStartAudmix;
	}

}TCMSConf,*PTCMSConf;


//����ģ����Ϣ
typedef struct tagCMSConfTemplate : public TTPConfTemplate
{  

    
    tagCMSConfTemplate& operator =  ( TTPConfTemplate &tRhs )
    {
       
        TTPConfTemplate::operator = (tRhs);
        m_wID = tRhs.m_wID;					//ģ��ID
        m_dwTimeID= tRhs.m_dwTimeID;		
        return *this;
   }

    
    tagCMSConfTemplate& operator = (const tagCMSConfTemplate& tRhs)
    {
        if(this == &tRhs)
            return *this; 
        		
        TTPConfTemplate::operator = (tRhs); 

        m_wID = tRhs.m_wID;					//ģ��ID
        m_dwTimeID= tRhs.m_dwTimeID; 
        return *this;
	}


/**
* ����:  ����һ������ģ��
* @param [in] temp	 Ҫ������ģ�� 
* @return 
    */  
    void  InvalidConfTemp()   
    { 
        Clear();
        m_tTurnList.m_wInterval = 20;
        m_wID = INVALID_WORD;
    }

  //����cnsID ��ȡ���ַ��Ϣ
    TEpAddr * GetCnsAddrByID( u16 wCnsID  )
    {
        if ( wCnsID == INVALID_WORD )
        {
            return NULL;
         }

        for ( u16 i = 0; i < m_atEpList.m_wNum; i++ )
        {
            if ( m_atEpList.m_tCnsList[i].m_wEpID == wCnsID )
            {
                return &m_atEpList.m_tCnsList[i];
            }
        }
        return NULL;
    }


 
 
   //��ӻ᳡�б�
    u16 AddConfEp( TTpCallAddr tCallAddr )
    {   
        u16 wRe = NO_ERROR;
        EmConfAddEpRet emRe = this->m_atEpList.Add( tCallAddr );
       
        switch ( emRe )
        { 
        case TP_ConfAddEpRet_Success: 
            {
                int nMaxIndex = this->m_atEpList.m_wNum - 1 ;
                if ( nMaxIndex > 0 )
                {
                    this->m_atEpList.m_tCnsList[ nMaxIndex].m_wEpID = this->m_atEpList.m_tCnsList[ nMaxIndex - 1 ].m_wEpID + 1;
                } 
            } 
            break;
        case TP_ConfAddEpRet_MaxNum:
            wRe = ERR_CMS_CNS_MAX_NUM ;
            break;
        case TP_ConfAddEpRet_AliasReapeat: 
            wRe = ERR_CMS_CNS_ALIAS_EXIST ;
            break;
        case TP_ConfAddEpRet_ParamError: 
            wRe = ERR_CMS_CNS_ALIARS_EMPTY ;
            break;
        default: 
            wRe = ERR_CMS_CNS_UNKNOW ;
            break;
         }
        return wRe;
    }
/*
	u16 AddConfEp(EmTpAliasType emType, s8* pszEpAlias)
    {   
        u16 wRe = NO_ERROR;
        EmConfAddEpRet emRe = this->m_atEpList.Add(emType,pszEpAlias);
		
        switch ( emRe )
        { 
        case TP_ConfAddEpRet_Success: 
            {
                int nMaxIndex = this->m_atEpList.m_wNum - 1 ;
                if ( nMaxIndex > 0 )
                {
                    this->m_atEpList.m_tCnsList[ nMaxIndex].m_wEpID = this->m_atEpList.m_tCnsList[ nMaxIndex - 1 ].m_wEpID + 1;
                } 
            } 
            break;
        case TP_ConfAddEpRet_MaxNum:
            wRe = ERR_CMS_CNS_MAX_NUM ;
            break;
        case TP_ConfAddEpRet_AliasReapeat: 
            wRe = ERR_CMS_CNS_ALIAS_EXIST ;
            break;
        case TP_ConfAddEpRet_ParamError: 
            wRe = ERR_CMS_CNS_ALIARS_EMPTY ;
            break;
        default: 
            wRe = ERR_CMS_CNS_UNKNOW ;
            break;
		}
        return wRe;
    }*/

    //ɾ��һ��cns�᳡����ѯ�ͻ����б�Ҫͬ������
    u16 DeletConfEp( u16 wCnsID )
    {    
        if ( wCnsID == INVALID_WORD )
        {
            return ERR_CMS_CNSID_INVALID;
         }

        for ( u16 i = 0; i < m_atEpList.m_wNum; i++ )
        {
            if ( m_atEpList.m_tCnsList[i].m_wEpID == wCnsID )
            {    
                //ɾ��cns�б��и���
                this->m_atEpList.m_tCnsList[ i ].m_wEpID = INVALID_WORD;
                ZeroMemory(&this->m_atEpList.m_tCnsList[ i ].m_tEpAddr.m_tAlias,sizeof(this->m_atEpList.m_tCnsList[ i ].m_tEpAddr.m_tAlias));
                for ( u16 j = i ; j< this->m_atEpList.m_wNum -1 ; j++ )
                {
                    this->m_atEpList.m_tCnsList[ j ] = this->m_atEpList.m_tCnsList[ j +1 ]; 
                } 
                
                this->m_atEpList.m_tCnsList[ m_atEpList.m_wNum - 1 ].m_wEpID = INVALID_WORD;
                ZeroMemory(&this->m_atEpList.m_tCnsList[ m_atEpList.m_wNum - 1 ].m_tEpAddr.m_tAlias,sizeof(this->m_atEpList.m_tCnsList[ m_atEpList.m_wNum - 1 ].m_tEpAddr.m_tAlias));
                m_atEpList.m_wNum --;

                 //�������б����Ƿ������cns����������ͬ��ɾ��
                s32 nIndex = GetCnsIndexFrmAudMixLst( wCnsID );
                if ( nIndex > -1 )
                {
                    this->m_atAuxMixList.m_awList[ nIndex ] = INVALID_WORD;
                    for ( u16 j = nIndex ; j< TP_CONF_MAX_AUDMIXNUM - 1 ; j++ )
                    {
                       this->m_atAuxMixList.m_awList[ j ] = this->m_atAuxMixList.m_awList[ j +1 ]; 
                    } 
                    this->m_atAuxMixList.m_awList[ TP_CONF_MAX_AUDMIXNUM -1 ] = INVALID_WORD;
                    
                }

                 //�����ѯ�б����Ƿ������cns����������ͬ��ɾ��
                nIndex = GetCnsIndexFrmPollLst( wCnsID );
                if ( nIndex > -1 )
                {  
                    this->m_tTurnList.m_awList[ nIndex ] = INVALID_WORD;
                    for ( u16 j = nIndex ; j< this->m_tTurnList.m_wNum -1 ; j++ )
                    {
                        this->m_tTurnList.m_awList[ j ] = this->m_tTurnList.m_awList[j +1 ]; 
                    } 
                    this->m_tTurnList.m_awList[ this->m_tTurnList.m_wNum -1] = INVALID_WORD;
                    this->m_tTurnList.m_wNum --;
                }

                return NO_ERROR;
            }
        }

        return ERR_CMS_NOT_FIND;
    }
    //��ջ᳡�б�
    u16 ClearConfEpLst()
    {
       if (m_atEpList.m_wNum != 0 )
       {  
          ZeroMemory(&m_atEpList,sizeof(TEpAddrList));
          ClearPollLst();
          ClearAudmixLst();
       }
       return NO_ERROR;
    }

    //������ѯ�б���cns
    u16 UpPollCns( u16 wEpID )
    {
        if ( wEpID == INVALID_WORD )
        {
            return ERR_CMS_CNSID_INVALID;
         }

       s32 nIndex =  GetCnsIndexFrmPollLst(wEpID);
       if ( nIndex < 0 )
       {
           return ERR_CMS_CNS_UNEXIST;
        }
       
       if ( nIndex == 0 )
       {
           return NO_ERROR;
       }
 
       m_tTurnList.m_awList[nIndex] = m_tTurnList.m_awList[nIndex -1] ;
       m_tTurnList.m_awList[nIndex -1] = wEpID;
       return NO_ERROR;
    }
    
    //������ѯ�б���cns
    u16 DownPollCns( u16 wEpID )
    {
        if ( wEpID == INVALID_WORD )
        {
            return ERR_CMS_CNSID_INVALID;
         }

        s32 nIndex =  GetCnsIndexFrmPollLst(wEpID);
        if ( nIndex < 0 )
        {
            return ERR_CMS_CNS_UNEXIST;
        }
        
        if ( nIndex == m_tTurnList.m_wNum-1 )
        {
            return NO_ERROR;
        }
        
        m_tTurnList.m_awList[nIndex ] = m_tTurnList.m_awList[nIndex + 1] ;
        m_tTurnList.m_awList[nIndex + 1] = wEpID;
        return NO_ERROR;
    }

    //�ö���ѯ�б���ĳ��cns
    u16 TopPollCns( u16 wEpID )
    {
        if ( wEpID == INVALID_WORD )
        {
            return ERR_CMS_CNSID_INVALID;
         }

        s32 nIndex =  GetCnsIndexFrmPollLst(wEpID);
        if ( nIndex < 0 )
        {
            return ERR_CMS_CNS_UNEXIST;
         }
        
        if ( nIndex == 0 )
        {
            return NO_ERROR;
        }
         
        for ( u16 i = nIndex; i> 0; i--)
        {
           m_tTurnList.m_awList[i] = m_tTurnList.m_awList[i -1];
        }
        m_tTurnList.m_awList[0] = wEpID;
        return NO_ERROR;
    }

    //�õ���ѯ�б���ĳ��cns
    u16 BottomPollCns( u16 wEpID )
    {
        if ( wEpID == INVALID_WORD )
        {
            return ERR_CMS_CNSID_INVALID;
         }

        s32 nIndex =  GetCnsIndexFrmPollLst(wEpID);
        if ( nIndex < 0 )
        {
            return ERR_CMS_CNS_UNEXIST;
         }
        
        if ( nIndex == m_tTurnList.m_wNum-1 )
        {
            return NO_ERROR;
        }
         
        for ( u16 i = nIndex; i < m_tTurnList.m_wNum-1; i++)
        {
            m_tTurnList.m_awList[i] = m_tTurnList.m_awList[i + 1];
        }
        m_tTurnList.m_awList[m_tTurnList.m_wNum-1] = wEpID;
        return NO_ERROR;
    }

    //����ѯ�б����һ��cns
     u16 AddPollCns(u16 wEpID)
     {		 
        if ( wEpID == INVALID_WORD )
         {
             return ERR_CMS_CNSID_INVALID;
         }
        s32 nIndex = GetCnsIndexFrmPollLst( wEpID );
        if ( nIndex >= 0 )
        {
            return ERR_CMS_CNS_ALIAS_EXIST;
        }
       
        if ( TP_CONF_MAX_TURNNUM  == m_tTurnList.m_wNum )
        {
            return ERR_CMS_CNS_MAX_NUM;
        }

        m_tTurnList.m_awList[m_tTurnList.m_wNum] = wEpID;
        m_tTurnList.m_wNum ++;
        return NO_ERROR;

//         for (u16 wIndex = 0; wIndex < TP_CONF_MAX_TURNNUM; ++wIndex)
//         {
//             if (!VALID_HANDLE(m_tTurnList.m_awList[wIndex]))
//             {
//                 m_tTurnList.m_awList[wIndex] = wEpID;
//                 m_tTurnList.m_wNum ++;
//                 return NO_ERROR;
//             }
//         }
      
	}



     //����ѯ�б����һ��cns
     u16 AddPollAllCns( )
     {	 
         if ( TP_CONF_MAX_TURNNUM  == m_tTurnList.m_wNum )
         {
             return ERR_CMS_CNS_MAX_NUM;
         }

         int cont = m_atEpList.m_wNum;
         for ( int i = 0; i<cont && TP_CONF_MAX_TURNNUM  > m_tTurnList.m_wNum; i++  )
         {
             //��ϯ��������ѯ
             if ( m_atEpList.m_tCnsList[i].m_wEpID == m_wDefaultChairMan )
             {
                 continue;
             }

             m_tTurnList.m_awList[m_tTurnList.m_wNum] = m_atEpList.m_tCnsList[i].m_wEpID;
             m_tTurnList.m_wNum ++;
         }
         
        
     
         return NO_ERROR;
      
	}


     //��ѯ�б�ɾ��һ��cns
     u16 DeletePollCns(u16 wEpID)
     {  
         if ( wEpID == INVALID_WORD )
         {
            return ERR_CMS_CNSID_INVALID;
         }

         s32 nIndex = GetCnsIndexFrmPollLst( wEpID );
         if ( nIndex < 0 )
         {
             return ERR_CMS_CNS_UNEXIST;
         }

         m_tTurnList.m_awList[nIndex] = INVALID_WORD;
         for ( u16 wIndex = nIndex; wIndex < m_tTurnList.m_wNum -1; wIndex ++)
         {
             m_tTurnList.m_awList[wIndex] = m_tTurnList.m_awList[wIndex+1];
         }
         m_tTurnList.m_wNum -= 1;
         m_tTurnList.m_awList[m_tTurnList.m_wNum] = INVALID_WORD;
         return NO_ERROR;
     }
  

     //�����ѯ�б�
     u16 ClearPollLst()
     { 
         if ( m_tTurnList.m_wNum > 0 )
         {  
             m_tTurnList.m_wNum = 0;
              
         }
        
        return NO_ERROR;
     }

     //��ջ����б�
     u16 ClearAudmixLst()
     { 
        memset(&m_atAuxMixList,sizeof(TAuxMixList),INVALID_WORD); 
        return NO_ERROR;

     }

    //����cns�Ļ᳡ID���������ڻ����б�����к�
    s32 GetCnsIndexFrmAudMixLst( u16 wCnsID )
    {
        if ( wCnsID == INVALID_WORD )
        {
            return -1;
        }

        for ( u16 i = 0; i< TP_CONF_MAX_AUDMIXNUM; i++ )
        {
            if ( this->m_atAuxMixList.m_awList[i] == wCnsID) 
            {
                return i;
            }
        }
        
        return -1;
    }
    
    //����cns�Ļ᳡ID������������ѯ�б�����к�
    s32 GetCnsIndexFrmPollLst( u16 wCnsID )
    {  
        if ( wCnsID == INVALID_WORD )
        {
            return -1;
        }
        s32 nCont = this->m_tTurnList.m_wNum;
        for ( s32 i = 0; i< nCont; i++ )
        {
            if ( this->m_tTurnList.m_awList[i] == wCnsID) 
            {
                return i;
            }
        }
        
        return -1;
	}


    s8 *GetChairManAliars()
    {
        TEpAddr * p = GetCnsAddrByID( m_wDefaultChairMan );
        if ( p != NULL )
        {
			return p->m_tEpAddr.m_tAlias.m_abyAlias;
      //      return p->m_tAlias.m_abyAlias;
        }
        
        return "";
    }


}TCMSConfTemplate,*PTCMSConfTemplate;


//����Ϣ
typedef struct tagScreenInfo
{
	u8  byScreenID;
	s8  achCnsName[TP_MAX_ALIAS_LEN_CNC+1];
	EmTPPosStatus  emScreenState;
	EMPosPic emPosPic;    

	tagScreenInfo()
	{
		byScreenID = 0;		
		ZeroMemory( achCnsName, sizeof(achCnsName) );
		emScreenState = emPosInAcitve;
		emPosPic = emPic_Invalid;
	}
} TScreenInfo, *PTScreenInfo;
 

//��ϯ��Ϣ
typedef struct tagSeatInfo{
	u8 bySeatID;              
	BOOL32 bSpokesMan;
	
	tagSeatInfo()
	{
          bySeatID = 0;
          bSpokesMan = FALSE;
	}
} TSeatInfo, *PTSeatInfo;



 //�����еĻ᳡״̬ 
enum EM_CnsState{
    emCnsStateMute = 0x1,         //����  �������Ƶĵ�һλ��0 ��ʾ��������1��ʾ����
    emCnsStateSilence = 0x2,      //  �����������Ƶĵڶ�λ��0 ��ʾ�Ǿ�����1��ʾ����
    emCnsStateDbFolw = 0x4,     // ˫�� ,   �����Ƶĵ���λ��0 ��ʾ�� ˫�� ��1��ʾ ˫�� 
};

//RoomInfo : CNS
typedef struct tagTCnsInfoEx :public TCnsInfo
{
    DWORD dwIndex;    //��commeninterface���У��ýṹ��Ĵ洢���
    BOOL32 bMute;       //�Ƿ����� 
    BOOL32 bSilence;   // �Ƿ���
    BOOL32 bDbFlow;  //�Ƿ�˫�� 
   
    BOOL32 operator ==( tagTCnsInfoEx & cnsInfo )
    {   
        BOOL32 re = FALSE;
        if ( this->dwIndex == cnsInfo.dwIndex && 
               (TCnsInfo::operator == (cnsInfo) ) )
        {
            re = TRUE;
        }
        return re;
    }


    tagTCnsInfoEx()
    {
        TCnsInfo::Clear();
       dwIndex = 0;
       bMute = FALSE;
       bSilence = FALSE;
       bDbFlow = FALSE;
    }

}TCnsInfoEx, *PTCnsInfoEx;


typedef struct tagTPAddrInfo
{
	u32  dwEntryIdx;                               // ��Ŀ����
	u32  dwInGroupIdx;                             // �������� 
	s8   achEntryName[TP_MAX_ALIAS_LEN_CNC+1];
	s8   achE164[TP_MAX_ALIAS_LEN_CNC+1];
    BOOL              bOnLine;                     // �Ƿ�����
	EmTPEndpointType  m_emEndpointType;		       // ��ַ����

	tagTPAddrInfo()
	{ 
		SetNull();
	}

	BOOL32 operator ==( const tagTPAddrInfo & tInfo )
    {   
		if ( strcmp( achEntryName, tInfo.achEntryName ) == 0 && dwEntryIdx == tInfo.dwEntryIdx &&  dwInGroupIdx == tInfo.dwInGroupIdx )
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
    }

	void SetNull()
	{
		dwEntryIdx = INVALID_INDEX;
		dwInGroupIdx = INVALID_INDEX;
		memset( achEntryName, 0, sizeof(achEntryName) );
		memset( achE164, 0, sizeof(achE164) );
        bOnLine = FALSE;
		m_emEndpointType = emTPEndpointTypeUnknown;
	}

	BOOL32 IsNull()
	{
		if ( dwEntryIdx == INVALID_INDEX )
		{
			return TRUE;
		}
		return FALSE;
	}
}TAddrInfo;

typedef struct tagTPGroupInfo
{
	u32 dwGroupIdx;
	u32 dwInGroupIdx;                              // �������� 
	s8  achGroupName[TP_MAX_ALIAS_LEN_CNC+1];          // ����
	s32 nEntryNum;                                 // ��Ŀ����
	u32 adwEntryIdx[MAXNUM_ENTRY_TABLE];	       // ����ն�����
	s32 nDownGroupNum;                             // �¼������
	tagTPGroupInfo()
	{ 
		SetNull();
	}

	BOOL operator ==( const tagTPGroupInfo & tInfo )
	{
		if ( strcmp( achGroupName, tInfo.achGroupName ) == 0 && dwGroupIdx == tInfo.dwGroupIdx )
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}

	void SetNull()
	{
		dwGroupIdx = INVALID_INDEX;
		dwInGroupIdx = INVALID_INDEX;
		memset( achGroupName, 0, sizeof(achGroupName) );
		nEntryNum = 0;
		memset( adwEntryIdx, 0, sizeof(adwEntryIdx) );
		nDownGroupNum = 0;
	}
	BOOL32 IsNull()
	{
		if ( dwGroupIdx == INVALID_INDEX )
		{
			return TRUE;
		}
		return FALSE;
	}
}TGroupInfo;

enum EM_ItemType
{
	emEntryItem = 0,
	emGroupItem,
};

typedef struct tagAddrItem
{
	EM_ItemType emItemType;
	TAddrInfo   tAddrInfo;
	TGroupInfo  tGroupInfo;
	CString     strImg;
	CString     strNameLetter;
	
	tagAddrItem()
	{ 
		emItemType = emEntryItem;
		strImg.Empty();
		strNameLetter.Empty();
	}

	BOOL operator ==( const tagAddrItem & tItem )
    {
		if ( emItemType == tItem.emItemType )
		{
			if ( emItemType == emEntryItem )
			{
				return tAddrInfo == tItem.tAddrInfo;
			}
			else
			{
				return tGroupInfo == tItem.tGroupInfo;
			}
		}
		else
		{
			return FALSE;
		}
	}

	BOOL32 IsNull()
	{
		if ( emItemType == emEntryItem )
		{
			return tAddrInfo.IsNull();
		}
		else
		{
			return tGroupInfo.IsNull();
		}
	}

	void SetNull()
	{
		emItemType = emEntryItem;
		tAddrInfo.SetNull();
		tGroupInfo.SetNull();
		strImg.Empty();
		strNameLetter.Empty();
	}

	BOOL IsSameName( tagAddrItem& tItem )
	{
		if ( emItemType == tItem.emItemType )
		{
			if ( emItemType == emEntryItem )
			{
				//��Ŀ���ƺ�E164��ȫ��һ�������
				if ( strcmp( tAddrInfo.achEntryName, tItem.tAddrInfo.achEntryName ) == 0 
					&& strcmp( tAddrInfo.achE164, tItem.tAddrInfo.achE164 ) == 0 )
				{
					return TRUE;
				}
				else
				{
					return FALSE;
				}		
			}
			else
			{
				return strcmp( tGroupInfo.achGroupName, tItem.tGroupInfo.achGroupName ) == 0;
			}
		}
		else
		{
			return FALSE;
		}
	}
	
}TAddrItem;


enum EM_AddrShowState
{
    emShowAllAddr = 0,
    emShowGroup,
    emShowOnline,
    emShowOffline,
}; 

typedef struct tagConfCallEpAddrList 
{
    u16 m_wConfID;
    TEpAddrList m_tEpAdrLst;
    tagConfCallEpAddrList()
    { 
        m_wConfID = INVALID_WORD;
    }

    VOID Clear()
    {
        m_wConfID = INVALID_WORD;
        ZeroMemory( &m_tEpAdrLst, sizeof(TEpAddrList));
    }

} TConfCallEpAddrList;


//����ǽ��Ϣ
typedef struct tagCmsTvwInfo: public TTPHduRegInfo
{  
    BOOL bCodeStream; 

    tagCmsTvwInfo():TTPHduRegInfo()
    { 
       bCodeStream = TRUE;
    }

    void ClearCnsInfo()
    { 
        ZeroMemory( m_achAlias, sizeof(m_achAlias) ) ;
        
    }

    u16 SetCnsInfo(const s8 *pCnsAliars  )
    {
        if ( pCnsAliars == NULL )
        {
            return ERR_CMS_CNS_ALIARS_EMPTY;
        }
       
        _snprintf( m_achAlias, sizeof(m_achAlias), "%s",pCnsAliars );  
        return NO_ERROR; 
    }

    tagCmsTvwInfo &operator = ( TTPHduRegInfo & tHdu)
    {
        TTPHduRegInfo::operator = (tHdu);
//         _snprintf( m_achAlias, sizeof(m_achAlias), "%s",tHdu.m_achAlias );
//          m_dwChannelHandle = tHdu.m_dwChannelHandle;
//          m_bIsOnline = tHdu.m_bIsOnline;	//HDU�Ƿ�ע��
//          m_dwIpAddr = tHdu.m_dwIpAddr;		//����IP��ַ	,   ������
//          m_wStartPort = tHdu.m_wStartPort;	//������ʼ���ն˿�, ������  
 
         return *this;
    } 

   
   
    
    BOOL32 operator == (const tagCmsTvwInfo& tRhs)
    {	
        return  m_dwChannelHandle == tRhs.m_dwChannelHandle;
	}

}TCmsTvwInfo;

//��¼��Ϣ
typedef struct tagLoginInfo
{
	u32     dwIp;
	u16     nPort;
	CString  strName;
	CString  strPswd;

	tagLoginInfo()
	{
		dwIp = 0;
		nPort = 0;
		strName = "";
		strPswd = "";
	}
}TLoginInfo;

//����������Ϣ,ϵͳ����
typedef struct tagLockScreenInfo
{
	bool   bOpen;
	CString  strPswd;
	CString  strSysName;

	tagLockScreenInfo()
	{
		bOpen = false;
		strPswd.Empty();
		strSysName.Empty();
	}
}TLockScreenInfo;

//������MainMenu��Ŀ��Ϣ
typedef struct tagConfMenuInfo
{
	CString strName;	            //����
	int     nIndex;                 //��Ŀ����
	CString strItemType;            //��Ŀ����
	CString strItemFunc;            //��Ŀ�����¼�
	CString strImgFolder;           //��ĿͼƬ·��
	BOOL    bShow;                  //�Ƿ�Ӧ����ʾ
	BOOL    bSetShow;               //�Ƿ�����Ϊ��ʾ

	tagConfMenuInfo()
	{
		nIndex = 0;
		bShow = TRUE;
		bSetShow = TRUE;
		strName.Empty();
		strItemType.Empty();
		strItemFunc.Empty();
		strImgFolder.Empty();
	}
}TConfMenuInfo;

/*
enum Em_ImgSchm{
    emImgSchm0,
	emImgSchm1,
	emImgSchm2,
	emImgSchm3,
	emImgSchm4
};
*/

typedef struct tagDualSrcInfo
{
    vector<TVgaInfo>  vctVgaInfo;
    EmVgaType         emDefaultType;
    EmVgaType         emCurrentType;

    tagDualSrcInfo()
    {
        Clear();
    }

    void Clear()
    {
        vctVgaInfo.clear();
        emDefaultType = emVgaType001;
        emCurrentType = emVgaType001;
    }

}TDualSrcInfo;

enum EM_BrdOptType
{
	em_UnKnow_Ret,
	em_Add_Ret,
	em_Modify_Ret,
	em_Del_Ret
};

typedef struct tagTBrdOptRet
{
	EM_BrdOptType emBrdOptType;
	EmTpBoardRet emTpBoardRet;

	tagTBrdOptRet()
	{
		Clear();
	}

	void Clear()
	{
		emBrdOptType = em_UnKnow_Ret;
		emTpBoardRet = emTP_Board_UnKonw;
	}

}TBrdOptRet;

typedef struct tagTTvwBrdOptRet
{
	EM_BrdOptType emBrdOptType;
	EmModifyHduRet emTvwModifyHduRet;
	
	tagTTvwBrdOptRet()
	{
		Clear();
	}
	
	void Clear()
	{
		emBrdOptType = em_UnKnow_Ret;
		emTvwModifyHduRet = em_hdu_brd_no_cfg;
	}
	
}TTvwBrdOptRet;


typedef struct tagTvwStyleInfo   //��ŵ���ǽ���ǰ���м�����
{
	s32 nCol;					//������
	s32 nRow;					//������
	s32 nKey;					//��ǰѡ��λ��
	TTPName tChanName;			//ͨ����
	THduStyleUnit tHduStyleUnit;
	
	tagTvwStyleInfo()
	{
		Clear();
	}
	
	void Clear()
	{
		nCol = 1;
		nRow = 1;
		nKey = -1;
		tChanName.Clear();
		memset( this, 0, sizeof( tagTvwStyleInfo ) );
		tHduStyleUnit.Clear();
	}
	
	tagTvwStyleInfo& operator =(const tagTvwStyleInfo& tTvwStyleInfo)
	{
		if ( this == &tTvwStyleInfo )
		{
			return *this;
		}
		
		nCol = tTvwStyleInfo.nCol;
		nRow = tTvwStyleInfo.nRow;
		nKey = tTvwStyleInfo.nKey;
		tChanName.SetAlias( tTvwStyleInfo.tChanName.m_abyAlias );
		tHduStyleUnit = tTvwStyleInfo.tHduStyleUnit;
		
		return *this;
	}
	
}TTvwStyleInfo,*PTTvwStyleInfo;

typedef struct tagUmsToolFile   //���������ļ��ṹ
{
	s8 chFileName[_MAX_FNAME];
	s8 chFileFullPath[MAX_PATH];
	u64 nFileSize;
	
	tagUmsToolFile()
	{
		Clear();
	}
	
	void Clear()
	{
		memset( this, 0, sizeof( tagUmsToolFile ) );
	}
	
	tagUmsToolFile& operator =(const tagUmsToolFile& tTvwStyleInfo)
	{
		if ( this == &tTvwStyleInfo )
		{
			return *this;
		}

		strncpy( chFileName, tTvwStyleInfo.chFileName, _MAX_FNAME );
		strncpy( chFileFullPath, tTvwStyleInfo.chFileFullPath, MAX_PATH );
		nFileSize = tTvwStyleInfo.nFileSize;
		
		return *this;
	}
	
}TUmsToolFile,*PTUmsToolFile;


//�᳡�ͻ����¼����Ϣ
typedef struct tagUmcRecInfo : public TConRecState
{
	s8  m_achName[TP_MAX_NAME_LEN+1];		//�����᳡����

	tagUmcRecInfo& operator = (const TConRecState &tConRecState)
    {
        if(this == &tConRecState)
			return *this;  
		
        TConRecState::operator = (tConRecState); 
        return *this;
	}
	
	tagUmcRecInfo()
	{
		Clear();
	}
	
	void Clear()
	{
		memset( m_achName, 0, TP_MAX_NAME_LEN+1 );
	}
	
}TUmcRecInfo;

//������Ϣ(����¼�������Ϣ)
typedef struct tagUmcConfInfo : public TCMSConf
{
	vector<TUmcRecInfo> m_vecTRecInfo;		//�᳡�ͻ����¼����Ϣ
	TConfPlayStatus m_tConfPlayStatus;		//������Ϣ

	tagUmcConfInfo( TCMSConf &tCMSConf )
    {
        tagUmcConfInfo::Clear();

        TCMSConf::operator = (tCMSConf);
	}

	tagUmcConfInfo()
	{
		Clear();
	}
	
	void Clear()
	{
		m_vecTRecInfo.clear();
		m_tConfPlayStatus.Clear();
		TCMSConf::Clear();
	}

}TUmcConfInfo;

//������ʽ
typedef struct tagTTPCallSerFormat
{
	u16         m_byFrameRate; 
	EmTpVideoResolution  emRes; 
	EmTpVideoQualityLevel emTpVideoQualityLevel; //HP,BP
	public:
		tagTTPCallSerFormat()
		{ 
			Clear();
		}
		void Clear()
		{
			memset( this ,0 ,sizeof( struct  tagTTPCallSerFormat ) );
			emTpVideoQualityLevel = emTPH264HP;
		}
		
}TTPCallSerFormat;

//��������(��������)
typedef struct tagRegAlias : public TTPAlias
{
	EmTPEndpointType	m_emEndpointType;

	tagRegAlias()
	{
		Clear();
	}
	void Clear()
	{
		m_emEndpointType = emTPEndpointTypeUnknown;
	}
	
	tagTTPAlias& operator = (const TTPAlias& tAlias)
	{
		if (this == &tAlias)
		{
			return *this;
		}
		TTPAlias::operator = (tAlias); 
		return *this;
	}
}TRegAlias;

//��������(��������)
typedef struct tagAliasEx
{
	EmTPEndpointType	m_emEndpointType;
	vector<TTPAlias>    m_vecTTPAlias;
	
	tagAliasEx()
	{
		Clear();
	}
	
	void Clear()
	{
		m_emEndpointType = emTPEndpointTypeUnknown;
		m_vecTTPAlias.clear();
	}
	
	//shishi
	BOOL32 operator == (tagAliasEx& tRhs)
    {	
		BOOL32 bFind = FALSE;
		
		vector<TTPAlias>::iterator it = m_vecTTPAlias.begin();
		for ( ; it != m_vecTTPAlias.end(); it++ )
		{
			vector<TTPAlias>::iterator itRhs = tRhs.m_vecTTPAlias.begin();
			for ( ; itRhs != tRhs.m_vecTTPAlias.end(); itRhs++ )
			{
				if ( it->m_byType == itRhs->m_byType
					&& ( strcmp( it->m_abyAlias, itRhs->m_abyAlias ) == 0 ) )
				{
					bFind = TRUE;
				}
			}
		}
		
        return  bFind;
	}
	
}TAliasEx;
#endif 
