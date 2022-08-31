// 작성자 허석문  HW27

#include<stdio.h>

int input();
void myflush();

int main()
{
	input();
	printf("달걀 포장이 끝났습니다.\n");
}

int input()
{
	int i, gram;
	for (i = 1; i <= 10; i++)
	{
		int res;;
		printf("계란의 무게를 입력하세요:");
		res = scanf("%d", &gram);
		if (res == 1 && 150 <= gram && gram <= 500 && getchar() == '\n')
		{
			printf("현재 달걀의 수 : %d\n", i);
		}
		else if (gram < 150 && getchar() == '\n')
		{
			printf("메추리알 가지고 장난하지 마시오~ ^^\n");
			i--;
		}
		else if (500 < gram && getchar() == '\n')
		{
			printf("타조알 가지고 장난하지 마시오~ ^^\n");
			i--;
		}
		else
		{
			myflush();
			i--;
		}
	}
	return 0;
}

void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}