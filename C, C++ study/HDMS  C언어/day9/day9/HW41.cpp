//�ۼ��� �㼮�� HW41

#include<stdio.h>

int i, j;
char let;

int main()
{
	printf("������ �빮�� �Է�('A'~'Z'):");
	scanf("%c", &let);
	if ('A' <= let && let <= 'Z')
	{
		for (i = let; i >= 'A'; i--)
		{
			for (j = let; j >= i; j--)
			{
				printf("%c", j);
				if (j == i)
				{
					printf("\n");
				}
			}
		}
	}
	return 0;
}
