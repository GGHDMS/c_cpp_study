// 작성자 허석문 HW4

#include<stdio.h>


double year = 365.2422;
int day, hour, min;
double sec;
void calc();

int main()
{
	calc();
	return 0;
}

void calc()
{
	day = (int)year;
	double exact_hour = 24 * (year - day);
	hour = (int)exact_hour;
	double exact_min = 60 * (exact_hour - hour);
	min = (int)exact_min;
	sec = 60 * (exact_min - min);
	printf("%.4lf일은 %d일 %d시간 %d분 %.2lf초 입니다", year, day, hour, min, sec);
}