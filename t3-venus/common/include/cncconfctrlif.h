/*****************************************************************************
ģ����      : cmc cnclib�ӿ�
�ļ���      : cncconfctrlif.h
����ļ�    : 
�ļ�ʵ�ֹ���: cns�������
����        : Ф��Ȼ
�汾        : V1.0  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2011/4/30   1.0         Ф��Ȼ        ����
******************************************************************************/
#ifndef __CNCCONFCTRLIF_H__
#define __CNCCONFCTRLIF_H__

#include "kdvdispevent.h"
#include "tpstruct.h"

class CCncConfCtrlIF : public CKdvDispEvent
{
public:  //����
	

     /** 
	* ����  ������Ե����
	* @return tDialParam ��Ӧ����
	* @remarks 
	*/
    virtual const u16 MakeCall( TTPDialParam &tDialParam ) = 0 ;

    /** ���� ����ptp����
	 *  @return T 
	 *  @remarks 
	 */
    virtual const u16 HungupPtpConf() = 0;

	/** 
	* ����  ���û᳡�ڷ�����
	* @param [in]  byIndex  ���
	* @return 
	* @remarks 
	*/
	virtual u16 SetInnerSpeaker( u8 byIndex ) = 0;

	/** 
	* ����  ����/�رձ�������
	* @param [in]  bMute  ����/�ر�
	* @return  
	* @remarks 
	*/
	virtual u16 SetCnsMute( BOOL bMute = TRUE ) = 0;
	/** 
	* ����  ����/�رձ��ؾ���
	* @param [in]  bQutie  ����/�ر�
	* @return  
	* @remarks 
	*/
    virtual u16 SetCnsQutie( BOOL bQutie = TRUE ) = 0;
	
	/** 
	* ����  ������������
	* @return byVolume ����
	* @remarks 
	*/
	virtual u16 AdjustInputVol( u8 byVolume ) = 0;
	
	/** 
	* ����  �����������
	* @return byVolume ����
	* @remarks 
	*/
	virtual u16 AdjustOutputVol( u8 byVolum ) = 0;

	/** 
	* ����  �������Ϣ
	* @return vector<TScreenInfo> ����Ϣ
	* @remarks 
	*/
	virtual void ClearCnsScreenInfo() = 0;

    /** 
	* ����  ����ѡ��
    * @param [in]  byScreenID  ����
    * @param [in]  wEpID  ѡ����cnsID
	* @return  
	* @remarks 
	*/
	virtual u16 SetSelView( u8 byScreenID, u16 wEpID ) = 0;

    /** 
	* ����  ȡ��ѡ��
    * @param [in]  byScreenID  ���� 
	* @return  
	* @remarks 
	*/
	virtual u16 CancleSelView( u8 byScreenID ) = 0;

    /** 
	* ����  ����/ֹͣ��ѯ
    * @param [in]  bStart   true:������false���ر�
	* @return  
	* @remarks 
	*/
	virtual u16 StartPoll( BOOL  bStart ) = 0;

	
    /** 
	* ����  ����/ֹͣ˫��
    * @param [in]  bStart   true:������false���ر�
	* @return  
	* @remarks 
	*/
	virtual u16 StartDual( BOOL  bStart ) = 0;



     /** 
	* ����  ����/ֹͣ˫������
	* @return  BOOL  TRUE:������ FALSE:ֹͣ
	* @remarks 
	*/
    virtual u16 StartDualCodeStream( const TTPCnMediaTransPort  &tVideoTransAddr , const TTPCnMediaTransPort  &tAudioTransAddr ) const = 0;

    virtual u16 StopDualCodeStream() const = 0;

    virtual u16 ReqKeyFrame( BOOL32 bForce ) const = 0;

     /** 
	* ����  ��Ļ��ʾ˫��ͼ��
	* @return   
	* @remarks 
	*/
    virtual u16 ScrnDisplayDual( const u16 wScrnID ) const = 0 ;

     /** 
	* ����  ��Ļ��ʾ˫��ͼ��
	* @return  
	* @remarks 
	*/
    virtual u16 ScrnStopDisplayDual( const u16 wScrnID ) const = 0 ;


    /** 
	* ����  ��Ļ����
	* @return    
	* @remarks 
	*/
    virtual u16 ScrnDisplayLocal( const u16 wScrnID ) const = 0 ;


    /** 
	* ����  ȡ����Ļ����
	* @return    
	* @remarks 
	*/
    virtual u16 ScrnStopDisplayLocal( const u16 wScrnID ) const = 0 ;

    /** 
	* ����  ����ѡ������ǽ
    * @param [in]  byScreenID  ����
	* @return  
	* @remarks 
	*/
	virtual u16 SelTVSView( u8 byScreenID ) = 0 ;

    /** 
	* ����  ȡ��ѡ������ǽ
    * @param [in]  byScreenID  ���� 
	* @return  
	* @remarks 
	*/
	virtual u16 CancelSelTVSView( u8 byScreenID ) = 0 ;

public:  //��ȡ���

      /** ����  ��ȡCNS����״̬
	 *  @return TTPCnsConfStatus ����״̬
	 *  @remarks 
	 */
	virtual const TTPCnsConfStatus& GetCnsConfStatus() const =0;


    	/** 
	* ����  ��ȡ�᳡�ڷ�����
	* @return  byIndex  ���
	* @remarks 
	*/
	virtual u8 GetInnerSpeaker() const = 0;
	/** 
	* ����  ����CNS�Ƿ�����
	* @return  BOOL  �Ƿ�����
	* @remarks 
	*/
	virtual BOOL IsLocalCnsMute() const = 0;
	/** 
	* ����  ����CNS�Ƿ���
	* @return  BOOL  �Ƿ���
	* @remarks 
	*/
    virtual BOOL IsLocalCnsQuite() const = 0;


    /** 
	* ����  ��ȡ��������
	* @return  u8  ����
	* @remarks 
	*/
	virtual const u8& GetInputVol() const = 0;


    /** 
	* ����  ��ȡ�������
	* @return  u8  ����
	* @remarks 
	*/
	virtual const u8& GetOutputVol() const = 0;


    	/** 
	* ����  ��ȡ����Ϣ
	* @return vector<TScreenInfo> ����Ϣ
	* @remarks 
	*/
	virtual const vector<TScreenInfo>& GetCnsScreenInfo() const = 0;


    /** 
	* ����  ����CNS�Ƿ�����ѯ
	* @return  BOOL  �Ƿ���ѯ
	* @remarks 
	*/
	virtual BOOL IsLocalCnsPoll() const = 0;

	/** 
	* ����  ����CNS�Ƿ���˫��
	* @return  BOOL  �Ƿ�˫��
	* @remarks 
	*/
    virtual BOOL IsLocalCnsDual() const = 0;

    virtual TTPCnMediaTransPort GetVedioTransAddr() const = 0;

    virtual TTPCnMediaTransPort GetAudioTransAddr() const = 0;

	//�������л�
	virtual u16 ViewLocalPIPCmd( const u8 byScrnID, const BOOL bLocalP ) = 0;

	virtual BOOL IsViewLocalPIP() const = 0;
   
    virtual BOOL32 IsRcvDual() const = 0;
};

#endif
