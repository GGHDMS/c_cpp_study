//작성자 허석문 H@53

#include<stdio.h>
#include<string.h>

int num;
char str[20], sstr[20];
void input(char *);
int calc(char *);
void output(char *, int);

int main()
{
	while (1)
	{
		input(str);
		if (strcmp(str, "end") == 0) { break; }
		strcpy(sstr, str);
		num = calc(sstr);
		output(str, num);
	}
	return 0;
}

void input(char *str)
{
	printf("단어 입력:");
	scanf("%s", str);
}

int calc(char *str)
{
	int num, i, k = 1;
	num = strlen(str);
	for (i = 0; i < num / 2; i++)
	{
		if (str[i] >= 97 && 122 >= str[i])
		{
			str[i] -= 32;
		}
		if (str[num -1 - i] >= 97 && 122 >= str[num -1 - i])
		{
			str[num -1 - i] -= 32;
		}
		if (str[i] != str[num -1 -i])
		{
			k = 0;
			break;
		}	
	}
	return k;
}

void output(char *str, int num)
{
	if (num == 1)
	{
		printf("\"%s\" : 회문입니다!\n", str);
	}
	else
	{
		printf("\"%s\" : 회문이 아닙니다!\n", str);
	}
}