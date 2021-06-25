#include "threadpool.h"

threadpool* threadpool::instance = NULL;

threadpool* threadpool::GetInstance() {
	if (instance == NULL) {
		instance = new threadpool();
	}
	return instance;
}

threadpool::threadpool() :m_mutex(), m_cond(), isrunning(true),maxthreadnum(5){
	start();
}

threadpool::~threadpool() {
	if (isrunning) {
		stop();   
	}
}
void threadpool::stop() {
	{
		unique_lock<mutex> lck(m_mutex);

		isrunning = true;
		m_cond.notify_all();
		cout << "stop all thread,quit" << endl;
	}
	for (vector<thread*>::iterator it = pool.begin(); it != pool.end(); it++) {
		(*it)->join();
	}
	//pool.clear();
}

void threadpool::start() {
	for (int i = 0; i < maxthreadnum; i++) {
		
		pool.push_back(new thread(&threadpool::worker, this));

	}
}

void threadpool::addtask(task t) {
	{
		unique_lock<mutex> lck(m_mutex);
		cout << "addtask" << endl;
		taskque.push(t);
	}
	m_cond.notify_one();
}
void threadpool::worker() {
	
	unique_lock<mutex> lck(m_mutex);
	cout << "entering worker" << endl;
	while (isrunning) {
		if (taskque.empty()) {
			cout << "waiting" << endl;
			m_cond.wait(lck);
		}
		else {
			task cur = taskque.front();
			cout << "excute cur"<<this_thread::get_id() << endl;
			taskque.pop();
			lck.unlock();//��������ʹ���깫����Դ
			cur(); //ִ�в���
			lck.lock();//������������һ��ѭ��
			
		}
	}
}