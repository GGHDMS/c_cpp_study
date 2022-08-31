#include <iostream>
using namespace std;

void prn(const char *);
void prn(const char *, int);
void prn(char, int);
void prn(int, int);

int main() {
	char str[10] = "str";

	prn(str);
	prn("Moon");
	prn("Gogumi", 3);
	prn('#', 7);
	prn(65, 7);

	return 0;
}

void prn(const char *p) {
	cout << p << endl;
}

void prn(const char *p, int rc) {
	int i;
	for (i = 0; i < rc; i++) {
		cout << p << endl;
	}
}
void prn(char ch, int rc) {
	int i;
	for (i = 0; i < rc; i++) {
		cout << ch;
	}
	cout << endl;
}

void prn(int n, int num) {
	int i;
	for (i = 0; i < num; i++) {
		cout << n << ' ';
	}
	cout << endl;
}