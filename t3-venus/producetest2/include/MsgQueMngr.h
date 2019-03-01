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
	 /** 收到测试结果的解析函数
	 *  @param[in] 测试结果
	 *  @node 
	 *  @return 模式是否改变
	 */
	 void InitTestResultMsg( const TObMsg &ObMsg );
	 /** 收到串口类测试项结果的解析函数
	 *  @param[in] 测试结果
	 *  @node 
	 *  @return 模式是否改变
	 */
	 void InitRSTestResultMsg( const TObMsg &ObMsg );
	 /** 收到凤凰ALM端口测试项结果的解析函数
	 *  @param[in] 测试结果
	 *  @node 
	 *  @return 模式是否改变
	 */
	 void InitALMTestResultMsg( const TObMsg &ObMsg );
	 /** 收到CANNON端口采集到的音量平均值解析函数
	 *  @param[in] 测试结果
	 *  @node 
	 *  @return 模式是否改变
	 */
	 void InitCannonTestResultMsg( const TObMsg &ObMsg );
	 /** 收到CANNON端口采集到的音量平均值解析函数
	 *  @param[in] 测试结果
	 *  @node 
	 *  @return 模式是否改变
	 */
	 void InitMainOutTestResultMsg( const TObMsg &ObMsg );
	 /** 网络序转主机序实现函数
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
	u32 m_dwCurPos;    //当前消息的位置
//	u8  m_nIndex;      //记录当前返回音量值是第几个
	typedef vector< TQueMsg > MsgList;
	MsgList m_vecMsgList;
	BOOL bIsFault;
	BOOL m_bTestResult; //本地判断的测试项通过与否
	BOOL m_bZeroCannonResult; //无返回值时本地值记录
	BOOL m_bZeroMainOutResult;
//	u32 m_bMainOutVol[10];    //记录相同输入 不同的cannon口输出的音量均值
//	u32 m_bCannonOutVol[6];   //记录不同的输入 cannon1口输出的音量均值
};
