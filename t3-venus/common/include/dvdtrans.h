// dvdtrans.h: interface for the CDvdTrans class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DVDTRANS_H__A2DE305B_618D_419A_887E_755D39AE70DB__INCLUDED_)
#define AFX_DVDTRANS_H__A2DE305B_618D_419A_887E_755D39AE70DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "string"
using namespace std;
#include "asflib.h"

#pragma warning(disable : 4251)

#ifndef MIN_WARN_SPACE
#define MIN_WARN_SPACE          200//С��200M������ʾ
#define MIN_STOP_SPACE          50//С��50Mֱ��ֹͣ
#endif


#ifdef DVDTRANS_EXPORTS
#define DVDTRANS_API __declspec(dllexport)
#else
#define DVDTRANS_API __declspec(dllimport)
#endif

#define MAX_LANGUAGE     256       //������ַ���


enum
{
		DVD_Error_NoError				= 0,   // û�д�����ȷ����
		DVD_Error_FileNotFound			= 1,   // �ļ�û���ҵ�
		DVD_Error_InvalidDvdFile		= 2,	// ��Ч��DVD�ļ�
		DVD_Error_Transing              = 3,    //����ת����
		DVD_Error_OpenError             = 4,
		DVD_Error_UnknownError			= 5	// �޷�ȷ���Ĵ���		
};
typedef u16 Error_Code;

typedef struct tagDvdInfo{
	u8		byVideoType;		//��Ƶ261,263...,
	u32		dwVideoBitrate;	    //ƽ������
	u8      byAudioType;        //��Ƶg711,mp3....
	u8      byRatio;            //mp3 0,1,2,3,4
	u8      bySelectedAudio;    //ѡ�����Ƶ���
	u8      bySelectedSubPic;   //ѡ�����Ļ���
	
}TDvdInfo;

typedef struct tagDvdAttr{
	u8     byNumberOfAudio;
	LCID   adwAudioLanguage[8];
	u8     byNumberOfSubPic;
	LCID   adwSubPicLanguage[32];
	public:
		tagDvdAttr()
		{
			memset(this,0,sizeof(tagDvdAttr));
		}

}TDvdAttr;

class CDvdReader;
class CAudioEncoder;
class CAsfTransEncoder;
typedef CAsfTransEncoder CVideoEncoder;

class DVDTRANS_API CDvdTrans  
{
public:
	u16 GetDvdAttr( OUT TDvdAttr & tDvdAttr);
//	u16 GetSubPicAttr(IN u16 wSubPicIndex,OUT const TSubPicAttr &tSubPicAttr);
//	u16 GetSubPicCount(u16 &wSubPicCount);
//	u16 GetAudioAttr( IN u16 wAudioIndex,OUT TAudioAttr *ptAudioAttr);
//	u16 GetAudioCount(OUT u16 &wAudioCount);
	u16 SetOutInfo(const TDvdInfo &tDvdInfo);
	BOOL32 SetOutStreamPath(const char *szOutPath);
	BOOL32 SetInStreamPath(const char *szInPath=NULL);
	BOOL32 SetNotifyMsg(HWND hWnd,u32 dwMsg);
	u16 EndTransform();
	u16 BeginTransform();

    s32 CheckSpace(LPCTSTR lptrDisk  = NULL ) const;

	CDvdTrans();
	virtual ~CDvdTrans();

private:
	BOOL ChangeFile(u32 dwLastFileStamp);
	void YV12_I420(u8 *pInputBuf, u32 dwWidth, u32 dwHeight);
	VOID DealData(u32 dwStatus, TStreamDataPayload *ptStreamPayload);
	void Close();
	void DvdTransProc();
	BOOL32 ConfigAsfFileProperty(u32 dwWidth,u32 dwHeight);
	CDvdReader            *m_pcDvdReader;
	CKdvASFFileWriter     *m_pcAsfWriter;
	CAudioEncoder         *m_pcAudioEncoder;
	CVideoEncoder         *m_pcVideoEncoder;

	TDvdInfo    m_tDvdInfo;

    string 	    m_strInputPath;				//ת�����������ļ���ȫ·��
	string		    m_strOutputPath;			//ת����������ļ���ȫ·��
	HWND			m_hWnd;					//֪ͨ�ϲ����ľ�� 
	u32				m_dwMsg;				//֪ͨ��ϢID

//	HANDLE           m_hStopEvent;
	HANDLE           m_hDvdThread;

	BOOL32              m_bTransfering;         //�Ƿ�����æ
	volatile BOOL32     m_bStop;
	u8                  *m_pbyVideoBuf;
	u8                  *m_pbyZoomBuf;
	u8                  *m_pbyChangeBuf;
    u8              m_byAudioMode;      //���õ���Ƶ����
	u32             m_dwOutWidth;
	u32             m_dwOutHeight;
	u32              m_dwFileDuration;           //ms
	u32              m_dwFileSize;             //�ļ���С
	u32              m_dwFileIndex;            //��ǰת���ļ�
//	BOOL32           m_bFirstTime;
//	u64              m_llAudioTimeOffSet;
//	u64              m_llVideoTimeOffSet;
    BOOL32          m_bOspSelfInit;

    u32             m_dwLastFileStamp;
	u8              *m_pbyRemainBuf;
	u32             m_dwRemainLen;
	u8              *m_pbyAudioBuf;

	
    HWND                m_hTimer;

    TStreamProperty     m_atStreamProp[2];

	friend  void DvdTransThread(void *lpParam);
	friend  void DataProcCB(u32 dwStatus, TStreamDataPayload *ptStreamPayload,
                            void *pContext);
    friend VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime);

};

#endif // !defined(AFX_DVDTRANS_H__A2DE305B_618D_419A_887E_755D39AE70DB__INCLUDED_)
