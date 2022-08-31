#include "matrix.h"


int main() {
	matrix a(2, 3);
	a.print();
	a.input_matrix();
	a.print();
	a.set(1, 2, 20);
	a.print();
	cout << a.get(1, 3) << endl;
	cout << a.get(2, 1) << endl << endl;
	a.resize(4, 3);
	a.input_matrix();
	a.print();
	return 0
		;
}