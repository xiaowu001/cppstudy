#include "Utility.h"

using namespace std;


Utility::Utility() = default;

Utility::~Utility() = default;

int Utility::initserversocket(uint16_t &port) {
	int listenfd = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in serveraddr;
	memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(port);
    
    if(bind(listenfd, reinterpret_cast<sockaddr*> (&serveraddr), sizeof(serveraddr)) == -1){
        cout<<"bind error"<<endl;
        exit(1);
    }
    if (-1 == listen(listenfd,5)){
        cout<<"listen error"<<endl;
    }
    cout<<"listen socket done"<<endl;
    return listenfd;
}

void Utility::addepoll(int &epollfd, int listenfd){
    struct epoll_event ev = {0,{0}};
    ev.data.fd = listenfd;
    ev.events = EPOLLET|EPOLLIN|EPOLLRDHUP;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd, &ev);    
    cout<<"add fd to epoll done"<<endl;
}