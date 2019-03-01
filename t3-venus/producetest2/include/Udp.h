#ifndef __UDP_H
#define __UDP_H
#include "kdvtype.h"
// ����������ݵĻص���������
// ����Ϊ���յ����ݰ�����Ϣ(����Դ��ַ������)
typedef void  (* UdpRecCallBack)(const char * ip, unsigned short port, const char * data, short len);

// ��UDP�˿�
// ����ΪUDP�Ķ˿ںźͽ������ݵĻص�����
// ����UDP-ID
extern long UdpOpen(u16 port, UdpRecCallBack pfBackCall);

// �ر�UDP�˿�
// ����ΪUDP��ID
extern void UdpClose(u32 dwUdpId);

// �����ݰ�д��UDP�˿�
// ����ΪUDP-ID�����ݰ���Ϣ������Ŀ�ĵ�ַ�����ݣ�
extern void UdpWrite( long udpId, const s8 * ip, u16 port, const s8 * data, s16 len );


#endif
