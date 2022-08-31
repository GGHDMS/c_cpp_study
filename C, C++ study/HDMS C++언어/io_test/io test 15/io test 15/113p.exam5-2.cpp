#include <iostream>
#include <string>
#include "113p.exam5-2.h"
using namespace std;

int main()
{
	Temp<int> a(10);  // int형의 Temp클래스를 만들고 객체 생성  
	Temp<double> b(3.5);  // double형 Temp를 만들고 객체 생성 

	cout << a.get() << endl; 
	b.put(2.4);  
	cout << b.get() << endl;

	Temp<string> c("dream");
	c.put("heia");
	cout << c.get() << endl;

	return 0;
}