// �ۼ��� �㼮��  HW27

#include<stdio.h>

int input();
void myflush();

int main()
{
	input();
	printf("�ް� ������ �������ϴ�.\n");
}

int input()
{
	int i, gram;
	for (i = 1; i <= 10; i++)
	{
		int res;;
		printf("����� ���Ը� �Է��ϼ���:");
		res = scanf("%d", &gram);
		if (res == 1 && 150 <= gram && gram <= 500 && getchar() == '\n')
		{
			printf("���� �ް��� �� : %d\n", i);
		}
		else if (gram < 150 && getchar() == '\n')
		{
			printf("���߸��� ������ �峭���� ���ÿ�~ ^^\n");
			i--;
		}
		else if (500 < gram && getchar() == '\n')
		{
			printf("Ÿ���� ������ �峭���� ���ÿ�~ ^^\n");
			i--;
		}
		else
		{
			myflush();
			i--;
		}
	}
	return 0;
}

void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}