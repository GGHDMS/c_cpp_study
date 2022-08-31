#include <iostream>
using namespace std;

class Base {
	int va;
public:
	Base() { va = 10; };
	void view() { cout << "Base view..." << va << endl; }
};

class Derived : public Base {
	int vb;
public:
	Derived() { vb = 22; }
	void view() { cout << "Derived..." << vb << endl; }
};

int main() {
	Base a;
	Derived b;

	Base *bp = &a;
	Derived *dp = &b;

	bp->view();
	dp->view();

	bp = &b;
	bp->view();

	dp = (Derived*)&a;
	dp->view();

	return 0;
}