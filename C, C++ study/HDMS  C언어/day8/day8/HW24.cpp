//�ۼ��� �㼮�� HW24

#include<stdio.h>

int deep, day;
int input();
int calc(int);
void output(int, int);

int main()
{
	deep = input();
	day = calc(deep);
	output(deep, day);
	return 0;
}

int input()
{
	int m;
	printf("�칰�� ���̸� �Է��Ͻÿ�(cm����):");
	scanf("%d", &m);
	return m;
}

int calc(int m)
{
	int i = 0;
	int calc_deep;
	calc_deep = m;
	while (1)
	{
		if (m == 0) { break; }
		calc_deep -= 50;
		i++;
		if (calc_deep <= 0) { break; }
		calc_deep += 20;
	}
	return i;
}

void output(int m, int i)
{
	printf("�칰����  %dcm : %d��\n", m, i);
}