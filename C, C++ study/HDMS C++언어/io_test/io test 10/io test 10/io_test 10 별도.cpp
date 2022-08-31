#include <iostream>
using namespace std;
class Time {
	int hour;
	int min;
public:
	/*explicit*/ Time(double t = 0.0) { // 기본자료형을 Time type으로 자동형 변환 시킴 - explicit 하면 수행 안됨(명시적 호출은 가능)
		this->hour = t;
		this->min = (t - this->hour) * 60;
		cout << "Time(double)..." << endl;
	}
	void show() {
		cout << this->hour << "시간" << this->min << "분" << endl;
	}
};


int main() {
	Time a;
	a.show();
	a = 3.5; // a.operator=(3.5); == a.operator(Time(3.5));
	a.show();
	a = 3;
	a.show(); // a.operator(Time((double)3));

	Time b = 7.7;// 생성자의 암시적 호출
	Time c(7.7); // 생성자의 명시적 호출
	b.show();
	return 0;
}