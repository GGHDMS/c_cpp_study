//수강생 허석문 HW 8

#include <iostream>
using namespace std;

void swap_prt(const char *&ap, const char *bp);

int main() {
	const char *ap = "apple";
	const char *bp = "banna";
	cout << "바꾸기 전의 문자열 : " << ap << " " << bp << endl;
	swap(ap, bp);
	cout << "바꾼 후의 문자열 : " << ap << " " << bp << endl;
	return 0;
}

void swap_prt(const char *&ap, const char *bp) {
	const char *temp;
	temp = ap;
	ap = bp;
	ap = temp;
}