/*=============================================================================
ģ   ��   ��: �ļ������ͻ���ҵ���ܿ�
��   ��   ��: evsuclib.h
�� ��  �� ��: ��
�ļ�ʵ�ֹ���: suclib ����淢�͵���Ϣ
��        ��: ���
��        ��: V1.0  Copyright(C) 2006-2007 Kedacom, All rights reserved.
-------------------------------------------------------------------------------
�޸ļ�¼:
��      ��  �汾    �޸���      �޸�����
2007/02/13  1.0     ���        ����
=============================================================================*/

#ifndef _EVSUCLIB_
#define _EVSUCLIB_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//1. ����
    //���ӳɹ�����Ϣ�壺u32(������IP��ַ��������)
    SUC_EVENT( SUC_DISP_CONNECT_ACK,            SUCLIB_MSG_BGN )
    //����ʧ�ܣ���Ϣ�壺�ޣ���������
    SUC_EVENT( SUC_DISP_CONNECT_NACK,           SUCLIB_MSG_BGN + 1 )

    //�Ͽ��ɹ�����Ϣ�壺u32(������IP��ַ��������)
    SUC_EVENT( SUC_DISP_LOGOUT_ACK,             SUCLIB_MSG_BGN + 2 )
    //�Ͽ�ʧ�ܣ���Ϣ�壺�ޣ��������룬���ᷢ�͸���Ϣ
    SUC_EVENT( SUC_DISP_LOGOUT_NACK,            SUCLIB_MSG_BGN + 3 )

    //������������Ϣ�壺��
    SUC_EVENT( SUC_DISP_RESET_ACK,              SUCLIB_MSG_BGN + 4 )
    //�ܾ���������Ϣ�壺�ޣ���������
    SUC_EVENT( SUC_DISP_RESET_NACK,             SUCLIB_MSG_BGN + 5 )

//2. �û�
    //��ȡ�û��б�ɹ�����Ϣ�壺��
    SUC_EVENT( SUC_DISP_GETUSERLIST_ACK,        SUCLIB_MSG_BGN + 10 )
    //��ȡ�û��б�ʧ�ܣ���Ϣ�壺�ޣ���������
    SUC_EVENT( SUC_DISP_GETUSERLIST_NACK,       SUCLIB_MSG_BGN + 11 )
    //�û��б�֪ͨ����Ϣ�壺��
    SUC_EVENT( SUC_DISP_USERLIST_NOTIF,         SUCLIB_MSG_BGN + 12 )

    //����û��ɹ�����Ϣ�壺��
    SUC_EVENT( SUC_DISP_ADDUSER_ACK,            SUCLIB_MSG_BGN + 13 )
    //����û�ʧ�ܣ���Ϣ�壺�ޣ���������
    SUC_EVENT( SUC_DISP_ADDUSER_NACK,           SUCLIB_MSG_BGN + 14 )

    //�༭�û��ɹ�����Ϣ�壺��
    SUC_EVENT( SUC_DISP_EDITUSER_ACK,           SUCLIB_MSG_BGN + 15 )
    //�༭�û�ʧ�ܣ���Ϣ�壺�ޣ���������
    SUC_EVENT( SUC_DISP_EDITUSER_NACK,          SUCLIB_MSG_BGN + 16 )

    //ɾ���û��ɹ�����Ϣ�壺��
    SUC_EVENT( SUC_DISP_DELUSER_ACK,            SUCLIB_MSG_BGN + 17 )
    //ɾ���û�ʧ�ܣ���Ϣ�壺�ޣ���������
    SUC_EVENT( SUC_DISP_DELUSER_NACK,           SUCLIB_MSG_BGN + 18 )

