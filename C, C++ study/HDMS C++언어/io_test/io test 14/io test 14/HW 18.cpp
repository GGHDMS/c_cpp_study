#include "SmartArray.h"
#include <iostream>
using namespace std;

int main() {
	int temp;
	int tot = 0;
	int i;
	SmartArray ch(3);
	cout << "ö���� �� ������ ���� �Է� : ";
	for (i = 0; i < 3; i++) {
		cin >> temp;
		if (ch.put(i, temp)) {
			tot += ch.getAry()[i];
		}
	}
	cout << "ö���� ���� : " << tot << endl;
	cout << "ö���� ��� : " << tot / 3.0 << endl;
	cout << ch.getMax() << endl;

	SmartArray me(5);
	tot = 0;
	cout << "������ �� ������ ���� �Է� : ";
	for (i = 0; i < 5; i++) {
		cin >> temp;
		if (me.put(i, temp)) {
			tot += me.getAry()[i];
		}
	}
	cout << "������ ���� : " << tot << endl;
	cout << "������ ��� : " << tot / 5.0 << endl;
	cout << me.getMax() << endl;

	if (ch > me) {
		cout << "ö���� �ְ����� ���ں��� ũ��..." << endl;
	}
	else {
		cout << "ö���� �ְ����� ���ں��� ũ�� �ʴ�..." << endl;
	}
	return 0;
}