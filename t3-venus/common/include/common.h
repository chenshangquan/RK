#ifndef _NMS_COMMON_H_
#define _NMS_COMMON_H_

/* 
    ��Ƶ�����Ʒҵ����������ģ��ͳһ�����汾��ǰ׺
    ����ͳһ�汾�滮�趨���������Ӧ������ϵͳ(��ģ��汾����ͻ)��������������

    GetMcuBuildVersion()��GetMtBuildVersion()��
    ���У�MT����ϵͳ��MTC��PCDV��PCMT��MtBatchConfig��
                      NetworkTest��SUS��SUC��StreamPlayer ���� MT �汾��
    ������������ MCS��VOS��nmcui��gkc��dcc��rsc�ȣ� ���� MCU �汾��
    ���ýӿ�ʱ���𿪡�

    ��ʽ�����汾�ĸ�ʽ���£�
    V.R.B.SP.Fix.���ڣ���1.1.2.0.0.080911
*/
#define KDV_NMS_MCU_VER_PREFIX          (const char*)"4.5.3.0.0."
#define KDV_NMS_MT_VER_PREFIX           (const char*)"2.1.1.0.2." //(const char*)"2.1.1.0.0." 2010-12-1 by yjj
#define KDV_NMS_CMS_VER_PREFIX          (const char*)"1.1.1.1.0." // 2011-10-8 by yjj   ver.release.built.sp1.fix
#define KDV_NMS_CNC_VER_PREFIX          (const char*)"1.1.3.0.0." // V1R1B3
#define KDV_NMS_CNSTOOL_VER_PREFIX      (const char*)"1.1.6.4.1." // V1R1B6 sp4
#define KDV_NMS_UMC_VER_PREFIX          (const char*)"1.1.3.0.0." // V1R1B3
#define KDV_NMS_UMSTOOL_VER_PREFIX      (const char*)"1.1.6.4.1." // V1R1B5 sp4

s8* GetBuildVersion();
s8* GetMcuBuildVersion();
s8* GetMtBuildVersion();
s8* GetCncBuildVersion();
s8* GetCnsToolBuildVersion();
s8* GetUmcBuildVersion();
s8* GetUmsToolBuildVersion();

#endif

#ifdef _NMS_COMMON_CPP_

#include <string.h>
s8* GetBuildVersion()
{
    static s8 sabyVersionBuf[128] = { 0 };
    if ( strlen( sabyVersionBuf ) != 0 )
    {
        return sabyVersionBuf;
    }

    s8 achMon[16] = {0};
    u32 byDay = 0;
    u32 byMonth = 0;
    u32 wYear = 0;
    static s8 achFullDate[24] = {0};

    s8 achDate[32] = {0};
    sprintf(achDate, "%s", __DATE__);

#ifdef WIN32
    sscanf(achDate, "%s %d %d", achMon, &byDay, &wYear );

    if ( 0 == stricmp( achMon, "JAN") )
        byMonth = 1;
    else if ( 0 == stricmp( achMon, "FEB") )
        byMonth = 2;
    else if ( 0 == stricmp( achMon, "MAR") )
        byMonth = 3;
    else if ( 0 == stricmp( achMon, "APR") )
        byMonth = 4;
    else if ( 0 == stricmp( achMon, "MAY") )
        byMonth = 5;
    else if ( 0 == stricmp( achMon, "JUN") )
        byMonth = 6;
    else if ( 0 == stricmp( achMon, "JUL") )
        byMonth = 7;
    else if ( 0 == stricmp( achMon, "AUG") )
        byMonth = 8;
    else if ( 0 == stricmp( achMon, "SEP") )
        byMonth = 9;
    else if ( 0 == stricmp( achMon, "OCT") )
        byMonth = 10;
    else if ( 0 == stricmp( achMon, "NOV") )
        byMonth = 11;
    else if ( 0 == stricmp( achMon, "DEC") )
        byMonth = 12;
    else
        byMonth = 0;

    sprintf( achFullDate, "%02d%02d%02d", wYear - 2000, byMonth, byDay );

    sprintf( sabyVersionBuf, "%s%s", KDV_NMS_MCU_VER_PREFIX, achFullDate );

#else
	sprintf( sabyVersionBuf, "%s%s", KDV_NMS_MCU_VER_PREFIX, achDate );
#endif


    return sabyVersionBuf;
}

