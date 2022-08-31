#include <iostream>
#include "pet.h"
#include "cat.h"
#include "dog.h"
#include "duck.h"
#include "goldFish.h"

using namespace std;

int main()
{
	Pet *petAry[4] = { new Cat("æﬂøÀ¿Ã", Pet::MAMMAL, 2), new Dog("∏€∏€¿Ã", Pet::MAMMAL, 5),
						new Duck("µµ≥ŒµÂ", Pet::BIRDS, 1), new GoldFish("¥œ∏", Pet::FISH, 2)};

	for (int i = 0; i < 4; i++) {
		/*if (tempCat = dynamic_cast<Cat *>(petAry[i])) {
			cout << "** Cat∞¥√º ≈◊Ω∫∆Æ **" << endl;
			tempCat->eat();
			tempCat->creep();
			tempCat->view();
		}
		else if (tempDog = dynamic_cast<Dog *>(petAry[i])) {
			cout << "** Dog∞¥√º ≈◊Ω∫∆Æ **" << endl;
			tempDog->eat();
			tempDog->creep();
			tempDog->view();
		}
		else if (tempDuck = dynamic_cast<Duck *>(petAry[i])) {
			cout << "** Duck∞¥√º ≈◊Ω∫∆Æ **" << endl;
			tempDuck->eat();
			tempDuck->creep();
			tempDuck->swim();
			tempDuck->view();
		}
		else {
			tempFish = dynamic_cast<GoldFish *>(petAry[i]);
			cout << "** GoldFish∞¥√º ≈◊Ω∫∆Æ **" << endl;
			tempFish->eat();
			tempFish->swim();
			tempFish->view();
		}*/
		petAry[i]->eat();
		if (dynamic_cast<ILandAnimal *>(petAry[i])) {
			dynamic_cast<ILandAnimal *>(petAry[i])->creep();
		}
		if (dynamic_cast<IAquaticAnimal *>(petAry[i])) {
			dynamic_cast<IAquaticAnimal *>(petAry[i])->swim();
		}
		petAry[i]->view();
		cout << endl;
	}
	for (int i = 0; i < 4; i++) {
		delete petAry[i];
	}
}