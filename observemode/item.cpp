#include "item.h"

using namespace std;


class base;

item::item(subject* b)
{
	b->attach(this);
	this->s = (base*)b;
}


item::~item(void)
{
	if (this->s!=NULL){
		s->dettach(this);
	}
}

void item::update(){
	int n = s->getstate();
	cout<<"updating"<<n<<endl;
	cout<<"updating"<<endl;
}
