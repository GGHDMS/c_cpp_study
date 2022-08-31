//수강생 허석문 HW10
#include <iostream>
using namespace std;

class Time {
private:
	int hour;
	int min;
public:
	Time();
	Time(int, int);
	Time(double);
	Time(const Time &tr);
	Time plus(const Time &tr);
	void setHour(int);
	int getHour();
	void setMin(int);
	int getMin();
};

Time::Time() {
	hour = 0;
	min = 0;
}
Time::Time(int hour, int min){
	if (hour < 0) {
		this->hour = 0;
	}
	else {
		this->hour = hour;
	}
	if (min < 0) {
		this->min = 0;
	}
	else {
		this->min = min % 60;
		this->hour += min / 60;
	}
}
Time::Time(double t) {
	int hour, min;
	if (t < 0) {
		hour = 0;
		min = 0;
	}
	else {
		hour = t / 1;
		min = 60 * (t - hour);
	}
	this->hour = hour;
	this->min = min;
}
Time::Time(const Time &tr) {
	this->hour = tr.hour;
	this->min = tr.min;
}
Time Time::plus(const Time &tr) {
	Time t(this->hour + tr.hour, this->min + tr.min);
	return t;
}
void Time::setHour(int hour) {
	if (hour < 0) {
		this->hour = 0;
	}
	else {
		this->hour = hour;
	}

}
int Time::getHour() {
	return hour;
}
void Time::setMin(int min) {
	if (min < 0) {
		this->min = min;
	}
	else {
		this->min = min % 60;
		this->hour += min / 60;
	}
}
int Time::getMin() {
	return min;
}

int main() {
	Time a(3, 20), b;
	cout << a.getHour() << "시간" << a.getMin() << "분" << endl;
	b.setHour(4);
	b.setMin(42);
	cout << b.getHour() << "시간" << b.getMin() << "분" << endl;
	Time res = a.plus(b);
	cout << "두 시간을 더하면 : " << res.getHour() << "시간" << res.getMin() << "분" << endl;
	return 0;
}