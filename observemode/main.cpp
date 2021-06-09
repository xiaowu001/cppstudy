#include"observe.h"
#include"base.h"
#include"subject.h"
#include"item.h"


#include<iostream>
#include<list>

using namespace std;

int main(){
	subject* s = new base(1);
	observe* i = new item();
	s->attach(i);
	observe* i = new item(s);
	s->notify();
	system("pause");
}