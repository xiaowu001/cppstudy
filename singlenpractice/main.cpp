#include<iostream>
#include<memory>
#include"singleton.h"
#include"hungryman.h"
using namespace std;


int main() {

	singleton* n = singleton::getinstance();
	singleton& ref = *singleton::getinstance();
	cout << n << endl;
	cout << &ref << endl;
}