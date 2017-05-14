#ifndef TASK_H
#define TASK_H
#include "SocketConnection.h"
#pragma once
class CTask
{
	int  m_nCount;
	const char * m_message;
	int m_message_lenght;
	SocketConnection * m_socketConnection; //SocketÍ¨ÐÅ·¢ËÍ¶Ë
public:
	CTask(int nCount, SocketConnection *socketConnection, const char *message, int message_length);
	~CTask();
	void DoWork();
};

#endif
