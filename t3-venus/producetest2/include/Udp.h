#ifndef __UDP_H
#define __UDP_H
#include "kdvtype.h"
// 定义接收数据的回调函数类型
// 参数为接收到数据包的信息(包的源地址和内容)
typedef void  (* UdpRecCallBack)(const char * ip, unsigned short port, const char * data, short len);

// 打开UDP端口
// 参数为UDP的端口号和接收数据的回调函数
// 返回UDP-ID
extern long UdpOpen(u16 port, UdpRecCallBack pfBackCall);

// 关闭UDP端口
// 参数为UDP的ID
extern void UdpClose(u32 dwUdpId);

// 将数据包写入UDP端口
// 参数为UDP-ID和数据包信息（包的目的地址和内容）
extern void UdpWrite( long udpId, const s8 * ip, u16 port, const s8 * data, s16 len );


#endif
