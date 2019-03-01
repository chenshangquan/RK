#ifndef _h_tpadplatstruct_h__
#define _h_tpadplatstruct_h__

#include "ummessagestruct.h"
#include <winioctl.h>


enum emTPadSubType
{
    emTPad_none = 0,
    emTPad_cnc = 0x001,
    emTPad_centerctrl = 0x002,
};

//tpad�ӹ�������tpad����Ϣ
typedef struct tagTPadSubInfo
{
    u32 dwIp;
    u32 dwPort;
    emTPadSubType emType;
    
    tagTPadSubInfo()
    {
        dwIp = 0;
        dwPort = 0;
        emType = emTPad_none;
    }
}TTPadSubInfo;

//���ӵ�TPad�Ľڵ���Ϣ
typedef struct tagNodeInfo
{
    u32 dwNodeId;
    u32 dwInstId;
    emTPadSubType emSubType;
    
    tagNodeInfo()
    {
        dwNodeId = 0;
        dwInstId = 0;
        emSubType = emTPad_none;
    }

    BOOL operator ==( const tagNodeInfo &tInfo )
    {
        if ( dwNodeId == tInfo.dwNodeId && dwInstId == tInfo.dwInstId )
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
	}
}TNodeInfo;


//TPad��¼��Ϣ
typedef struct tagPadLoginInfo
{
    u32     dwCnsIp;
    u32     dwLocalIp;
    CLoginRequest  cUserInfo;
      
    tagPadLoginInfo()
    {
        dwCnsIp = 0;
        dwLocalIp = 0;
    }
}TPadLoginInfo;


//TPad ��Item��Ϣ
typedef struct tagMainMenuInfo
{
	CString strName;	            //����
	int     nIndex;                 //��Ŀ����
	CString strItemFunc;            //��Ŀ�����¼�
	CString strImgFolder;           //��ĿͼƬ·��
    CString strExePath;             //exe·��������
    DWORD   dwProcID;               //exe�򿪺�Ľ��̺ţ�����Ϊ��Ч�Ľ��̺�
	CString strExeClassName;        //exe�����������������ҵ���������ʾ
	CString strExeCaption;          //exe�����ڱ���
	BOOL    bShow;                  //�Ƿ�Ӧ����ʾ
	
	tagMainMenuInfo()
	{
		nIndex = 0;
        dwProcID = 0;
		bShow = TRUE;
		strName.Empty();
		strItemFunc.Empty();
		strImgFolder.Empty();
        strExePath.Empty();
		strExeClassName.Empty();
		strExeCaption.Empty();
	}

	void SetNull()
	{
		nIndex = 0;
        dwProcID = 0;
		bShow = TRUE;
		strName.Empty();
		strItemFunc.Empty();
		strImgFolder.Empty();
        strExePath.Empty();
		strExeClassName.Empty();
		strExeCaption.Empty();
	}
}TMainMenuInfo;


//��ϵͳ��������
enum EM_OSType
{
	emLogOff = 0,      //ע��
	emShutDown,        //�ػ�
	emReboot,          //����
	emSleep,           //����
};

//Wifi��Ŀ����
typedef struct tagWiFiItem
{
    CString  strSSID;       //��������
	BOOL     bConnect;      //�Ƿ�����
    BOOL     bEncrypt;      //�Ƿ����
	s32      nAuthType;     //����ģʽ
    s32      nQuality;      //�ź�ǿ��

	tagWiFiItem()
	{
		strSSID.Empty();
		bConnect = FALSE;
		bEncrypt = FALSE;
		nAuthType = 1;
		nQuality = 0;
	}
}TWifiItem;


//ͼƬ�ֻ�����
enum Em_ImgSchm{ 
    emImgSchm0,
    emImgSchm1,
    emImgSchm2,
    emImgSchm3,
	emImgSchm4
};

//�ļ�����
enum EM_FileType
{
    emFileType_image = 0,    //image
    emFileType_pdf,          //pdf
    emFileType_ppt,          //ppt
    emFileType_txt,          //txt
    emFileType_doc,          //doc
    emFileType_xls,          //xls
    emFileType_unknown,      //unknown
};

//�ļ����͵�ö��
enum EM_DeviceType
{
        emDevice_No = 0,      //δ����豸
        emDevice_HDD,           //�ƶ�Ӳ��
        emDevice_Udisk,         //U��
};