s8* GetMcuBuildVersion()
{
    static s8 sabyVersionBuf[128] = { 0 };
    if ( strlen( sabyVersionBuf ) != 0 )
    {
        return sabyVersionBuf;
    }

    s8 achMon[16] = {0};
    u32 byDay = 0;
    u32 byMonth = 0;
    u32 wYear = 0;
    static s8 achFullDate[24] = {0};

    s8 achDate[32] = {0};
    sprintf(achDate, "%s", __DATE__);

#ifdef WIN32
    sscanf(achDate, "%s %d %d", achMon, &byDay, &wYear );

    if ( 0 == stricmp( achMon, "JAN") )
        byMonth = 1;
    else if ( 0 == stricmp( achMon, "FEB") )
        byMonth = 2;
    else if ( 0 == stricmp( achMon, "MAR") )
        byMonth = 3;
    else if ( 0 == stricmp( achMon, "APR") )
        byMonth = 4;
    else if ( 0 == stricmp( achMon, "MAY") )
        byMonth = 5;
    else if ( 0 == stricmp( achMon, "JUN") )
        byMonth = 6;
    else if ( 0 == stricmp( achMon, "JUL") )
        byMonth = 7;
    else if ( 0 == stricmp( achMon, "AUG") )
        byMonth = 8;
    else if ( 0 == stricmp( achMon, "SEP") )
        byMonth = 9;
    else if ( 0 == stricmp( achMon, "OCT") )
        byMonth = 10;
    else if ( 0 == stricmp( achMon, "NOV") )
        byMonth = 11;
    else if ( 0 == stricmp( achMon, "DEC") )
        byMonth = 12;
    else
        byMonth = 0;

    sprintf( achFullDate, "%02d%02d%02d", wYear - 2000, byMonth, byDay );

    sprintf( sabyVersionBuf, "%s%s", KDV_NMS_MCU_VER_PREFIX, achFullDate );

#else
	sprintf( sabyVersionBuf, "%s%s", KDV_NMS_MCU_VER_PREFIX, achDate );
#endif

    return sabyVersionBuf;
}

s8* GetMtBuildVersion()
{
    static s8 sabyVersionBuf[128] = { 0 };
    if ( strlen( sabyVersionBuf ) != 0 )
    {
        return sabyVersionBuf;
    }

    s8 achMon[16] = {0};
    u32 byDay = 0;
    u32 byMonth = 0;
    u32 wYear = 0;
    static s8 achFullDate[24] = {0};

    s8 achDate[32] = {0};
    sprintf(achDate, "%s", __DATE__);

#ifdef WIN32
    sscanf(achDate, "%s %d %d", achMon, &byDay, &wYear );

    if ( 0 == stricmp( achMon, "JAN") )
        byMonth = 1;
    else if ( 0 == stricmp( achMon, "FEB") )
        byMonth = 2;
    else if ( 0 == stricmp( achMon, "MAR") )
        byMonth = 3;
    else if ( 0 == stricmp( achMon, "APR") )
        byMonth = 4;
    else if ( 0 == stricmp( achMon, "MAY") )
        byMonth = 5;
    else if ( 0 == stricmp( achMon, "JUN") )
        byMonth = 6;
    else if ( 0 == stricmp( achMon, "JUL") )
        byMonth = 7;
    else if ( 0 == stricmp( achMon, "AUG") )
        byMonth = 8;
    else if ( 0 == stricmp( achMon, "SEP") )
        byMonth = 9;
    else if ( 0 == stricmp( achMon, "OCT") )
        byMonth = 10;
    else if ( 0 == stricmp( achMon, "NOV") )
        byMonth = 11;
    else if ( 0 == stricmp( achMon, "DEC") )
        byMonth = 12;
    else
        byMonth = 0;

    sprintf( achFullDate, "%02d%02d%02d", wYear - 2000, byMonth, byDay );

    sprintf( sabyVersionBuf, "%s%s", KDV_NMS_MT_VER_PREFIX, achFullDate );

#else
	sprintf( sabyVersionBuf, "%s%s", KDV_NMS_MT_VER_PREFIX, achDate );
#endif

    return sabyVersionBuf;
}


