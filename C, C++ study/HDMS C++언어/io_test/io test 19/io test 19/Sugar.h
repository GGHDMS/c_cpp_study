#pragma once
#include "Condiment.h"

class Sugar:public Condiment
{
public:
	static const string name;
	static const int price;
	Sugar(Beverage *beverage);
	virtual ~Sugar();
	int getPrice();
	string getDescript();
};

