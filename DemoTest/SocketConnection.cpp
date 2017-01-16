
#include "SocketConnection.h"
using namespace std;

//��װWIFI Socketͨ�ŵ���

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
	if (connect(sockClient, (SOCKADDR *)&addrServer, sizeof(addrServer)) == INVALID_SOCKET){
		printf("SocketConnect---%s failed:%d \n ����:IP��ַ: %s �˿ڣ�%d \n", carName, WSAGetLastError(),  addressIP, ipPort);
	}
	else{
		printf("����������: ����:%s IP��ַ: %s �˿ڣ�%d \n", carName, addressIP, ipPort);
	}

}

SocketConnection::~SocketConnection(){}

	//��ʼ��Soket
	//���ݲ��� addressIP: ���ӵ�IP��ַ
	//���ݲ��� ipPort :���ӵ�ͨ�Ŷ˿�
	void SocketConnection::initializeSocket(char* car, char* addressIP, int ipPort){

	}



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

