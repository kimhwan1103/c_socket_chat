#include <stdio.h>
#include <WinSock2.h>
#pragma comment (lib, "ws2_32.lib")


int main(void) {

	WSADATA w;
	SOCKET SockSvr;
	SOCKET SockSS;
	int nlen;
	struct sockaddr_in addrSockSvr;
	struct sockaddr_in addrSockclt;

	if (WSAStartup(MAKEWORD(2, 2), &w) == SOCKET_ERROR) {
		printf("���� �ʱ�ȭ ����\n");
	}

	else
		printf("���� �ʱ�ȭ ����\n");
	

	SockSvr = socket(AF_INET, SOCK_STREAM, 0);
	if (SockSvr == INVALID_SOCKET) {
		printf("���� ���� ����\n");
		return 0;
	}
	else
		printf("���� ���� ����\n");

	addrSockSvr.sin_family = AF_INET;
	addrSockSvr.sin_port = htons(9000);
	addrSockSvr.sin_addr.S_un.S_addr = INADDR_ANY;
	bind(SockSvr, (struct sockaddr*) & addrSockSvr, sizeof(addrSockSvr));
	printf("����\n");


	listen(SockSvr, 5);
	printf("����\n");

	nlen = sizeof(addrSockclt);
	SockSS = accept(SockSvr, (struct sockaddr*) &addrSockclt, &nlen);
	printf("����\n");

	send(SockSS, "Hello TCP/IP WORLD", 18, 0);
	printf("����\n");

	closesocket(SockSS);
	printf("����\n");

	WSACleanup();

	return 0;

}