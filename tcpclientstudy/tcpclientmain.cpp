#include<iostream>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#pragma warning(disable:4996)
using namespace std;

int main() {
	WSADATA wsadat;
	SOCKADDR_IN sockaddress;

	const char* pdata = "this is client";

	int result = WSAStartup(MAKEWORD(2, 2), &wsadat);
	if (result != 0) {
		cout << "winsocket startup failed" << endl;
		exit(1);
	}



	SOCKET sock;
	sock= socket(AF_INET, SOCK_STREAM, 0);
	if (sock == INVALID_SOCKET) {
		cout << "Could not create socket " << endl;
		exit(1);
	}

	/*int flag = 1;
	if (-1 == setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<const char*>(&flag), sizeof(flag)))
	{
		cout << "Set Socket Failed!! Errno" << endl;
		exit(1);
	}*/

	memset(&sockaddress, 0, sizeof(sockaddress));
	sockaddress.sin_family = AF_INET;
	sockaddress.sin_addr.s_addr =inet_addr("10.9.82.169");//server µÄµØÖ·
	sockaddress.sin_port = htons(atoi("1234"));



	if (SOCKET_ERROR == connect(sock, (SOCKADDR*)& sockaddress, sizeof(sockaddress))) {

		cout << "connect error";
		cout << WSAGetLastError() << endl;
		exit(1);
	}

	//char message[100] = { 0 };
	//int msglen = recv(sock, message, sizeof(message) - 1, 0);
	//if (msglen == -1)
	//{
	//	cout << "recv() error" << endl;
	//	exit(1);
	//}

	//cout << "msg from server : " << message << endl;
	send(sock, pdata, 15, 0);


	closesocket(sock);
	WSACleanup();

	return 0;

}
