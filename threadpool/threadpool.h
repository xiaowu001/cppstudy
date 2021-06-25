#pragma once
#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <utility>
#include <queue>
#include <thread>
#include <functional>
#include <mutex>
#include<iostream>


using namespace std;
class threadpool
{
public:
	threadpool();
	~threadpool();
	void start();
	void stop();
	static threadpool* GetInstance();


private:
	using task = function<void()>;
	vector<thread*> pool;
	queue<task> taskque;

	mutex m_mutex;
	condition_variable m_cond;
	static threadpool* instance;

	bool isrunning;
	int maxthreadnum;
public:
	void addtask(task t);
	void worker();
};

#endif