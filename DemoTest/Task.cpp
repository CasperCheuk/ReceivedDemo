#include "Task.h"
#include <iostream>
using namespace std;


CTask::CTask(int *nCount,SocketConnection *socketConnection, const char* message,int message_length)
{
	m_nCount = nCount;
	m_socketConnection = socketConnection;
	m_message = message;
	m_message_lenght = message_length;
}


CTask::~CTask()
{
	delete m_nCount;
}
void CTask::DoWork(){
	for (int i = 0; i < m_message_lenght; i++)
	{
		printf("Send Message = %x\n ", (m_message[i])&0x0000ff);
	}
	printf("Length:%d \n", m_message_lenght);

	send((*m_socketConnection).sockClient, m_message, m_message_lenght, 0);
}

