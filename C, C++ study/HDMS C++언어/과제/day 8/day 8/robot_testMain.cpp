#include<iostream>
using namespace std;
#include "Robot.h"

int main()
{
	Robot r1;
	Robot r2("하랑이");
	Robot r3("댕댕이", 100);
	Robot r4(r2);

	cout << r1.getName() << " " << r2.getEnergy() << endl;
	cout << r2.getName() << " " << r2.getEnergy() << endl;
	cout << r3.getName() << " " << r3.getEnergy() << endl;
	cout << r4.getName() << " " << r4.getEnergy() << endl;

	r2.setName("로보트태권브이");
	r2.setEnergy(250);
	r2.setEnergy(-50);
	cout << r2.getName() << " " << r2.getEnergy() << endl;

	r3.go();
	r3.back();
	r3.turn();
	r3.jump();
	r3.charge(120);
	cout << r3.getName() << " " << r3.getEnergy() << endl;

	return 0;
}