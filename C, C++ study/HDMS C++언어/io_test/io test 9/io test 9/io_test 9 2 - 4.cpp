#include <iostream>
using namespace std;

class Letter {
private:
	const char ch; // �ݷ� �ʱ�ȭ �ʼ�
	int num;
public:
	Letter(char h = '*', int n = 0);
	void n_prn();
	void c_prn() const;
	void show();
};

Letter::Letter(char c, int n) :ch(c) { // ch(c) �ʼ�
	num = n;
}

void Letter::n_prn() {
	//ch = '@';
	num += 10;
	cout << "const�� �ƴ� ����Լ� ȣ��..." << endl;
	show();
}

void Letter::c_prn()const {
	//num += 10;
	cout << "const ����Լ� ȣ��..." << endl;
	//show();
}

void Letter::show() {
	int i;
	for (i = 0; i < num; i++) {
		cout << ch;
	}
	cout << endl;
}

int main() {
	Letter a('@', 5);
	const Letter b('#', 3);

	a.c_prn();
	a.c_prn();
	//b.n_prn();
	b.c_prn();

	return 0;
}



