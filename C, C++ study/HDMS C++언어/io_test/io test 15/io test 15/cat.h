#pragma once
#include <iostream>
#include "pet.h"
#include "ILandAnimal.h"

using namespace std;

class Cat : public Pet, public ILandAnimal {
public:
	Cat(string name = "noname", PetKind kind = UNKNOWN, age_t age = 0) : Pet(name, kind, age) { }
	~Cat() { }
	void eat() {
		cout << "고양이 ";
		Pet::eat();
	}
	void creep() {
		cout << "땅 위에서 사뿐사뿐 걷습니다" << endl;
	}
};
