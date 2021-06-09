#include "adapter.h"


adapter::adapter(void)
{
}


adapter::~adapter(void)
{
}

void adapter::func(){
	cout<<"rewriting"<<endl;
	this->adafunc(); //重写func接口，使接口变为适应adaptee的接口
}