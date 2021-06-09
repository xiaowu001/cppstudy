#include<iostream>
#include"core.h"
#include"factory.h"
#include"subfactory1.h"
#include<vector>
using namespace std;





int main(){
	subfactory1 m;
	core* h = m.creatcore();
	h->func();
	return 0;


}