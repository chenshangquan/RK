#ifndef _UDPSESSION_H_
#define _UDPSESSION_H_
#include "Udp.h"
/*
	Udp�Ự��������Ϣ����ҵ���ࣩ	
*/
class CUdpSession
{
public:
	/** ���캯�� 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	CUdpSession();

	/** �������� 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	~CUdpSession();
 
private:
	/*=============================================================================
	�� �� ���� GetIdlePort
	��    �ܣ� ��ȡָ���˿������һ�����ж˿�
	�㷨ʵ�֣� 
	ȫ�ֱ����� 
	��    ���� wStartPort����ʼ���˿ڣ�dwIP������ip��wEndPort���������˿�
	�� �� ֵ�� ���ж˿�ֵ 
	-------------------------------------------------------------------------------
	�޸ļ�¼:
	��      ��  �汾    �޸���  �޸�����
	2012/9/27   1.0     �����    ����
	=============================================================================*/
/*	u16 GetIdlePort(u32 dwIP,  u16 wStartPort, u16 wEndPort);*/


protected:
	/** ��Ϣ������ 
	 *  @param[in] ip���˿ڡ����ݡ����ݳ���
	 *  @node 
	 *  @return 
	 */
	static void ProcMsg( const char * ip, unsigned short port, const char * data, short len );
	/** ��ʼ�� 
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	void Init();
private:
	/*
		Udp���ӵ�ID	
	*/
	static u32 m_dwUdpId;

	/*
		��ǰ��Ϣ��Ip
	*/
	u32 m_dwIpAddr;
	/*
		������ϢBuffer	
	*/
	static s8 m_achLoadBuf[MAX_LOAD_BUF_LEN];
	/*
		������Ϣ����	
	*/
	static u32 m_dwInfoLen;

};








//ת������
#define MKLONG(BUF)  ( (BUF[0]<<24)+(BUF[1]<<16)+(BUF[2]<<8)+BUF[3] )



#endif