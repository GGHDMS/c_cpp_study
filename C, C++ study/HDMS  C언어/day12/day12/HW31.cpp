//�ۼ��� �㼮�� HW31

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
	printf("���� �ܾ��� %d�� �Դϴ�.\n", tot_money);
	while (1)
	{
		want = menu();
		if (want == 'q') { break; }
		else if (want == 'i')
		{
			while (1)
			{
				money = inputInt("�Աݾ��� �Է��ϼ��� : ");
				if (money < 0)
				{
					printf("�߸� �Է��ϼ̽��ϴ�.\n");
				}
				else { break; }
			}
			tot_money = deposit(tot_money, money);
			printf("���� �ܾ��� %d�� �Դϴ�\n", tot_money);
		}
		else
		{
			while (1)
			{
				money = inputInt("��ݾ��� �Է��ϼ��� : ");
				if (money < 0)
				{ 
					printf("�߸� �Է��ϼ̽��ϴ�.\n"); 
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
				printf("���� �ܾ��� %d�� �Դϴ�\n", tot_money);
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
		printf("�޴��� �����Ͻÿ�(i-�Ա�, o-���, q-����): ");
		scanf("%c", &w);
		if (getchar() == '\n'&& (w == 'i' || w == 'o' || w == 'q')){ break; }
		else { printf("�߸� �Է��ϼ̽��ϴ�."); myflush(); }
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
