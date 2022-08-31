#pragma once
#include <iostream>
#include "pet.h"
#include "IAquaticAnimal.h"

using namespace std;

class GoldFish : public Pet, public IAquaticAnimal {
public:
	GoldFish(string name = "noname", PetKind kind = UNKNOWN, age_t age = 0) : Pet(name, kind, age) { }
	~GoldFish() { }
	void eat() {
		cout << "금붕어 ";
		Pet::eat();
	}
	void swim() {
		cout << "물 속에서 헤엄칩니다" << endl;
	}
};