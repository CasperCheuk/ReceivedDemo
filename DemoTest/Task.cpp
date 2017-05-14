#include "Task.h"
#include <iostream>
using namespace std;


/*****************************************
* @������:    CTask
* @����:      Casper
* @ȫ��:      CTask::CTask
* @����:      
* @Ȩ��:      public 
* @����ֵ:     --
* @Qualifier:
* @Parameter: int nCount -- �����ţ������
* @Parameter: SocketConnection * socketConnection --socketConnection��װ������
* @Parameter: const char * message --���ݰ�
* @Parameter: int message_length --���ݰ�����
* @Date:      2017/02/17
*****************************************/
CTask::CTask(int nCount,SocketConnection *socketConnection, const char* message,int message_length)
{
	m_nCount = nCount;
	m_socketConnection = socketConnection;
	m_message = message;
	m_message_lenght = message_length;
}


CTask::~CTask()
{
	
}
void CTask::DoWork(){


	printf("Sended Message = (%d) Data:(", m_message_lenght);
	for (int i = 0; i < m_message_lenght; i++)
	{
		printf("%x ", (m_message[i] & 0x000000ff));
	}
	printf(")");
	printf("\n");
	send((*m_socketConnection).sockClient, m_message, m_message_lenght, 0);
	/*
	for (int i = 0; i < m_message_lenght; i++)
	{
		printf("Send Message = %x\n ", (m_message[i])&0x0000ff);
	}
	printf("Length:%d \n", m_message_lenght);

	send((*m_socketConnection).sockClient, m_message, m_message_lenght, 0);
	*/
}

