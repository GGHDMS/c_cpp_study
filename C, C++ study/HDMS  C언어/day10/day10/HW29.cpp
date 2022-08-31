//작성자 허석문 HW29

#include<stdio.h>
void inputUint(int *, int *, int *);
int transNumber(int);
void output(int);
void myflush();
int p1, p2, N, tot = 0, calc_p1;

int main()
{
	inputUint(&p1, &p2, &N);
	for (p1; p1 <= p2; p1++)
	{
		int count = 0;
		calc_p1 = p1;
		while (1)
		{
			count++;
			calc_p1 = transNumber(calc_p1);
			if (calc_p1< 10)
			{
				if (count == N)
				{
					printf("%d\n", p1);
					tot++;
					break;
				}
				else { break; }
			}
		}
	}
	output(tot);
	return 0;
}

void inputUint(int *p1, int *p2, int *N)
{
	while (1)
	{
		int res;
		printf("시작 값(p1) :");
		res = scanf("%d", p1);
		if (res != 1 || getchar() !='\n')
		{ 
			myflush(); continue;
		}
		if (*p1 < 100) { continue; }
		printf("끝 값(p2) :");
		res = scanf("%d", p2);
		if (res != 1 || getchar() !='\n')
		{
			myflush(); continue;
		}
		if (*p2 > 10000 || *p1 > * p2) { continue; }
		printf("고집수(N):");
		res = scanf("%d", N);
		if (*N < 1 || 10 < *N) { continue; }
		if (res != 1 && getchar() != '\n') { continue; }
		break;
	}
}

int transNumber(int p1)
{
	int num1, num2, num3, num4, num5;
	if (10 <= p1 && p1 < 100)
	{
		num2 = p1 / 10;
		num1 = p1 - num2 * 10;
		return num2 * num1;
	}
	else if (100 <= p1 && p1 < 1000)
	{
		num3 = (p1 / 100);
		num2 = (p1 - num3 * 100) / 10;
		num1 = (p1 - num3 * 100 - num2 * 10);
		return num3 * num2 * num1;
	}
	else if (1000 <= p1 && p1 < 10000)
	{
		num4 = p1 / 1000;
		num3 = (p1 - num4 * 1000) / 100;
		num2 = (p1 - num4 * 1000 - num3 * 100) / 10;
		num1 = (p1 - num4 * 1000 - num3 * 100 - num2 * 10);
		return num4 * num3* num2* num1;
	}
	else
	{
		num5 = p1 / 10000;
		num4 = (p1 - num5 * 10000) / 1000;
		num3 = (p1 - num5 * 10000 - num4 * 1000) / 100;
		num2 = (p1 - num5 * 10000 - num4 * 1000 - num3 * 100)/10;
		num1 = (p1 - num5 * 10000 - num4 * 1000 - num3 * 100 - num2 * 10);
		return num5 * num4 * num3 * num2 * num1;
	}
}

void output(int tot)
{
	printf("총 개수 : %d\n", tot);
}

void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}
