// 작성자 허석문 HW20

#include<stdio.h>

int time, g_pay, tot_pay, taxes;
void input();
void pay();
void tax();
void output();

int main()
{
	input();
	pay();
	tax();
	output();
	return 0;
}

void input()
{
	printf("1주일간의 근무시간을 입력하시오:");
	scanf("%d", &time);
}

void pay()
{
	if (time <= 40) { g_pay = 3000 * time;}
	else { g_pay = 40 * 3000 + (int)((time - 40) * 3000 * 1.5);}
}

void tax()
{
	if (g_pay <= 100000)
	{
		taxes = (int)(g_pay * 0.15);
		tot_pay = g_pay - taxes;
	}
	else
	{
		taxes = (int)(100000 * 0.15) + (int)((g_pay - 100000)*0.25);
		tot_pay = g_pay - taxes;
	}
}

void output()
{
	printf("총수입:%d원\n", g_pay);
	printf("세  금:%d원\n", taxes);
	printf("실수입:%d원\n", tot_pay);
}