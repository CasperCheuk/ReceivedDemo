
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
//ͷ�ļ�

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
	printf("�����߳�����...\n");

	while (true)
	{
		char* receivedBuff = ReceiveData(sockettest.sockClient);//�÷���ֵ��һ5���ֽڳ�����
		switch (receivedBuff[0])
		{
		case 0x31://�����˿���
			break;
		case 0x32://���ڵ��ȼ��� 
			break;
		case 0x33://�������Դ�����ͷ�����������ڼ���
			break;
		case 0x34://���������ڵ���ж��
			break;
		case 0x35://������ж�����
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
		printf("�������ݳ��ȣ�%d\n", received_Lenth);
		if (receivedbuff[3]==0x22)continue;
		if (received_Lenth==0) continue;
		PrintTool("������Ϣ��",receivedbuff,8);
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
	char receiveBuf[10];//����

	//����ʾ��
	//send(sockettest.sockClient, "hello\n", strlen("hello\n") + 1, 0);
	//sockettest.sendMessageToCar("hello\n", strlen("hello\n") + 1);
	sockettest.sendMessageToCar(data_test, 5);

	CTaskQueue *mQueue = new CTaskQueue();
	mQueue->Start();

	WifiReceivedThread *wifiReceivedThread = new WifiReceivedThread();//�������߳�
	wifiReceivedThread->Start(&workTest);
	char input;
	while (true)
	{
		cin >> input;
		printf("����q�����»س������򽫷��͵��������ֵ�WIFIģ��:%c\n",input);
		if (input == 'q'){
		data++;//����
		//CTask *newTask = new CTask(50, &sockettest, &CMD0X80, 1);
		//CTask *newTask = new CTask(50, &sockettest, data_test, 5);
		//CTask *newTask = new CTask(50, &sockettest, &data, 1);
		PrintTool("������Ϣ��", data_contact, 8);
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