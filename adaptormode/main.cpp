
#include<iostream>
#include"target.h"
#include"adapter.h"

using namespace std;

int main(){
	target* t = new adapter();
	t->func();//ÀàÄ£Ê½

	target* t
	system("pause");
	return 0;
}