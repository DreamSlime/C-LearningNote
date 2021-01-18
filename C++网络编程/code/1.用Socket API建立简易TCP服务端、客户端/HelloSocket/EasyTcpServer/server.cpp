#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN

#include <iostream>
#include <windows.h>
#include <WinSock2.h>


int main(void) {

	//����Windows socket 2.x����
	WORD ver = MAKEWORD(2, 2); //2.2�汾
	WSADATA dat;
	WSAStartup(ver, &dat); //winsocket���������� �汾��
	/*****************��Socket API ��������TCP�����************************/
	//1.����һ��socket(�׽���)
	SOCKET _sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);//AF_INET:IPV4 SOCK_STREAM:��������socket���� IPPROTO_TCP:TCP��ʽ
	//2.�󶨽��ܿͻ������ӵĶ˿� bind
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET; //IPV4����
	_sin.sin_port =htons(4567); //�˿ں� host to net unsigned short ������������תΪ���������
	_sin.sin_addr.S_un.S_addr = INADDR_ANY;//�������󶨵�ip��ַ��һ�����������ж��ip��ַ д��1��inet_addr("192.168.31.203") д��2��INADDR_ANY(�������е�ip��ַ)
	if (bind(_sock, (sockaddr*)&_sin, sizeof(sockaddr_in)) == SOCKET_ERROR) {
		std::cout<<"error,�󶨽��ܿͻ������ӵĶ˿�ʧ��...."<< std::endl;
	}
	else {
		std::cout << "�󶨽��ܿͻ������ӵĶ˿ڳɹ�...." << std::endl;
	}
	//3.��������˿� listen
	if (listen(_sock, 5) == SOCKET_ERROR) {//���ȴ�5��������
		std::cout << "error,��������˿�ʧ��...." << std::endl;
	}
	else {
		std::cout << "��������˿ڳɹ�...." << std::endl;
	}
	//4.�ȴ����ܿͻ������� accept
	sockaddr_in ClientAddr = {};
	int nAddrLen = sizeof(sockaddr_in);
	SOCKET _cSock = INVALID_SOCKET;
	char msgBuf[] = "Hello, I'm Server.";
	while (true) {
		_cSock = accept(_sock, (sockaddr*)&ClientAddr, &nAddrLen); //���ͻ����������ǵ�ʱ�����ǾͿ����յ�ClientAddr(socket����)��nAddrLen(socket���ݵĳ���)
		if (_cSock == INVALID_SOCKET) {
			std::cout << "warning,���ܵ���Ч�ͻ���SOCKET...." << std::endl;
		}
		std::cout << "�¿ͻ��˼���:IP=" <<inet_ntoa(ClientAddr.sin_addr)<< std::endl;
		//5.��ͻ��˷���һ������send
		send(_cSock, msgBuf, strlen(msgBuf) + 1, 0);//���͸�_cSock msgBuf��Ϣ +1Ϊ��β��
	}
	//6.�ر�socket close socket
	closesocket(_sock);
	/*****************************************************************/
	//���Windows socket ����
	WSACleanup();
	return 0;
}