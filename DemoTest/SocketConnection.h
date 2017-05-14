
#ifndef SOCKETCONECTION_H
#define SOCKETCONECTION_H
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp> 
#include<winsock2.h>
#include <fstream>
#include "SocketConnection.h"
#pragma comment(lib,"ws2_32.lib")  
using namespace std;

//��װWIFI Socketͨ�ŵ���
/*
//�÷�ʾ��
char*  carname = "blueCar";
char ipAddress[] = "192.168.1.1";
int ipPort = 2001;
SocketConnection socketTest(carname, ipAddress, ipPort);//��ʼ������

//����ʾ��
send(socketTest.sockClient, "hello\n", strlen("hello\n") + 1, 0);
//����
sockettest.sendMessageToCar("hello\n", strlen("hello\n") + 1);
//����
char data[] = { 0xAA,0xBB,0xCC,0xDD,0xEE};
socketTest.sendMessageToCar(data, 5);
*/

class SocketConnection{

public:
	char* carName;//С������,����һ��Socket����
	SOCKET sockClient;//Soket���Ӷ���
	SOCKADDR_IN addrServer;//Socket��������

	SocketConnection(char *car, char addressIP[], int ipPort);
	~SocketConnection();



	/*****************************************
	* @������:    sendMessageToCar
	* @����:      Casper
	* @ȫ��:      SocketConection::sendMessageToCar
	* @Ȩ��:      public
	* @����ֵ:    void --
	* @Qualifier:
	* @Parameter: char data[] --���͵�����
	* @Parameter: int length --���ݳ��� charΪ��λ
	* @Date:      2016/12/02
	*****************************************/
	void sendMessageToCar(char data[], int length);

};
#endif

