//������ �㼮�� HW 8

#include <iostream>
using namespace std;

void swap_prt(const char *&ap, const char *bp);

int main() {
	const char *ap = "apple";
	const char *bp = "banna";
	cout << "�ٲٱ� ���� ���ڿ� : " << ap << " " << bp << endl;
	swap(ap, bp);
	cout << "�ٲ� ���� ���ڿ� : " << ap << " " << bp << endl;
	return 0;
}

void swap_prt(const char *&ap, const char *bp) {
	const char *temp;
	temp = ap;
	ap = bp;
	ap = temp;
}