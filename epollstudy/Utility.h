#include <mutex>
#include<iostream>
#include <netinet/in.h>
#include <fcntl.h>
#include<sys/socket.h>
#include<sys/epoll.h>
#include<memory.h>
#include <errno.h>


#pragma once

using namespace std;

class Utility
{
public:
	Utility();

	virtual ~Utility();
    
    static std::mutex mutex;

	static int initserversocket(uint16_t &port);
    static void addepoll(int &epollfd, int listenfd);
};

