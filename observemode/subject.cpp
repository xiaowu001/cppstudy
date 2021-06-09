#include "subject.h"


subject::subject(void)
{
}


subject::~subject(void)
{
}

void subject::attach(observe* o){
	obmananger.push_back(o);
}

void subject::dettach(observe* o){
	obmananger.remove(o);
}

void subject::notify(){
	list<observe*>::iterator it;
	for (it = obmananger.begin();it !=obmananger.end();it++){
		(*it)->update();
	}
}