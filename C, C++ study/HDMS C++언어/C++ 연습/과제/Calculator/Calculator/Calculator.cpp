#include "Calculator.h"

CalculatorBase::CalculatorBase() {
	id = seq;
	seq++;
}
int CalculatorBase::getId() {
	return id;
}
double CalculatorBase::getResult() {
	return result;
}
void CalculatorBase::printResult() {
	;
}

int CalculatorBase::seq = 0;

double Calculator1::add(double a, double b) {
	last_a = a;
	last_b = b;
	last_op = '+';
	result = a + b;
	return result;
}
double Calculator1::sub(double a, double b) {
	last_a = a;
	last_b = b;
	last_op = '-';
	result = a - b;
	return result;
}
double Calculator1::mul(double a, double b) {
	last_a = a;
	last_b = b;
	last_op = '*';
	result = a * b;
	return result;
}
double Calculator1::div(double a, double b) {
	last_a = a;
	last_b = b;
	last_op = '/';
	result = a / b;
	return result;
}
void Calculator1::printResult() {
	cout << last_a << last_op << last_b << '=' << result << endl;
}

double Calculator2::add(double a, double b) {
	result = a + b;
	cout << a << '+' << b << '=' << result << endl;
	return result;
}
double Calculator2::sub(double a, double b) {
	result = a - b;
	cout << a << '-' << b << '=' << result << endl;
	return result;
}
double Calculator2::mul(double a, double b) {
	result = a * b;
	cout << a << '*' << b << '=' << result << endl;
	return result;
}
double Calculator2::div(double a, double b) {
	result = a / b;
	cout << a << '/' << b << '=' << result << endl;
	return result;
}

void Calculator2::printResult() {
	cout << "Last Result : " << result << endl;
}