//�ļ���Ϣ
typedef struct tagFileInfo 
{
    CString     strFileName;    //�ļ���
    CString     strFilePath;    // �ļ�·��
    BOOL        bIsFolder;      //�Ƿ����ļ���
    DWORD       dwFileCount;    //�����ĵ���Ŀ
    EM_FileType   em_fileType;  //�ļ����� 
    BOOL        bExtend;
    BOOL        bSel;           //�궨ѡ��״̬
	BOOL        bHighLight;     //��Ŀ�Ƿ�Ĭ�ϸ���
    EM_DeviceType  em_DeviceType;//�ƶ��豸����
    tagFileInfo()
    {
        strFileName.Empty();
        strFilePath.Empty();
        bIsFolder = FALSE;
        bExtend = TRUE;//dyy
        dwFileCount = 0;
        em_fileType = emFileType_unknown;//dyy
        bSel = FALSE;
        em_DeviceType = emDevice_No;
		bHighLight = FALSE;
    }
    
    void setNULL()
    {
        strFileName.Empty();
        strFilePath.Empty();
        bIsFolder = FALSE;
        bExtend = TRUE;
        dwFileCount = 0;
        em_fileType = emFileType_unknown;
        bSel = FALSE;
        em_DeviceType = emDevice_No;
		bHighLight = FALSE;
    }
    
    void operator=(const tagFileInfo& tCopy )
    {
        strFileName = tCopy.strFileName;
        strFilePath = tCopy.strFilePath;
        bIsFolder = tCopy.bIsFolder;
        bExtend = tCopy.bExtend;
        dwFileCount = tCopy.dwFileCount;
        em_fileType = tCopy.em_fileType;
        bSel = tCopy.bSel;
        em_DeviceType = tCopy.em_DeviceType;
		bHighLight = tCopy.bHighLight;
    }
    
}TFileItem;



//���м�ļ��й���
typedef struct tagListPathDirInfo
{
    CString strName;	            //��ʾ�ļ�������
    CString strItemFunc;            //��Ŀ�����¼�
    CString strFullPath;            //��Ӧ�ļ���ȫ·��
    CRect   rcItemRect;             //��Ŀ��С
    int nListOffSet;
    
    tagListPathDirInfo()
    {
        strName.Empty();
        strItemFunc.Empty();
        rcItemRect = NULL;
    }
    
    void SetNull()
    {
        strName.Empty();
        strItemFunc.Empty();
        rcItemRect = NULL;
    }
}TListPathDirInfo;


//����ƶ�Ӳ�� dyy

#if _MSC_VER <= 1200

#define IOCTL_STORAGE_QUERY_PROPERTY   CTL_CODE(IOCTL_STORAGE_BASE, 0x0500, METHOD_BUFFERED, FILE_ANY_ACCESS)

typedef enum _STORAGE_PROPERTY_ID {
    StorageDeviceProperty = 0,
        StorageAdapterProperty,
        StorageDeviceIdProperty
} STORAGE_PROPERTY_ID, *PSTORAGE_PROPERTY_ID;


typedef enum _STORAGE_QUERY_TYPE {
    PropertyStandardQuery = 0, 
        PropertyExistsQuery, 
        PropertyMaskQuery, 
        PropertyQueryMaxDefined 
} STORAGE_QUERY_TYPE, *PSTORAGE_QUERY_TYPE;




typedef struct _STORAGE_PROPERTY_QUERY {
    STORAGE_PROPERTY_ID  PropertyId;
    STORAGE_QUERY_TYPE  QueryType;
    UCHAR  AdditionalParameters[1];
} STORAGE_PROPERTY_QUERY, *PSTORAGE_PROPERTY_QUERY;


typedef struct _STORAGE_DEVICE_DESCRIPTOR {
    ULONG  Version;
    ULONG  Size;
    UCHAR  DeviceType;
    UCHAR  DeviceTypeModifier;
    BOOLEAN  RemovableMedia;
    BOOLEAN  CommandQueueing;
    ULONG  VendorIdOffset;
    ULONG  ProductIdOffset;
    ULONG  ProductRevisionOffset;
    ULONG  SerialNumberOffset;
    ULONG  BusType;
    ULONG  RawPropertiesLength;
    UCHAR  RawDeviceProperties[1];
} STORAGE_DEVICE_DESCRIPTOR, *PSTORAGE_DEVICE_DESCRIPTOR;

#endif



#endif
