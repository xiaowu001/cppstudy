#include<iostream>
#include"threadpool.h"
#include <chrono>
#include<thread>

using namespace std;

void print1() {
	cout << "print1" << endl;
}
void foo() {
	cout << "started foo" << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "done foo" << endl;
}
int main()
{
	{
		threadpool threadPool;
		

		threadPool.addtask(foo);
		threadPool.addtask(print1);
	}
	return 0;
}