// �ۼ��� �㼮�� HW22

#include<stdio.h>
double num, sum = 0;
int older=1;

int main()
{
	while (older <= 5)
	{
		printf("%d �� �л��� Ű��?", older);
		scanf("%lf", &num);
		sum += num;
		older++;
	}
	printf("�ټ� ���� ��� Ű�� %.1lf cm �Դϴ�.\n", sum / 5);
	return 0;
}