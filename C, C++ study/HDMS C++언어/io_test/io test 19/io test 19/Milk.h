#pragma once
#include "Condiment.h"

class Milk: public Condiment
{
public:
	static const string name;
	static const int price;
	Milk(Beverage *beverage);
	virtual ~Milk();
	int getPrice();
	string getDescript();
};

