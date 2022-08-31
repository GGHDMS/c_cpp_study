#include <iostream>
#include "116p.Light.h"
using namespace std;

int main()
{
	/*my_sp<Light> room1(new Light);
	my_sp<Light> room2(new Light);
	my_sp<Light> room3(new Light); */
	auto_ptr<Light> room1(new Light); // 라이브러리에서 제공해주는 스마트포인터 auto_ptr
	auto_ptr<Light> room2(new Light);
	auto_ptr<Light> room3(new Light);
	room_ctl(room1, false); 
	room_ctl(room2);
	room_ctl(room3, false);  
	cout << boolalpha << "room1 : " << room1->getStat() << endl; 
	cout << "room2 : " << room2->getStat() << endl; 
	cout << "room3 : " << room3->getStat() << endl; 
	return 0;
}