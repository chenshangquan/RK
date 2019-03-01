/*****************************************************************************
ģ����      : cmc cnclib�ӿ�
�ļ���      : cncconfigif.h
����ļ�    : 
�ļ�ʵ�ֹ���: cns����
����        : Ф��Ȼ
�汾        : V1.0  Copyright(C) 2011-2012 KDC, All rights reserved.
-----------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2011/4/30   1.0         Ф��Ȼ        ����
******************************************************************************/
#ifndef __CNCCONFIGIF_H__
#define __CNCCONFIGIF_H__

#include "kdvdispevent.h"
#include "cmsstruct.h"
#include <vector>

class CCncConfigIF : public CKdvDispEvent
{
public:
	/** ����  ע��SIP����
	 *  @param[in] tSipCfg ������Ϣ
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
	virtual u16 RegSipService(const TTPSipRegistrarCfg& tSipCfg) = 0;

	/** ����  ע��SIP����
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
	virtual u16 UnRegSipService() = 0;

	/** ����   ���SIP����
	 *  @return TTPSipRegistrarCfg SIP��Ϣ
	 */
	virtual const TTPSipRegistrarCfg& GetSipRegCfg() const = 0;

	/** ����   �����������
	 *  @return tagTTPEthnetInfo ����������Ϣ
	 */
	virtual const TTPEthnetInfo& GetEthnetCfg() const = 0;

	/** ����   GK
	 *  @return tGkCfg ������Ϣ
	 */
    virtual u16 RegGk( const TTPGKCfg& tGkCfg ) = 0;

    /** ����   ���GK����
	 *  @return tagTTPEthnetInfo ����������Ϣ
	 */
	virtual  const TTPGKCfg& GetGkCfg() const = 0;

	/** ����   ������������
	 *  @param[in] cfg ��������
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
	virtual u16 UpdateEthnetCfg( const TTPEthnetInfo& cfg ,EmTpIpNameNatSyn emTpIpType) = 0;

	virtual u16 SaveWEthnetCfgCmd( const TTPWEthnetInfo& tTPWEthnetInfo, EmTpIpNameNatSyn emTpIpType ) = 0;
	
	/** ����   ��ñ���CNS��Ϣ
	 *  @return TTPCnsInfo CNS��Ϣ
	 */
	virtual const TTPCnsInfo& GetLocalCnsInfo() const = 0;

	/** ����   ��ñ���CNS�б�
	 *  @return vector<TTPCnsInfo> CNS�б�
	 */
	virtual const vector<TTPCnsInfo>& GetLocalCnsList() const = 0;

	/** ����   ����CNS��Ϣ
	 *  @param[in] tInfo CNS��Ϣ byIndex ��Ϣ��������(0Ϊcnc 1Ϊά������)
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
	virtual u16 UpdateCnsInfo( const TTPCnsInfo& tInfo, u8 byIndex ,EmTpIpNameNatSyn emTpIpType) = 0;

	/** ����   ����CNS���᳡
	 *  @param[in] pbyRoomName �᳡��
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
	virtual u16 SetMainCns( s8* pbyRoomName ) = 0;

	/** ����   ��ȡCNS���᳡��
	 *  @return �ɹ����ػ᳡��,ʧ�ܷ���NULL
	 *  @remarks 
	 */
	virtual const s8* GetMainCnsName() const = 0;
   
    /** ����   ����ϵͳʱ��
	 *  @return �ɹ����ػ᳡��,ʧ�ܷ���NULL
	 *  @remarks 
	 */
    virtual u16 UpdateSysTime( const TTPTime& time ) = 0;
       
    /** ����   ��ȡϵͳʱ��
	 *  @return �ɹ����ػ᳡��,ʧ�ܷ���NULL
	 *  @remarks 
	 */    
    virtual u16 ReqSysTime() = 0;

    /** ����   ���˫��Դ��Ϣ
	 *  @return TDualSrcInfo˫��Դ��Ϣ
	 */
    virtual const TDualSrcInfo& GetDualSrcInfo() const = 0;

    /** ����   �����ʾԴ����ӿ���Ϣ
	 *  @return TTPVgaMixInfo��ʾԴ����ӿ���Ϣ
	 */
    virtual const TTPVgaMixInfo& GetVgaMixInfo() const = 0;

    /** ����   ѡ��˫��Դ�˿�
	*  @param[out] emType ˫��Դ����
	*  @return �ɹ�����0,ʧ�ܷ��ط�0������
	*/
    virtual u16 SelDualInputPort( EmVgaType emType ) = 0;

    /** ����   ����˫��Դ��Ϣ
	*  @param[out] tVgaInfo ˫��Դ��Ϣ
	*  @return �ɹ�����0,ʧ�ܷ��ط�0������
	*/
    virtual u16 SetDualPortInfo( const TVgaInfo& tVgaInfo, BOOL bDefault = FALSE ) = 0;

	/** ����   ����NAT����
	 *  @param[in] cfg NAT����
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
	virtual u16 UpdateNATCfg( const TTPNatCfg& cfg,EmTpIpNameNatSyn emTpIpType) = 0;
	
	/** ����   ���NAT����
	 *  @return tagTTPNatCfg ����������Ϣ
	 */
	virtual const TTPNatCfg& GetNATCfg() const = 0;
	
	/** ����   ���ü���
	 *  @param[in] 
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
	virtual u16 SetAesEncrypCmd( const TTpEncryptKey& tEncryptKey ) = 0;
	
	/** ����   ����ϵͳ������Ϣ
	*  @param[out] tTPSleepInfo ϵͳ������Ϣ
	*  @return �ɹ�����0,ʧ�ܷ��ط�0������
	*/
    virtual u16 SetSysSleepInfo( const TCenDevSleepInfo& tCenDevSleepInfo ) = 0;

	 /** ����   ���ϵͳ������Ϣ
	 *  @return TTPSleepInfo ϵͳ������Ϣ
	 */
    virtual const TCenDevSleepInfo& GetSysSleepInfo() const = 0;

    /**
	* ����   �װ����������
	* @param [in]  dwIP	IP��ַ
	* @param [in] 
	* @param [in] 
	* @return u16 
	*/  
    virtual u16 SetDataServerInfoCmd( u32 dwIp ) =0 ;

	 /**
	* ����   �����ָ�����
	* @param [in]  emLostPackage ��������
	* @return u16 
	*/  
	virtual u16 SetLostPacketCmd( EmTpLostPackageRestore emLostPackage ) = 0;

	virtual u16 SetFtpInfoRsq( const TTPFtpInfo &tTPFtpInfo ) = 0;
	
	virtual u16 SetTelInfoRsp( const TTPTelnetInfo &tTPTelnetInfo) = 0;

	//�Ʒ���������
	virtual u16 SetCloudServerInfo(const TTpCloudServerInfo& tTpCloudServerInfo) = 0;
	virtual const TTpCloudServerInfo& GetCloudServerInfo() const = 0;
};

#endif