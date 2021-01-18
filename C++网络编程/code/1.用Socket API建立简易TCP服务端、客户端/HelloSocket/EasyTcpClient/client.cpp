#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <windows.h>
#include <WinSock2.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS 0
#pragma comment(lib,"ws2_32.lib")
int main(void) {
	//启动Windows socket 2.x环境
	WORD ver = MAKEWORD(2, 2); //2.2版本
	WSADATA dat;
	WSAStartup(ver, &dat); //winsocket的启动函数 版本号
	/*****************用Socket API 建立简易TCP客户端************************/
	//1.建立一个socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, 0);//AF_INET:IPV4
	if (INVALID_SOCKET == _sock) {
		std::cout << "error,建立套接字失败...." << std::endl;
	}
	else {
		std::cout << "建立套接字成功...." << std::endl;
	}
	//2.连接服务器 connect
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);
	_sin.sin_addr.S_un.S_addr = inet_addr("192.168.31.203");
	int ret = connect(_sock, (sockaddr*)&_sin,sizeof(sockaddr_in));
	if (SOCKET_ERROR == ret) {
		std::cout << "error,连接失败...." << std::endl;
	}
	else {
		std::cout << "建立连接成功...." << std::endl;
	}
	//3.接受服务器信息 recv
	char recvBuf[256] = {};
	int nlen = recv(_sock, recvBuf, 256, 0);
	if (nlen > 0) {
		std::cout <<"接收到数据："<< recvBuf << std::endl;
	}
	//4.关闭socket close socket
	closesocket(_sock);
	/*****************************************************************/
	//清除Windows socket 环境
	WSACleanup();
	getchar();
	return 0;
}