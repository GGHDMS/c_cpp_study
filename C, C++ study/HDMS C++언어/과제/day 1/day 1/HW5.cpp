//HW 5 허석문

#include <iostream>
#include <iomanip>
using namespace std;

void my_flush();

int main() {
	char name[20];
	int k, e, m;
	int tot;
	double average;
	cout << "이름 : ";
	cin.getline(name, 20);
	cout << "세 과목의 점수 : ";
	cin >> k >> e >> m;
	while (cin.fail()) {
		my_flush();
		cout << "다시 입력하세요: ";
		cin >> k >> e >> m;
	}
	cout << '\n';
	cout << "               =========< 성적표 >=========" << endl;
	cout << "==========================================================" << endl;
	cout << setw(9) << "이름" << setw(9) << "국어" << setw(9) << "영어" << setw(9) << "수학" << setw(9) << "총점" << setw(9) << "평균" << endl;
	cout << "==========================================================" << endl;
	tot = k + e + m;
	average = tot / 3.0;
	cout << setw(9) << name << setw(9) << k << setw(9) << e << setw(9) << m << setw(9) << tot << setw(9) << fixed << setprecision(2) << average << endl<< endl;
}

void my_flush() {
	cin.clear();

	while (cin.get() != '\n');
}
