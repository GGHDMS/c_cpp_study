//작성자 허석문 HW46

#include<stdio.h>
int year,month, day, num, sum;
int calc_month[12] = { 31 , 28 , 31, 30, 31, 30, 31, 31, 30 , 31, 30, 31 };
char str[7][4] = { {"일"}, {"월"}, {"화"}, {"수"}, {"목"}, {"금"}, {"토"} };
void input(int *, int *, int *);
int ocheck(int *, int*, int*);
int want(int *, int*, int*);
void output(int *, int *, int*, int);
void check(int, int *);

int main()
{
	input(&year, &month, &day);
	sum = want(&year, &month, &day);
	output(&year, &month, &day, sum);
	return 0;
}

void input(int *year, int *month, int *day)
{
	int res;
	while (1)
	{
		printf("년 월 일을 입력하시오 :");
		res = scanf("%d %d %d", year, month, day);
		if (res == 3 && getchar() == '\n')
		{
			if (ocheck(year, month, day) == 0) { break; };
		}
		else
		{
			while (getchar() != '\n')
			{
				;
			}
		}
	}

}


int ocheck(int *year, int *month, int *day)
{
	check(*year, &num);
	int i = -1;
	if (num == 366)
	{
		if (*year >= 1900 && *month == 2 && 0< *day && *day <= 29)
		{
			i = 0;
		}
		else if (*year >= 1900 && 0 < *month && *month < 13 && 0 < *day && *day <= calc_month[*month - 1])
		{
			i = 0;
		}
		else
		{
			;
		}
	}
	else
	{
		if (*year >= 1900 && 0 < *month && *month < 13 && 0 < *day && *day <= calc_month[*month - 1])
		{
			i = 0;
		}
	}
	return i;
}

int want(int *year, int *month, int *day)
{
	int sum = 0, num;
	int i;
	for (i = 1900; i < *year; i++)
	{
		check(i, &num);
		if (num == 366) { sum += 366; }
		else { sum += 365; }
	}
	for (i = 1; i < *month; i++)
	{
		check(*year, &num);
		if (num == 366)
		{
			if (i == 2)
			{
				sum += 29;
			}
			else
			{
				sum += calc_month[i-1];
			}
		}
		else
		{
			sum += calc_month[i-1];
		}
	}
	sum += *day;
	return sum;
}

void output(int *year, int *month, int *day, int sum)
{
	int num;
	num = sum % 7;
	printf("%d년 %d월 %d일은 %s요일입니다\n", *year, *month, *day, str[num]);
}

void check(int year, int *num)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				*num = 366;
			}
			else
			{
				*num = 365;
			}
		}
		else
		{
			*num = 366;
		}
	}
	else
	{
		*num = 365;
	}
}


