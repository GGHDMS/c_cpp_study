#include <cstring>
#include "MyString.h"

ostream & operator<<(ostream &os, const MyString &m);
istream & operator>>(istream &is, MyString &m);

int main() {
	MyString ary[5];
	MyString res;
	int i;
	cout << "5개의 과일이름 입력 : ";
	for (i = 0; i < 5; i++) {
		cin >> ary[i];
	}
	cout << "첫번째와 두번재 중 긴 과일 이름 : ";
	if (ary[0] > ary[1]) {
		cout << ary[0] << endl;
	}
	else {
		cout << ary[1] << endl;
	}
	res = ary[0] + ary[1] + ary[2] + ary[3] + ary[4];
	cout << "모든 문자열 출력: " << res << endl;
	cout << "배열내의 문자열 출력..." << endl;
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