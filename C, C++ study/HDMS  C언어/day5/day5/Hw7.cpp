//�ۼ��� �㼮�� HW7

#include<stdio.h>

double km, km_h, sec;
int hour, min;

int main()
{
	printf("�Ÿ��� �Է��ϼ���(km����):");
	scanf("%lf", &km);
	printf("�ü��� �Է��ϼ���(km/h����):");
	scanf("%lf", &km_h);
	hour = (int)(km / km_h);
	min = (int)(km / km_h * 60 - hour * 60);
	sec = (km / km_h * 3600 - hour * 3600 - min * 60);
	printf("%.2lfkm = > %d�ð� %d�� %.3lf �� �ҿ��", km, hour, min, sec);
	return 0;
}
