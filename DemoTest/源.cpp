
#include <iostream>
#include <stdio.h>
#include<winsock2.h>
#include <vector>
#include <opencv2/opencv.hpp>
#include <QtCore/QCoreApplication>
#include <QtCore/QThread>
#include "SocketConnection.h"
#include "TaskQueue.h"
#include "Task.h"
#pragma comment(lib, "ws2_32.lib")
//头文件

using namespace std;
using namespace cv;


/*
void MyWorkTask1(CTaskQueue* pTaskQueue,int* nCount){

	for (size_t i = 0; i < 20;i++)
	{
		CTask* task = new CTask(nCount);
		pTaskQueue->Push(task);
	}
}

void MyWorkTask2(CTaskQueue* pTaskQueue, int* nCount){

	for (size_t i = 0; i < 20; i++)
	{
		CTask* task = new CTask(nCount);
		pTaskQueue->Push(task);
	}
}
*/


int main(int argc, char * argv[]){
	
	int int_input = 0;

	
	char*  carname = "blueCar";
	char ipAddress[] = "192.168.1.1";
	int ipPort = 2001;
	SocketConnection socket(carname,ipAddress,ipPort);
	
	const char y4[] = { 0xAA,0xBB,0xCC,0xDD,0xEE};
	const char y5 = 0xab;
	int* num = new int(0);

	CTaskQueue* pTaskQueue = new CTaskQueue();
	pTaskQueue->Start();



	CTask* task = new CTask(num, &socket, y4, 5);
	pTaskQueue->Push(task);

	while (true)
	{

	}


	
	/*
	while (true)
	{
	cin >> int_input;//等待输入命令
	if (int_input==1)
	{
		send(socket.sockClient, y4, 3, 0);
		int_input = 2;
	}
	}

	
	CTaskQueue* pTaskQueue = new CTaskQueue();
	pTaskQueue->Start();

	int* nCount = new int(0);

	std::thread thread1(&MyWorkTask1,pTaskQueue,nCount);
	std::thread thread2(&MyWorkTask2, pTaskQueue, nCount);

	if (thread1.joinable()){
		thread1.join();
	}
	if (thread2.joinable()){
		thread2.join();
	}
	system("pause");

	*/
}