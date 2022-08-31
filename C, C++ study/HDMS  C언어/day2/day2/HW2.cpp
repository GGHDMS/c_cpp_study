//작성자 허석문 HW2

#include<stdio.h>

int money = 278970;
int m50000, m10000, m5000, m1000, m500, m100, m50, m10;
int number(int, int, int);

int main()
{
	m50000 = money / 50000;
	money = number(money, 50000, m50000);
	m10000 = money / 10000;
	money = number(money, 10000, m10000);
	m5000 = money / 5000;
	money = number(money, 5000, m5000);
	m1000 = money / 1000;
	money = number(money, 1000, m1000);
	m500 = money / 500;
	money = number(money, 500, m500);
	m100 = money / 100;
	money = number(money, 100, m100);
	m50 = money / 50;
	money = number(money, 50, m50);
	m10 = money / 10;
	number(money, 10, m10);
	return 0;
}

int number(int money, int value,int my_number)
{
	printf("%d원권 =>%d\n", value, my_number);
	money = money - value * my_number;
	return money;
}
