//�ۼ��� �㼮�� HW50

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
			printf("%s���ڿ� �ȿ� %c���ڴ� %d�� ��ġ�� �����մϴ�\n", str, ch, num);
		}
		else
		{
			printf("%s���ڿ� �ȿ� %c���ڴ� �������� �ʽ��ϴ�.\n", str, ch);
		}
	}
	return 0;
}

void input(char *str, char *ch)
{
	printf("���ڿ��� �Է��Ͻÿ�:");
	scanf("%s", str);
	printf("���ڸ� �Է��ϼ���:");
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