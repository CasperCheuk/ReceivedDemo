
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
class SocketConnection{


public:
	char* carName;//С������,����һ��Socket����
	SOCKET sockClient;//Soket���Ӷ���
	SOCKADDR_IN addrServer;//Socket��������

	SocketConnection(char *car, char addressIP[], int ipPort);
	~SocketConnection();

	//��ʼ��Soket
	//���ݲ��� addressIP: ���ӵ�IP��ַ
	//���ݲ��� ipPort :���ӵ�ͨ�Ŷ˿�
	void initializeSocket(char* car, char* addressIP, int ipPort);

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

