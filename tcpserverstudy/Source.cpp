#include<iostream>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)
using namespace std;

int main() {
	WSADATA wsadat;
	SOCKET serversock, clientsock;
	SOCKADDR_IN serveraddr, clientaddr;
	int clientaddrlen;

	int res = WSAStartup(MAKEWORD(2, 2), &wsadat);
	if (res != 0) {
		cout << "wsastartup error" << endl;
	}

	serversock = socket(AF_INET, SOCK_STREAM, 0);
	if (serversock == INVALID_SOCKET)
	{
		cout << "socket() error" << endl;
		exit(1);
	}


	memset(&serveraddr, 0, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(atoi("1234"));

	if (bind(serversock, (SOCKADDR*) &serveraddr, sizeof(serveraddr)) == SOCKET_ERROR) {
		cout << "bind error" << endl;
		exit(1);
	};

	int tmp = listen(serversock,5);
	cout << "Enter listen mode" << endl;

	if (tmp == SOCKET_ERROR) {
		cout << "listen failed" << endl;
		exit(1);
	}

	clientaddrlen = sizeof(clientaddr);
	clientsock = accept(serversock, (SOCKADDR*)& clientaddr, &clientaddrlen);

	// 向客户端发送数据
	//char message[] = "Hello, It's servers!";
	//send(clientsock, message, sizeof(message), 0);


	char msg[1000] = { 0 };
	int msglen = recv(clientsock, msg, sizeof(msg),0);
	if (msglen == -1) {
		cout << "socket error" << endl;
		exit(1);
	}
	else {
		cout << msg << endl;
	}

	closesocket(clientsock);
	closesocket(serversock);


	WSACleanup();
	return 0;

}