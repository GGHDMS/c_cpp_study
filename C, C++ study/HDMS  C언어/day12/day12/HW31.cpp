//작성자 허석문 HW31

# include<stdio.h>

int tot_money = 0, money;
char want;
int menu();
void myflush();
int inputInt(const char *);
int deposit(int, int);
int withdraw(int, int);

int main() 
{
	printf("현재 잔액은 %d원 입니다.\n", tot_money);
	while (1)
	{
		want = menu();
		if (want == 'q') { break; }
		else if (want == 'i')
		{
			while (1)
			{
				money = inputInt("입금액을 입력하세요 : ");
				if (money < 0)
				{
					printf("잘못 입력하셨습니다.\n");
				}
				else { break; }
			}
			tot_money = deposit(tot_money, money);
			printf("현재 잔액은 %d원 입니다\n", tot_money);
		}
		else
		{
			while (1)
			{
				money = inputInt("출금액을 입력하세요 : ");
				if (money < 0)
				{ 
					printf("잘못 입력하셨습니다.\n"); 
				}
				else
				{
					break;
				}
			}
			tot_money = withdraw(tot_money, money);
			if (tot_money < 0)
			{
				tot_money += money;
				printf("현재 잔액은 %d원 입니다\n", tot_money);
				continue;
			}
		}

	}
	return 0;
}

int menu()
{
	char w;
	while (1)
	{
		printf("메뉴를 선택하시오(i-입금, o-출금, q-종료): ");
		scanf("%c", &w);
		if (getchar() == '\n'&& (w == 'i' || w == 'o' || w == 'q')){ break; }
		else { printf("잘못 입력하셨습니다."); myflush(); }
	}
	return w;
}

int inputInt(const char *msg)
{
	int money, res;
	while (1)
	{
		printf(msg);
		res = scanf("%d", &money);
		if (res == 1 && getchar() == '\n') { break; }
		else{myflush(); }
	}
	return money;
}

int deposit(int tot_money, int money)
{
	tot_money = money;
	return tot_money;
}

int withdraw(int tot_money, int money)
{
	tot_money -= money;
	return tot_money;
}


void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}
