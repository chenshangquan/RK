#ifndef  _ASF_TRANS_
#define  _ASF_TRANS_

#if _MSC_VER > 1000
#pragma once
#endif

#include "asflib.h"
#include "helpmacro.h"
#include "string"

using namespace std;
//////////////////////////////////////////////////////////////////////////
// ERROR_CODE
OSPEVENT( ASF_TRANS_NO_ERROR,			 0 );
OSPEVENT( ASF_TRANS_FILENAME_EMPTY,		 1 );		//����/����������ļ�Ϊ��
OSPEVENT( ASF_TRANS_FILE_OPEN_FAILED,	 2 );		//�����������ļ�ʧ��
OSPEVENT( ASF_TRANS_GET_STREAM_NUM_FAILED, 3 );		//��ȡ�����Ը���ʧ��
OSPEVENT( ASF_TRANS_STREAM_NUM_ZERO,     4 );		//�����Ը���Ϊ0
OSPEVENT( ASF_TRANS_GET_STREAM_PROPERTY_FAILED, 5 );//��ȡ������ʧ��
OSPEVENT( ASF_TRANS_IN_MEMORY_SHORT,		6 );  //���������ռ�̫С
OSPEVENT( ASF_TRANS_WRITE_FILE_OPEN_FAILED, 7 );	//д�������ļ���ʧ��
OSPEVENT( ASF_TRANS_SET_STREAM_PROPERTY_FAILED, 8 ); //д��������ʧ��

//��ʼ: WPARAM: 1; LPARAM: 0
//����: WPARAM: 2; LPARAM: u32(���Ȱٷ���, ��λ���ִ���С�����һλ)
//����: WPARAM: 3; LPARAM: 0(�ɹ�), -1(�û�����ֹͣ), -2(�ռ䲻��), ����(Asflib�⺯������ֵ)
//��ʾ: WPARAM: 4; LPARAM: 0
#define WM_ASF_TRANS				    WM_USER + 0x4323

BEGIN_NAME_SPACE

class CAsfTransEncoder;
class CAsfTransDecoder;
typedef CAsfTransDecoder CDecoder;
typedef CAsfTransEncoder CEncoder;

extern UINT TransFunctionProc(LPVOID lpParam);
extern void CALLBACK EXPORT TimerProc(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime);
//extern void CALLBACK EXPORT TimerProc(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime);

//�����ϲ����Ȥ������
typedef struct tagStreamInfo
{
	u8		byType;				//��������,����Ƶ������Ƶ��
	u8		byStreamNumber;		//�����
	u8		byMediaType;		//ý�����ͣ���Ƶ261,263...,��Ƶg711,mp3....
	u32		dwDuration;			//����ʱ��
	u32		dwAverageBitrate;	//ƽ������
	s32		nWidth;				//ͼ�����Ŀ��
	s32		nHeight;			//ͼ�����ĸ߶�
public:
	tagStreamInfo()
	{
		memset(this, 0, sizeof(tagStreamInfo) );
	}
}TStreamInfo;

class CAsfTrans
{
public:
	typedef enum EmSuffix
	{
		emFirst = 0,
		emSecond,
		emMaxNum,
	}Suffix;

	enum EmStreamPropertyNum
	{
		emMaxStreamNum = 3
	};

	//��ASF�ļ����������Ӧ��˳��1,2,3, ���������±�ֱ�Ϊ0,1, 2
	enum EmStreamNum
	{
		emFirstAudio = 0,
		emFirstVideo = 1,
		emSecondVideo = 2
	};

#define MIN_WARN_SPACE          200//С��200M������ʾ
#define MIN_STOP_SPACE          50//С��50Mֱ��ֹͣ
    enum EmSpaceLeft
    {
        emSpaceOk       = 0,
        emSpaceWarning  = 1,
        emSpaceStop     = 2
    };

public:

	CAsfTrans();
	~CAsfTrans();

	/*�������� SetInStreamPath
    ��    �ܣ� ���������ļ���ȫ·��
    ��    ���� IN const char* szInPath
    �� �� ֵ�� void 
    ˵    ���� */
	void SetInStreamPath( IN const char* szInPath ) ;
    /*�������� GetInStreamPath
    ��    �ܣ� �õ������ļ���ȫ·�� 
    ��    ���� 
    �� �� ֵ�� const char* 
    ˵    ���� */
	const char* GetInStreamPath() const;

    /*�������� SetOutStreamPath
    ��    �ܣ� ��������ļ���ȫ·��
    ��    ���� IN const char* szOutPath
    �� �� ֵ�� void 
    ˵    ���� */
	void SetOutStreamPath( IN const char* szOutPath );
    /*�������� GetOutStreamPath
    ��    �ܣ� �õ�����ļ���ȫ·��
    ��    ���� 
    �� �� ֵ�� const char* 
    ˵    ���� */
	const char* GetOutStreamPath() const;

