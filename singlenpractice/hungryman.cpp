#include "hungryman.h"
#include<iostream>

using namespace std;

hungryman hungryman::tmp;

hungryman::hungryman() {
	cout << "hungrymancreate" << endl;
	//tmp = *new hungryman();
};
hungryman::~hungryman() {
	cout << "hungrymanexit" << endl;
};

hungryman& hungryman::getinstance() {
	cout << "hungrymanbuidling" << endl;
	return tmp;
}
