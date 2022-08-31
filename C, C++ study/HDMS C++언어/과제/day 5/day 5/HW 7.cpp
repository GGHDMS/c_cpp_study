//수강생 허석문 HW 7

#include <iostream>
using namespace std;

struct Savings {
	int w500;
	int w100;
	int w50;
	int w10;
};

void init(Savings &s);
void input(int &unit, int &cnt);
void save(Savings &s, int unit, int cnt);
int total(Savings &s);
void myFlush();

int main() {
	Savings s;
	int unit, cnt, tot;

	init(s);
	while (1)
	{
		input(unit, cnt);
		if (cin.fail()) {
			break;
		}
		save(s, unit, cnt);
	}
	tot = total(s);
	cout << "총 저금액 : " << tot << endl;
	return 0;
}

void init(Savings &s) {
	s.w10 = 0;
	s.w100 = 0;
	s.w50 = 0;
	s.w500 = 0;
}

void input(int &unit, int &cnt) {
	while (1) {
		cout << "동전의 금액: ";
		cin >> unit;
		if (cin.fail()) {
			break;
		}
		myFlush();
		if (unit == 10 || unit == 50 || unit == 100 || unit == 500) {
			break;
		}
	}

	while (1){
		if (cin.fail()) {
			break;
		}
		cout << "동전의 개수: ";
		cin >> cnt;
		if (cin.fail()) {
			myFlush();
			continue;
		}
		myFlush();
		if (cnt > 0) {
			break;
		}
	}
}

int total(Savings &s) {
	int sum;
	sum = s.w10 * 10 + s.w100 * 100 + s.w50 * 50 + s.w500 * 500;
	return sum;
}

void save(Savings &s, int unit, int cnt) {
	switch (unit)
	{
	case 10: s.w10 += cnt; break;
	case 50: s.w50 += cnt; break;
	case 100: s.w100 += cnt; break;
	case 500: s.w500 += cnt; break;
	default: break;
	}
}

void myFlush() {
	cin.clear();
	while (cin.get()!='\n')
	{
		;
	}
}

