//�ۼ��� �㼮�� HW25

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
			printf("���~ �¾Ҵ�~~~ ��ī��ī ~~ %d ��° ���� ���߼̽��ϴ�.\n", i);
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
		printf("���ڸ� �Է��ϼ���:");
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
		printf("%d���ٴ� ũ�� %d���ٴ� �۽��ϴ�\n", min, max);
	}
	if (num > ans)
	{
		max = num;
		printf("%d���ٴ� ũ�� %d���ٴ� �۽��ϴ�\n", min, max);
	}
	
}

int random(int num)
{
	int res;
	res = rand() % num;
	return res;
}
