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
		cout << "개 ";
		Pet::eat();
	}
	void creep() {
		cout << "땅 위에서 네발로 걷습니다" << endl;
	}
};