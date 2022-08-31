// �ۼ��� �㼮�� HW26

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int random(int);
int input();
void output(int, int);
void myflush();
int per, com, win = 0, draw = 0;

int main()
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		com = random(3) + 1;
		per = input();
		if ((com == 1 && per == 2) || (com == 2 && per == 3) || (com == 3 && per == 1))
		{ 
			if (per == 1) { printf("����� ���� ����, ��ǻ�ʹ� �� ���� : �����ϴ�\n"); }
			else if (per == 2) { printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�\n"); }
			else { printf("����� �� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�\n"); }
			break; 
		}
		else if (com == per)
		{
			if (per == 1) { printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�\n"); draw++; }
			else if (per == 2) { printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�\n"); draw++; }
			else { printf("����� �� ����, ��ǻ�ʹ� �� ���� : �����ϴ�\n"); draw++; }
		}
		else
		{
			if (per == 1) { printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�\n"); win++; }
			else if (per == 2) { printf("����� ���� ����, ��ǻ�ʹ� �� ���� : �̰���ϴ�\n"); win++; }
			else { printf("����� �� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�\n"); win++; }
		}
	}

	output(win, draw);
	return 0;
}

int random(int n)
{
	int res;
	res = rand() % n;
	return res;
}

int input()
{
	while (1)
	{		
		int res;
		printf("������ 1, ������ 2, ���� 3 �߿��� �����ϼ���:");
		res =scanf("%d", &per);
		if (res == 1 && getchar() == '\n' && 1 <= per && per <= 3) { break; }
		else if (per <1 || per>3)
		{
			;
		}
		else { myflush();}
	}
	return per;
}

void output(int win, int draw)
{
	printf("���� ��� : %d �� %d ��\n", win, draw);
}

void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}