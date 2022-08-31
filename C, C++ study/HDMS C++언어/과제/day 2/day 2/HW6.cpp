// 허석문 HW6

#include <iostream>
using namespace std;

int my_strlen(char *, char ch = '\0');

int main() {
	char str[50];
	char ch;
	int len;
	cout << "문자열 입력 : ";
	cin >> str;
	len = my_strlen(str);
	cout << "문자열의 길이 : " << len << endl;
	cout << "문자 입력 : ";
	cin >> ch;
	len = my_strlen(str, ch);
	cout << ch << " 이전 까지의 길이 : " << len << endl;
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