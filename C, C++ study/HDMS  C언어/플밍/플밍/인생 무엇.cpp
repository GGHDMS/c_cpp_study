#include <iostream>
using namespace std;

#define SQUARE(x) x*x;
inline int square(int x) { return x * x; }

int main() {
	int ires;
	ires = square(3 + 4);
	cout << "inline �Լ��� �̿��� 3+4�� �ŵ����� :" << ires << endl;

	ires = SQUARE(3 + 4);
	cout << "��ũ�� �Լ��� �̿��� 3+4�� �ŵ����� :" << ires << endl;
}