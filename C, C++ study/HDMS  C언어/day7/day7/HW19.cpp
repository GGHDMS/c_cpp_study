//작성자 허석문 HW19

#include<stdio.h>

int year, num;
void input();
void check();
void output();

int main()
{
	input();
	check();
	output();
	return 0;
}

void input()
{
	printf("년도를 입력하세요:");
	scanf("%d", &year);
}

void check()
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				num = 366;
			}
			else
			{
				num = 365;
			}
		}
		else
		{
			num = 366;
		}
	}
	else
	{
		num = 365;
	}
}

void output()
{
	if (num == 366)
	{
		printf("%d년은 윤년(Leao year)입니다\n", year);

	}
	if (num == 365)
	{
		printf("%d년은 평년(Common year)입니다\n", year);
	}
}


