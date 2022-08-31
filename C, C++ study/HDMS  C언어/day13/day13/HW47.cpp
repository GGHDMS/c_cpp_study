//작성자 허석문 HW47

#include<stdio.h>
void myflush();
void input(double *);
double max(double *);
double min(double *);
void output(double, double);
double min_num, max_num;


int main()
{
	double num[5];
	input(num);
	max_num = max(num);
	min_num = min(num);
	output(max_num, min_num);
	return 0;
}

void input(double *num) 
{
	int i;
	for (i = 0; i <= 4; i++)
	{
		printf("%d 번 방 값:", i);
		scanf("%lf", &num[i]);
		if (getchar() != '\n') { myflush(); i--; }
	}
}

double max(double *num)
{
	double max;
	int i;
	max = num[0];
	for (i = 1; i <= 4; i++)
	{
		if (num[i] > max) { max = num[i]; }
	}
	return max;
}

double min(double *num)
{
	double min;
	int i;
	min = num[0];
	for (i = 1; i <= 4; i++)
	{
		if (num[i] < min) { min = num[i]; }
	}
	return min;
}

void output(double max, double min)
{
	printf("가장 큰 값 : %.2lf\n", max);
	printf("가장 작은 값 : %.2lf", min);
}

void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}