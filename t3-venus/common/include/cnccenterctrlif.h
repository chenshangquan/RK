/*****************************************************************************
ģ����      : cnclib�п���Ϣ�Ľӿ�
�ļ���      : cncconfctrlif.h
����ļ�    : 
�ļ�ʵ�ֹ���: cnstool�п���Ϣ�鿴
����        : ������
�汾        : V1.0  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2012/11/27   1.0					  ����
******************************************************************************/
#ifndef _CNCCENTERCONTROLIF_H_
#define _CNCCENTERCONTROLIF_H_

#include "kdvdispevent.h"

class CCncCenterCtrlIF : public CKdvDispEvent
{
public:
    /** 
	* ����  ����ϵͳ��Դ
	* @param [in]  emPower  ����
	* @return 
	* @remarks 
	*/
    virtual u16 SetSysPower( EmSchPower emPower ) = 0;

    virtual u16 SetSysAllLight( EmSchLight emLight ) = 0;
    /** 
	* ����  �������ƿ���
	* @param [in]  emMidLight  ����
	* @return 
	* @remarks 
	*/
    virtual u16 SetMainLight( EmSchMidLight emMidLight ) = 0;
    /** 
	* ����  ���ø��ƿ���
	* @param [in]  emScrLight  ����
	* @return 
	* @remarks 
	*/
    virtual u16 SetAuxiLight( EmSchScrLight emScrLight ) = 0;

    /** 
	* ����  ѡ����ӻ�
	* @param [in]  byIndex  ���
	* @return 
	* @remarks 
	*/
    virtual u16 SelectTV( u8 byIndex ) = 0;
    /** 
	* ����  ���õ��ӻ���Դ
	* @param [in]  byIndex  ����
	* @return 
	* @remarks 
	*/
    virtual u16 SetTVPowerMode( u8 byIndex, EmTvPowerMode emMode ) = 0;
    /** 
	* ����  ���õ��ӻ�����ģʽ
	* @param [in]  emMode  ����ģʽ
	* @return 
	* @remarks 
	*/
    virtual u16 SetTVAudVisMode( EmTVAudVisMode emMode ) = 0;
    /** 
	* ����  ���õ��ӻ���ʾģʽ
	* @param [in]  emMode  ��ʾģʽ
	* @return 
	* @remarks 
	*/
    virtual u16 SetTVDisMode( EmTVDisplayMode emMode ) = 0;
    /** 
	* ����  ���õ��ӻ�����ѡ��
	* @param [in]  emSelect  ����ѡ��
	* @return 
	* @remarks 
	*/
    virtual u16 SetTVInpSelect( u8 byIndex, EmTVInputSelect emSelect ) = 0;
    /** 
	* ����  ��ȡ���ӻ�����
	* @return TCentreTVCfg*  ���ӻ���������ָ��
	*/
    virtual TCentreTVCfg* GetCentreTVCfg() = 0; 

    /** 
	* ����  �����ĵ����������
    * @param [in]  emPower  ����
	* @return 
	*/
    virtual u16 SetDCamPower( EmDCamPower emPower ) = 0;
    /** 
	* ����  �����ĵ�������Զ��۽�ģʽ
	* @param [in]  emMode  ģʽ
	* @return 
	*/
    virtual u16 SetDCamAFMode( EmDCamAFMode emMode ) = 0;
    /** 
	* ����  �����ĵ��������ƽ��ģʽ
	* @param [in]  emMode  ģʽ
	* @return 
	*/
    virtual u16 SetDCamWBMode( EmDCamWBMode emMode ) = 0;
    /** 
	* ����  �����ĵ��������Ұ����
	* @param [in]  emZoom  ��Ұ���� zoom+/zoom- ,emAction ��ʼ /ֹͣ 
	* @return 
	*/
    virtual u16 SetDCamZoom( EmDCamZoom emZoom, EmCnAction emAction ) = 0;
	/** 
	* ����  �����ĵ����������ֵ
	* @param [in]  wZoom  ��Ұֵ
	* @return 
	*/
	virtual	u16 SetDCamZoomValueCmd( const u16& wZoom ) = 0;
	/** 
	* ����  �����ĵ������Ԥ��λ
	* @param [in]  emNum  Ԥ��λ
	* @return 
	*/
    virtual u16 SetDCamPreset( EmDCamPresetNum emNum ) = 0;
    /** 
	* ����  �����ĵ������Ԥ��λ
	* @param [in]  emNum  Ԥ��λ
	* @return 
	*/
    virtual u16 SetDCamRecall( EmDCamRecallNum emNum ) = 0;
	/** 
	* ����  ���ÿյ�����ĵ�Դ����
	* @param [in] emPower ��Դ����
	* @return 
	*/
/*    virtual u16 SetAirPower( EmCentreACPower emPower ) = 0;*/
	/** 
	* ����  ���ÿյ�����Ŀյ�ģʽ
	* @param [in]  emMode �յ�ģʽ
	* @return 
	*/
    virtual u16 SetACMode( EmCentreACMode emMode ) = 0;
	/** 
	* ����  ���ÿյ��¶�
	* @param [in]  byTemp  �¶�
	* @return 
	* @remarks 
	*/
    virtual u16 SetACTemp( u8 byTemp ) = 0;
	/** 
	* ����  ���ÿյ������·�ģʽ
	* @param [in] byVol �·�ģʽ
	* @return 
	* @remarks 
	*/
    virtual u16 SetACAirVol( EmCentreACAirVol emAirVol ) = 0;
	/** 
	* ����  ѡ��յ�
	* @param [in]  byIndex  ���
	* @return 
	* @remarks 
	*/
    virtual u16 SelectAir( u8 byIndex ) = 0;
	/** 
	* ����  ��ȡ�յ���������
	* @return TCentreTVCfg*  �յ�������������ָ��
	*/
    virtual void GetCentreACCfg( vector<TCentreACCfg> &vecTCentreACCfg )const = 0;
    /** 
	* ����  ���ÿյ���Դ
	* @param [in]  byIndex  ����
	* @return 
	* @remarks 
	*/
    virtual u16 SetACPowerMode( u8 byIndex, EmCentreACPower emMode ) = 0;
	/** 
	* ����  ����Ӧ�õ�����
	* @param [in]  byIndex  ����
	* @return 
	* @remarks 
	*/
    virtual u16 SetApplyToAll( u8 byIndex, BOOL** atbIsCtrl ) = 0;
	/** 
	* ����  ����Ӧ�õ�����
		* @param [in]  byIndex  ����
		* @return 
		* @remarks 
	*/
	virtual BOOL* GetApplyToAllInfo() = 0;

