//�ۼ��� �㼮�� HW22

#include<stdio.h>
int number, i = 1;
int input();

int main()
{
	number = input();
	while (number >= 1)
	{
		printf("*");
		number--;
		if (i % 5 == 0)
		{
			printf("\n");
		}
		i++;
	}
	printf("\n");
	return 0;
}

int input()
{
	int num;
	printf("�������� �Է��ϼ���:");
	scanf("%d", &num);
	return num;
}