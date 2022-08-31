//작성자 허석문 HW42

#include<stdio.h>

int main()
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 2; j <= 5; j++)
		{
			printf("%d * %d = %d\t", j, i, j*i);
			if(j==5){printf("\n"); }
		}
	}
	printf("\n\n");

	for (i = 1; i <= 9; i++)
	{
		for (j = 6; j <= 9; j++)
		{
			printf("%d * %d = %d\t", j, i, j*i);
			if (j == 9) { printf("\n"); }
		}
	}
	printf("\n\n");

	int k;
	for (i=2; i<=6; i+=4)
	{
		for (j = 1; j <= 9; j++)
		{
			for (k = i; k <=i+3; k++)
			{
				printf("%d * %d = %d\t", k, j, j*k);
				if (k == 5 || k == 9) { printf("\n"); }
			}
		}
		printf("\n\n");
	}
	return 0;
}