#include "factory.h"
#include<iostream>

using namespace std;
factory::factory(void)
{
}
core* factory::creatcore(){
	cout<<"building"<<endl;
	return new innercore;
}
factory::~factory(void)
{
}
