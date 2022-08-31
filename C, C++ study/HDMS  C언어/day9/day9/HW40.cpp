//작성자 허석문 HW40

#include<stdio.h>
int i, j, num;

int main()
{
	printf("출력 라인수를 입력하시오:");
	scanf("%d", &num);
	for (i = 1; i <= num; i++)
	{
		for (j = 1; j <= num * 2 + 1; j++)
		{
			if (j <= i || num * 2 + 1 - (j-1) <= i)
			{
				printf("*");
				if (j == num * 2 + 1)
				{
					printf("\n");
				}
			}
			else
			{
				printf(" ");
			}
		}
	}
	return 0;
}