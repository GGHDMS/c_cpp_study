#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include <memory>

class Test {
private:
	char str[80];
public:
	Test(const char *s) { strcpy(str, s); }
	~Test() { cout << str << "객체의 소멸자 호출.." << endl; }
};

int mod1(int x, int y);
int mod2(int x, int y);

int main() {
	int a, b, res;

	cout << "두 정수 입력:";
	cin >> a >> b;
	try {
		res = mod2(a, b);
	}
	catch (const char *s) {
		cout << s << endl;
		exit(1);
	}
	cout << "몫의 두배 : " << res << endl;
	return 0;
}

int mod2(int x, int y) {
	//Test ob1("mod2");
	//Test *p1 = new Test("mod2");
	auto_ptr<Test>ob1(new Test("mod2"));
	int r;
	
	r = 2 * mod1(x, y);
	//delete p1;
	return r;
}

int mod1(int x, int y) {
	////Test ob2("mod1");
	//Test *p2 = new Test("mod2");
	auto_ptr<Test>ob2(new Test("mod1"));
	if (y == 0) {
		throw "0으로 나눌 수 없습니다.";
	}
	//delete p2;
	return x / y;
}