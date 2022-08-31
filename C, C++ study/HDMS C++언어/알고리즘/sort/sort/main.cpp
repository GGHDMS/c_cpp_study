#pragma warning(disable:4996)

#include <iostream>
using namespace std;
#include "quick.h"
#include "insort.h"

int main() {
	char ch[5][20] = { "adfasdfasf", "jnvcoa", "daffvad", "fadfivjc", "cjbvo"};
	char** a;
	a = new char*[5];
	for (int i = 0; i < 5; i++) {
		a[i] = new char[strlen(ch[i])+1];
		strcpy(a[i], ch[i]);
	}
	//quick_sort(a, 0, 4);
	insertionSort(a, 0, 4);
	for (int i = 0; i < 5; i++) {
		cout << a[i] << endl;
	}
	return 0;
}
