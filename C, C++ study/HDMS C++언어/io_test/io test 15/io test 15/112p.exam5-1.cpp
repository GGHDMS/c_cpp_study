#include <iostream>
#include "112p.exam5-1.h"
using namespace std;

int main()
{
	int a = 10, b = 20, ires;
	double x = 2.4, y = 3.5, dres;
	const char *ap = "apple", *bp = "banana", *resp;

	ires = max(a, b);
	cout << "�� ���� �߿��� ū �� : " << ires << endl;
	dres = max(x, y);
	cout << "�� �Ǽ� �߿��� ū �� : " << dres << endl;
	//dres = max(a, x);

	resp = max(ap, bp);
	cout << "�� ���ڿ� �߿��� ū �� : " << resp << endl;

	return 0;
}