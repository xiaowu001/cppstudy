#pragma once
#include"core.h"
#include"innercore.h"

#ifndef FACTORY_H
#define FACTORY_H



class factory
{
public:
	factory(void);
	virtual core* creatcore();
	~factory(void);
};

#endif;