	/** 
	* ����  �����пص���ǽ
		* @param [in]  
		* @return 
		* @remarks 
	*/
	virtual u16 SetDisplayCmd( BOOL bDisplay, const TTPDisplayType& tDisplayType1, const TTPDisplayType& tDisplayType3 ) = 0;
	/** 
	* ����  ���õ��ӻ��ͺ�
		* @param [in]  
		* @return 
		* @remarks 
	*/
	virtual u16 SetCentreTVModle( EmTVModle emTvMode) = 0;
	virtual u16 SetDisplayShowCmd( BOOL bDisplayShow) = 0;
	//��ȡ����ǽ���ź�Դ״̬
	virtual const BOOL& GetDisplayState() const = 0;
	virtual const TTPDisplayType& GetDisplayType1() const = 0;
	virtual const TTPDisplayType& GetDisplayType3() const = 0;

	virtual const BOOL& GetDisplayShowState() const = 0;

		/** 
	* ����  ���������������
		* @param [in]  
		* @return 
		* @remarks 
	*/
	virtual u16 SetCurtainState( BOOL** bIsCtrl, EmCurAction emCurAction ) = 0;	
	/** 
	* ����  ��ȡ�ײ㷢�͵Ĵ�����������
		* @param [in]  
		* @return 
		* @remarks 
	*/
	virtual void GetCentreCurName( vector<TCentreCurName> &vecTCentreCurName )const = 0;

	virtual const TCentreCurInfo& GetCurtainInfo( ) const = 0;

	virtual	u16 SetPanCamNumber( const u8 &byPanCamNum ) const = 0;

	virtual u16 SetDCCamFocus( EmFocus emFocusMode ,EmCnAction emAction ) const = 0;

	virtual	u16 SetDCCamExposure( EmExpMode emExpMode ) const = 0;

	virtual	u16 SetDCCamExpGainCmd( EmDCamGain emExpGain ) const = 0;
	
	virtual	u16 SetDCCamAperture( EmDCamIris emAperture ) const = 0;

	virtual	u16 SetDCCamShutCmd( EmDCamShutSpd emShutSpd ) const = 0;

	virtual	u16 SetDcCamRGainCmd( const u16& wRGain ) const =0;
	virtual	u16 SetDcCamBGainCmd( const u16& wRGain ) const =0;
	virtual u16 SetCurtainNumberCmd( const u8& byCurNum ) const = 0;
	virtual u16 SetCurtainName( const u8& byCurIndex, const TCentreCurName &tCurtainName) const =0;
	virtual u16 SetCurtainOpen( const BOOL& bOpen ) const = 0;
	virtual u16 SetDuoVideoCmd( const BOOL& bOpen ) const = 0;
	virtual u16 SetDCCamOpenCmd( const BOOL& bOpen ) const = 0;
	virtual u16 SetDCCamPreset( const BOOL& bOpen ) const = 0;
	virtual u16 SetAirConditionCmd( const u8& byAcNum ) const = 0;
	virtual u16 SetDcCamModel( EmDCamProType emDcCamType ) const = 0;
	virtual u16 SetPaCamModel( EmQCamProType emDPaCamType ) const = 0;
};
#endif