#include "Calculator.h"

int main() {
	CalculatorBase* c;
	Calculator1 c1;
	Calculator2 c2;
	cout << "Calculator 1" << endl;
	cout << c1.getId() << endl;
	cout << c1.add(1, 2) << endl;
	cout << c1.getResult() << endl;
	c1.printResult();
	cout << "Calculator 2" << endl;
	cout << c2.getId() << endl;
	cout << c2.mul(3, 4) << endl;
	cout << c2.getResult() << endl;
	c2.printResult();
	c = &c1;
	cout << "Calculator 1" << endl;
	cout << c->getId() << endl;
	cout << c->sub(6, 5) << endl;
	cout << c->getResult() << endl;
	c->printResult();
	c = &c2;
	cout << "Calculator 2" << endl;
	cout << c->getId() << endl;
	cout << c->div(7, 2) << endl;
	cout << c->getResult() << endl;
	c->printResult();
	return 0;
}