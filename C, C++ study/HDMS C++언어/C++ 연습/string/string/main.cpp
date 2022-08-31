#include "String.h"

int main() {
	String a("Hello"), b = "World";
	cout << a << b << endl;
	String c = a + b;
	cout << c << endl;
	cout << "Size: " << a.size() << endl;
	a[1] = 'i';
	cout << a << endl;
	String d = "Hillo";
	cout << (a == b) << endl;
	a = "Second";
	cout << a << endl;
	cout << (a == "Second") << endl;
	cout << (a == "First") << endl;
	cin >> b;
	cout << b << endl;;
	return 0;
}