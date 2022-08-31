#include <stdio.h>

int main() {

	int A[5][5] = { 0, };
	int i, j, num = 1;
	printf(" 巩力 1\n");
	i = 0, j = 0, num = 1;
	while (i<5)
	{
		A[i][j] = num;
		num++;
		j++;
		if (j % 5 == 0) {
			i++;
			j = 0;
		}
	}

	i = 0, j = 0, num = 1;
	while (i<5)
	{
		printf("%-6d", A[i][j]);
		j++;
		if (j % 5 == 0) {
			i++;
			j = 0;
			printf("\n");
		}
	}
	printf("\n");

	printf(" 巩力 2\n");

	i = 0, j = 0, num = 1;
	while (j<5)
	{
		A[i][j] = num;
		num++;
		i++;
		if (i % 5 == 0) {
			j++;
			i = 0;
		}
	}

	i = 0, j = 0;
	while (i<5)
	{
		printf("%-6d", A[i][j]);
		j++;
		if (j % 5 == 0) {
			i++;
			j = 0;
			printf("\n");
		}
	}
	printf("\n");
	printf("巩力 3\n");

	i = 0, j = 0, num = 1;
	do
	{
		A[i][j] = num;
		num++;
		if ((j+1)%(i+1) == 0){
			i++;
			j = 0;
		}
		else {
			j++;
		}
	} while (i != 5);

	i = 0, j = 0;
	do
	{
		printf("%-6d", A[i][j]);
		if ((j+1)%(i+1) == 0) {
			printf("\n");
			i++;
			j = 0;
		}
		else {
			j++;
		}
	} while (i != 5);
	printf("\n");
	printf("巩力 4\n");

	i = 0, j = 4, num = 1;
	do
	{
		A[i][j] = num;
		num++;
		if (j % 4 == 0) {
			i++;
			j = 4 - i;
		}
		else {
			j++;
		}
	} while (i != 5);

	i = 0, j = 4;
	do
	{
		if (i != 4 && (i+j+1)% 5 == 0){
			printf("%*c", j * 6,' ');
			printf("%-6d", A[i][j]);
		}
		else {
			printf("%-6d", A[i][j]);
		}
		if (j == 4) {
			i++;
			j = 4 - i;
			printf("\n");
		}
		else {
			j++;
		}
	} while (i != 5);
	
	return 0;
}