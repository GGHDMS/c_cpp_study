#include <iostream>
using namespace std;

#define SQUARE(x) x*x;
inline int square(int x) { return x * x; }

int main() {
	int ires;
	ires = square(3 + 4);
	cout << "inline 함수를 이용한 3+4의 거듭제곱 :" << ires << endl;

	ires = SQUARE(3 + 4);
	cout << "매크로 함수를 이용한 3+4의 거듭제곱 :" << ires << endl;
}