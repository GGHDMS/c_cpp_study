//HW 5 �㼮��

#include <iostream>
#include <iomanip>
using namespace std;

void my_flush();

int main() {
	char name[20];
	int k, e, m;
	int tot;
	double average;
	cout << "�̸� : ";
	cin.getline(name, 20);
	cout << "�� ������ ���� : ";
	cin >> k >> e >> m;
	while (cin.fail()) {
		my_flush();
		cout << "�ٽ� �Է��ϼ���: ";
		cin >> k >> e >> m;
	}
	cout << '\n';
	cout << "               =========< ����ǥ >=========" << endl;
	cout << "==========================================================" << endl;
	cout << setw(9) << "�̸�" << setw(9) << "����" << setw(9) << "����" << setw(9) << "����" << setw(9) << "����" << setw(9) << "���" << endl;
	cout << "==========================================================" << endl;
	tot = k + e + m;
	average = tot / 3.0;
	cout << setw(9) << name << setw(9) << k << setw(9) << e << setw(9) << m << setw(9) << tot << setw(9) << fixed << setprecision(2) << average << endl<< endl;
}

void my_flush() {
	cin.clear();

	while (cin.get() != '\n');
}
