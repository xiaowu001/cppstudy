
#include <iostream>
#include <thread>
#include<mutex>
#include <chrono>

using namespace std;

mutex mut;


void thread_function(int n)
{
	lock_guard<mutex> lock(mut);
	std::thread::id this_id = std::this_thread::get_id();			//��ȡ�߳�ID

	for (int i = 0; i < 5; i++) {
		cout << "Child function thread " << this_id << " running : " << i + 1 << endl;
		std::this_thread::sleep_for(std::chrono::seconds(n));   	//����˯��n��
	}
}

class Thread_functor
{
public:
	// functor��Ϊ���ƺ���,C++�еķº�����ͨ������������()�����ʵ�֣�ʹ�������ʹ�ú���һ����������Ķ���
	void operator()(int n)
	{
		lock_guard<mutex> lock(mut);
		std::thread::id this_id = std::this_thread::get_id();

		for (int i = 0; i < 5; i++) {
			cout << "Child functor thread " << this_id << " running: " << i + 1 << endl;
			std::this_thread::sleep_for(std::chrono::seconds(n));   //����˯��n��
		}
	}
};


int main()
{
	thread mythread1(thread_function, 1);      // ���ݳ�ʼ������Ϊ�̵߳Ĳ���
	if (mythread1.joinable())                  //�ж��Ƿ���Գɹ�ʹ��join()����detach()������true����ԣ�����false�򲻿���
		mythread1.join();                     // ʹ��join()�����������߳�ֱ�����߳�ִ�����

	Thread_functor thread_functor;			 //��������ʵ����һ������
	thread mythread2(thread_functor, 3);     // ���ݳ�ʼ������Ϊ�̵߳Ĳ���
	if (mythread2.joinable())
		mythread2.detach();                  // ʹ��detach()���������̺߳����̲߳������У����߳�Ҳ���ٵȴ����߳�

	auto thread_lambda = [](int n) {			//lambda���ʽ��ʽ��[capture list] (params list) mutable exception-> return type { function body }
		lock_guard<mutex> lock(mut);
		std::thread::id this_id = std::this_thread::get_id();
		for (int i = 0; i < 5; i++)
		{
			cout << "Child lambda thread " << this_id << " running: " << i + 1 << endl;
			std::this_thread::sleep_for(std::chrono::seconds(n));   //����˯��n��
		}
	};

	thread mythread3(thread_lambda, 4);     // ���ݳ�ʼ������Ϊ�̵߳Ĳ���
	if (mythread3.joinable())
		mythread3.join();                     // ʹ��join()�����������߳�ֱ�����߳�ִ�����

	std::thread::id this_id = std::this_thread::get_id();
	for (int i = 0; i < 5; i++) {
		cout << "Main thread " << this_id << " running: " << i + 1 << endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	getchar();
	return 0;
}
