#include"Charactor.h"

Charactor::Charactor(string name) : name(name) 
{
	this->way = NULL;
};
Charactor::~Charactor() {}

void Charactor::setWay(IFight *way)
{
	this->way = way;
}
