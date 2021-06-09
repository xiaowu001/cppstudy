#pragma once

#ifndef PRODUCT_H
#define PRODUCT_H
class product
{
public:
	product(void);
	~product(void);
	virtual void setA(int a);
	virtual void setB(int b);
	virtual void setC(int c);
	int geta();
	int getc();
private:
	int A;
	int B;
	int C;
};
#endif

