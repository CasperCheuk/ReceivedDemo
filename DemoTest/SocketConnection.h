
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

//封装WIFI Socket通信的类
/*
//用法示例
char*  carname = "blueCar";
char ipAddress[] = "192.168.1.1";
int ipPort = 2001;
SocketConnection socketTest(carname, ipAddress, ipPort);//初始化对象

//发送示例
send(socketTest.sockClient, "hello\n", strlen("hello\n") + 1, 0);
//或者
sockettest.sendMessageToCar("hello\n", strlen("hello\n") + 1);
//或者
char data[] = { 0xAA,0xBB,0xCC,0xDD,0xEE};
socketTest.sendMessageToCar(data, 5);
*/

class SocketConnection{

public:
	char* carName;//小车名称,代表一个Socket连接
	SOCKET sockClient;//Soket连接对象
	SOCKADDR_IN addrServer;//Socket服务配置

	SocketConnection(char *car, char addressIP[], int ipPort);
	~SocketConnection();



	/*****************************************
	* @方法名:    sendMessageToCar
	* @作者:      Casper
	* @全名:      SocketConection::sendMessageToCar
	* @权限:      public
	* @返回值:    void --
	* @Qualifier:
	* @Parameter: char data[] --发送的数据
	* @Parameter: int length --数据长度 char为单位
	* @Date:      2016/12/02
	*****************************************/
	void sendMessageToCar(char data[], int length);

};
#endif

