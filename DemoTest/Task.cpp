#include "Task.h"
#include <iostream>
using namespace std;


/*****************************************
* @方法名:    CTask
* @作者:      Casper
* @全名:      CTask::CTask
* @描述:      
* @权限:      public 
* @返回值:     --
* @Qualifier:
* @Parameter: int nCount -- 任务标号，可随机
* @Parameter: SocketConnection * socketConnection --socketConnection封装的链接
* @Parameter: const char * message --数据包
* @Parameter: int message_length --数据包长度
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

