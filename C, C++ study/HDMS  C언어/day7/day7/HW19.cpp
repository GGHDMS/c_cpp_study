//�ۼ��� �㼮�� HW19

#include<stdio.h>

int year, num;
void input();
void check();
void output();

int main()
{
	input();
	check();
	output();
	return 0;
}

void input()
{
	printf("�⵵�� �Է��ϼ���:");
	scanf("%d", &year);
}

void check()
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				num = 366;
			}
			else
			{
				num = 365;
			}
		}
		else
		{
			num = 366;
		}
	}
	else
	{
		num = 365;
	}
}

void output()
{
	if (num == 366)
	{
		printf("%d���� ����(Leao year)�Դϴ�\n", year);

	}
	if (num == 365)
	{
		printf("%d���� ���(Common year)�Դϴ�\n", year);
	}
}


