#include "WifiReceivedThread.h"


WifiReceivedThread::WifiReceivedThread()
{
}


WifiReceivedThread::~WifiReceivedThread()
{
}


/*****************************************
* @方法名:    PrintTool
* @作者:      Casper
* @全名:      PrintTool
* @描述:      以16进制形式打印数组数据,用例:
*			  PrintTool("sockReceived", receivedbuff, 8);
* @权限:      public
* @返回值:    void --
* @Qualifier:
* @Parameter: const char * text --要添加到打印头的标志信息
* @Parameter: char * charArray --char数组
* @Parameter: int ArrayLength --数组长度
* @Date:      2017/03/18
*****************************************/
bool WifiReceivedThread::Start(void (*workFunction)()){
	if (m_bIsStart)
	{
		return false;
	}

	m_bIsStart = true;
	m_thread = std::thread(workFunction);

	return true;
}

void WifiReceivedThread::Stop(){

	m_bIsStart = false;
	m_thread.join();
}
void ClearArrayBuff(char *charArray, int ArrayLength){
	for (int i = 0; i < ArrayLength; i++)
	{
		charArray[i] = 0x00;
	}
}


  /*****************************************
  * @方法名:    PrintTool
  * @作者:      Casper
  * @全名:      PrintTool
  * @描述:      以16进制形式打印数组数据
  * @权限:      public 
  * @返回值:    void --
  * @Qualifier:
  * @Parameter: const char * text --要添加到打印头的标志信息
  * @Parameter: char * charArray --char数组
  * @Parameter: int ArrayLength --数组长度
  * @Date:      2017/04/26
  *****************************************/
  void PrintTool(const char *text,char *charArray,int ArrayLength){
	  printf(text);
	  printf(": ArraySize(%d) Data:(", ArrayLength);
	  for (int i = 0; i < ArrayLength; i++)
	  {
		  printf("%x ", (charArray[i] & 0x000000ff));
	  }
	  printf(")");
	  printf("\n");
  }

  /*****************************************
  * @方法名:    ReceiveData
  * @作者:      Casper
  * @全名:      ReceiveData
  * @描述:      接收SOCKET连接发来的信息，并校验包头
  * @权限:      public 
  * @返回值:    char* -- 接收到的包信息，是一个5字节长数组
  * @Qualifier:
  * @Parameter: SOCKET sockClient -- 机器人连接
  * @Date:      2017/05/12
  *****************************************/
  char* ReceiveData(SOCKET sockClient){
	  char receivedbuff[1];//检查包头
	  char dataBuff[5];//数据
	  while (true)
	  {
		  recv(sockClient, receivedbuff, 1, 0);//接收1个字节
		  if (receivedbuff[0] == (char)0x84)//包头检查,若不强转将不正确，因为char会向上提升为int,由于首位为1，将变成一个较大的数
		  {
			  //printf("receivedbuff[0] = 0x84\n");
			  ClearArrayBuff(receivedbuff,1);//清空数组
			  recv(sockClient, receivedbuff, 1, 0);//接收1个字节
			  if (receivedbuff[0] == (char)0x64)
			  {
				  ClearArrayBuff(receivedbuff, 1);//清空数组
				  recv(sockClient, receivedbuff, 1, 0);//接收1个字节
				  if (receivedbuff[0] == (char)0x44)
				  {
					  recv(sockClient, dataBuff, 5, 0);//接收5个字节
					  PrintTool("接收到来自BlueRobot的信息:", dataBuff, 5);
					  return dataBuff;
				  }
			  }
		  }
	  }
  }