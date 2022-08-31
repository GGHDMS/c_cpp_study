#include <iostream>
using namespace std;
#include <cstdlib>

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define ARRAY_ITEM_SIZE(a) (sizeof(a[0]))

int compare(const int * one, const int * two) {
	return (*one < *two) ? -1 : 1;
}

int main() {
	int a[] = { 20,50,30,70,40 };
	qsort(a, ARRAY_SIZE(a), ARRAY_ITEM_SIZE(a), reinterpret_cast<int(*)(const void *, const void*)>(compare));
	for (auto value : a) {
		cout << value << ' ';
	}
	cout << endl;
	return 0;
}