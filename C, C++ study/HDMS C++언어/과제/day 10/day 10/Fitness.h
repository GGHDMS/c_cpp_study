#pragma once
#include <iostream>
using namespace std;

class Fitness {
private:
	int num;
	char *name;
	double weight;
	double height;
public:
	Fitness();
	Fitness(int num, char *name, double weight, double height);
	Fitness(Fitness &r);;
	~Fitness();
	Fitness & operator=(Fitness &r);
	bool operator==(Fitness &r);
	void setNum(int num);
	int getNum();
	void setName(const char * name);
	char *getName();
	void setWeight(double weight);
	double getWeight();
	void setHeight(double height);
	double getHeight();
	double bmi();
};
