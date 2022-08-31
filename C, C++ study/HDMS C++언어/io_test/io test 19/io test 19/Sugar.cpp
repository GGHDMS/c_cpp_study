#include "Sugar.h"
const string Sugar::name = "����";
const int Sugar::price = 500;

Sugar::Sugar(Beverage *beverage):Condiment(Sugar::name, Sugar::price, beverage)
{

}
Sugar::~Sugar() { }
int Sugar::getPrice() {
	return (price + beverage->getPrice());
}
string Sugar::getDescript() {
	char buffer[100] = { 0 };
	sprintf(buffer, "(�ɼ� : %d) > ", price);
	return name + buffer + beverage->getDescript();
}