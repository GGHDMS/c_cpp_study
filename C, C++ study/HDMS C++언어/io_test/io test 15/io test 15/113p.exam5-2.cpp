#include <iostream>
#include <string>
#include "113p.exam5-2.h"
using namespace std;

int main()
{
	Temp<int> a(10);  // int���� TempŬ������ ����� ��ü ����  
	Temp<double> b(3.5);  // double�� Temp�� ����� ��ü ���� 

	cout << a.get() << endl; 
	b.put(2.4);  
	cout << b.get() << endl;

	Temp<string> c("dream");
	c.put("heia");
	cout << c.get() << endl;

	return 0;
}