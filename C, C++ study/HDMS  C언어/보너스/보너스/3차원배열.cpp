//작성자 허석문 3차원 동적배열

#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int ***myAlloc(int, int, int);
void dataInput(int ***, int, int, int);
void dataOutput(int ***, int, int, int);
void myDelete(int ***, int, int);

int main()
{
	int ***ip;
	int side, col, row;
	printf("side 수 입력:");
	scanf("%d", &side);
	printf("row  수 입력:");
	scanf("%d", &row);
	printf("col  수 입력:");
	scanf("%d", &col);
	ip = myAlloc(side, row, col);
	dataInput(ip, side, row, col);
	dataOutput(ip, side, row, col);
	myDelete(ip, side, row);
	return 0;
}

int ***myAlloc(int s, int r, int c)
{
	int ***i;
	int j, k;
	i = (int ***)malloc(sizeof(int ***)*s);
	for (j = 0; j < s; j++)
	{
		i[j] = (int**)malloc(sizeof(int**)*r);
		for (k = 0 ; k < r ; k++)
		{
			i[j][k] = (int*)malloc(sizeof(int*)*c);
		}
	}
	return i;
}

void dataInput(int ***p, int s, int r, int c)
{
	int i, j, k, num = 1;
	for (i = 0; i < s; i++)
	{
		for (j = 0; j < r; j++)
		{
			for (k = 0; k < c; k++)
			{
				p[i][j][k] = num;
				num++;
			}
		}
	}
}

void dataOutput(int ***p, int s, int r, int c)
{
	int i, j, k;
	for (i = 0; i < s; i++)
	{
		printf("-----------------------------------------------------------------------------------\n");
		printf("%d면\n\n", i);
		for (j = 0; j < r; j++)
		{
			for (k = 0; k < c; k++)
			{
				printf("%d행 %d열 : ", j, k);
				printf("%3d ", p[i][j][k]);
			}
			printf("\n\n");
		}
	}
}

void myDelete(int ***p, int s, int r)
{
	int i, j;
	for (i = 0; i < s; i++)
	{
		for (j = 0; j < r; j++)
		{
			free(p[i][j]);
		}
		free(p[i]);
	}
}