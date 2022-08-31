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
	cout << "������ ���� �Ļ�Ŭ����..." << endl;
	a.func('A');
	a.func(10);

	rDerived b;
	cout << "�������� �Ļ�Ŭ����..." << endl;
	b.func('B');
	b.func(97); // no
	b.Base::func(97); // ok
	b.func(100.5); // func(int in)�� overriding �ϸ� ȣ���� ��ȣ�ϱ� ������ func(double db)�� ������ �Ѵ�

	return 0;
}