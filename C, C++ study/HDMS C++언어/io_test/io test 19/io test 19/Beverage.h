#pragma once
#include <string>
using namespace std;
class Beverage
{
protected:
	string name;
	int price;
public:
	Beverage(string name, int price) :name(name), price(price) {};
	virtual ~Beverage() {};
	virtual int getPrice() = 0 ;
	virtual string getDescript() = 0;

};