s8* GetCncBuildVersion()
{
    static s8 sabyVersionBuf[128] = { 0 };
    if ( strlen( sabyVersionBuf ) != 0 )
    {
        return sabyVersionBuf;
    }
    
    s8 achMon[16] = {0};
    u32 byDay = 0;
    u32 byMonth = 0;
    u32 wYear = 0;
    static s8 achFullDate[24] = {0};
    
    s8 achDate[32] = {0};
    sprintf(achDate, "%s", __DATE__);
    
#ifdef WIN32
    sscanf(achDate, "%s %d %d", achMon, &byDay, &wYear );
    
    if ( 0 == stricmp( achMon, "JAN") )
        byMonth = 1;
    else if ( 0 == stricmp( achMon, "FEB") )
        byMonth = 2;
    else if ( 0 == stricmp( achMon, "MAR") )
        byMonth = 3;
    else if ( 0 == stricmp( achMon, "APR") )
        byMonth = 4;
    else if ( 0 == stricmp( achMon, "MAY") )
        byMonth = 5;
    else if ( 0 == stricmp( achMon, "JUN") )
        byMonth = 6;
    else if ( 0 == stricmp( achMon, "JUL") )
        byMonth = 7;
    else if ( 0 == stricmp( achMon, "AUG") )
        byMonth = 8;
    else if ( 0 == stricmp( achMon, "SEP") )
        byMonth = 9;
    else if ( 0 == stricmp( achMon, "OCT") )
        byMonth = 10;
    else if ( 0 == stricmp( achMon, "NOV") )
        byMonth = 11;
    else if ( 0 == stricmp( achMon, "DEC") )
        byMonth = 12;
    else
        byMonth = 0;
    
    sprintf( achFullDate, "%04d%02d%02d", wYear, byMonth, byDay );
    
    sprintf( sabyVersionBuf, "%s%s", KDV_NMS_CNC_VER_PREFIX, achFullDate );
    
#else
    sprintf( sabyVersionBuf, "%s%s", KDV_NMS_CNC_VER_PREFIX, achDate );
#endif
    
    return sabyVersionBuf;
}

s8* GetCnsToolBuildVersion()
{
    static s8 sabyVersionBuf[128] = { 0 };
    if ( strlen( sabyVersionBuf ) != 0 )
    {
        return sabyVersionBuf;
    }
    
    s8 achMon[16] = {0};
    u32 byDay = 0;
    u32 byMonth = 0;
    u32 wYear = 0;
    static s8 achFullDate[24] = {0};
    
    s8 achDate[32] = {0};
    sprintf(achDate, "%s", __DATE__);
    
#ifdef WIN32
    sscanf(achDate, "%s %d %d", achMon, &byDay, &wYear );
    
    if ( 0 == stricmp( achMon, "JAN") )
        byMonth = 1;
    else if ( 0 == stricmp( achMon, "FEB") )
        byMonth = 2;
    else if ( 0 == stricmp( achMon, "MAR") )
        byMonth = 3;
    else if ( 0 == stricmp( achMon, "APR") )
        byMonth = 4;
    else if ( 0 == stricmp( achMon, "MAY") )
        byMonth = 5;
    else if ( 0 == stricmp( achMon, "JUN") )
        byMonth = 6;
    else if ( 0 == stricmp( achMon, "JUL") )
        byMonth = 7;
    else if ( 0 == stricmp( achMon, "AUG") )
        byMonth = 8;
    else if ( 0 == stricmp( achMon, "SEP") )
        byMonth = 9;
    else if ( 0 == stricmp( achMon, "OCT") )
        byMonth = 10;
    else if ( 0 == stricmp( achMon, "NOV") )
        byMonth = 11;
    else if ( 0 == stricmp( achMon, "DEC") )
        byMonth = 12;
    else
        byMonth = 0;
    
    sprintf( achFullDate, "%04d%02d%02d", wYear, byMonth, byDay );
    
    sprintf( sabyVersionBuf, "%s%s", KDV_NMS_CNSTOOL_VER_PREFIX, achFullDate );
    
#else
    sprintf( sabyVersionBuf, "%s%s", KDV_NMS_CNSTOOL_VER_PREFIX, achDate );
#endif
    
    return sabyVersionBuf;
}

