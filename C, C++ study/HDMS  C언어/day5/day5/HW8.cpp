// �ۼ��� �㼮�� HW8

#include<stdio.h>

int his, cul, fun, tot;
double avg;

int main()
{
	printf("����, ����, ���� ������ �Է��ϼ��� :");
	scanf("%d %d %d", &his, &cul, &fun);
	tot = his + cul + fun;
	avg = tot / 3.0;
	printf("������ %d�̰� ����� %.2lf�Դϴ�", tot, avg);
	return 0;
}
