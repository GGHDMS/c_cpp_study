#include <iostream>
using namespace std;
#include "SmartAryT.h"
int main()
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(2);
	SmartArray<double> height(3);

	int i;
	bool res;
	double tot = 0;
	double temp;

	cout << "�� �л��� Ű �Է� �ϱ�... " << endl;
	for (i = 0; i < 3; i++)
	{
		cout << i + 1 << " �� �л��� Ű �Է� : ";
		cin >> temp;
		height.put(i, temp);
	}
	for (i = 0; i < 3; i++)
	{
		res = height.get(i, temp);
		if (res)
			tot += temp;
		else
			cout << "�迭 �б� ����" << endl;
	}
	cout << "��� Ű : " << tot / 3.0 << endl;
	return 0;
}
