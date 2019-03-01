// vcdconvert.h: interface for the CVcdConvert class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VCDCONVERT_H__C28639EF_BB38_4CBE_8B09_899FF6EEC356__INCLUDED_)
#define AFX_VCDCONVERT_H__C28639EF_BB38_4CBE_8B09_899FF6EEC356__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <vector>
#include "kdvtype.h"
#include "StdAfx.h"	// Added by ClassView

#ifdef VCDTRANS_EXPORTS
#define VCDTRANS_API __declspec(dllexport)
#else
#define VCDTRANS_API __declspec(dllimport)
#endif

typedef struct tagVideoInfo
{
	u8		byType;				//��������,����Ƶ������Ƶ��
	u8		byStreamNumber;		//�����
	u8		byMediaType;		//ý�����ͣ���Ƶ261,263...,��Ƶg711,mp3....
	u32		dwDuration;			//����ʱ��
	u32		dwAverageBitrate;	//ƽ������
	s32		nWidth;				//ͼ�����Ŀ��
	s32		nHeight;			//ͼ�����ĸ߶�
public:
	tagVideoInfo()
	{
		memset(this, 0, sizeof(tagVideoInfo));
	}
}TVideoInfo;
typedef enum enSpaceLeft
{
	emSpaceOk       = 0,
	emSpaceWarning  = 1,
	emSpaceStop     = 2
}enumSpaceLeft;

class CVCDTrans;

VCDTRANS_API int vcdtranver(void);

class VCDTRANS_API CVcdConvert  
{
public:
	enumSpaceLeft CheckSpace(LPCTSTR lptrDisk  = NULL ) const;
	VOID EndTransform();
	u16 GetInStreamInfo( TVideoInfo *ptStreamInfo, u32 &dwNum );
	const char* GetOutStreamPath();
    void GetInStreamPath(std::vector<std::string> &vctstrInputFile);
	u16 GetOutStreamInfo(const TVideoInfo *ptStreamInfo);
	VOID SetNotifyMsg(HWND hWnd,u32 dwMsg);
	VOID SetOutStreamPath(const char *szOutPath);
	VOID SetInStreamPath(const s8 (*lptrInputFile)[MAX_PATH + 1], s32 nFileNum);
	BOOL32 SetOutInfo(TVideoInfo *ptVideoInfo, u8 byAudioType,u8 byRatio=0);
	BOOL32 BeginTransform();
	CVcdConvert();
	virtual ~CVcdConvert();
private:
	CVCDTrans *m_pVcdTrans;
	BOOL32     m_bOspSelfInitd;

};

#endif // !defined(AFX_VCDCONVERT_H__C28639EF_BB38_4CBE_8B09_899FF6EEC356__INCLUDED_)
