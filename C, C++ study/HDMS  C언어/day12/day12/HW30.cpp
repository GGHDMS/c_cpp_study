//작성자 허석문 HW30

#include<stdio.h>

int num;
void myflush();

int main()
{
	int i;
	while (1)
	{
		int res;
		printf("10진수 정수를 입력하시오:");
		res = scanf("%d", &num);
		if (res == 1 && getchar() == '\n') { break; }
		else { myflush(); }
	}
	unsigned int  calc = 0x80000000;
	printf("%d(10) = ", num);
	for (i = 1; i <= 32; i++)
	{
		if ((num & calc) == 0)
		{
			printf("0");
		}
		else 
		{ 
			printf("1"); 
		}
		calc = calc >> 1;
	}
	printf("(2)\n");
	
	return 0;
}

void myflush()
{
	while (getchar() !='\n')
	{
		;
	}
}