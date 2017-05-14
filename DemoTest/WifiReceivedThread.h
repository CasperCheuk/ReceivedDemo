#pragma once
#include "Task.h"
#include <mutex>
#include <thread>
#include "SocketConnection.h"				//����������������

//���߳̽���WIFI�����࣬����WifiReceivedThread.start(Function)�󣬽��������߳���ִ�д���ĺ���
class WifiReceivedThread
{
public:
	WifiReceivedThread();
	~WifiReceivedThread();

private:
	std::thread m_thread;
	std::mutex m_mutex;
	bool m_bIsStart = false;//�߳��Ƿ���
public:
	bool Start(void(*workFunction)());
	void Stop();

};
void ClearArrayBuff(char *charArray, int ArrayLength);//������������Ԫ����Ϊ0x00
void PrintTool(const char *text, char *charArray, int ArrayLength);
char* ReceiveData(SOCKET sockClient);//������Ϣ