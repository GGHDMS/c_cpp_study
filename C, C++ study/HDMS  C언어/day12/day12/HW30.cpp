//�ۼ��� �㼮�� HW30

#include<stdio.h>

int num;
void myflush();

int main()
{
	int i;
	while (1)
	{
		int res;
		printf("10���� ������ �Է��Ͻÿ�:");
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