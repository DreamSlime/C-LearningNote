#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <windows.h>
#include <WinSock2.h>


int main(void) {

	//����Windows socket 2.x����
	WORD ver = MAKEWORD(2,2); //2.2�汾
	WSADATA dat;	  
	WSAStartup(ver,&dat); //winsocket���������� �汾��
	/*****************��дsocket����ͨ�ŵĴ���************************/


	/*****************************************************************/
	//���Windows socket ����
	WSACleanup();
	return 0;
}