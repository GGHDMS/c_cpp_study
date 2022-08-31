#include "Coffee.h"
#include "Milk.h"
#include "Sugar.h"
#include <iostream>
using namespace std;

int main() {
	Beverage *coffee = new Coffee();
	coffee = new Milk(coffee);
	coffee = new Sugar(coffee);
	coffee->getDescript();
	cout << coffee->getDescript() << " : ";
	cout << coffee->getPrice() << endl;

	return 0;
}