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
		cout << "개 ";
		Pet::eat();
	}
	void creep() {
		cout << "땅 위에서 두발로 걷습니다" << endl;
	}
	void swim() {
		cout << "물 속에서 두발로 헤엄칩니다" << endl;
	}
};