//�ۼ��� �㼮�� HW3

#include<stdio.h>

int total_sec = 54321;
int hour, min, sec;
void calc_ouput(int);

int main()
{
	calc_ouput(total_sec);
	return 0;
}

void calc_ouput(int total_sec)
{
	hour = total_sec / 3600;
	int mid_total_sec = total_sec - 3600 * hour;
	min = mid_total_sec / 60;
	int sec = mid_total_sec - 60 * min;
	printf("%d�ʴ� %d�ð� %d�� %d�� �Դϴ�", total_sec, hour, min, sec);
}