#include <stdio.h>

int main() {

	char num;

	for (num = 0; num <= 127; num++) {
		if (num == -128) {
			break;
		}
		if (num % 16 == 0) {
			printf("--------------------------\n");
			printf("10진수   16진수    문자\n");
			printf("--------------------------\n");
		}
		printf("%5d", num);
		printf("%8x", num);
		printf("%9c", num);
		printf("\n");
	}
	return 0;
}