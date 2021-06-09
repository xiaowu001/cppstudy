#pragma once
#include<stdio.h>
#ifndef SINGLETON
#define SINGLETON

using namespace std;

class singleton
{
public:
	singleton();
	~singleton();
	static singleton* getinstance();
private:
	static singleton* res;
};
#endif // !SINGLETON



