/*
	通用结构体定义
*/
#include "tptype.h"
#include "osp.h"
#pragma once
//UI模式
enum EmUIMode
{
	emModeNormal,	//普通模式
		emModeLoad,	//加载模式
		emModeTest	//测试模式
};

//UI状态
enum EmUIState
{
	emUILoading,		//正在加载
		emUILoadEdit,	//加载编辑状态
		emUILoadNormal,	//加载普通状态
		emUITesting,	//正在测试
		emUITestPre,	//测试准备
		emUITestReady	//测试准备好
};

/*
	测试项类型
*/
enum EmTestCaseType
{	
	emMediaCase,		//媒体测试项
		emCmdCase,		//命令测试项
		emExeCase		//执行测试项

};

/*
	测试项进度	
*/
enum EmTestCaseProcedure
{
	emCaseEndPending,		//等待结束
		emCasePrePending,	//等待开始
		emCaseTested,		//已经测试
		emCaseTesting,		//正在测试
		emCaseWaiting		//等待
};

/*
	测试项状态	
*/
enum EmTestCaseState
{
	emNotPassed,		//测试未通过
		emNotReady,		//没有准备好
		emPassed,		//测试通过
		emReady,		//准备好
		emTesting,		//正在测试
/*		emReTesting,	//有回复消息的测试项重测*/
        emReceived,       //音量测试项子项收到返回值
		emCmdTesting,   //cmd类测试项正在测试
		emAbort         //中断
};

/*
	板卡进度	
*/
enum EmBrdProceduer
{
	emBrdRegPending,	//板卡注册等待；
	emBrdPrePending,	//板卡准备等待；
	emBrdEndPending,	//板卡结束等待
	emBrdTesting,		//板卡测试中
	emBrdTested			//板卡已经测试
};


/*
	置测试项的类型 IDevice::SetTestCase的参数
*/
enum EmCaseSetType
{
	emTestNext,			//下一个测试项
	emTestCur			//当前测试项
};

/*
	设备加载状态	
*/
enum EmDeviceLoadState
{

};

/*
	消息体数据结构
*/
typedef struct tagMsgParam 
{
	u16		wMsgId;			// 消息号
	void*	pData;				// 数据
}TMsgParam;

/*
	输入码流参数结构
*/
typedef struct tagStreamInParam
{
	u32 dwVidCount;			//视频数
	u32 dwAudCount;			//音频数
	u32 dwVidRTPPort;		//视频RTP端口
	u32	dwAudRTPPort;		//音频RTP端口
	u16	wKeyFrameMsg;		//请求关键帧消息

}TStreamInParam;

/*
	输出码流参数结构
*/
typedef struct tagStreamOutParam
{	
	u32 dwVidCount;			//视频数
	u32 dwAudCount;			//音频数
	s8	achFileName[MAX_FILE_NAME_LENTH];	//文件名	
}TStreamOutParam;

/*
	编码器网络参数结构
*/
typedef struct EncoderNetParam
{
	u32		dwVidLocalRTPPortStart;			//视频本地网络参数RTP起始端口
	u32		dwVidLocalInterval;				//视频本地网络参数端口间隔
	u32		dwVidRemoteRTPPortStart;		//视频远端网络参数RTP起始端口
	u32		dwVidRemoteInterval;			//视频远端网络参数端口间隔
	u32		dwAudLocalRTPPortStart;			//音频本地网络参数RTP起始端口
	u32		dwAudLocalInterval;				//音频本地网络参数端口间隔
	u32		dwAudRemoteRTPPortStart;		//视频远端网络参数RTP起始端口
	u32		dwAudRemoteInterval;			//音频远端网络参数端口间隔
}TEncoderNetParam;


/*
	板卡注册消息
*/
typedef struct tagBrdRegMsg
{	
	u32 dwRegMsgId;			//注册消息ID
	u32 dwAckMsgId;			//Ack消息ID
	u32 dwNackMsgId;		//Nack消息ID	
}TBrdRegMsg;

/*
	消息类型 	
*/
enum EmQueMsgType
{
	emMsgIn,			//发送消息
	emMsgOut			//接收消息
};

/*
	队列中消息结构
*/
typedef struct tagQueMsg
{
	EmQueMsgType	emMsgType;						//消息类型		
	u16				dwMsgId;						//消息号
	String			strMsgDiscription;				//描述
	u8				achMsgBody[MAX_MSG_BODY_LEN];	//消息体
}TQueMsg;


//typedef struct tagDefaultStruct
//{
//	u32	dwMsgId;						
//	String strMsgDiscription;  
//	s8  achMsgBody[MAX_MSG_BODY_LEN];
//} Td;
/*
	消息IOspOb处理的消息结构	
*/
typedef struct tagObMsg
{
	//源结点
	u32 srcnode;
	//目的结点
	u32 dstnode;
	//目的应用实例
	u32 dstid;
	//源目的实例
	u32 srcid;
	//消息号
	u16 event;
	//消息体长度
	u16 length;
	//消息体
	u8 *content;
}TObMsg;

/*
	测试项状态消息体	
*/
typedef struct tagCaseStateMsg
{
	String			strCaseName;	//测试项名	
	EmTestCaseState emState;		//状态
}TCaseStateMsg;

/*
	板卡注册时的结构	
*/
typedef struct tagDeviceLoginInfo
{
    s8          achSerial[MAX_SERIAL_LENGTH];           //序列号
    s8          achMac[MAX_MAC_LENGTH];                 //mac地址
    s8          achSoftVersion[MAX_VERSION_LENGTH];     //软件版本
    s8          achHardVersion[MAX_VERSION_LENGTH];     //硬件版本
	EmCnModel   emMtModel;                              //设备类型
    u32_ip		    dwIp;                                   //设备ip
    u32_ip			dwSubMask;                              //子网掩码
}TDeviceInfo;

/*
升级的状态过程（板卡报的）
*/
enum KDM_NOTIFY_STATUS
{
    KDM_BOOT_INITIAL= 0,		/* 初始化状态*/
		KDM_BOOTINFO_SET,       /* IP/MAC 设置成功 */
		KDM_UPDATE_E2PROM,		/* EPROM 升级成功 */
		KDM_UPLOAD_OS,			/* OS 上传完成 */
		KDM_UPDATE_OS,			/* OS 升级完成 */
		KDM_UPLOAD_UBOOT,		/* BOOT 上传完成 */
		KDM_UPDATE_UBOOT,       /* BOOT 升级完成 */
		KDM_UPLOAD_SYS,			/* SYS 上传完成 */
		KDM_UPDATE_SYS,			/* SYS 升级完成 */
		KDM_UPLOAD_APP,			/* APP上传完成*/
		KDM_UPDATE_APP,			/* APP升级完成*/
		KDM_UPLOAD_USR,			/* USR上传完成*/
		KDM_UPDATE_USR,			/* USR升级完成*/
		KDM_PROCESS_OK			/*所有升级完成*/
};

/*
通知界面的加载状态
*/
enum EmLoadState
{
	emBootInfoSet = 1,			//IP/MAC 设置成功
		emUpdateE2prom,			// EPROM 升级成功 
		emUploadSys,			// SYS 上传完成 
		emUpdateSys,			// SYS 升级完成 
		emProcessOk				//所有加载完成  全部升级成功
};

/*
通知界面的加载错误信息	
*/
enum EmLoadErr
{
	emRcvAckErr = 1,	//分配IP、MAC地址出错
		emWriteEpromErr	//写Eprom出错
};