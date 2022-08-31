#pragma once
#include <iostream>
#include "pet.h"
#include "ILandAnimal.h"

using namespace std;

class Dog : public Pet, public ILandAnimal {
public:
	Dog(string name = "noname", PetKind kind = UNKNOWN, age_t age = 0) : Pet(name, kind, age) { }
	~Dog() { }
	void eat() {
		cout << "�� ";
		Pet::eat();
	}
	void creep() {
		cout << "�� ������ �׹߷� �Ƚ��ϴ�" << endl;
	}
};