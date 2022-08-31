#include <iostream>
using namespace std;
#include "Robot.h"

Robot::Robot() {
	name = new char[strlen("") + 1];
	strcpy(name, "");
	energy = 0;
}
void Robot::errPrn() {
	cout << "에너지 부족" << endl;
}
Robot::~Robot(){
	delete[]this->name;
}
Robot::Robot(const char *name, int energy) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->energy = energy;
}
Robot::Robot(Robot&r) {
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->energy = r.energy;
}
void Robot::go() {
	energy -= 10;
	if (energy < 0) {
		errPrn();
		energy += 10;
	}
	else
	{
		cout << "전진..." << endl;
	}
}
void Robot::back() {
	energy -= 20;
	if (energy < 0) {
		errPrn();
		energy += 20;
	}
	else
	{
		cout << "후진..." << endl;
	}
}
void Robot::turn() {
	energy -= 30;
	if (energy < 0) {
		errPrn();
		energy += 30;
	}
	else
	{
		cout << "턴..." << endl;
	}
}
void Robot::jump() {
	energy -= 40;
	if (energy < 0) {
		errPrn();
		energy += 40;
	}
	else
	{
		cout << "점프..." << endl;
	}
}
void Robot::charge(int e) {
	if (e > 0) {
		this->energy += e;
	}
}
char * Robot::getName() {
	return this -> name;
}
void Robot::setName(const char * name) {
	if (this->name != NULL) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
int Robot::getEnergy() {
	return this->energy;
}
void Robot::setEnergy(int energy) {
	if (energy >= 0) {
		this->energy = energy;
	}
}