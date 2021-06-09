#include "subfactory1.h"
#include<iostream>

using namespace std;

subfactory1::subfactory1(void)
{
}

core* subfactory1::creatcore(){
	cout<<"subfactroy building"<<endl;
	return new innercore;
}
subfactory1::~subfactory1(void)
{
}
