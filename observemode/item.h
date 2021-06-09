#pragma once
#include "observe.h"
#include "base.h"
#include<iostream>
class item :
	public observe
{
public:
	item(subject* b);
	~item(void);

	virtual void update();
private:
	base* s;

};

