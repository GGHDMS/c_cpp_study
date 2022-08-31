#include <iostream>
using namespace std;

class Time {
private:
	int hour;
	int min;
public:
	Time(int hour = 0, int m = 0);
	Time operator+(const Time &br);
	Time operator-();
	Time &operator++();
	Time operator++(int);
	Time &operator--();
	Time operator--(int);
	Time operator*(int);
	void show();
};

Time::Time(int h, int m) {
	hour = h;
	min = m;
}

Time Time::operator+(const Time &br) {
	int h, m;
	h = hour + br.hour;
	m = min + br.min;
	if (m >= 60) {
		h += m / 60;
		m = m % 60;
	}
	return Time(h, m);
}

Time Time::operator-() {
	Time temp(-hour, -min);
	return temp;
}

Time &Time::operator++() {
	min++;
	if (min == 60) {
		hour++;
		min = 0;
	}
	return *this;
}

Time Time::operator++(int) {
	Time temp(hour, min);
	min++;
	if (min == 0) {
		hour++;
		min = 0;
	}
	return temp;
}

Time &Time::operator--() {
	min--;
	if (min == -1) {
		hour--;
		min = 59;
	}
	return *this;
}

Time Time::operator--(int) {
	Time temp(hour, min);
	min--;
	if (min == -1) {
		hour--;
		min = 59;
	}
	return temp;
}

void Time::show() {
	cout << hour << "½Ã°£" << min << "ºÐ" << endl;
}

void func(Time &br);

Time Time::operator *(int n) {
	int h, m;
	h = hour * n;
	m = min * n;
	if (m >= 60) {
		h += m / 60;
		m = m % 60;
	}
	return Time(h, m);
}

Time operator*(int n, Time &a) {
	cout << "extern operator+()..." << endl;
	return a * n;
}

int main() {
	Time a(5, 50), b(3, 30), c;
	c = -b + a;
	a.show();
	b.show();
	c.show();

	c = ++a + b;
	a.show();
	b.show();
	c.show();

	c = a + b++;
	a.show();
	b.show();
	c.show();

	func(++a);
	a.show();

	Time res;
	res = --a;
	res.show();
	a.show();
	res = a--;
	res.show();
	a.show();

	Time d(2, 30), e;
	e = 3 * d;
	e.show();
	return 0;
}

void func(Time &br) {
	br++;
}