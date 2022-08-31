#include <iostream>
using namespace std;
class Obj
{
public:
	void Foo(void) { cout << __FUNCTION__ << endl; }
};

int main() {
	Obj o;
	Obj *p;
	p = &o; 

	void (Obj::*pmFunc)(void);
	pmFunc = &Obj::Foo;

	(o.*pmFunc)();
	(p->*pmFunc)();

	return 0;
}