#include<iostream>
using namespace std;

class Base{
private:
	int a;
public:
	Base(int n=10) { 
		a=n;
		cout << "Base ������ ������" << endl;
	}  // ������
	virtual void view() { cout << "Base(" << a << ')' << endl; } // ��� ����Լ�
	virtual ~Base() {}
};

class BaseA : virtual public Base {
private:
	int ba;
protected:
	void viewA() {
		cout << "BaseA(" << ba << ')' << endl;
	}
public:
	BaseA(int n, int m) : Base(n), ba(m) {cout << "BaseA������ ������" << endl; } 
	void view() {
		Base::view();
		viewA();
	}
};

class BaseB : virtual public Base {
private:
	int bb;
protected:
	void viewB() {
		cout << "BaseB(" << bb << ')' << endl;
	}
public:
	BaseB(int n, int m) : Base(n), bb(m) {cout << "BaseB������ ������" << endl; }  
	void view() {
		Base::view();
		viewB();
	}
};

class Derived : public BaseA, public BaseB 
{
private:
	int dd;
public : 
	Derived(int n, int ma, int mb, int l) : Base(n), BaseA(n, ma), BaseB(n, mb), dd(l)
	{cout << "Derived ������ ������" << endl;  }
	void view() {
		Base::view();
		BaseA::viewA();
		BaseB::viewB();
		cout << "Derived(" << dd << ')' << endl;
	}
};  // ���߻��

int main()
{
	BaseA a(10, 20);
	BaseB b(30, 40);
	cout << "BaseA�� ��ü ���..." << endl;
	a.view();
	cout << "BaseB�� ��ü ���..." << endl;
	b.view();
	Derived d(77, 20, 30, 40);
	cout << "Derived�� ��ü ���..." << endl;
	d.view();
	return 0;
}
