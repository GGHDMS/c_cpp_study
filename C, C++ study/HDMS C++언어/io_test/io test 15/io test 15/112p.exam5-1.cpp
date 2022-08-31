#include <iostream>
#include "112p.exam5-1.h"
using namespace std;

int main()
{
	int a = 10, b = 20, ires;
	double x = 2.4, y = 3.5, dres;
	const char *ap = "apple", *bp = "banana", *resp;

	ires = max(a, b);
	cout << "두 정수 중에서 큰 값 : " << ires << endl;
	dres = max(x, y);
	cout << "두 실수 중에서 큰 값 : " << dres << endl;
	//dres = max(a, x);

	resp = max(ap, bp);
	cout << "두 문자열 중에서 큰 값 : " << resp << endl;

	return 0;
}