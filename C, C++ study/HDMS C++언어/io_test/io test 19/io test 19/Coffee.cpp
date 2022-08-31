#include "Coffee.h"
#include <cstring>

const string Coffee::name = "�⺻Ŀ��";
const int Coffee::price = 1500;

Coffee::Coffee() :Beverage(Coffee::name, Coffee::price) { ; }
Coffee::~Coffee(){}
int Coffee::getPrice() { return price; }
string Coffee::getDescript() {
	char buffer[100] = { 0 };
	sprintf(buffer, "(��ǰ : %d)",  price);
	return name + buffer;
}