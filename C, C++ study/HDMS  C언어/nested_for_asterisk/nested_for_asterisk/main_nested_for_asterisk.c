#include <stdio.h>

int main() {

	int i, j, n = 5;

	for (i = 1; i <=5; i++) {
		for (j = 5; j >= 1; j--) {
			if (i <= j) {
				printf("*");
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("---------------------------------\n");
	printf("\n");


	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= 5; j++) {
			if (i >= j) {
				printf("*");
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("---------------------------------\n");
	printf("\n");

	for (i = 5; i >= 1; i--) {
		for (j = 1; j <= 5; j++) {
			if (i > j) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("---------------------------------\n");
	printf("\n");

	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= 5; j++) {
			if (i <= j) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("---------------------------------\n");
	printf("\n");

	for (i = 0; i <= 4; i++) {
		for (j = 1; j <= 9; j++) {
			if (n-i <= j && j <= n+i) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("---------------------------------\n");
	printf("\n");

	for (i = 4; i >=0; i--) {
		for (j = 1; j <= 9; j++) {
			if (n - i <= j && j <= n + i) {
				printf("*");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("---------------------------------\n");
	printf("\n");

	for (i = 5; i >=1; i--) {
		for (j = 1; j <= 5; j++) {
			if (i == j) {
				printf(" ");
			}
			else {
				printf("*");
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("---------------------------------\n");
	printf("\n");
	return 0;
}