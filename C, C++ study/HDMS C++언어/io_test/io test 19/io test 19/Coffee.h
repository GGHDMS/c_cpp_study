#pragma once
#include "Beverage.h"

class Coffee: public Beverage
{
public:
	static const string name;
	static const int price;
	Coffee();
	virtual ~Coffee();
	virtual int getPrice();
	virtual string getDescript();
};

