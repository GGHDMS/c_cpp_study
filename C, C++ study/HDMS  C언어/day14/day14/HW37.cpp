//�ۼ��� �㼮�� HW37

#include<stdio.h>

int main()
{
	int i, calc, num, calc_num, money;
	for (i = 0; i < 5; i++)
	{
		money = 0;
		calc = 1;
		printf("����� �ٹ��ϼ��� �Է��Ͻÿ�:");
		scanf("%d", &num);
		calc_num = num;
		while (1)
		{
			calc_num -= calc;
			if (calc_num <= 0)
			{
				calc_num += calc;
				money += calc * calc_num;
				break;
			}
			money += calc * calc;
			calc++;
		}
		printf("�ٹ��� : %d / �� ��ȭ �� %d��\n", num, money);
	}
	return 0;
}