
#include<iostream>
#include"target.h"
#include"adapter.h"

using namespace std;

int main(){
	target* t = new adapter();
	t->func();//��ģʽ

	target* t
	system("pause");
	return 0;
}