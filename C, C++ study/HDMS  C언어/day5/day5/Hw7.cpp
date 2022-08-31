//작성자 허석문 HW7

#include<stdio.h>

double km, km_h, sec;
int hour, min;

int main()
{
	printf("거리를 입력하세요(km단위):");
	scanf("%lf", &km);
	printf("시속을 입력하세요(km/h단위):");
	scanf("%lf", &km_h);
	hour = (int)(km / km_h);
	min = (int)(km / km_h * 60 - hour * 60);
	sec = (km / km_h * 3600 - hour * 3600 - min * 60);
	printf("%.2lfkm = > %d시간 %d분 %.3lf 초 소요됨", km, hour, min, sec);
	return 0;
}
