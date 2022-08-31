// 작성자 허석문 HW26

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int random(int);
int input();
void output(int, int);
void myflush();
int per, com, win = 0, draw = 0;

int main()
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		com = random(3) + 1;
		per = input();
		if ((com == 1 && per == 2) || (com == 2 && per == 3) || (com == 3 && per == 1))
		{ 
			if (per == 1) { printf("당신은 바위 선택, 컴퓨터는 보 선택 : 졌습니다\n"); }
			else if (per == 2) { printf("당신은 가위 선택, 컴퓨터는 바위 선택 : 졌습니다\n"); }
			else { printf("당신은 보 선택, 컴퓨터는 가위 선택 : 졌습니다\n"); }
			break; 
		}
		else if (com == per)
		{
			if (per == 1) { printf("당신은 바위 선택, 컴퓨터는 바위 선택 : 비겼습니다\n"); draw++; }
			else if (per == 2) { printf("당신은 가위 선택, 컴퓨터는 가위 선택 : 비겼습니다\n"); draw++; }
			else { printf("당신은 보 선택, 컴퓨터는 보 선택 : 비겼습니다\n"); draw++; }
		}
		else
		{
			if (per == 1) { printf("당신은 바위 선택, 컴퓨터는 가위 선택 : 이겼습니다\n"); win++; }
			else if (per == 2) { printf("당신은 가위 선택, 컴퓨터는 보 선택 : 이겼습니다\n"); win++; }
			else { printf("당신은 보 선택, 컴퓨터는 바위 선택 : 이겼습니다\n"); win++; }
		}
	}

	output(win, draw);
	return 0;
}

int random(int n)
{
	int res;
	res = rand() % n;
	return res;
}

int input()
{
	while (1)
	{		
		int res;
		printf("바위는 1, 가위는 2, 보는 3 중에서 선택하세요:");
		res =scanf("%d", &per);
		if (res == 1 && getchar() == '\n' && 1 <= per && per <= 3) { break; }
		else if (per <1 || per>3)
		{
			;
		}
		else { myflush();}
	}
	return per;
}

void output(int win, int draw)
{
	printf("게임 결과 : %d 승 %d 무\n", win, draw);
}

void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}