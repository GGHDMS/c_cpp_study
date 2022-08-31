//작성자 허석문 HW33

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
		printf("1. 환풍구 열기 / 2. 환풍구 닫기 / 3. 환풍구 전체 전환 / 4. 종료 : ");
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
	printf("                          Fan 열기 작업 실행 화면\n");
	printf("------------------------------------------------------------------------------\n");
	while (1)
	{
		printf("ON할 FAN 번호를 입력하시오(1~8):");
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
		printf("%d번FAN\t", i);
	}
	printf("\n");
	displayFan(fan);
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
}

void offFan(unsigned char *fan)
{
	int num, i, calc = 254;
	printf("                          Fan 닫기 작업 실행 화면\n");
	printf("------------------------------------------------------------------------------\n");
	while (1)
	{
		printf("OFF할 FAN 번호를 입력하시오(1~8):");
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
		printf("%d번FAN\t", i);
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
	printf("                      Fan 전체 전환 작업 실행 화면\n");
	printf("------------------------------------------------------------------------------\n");
	*fan = ~*fan;
	printf("전체 FAN의 상태가 전환되었습니다.(ON, OFF 상태 뒤바뀜\n");
	printf("------------------------------------------------------------------------------\n");
	for (i = 8; i >= 1; i--)
	{
		printf("%d번FAN\t", i);
	}
	printf("\n");
	displayFan(fan);
	printf("\n");
	printf("------------------------------------------------------------------------------\n");
}