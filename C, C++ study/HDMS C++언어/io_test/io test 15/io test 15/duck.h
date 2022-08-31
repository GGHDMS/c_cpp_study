#pragma once
#include <iostream>
#include "pet.h"
#include "ILandAnimal.h"
#include "IAquaticAnimal.h"

using namespace std;

class Duck : public Pet, public ILandAnimal, public IAquaticAnimal {
public:
	Duck(string name = "noname", PetKind kind = UNKNOWN, age_t age = 0) : Pet(name, kind, age) { }
	~Duck() { }
	void eat() {
		cout << "�� ";
		Pet::eat();
	}
	void creep() {
		cout << "�� ������ �ι߷� �Ƚ��ϴ�" << endl;
	}
	void swim() {
		cout << "�� �ӿ��� �ι߷� ���Ĩ�ϴ�" << endl;
	}
};