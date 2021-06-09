#pragma once
#include "factory.h"
class subfactory1 :	public factory
{
public:
	subfactory1(void);
	virtual core* creatcore();
	~subfactory1(void);
};

