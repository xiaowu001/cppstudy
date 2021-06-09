#include "singleton.h"
#include<iostream>
using namespace std;

singleton* singleton::res = NULL;

singleton* singleton::getinstance() {
	if (res == NULL) {
		cout << "building singleton" << endl;
		res = new singleton();
	}
	return res;
}
singleton::singleton() {
	cout << "createlazyman" << endl;
};
singleton::~singleton() {};

