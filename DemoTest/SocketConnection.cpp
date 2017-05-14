
#include "SocketConnection.h"
using namespace std;

//封装WIFI Socket通信的类
/*
//初始化示例
char*  carname = "blueCar";
char ipAddress[] = "192.168.1.1";
int ipPort = 2001;
SocketConnection socketTest(carname, ipAddress, ipPort);//初始化对象

//发送示例
char data[] = { 0xAA,0xBB,0xCC,0xDD,0xEE};
socketTest.sendMessageToCar(data, 5);	//5为char data[]数组长度

//或者
send(socketTest.sockClient, "hello\n", strlen("hello\n") + 1, 0);

//或者
sockettest.sendMessageToCar("hello\n", strlen("hello\n") + 1);

*/



SocketConnection::SocketConnection(char *car, char addressIP[], int ipPort){
	carName = car;

	{//Socket初始化代码块，若不添加则出现“WSAGetLastError()=10093”错误
	WORD wVerisonRequested;
	WSADATA wsaData;
	int err;
	wVerisonRequested = MAKEWORD(1, 1);
	err = WSAStartup(wVerisonRequested, &wsaData);
	}
	sockClient = socket(AF_INET, SOCK_STREAM, 0);
	//const char address[] = "192.168.1.1";
	addrServer.sin_addr.S_un.S_addr = inet_addr(addressIP);
	addrServer.sin_family = AF_INET;
	addrServer.sin_port = htons(ipPort);//绑定端口，默认为2001
	//如果连接失败,打印信息
	//connect(sockClient, (SOCKADDR *)&addrServer, sizeof(addrServer))
	//bind(sockClient, (SOCKADDR*)&addrServer, sizeof(SOCKADDR))
	if (connect(sockClient, (SOCKADDR *)&addrServer, sizeof(addrServer)) == INVALID_SOCKET){
		printf("SocketConnect---%s failed:%d \n 连接:IP地址: %s 端口：%d \n", carName, WSAGetLastError(),  addressIP, ipPort);
	}
	else{
		printf("连接已启动: 名称:%s IP地址: %s 端口：%d \n", carName, addressIP, ipPort);
	}

}

SocketConnection::~SocketConnection(){}





	/*****************************************
	* @方法名:    sendMessageToCar
	* @作者:      Casper
	* @全名:      SocketConection::sendMessageToCar
	* @权限:      public
	* @返回值:    void --
	* @Qualifier:
	* @Parameter: char data[] --发送的数据
	* @Parameter: int length -- 数据长度 char为单位
	* @Date:      2016/12/02
	*****************************************/
	void SocketConnection::sendMessageToCar(char data[], int length){
		send(sockClient, data, length, 0);
	}

