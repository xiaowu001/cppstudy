#include "base.h"


base::base(int state)
{
	base::setstate(state);
}


base::~base(void)
{
}
void base::setstate(int state){
	this->state = state;
}
int base::getstate(){
	return state;
}

