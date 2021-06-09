#include<iostream>
#include<sys/socket.h>
#include<sys/epoll.h>
#include<fcntl.h>
#include<memory.h>
#include"Utility.h"
//#include <netinet/in.h>  
//#include <arpa/inet.h>  


#define MAX_EVENTS 500
using namespace std;

int main() {
	uint16_t port = 8086;
    int clientfd, sockfd;
    sockaddr_in clientaddr;
    
    ssize_t n;
    char dat[1000];
	int listenfd = Utility::initserversocket(port);
    
    int epollfd = epoll_create(MAX_EVENTS); //epollfd创建
    
    fcntl(listenfd, F_SETFL, O_NONBLOCK);//设置socket为非阻塞
    
    Utility::addepoll(epollfd, listenfd);
    
    struct epoll_event events[20];
    struct epoll_event ev;
    while(1){
        int nums = epoll_wait(epollfd, events,20,500);
        for (int i = 0;i<nums;i++){
            if (events[i].data.fd == listenfd){
                socklen_t clientaddrlen = sizeof(clientaddr);
                clientfd = accept(listenfd, reinterpret_cast<sockaddr*> (&clientaddr), &clientaddrlen);
                Utility::addepoll(epollfd,clientfd);
            }else if(events[i].events & EPOLLIN){
               sockfd = events[i].data.fd;
               
               if (recv(sockfd, dat, sizeof(dat),0) == -1){
                   cout<<"socket recv error"<<endl;
                   exit(1);
               }else{
                   cout<<dat<<endl;
               }
               
               //if( (n = read(sockfd, dat, 100)) < 0){
               //    cout<<"read error"<<endl;
               //}
               ev.data.fd = sockfd;
               ev.events = EPOLLIN|EPOLLET;
               epoll_ctl(epollfd, EPOLL_CTL_DEL, sockfd, &ev);
            }else if (events[i].events & EPOLLOUT){
                cout<<"not developed"<<endl;
                exit(1);
               // sockfd = events[i].data.fd;
               //write(sockfd,dat,n);
               //ev.data.fd = sockfd;
               //ev.events = EPOLLIN|EPOLLET;
               //epoll_ctl(epollfd, EPOLL_CTL_MOD, sockfd, &ev);
            }
            
        }
        
    }
    return 0;
}