#pragma once
#include "subject.h"
class base :
	public subject
{
public:
	base(int n);
	~base(void);
	int getstate();
	void setstate(int state);
private:
	int state;


};

