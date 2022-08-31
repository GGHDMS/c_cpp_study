//작성자 허석문 HW56

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int random(int);
void input(int(*)[5]);
void calc(int(*)[5], int *, int *, int *);
void output(int(*)[5]);
int num[5][5];
int sum1 = 0, sum2 = 0, sum3 = 0;

int main()
{
	srand((unsigned int)time(NULL));
	input(num);
	calc(num, &sum1, &sum2, &sum3);
	output(num);
	return 0;
}

void input(int(*num)[5])
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			num[i][j] = random(20) + 1;
		}
	}
}

void calc(int (*num)[5], int *sum1, int *sum2, int *sum3)
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (j > i) { *sum2 += num[i][j]; }
			else if (j < i) { *sum3 += num[i][j]; }
			else { *sum1 += num[i][j]; }
		}
	}
}

void output(int(*num)[5])
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		printf("%d번 행 ;", i);
		for (j = 0; j < 5; j++)
		{
			printf("%3d", num[i][j]);
		}
		printf("\n");
	}
	printf("sum1 = %d\n", sum1);
	printf("sum2 = %d\n", sum2);
	printf("sum3 = %d\n", sum3);
}

int random(int n)
{
	int res;
	res = rand() % n;
	return res;
}
