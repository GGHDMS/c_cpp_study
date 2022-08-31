#include <iostream>
using namespace std;
#include <cstring>

class MoneyBox {
private:
	char *name;
	int sum;
public:
	MoneyBox(const char *np = "아무개", int m = 0);
	MoneyBox(const MoneyBox &br);
	~MoneyBox();
	MoneyBox &operator=(const MoneyBox &br);
	void save(int m);
	void use(int m);
	void prn();
};

MoneyBox::MoneyBox(const char *np, int m) {
	name = new char[strlen(np) + 1];
	strcpy(name, np);
	sum = m;
	cout << "overloaded cons..." << endl;
}

MoneyBox::MoneyBox(const MoneyBox &br) {
	name = new char[strlen(br.name) + 1];
	strcpy(name, br.name);
	sum = br.sum;
	cout << "copy cons..." << endl;
}

MoneyBox::~MoneyBox() {
	delete[]name;
}

MoneyBox &MoneyBox::operator=(const MoneyBox &br) {
	if (this == &br)return *this;
	delete[]name;
	name = new char[strlen(br.name) + 1];
	strcpy(name, br.name);
	sum = br.sum;
	cout << "operator cons..." << endl;
	return *this;
}

void MoneyBox::save(int m) {
	sum += m;
}

void MoneyBox::use(int m) {
	sum -= m;
}

void MoneyBox::prn() {
	cout << "이름 : " << name << endl;
	cout << "잔액 : " << sum << endl;
}

int main() {
	MoneyBox a("철이", 100), b("메텔", 500), temp;
	a.prn();
	b.prn();
	/*temp = a;
	a = b;
	b = temp;*/

	temp.operator=(a);
	a.operator=(b);
	b.operator=(temp);

	a.prn();
	b.prn();

	a = b = temp;
	a = a;

	return 0;
}





