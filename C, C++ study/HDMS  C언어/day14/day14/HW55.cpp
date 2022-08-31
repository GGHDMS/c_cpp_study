//작성자 허석문 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int num[3][4];
int random(int);
void input(int(*)[4]);
void output(int(*)[4]);

int main()
{
	srand((unsigned int)time(NULL));
	input(num);
	output(num);
	return 0;
}

void input(int(*num)[4])
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			num[i][j] = random(10) + 1;
		}
	}
}

int random(int n)
{
	int res;
	res = rand() % n;
	return res;
}

void output(int(*num)[4])
{
	int i, j, sum;
	for (i = 0; i < 3; i++)
	{
		sum = 0;
		printf("%d행    :", i);
		for (j = 0; j < 4; j++)
		{
			printf("%3d", num[i][j]);
			sum += num[i][j];
		}
		printf("%5d행의 합 : %d\n", i, sum);
	}
	printf("열의 합:");
	for (i = 0; i < 4; i++)
	{
		sum = 0;
		for (j = 0; j < 3; j++)
		{
			sum += num[j][i];
		}
		printf("%3d", sum);
	}
	printf("\n");
}