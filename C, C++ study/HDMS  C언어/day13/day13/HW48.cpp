//작성자 허석문 HW48

#include<stdio.h>

int ary[] = { 2,8,15,1,8,10,5,19,19,3,5,6,6,2,8,2,12,16,3,8,17,
12,5,3,14,13,3,2,17,19,16,8,7,12,19,10,13,8,20,
16,15,4,12,3,14,14,5,2,12,14,9,8,5,3,18,18,20,4 };
int count[20];

int main()
{
	int i, j, num, calc;
	num = sizeof(ary) / sizeof(ary[0]);
	for (i = 1; i <= 20; i++)
	{
		calc = 0;
		for (j = 0; j < num; j++)
		{
			if (ary[j] == i)
			{
				calc ++;
			}
		}
		count[i-1] = calc;
	}
	for (i = 0; i < 20; i++)
	{
		printf("%d - %d개\n", i + 1, count[i]);
	}
	return 0;
}