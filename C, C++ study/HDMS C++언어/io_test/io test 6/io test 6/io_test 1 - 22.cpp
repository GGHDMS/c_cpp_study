#include <iostream>
using namespace std;

//int &func();
//
//int main() {
//	int num = 7;
//	num = func();
//	cout << num << endl;
//	return 0;
//}
//
//int &func() {
//	int a = 10;
//	return a;
//}

//int &sub();
//
//int main() {
//	sub()++;
//	sub();
//	return 0;
//}
//int &sub() {
//	static int n = 10;
//	cout << "n = " << n << endl;
//	return n;
//}

struct Score {
	int kor, eng, mat;
	double avg;
};

void input(Score &r);
Score &average(Score &r);

int main() {
	Score s;

	input(s);
	cout << "��� ���� : ";
	cout << average(s).avg << endl;

	return 0;
}

void input(Score &r) {
	cout << "�� ������ ���� �Է� : ";
	cin >> r.kor >> r.eng >> r.mat;
}

Score &average(Score &r) {
	int tot;
	tot = r.kor + r.eng + r.mat;
	r.avg = tot / 3.0;

	return r;
}