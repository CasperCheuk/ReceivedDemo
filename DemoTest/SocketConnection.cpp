
#include "SocketConnection.h"
using namespace std;

//��װWIFI Socketͨ�ŵ���
/*
//��ʼ��ʾ��
char*  carname = "blueCar";
char ipAddress[] = "192.168.1.1";
int ipPort = 2001;
SocketConnection socketTest(carname, ipAddress, ipPort);//��ʼ������

//����ʾ��
char data[] = { 0xAA,0xBB,0xCC,0xDD,0xEE};
socketTest.sendMessageToCar(data, 5);	//5Ϊchar data[]���鳤��

//����
send(socketTest.sockClient, "hello\n", strlen("hello\n") + 1, 0);

//����
sockettest.sendMessageToCar("hello\n", strlen("hello\n") + 1);

*/



SocketConnection::SocketConnection(char *car, char addressIP[], int ipPort){
	carName = car;

	{//Socket��ʼ������飬�����������֡�WSAGetLastError()=10093������
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
	addrServer.sin_port = htons(ipPort);//�󶨶˿ڣ�Ĭ��Ϊ2001
	//�������ʧ��,��ӡ��Ϣ
	//connect(sockClient, (SOCKADDR *)&addrServer, sizeof(addrServer))
	//bind(sockClient, (SOCKADDR*)&addrServer, sizeof(SOCKADDR))
	if (connect(sockClient, (SOCKADDR *)&addrServer, sizeof(addrServer)) == INVALID_SOCKET){
		printf("SocketConnect---%s failed:%d \n ����:IP��ַ: %s �˿ڣ�%d \n", carName, WSAGetLastError(),  addressIP, ipPort);
	}
	else{
		printf("����������: ����:%s IP��ַ: %s �˿ڣ�%d \n", carName, addressIP, ipPort);
	}

}

SocketConnection::~SocketConnection(){}





	/*****************************************
	* @������:    sendMessageToCar
	* @����:      Casper
	* @ȫ��:      SocketConection::sendMessageToCar
	* @Ȩ��:      public
	* @����ֵ:    void --
	* @Qualifier:
	* @Parameter: char data[] --���͵�����
	* @Parameter: int length -- ���ݳ��� charΪ��λ
	* @Date:      2016/12/02
	*****************************************/
	void SocketConnection::sendMessageToCar(char data[], int length){
		send(sockClient, data, length, 0);
	}

