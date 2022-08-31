#include<iostream>
using namespace std;

class Base{
private:
	int a;
public:
	Base(int n=10) { 
		a=n;
		cout << "Base 생성자 수행중" << endl;
	}  // 생성자
	virtual void view() { cout << "Base(" << a << ')' << endl; } // 출력 멤버함수
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
	BaseA(int n, int m) : Base(n), ba(m) {cout << "BaseA생성자 수행중" << endl; } 
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
	BaseB(int n, int m) : Base(n), bb(m) {cout << "BaseB생성자 수행중" << endl; }  
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
	{cout << "Derived 생성자 수행중" << endl;  }
	void view() {
		Base::view();
		BaseA::viewA();
		BaseB::viewB();
		cout << "Derived(" << dd << ')' << endl;
	}
};  // 다중상속

int main()
{
	BaseA a(10, 20);
	BaseB b(30, 40);
	cout << "BaseA의 객체 출력..." << endl;
	a.view();
	cout << "BaseB의 객체 출력..." << endl;
	b.view();
	Derived d(77, 20, 30, 40);
	cout << "Derived의 객체 출력..." << endl;
	d.view();
	return 0;
}
