#include "Coffee.h"
#include <cstring>

const string Coffee::name = "기본커피";
const int Coffee::price = 1500;

Coffee::Coffee() :Beverage(Coffee::name, Coffee::price) { ; }
Coffee::~Coffee(){}
int Coffee::getPrice() { return price; }
string Coffee::getDescript() {
	char buffer[100] = { 0 };
	sprintf(buffer, "(본품 : %d)",  price);
	return name + buffer;
}