#pragma once
#include "Beverage.h"

class Condiment : public Beverage
{
protected:
	Beverage *beverage;
public:
	Condiment(string name, int price, Beverage *beverage) : Beverage(name, price), beverage(beverage) {};
	virtual ~Condiment() { delete beverage; };
};

