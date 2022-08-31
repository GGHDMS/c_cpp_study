#include "SmartArray.h"
#include <iostream>
using namespace std;

int main() {
	int temp;
	int tot = 0;
	int i;
	SmartArray ch(3);
	cout << "철이의 세 과목의 점수 입력 : ";
	for (i = 0; i < 3; i++) {
		cin >> temp;
		if (ch.put(i, temp)) {
			tot += ch.getAry()[i];
		}
	}
	cout << "철이의 총점 : " << tot << endl;
	cout << "철이의 평균 : " << tot / 3.0 << endl;
	cout << ch.getMax() << endl;

	SmartArray me(5);
	tot = 0;
	cout << "메텔의 세 과목의 점수 입력 : ";
	for (i = 0; i < 5; i++) {
		cin >> temp;
		if (me.put(i, temp)) {
			tot += me.getAry()[i];
		}
	}
	cout << "메텔의 총점 : " << tot << endl;
	cout << "메텔의 평균 : " << tot / 5.0 << endl;
	cout << me.getMax() << endl;

	if (ch > me) {
		cout << "철이의 최고점은 메텔보다 크다..." << endl;
	}
	else {
		cout << "철이의 최고점은 메텔보다 크지 않다..." << endl;
	}
	return 0;
}