//작성자 허석문 HW39

#include<stdio.h>

int main()
{
	int i, j;
	for (i = 0; i<=9; i++)
		for (j = 0; j <= 90; j += 10)
		{
			printf("%4d", i + j);
			if (j == 90)
			{
				printf("\n");
			}
		}
	return 0;
}