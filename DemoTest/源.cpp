
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
#include "WifiReceivedThread.h"
#pragma comment(lib, "ws2_32.lib")
//头文件

using namespace std;
using namespace cv;

char*  carname = "blueCar";
char ipAddress[] = "192.168.1.1";
int ipPort = 2001;
SocketConnection sockettest(carname, ipAddress, ipPort);

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

void delay(){
	for (int i = 500; i > 0;i--)
	{
		for (int j = 100; j > 0;j--)
		{
			for (int k = 10000; k > 0;k--)
			{
			}
		}
	}
}


void workTest(){
	printf("接收线程启动...\n");

	while (true)
	{
		char* receivedBuff = ReceiveData(sockettest.sockClient);//该返回值是一5个字节长数组
		switch (receivedBuff[0])
		{
		case 0x31://机器人空闲
			break;
		case 0x32://正在调度捡球 
			break;
		case 0x33://机器人自带摄像头发现网球，正在捡球
			break;
		case 0x34://机器人正在调度卸球
			break;
		case 0x35://机器人卸球完成
			break;
		default:
			break;
		}
	}

	/*
	while (1)
	{
		char receivedbuff[8];
		memset(receivedbuff, 0, 8);
		int received_Lenth = recv(sockettest.sockClient, receivedbuff, 8, 0);
		Sleep(1);
		printf("接收数据长度：%d\n", received_Lenth);
		if (receivedbuff[3]==0x22)continue;
		if (received_Lenth==0) continue;
		PrintTool("接收信息：",receivedbuff,8);
		//for (int i = 0; i < 8; i++)
		{
				//printf("Received:%x\n", receivedbuff[i]);
		}
	}
	*/
	
};

int main(int argc, char * argv[]){
	
	int int_input = 0;

	//int ipPort = 6000;
	
	
	char data_test[] = { 0xAA, 0xBB, 0xCC, 0xDD, 0xEE };
	char data_contact[] = { 0x84, 0x64, 0x44, 0x13, 0x01, 0x02,0x03,0x04 };
	char data = 0x00;
	char CMD0X80 = 0x80;
	char receiveBuf[10];//接收

	//发送示例
	//send(sockettest.sockClient, "hello\n", strlen("hello\n") + 1, 0);
	//sockettest.sendMessageToCar("hello\n", strlen("hello\n") + 1);
	sockettest.sendMessageToCar(data_test, 5);

	CTaskQueue *mQueue = new CTaskQueue();
	mQueue->Start();

	WifiReceivedThread *wifiReceivedThread = new WifiReceivedThread();//测试新线程
	wifiReceivedThread->Start(&workTest);
	char input;
	while (true)
	{
		cin >> input;
		printf("输入q，按下回车，程序将发送递增的数字到WIFI模块:%c\n",input);
		if (input == 'q'){
		data++;//自增
		//CTask *newTask = new CTask(50, &sockettest, &CMD0X80, 1);
		//CTask *newTask = new CTask(50, &sockettest, data_test, 5);
		//CTask *newTask = new CTask(50, &sockettest, &data, 1);
		PrintTool("发送信息：", data_contact, 8);
		CTask *newTask = new CTask(50, &sockettest, data_contact, 8);
		mQueue->Push(newTask);
		input = '0';
		}
	}
	


	while (true)
	{

		delay();
		//CTask *newTask = new CTask(50, &sockettest, y4, 5);
		//mQueue->Push(newTask);
		//printf("Push new Task...\n");
		//printf("Receiving...\n");
		//recv(socket.sockClient, receiveBuf, 3, 0);
		for (int i = 0; i < 3;i++)
		{
			//printf("Received:%c\n", receiveBuf[i]);
		}
		
	}


	
	
}