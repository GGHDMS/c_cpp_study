//작성자 허석문 HW6

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
	printf("화씨 온도를 입력하세요:");
	scanf("%d", &f);
	return f;
}

void output(int F)
{
	double C = 5.0 / 9 * (F - 32);
	printf("섭씨 온도는 %.2lf도 입니다", C);
}