#ifndef _CCOMM_H_
#define _CCOMM_H_
#pragma once
#include "kdvtype.h"
#include "windows.h"
class CComm
{
public:
	/** ���캯�� 
	 *  @param[in] ������Ϣ����ص�����
	 *  @node 
	 *  @return 
	 */
	CComm(  ComReadCallBack pfGetCall );
	~CComm();
	/**  �򿪴���
	 *  @param[in] ������
	 *  @node 
	 *  @return 
	 */
	BOOL OpenComm(LPCSTR pCommPort);          	
	/** �رմ��� 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	BOOL CloseComm();      
	
	/**  ���ô��ڲ���
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	BOOL SetCommParam(u32 dwBaud = 115200, u32 dwfParity = NOPARITY,
	BYTE byByteSize = 8, BYTE byStopBits = ONESTOPBIT);          //���ò���
	/** д���ݵ����� 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	BOOL WriteComm(const LPSTR pSndBuffer, u32 dwBytesToWrite);  
	/** ��ȡ�������� 
	 *  @param[in] pInBuffer:���ݻ����� dwBytesToRead:���ݴ�С
	 *  @node 
	 *  @return ʵ�ʶ�ȡ�Ĵ�С
	 */
	u32  ReadComm(LPSTR pInBuffer, u32 dwBytesToRead);   
	/**  ��ȡ���ھ��
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */

protected:
	HANDLE GetCommHandle();                  
	/** ��ȡ�¼����
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	HANDLE GetEventHandle();                 //��ȡ�¼����
	/** ��ȡ״̬
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	BOOL   GetOpenState();                   
	ComReadCallBack GetComReadCallback();    //��ȡ�ص�����ָ��
	static DWORD WINAPI CommWatchProc(PVOID pvoid);
	
private:
	HANDLE	m_hComm;
	HANDLE  m_hEvent;
	BOOL	m_bOpen;
	ComReadCallBack m_fnReadCallback;
	OVERLAPPED m_Wol;     //д����OVERLAPPED�ṹ����
	OVERLAPPED m_Rol;     //������OVERLAPPED�ṹ����
	String m_strCommName; //������

};

#endif