
//其它宏定义文件
#pragma once
#define MAX_SERIAL_LENGTH	(u32)32				//序列号最大长度
#define MAX_SERIAL_INPUT_LEN (u32)10			//输入的序列号最大长度	
#define MAX_MAC_LENGTH		(u32)32				//MAC地址字符串最大长度
#define MAX_VERSION_LENGTH	(u32)32				//版本长度
#define MAX_SYSFILE_NAME_LENGTH	(u32)32			//Sysfile名最大长度
#define PIPELINE_SN_LEN     (u32)6				//生产线号长度
#define MAX_DATE_LEN		(u32)20				//日期长度 yyyy/mm/dd hh:mm:ss
#define MAX_FILE_NAME_LENTH	(u32)256			//最大文件名长度
#define MAX_PATH_LENTH		(u32)1024			//最大路径长度
#define MAX_LOAD_BUF_LEN    (u32)800	        //加载缓存的大小
#define MAC_SIZE			(u32)6				//Mac 6字节
#define IP_SIZE				(u32)4				//IP 4字节
#define IP_STR_LEN			(u32)15				//ip字符串最大长度15
#define MAX_HW_LEN			(u32)4				//最大的HW长度
#define LOGIN_MODE_LENTH    (u32)32				//登录时模式信息buffer的长度
#define USER_INFO_SIZE		(u32)152			//登录时报上来的用户信息结构长度
#define MAX_COM_DISP_LEN    (u32)3000			//超级终端显示长度
//队列消息相关
#define MAX_MSG_BODY_LEN	10000				//消息体长度
//端口
#define SERVRT_PORT			60000				//OSP监听端口
#define LOAD_UDP_PORT		6000				//加载Udp端口
//颜色
#define COLOR_RED		0XFFFF0000
#define COLOR_BLUE		0XFF0000FF
#define COLOR_GREEN		0XFF009966
#define COLOR_BLACK		0xFF000000
#define COLOR_WHITE		0xFFFFFFFF
#define COLOR_GRAY		0xFFEEEEEE		
//其它
#define VERSION_NUM     0X0100                      //版本号
#define APP_PRIO		80							//App优先级
#define DEFAULT_INS_ID	1							//默认Instance号	
#define INVALD_MODE		0xff
typedef std::string String;							//String
typedef DuiLib::CMarkupNode DocNode;				//DocNode
typedef DuiLib::CAppWindow Window;					//窗口
typedef DuiLib::CControlUI Control;					//控件
#define DOCMNGR IDocManager::GetSingletonPtr()		//文档操作
#define USERDATA (IUserDataMngr::GetSingletonPtr())	//用户数据
#define CHECK_FILE_EXISTS ICommonOp::CheckFileExists
#define NOTIFY	ICommonOp::Notify
//端口定义
#define PRODUCETEST_SENDBASEPORT	(u32)12050
//本软件发送码流端口
//第一个HDU  video send
#define HDU_SNDRTPPORT1_vid		PRODUCETEST_SENDBASEPORT  + 0
//第一个HDU  audeo send
#define HDU_SNDRTPPORT1_aud		PRODUCETEST_SENDBASEPORT  + 2
//第二个HDU video send
#define HDU_SNDRTPPORT2_vid		PRODUCETEST_SENDBASEPORT  + 4
//第二个HDU audeo send
#define HDU_SNDRTPPORT2_aud		PRODUCETEST_SENDBASEPORT  + 6
//第三个HDU video send
#define HDU_SNDRTPPORT3_vid		PRODUCETEST_SENDBASEPORT  + 8
//第三个HDU audeo send
#define HDU_SNDRTPPORT3_aud		PRODUCETEST_SENDBASEPORT  + 10
//EAPU编码器本地RTP端口
#define	EAPU_SNDRTPPORT1_aud	PRODUCETEST_SENDBASEPORT  + 50
//EAPU板卡接收码流起始RTP端口
#define EAPU_RCVRTPPORT			EAPU_LOCALRCVPORT + 2
//EAPU解码器本地RTP端口
#define EAPU_DEC_LOCAL_RTPPORT	SERVER_RCVPORT + 2
//MPU/MPU2发送码流起始RTP端口
#define MPU_SND_RTPPORT			PRODUCETEST_SENDBASEPORT + 8
//MPU/MPU2 VMP模式解码器RTP端口
#define MPU_DEC_LOCAL_RTPPORT	39000
//MPU-BAS模式本地RTP端口(4个适配通道)
#define MPU_BAS_SNDRTPPORT_1	PRODUCETEST_SENDBASEPORT + 18
#define MPU_BAS_SNDRTPPORT_2	PRODUCETEST_SENDBASEPORT + 20
#define MPU_BAS_SNDRTPPORT_3	PRODUCETEST_SENDBASEPORT + 22
#define MPU_BAS_SNDRTPPORT_4	PRODUCETEST_SENDBASEPORT + 24
//MPU-BAS模式远端RTP端口(4个适配通道)
#define MPUTEST_BAS_RECVBASEPORT_1	MPUTEST_BAS_RECVBASEPORT
#define MPUTEST_BAS_RECVBASEPORT_2	MPUTEST_BAS_RECVBASEPORT + 20
#define MPUTEST_BAS_RECVBASEPORT_3	MPUTEST_BAS_RECVBASEPORT + 40
#define MPUTEST_BAS_RECVBASEPORT_4	MPUTEST_BAS_RECVBASEPORT + 60
//MPU-BAS模式解码器RTP端口(4个适配通道)
#define MPUTEST_BAS_SENDSVRPORT_1	MPUTEST_BAS_SENDSVRPORT
#define MPUTEST_BAS_SENDSVRPORT_2	MPUTEST_BAS_SENDSVRPORT + 20
#define MPUTEST_BAS_SENDSVRPORT_3	MPUTEST_BAS_SENDSVRPORT + 40
#define MPUTEST_BAS_SENDSVRPORT_4	MPUTEST_BAS_SENDSVRPORT + 60


