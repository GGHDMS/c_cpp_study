#include<iostream>
using namespace std;
#include "iMoneyBox.h"

int main() {
	iMoneyBox a("철이", 100, 2000), b("메텔", 500, 3000);

	a.save(600);
	b.use(100);
	cout << a.getName().getStr() << " " << a.getSum() << " " << a.getLimit() << endl;
	cout << b.getName().getStr() << " " << b.getSum() << " " << b.getLimit() << endl;
	cout << "철이의 저금통 사용량: " << a.check() << '%' << endl;
	cout << "메텔의 저금통 사용량: " << b.check() << '%' << endl;
	return 0;
}