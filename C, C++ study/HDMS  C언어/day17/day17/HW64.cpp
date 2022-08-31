//작성자 허석문 HW64

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

int strike, ball;
int base[4];
void input(int *);
void calc(int*, int *, int *);
void output(int, int);

int main()
{
	int i = 1;
	srand((unsigned int)time(NULL));
	input(base);
	printf("%d %d %d %d\n", base[0], base[1], base[2], base[3]);
	while (1)
	{
		printf("%d차 :", i);
		calc(base, &strike, &ball);
		output(strike, ball);
		if (strike == 4) { printf("  OK!!!\n"); break; }
		i++;
	}
	return 0;
}

void input(int *base)
{
	int i,j;
	for (i = 0; i < 4; i++)
	{
		base[i] = rand() % 9 + 1;
		if (i > 0)
		{
			for (j = 0; j < i; j++)
			{
				if (base[i] == base[j]) { i--; }
			}
		}
	}
}

void calc(int *base, int *strike, int *ball)
{
	int i, j, count = 0, s = 0, b = 0;
	char num;
	for (i = 0; i < 4; i++)
	{
		num = getche();
		printf(" ");
		for (j = 0; j < 4; j++)
		{
			if (base[i] == num - '0') { s++; break; }
			else if (base[j] == num - '0') { b++; break; }
			else { ; }
		}
		getche();
		count++;
	}
	*strike = s;
	*ball = b;
}

void output(int strike, int ball)
{
	
	if (strike == 0 && ball == 0)
	{
		printf("  No!");
	}
	else if (strike == 4)
	{
		;
	}
	else
	{
		printf("  %dS %dB\n", strike, ball);
	}
}