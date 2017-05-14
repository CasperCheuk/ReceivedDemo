#pragma once
#include "Task.h"
#include <mutex>
#include <thread>
#include "SocketConnection.h"				//机器人连接类声明

//新线程接收WIFI数据类，调用WifiReceivedThread.start(Function)后，将会在新线程中执行传入的函数
class WifiReceivedThread
{
public:
	WifiReceivedThread();
	~WifiReceivedThread();

private:
	std::thread m_thread;
	std::mutex m_mutex;
	bool m_bIsStart = false;//线程是否开启
public:
	bool Start(void(*workFunction)());
	void Stop();

};
void ClearArrayBuff(char *charArray, int ArrayLength);//将传入的数组各元素置为0x00
void PrintTool(const char *text, char *charArray, int ArrayLength);
char* ReceiveData(SOCKET sockClient);//接收信息