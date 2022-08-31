//작성자 허석문 HW25

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int max = 100, min = 0;
int random(int);
int input();
void output(int, int);

int main()
{
	int number, answer;
	int i = 1;
	srand((unsigned int)time(NULL));
	answer = random(100) + 1;
	while (1)
	{
		number = input();
		if (answer == number)
		{
			printf("우와~ 맞았당~~~ 추카추카 ~~ %d 번째 만에 맞추셨습니다.\n", i);
			break;
		}
		output(number, answer);
		i++;
	}
	return 0;
}

int input()
{
	int num;
	while (1)
	{
		printf("숫자를 입력하세요:");
		scanf("%d", &num);
		if (num>=0 && num <= 100) { break; }
	}
	return num;
}

void output(int num, int ans)
{
	if (num < ans)
	{
		min = num;
		printf("%d보다는 크고 %d보다는 작습니다\n", min, max);
	}
	if (num > ans)
	{
		max = num;
		printf("%d보다는 크고 %d보다는 작습니다\n", min, max);
	}
	
}

int random(int num)
{
	int res;
	res = rand() % num;
	return res;
}
