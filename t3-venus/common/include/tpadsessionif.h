/*=======================================================================
ģ����      : TPad lib�ӿ�
�ļ���      : tpadsessionif.h
����ļ�    : 
�ļ�ʵ�ֹ���: tpadlib���ƽӿ�
-------------------------------------------------------------------------
�޸ļ�¼:
��  ��      �汾        �޸���      �޸�����
2013.3.6    1.0         Ф��Ȼ        ����
=======================================================================*/
#if !defined _TPADSESSIONIF_H_
#define _TPADSESSIONIF_H_

#include "kdvdispevent.h"
#include "tpstruct.h"

class CTPadSessionIF : public CKdvDispEvent 
{
public:	
    /*��    ��  ��ʼ��lib�⻷��
	��    ��  dwAppID�� ��Ҫ��appID
	�� �� ֵ   
	˵    ��   ʹ�������ӿ�֮ǰ������øýӿ�*/ 
	virtual void InitEnv( u32 dwAppID ) = 0;
	
	/** ����  ���ӵ�CNS 
	 *  @param[in] dwIP	������CNS��IP��ַ
	 *  @param[in] dwPort  ������CNS�Ķ˿�
	 *  @param[in] strUser	�û���
	 *  @param[in] strPwd	����
     *  @param[in] achVersion TPad�汾��
	 *  @return �ɹ�����0,ʧ�ܷ��ط�0������
	 *  @remarks 
	 */
	virtual u16 ConnectCns(u32 dwIP, u32 dwPort,
		const CString& strUser, const CString& strPwd, 
        s8* achVersion, BOOL32 bConnect = TRUE) = 0;

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

	 /** ����  ��ȡ����ip
	 *  @param[in] 
	 *  @return  ����ip 
	 *  @remarks 
	 */
    virtual u32 GetLocalHostIP() = 0;

	/** 
	* ����  ����/ֹͣ˫������
	* @return  BOOL  TRUE:������ FALSE:ֹͣ
	* @remarks 
	*/
    virtual u16 StartDualCodeStream( const TTPCnMediaTransPort  &tVideoTransAddr , const TTPCnMediaTransPort  &tAudioTransAddr ) const = 0;

    virtual u16 StopDualCodeStream() const = 0;

    virtual u16 ReqKeyFrame( BOOL32 bForce ) const = 0;

	virtual TTPCnMediaTransPort GetVedioTransAddr() const = 0;
	
    virtual TTPCnMediaTransPort GetAudioTransAddr() const = 0;

	/** ����  ��ȡCNS����״̬
	*  @return TTPCnsConfStatus ����״̬
	*  @remarks 
	*/
	//virtual TTPCnsConfStatus& GetCnsConfStatus() const =0;
	virtual TTPCnsConfStatus GetCnsConfStatus() const = 0;


    /** ����  �ж��Ƿ�ɽ�������(cnc���пؾ�������Tpad)
	 *  @return  TRUE �����ӣ�FALSE	û����
	 *  @remarks 
	 */
    virtual BOOL IsReadyLogin( vector<TNodeInfo>&vctNodeList ) = 0;

	
    /** ����  ��ȡ��½ip
	 *  @param[in] 
	 *  @return  ��½ip
	 *  @remarks 
	 */
	virtual u32 GetLoginIp() = 0;
        
	//�ļ�����
	virtual u16 FileDualCmd( BOOL bStart ) = 0;
	virtual u16 FileDualRcvAddrCmd( EmTPAddDualRcvResult emAddDualRcvRes, TTPCnMediaTransPort &tVideoTransAddr, u16 nVideoNode ) = 0;

	virtual TTPMtVideoEncodeParameter& GetFileDualEncParam() = 0;  

	virtual TEncryptKey& GetFileDualkey() = 0;

	virtual u8 GetFileDualPayload() = 0;

	virtual TTPCnMediaTransPort& GetFileDualTransPort() = 0;

    virtual void TPadHomeKeyNty() = 0;

	virtual void OpenCenterCtrl() = 0;

    virtual void WBConfStartNty( bool bIsSelfStart, bool bIsSuccess  ) = 0;
    
    //virtual void NewConfCallRsp( BOOL bIsJoinWBConf ) = 0;
    
    virtual void WBConfStateNty( bool bIsInWBConf ) = 0;
    
    virtual void SetDataServerInfoCmd( u32 dwIp ) = 0;
    
	virtual void T300UpdateInd( BOOL bIsUpT300 ) = 0;
};

#endif