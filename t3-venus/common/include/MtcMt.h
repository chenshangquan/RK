#ifndef __MTCMT_H__
#define __MTCMT_H__

//#include "vccommon.h"		// �ն˿���ҵ��
#include "mtstruct.h"

class CMtcMt
{
public:
    CMtcMt(){ SetMt(0, 0, 0, _T(""), _T(""));}
    CMtcMt(u16 wMcuMtId){ SetMt(wMcuMtId); }
    CMtcMt(u32 dwMcuMtId){ SetMt(dwMcuMtId); }

	u8          m_byMtId;	// �ն�ID
	u8          m_byMcuId;	// McuID
	u8          m_byType;	// �ն�����
	CString     m_strAlias;	// �ն˱���
	CString     m_strE164Name;	// E164����

    u16 GetMcuMtId16() const { return MAKEWORD(m_byMtId, m_byMcuId); }
    u32 GetMcuMtId32() const { return (u32)(MAKEWPARAM(GetMcuMtId16(), 0)); }

	void SetMt(u8 byMtId, u8 byMcuId, u8 byType,
		const CString& strAlias,
		const CString& strE164Name)
	{
		m_byMtId = byMtId;
		m_byMcuId = byMcuId;
		m_byType = byType;
		m_strAlias = strAlias;
		m_strE164Name = strE164Name;
	};
    /*�������� SetMt
    ��    �ܣ� 
    ��    ���� u16 wMcuMtId
    �� �� ֵ�� void 
    ˵    ���� */
	void SetMt(u16 wMcuMtId)
	{
		// ��ʱ�����16�����������ʹ���McuId��MtId
		SetMt(LOBYTE(wMcuMtId), HIBYTE(wMcuMtId), 0, _T(""), _T(""));
	};
    /*�������� SetMt
    ��    �ܣ� 
    ��    ���� u32 dwMcuMtId
    �� �� ֵ�� void 
    ˵    ���� */
	void SetMt(u32 dwMcuMtId)
	{
		// ��ʱ�����32�����������ʹ���McuId��MtId
		SetMt(LOWORD(dwMcuMtId));
	};
    /*�������� SetMt
    ��    �ܣ� 
    ��    ���� TMtId tMtId
    �� �� ֵ�� void 
    ˵    ���� */
	inline void SetMt(const TMtId &tMtId)
	{
		m_byMcuId = tMtId.byMcuNo;
		m_byMtId = tMtId.byTerNo;
	}
    /*�������� SetMt
    ��    �ܣ� 
    ��    ���� TMtInfo tMtInfo
    �� �� ֵ�� void 
    ˵    ���� */
    inline void SetMt(const TMtInfo &tMtInfo)
    {
		m_byMcuId = tMtInfo.tLabel.byMcuNo;
        m_byMtId = tMtInfo.tLabel.byTerNo;
        m_strAlias = tMtInfo.achAlias;
    }
	void Clear(){SetMt(0, 0, 0, _T(""), _T(""));}

    /*�������� operator==
    ��    �ܣ� 
    ��    ���� const CMtcMt &cMt
    �� �� ֵ�� BOOL 
    ˵    ���� */
	BOOL operator==(const CMtcMt &cMt) const
	{
		return (m_byMcuId == cMt.m_byMcuId && m_byMtId == cMt.m_byMtId);
	}

    /*�������� operator!=
    ��    �ܣ� 
    ��    ���� const CMtcMt &cMt
    �� �� ֵ�� BOOL 
    ˵    ���� */
	BOOL operator!=(const CMtcMt &cMt) const
	{
		return !((*this) == cMt);
	}
    /*�������� operator=
    ��    �ܣ� 
    ��    ���� const CMtcMt &cMt
    �� �� ֵ�� CMtcMt& 
    ˵    ���� */
	CMtcMt& operator=(const CMtcMt &cMt)
	{
		SetMt(cMt.m_byMtId, cMt.m_byMcuId, cMt.m_byType,
			cMt.m_strAlias, cMt.m_strE164Name);
		return (*this);
	}
	
    /*�������� operator=
    ��    �ܣ� 
    ��    ���� const TMtInfo &tMtInfo
    �� �� ֵ�� CMtcMt& 
    ˵    ���� */
	CMtcMt& operator=(const TMtInfo &tMtInfo)
	{
		SetMt(tMtInfo);
		return (*this);
	}

    /*�������� Print
    ��    �ܣ� 
    ��    ���� 
    �� �� ֵ�� void 
    ˵    ���� */
	void Print() const
	{
		OspPrintf(TRUE, FALSE, "<McuId = %d, MtID = %d> MtAlias = %s\n", 
			m_byMcuId, m_byMtId, m_strAlias);
	}
	
}; // CMtcMt


//����һЩ��ʱ�ı���
#define MT_ADDRENTRY_NUM		1600 //callin callout missed 5*userdef(ÿ��192)
#define MT_ADDRMULTISET_NUM		16	
#define CTRL_POLL_MAXNUM		128

//��������õ��ĺ�
#define ASSIGN_MTINFO_WITH_CMTCMT(tMt, cMtcMt)				\
	tMt.tLabel.byMcuNo = cMtcMt.m_byMcuId;					\
	tMt.tLabel.byTerNo = cMtcMt.m_byMtId;					\
	memset(tMt.achAlias, 0, sizeof(TMtInfo) );				\
	memcpy(tMt.achAlias, (LPCTSTR)cMtcMt.m_strAlias, min( MT_MAX_NAME_LEN, cMtcMt.m_strAlias.GetLength() ) );\
	tMt.achAlias[MT_MAX_NAME_LEN] = '\0';				


#endif


