// �㼮�� HW6

#include <iostream>
using namespace std;

int my_strlen(char *, char ch = '\0');

int main() {
	char str[50];
	char ch;
	int len;
	cout << "���ڿ� �Է� : ";
	cin >> str;
	len = my_strlen(str);
	cout << "���ڿ��� ���� : " << len << endl;
	cout << "���� �Է� : ";
	cin >> ch;
	len = my_strlen(str, ch);
	cout << ch << " ���� ������ ���� : " << len << endl;
}

int my_strlen(char *str, char ch) {
	int len = 0;

	while (str[len] != '\0') {
		if (str[len] == ch) {
			break;
		}
		len++;
	}
	return len;
}