//3. �汾��Ϣ
    //��ȡ�����Ƽ��汾�ɹ�(��SUC_DISP_ALLRECOMMENDEDVER_NOTIF����)����Ϣ�壺��
    SUC_EVENT( SUC_DISP_GETALLRECOMMENDEDVER_ACK,   SUCLIB_MSG_BGN + 30 )
    //��ȡ�����Ƽ��汾ʧ�ܣ���Ϣ�壺�ޣ���������
    SUC_EVENT( SUC_DISP_GETALLRECOMMENDEDVER_NACK,  SUCLIB_MSG_BGN + 31 )
    //�����Ƽ��汾֪ͨ��(��SUC_DISP_GETALLRECOMMENDEDVER_ACK����)����Ϣ�壺��
    SUC_EVENT( SUC_DISP_ALLRECOMMENDEDVER_NOTIF,    SUCLIB_MSG_BGN + 32 )

    //��ȡָ���豸���а汾�ɹ�����SUC_DISP_ONEDEVVERINFO_NOTIF����
    //��Ϣ�壺IFCSrvDevVerFullInfo * n
    SUC_EVENT( SUC_DISP_GETONEDEVVERINFO_ACK,       SUCLIB_MSG_BGN + 35 )
    //��ȡָ���豸���а汾ʧ�ܣ���Ϣ�壺�ޣ���������
    SUC_EVENT( SUC_DISP_GETONEDEVVERINFO_NACK,      SUCLIB_MSG_BGN + 36 )
    //ĳһ�豸���а汾֪ͨ����SUC_DISP_GETONEDEVVERINFO_ACK����
    //��Ϣ�壺IFCSrvDevVerFullInfo * n
    SUC_EVENT( SUC_DISP_ONEDEVVERINFO_NOTIF,        SUCLIB_MSG_BGN + 37 )

    //�����Ƽ��汾�ɹ�����Ϣ�壺��
    SUC_EVENT( SUC_DISP_SETRECOMMENDEDVER_ACK,      SUCLIB_MSG_BGN + 40 )
    //�����Ƽ��汾ʧ�ܣ���Ϣ�壺�ޣ���������
    SUC_EVENT( SUC_DISP_SETRECOMMENDEDVER_NACK,     SUCLIB_MSG_BGN + 41 )
    //�����Ƽ��汾ʧ��֪ͨ����Ϣ�壺�ޣ���������
    SUC_EVENT( SUC_DISP_SETRECOMM_FAIL_NOTIF,       SUCLIB_MSG_BGN + 42 )
    //�����Ƽ��汾����֪ͨ����Ϣ�壺u16(����10�õ��ٷ�����������)
    SUC_EVENT( SUC_DISP_SETRECOMM_PRO_NOTIF,        SUCLIB_MSG_BGN + 43 )
    //�Ƽ��汾���֪ͨ����Ϣ�壺
    //u32(ԭ���Ƽ��汾�豸��ţ����������Ϊ-1��˵��ԭ��û���Ƽ��汾)
    //+ IFCSrvDevVerFullInfo(�µ��Ƽ��汾)
    SUC_EVENT( SUC_DISP_RECOMMENDEDVER_NOTIF,       SUCLIB_MSG_BGN + 44 )

    //ɾ��ĳһ�汾�ɹ�����SUS_DISP_DELONEVER_NOTIF����
    //��Ϣ�壺u32(�汾��ţ�������)
    SUC_EVENT( SUC_DISP_DELONEVER_ACK,              SUCLIB_MSG_BGN + 50 )
    //ɾ��ĳһ�汾ʧ�ܣ���Ϣ�壺�ޣ���������
    SUC_EVENT( SUC_DISP_DELONEVER_NACK,             SUCLIB_MSG_BGN + 51 )
    //ɾ��ĳһ�汾֪ͨ����SUS_DISP_DELONEVER_ACK����
    //��Ϣ�壺u32(�汾��ţ�������)
    SUC_EVENT( SUC_DISP_DELONEVER_NOTIF,            SUCLIB_MSG_BGN + 52 )

    //�༭ĳһ�汾�ɹ�����SUS_DISP_EDITONEVER_NOTIF����
    //��Ϣ�壺u32(�豸��ţ�������) + IFCHardwareVer + s8[MAX_FILESRV_BUG_REPORT_LEN]
    SUC_EVENT( SUC_DISP_EDITONEVER_ACK,             SUCLIB_MSG_BGN + 55 )
    //�༭ĳһ�汾ʧ�ܣ���Ϣ�壺�ޣ���������
    SUC_EVENT( SUC_DISP_EDITONEVER_NACK,            SUCLIB_MSG_BGN + 56 )
    //�༭ĳһ�汾֪ͨ����SUS_DISP_EDITONEVER_ACK����
    //��Ϣ�壺u32(�豸��ţ�������) + IFCHardwareVer + s8[MAX_FILESRV_BUG_REPORT_LEN]
    SUC_EVENT( SUC_DISP_EDITONEVER_NOTIF,           SUCLIB_MSG_BGN + 57 )

