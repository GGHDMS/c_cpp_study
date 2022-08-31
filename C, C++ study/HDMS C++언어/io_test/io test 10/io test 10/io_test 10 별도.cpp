#include <iostream>
using namespace std;
class Time {
	int hour;
	int min;
public:
	/*explicit*/ Time(double t = 0.0) { // �⺻�ڷ����� Time type���� �ڵ��� ��ȯ ��Ŵ - explicit �ϸ� ���� �ȵ�(����� ȣ���� ����)
		this->hour = t;
		this->min = (t - this->hour) * 60;
		cout << "Time(double)..." << endl;
	}
	void show() {
		cout << this->hour << "�ð�" << this->min << "��" << endl;
	}
};


int main() {
	Time a;
	a.show();
	a = 3.5; // a.operator=(3.5); == a.operator(Time(3.5));
	a.show();
	a = 3;
	a.show(); // a.operator(Time((double)3));

	Time b = 7.7;// �������� �Ͻ��� ȣ��
	Time c(7.7); // �������� ����� ȣ��
	b.show();
	return 0;
}