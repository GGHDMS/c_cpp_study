//�ۼ��� �㼮�� HW33

#include<stdio.h>
unsigned char fan = 0;
void openFan(unsigned char*);
void offFan(unsigned char*);
void reverseFan(unsigned char*);
void displayFan(unsigned char*);
int num, open_num, close_num;
int menu();

int main()
{
	while (1)
	{
		num = menu();
		if (num == 4) { break; }
		printf("------------------------------------------------------------------------------\n");
		if (num == 1) { openFan(&fan); }
		if (num == 2) { offFan(&fan); }
		if (num == 3) { reverseFan(&fan); }
		
	}
	return 0;
}

int menu()
{
	int num;
	while (1)
	{
		printf("1. ȯǳ�� ���� / 2. ȯǳ�� �ݱ� / 3. ȯǳ�� ��ü ��ȯ / 4. ���� : ");
		if (scanf("%d", &num)==1 && 1 <= num && num <= 4 && getchar() == '\n') { break; }
		else
		{
			while (getchar() != '\n')
			{
				;
			}
		}

	}
	return num;
}

void openFan(unsigned char *fan)
{
	int num, i, calc=1;
	printf("                          Fan ���� �۾� ���� ȭ��\n");
	printf("------------------------------------------------------------------------------\n");
	while (1)
	{
		printf("ON�� FAN ��ȣ�� �Է��Ͻÿ�(1~8):");
		if (scanf("%d", &num) == 1 && 0 < num && num < 9 && getchar() == '\n') { break; }
		else {
			while (getchar() != '\n')
			{
				;
			}
		}
	}
	for (i = 1; i <= num; i++)
	{
		if (i > 1) { calc *= 2; }
	}
	*fan = *fan | calc;
	printf("------------------------------------------------------------------------------\n");
	for (i = 8; i >= 1; i--)
	{
		printf("%d��FAN\t", i);
	}
	printf("\n");
	displayFan(fan);
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
}

void offFan(unsigned char *fan)
{
	int num, i, calc = 254;
	printf("                          Fan �ݱ� �۾� ���� ȭ��\n");
	printf("------------------------------------------------------------------------------\n");
	while (1)
	{
		printf("OFF�� FAN ��ȣ�� �Է��Ͻÿ�(1~8):");
		if (scanf("%d", &num) == 1 && 0 < num && num < 9 && getchar() == '\n') { break; }
		else {
			while (getchar() != '\n')
			{
				;
			}
		}
	}
	for (i = 1; i <= num; i++)
	{
		if (i > 1) { calc <<= 1; }
	}
	*fan = *fan & calc;
	printf("------------------------------------------------------------------------------\n");
	for (i = 8; i >= 1; i--)
	{
		printf("%d��FAN\t", i);
	}
	printf("\n");
	displayFan(fan);
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
}

void displayFan(unsigned char *fan)
{
	int i;
	for (i = 128; i >= 1; i /= 2)
	{
		if ((*fan & i) == i)
		{
			printf("ON\t");
		}
		else { printf("OFF\t"); }
	}
}

void reverseFan(unsigned char *fan)
{
	int i;
	printf("                      Fan ��ü ��ȯ �۾� ���� ȭ��\n");
	printf("------------------------------------------------------------------------------\n");
	*fan = ~*fan;
	printf("��ü FAN�� ���°� ��ȯ�Ǿ����ϴ�.(ON, OFF ���� �ڹٲ�\n");
	printf("------------------------------------------------------------------------------\n");
	for (i = 8; i >= 1; i--)
	{
		printf("%d��FAN\t", i);
	}
	printf("\n");
	displayFan(fan);
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
}