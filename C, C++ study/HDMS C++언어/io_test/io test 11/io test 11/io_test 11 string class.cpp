#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	cout << boolalpha;
	cout << a.empty();
	a = "Dream";
	cout << a << " " << a.empty() << endl;
	cout << a.at(3) << endl;
	cout << a[3];
	cout << a.find("ea") << endl;
	cout << a.find("xx") << endl; // 못찾았을 경우 -1리턴
	cout << (unsigned int)-1 << endl;
	string res, b("Hope");

	res = a + b;
	cout << res << res.length() << endl;
	res.erase(2, 3);
	cout << res << res.length() << endl;
	return 0;
}