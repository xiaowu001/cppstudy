#include<iostream>
#include"builder.h"
#include"product.h"
#include"director.h"


using namespace std;

int main(){
	builder* b = new firstbuilder;
	
	director* dir = new director(b);
	product* p = b->getp();
	int n = p->geta();
	cout<<n<<endl;
}