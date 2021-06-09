#include<iostream>
#include<vector>
#include"test1.h"
using namespace std;

typedef int (*f)(int a, int b);
int func(int a, int b){
	return a+b;
}
class test{
public:
	void geta(){
		cout<<"check"<<a<<endl;
	}
private:
	int a;
};


template<typename T> void swapt(T& t1, T& t2){
	T temp;
	temp =t1;
	t1 = t2;
	t2 = temp;

}
template<> void swapt(vector<int>& t1,vector<int>& t2){
	t1.swap(t2);
	cout<<"hhh"<<endl;
}

int main(){
	//int n = func(1,2);
	//f fun = func;
	//int m = fun(5,6);
	//cout<<*fun<<endl;
	//cout<<*func<<endl;
	//typedef函数名称定义
	vector<int> h1, h2;
	h1.push_back(1);
	h2.push_back(2);

	swapt(h1, h2);

	cout<<h1[0]<<endl;
	funout();
	system("pause");
}