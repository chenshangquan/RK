/** @defgroup CncLib���ƽӿ�
 *  @author  Ф��Ȼ
 *  @version V1.0  Copyright(C) 2011-2012 KDC, All rights reserved.
 *  @date    2011-2012
 *  @{
 */

#if !defined(AFX_CNSSESSIONCTRIF_H__EAE7EF3A_F4D7_4942_AFD0_9DC72544033B__INCLUDED_)
#define AFX_CNSSESSIONCTRIF_H__EAE7EF3A_F4D7_4942_AFD0_9DC72544033B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "cncaddrbookif.h"
#include "cncconfigif.h"
#include "cncconfctrlif.h"
#include "umcConfCtrlIF.h"
#include "cncuserctrlif.h"
#include "cncsipinfoctrlif.h"
#include "cnccenterctrlif.h"
#include "cncportdiagctrlif.h"
#include "cncsysctrlif.h"
#include "cncnetmngctrlif.h"
#include "tpadplatstuct.h"

class CCnsSessionCtrlIF : public CKdvDispEvent 
{
public:
	
    /*��    ��  ��ʼ��lib�⻷��
	��    ��  dwAppID�� ����ʹ�õ�appID
              dwDesIID: Ŀ��appID,Ĭ��MAKEIID(AID_CN_UE, 1)
	�� �� ֵ   
	˵    ��   ʹ�������ӿ�֮ǰ������øýӿ�*/ 
	virtual void InitEnv( u16 wAppID, u32 dwDesIID = MAKEIID(AID_CN_UE, 1) ) = 0;


	/** ����  ��ȡ�ض��Ŀ��ƽӿ� 
	 *  @param[out] ppCtrl CCncAddrbookIF�ӿ�
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks �����ӵ��ն�ʱ,���Ի�ȡ��Щ�ӿ�,�ڶϿ����Ӻ�,������Щ�ӿ�����ʧЧ
	 */
	virtual u16 CncGetInterface(CCncAddrbookIF **ppCtrl) = 0;
	virtual u16 CncGetInterface(CCncConfigIF **ppCtrl) = 0;	
	virtual u16 CncGetInterface(CCncConfCtrlIF **ppCtrl) = 0; 
	virtual u16 CncGetInterface(CCncUserCtrlIF **ppCtrl) = 0;
	virtual u16 CncGetInterface(CUmcConfCtrlIF **ppCtrl) = 0;
	virtual u16 CncGetInterface(CCncSipInfoCtrlIF **ppCtrl) = 0;
 	virtual u16 CncGetInterface(CCncSysCtrlIF **ppCtrl) = 0;
 	virtual u16 CncGetInterface(CCncPortDiagCtrlIF **ppCtrl) = 0;
 	virtual u16 CncGetInterface(CCncCenterCtrlIF **ppCtrl) = 0;
	virtual u16 CncGetInterface(CCncNetMngCtrlIF **ppCtrl) = 0;
	
    /** ����  �Ƿ�ʹ�õ�ַ�� ��
	 *  @param[in] bUseAddrbook	 �Ƿ�ʹ��
	 *  @return  
	 *  @remarks  ά�����߲���Ҫ��ʹ�õ�ַ��  2012.12.12
	 */
	virtual void SetUseAddrbook( BOOL bUseAddrbook) = 0;

	/** ����  ���ӵ�CNS 
	 *  @param[in] dwIP	������CNS��IP��ַ
	 *  @param[in] dwPort  ������CNS�Ķ˿�
	 *  @param[in] strUser	�û���
	 *  @param[in] strPwd	����
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
	virtual u16 ConnectCns(u32 dwIP, u32 dwPort,
		const CString& strUser,
		const CString& strPwd, BOOL32 bConnect = TRUE) = 0;

	/** ����  �Ͽ�CNS���� 
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks ��û�����ӵ�CNSʱ���ô˷����������κ�����
	 */
	virtual u16 DisconnectCns() = 0;

	/** ����  ��ѯ�Ƿ�������CNS 
	 *  @return  TRUE �����ӣ�FALSE	û����
	 *  @remarks 
	 */
	virtual BOOL IsConnectedCns() = 0;

	/** ����  ��ѯ���ӵ�Cns�б�
	 *  @return  TTPCnList Cns�б�
	 *  @remarks 
	 */
	virtual const TTPCnList& GetConnectCnsList() const = 0;

	/** ����  ��¼CNS�᳡
	 *  @param[in] byIns	�᳡Ins
	 *  @return  �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
	virtual u16 LoginCnsIns( u8 byIns ) = 0;

    /** ����  ��ȡ����ip
	 *  @param[in] 
	 *  @return  ����ip 
	 *  @remarks 
	 */
    virtual u32 GetLocalHostIP() = 0;

    /** ����  ��ȡ��½ip
	 *  @param[in] 
	 *  @return  ��½ip
	 *  @remarks 
	 */
	virtual u32 GetLoginIp() = 0;
    
    /** ����  ���ӵ�TPad
     *  @param[in] dwIP	������tpad��IP��ַ
	 *  @param[in] dwPort  ������tpad�Ķ˿�
	 *  @return  �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
    virtual u16 ConnectTPad( TTPadSubInfo tSubInfo /*u32 dwIP, u32 dwPort, emTPadSubType emSubType*/) = 0;

    /** ����  pad��cnc��Tpad��ϵͳ����������
	 *  @param[in] strSysName ���õ�ϵͳ����
	 *  @return  �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
    virtual u16 SetTpadSysName( string strSysName ) = 0;
	 /** ���� �п�֪ͨtpad ��tpad������cns����
	 *  @param[in] strSysName ���õ�ϵͳ����
	 *  @return  �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
	virtual u16 DisConnectTpad() = 0;
};


#endif // !defined(AFX_CNSSESSIONCTRIF_H__EAE7EF3A_F4D7_4942_AFD0_9DC72544033B__INCLUDED_)
