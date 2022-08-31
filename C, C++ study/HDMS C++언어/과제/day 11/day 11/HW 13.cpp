//수강생 허석문 HW 13

#include <iostream>
using namespace std;

class Time {
private:
	int hour;
	int min;
	double time;
	static int mode;
	enum {integer, real};
public:
	Time();
	Time(int, int);
	Time(double);
	Time(const Time &tr);
	Time plus(const Time &tr);
	int getHour();
	void setHour(int);
	void setMin(int);
	int getMin();
	friend ostream &operator <<(ostream &os, const Time &br);
	static void mode_change();
};

int Time::mode = 0;

Time::Time() {
	hour = 0;
	min = 0;
	time = 0.0;
}
Time::Time(int h, int m) {
	if (h < 0) {
		h = 0;
		time = 0;
	}
	else {
		hour = h;
		time = h;
	}
	if (m < 0) {
		min = 0;
	}
	else {
		min = m % 60;
		hour += m / 60;
		time += m / 60.0;
	}
}
Time::Time(double t) {
	if (t < 0) {
		hour = min = 0;
		time = 0.0;
	}
	else {
		time = t;
		hour = t / 1;
		min = (t - hour) * 60;
	}
}
Time::Time(const Time &tr) {
	hour = tr.hour;
	min = tr.min;
	time = tr.time;

}
Time Time::plus(const Time &tr) {
	return Time(time + tr.time);
}
int Time::getHour() {
	return hour;
}
void Time::setHour(int h) {
	if (h < 0) {
		time = time - hour;
		hour = 0;
	}
	else {
		time = time - hour + h;
		hour = h;
	}
}
void Time::setMin(int m) {
	if (m < 0) {
		min = 0;
		time = (int)time;
	}
	else{
		hour += m / 60;
		min = m % 60;
		time = hour + min / 60.0;
	}
}
int Time::getMin() {
	return min;
}
ostream &operator <<(ostream &os, const Time &br) {
	if (br.mode == br.integer) {
		cout << br.hour << "시간 " << br.min << "분";
	}
	else {
		cout << br.time << "시간";
	}
	return os;
}
void Time::mode_change() {
	if (mode == integer) {
		mode = real;
	}
	else {
		mode = integer;
	}
}


int main() {
	Time a(3, 21);
	Time b(2.7);
	Time c = a.plus(b);
	cout << "기본 출력 형태(시간, 분)..." << endl;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	Time::mode_change();
	cout << "출력모드를 바꾼 후..." << endl;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	return 0;
}