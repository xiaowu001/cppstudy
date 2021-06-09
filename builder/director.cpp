#include "director.h"



director::director(builder* b){
	b->creatp();
	b->buildA();
	b->buildB();
	b->buildC();

}

director::~director(void)
{
}
