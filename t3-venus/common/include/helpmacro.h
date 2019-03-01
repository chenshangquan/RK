#ifndef  _ASF_TRANS_HELPMACRO_
#define _ASF_TRANS_HELPMACRO_


#include "vfw.h"

#define SAFE_DEL(p) { delete p; p = NULL; }
#define SAFE_ARR_DEL(p) { delete[] p; p = NULL; }

#define BEGIN_NAME_SPACE	\
	namespace CodeTrans{

#define END_NAME_SPACE }

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#define MAX_FRAME_WIDTH        (s32)1024//
#define MAX_FRAME_HEIGHT       (s32)768//

#define GUID_WMMEDIASUBTYPE_KDM4  {0x344D444B, 0x0000, 0x0010, {0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71}}
#define GUID_WMMEDIASUBTYPE_KDM2  {0x324D444B, 0x0000, 0x0010, {0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71}}
#define GUID_WMMEDIASUBTYPE_KDH1  {0x3148444B, 0x0000, 0x0010, {0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71}}
#define GUID_WMMEDIASUBTYPE_KDH3  {0x3348444B, 0x0000, 0x0010, {0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71}}
#define GUID_WMMEDIASUBTYPE_KDH4  {0x3448444B, 0x0000, 0x0010, {0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71}}

typedef struct tagFOURCC
{
	u32 dwFOURCC;
	u8  byBitCount;
}TFOURCC;

const TFOURCC g_tFrameFormat[3]=
{
	{ BI_RGB, 24 },
    { mmioFOURCC('U','Y','V','Y'), 16},
	{ mmioFOURCC('I','4','2','0'), 12},
};

const TFOURCC g_tEncType[5]=
{
	{ mmioFOURCC('k','d','m','4'), 24 },
    { mmioFOURCC('k','d','h','1'), 24},
	{ mmioFOURCC('k','d','h','3'), 24},
	{ mmioFOURCC('k','d','h','4'), 16},
	{ mmioFOURCC('k','d','m','2'), 24},
};


typedef struct tagVideoEncType
{
	u32  m_dwFOURCC;
	u8   m_byBitCount;
	GUID m_subtype;
}TVideoEncType;

const TVideoEncType g_tVideoEncTypeArr[5]=
{
	{ mmioFOURCC('K','D','M','4'), 24, GUID_WMMEDIASUBTYPE_KDM4},
	{ mmioFOURCC('K','D','H','1'), 24, GUID_WMMEDIASUBTYPE_KDH1},
	{ mmioFOURCC('K','D','H','3'), 24, GUID_WMMEDIASUBTYPE_KDH3},
	{ mmioFOURCC('K','D','H','4'), 24, GUID_WMMEDIASUBTYPE_KDH4},
	{ mmioFOURCC('K','D','M','2'), 24, GUID_WMMEDIASUBTYPE_KDM2},
};



BEGIN_NAME_SPACE

/*��Ƶ�������*/
typedef struct VideoEncParam
{
	u8  m_byEncType;   /*ͼ���������*/
    u8  m_byRcMode;    /*ͼ��ѹ�����ʿ��Ʋ���*/
    u16  m_byMaxKeyFrameInterval;/*I֡�����P֡��Ŀ*/
    u8  m_byMaxQuant;  /*�����������(1-31)*/
    u8  m_byMinQuant;  /*��С��������(1-31)*/
    u8  m_byReserved1; /*����*/
	u8  m_byQcMode; /*ͼ���������ʿ��Ʋ���,�������Ȼ����ٶ�����*/
    u8  m_byQI;
    u8  m_byQP;
    u16  m_wBitRate;    /*���������(Kbps)*/
    u16  m_wReserved4;  /*����*/		

	public:
		VideoEncParam()
		{
			memset(this, 0, sizeof(VideoEncParam) );
		}
}TVideoEncParam;


//--comment: ���½ṹժ��MediaSDK,�����������Ӧ���ĵ�

//Video Encode Param
typedef struct tagEncParamVideo
{
	u8            m_byEncType;
	HIC			  m_hIC; 
	BITMAPINFO    m_bmpEnc;
	s32           m_nBufSize;
	u8*           m_pEncBuf;
    u8            m_byRcMode;    /*ͼ��ѹ�����ʿ��Ʋ���*/
    u16           m_wMaxKeyFrameInterval;/*I֡�����P֡��Ŀ*/
    u8            m_byMaxQuant;  /*�����������(1-31)*/
    u8            m_byMinQuant;  /*��С��������(1-31)*/
    u8			  m_byQPMin;        // ��С��������(1-51)
    u8			  m_byQPMax;        // �����������(1-51)
    u16           m_wBitRate;    /*���������(Kbps)*/
    u16           m_wReserved4;  /*����*/
	public:
		tagEncParamVideo()
		{
			memset( this, 0, sizeof(tagEncParamVideo) );
		}
}TEncParamVideo;

//�����������ṹ
typedef struct
{
	s32 rc_mode;
	s32 bitrate;
	s32 quality;
	s32	quant;
	s32 rc_buffersize;
	s32 fourcc_used;
	s32 quant_type;
	s32 max_key_interval;
	s32 min_quant;
	s32 max_quant;
	s32 bidirectional;
	s32 deinterlacing;
	s32 adapt_quant;
	s32 cpu;
	s32 max_vbv_delay;
	s32 interlaced_coding;
	s32 top_field_first;
	s32 alternative_scan;
	s32 save;
} CONFIG_MP4V;

typedef struct {
    s32	FrameFormat;
    s32	BitRate;
    s32	IFramePeriod;
    s32	IntraFrame;
    s32	MinQUANT;
    s32	MaxQUANT;
    s32	HasRTPPacketInfo;
    s32 nFrameRate;
}TH261EncParam;


typedef struct
{
    u32 fccType;      //����ΪСд"vidc"
    u32 fccHandler;   //����ΪСд"kdh1"
    TH261EncParam EncParam;
}CONFIG_H261;      //��State��Ϊ��ͬVfW���ĵ�һ��


typedef struct 
{
	s32 bRateControl;			// �������Ƿ�ʹ�����ʿ��ƣ�1�����ã�0�������ã��������
	s32 BitsPerSecond;			// ���ʣ���λ��bit/s��һ�������100,000~1000,000֮��
	
	s32 PRate;				 // I֡�ļ����һ��Ϊ12
	
	s32 QI;                  // I֡�ĳ�ʼ��������
	s32 QP;                  // P֡�ĳ�ʼ��������
	
	s32 min_quantizer;
	s32 max_quantizer;	
	
	s32 sourceFormat;		 // 1 : sub_CIF; 2 : CIF; 3 : cif;  4 : 4cif 
	
}H263_CONFIG;


typedef struct 
{
	s32 rc_mode;			// �������Ƿ�ʹ�����ʿ��ƣ�1�����ã�0�������ã��������
	s32 bitrate;			// ���ʣ���λ��bit/s��һ�������100,000~1000,000֮��
	s32 quality;			// 1:�������ȣ� 0���ٶ�����,һ�����1
	
	s32 fourcc_used;
	
	s32 max_key_interval;    // I֡�ļ����һ��Ϊ12��15��0��ʾֻ�е�һ֡��I֡
	
	s32 QPMin;                  // ��С��������(1-51)
	s32 QPMax;                  // �����������(1-51)
		
	s32 nCodecMode;			 // 0:RTP�����뷽ʽ��Ĭ�ϣ�   1:֡���뷽ʽ
	
}H264_CONFIG;

typedef struct 
{
	int BitsPerSecond;		// ���ʣ���λ��bit/s��һ�������100,000~1000,000֮��
	
	int PRate;				// I֡�ļ����һ��Ϊ12
	
	int min_quantizer;
	int max_quantizer;
	
}MPG2_CONFIG;

END_NAME_SPACE

#endif