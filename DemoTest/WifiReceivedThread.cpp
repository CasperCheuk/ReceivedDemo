#include "WifiReceivedThread.h"


WifiReceivedThread::WifiReceivedThread()
{
}


WifiReceivedThread::~WifiReceivedThread()
{
}


/*****************************************
* @������:    PrintTool
* @����:      Casper
* @ȫ��:      PrintTool
* @����:      ��16������ʽ��ӡ��������,����:
*			  PrintTool("sockReceived", receivedbuff, 8);
* @Ȩ��:      public
* @����ֵ:    void --
* @Qualifier:
* @Parameter: const char * text --Ҫ��ӵ���ӡͷ�ı�־��Ϣ
* @Parameter: char * charArray --char����
* @Parameter: int ArrayLength --���鳤��
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
  * @������:    PrintTool
  * @����:      Casper
  * @ȫ��:      PrintTool
  * @����:      ��16������ʽ��ӡ��������
  * @Ȩ��:      public 
  * @����ֵ:    void --
  * @Qualifier:
  * @Parameter: const char * text --Ҫ��ӵ���ӡͷ�ı�־��Ϣ
  * @Parameter: char * charArray --char����
  * @Parameter: int ArrayLength --���鳤��
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
  * @������:    ReceiveData
  * @����:      Casper
  * @ȫ��:      ReceiveData
  * @����:      ����SOCKET���ӷ�������Ϣ����У���ͷ
  * @Ȩ��:      public 
  * @����ֵ:    char* -- ���յ��İ���Ϣ����һ��5�ֽڳ�����
  * @Qualifier:
  * @Parameter: SOCKET sockClient -- ����������
  * @Date:      2017/05/12
  *****************************************/
  char* ReceiveData(SOCKET sockClient){
	  char receivedbuff[1];//����ͷ
	  char dataBuff[5];//����
	  while (true)
	  {
		  recv(sockClient, receivedbuff, 1, 0);//����1���ֽ�
		  if (receivedbuff[0] == (char)0x84)//��ͷ���,����ǿת������ȷ����Ϊchar����������Ϊint,������λΪ1�������һ���ϴ����
		  {
			  //printf("receivedbuff[0] = 0x84\n");
			  ClearArrayBuff(receivedbuff,1);//�������
			  recv(sockClient, receivedbuff, 1, 0);//����1���ֽ�
			  if (receivedbuff[0] == (char)0x64)
			  {
				  ClearArrayBuff(receivedbuff, 1);//�������
				  recv(sockClient, receivedbuff, 1, 0);//����1���ֽ�
				  if (receivedbuff[0] == (char)0x44)
				  {
					  recv(sockClient, dataBuff, 5, 0);//����5���ֽ�
					  PrintTool("���յ�����BlueRobot����Ϣ:", dataBuff, 5);
					  return dataBuff;
				  }
			  }
		  }
	  }
  }