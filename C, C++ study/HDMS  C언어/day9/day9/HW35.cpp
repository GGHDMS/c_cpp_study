//�ۼ��� �㼮�� HW35

#include<stdio.h>
int i, num, sum = 0;

int main()
{
	for (i = 1; i <= 5; i++)
	{
		printf("0���� ū���� �Է��Ͻÿ�(%d ��°):", i);
		scanf("%d", &num);
		if (num < 0)
		{
			i--;
			continue;
		}
		sum += num;
	}
	printf("�Էµ� ���� �� ��: %d", sum);
	return 0;
}