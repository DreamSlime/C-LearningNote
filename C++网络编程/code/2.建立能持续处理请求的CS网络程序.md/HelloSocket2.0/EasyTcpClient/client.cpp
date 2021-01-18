#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <windows.h>
#include <WinSock2.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS 0
#pragma comment(lib,"ws2_32.lib")
int main(void) {
	//����Windows socket 2.x����
	WORD ver = MAKEWORD(2, 2); //2.2�汾
	WSADATA dat;
	WSAStartup(ver, &dat); //winsocket���������� �汾��
	/*****************��Socket API ��������TCP�ͻ���************************/
	//1.����һ��socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, 0);//AF_INET:IPV4
	if (INVALID_SOCKET == _sock) {
		std::cout << "error,�����׽���ʧ��...." << std::endl;
	}
	else {
		std::cout << "�����׽��ֳɹ�...." << std::endl;
	}
	//2.���ӷ����� connect
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);
	_sin.sin_addr.S_un.S_addr = inet_addr("192.168.31.203");
	int ret = connect(_sock, (sockaddr*)&_sin, sizeof(sockaddr_in));
	if (SOCKET_ERROR == ret) {
		std::cout << "error,����ʧ��...." << std::endl;
	}
	else {
		std::cout << "�������ӳɹ�...." << std::endl;
	}
	while (true) {
		//3.������������
		char cmdBuf[128] = {};
		scanf("%s",cmdBuf);
		//4.��������
		std::cout << 2 << std::endl;
		Sleep(300);
		if (strcmp(cmdBuf, "exit")==0) {
			std::cout << "�յ��˳�������������..." << std::endl;
			break;
		}
		else {
			//5.�������������������
			send(_sock, cmdBuf, strlen(cmdBuf) + 1, 0);
		}
		//6.���ܷ�������Ϣ recv
		char recvBuf[256] = {};
		int nlen = recv(_sock, recvBuf, 256, 0);
		if (nlen > 0) {
			std::cout << "���յ����ݣ�" << recvBuf << std::endl;
		}
	}
	//7.�ر�socket close socket
	closesocket(_sock);
	/*****************************************************************/
	//���Windows socket ����
	WSACleanup();
	std::cout << "���˳������������..." << std::endl;
	getchar();
	return 0;
}