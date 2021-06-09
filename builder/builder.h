#pragma once
#include"product.h"
#ifndef BUILDER_H
#define BUILDER_H

class builder
{
public:
	builder(void);
	~builder(void);
	virtual void creatp() = 0;
	virtual product* getp() = 0;
	virtual void buildA() = 0;
	virtual void buildB() = 0;
	virtual void buildC() = 0;

protected:
	product* p;
};

class firstbuilder : public builder{
public:
	firstbuilder(void);
	~firstbuilder(void);
	void creatp();
	product* getp();
	void buildA();
	void buildB();
	void buildC();
};

#endif