//4. ������Ϣ
    //��ȡ���óɹ�����Ϣ�壺ISusConfig
    SUC_EVENT( SUC_DISP_GETCFG_ACK,                 SUCLIB_MSG_BGN + 70 )
    //��ȡ����ʧ�ܣ���Ϣ�壺�ޣ���������
    SUC_EVENT( SUC_DISP_GETCFG_NACK,                SUCLIB_MSG_BGN + 71 )


    //�޸����óɹ�����SUS_DISP_CFG_NOTIF����
    //��Ϣ�壺ISusConfig
    SUC_EVENT( SUC_DISP_EDITCFG_ACK,                SUCLIB_MSG_BGN + 80 )
    //�޸�����ʧ�ܣ���Ϣ�壺�ޣ���������
    SUC_EVENT( SUC_DISP_EDITCFG_NACK,               SUCLIB_MSG_BGN + 81 )
    //���ø���֪ͨ����SUS_DISP_EDITCFG_ACK����
    //��Ϣ�壺ISusConfig
    SUC_EVENT( SUC_DISP_CFG_NOTIF,                  SUCLIB_MSG_BGN + 82 )

//5. �ļ���Ϣ
    //ֹͣ�ϴ��ɹ�����Ϣ�壺��
    SUC_EVENT( SUC_DISP_STOPUPGRADE_ACK,            SUCLIB_MSG_BGN + 100 )
    //ֹͣ�ϴ�ʧ�ܣ���Ϣ�壺�ޣ���������
    SUC_EVENT( SUC_DISP_STOPUPGRADE_NACK,           SUCLIB_MSG_BGN + 101 )

    //��ʼ�ϴ��ɹ�����Ϣ�壺��
    SUC_EVENT( SUC_DISP_STARTUPGRADE_ACK,           SUCLIB_MSG_BGN + 105 )
    //��ʼ�ϴ�ʧ�ܣ���Ϣ�壺�ޣ���������
    SUC_EVENT( SUC_DISP_STARTUPGRADE_NACK,          SUCLIB_MSG_BGN + 106 )
    //�ϴ����̴�����Ϣ�壺�ޣ���������
    SUC_EVENT( SUC_DISP_UPGRADEFAIL_NOTIF,          SUCLIB_MSG_BGN + 107 )
    //�ϴ�����֪ͨ����Ϣ�壺u16(���ȣ���ȷ��%ǰС�����һλ��������)
    SUC_EVENT( SUC_DISP_UPGRADEPROGRESS_NOTIF,      SUCLIB_MSG_BGN + 108 )
    //�ϴ����֪ͨ����Ϣ�壺
    //u8(�ļ�����)
    //+ [ s8[MAX_FILESRV_FILENAME_LEN](�ļ���) + u32(0Ϊ�ɹ�������Ϊ�����룬������) ]
    //  * n
    SUC_EVENT( SUC_DISP_UPGRADERESULT_NOTIF,        SUCLIB_MSG_BGN + 109 )

//6. ������Ϣ
    //��ʱ����������
    SUC_EVENT( SUC_DISP_TIMEOUT,                SUCLIB_MSG_BGN + 300 )
    //��������Ϣ�壺u32(������IP��ַ��������)
    SUC_EVENT( SUC_DISP_DISCONNECTED,           SUCLIB_MSG_BGN + 301 )

#endif//_EVSUCLIB_