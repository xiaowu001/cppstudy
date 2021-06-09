#include<iostream>
#include "builder.h"

using namespace std;

builder::builder(void)
{
}
builder::~builder(void)
{
}
firstbuilder::firstbuilder(void){
}
firstbuilder::~firstbuilder(void){
}
void firstbuilder::creatp(){
	 p = new product;
}
product* firstbuilder::getp(){
	return p;
}
void firstbuilder::buildA(){
	cout<<"Abuilding"<<endl;
	p->setA(1);
}
void firstbuilder::buildB(){
	cout<<"Bbuilding"<<endl;
	p->setB(2);
}
void firstbuilder::buildC(){
	cout<<"Cbuilding"<<endl;
	p->setC(3);
}