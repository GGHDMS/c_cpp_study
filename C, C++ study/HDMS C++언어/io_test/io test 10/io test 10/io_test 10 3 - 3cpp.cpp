#include <iostream>
using namespace std;

class Time {
private:
	int hour;
	int min;
public:
	explicit Time(int h = 0, int m = 0); //Time(double t)에 explicit가 있고 Time(int, int)에 explicit 가 없으면 double 형도 int형으로 받아 형변환
	explicit Time(double t);
//	operator double() const; // double 형변환함수
//	operator int() const; // int 형변환 함수
	double to_double();
	int to_int();
	void show();
};

Time::Time(int h, int m) {
	cout << "int, int 생성자 호출..." << endl;
	hour = h;
	min = m;
}

Time::Time(double t) {
	cout << "double 생성자 호출..." << endl;
	hour = int(t);
	min = (int)((t - hour) * 60.0);
}

//Time::operator double()const {
//	cout << "operator double() 호출..." << endl;
//	double temp;
//	temp = hour + min / 60.0;
//	return temp;
//}
//
//Time::operator int() const {
//	cout << "operator int() 호출..." << endl;
//	return hour;
//}

double Time::to_double() {
	cout << "to_double() 호출..." << endl;
	double temp;
	temp = hour + min / 60.0;
	return temp;
}

int Time::to_int() {
	cout << "to_int() 호출..." << endl;
	return hour;
}
void Time::show() {
	cout << this->hour << "시간" << this->min << "분" << endl;
}

int main() {
	Time a;
	a = Time(3.5);
	a.show();

	double res;

	/*res = 1.0 + a;  형변환 함수가 여러개이면 호출이 모호하다 
	cout << res << endl;
*/
	res = 1.0 + a.to_int();
	cout << res << endl;

	res = 1.0 + a.to_double(); // 형변환 함수가 여러개이면 호출이 모호하다 
	cout << res << endl;

	//istream myin;
	ostream &myout = cout;
	myout << "HSM" << endl;
	return 0;
}