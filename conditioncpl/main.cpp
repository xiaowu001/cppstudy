#include <iostream>
#include<vector>
#include"t1.h"
using namespace std;
vector<int> func(vector<int> h) {
	vector<int> ret;
	ret = h;
	return ret;

}
int main()
{
	vector<int> tmp,res;
	tmp.push_back(1);
	tmp.push_back(2);
	res = func(tmp);
	tmp.push_back(3);
	cout << tmp[1] << endl;
}
