#include <iostream>
#include "pet.h"
#include "cat.h"
#include "dog.h"
#include "duck.h"
#include "goldFish.h"

using namespace std;

int main()
{
	Pet *petAry[4] = { new Cat("�߿���", Pet::MAMMAL, 2), new Dog("�۸���", Pet::MAMMAL, 5),
						new Duck("���ε�", Pet::BIRDS, 1), new GoldFish("�ϸ�", Pet::FISH, 2)};

	for (int i = 0; i < 4; i++) {
		/*if (tempCat = dynamic_cast<Cat *>(petAry[i])) {
			cout << "** Cat��ü �׽�Ʈ **" << endl;
			tempCat->eat();
			tempCat->creep();
			tempCat->view();
		}
		else if (tempDog = dynamic_cast<Dog *>(petAry[i])) {
			cout << "** Dog��ü �׽�Ʈ **" << endl;
			tempDog->eat();
			tempDog->creep();
			tempDog->view();
		}
		else if (tempDuck = dynamic_cast<Duck *>(petAry[i])) {
			cout << "** Duck��ü �׽�Ʈ **" << endl;
			tempDuck->eat();
			tempDuck->creep();
			tempDuck->swim();
			tempDuck->view();
		}
		else {
			tempFish = dynamic_cast<GoldFish *>(petAry[i]);
			cout << "** GoldFish��ü �׽�Ʈ **" << endl;
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