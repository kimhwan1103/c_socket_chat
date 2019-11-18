//소켓 통신을 위한 해더 파일 
#include <stdio.h> 
#include <WinSock2.h>
#pragma comment (lib, "ws2_32.lib")


int main(void) { //메인함수 

	WSADATA w; 
	SOCKET SockSvr;
	SOCKET SockSS;
	int nlen;
	struct sockaddr_in addrSockSvr; 
	struct sockaddr_in addrSockclt;

	if (WSAStartup(MAKEWORD(2, 2), &w) == SOCKET_ERROR) { //원속 초기화 
		printf("원속 초기화 실패\n");
	}

	else
		printf("원속 초기화 성공\n");
	

	SockSvr = socket(AF_INET, SOCK_STREAM, 0); //소켓생성
	if (SockSvr == INVALID_SOCKET) {
		printf("소켓 생성 실패\n");
		return 0;
	}
	else
		printf("소켓 생성 성공\n");

	addrSockSvr.sin_family = AF_INET;
	addrSockSvr.sin_port = htons(9000);
	addrSockSvr.sin_addr.S_un.S_addr = INADDR_ANY;
	bind(SockSvr, (struct sockaddr*) & addrSockSvr, sizeof(addrSockSvr));
	printf("성공\n");


	listen(SockSvr, 5);
	printf("성공\n");

	nlen = sizeof(addrSockclt);
	SockSS = accept(SockSvr, (struct sockaddr*) &addrSockclt, &nlen);
	printf("성공\n");

	send(SockSS, "Hello TCP/IP WORLD", 18, 0);
	printf("성공\n");

	closesocket(SockSS);
	printf("성공\n");

	WSACleanup();

	return 0;

}
