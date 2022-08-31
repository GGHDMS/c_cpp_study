#include<stdio.h>

void shell(int *, int);

int main() {
	int ary[] = { 156,154123,11,1235,1846,123518,1,156,12,133 };
	int n = sizeof(ary)/sizeof(ary[0]);
	shell(ary, n);
	return 0;
}

void shell(int *ary, int n) {
	int k = n;
	k = k / 3 + 1;
	do
	{
		for (int i = 0; i < n / 2; i++) {
			if (ary[i] > ary[i + k]) {
				int num;
				num = ary[i + k];
				ary[i + k] = ary[i];
				ary[i] = num;
			}
		}
	} while ((k = k / 3 + 1) != 1);

	for (k = 0; k < n; k++) {
		printf("%d ", ary[k]);
	}
}