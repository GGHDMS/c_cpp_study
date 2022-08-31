//작성자 허석문 HW59

#include<stdio.h>
#include<string.h>
char str[5][20];
void input(char(*)[20]);
void output(char(*)[20]);

int main()
{
	input(str);
	output(str);
	return 0;
}

void input(char(*str)[20])
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("%d번 문자열을 입력하시오 :", i + 1);
		scanf("%s", str[i]);
	}
}

void output(char(*str)[20])
{
	int i, num;
	for (i = 0; i < 5; i++)
	{
		num = strlen(str[i]);
		printf("str[%d] = %s  %c  %c\n", i, str[i], str[i][0], str[i][num - 1]);
	}
}

