#include "product.h"
#include<iostream>

using namespace std;

product::product(void)
{
}


product::~product(void)
{
}

void product::setA(int a){
	A = a;
}

void product::setB(int b){
	B = b;
}

void product::setC(int c){
	C = c;
}
int product::geta(){
	return A;
}
int product::getc(){
	return C;
}