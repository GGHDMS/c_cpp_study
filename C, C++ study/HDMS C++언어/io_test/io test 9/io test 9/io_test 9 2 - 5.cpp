#include <iostream>
using namespace std;

class Sample {
private:
	int num;
	static int cnt;
public:
	Sample(int n = 0);
	void prn() const;
	static void setNum(int n);
};

int Sample::cnt = 0;

void Sample::setNum(int n) {
	cnt = n;
}

Sample::Sample(int n) {
	num = n;
	cnt++;
}

void Sample::prn() const {
	cout << "num: " << num << ",";
	cout << "cnt: " << cnt << endl;
}

int main() {
	int start;
	
	cout << "���۰��� �Է��Ͻÿ�: ";
	cin >> start;
	Sample::setNum(start);
	Sample a(10), b(20), c(30);
	a.prn();
	b.prn();
	c.prn();
	a.setNum(0); // ��ü ������ ����~ Sample::setNum(0) �� ����
	a.prn();
	b.prn();
	c.prn();

	return 0;
}