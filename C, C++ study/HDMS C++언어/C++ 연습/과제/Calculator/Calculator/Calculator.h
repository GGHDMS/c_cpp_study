#ifndef Calculator_h
#define Calculaotr_h
#include <iostream>
using namespace std;
class CalculatorBase {
	int id;
	static int seq;
protected:
	double result;
public:
	CalculatorBase();
	int getId();
	double getResult();
	virtual void printResult();
	virtual double add(double a, double b) = 0;
	virtual	double sub(double a, double b) = 0;
	virtual double mul(double a, double b) = 0;
	virtual double div(double a, double b) = 0;
};


class Calculator1 : public CalculatorBase {
	double last_a;
	double last_b;
	char last_op;
public:
	virtual double add(double a, double b);
	virtual	double sub(double a, double b);
	virtual double mul(double a, double b);
	virtual double div(double a, double b);
	void printResult();
};

class Calculator2 : public CalculatorBase {
public:
	virtual double add(double a, double b);
	virtual	double sub(double a, double b);
	virtual double mul(double a, double b);
	virtual double div(double a, double b);
	void printResult();
};

#endif 