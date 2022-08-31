#include <iostream>
using namespace std;

class Base {
public:
	void func(char ch) { cout << "Base(char):" << ch << endl; }
	void func(int in) { cout << "Base(int):" << in << endl; }
};

class Derived : public Base{};

class rDerived : public Base{
public:
	void func(char ch) {
		cout << "rDerived(char):" << ch << endl;
	}
	/*void func(int in) {
		cout << "rderived(int):" << in << endl;
	}
	void func(double db) {
		cout << "rderived(doube):" << db << endl;
	}*/
};

int main() {
	Derived a;
	cout << "재정의 없는 파생클래스..." << endl;
	a.func('A');
	a.func(10);

	rDerived b;
	cout << "재정의한 파생클래스..." << endl;
	b.func('B');
	b.func(97); // no
	b.Base::func(97); // ok
	b.func(100.5); // func(int in)을 overriding 하면 호출이 모호하기 때문에 func(double db)도 만들어야 한다

	return 0;
}