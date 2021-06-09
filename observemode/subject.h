#pragma once
#include"observe.h"
#include<list>

using namespace std;

class observe;
class subject
{
public:
	subject(void);
	~subject(void);
	virtual void attach(observe* o);
	virtual void dettach(observe* o);
	void notify();
private:
	list<observe*> obmananger;
};