    /*�������� SetNotifyHWND
    ��    �ܣ� ����֪ͨ��Ϣ�ķ��ʹ��ھ��
    ��    ���� HWND hWnd
    �� �� ֵ�� void 
    ˵    ���� */
	void SetNotifyHWND(HWND hWnd);
    /*�������� RegisterMsg
    ��    �ܣ� ע��֪ͨ����ϢID
    ��    ���� u32 dwMsgId		    [in]��ϢID
    �� �� ֵ�� void 
    ˵    ���� ��ʼ: WPARAM: 1; LPARAM: 0
               ����: WPARAM: 2; LPARAM: u32(���Ȱٷ���, ��λ���ִ���С�����һλ)
               ����: WPARAM: 3; LPARAM: 0(�ɹ�), -1(�û�����ֹͣ), -2(�ռ䲻��), ����(Asflib�⺯������ֵ)
               ��ʾ: WPARAM: 4; LPARAM: 0 */
	void RegisterMsg(u32 dwMsgId);
    /*�������� IsDual
    ��    �ܣ� �Ƿ������·����
    ��    ���� 
    �� �� ֵ�� BOOL32 
    ˵    ���� ˫����ʱ�����ĸ���Ϊ3��һ·��Ƶ����·��Ƶ */
	BOOL32 IsDual() const
	{
		return m_dwStreamNum >= 3 ? TRUE : FALSE; 
	}

    /*�������� GetInStreamInfo
    ��    �ܣ� ��ȡ�����ļ���Ӧ����������Ϣ
    ��    ���� OUT TStreamInfo *ptStreamInfo  [in]�����������ʼ��ַ
               OUT u32 &dwNum				  [out]��������Ĵ�С/�Լ�ʵ�ʷ��صĴ�С	
    �� �� ֵ�� u16 
    ˵    ���� */
	u16 GetInStreamInfo( OUT TStreamInfo *ptStreamInfo, OUT u32 &dwNum );
    /*�������� SetOutStreamInfo
    ��    �ܣ� ��������ļ���Ӧ����������Ϣ
    ��    ���� IN TStreamInfo *ptStreamInfo		[in]�����������ʼ��ַ
               IN u32 &dwNum					[in]����Ĵ�С
    �� �� ֵ�� u16 
    ˵    ���� */
	u16 SetOutStreamInfo( IN TStreamInfo *ptStreamInfo, IN u32 &dwNum );

    /*�������� BeginTransform
    ��    �ܣ� ��ʼ��Ƶ��ʽ,������С��ת��
    ��    ���� 
    �� �� ֵ�� BOOL32 
    ˵    ���� */
	BOOL32 BeginTransform(void);

    /*=============================================================================
    �� �� ��:EndTransform
    ��    ��:�û�����ֹͣת��
    ��    ��:��
    ע    ��:��
    �� �� ֵ:��
    -------------------------------------------------------------------------------
    �޸ļ�¼:
    ��      ��  �汾    �޸���  �޸�����
    2006/07/27  4.0     ���    ����
    =============================================================================*/
    void EndTransform(void);

    /*=============================================================================
    �� �� ��:CheckSpace
    ��    ��:���ʣ��ռ�
    ��    ��:LPCTSTR lptrDisk           [in]    ���� C:\
    ע    ��:��
    �� �� ֵ:EmSpaceLeft
    -------------------------------------------------------------------------------
    �޸ļ�¼:
    ��      ��  �汾    �޸���  �޸�����
    2006/08/12  4.0     ���    ����
    =============================================================================*/
    EmSpaceLeft CheckSpace(LPCTSTR lptrDisk = NULL) const;

private:
	void Init();

	u16 GetInStreamProperty( OUT TStreamProperty * ptStreamPro, OUT u32 &dwNum );
	u16 SetOutStreamProperty( IN u32 dwNum );

    /*�������� GetOutStreamInfo
    ��    �ܣ� ��ȡ�����������Ϣ,��Ϊ�޷�ֱ�Ӵ�������ֱ�ӵõ�������ʽ
    ��    ���� OUT TStreamInfo* ptStreamInfo
               OUT u32 &dwNum
    �� �� ֵ�� u16 
    ˵    ���� */
	u16 GetOutStreamInfo(OUT TStreamInfo* ptStreamInfo, OUT u32 &dwNum );

	//forbid copy constructor and assign operator
	CAsfTrans(const CAsfTrans& rhs){};
	CAsfTrans& operator=(const CAsfTrans& rhs){};

private:
	CDecoder*		m_apDecoder[emMaxNum];			//�����Ľ�����
	CEncoder*		m_apEncoder[emMaxNum];			//�����ı�����

	string		    m_strInputPath;				//ת�����������ļ���ȫ·��
	string		    m_strOutputPath;				//ת����������ļ���ȫ·��
	BOOL32			m_bNeedReread;				//�Ƿ���Ҫ���¶�ȡ��������������	
	TStreamProperty	m_atInStreamProperty[emMaxStreamNum];	//�����ļ���������
	TStreamProperty m_atOutStreamProperty[emMaxStreamNum];	//���������������

	CKdvASFFileReader m_cReader;				//ASF �ļ��Ķ���		
	CKdvASFFileWriter m_cWriter;				//ASF �ļ�д����
	u32				  m_dwStreamNum;		//�ļ��е������ĸ���,�����ж��Ƿ���˫������
	HWND			  m_hWnd;					//֪ͨ�ϲ����ľ�� 
	u32				  m_dwMsg;				//֪ͨ��ϢID

	BOOL32			m_bOspInnerInit;			//��¼Osp�Ƿ����ڲ���ʼ����
	BOOL32			m_bTransfering;				//�Ƿ�����æ
    HANDLE          m_hEvent;                   //�ȴ��¼���

    HWND            m_hTimerWnd;        //��ʱ���

	friend UINT TransFunctionProc(LPVOID lpParam);
    friend void CALLBACK EXPORT TimerProc(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime);
};

END_NAME_SPACE

#endif