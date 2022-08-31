// 작성자 허석문 HW5

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
	printf("전기 사용량을 입력하세요:");
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
	printf("전기 사용 요금은 %lf 원 입니다.\n", fee);
}