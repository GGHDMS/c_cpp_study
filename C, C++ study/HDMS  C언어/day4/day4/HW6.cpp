//�ۼ��� �㼮�� HW6

#include<stdio.h>

int F;
int input();
void output(int);

int main()
{
	F = input();
	output(F);
	return 0;
}

int input()
{
	int f;
	printf("ȭ�� �µ��� �Է��ϼ���:");
	scanf("%d", &f);
	return f;
}

void output(int F)
{
	double C = 5.0 / 9 * (F - 32);
	printf("���� �µ��� %.2lf�� �Դϴ�", C);
}