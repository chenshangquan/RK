// License.h: interface for the CLicense class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LICENSEMGR_H__FAE7BA24_0B89_44AB_BD75_73E9C5CF6D66__INCLUDED_)
#define AFX_LICENSEMGR_H__FAE7BA24_0B89_44AB_BD75_73E9C5CF6D66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define LICENSE_LEN             25
#define LICENSE_RANDOM_LEN      19
#define LICENSE_VER_LEN         2


class CLicense  
{
public:
	CLicense();
	virtual ~CLicense();

public:
    // pbyVerҪ�������������֣�0-9������10����1.0�汾
    static BOOL32 GenerateLicense( char *pbyRamdom, char *pbyVer, char *pbyLicense, int nLenBuf );

    static BOOL32 ValidateLicense( char *pbyLicense );

    static BOOL32 GetLicenseVer( char *pbyLicense, char *pbyVer, int nBufLen );

private:
    // ����CRCУ����
    // *ptrָ���ͻ����������ֽڣ�len��Ҫ���͵����ֽ�����
    static unsigned short CalCRC(unsigned char *ptr, unsigned char len);

    // ��һ����ֵӳ�䵽�ַ�
    static char Int2char( int val );

    // ��һ����ֵӳ�䵽�ַ���
    static int Char2int( char ch );

private:
    static const char *m_s_pMap2char;
};

#endif // !defined(AFX_LICENSEMGR_H__FAE7BA24_0B89_44AB_BD75_73E9C5CF6D66__INCLUDED_)
