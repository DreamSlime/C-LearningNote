#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <windows.h>
#include <WinSock2.h>


int main(void) {

	//启动Windows socket 2.x环境
	WORD ver = MAKEWORD(2,2); //2.2版本
	WSADATA dat;	  
	WSAStartup(ver,&dat); //winsocket的启动函数 版本号
	/*****************编写socket网络通信的代码************************/


	/*****************************************************************/
	//清除Windows socket 环境
	WSACleanup();
	return 0;
}