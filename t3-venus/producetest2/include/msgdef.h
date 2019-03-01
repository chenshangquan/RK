//消息定义文件
#pragma once

//用户操作触发的消息
#define USER_MSG_BGN				WM_USER
#define EV_USER_DEVICE_CHANGE		(u16)( USER_MSG_BGN + 0 )		//设备发生变化 无消息体
#define EV_USER_START_IP_CHANGE		(u16)( USER_MSG_BGN + 1 )		//起始IP地址变化 无消息体
#define EV_USER_START_MAC_CHANGE	(u16)( USER_MSG_BGN + 2 )		//起始Mac地址变化 无消息体
#define EV_USER_UI_MODE_CHANGE		(u16)( USER_MSG_BGN + 3 )		//UI模式变化 无消息体
#define EV_USER_UI_STATE_CHANGE		(u16)( USER_MSG_BGN + 4 )		//UI状态变化 无消息体
#define EV_USER_STATE_STR_UPATE     (u16)( USER_MSG_BGN + 5 )		//状态字符串更新 无消息体
#define EV_USER_INIT_ST				(u16)( USER_MSG_BGN + 6 )		//初始化超级终端消息 消息体:绘制管理器指针
#define EV_USER_TFTP_PATH_CHANGE	(u16)( USER_MSG_BGN + 7 )		//tftp路径变化消息
#define EV_MAIN_WND_SIZE_CHANGE		(u16)( USER_MSG_BGN + 8 )		//主窗口大小变化
#define EV_MAIN_WND_MOVE			(u16)( USER_MSG_BGN + 9 )		//主窗口移动



//设备发到上层的消息
#define DVC_MSG_BGN					WM_USER + 100
//测试相关
#define	EV_DVC_LOAD_REQ				(u16)( DVC_MSG_BGN + 0 )        //设备加载请求 无消息体
#define	EV_DVC_LOAD_STATE_CHANGE	(u16)( DVC_MSG_BGN + 1 )		//设备加载状态变化 消息体：EmDeviceLoadState
#define EV_DVC_TEST_BRD_READY		(u16)( DVC_MSG_BGN + 2 )		//板卡准备就绪 无消息体
#define EV_DVC_TEST_BRD_END  		(u16)( DVC_MSG_BGN + 3 )		//板卡结束 无消息体
#define EV_DVC_CASE_STATE_CHANGE	(u16)( DVC_MSG_BGN + 4 )		//测试项状态变化 消息体 TCaseStateMsg
#define EV_DVC_BRD_INFO_LOAD_SUCCESS (u16)( DVC_MSG_BGN + 5 )		//板卡信息加载成功消息 消息体 板卡名（String）
#define EV_DVC_BRD_INFO_LOAD_FAIL   (u16)( DVC_MSG_BGN + 6 )		//板卡信息加载失败消息 消息体 板卡名（String）
#define EV_DVC_BRD_START_RESTORE	(u16)( DVC_MSG_BGN + 7 )		//板卡恢复出场设置成功 消息体 无
#define EV_DVC_BRD_RESTORE_SUCCESS  (u16)( DVC_MSG_BGN + 8 )		//板卡恢复出场设置成功 消息体 板卡名（String）
#define EV_DVC_TEST_ABORT           (u16)( DVC_MSG_BGN + 9 )		//设备测试中止
#define EV_DVC_DISCONNECT           (u16)( DVC_MSG_BGN + 10 )		//设备断链
#define EV_DVC_RESULT               (u16)( DVC_MSG_BGN + 11 )       //通知界面弹框消息
#define EV_DVC_SHOWBTN              (u16)( DVC_MSG_BGN + 12 )       //界面收到此消息显示继续下一项测试按钮
//加载相关消息
#define EV_LOAD_START_REQ			(u16)( DVC_MSG_BGN + 13 )
#define EV_LOAD_STATE_UPDATE		(u16)( DVC_MSG_BGN + 14 )		//加载状态变化  消息体 EmLoadState（状态）
#define EV_LOAD_ERR					(u16)( DVC_MSG_BGN + 15 )		//加载错误消息	消息体 EmLoadErr
#define EV_COM_DATA_READY			(u16)( DVC_MSG_BGN + 16 )		//串口有数据可供读取
#define EV_COM_UPDATE				(u16)( DVC_MSG_BGN + 17 )		//超级终端显示刷新
#define EV_COMM_PORT_AVAILABLE      (u16)( DVC_MSG_BGN + 18 )		//端口可用

//加载网络消息
/*
MSG TYPE
报文类型
*/
enum KDM_MESSAGE_TYPE
{
	/*
	功能：
		板卡请求获得IP，MAC
	方向：
		PU->服务器
	说明：
		无消息体
	*/
	KDM_BOOTINFO_REQ = 0,

	/*
	功能：
		服务器应答IP，MAC
	方向：
		服务器->板卡
	*/
	KDM_BOOTINFO_ACK,

	/*
	功能：
		板卡确认获得IP，MAC并设置
	方向：
		板卡->服务器
	说明：
		包含文件升级状态的报告
	*/
	KDM_NOTIFY
};

//通知消息
#define		KDM_NOTIFY_OPT		14
#define		NET_NOTIFY_OPT		20
//错误消息
#define KDM_ERR_RCV_ACK_ERR     0x01
#define KDM_ERR_WRITE_EPROM     0x02