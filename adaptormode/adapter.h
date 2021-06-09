#pragma once
#include "target.h"
#include"adaptee.h"
class adapter :	public target, private adaptee
{
public:
	adapter(void);
	~adapter(void);
	virtual void func();
};

