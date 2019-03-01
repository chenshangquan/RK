#pragma once

class CMsgQueMngr : public IMsgQueMngr
{	
public:
	CMsgQueMngr();
	~CMsgQueMngr();
	virtual bool IsEmpty();
	virtual bool IsEnd();
	virtual bool AddMsg( TQueMsg Msg );
	virtual IMsgQueMngr* Clone();
	virtual void SendHeaderMsg();
	//virtual void SendCurrentMsg();
	virtual void ProcMsg( const TObMsg &ObMsg );
	virtual void Restore();
	virtual void Print();
	//virtual void TestOver();
	static void DataClear();

private:
	 /** �յ����Խ���Ľ�������
	 *  @param[in] ���Խ��
	 *  @node 
	 *  @return ģʽ�Ƿ�ı�
	 */
	 void InitTestResultMsg( const TObMsg &ObMsg );
	 /** �յ���������������Ľ�������
	 *  @param[in] ���Խ��
	 *  @node 
	 *  @return ģʽ�Ƿ�ı�
	 */
	 void InitRSTestResultMsg( const TObMsg &ObMsg );
	 /** �յ����ALM�˿ڲ��������Ľ�������
	 *  @param[in] ���Խ��
	 *  @node 
	 *  @return ģʽ�Ƿ�ı�
	 */
	 void InitALMTestResultMsg( const TObMsg &ObMsg );
	 /** �յ�CANNON�˿ڲɼ���������ƽ��ֵ��������
	 *  @param[in] ���Խ��
	 *  @node 
	 *  @return ģʽ�Ƿ�ı�
	 */
	 void InitCannonTestResultMsg( const TObMsg &ObMsg );
	 /** �յ�CANNON�˿ڲɼ���������ƽ��ֵ��������
	 *  @param[in] ���Խ��
	 *  @node 
	 *  @return ģʽ�Ƿ�ı�
	 */
	 void InitMainOutTestResultMsg( const TObMsg &ObMsg );
	 /** ������ת������ʵ�ֺ���
	 *  @param[in] 
	 *  @node 
	 *  @return 
	 */
	 void NetToHostMsg( TCnProduceTestMsg &tTestMsg );

	 void CalAverageValue();
	 
	 void CalMainoutAverageValue();
	 void InitRSFirstTestResultMsg( const TObMsg &ObMsg );
	 void InitRSSecTestResultMsg( const TObMsg &ObMsg );
private:
	u32 m_dwCurPos;    //��ǰ��Ϣ��λ��
//	u8  m_nIndex;      //��¼��ǰ��������ֵ�ǵڼ���
	typedef vector< TQueMsg > MsgList;
	MsgList m_vecMsgList;
	BOOL bIsFault;
	BOOL m_bTestResult; //�����жϵĲ�����ͨ�����
	BOOL m_bZeroCannonResult; //�޷���ֵʱ����ֵ��¼
	BOOL m_bZeroMainOutResult;
//	u32 m_bMainOutVol[10];    //��¼��ͬ���� ��ͬ��cannon�������������ֵ
//	u32 m_bCannonOutVol[6];   //��¼��ͬ������ cannon1�������������ֵ
};
