// tvwCtrlIF.h: interface for the CTvwCtrlIF class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TVWCTRLIF_H__6765F8CF_B128_456F_8136_7FEE61CC6882__INCLUDED_)
#define AFX_TVWCTRLIF_H__6765F8CF_B128_456F_8136_7FEE61CC6882__INCLUDED_
#include "kdvdispevent.h"
#include "cmsstruct.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTvwCtrlIF : public  CKdvDispEvent  
{
public:
     /**
    * ����:	 ���󲥷�
    * @param [int]  tTvwInfo�����󲥷ŵĵ���ǽ��Ϣ
    * @return    
    * @remarks  �ɹ�����0��ʧ�ܷ��ش�����
    */
    virtual u16 PlayHduReq( const TTPHduPlayReq & tTvwInfo ) = 0 ;


    /**
    * ����:	 ֹͣ����
    * @param [int]  tTvwInfo������ֹͣ���ŵĵ���ǽ��Ϣ
    * @return    
    * @remarks  �ɹ�����0��ʧ�ܷ��ش�����
    */
    virtual u16 StopHduReq( const TTPHduPlayReq & tTvwInfo ) = 0 ;

    /**
    * ����:	 ֹͣ���е���ǽ����
    * @return    
    * @remarks  �ɹ�����0��ʧ�ܷ��ش�����
    */
    virtual u16 StopAllHduReq() = 0;

    /**
    * ����:	 ��ȡ����ǽ��������
    * @return   THduPlanData ����ǽ��������
    * @remarks  
    */
    virtual const THduPlanData& GetTvwPlanData() const = 0;

};

#endif // !defined(AFX_TVWCTRLIF_H__6765F8CF_B128_456F_8136_7FEE61CC6882__INCLUDED_)
