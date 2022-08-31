//작성자 허석문 HW37

#include<stdio.h>

int main()
{
	int i, calc, num, calc_num, money;
	for (i = 0; i < 5; i++)
	{
		money = 0;
		calc = 1;
		printf("기사의 근무일수를 입력하시오:");
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
		printf("근무일 : %d / 총 금화 수 %d개\n", num, money);
	}
	return 0;
}