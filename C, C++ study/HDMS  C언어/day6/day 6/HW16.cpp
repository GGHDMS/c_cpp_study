//�ۼ��� �㼮�� HW16

#include<stdio.h>

int num, fee;
int input();
int calc(int);
void output(int);

int main()
{ 
	num = input();
	calc(num);
	output(fee);
	return 0;
}

int input()
{
	printf("������ �Է��ϼ�����:");
	scanf("%d", &num);
	return num;
}

int calc(int num)
{
	if (num <= 5)
	{
		fee = 600;
	}
	else if (num <= 10)
	{
		fee = 800;
	}
	else
	{
		int add;
		add = (int)(num - 9) / 2;
		fee = 800 + add*100;
	}
	return fee;
}

void output(int fee)
{
	printf("��� : %d\n", fee);
}