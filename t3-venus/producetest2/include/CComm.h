#ifndef _CCOMM_H_
#define _CCOMM_H_
#pragma once
#include "kdvtype.h"
#include "windows.h"
class CComm
{
public:
	/** 构造函数 
	 *  @param[in] 串口消息处理回调函数
	 *  @node 
	 *  @return 
	 */
	CComm(  ComReadCallBack pfGetCall );
	~CComm();
	/**  打开串口
	 *  @param[in] 串口名
	 *  @node 
	 *  @return 
	 */
	BOOL OpenComm(LPCSTR pCommPort);          	
	/** 关闭串口 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	BOOL CloseComm();      
	
	/**  设置串口参数
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	BOOL SetCommParam(u32 dwBaud = 115200, u32 dwfParity = NOPARITY,
	BYTE byByteSize = 8, BYTE byStopBits = ONESTOPBIT);          //设置参数
	/** 写数据到串口 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	BOOL WriteComm(const LPSTR pSndBuffer, u32 dwBytesToWrite);  
	/** 读取串口数据 
	 *  @param[in] pInBuffer:数据缓冲区 dwBytesToRead:数据大小
	 *  @node 
	 *  @return 实际读取的大小
	 */
	u32  ReadComm(LPSTR pInBuffer, u32 dwBytesToRead);   
	/**  获取串口句柄
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */

protected:
	HANDLE GetCommHandle();                  
	/** 获取事件句柄
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	HANDLE GetEventHandle();                 //获取事件句柄
	/** 获取状态
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	BOOL   GetOpenState();                   
	ComReadCallBack GetComReadCallback();    //获取回调函数指针
	static DWORD WINAPI CommWatchProc(PVOID pvoid);
	
private:
	HANDLE	m_hComm;
	HANDLE  m_hEvent;
	BOOL	m_bOpen;
	ComReadCallBack m_fnReadCallback;
	OVERLAPPED m_Wol;     //写串口OVERLAPPED结构变量
	OVERLAPPED m_Rol;     //读串口OVERLAPPED结构变量
	String m_strCommName; //串口名

};

#endif