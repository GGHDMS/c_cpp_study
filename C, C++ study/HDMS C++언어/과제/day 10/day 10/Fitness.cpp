#include "Fitness.h"

Fitness::Fitness() {
	num = 0;
	name = new char[strlen("") + 1];
	strcpy(name, "");
	weight = 0;
	height = 0;
}
Fitness::Fitness(int num, char *name, double weight, double height) {
	this->num = num;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->weight = weight;
	this->height = height;
}
Fitness::Fitness(Fitness &r) {
	name = new char[strlen(r.name) + 1];
	strcpy(name, r.name);
	num = r.num;
	weight = r.weight;
	height = r.height;
}
Fitness::~Fitness() {
	if (this->name != NULL) {
		delete[]name;
	}
}
Fitness & Fitness::operator=(Fitness &r) {
	if (this == &r) return *this;
	delete[]name;
	name = new char[strlen(r.name) + 1];
	strcpy(name, r.name);
	num = r.num;
	weight = r.weight;
	height = r.height;
	return *this;
}
bool Fitness::operator==(Fitness &r) {
	if (strcmp(name, r.name) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
void Fitness::setNum(int num) {
	this->num = num;
}
int Fitness::getNum() {
	return num;
}
void Fitness::setName(const char * name) {
	if (this->name != NULL) {
		delete[]name;
	}
	if (name != NULL) {
		name = new char[strlen(name) + 1];
	}
}
char * Fitness::getName() {
	return name;
}
void Fitness::setWeight(double weight) {
	this->weight = weight;
}
double Fitness::getWeight() {
	return weight;
}
void Fitness::setHeight(double height) {
	this->height = height;
}
double Fitness::getHeight() {
	return height;
}
double Fitness::bmi() {
	return weight / ((height/100)*(height/100));
}
