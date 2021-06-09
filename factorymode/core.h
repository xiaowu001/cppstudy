#pragma once
#include<vector>
#ifndef CORE_H
#define CORE_H

using namespace std;

class core
{
public:
	core(void);
	vector<int> tmp;
	virtual void func();

	~core(void);
};
#endif;