s8* GetUmcBuildVersion()
{
    static s8 sabyVersionBuf[128] = { 0 };
    if ( strlen( sabyVersionBuf ) != 0 )
    {
        return sabyVersionBuf;
    }
    
    s8 achMon[16] = {0};
    u32 byDay = 0;
    u32 byMonth = 0;
    u32 wYear = 0;
    static s8 achFullDate[24] = {0};
    
    s8 achDate[32] = {0};
    sprintf(achDate, "%s", __DATE__);
    
#ifdef WIN32
    sscanf(achDate, "%s %d %d", achMon, &byDay, &wYear );
    
    if ( 0 == stricmp( achMon, "JAN") )
        byMonth = 1;
    else if ( 0 == stricmp( achMon, "FEB") )
        byMonth = 2;
    else if ( 0 == stricmp( achMon, "MAR") )
        byMonth = 3;
    else if ( 0 == stricmp( achMon, "APR") )
        byMonth = 4;
    else if ( 0 == stricmp( achMon, "MAY") )
        byMonth = 5;
    else if ( 0 == stricmp( achMon, "JUN") )
        byMonth = 6;
    else if ( 0 == stricmp( achMon, "JUL") )
        byMonth = 7;
    else if ( 0 == stricmp( achMon, "AUG") )
        byMonth = 8;
    else if ( 0 == stricmp( achMon, "SEP") )
        byMonth = 9;
    else if ( 0 == stricmp( achMon, "OCT") )
        byMonth = 10;
    else if ( 0 == stricmp( achMon, "NOV") )
        byMonth = 11;
    else if ( 0 == stricmp( achMon, "DEC") )
        byMonth = 12;
    else
        byMonth = 0;
    
    sprintf( achFullDate, "%04d%02d%02d", wYear, byMonth, byDay );
    
    sprintf( sabyVersionBuf, "%s%s", KDV_NMS_UMC_VER_PREFIX, achFullDate );
    
#else
    sprintf( sabyVersionBuf, "%s%s", KDV_NMS_UMC_VER_PREFIX, achDate );
#endif
    
    return sabyVersionBuf;
}

s8* GetUmsToolBuildVersion()
{
    static s8 sabyVersionBuf[128] = { 0 };
    if ( strlen( sabyVersionBuf ) != 0 )
    {
        return sabyVersionBuf;
    }
    
    s8 achMon[16] = {0};
    u32 byDay = 0;
    u32 byMonth = 0;
    u32 wYear = 0;
    static s8 achFullDate[24] = {0};
    
    s8 achDate[32] = {0};
    sprintf(achDate, "%s", __DATE__);
    
#ifdef WIN32
    sscanf(achDate, "%s %d %d", achMon, &byDay, &wYear );
    
    if ( 0 == stricmp( achMon, "JAN") )
        byMonth = 1;
    else if ( 0 == stricmp( achMon, "FEB") )
        byMonth = 2;
    else if ( 0 == stricmp( achMon, "MAR") )
        byMonth = 3;
    else if ( 0 == stricmp( achMon, "APR") )
        byMonth = 4;
    else if ( 0 == stricmp( achMon, "MAY") )
        byMonth = 5;
    else if ( 0 == stricmp( achMon, "JUN") )
        byMonth = 6;
    else if ( 0 == stricmp( achMon, "JUL") )
        byMonth = 7;
    else if ( 0 == stricmp( achMon, "AUG") )
        byMonth = 8;
    else if ( 0 == stricmp( achMon, "SEP") )
        byMonth = 9;
    else if ( 0 == stricmp( achMon, "OCT") )
        byMonth = 10;
    else if ( 0 == stricmp( achMon, "NOV") )
        byMonth = 11;
    else if ( 0 == stricmp( achMon, "DEC") )
        byMonth = 12;
    else
        byMonth = 0;
    
    sprintf( achFullDate, "%04d%02d%02d", wYear, byMonth, byDay );
    
    sprintf( sabyVersionBuf, "%s%s", KDV_NMS_UMSTOOL_VER_PREFIX, achFullDate );
    
#else
    sprintf( sabyVersionBuf, "%s%s", KDV_NMS_UMSTOOL_VER_PREFIX, achDate );
#endif
    
    return sabyVersionBuf;
}

#endif  //  _NMS_COMMON_H_
