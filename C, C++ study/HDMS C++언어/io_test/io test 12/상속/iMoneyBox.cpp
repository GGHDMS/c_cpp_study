#include <iostream>
using namespace std;
#include "iMoneyBox.h"

iMoneyBox::iMoneyBox(const char *np, int m, int l) : MoneyBox(np, m) {
	limit = l;
}

int iMoneyBox::check() {
	int temp;
	temp = int((double)this->sum / this->limit * 100);
	return temp;
}

void iMoneyBox::setLimit(int limit) {
	this->limit = limit;
}

int iMoneyBox::getLimit() {
	return this->limit;
}

void iMoneyBox::save(int m) {
	if (m > limit - getSum()) {
		cout << "저금통의 공간이 부족합니다..." << endl;
		return;
	}
	else {
		MoneyBox::save(m);
	}
}