//�ۼ��� �㼮�� HW49

#include<stdio.h>

int num;
void swap(int *);
int my_num[] = { 1, 2, 3, 4, 5};

int main()
{
	int i, calc;
	num = sizeof(my_num) / sizeof(my_num[0]);
	printf("ó�� �迭�� ����� ��:");
	for (i = 0; i < num; i++)
	{
		printf(" %2d", my_num[i]);
	}
	printf("\n");
	printf("�ٲ� �迭�� ����� ��:");
	swap(my_num);
	for (i = 0; i < num; i++)
	{
		printf(" %2d", my_num[i]);
	}
	printf("\n");
	return 0;
}

void swap(int *my_num)
{
	int i, calc;
	for (i = 0; i < num / 2; i++)
	{
		calc = my_num[i];
		my_num[i] = my_num[num - 1 - i];
		my_num[num - 1 - i] = calc;
	}
}