#include <iostream>
using namespace std;

class Time {
private:
	int hour;
	int min;
public:
	explicit Time(int h = 0, int m = 0); //Time(double t)�� explicit�� �ְ� Time(int, int)�� explicit �� ������ double ���� int������ �޾� ����ȯ
	explicit Time(double t);
//	operator double() const; // double ����ȯ�Լ�
//	operator int() const; // int ����ȯ �Լ�
	double to_double();
	int to_int();
	void show();
};

Time::Time(int h, int m) {
	cout << "int, int ������ ȣ��..." << endl;
	hour = h;
	min = m;
}

Time::Time(double t) {
	cout << "double ������ ȣ��..." << endl;
	hour = int(t);
	min = (int)((t - hour) * 60.0);
}

//Time::operator double()const {
//	cout << "operator double() ȣ��..." << endl;
//	double temp;
//	temp = hour + min / 60.0;
//	return temp;
//}
//
//Time::operator int() const {
//	cout << "operator int() ȣ��..." << endl;
//	return hour;
//}

double Time::to_double() {
	cout << "to_double() ȣ��..." << endl;
	double temp;
	temp = hour + min / 60.0;
	return temp;
}

int Time::to_int() {
	cout << "to_int() ȣ��..." << endl;
	return hour;
}
void Time::show() {
	cout << this->hour << "�ð�" << this->min << "��" << endl;
}

int main() {
	Time a;
	a = Time(3.5);
	a.show();

	double res;

	/*res = 1.0 + a;  ����ȯ �Լ��� �������̸� ȣ���� ��ȣ�ϴ� 
	cout << res << endl;
*/
	res = 1.0 + a.to_int();
	cout << res << endl;

	res = 1.0 + a.to_double(); // ����ȯ �Լ��� �������̸� ȣ���� ��ȣ�ϴ� 
	cout << res << endl;

	//istream myin;
	ostream &myout = cout;
	myout << "HSM" << endl;
	return 0;
}