//작성자 허석문 HW50

#include<stdio.h>
char str[100], ch;
int num;
void input(char *, char *);
int strcheck(char *, char);

int main()
{
	int i;
	for (i = 0; i < 3; i++)
	{	
		if (i > 0)
		{
			while (getchar() != '\n')
			{
				;
			}
		}
		input(str, &ch);
		num = strcheck(str, ch);
		if (num != -1)
		{
			printf("%s문자열 안에 %c문자는 %d번 위치에 존재합니다\n", str, ch, num);
		}
		else
		{
			printf("%s문자열 안에 %c문자는 존재하지 않습니다.\n", str, ch);
		}
	}
	return 0;
}

void input(char *str, char *ch)
{
	printf("문자열을 입력하시오:");
	scanf("%s", str);
	printf("문자를 입력하세요:");
	scanf(" %c", ch);
}

int strcheck(char *str, char ch)
{
	int i = 0;
	while (1)
	{
		if (str[i] == ch)
		{
			break;
		}
		if (i == 99)
		{
			i = -1;
			break;
		}
		i++;
	}
	return i;
}