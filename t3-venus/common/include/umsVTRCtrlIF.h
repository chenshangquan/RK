/*****************************************************************************
ģ����      : umstool����ά������
�ļ���      : umsVTRCtrlIF.h
����ļ�    : 
�ļ�ʵ�ֹ���: ums¼��������в���
����        : ʯ��
�汾        : V1.0  Copyright(C) 2013-2014 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2013/3/5    1.0         ʯ��	      ����
******************************************************************************/
#if !defined(UMCLIB_VTRCTRLIF_H)
#define UMCLIB_VTRCTRLIF_H
#include "kdvdispevent.h"
#include "tpstruct.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CUmsVTRCtrlIF :public  CKdvDispEvent  
{
public:
	/**
    * ����:	 	        �������¼�������
	* @param [in]       ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   ev_VTRAdd_req
	*/
	virtual u16  VTRAddReq( const TVcrCfg& tVTRCfg ) = 0;

    /**
    * ����:	 	        �����޸�¼�������
	* @param [in]       ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   ev_VTRMdy_req
	*/
	virtual u16  VTRModifyReq( const TVcrCfg& tVTRCfgOld, const TVcrCfg& tVTRCfgNew ) = 0;

    /**
    * ����:	 	        ����ɾ��¼�������
	* @param [in]       ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   ev_VTRDel_req
	*/
	virtual u16  VTRDeleteReq( const TVcrCfg& tVTRCfg ) = 0;

	/** 
	* ����  ��ȡ¼�����Ϣ
	* @param [in]  
	* @return  
	*/
	virtual u16 GetUmsVTRData( TVcrCfg& tVTRCfg ) = 0;

	/** 
	* ����  ��ȡȫ��¼�����Ϣ
	* @param [in]  
	* @return  
	*/
	virtual u16 GetUmsVTRData( vector<TVcrCfg> &vecTVcrCfg ) = 0;

	/** 
	* ����  ��ȡ¼��������ע��״̬
	* @param [in]  
	* @return  
	*/
	virtual u16 GetVtrRegState( BOOL32 &bRegState ) = 0;

	/** 
	* ����  ��ȡ¼��������������Ϣ
	* @param [in]  
	* @return  
	*/
	virtual u16 GetRecBaseInfo( vector<TRecBaseInfo> &vecTRecBaseInfo ) = 0;

	/** 
	* ����  ��ȡ¼���������ļ��б�
	* @param [in]  
	* @return  
	*/
	virtual u16 GetRecFileListInfo( vector<TRecFileInfo> &vecTVtrFileInfo ) = 0;

	/** 
	* ����  ��ȡ¼���������ļ��б�(�޺�׺)
	* @param [in]  
	* @return  
	*/
	virtual u16 GetRecFileListInfoNoSuffix( vector<TRecFileInfo> &vecTVtrFileInfoNoSuffix ) = 0;

	/**
    * ����:	 	        ɾ���ļ�����
	* @param [in]       �ļ���Ϣ
	*/
	virtual u16  RecDelFileReq( const TRecFileInfo& tRecFileInfo ) = 0;

	/**
    * ����:	 	        �޸��ļ�����
	* @param [in]       �ļ���Ϣ
	*/
	virtual u16  RecMdyFileReq( const TRecFileInfo& tRecFileInfoOld, const TRecFileInfo& tRecFileInfoNew ) = 0;

	/**
    * ����:	 	        ¼������
	* @param [in]       ¼����Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   ev_rec_recorder_conf_req
	*/
	virtual u16 RecStartConfReq( const TRecConfInfo& tRecConfInfo ) = 0;

	/**
    * ����:	 	        ��ͣ¼������
	* @param [in]       ¼����Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   ev_rec_pause_conf_req
	*/
	virtual u16 RecPauseConfReq( const TRecConfRes& tRecConfRes ) = 0;

	/**
    * ����:	 	        ����¼������
	* @param [in]       ¼����Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   ev_rec_resume_conf_req
	*/
	virtual u16 RecResumeConfReq( const TRecConfRes& tRecConfRes ) = 0;

	/**
    * ����:	 	        ����¼������
	* @param [in]       ¼����Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   ev_rec_stop_conf_req
	*/
	virtual u16 RecStopConfReq( const TRecConfRes& tRecConfRes ) = 0;

	/**
    * ����:	 	        ��ȡ¼����Ϣ
	* @param [in]       ¼����Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	*/
	virtual u16 GetRecConfInfo( vector<TConRecState>& vecTConRecState ) = 0;

	/**
    * ����:	 	        ��ȡ������Ϣ
	* @param [in]       ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	*/
	virtual u16 GetPlayConfInfo( vector<TConfPlayStatus>& vecTConfPlayStatus ) = 0;

	/**
    * ����:	 	        ��ʼ��������
	* @param [in]       ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   ev_rec_start_play_req
	*/
	virtual u16 RecStartPlayReq( const TRecPlayInfo& tRecPlayInfo ) = 0;
	
	/**
    * ����:	 	        ��ͣ��������
	* @param [in]       ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   ev_rec_pause_play_req
	*/
	virtual u16 RecPausePlayReq( const TPlayStatusMdyInfo& tPlayStatusMdyInfo ) = 0;
	
	/**
    * ����:	 	        ������������
	* @param [in]       ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   ev_rec_resume_play_req
	*/
	virtual u16 RecResumePlayReq( const TPlayStatusMdyInfo& tPlayStatusMdyInfo ) = 0;
	
	/**
    * ����:	 	        ������������
	* @param [in]       ������Ϣ
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   ev_rec_stop_play_req
	*/
	virtual u16 RecStopPlayReq( const TPlayStatusMdyInfo& tPlayStatusMdyInfo ) = 0;

	/**
    * ����:	 	        �᳡��ʽ����
	* @param [in]       wConfID:����ID, wMtID:�᳡ID
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	* @remarks ��Ϣ��   ev_rec_mt_format
	*/
	virtual u16 RecMtFormatReq( const u16& wConfID, const u16& wMtID ) = 0;

	/**
    * ����:	 	        ��ȡ¼���ID
	* @param [in]       ¼���ID
	* @return           u16 �ɹ�����0,ʧ�ܷ��ط�0������
	*/
	virtual u16 GetEqpID( u8& byEqpID ) = 0;

	//��m_vecTRecFileInfo�в���strFileNameNoSuffix��Ӧ��TRecFileInfo
	virtual TRecFileInfo FindFileName( CString strFileNameNoSuffix ) = 0;

	/**
    * ����:	 	        �õ�û��ǰ׺�ͺ�׺��¼���ļ���
	* @param [in]       ¼���ļ���
	* @return           û��ǰ׺�ͺ�׺��¼���ļ���
	*/
	virtual CString GetNoSuffixString( CString strFileName ) = 0;

 /** @}*/ // ����¼����ӿ�

};

#endif // !defined(UMCLIB_VTRCTRLIF_H)
