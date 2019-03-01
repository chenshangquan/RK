#ifndef _CNCSYSTEMCONTROL_H_
#define _CNCSYSTEMCONTROL_H_

#include "kdvdispevent.h"

class CCncSysCtrlIF : public CKdvDispEvent
{
public:
	/** 
	* ����  	�����������cpu/�ڴ����Ϣ
	* @param [in] 	   
	* @return  
	* @remarks 
	*/	
	virtual u16 ReqSysInfo() = 0;
	/** 
	* ����  	���շ�����������cpu/�ڴ����Ϣ
	* @param [in] 	   
	* @return  
	* @remarks 
	*/	
	virtual const TTPSysInfo& GetSysInfo()const = 0;
	/** 
	* ����  	��ȡ������Ϣ
	* @param [in] 	   
	* @return  
	* @remarks 
	*/	
 	virtual const TTPCnsConfStatus& GetCnConfStatus()const = 0;
	/** 
	* ����  	��ȡ������Ϣ
	* @param [in] 	   
	* @return  
	* @remarks 
	*/	
	virtual	const TTPCnConfInfo& GetCnConfVideoParam()const = 0;	
	/** 
	* ����  	ѡ�������
	* @param [in] 	 TCameraMemInfo  
	* @return  
	* @remarks 
	*/		
	virtual u16 CamSelCmd( const u8& byCameraIndx ) = 0;
	/** 
	* ����  	��ȡ��ѡ�е������
	* @param [in] 	 
	* @return  
	* @remarks 
	*/		
	virtual u8 GetCamSel()const = 0;
	/** 
	* ����  	�ָ������Ĭ�ϲ���
	* @param [in] 	   
	* @return  
	* @remarks 
	*/	
	virtual	u16 CamResetCmd() = 0;			
	/** 
	* ����  	��Ұ����
	* @param [in] 	 EmZoom  ��Ϊ:Զ����
	* @return  
	* @remarks 
	*/	
	virtual u16 SetCamZoomCmd( const EmZoom& emZoom ) = 0;		
	/** 
	* ����  	��Ұ�Ƿ���OSD����ʾ����
	* @param [in] 	 EmOSDShow  ��Ϊ:on��off
	* @return  
	* @remarks 
	*/	
	virtual	u16 SetCamOSDCmd( const EmOSDShow& emOSDShow ) = 0;	
	/** 
	* ����  	��ȡ��Ұ�Ƿ���OSD����ʾ����
	* @param [in] 	 
	* @return  EmOSDShow  ��Ϊ:on��off
	* @remarks 
	*/	
	virtual EmOSDShow GetCamOSD() = 0;
	/** 
	* ����  	������Զ��۽�
	* @param [in] 	 
	* @return  
	* @remarks 
	*/		
	virtual u16 SetCamAutoFocusCmd(const EmFocusMode& emFocusMode) = 0;
	/** 
	* ����  	������ֶ��۽�
	* @param [in] 	 EmFocus : Զ��/����	EmCnAction :  ��ʼ/ֹͣ
	* @return  
	* @remarks 
	*/	
	virtual	u16 SetCamFocusCmd( const EmFocus& emFocus, const EmCnAction& emCnAction ) = 0;		
	/** 
	* ����  	����Ԥ��λ����
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual	u16 CamPresetSaveCmd() = 0;
	/** 
	* ����  	���ÿ�������Ԥ��λ1
	* @param [in] 	 BOOL
	* @return  
	* @remarks 
	*/	
	virtual	u16 SetCamPresetMoveCmd( const BOOL& bPresetMove ) = 0;
	/** 
	* ����  	��ȡ��������Ԥ��λ1״̬
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual BOOL GetCamPresetMove() = 0;
	/** 
	* ����  	�����Զ��ع�
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual u16 CamAutoExposureCmd( const EmExpMode& emExpAuto ) = 0;
	/** 
	* ����  	����
	* @param [in] 	 EmGain ���淶Χ 0dB  3dB  6dB ������42dB
	* @return  
	* @remarks 
	*/	
	virtual	u16 CamGainCmd( const EmGain& emGain ) = 0;	
	/** 
	* ����  	��ȡ���������ֵ
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual EmGain GetCamGain() = 0;
	/** 
	* ����  ���ŵ���	���ŷ�Χ 1/60  1/100 1/250.....1/4000  1/10000
	* @param [in]  EmShutSpd
	* @return  
	* @remarks 
	*/
	virtual	u16 CamShutSpdCmd( const EmShutSpd& emShutSpd ) = 0;
	/** 
	* ����  	��ȡ���������ֵ
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual EmShutSpd GetCamShutSpd() = 0;
	/** 
	* ����  ����ģʽ����
	* @param [in]  EmBackLightType  ����ģʽ:�رգ�multi��Ĭ��7����Χ0-15����center��face detect
	*			   u8  = TP_INVALID_INDEX ��multiģʽ  0--15 multiģʽ����
	* @return  
	* @remarks 
	*/
	virtual	u16 CamBackLightCmd( const EmBackLightType& emBackLightType, const u8& byMulti ) = 0;
	/** 
	* ����  	��ȡ���������ģʽ
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual EmBackLightType GetCamBackLightType() = 0;
	/** 
	* ����  	��ȡ���������ģʽ��Ӧ��ֵ
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual u8 GetCamBackLightIndex() = 0;
	/** 
	* ����  ��Ȧ��С����
	* @param [in]  u8  ��Ȧ��С ��Χ 0--100			   
	* @return  
	* @remarks 
	*/	
	virtual	u16 CamAperture( const u8& byAperture) = 0;	
	/** 
	* ����  	��ȡ�������Ȧ��С
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual u8 GetCamAperture() = 0;
	/** 
	* ����  ��ƽ�����(��Ϊ�Զ����ֶ�)
	* @param [in] 		   
	* @return  
	* @remarks 
	*/		
	virtual	u16 CamAutoWBCmd( const EmWBMode& emWBMode ) = 0;	
	/** 
	* ����  R+����
	* @param [in] 	u16  R Gain ��Χ 0--100	   
	* @return  
	* @remarks 
	*/		
	virtual	u16 CamRGainCmd( const u16& wRGain ) = 0;
	/** 
	* ����  	��ȡ�������ƽ�����ģʽR+����ֵ
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual u16 GetCamRGain() = 0;
	/** 
	* ����  B+����
	* @param [in] 	u16  B Gain ��Χ 0--100	   
	* @return  
	* @remarks 
	*/		
	virtual	u16 CamBGainCmd( const u16& wBGain ) = 0;
	/** 
	* ����  	��ȡ�������ƽ�����ģʽB+����ֵ
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual u16 GetCamBGain() = 0;
	/** 
	* ����  ģʽ����  
	* @param [in] 	EmPicSceMode  ��Ϊ:�չ��/̫����/�ֶ�
	* @return  
	* @remarks 
	*/	
	virtual	u16 CamPicSceneModeCmd( const EmPicSceMode& emPicSceMode ) = 0;	
	/** 
	* ����  	��ȡ�����Picģʽ����״̬
	* @param [in] 	 
	* @return  EmPicSceMode  ��Ϊ:�չ��/̫����/�ֶ�
	* @remarks 
	*/	
	virtual EmPicSceMode GetCamPicSceneMode() = 0;
	/** 
	* ����  �ֶ�ģʽ�е�CAMMA����  
	* @param [in] 	EmGamma  ��Ϊ:emGammaOff��emGammaOn ��emSmart1�� emStrat2
	* @return  
	* @remarks 
	*/	
	virtual	u16 CamGammaCmd( const EmGamma& emGamma ) = 0;
	/** 
	* ����  	��ȡ�����PicģʽCAMMA����״̬
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual EmGamma GetCamGamma() = 0;
	/** 
	* ����  �ֶ�ģʽ�еĹ�Ȧ����  
	* @param [in]   u8 ��Ȧ��С  1--15
	* @return  
	* @remarks 
	*/	
    virtual	u16 CamPicSceAptCmd( const u8& byPicSceApt ) = 0;
	/** 
	* ����  	��ȡ�����Picģʽ��Ȧ����ֵ
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual u8 GetCamPicSceApt() = 0;
	/** 
	* ����  ͼƬ�����еĶԱȶȵ���
	* @param [in]   u16  ��С  0--200
	* @return  
	* @remarks 
	*/		
	virtual	u16 CamContrastCmd( const u16& wContrast ) = 0;	
	/** 
	* ����  	��ȡ�����ͼƬ�����еĶԱȶ�ֵ
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual u16 GetCamContrast() = 0;
	/** 
	* ����  ͼƬ�����е�ɫ�ȵ���
	* @param [in]   u16  ��С  0--200
	* @return  
	* @remarks 
	*/		
	virtual	u16 CamHueCmd( const u16& wHue ) = 0;
	/** 
	* ����  	��ȡ�����ͼƬ�����е�ɫ��ֵ
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual u16 GetCamHue() = 0;
	/** 
	* ����  ͼƬ�����еı��Ͷȵ���
	* @param [in]   u16  ��С  0--200
	* @return  
	* @remarks 
	*/	
	virtual	u16 CamSaturatCmd( const u16& wSaturat ) = 0;
	/** 
	* ����  	��ȡ�����ͼƬ�����еı��Ͷ�ֵ
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual u16 GetCamSaturat() = 0;
	/** 
	* ����  ͼƬ�����е����ȵ���
	* @param [in]   u16  ��С  0--200
	* @return  
	* @remarks 
	*/	
	virtual	u16 CamBrightCmd( const u16& wBright ) = 0;	
	/** 
	* ����  	��ȡ�����ͼƬ�����е�����ֵ
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual u16 GetCamBright() = 0;
	/** 
	* ����  ����---����������˵�������
	* @param [in]   EmStmClean  Ĭ��LOW  ��ΧOFF,LOW,MID,HIGH
	* @return  
	* @remarks 
	*/	
	virtual	u16 CamNRStmCleanCmd( const EmStmClean& emStmClean ) = 0;
	/** 
	* ����  	��ȡ�����������ģʽ
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual EmStmClean GetCamNRStmClean() = 0;
	/** 
	* ����  ����---3D�����������
	* @param [in]   Em3DNR   em3DNROff ��OFF��em3DNROn ��
	* @return  
	* @remarks 
	*/	
	virtual	u16 Cam3DNRCmd( const Em3DNR& em3DNR ) = 0;	
	/** 
	* ����  	��ȡ�����3D�������ģʽ
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual Em3DNR GetCam3DNR() = 0;

	/** 
	* ����  	��ȡȫ�����������
	* @param [in] 	 �������Ϣ
	* @return  
	* @remarks 
	*/	
	virtual u16 GetCamCfgAll( vector<TCnCameraCfg>& vecTCnCameraCfg ) = 0;

	/** 
	* ����  	��ȡ��ǰ���������
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual TCnCameraCfg GetCamCfg() = 0;
	/** 
	* ����  	��ȡ�ع�ģʽ
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual EmExpMode GetCamExpMode() = 0;
	/** 
	* ����  	��ȡ��ƽ��ģʽ
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual EmWBMode GetCamWBMode() = 0;

	/** 
	* ����  	����������͵���֪ͨ
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual	u16 SetLoadCameraFileNty() = 0;

	/** 
	* ����  	��ȡzoom
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual u16 GetCamZoom() = 0;

	/** 
	* ����  	����zoomֵ
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual u16 SetCamZoomCmd( const u16& wZoom ) = 0;

	/** 
	* ����  	�������������
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual u16 SetCamTypeCmd( const EmCamType& emCamType ) = 0;

	/** 
	* ����  	Sony����������������
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual u16 SonyBackLightCmd( const BOOL& bLight ) = 0;

	/** 
	* ����  	Sony�������������
	* @param [in] 	 
	* @return  
	* @remarks 
	*/	
	virtual u16 SonyStmClenCmd( const BOOL& bClen, const u8& bylevel ) = 0;

};
#endif
