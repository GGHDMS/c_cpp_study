// �ۼ��� �㼮�� HW5

#include<stdio.h>

int use;
double fee;
int input();
double calc(int);
void output(double);

int main()
{
	use =input();
	fee = calc(use);
	output(fee);
	return 0;
}

int input()
{
	int amount;
	printf("���� ��뷮�� �Է��ϼ���:");
	scanf("%d", &amount);
	return amount;
}

double calc(int my_money)
{
	double total_money;
	double tax;
	double final_money;
	total_money = 660 + 88.5 * my_money;
	tax = total_money * 0.09;
	final_money = total_money + tax;
	return final_money;
}

void output(double fee)
{
	printf("���� ��� ����� %lf �� �Դϴ�.\n", fee);
}