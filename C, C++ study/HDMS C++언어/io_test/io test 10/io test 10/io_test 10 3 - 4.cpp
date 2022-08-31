#include <iostream>
using namespace std;

class Time {
private:
	int hour;
	int min;
public:
	Time(int h = 0, int m = 0);
	Time operator*(int);
	//void operator<<(ostream &os) const;
	//void operator>>(istream &is);
	friend ostream & operator<<(ostream &, const Time &);
	friend istream & operator>>(istream &, Time &);
};

Time::Time(int h, int m) {
	hour = h;
	min = m;
}

Time Time::operator*(int n) {
	int h, m;
	h = hour * n;
	m = min * n;
	if (m >= 60) {
		h += m / 60;
		m = m % 60;
	}
	return Time(h, m);
}

//void Time::operator<<(ostream &os) const{
//	cout << "Time::oprator<<()..." << endl;
//	os << hour << "시간" << min << "분" << endl;
//}
//
//void Time::operator>>(istream &is) {
//	cout << "Time::oprator>>()..." << endl;
//	is >> hour >> min;
//}

Time operator*(int n, Time&a);
ostream &operator<<(ostream &os, const Time &br);
istream &operator>>(istream &is, Time &br);

int main() {
	Time a, b;
	cout << "시간과 분을 입력하세요 :";
	cin >> a;
	b = 3 * a;
	cout << a << b;
	return 0;
}

Time operator*(int n, Time &a) {
	return a * n;
}

ostream &operator<<(ostream &os, const Time &br) { // Time &br에서 & 선택 나머지 필수
	cout << "extern oprator<<()..." << endl;
	os << br.hour << "시간 " << br.min << "분" << endl; // const Time &br은 const Member 함수만 부를수 있다.
	return os;
}
istream &operator>>(istream &is, Time &br) { // 모든 & 필수
	cout << "extern oprator>>()..." << endl;
	is >> br.hour >> br.min;
	return is;
}
