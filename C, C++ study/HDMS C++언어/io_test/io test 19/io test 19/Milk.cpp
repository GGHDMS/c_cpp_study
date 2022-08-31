#include "Milk.h"
#include <cstring>

const string Milk::name = "밀크";
const int Milk::price = 500;

Milk::Milk(Beverage *beverage):Condiment(Milk::name, Milk::price, beverage)
{

}
Milk::~Milk(){ }
int Milk::getPrice() {
	return (price + beverage->getPrice());
}
string Milk::getDescript() {
	char buffer[100] = { 0 };
	sprintf(buffer, "(옵션 : %d) > ", price);
	return name +  buffer + beverage->getDescript();
}