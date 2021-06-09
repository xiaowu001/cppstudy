#pragma once
#include<iostream>

using namespace std;

#ifndef TARGET
#define TARGET
class target
{
public:
	target(void);
	~target(void);
	virtual void func();
};

#endif