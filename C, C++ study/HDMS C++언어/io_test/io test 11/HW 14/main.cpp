#include <cstring>
#include "MyString.h"

ostream & operator<<(ostream &os, const MyString &m);
istream & operator>>(istream &is, MyString &m);

int main() {
	MyString ary[5];
	MyString res;
	int i;
	cout << "5���� �����̸� �Է� : ";
	for (i = 0; i < 5; i++) {
		cin >> ary[i];
	}
	cout << "ù��°�� �ι��� �� �� ���� �̸� : ";
	if (ary[0] > ary[1]) {
		cout << ary[0] << endl;
	}
	else {
		cout << ary[1] << endl;
	}
	res = ary[0] + ary[1] + ary[2] + ary[3] + ary[4];
	cout << "��� ���ڿ� ���: " << res << endl;
	cout << "�迭���� ���ڿ� ���..." << endl;
	for (i = 0; i < 5; i++) {
		cout << ary[i] << endl;
	}
	return 0;
}

ostream & operator<<(ostream &os, const MyString &m) {
	os << m.str << "(" << m.len << ")" << endl;
	return os;
}
istream & operator>>(istream &is, MyString &m) {
	char temp[50];
	is >> temp;
	delete[]m.str;
	m.len = strlen(temp);
	m.str = new char[m.len + 1];
	strcpy(m.str, temp);
	return is;
}