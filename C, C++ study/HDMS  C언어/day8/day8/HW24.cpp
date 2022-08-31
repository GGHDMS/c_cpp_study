//작성자 허석문 HW24

#include<stdio.h>

int deep, day;
int input();
int calc(int);
void output(int, int);

int main()
{
	deep = input();
	day = calc(deep);
	output(deep, day);
	return 0;
}

int input()
{
	int m;
	printf("우물의 깊이를 입력하시오(cm단위):");
	scanf("%d", &m);
	return m;
}

int calc(int m)
{
	int i = 0;
	int calc_deep;
	calc_deep = m;
	while (1)
	{
		if (m == 0) { break; }
		calc_deep -= 50;
		i++;
		if (calc_deep <= 0) { break; }
		calc_deep += 20;
	}
	return i;
}

void output(int m, int i)
{
	printf("우물높이  %dcm : %d일\n", m, i);
}