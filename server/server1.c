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
		printf("盔加 檬扁拳 角菩\n");
	}

	else
		printf("盔加 檬扁拳 己傍\n");
	

	SockSvr = socket(AF_INET, SOCK_STREAM, 0);
	if (SockSvr == INVALID_SOCKET) {
		printf("家南 积己 角菩\n");
		return 0;
	}
	else
		printf("家南 积己 己傍\n");

	addrSockSvr.sin_family = AF_INET;
	addrSockSvr.sin_port = htons(9000);
	addrSockSvr.sin_addr.S_un.S_addr = INADDR_ANY;
	bind(SockSvr, (struct sockaddr*) & addrSockSvr, sizeof(addrSockSvr));
	printf("己傍\n");


	listen(SockSvr, 5);
	printf("己傍\n");

	nlen = sizeof(addrSockclt);
	SockSS = accept(SockSvr, (struct sockaddr*) &addrSockclt, &nlen);
	printf("己傍\n");

	send(SockSS, "Hello TCP/IP WORLD", 18, 0);
	printf("己傍\n");

	closesocket(SockSS);
	printf("己傍\n");

	WSACleanup();

	return 0;

}