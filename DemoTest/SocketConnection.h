
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
class SocketConnection{


public:
	char* carName;//小车名称,代表一个Socket连接
	SOCKET sockClient;//Soket连接对象
	SOCKADDR_IN addrServer;//Socket服务配置

	SocketConnection(char *car, char addressIP[], int ipPort);
	~SocketConnection();

	//初始化Soket
	//传递参数 addressIP: 连接的IP地址
	//传递参数 ipPort :连接的通信端口
	void initializeSocket(char* car, char* addressIP, int ipPort);

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

