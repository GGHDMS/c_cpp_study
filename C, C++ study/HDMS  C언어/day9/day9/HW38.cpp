//작성자 허석문 HW38

#include<stdio.h>

int i, j, k, money, calc_money;

int main()
{
	printf("현재 당신의 소유 금액 입력:");
	scanf("%d", &money);

	for (i = 1; i <= money / 500; i++)
	{
		for (j = 1; j <= money / 700; j++)
		{
			for (k = 1; k <= money / 400; k++)
			{
				calc_money = money - 500 * i - 700 * j - 400 * k;

				if (i >= 1 && j >= 1 && k >= 1 && calc_money == 0)
				{
					printf("크림빵(%d개), 새우깡(%d개), 콜라(%d개)\n", i, j, k);
				}
			}
		}
	}
	return 0;
}