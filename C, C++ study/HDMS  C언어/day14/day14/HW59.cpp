//�ۼ��� �㼮�� HW59

#include<stdio.h>
int num, sum, res;
int my_num[100];
int calc[1000];

int main()
{
	while (1)
	{
		int i, f_num;
		for (i = 0; i < 1000; i++)
		{
			calc[i] = 0;
		}
		sum = 0;
		printf("�Է��� ������ ���� :");
		res = scanf("%d", &num);
		if (getchar() != '\n') { break; }
		printf("���� �Է� :");
		for(i=0; i< num; i++)
		{
			scanf("%d", &my_num[i]);
		}
		for (i = 0; i < num; i++)
		{
			f_num = my_num[i];
			calc[f_num] = 1;
		}
		for (i = 0; i < 1000; i++)
		{
			if (calc[i] != 0) { sum += 1; }
		}
		printf("���� �ٸ� ���� ���� : %d\n", sum);
	}
	return 0;
}