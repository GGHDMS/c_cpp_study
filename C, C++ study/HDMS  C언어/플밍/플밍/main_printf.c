#include<stdio.h>

int main() {

	printf("æ»≥Á«œººø‰?\n");
	printf("100\n");
	printf("%d\n", 100);
	printf("%d %d\n", 10, 20);
	printf("%d\n", 10 + 20);
	printf("%d + %d = %d\n", 10, 20, 10 + 20);
	printf("%x + %x = %x\n", 10, 20, 10 + 20);
	printf("%o + %o = %o\n", 10, 20, 10 + 20);

	printf("%d / %d = %.2lf\n", 100, 200, (double)100 / 200);

	printf("%05d\n", 45);
	printf("%s\n", "Basic_c");
	printf("%10s\n", "Basic_c");
	printf("%-10s\n", "Basic_c");
	return 0;
}