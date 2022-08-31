//작성자 허석문 HW54

#include<stdio.h>
#include<string.h>

char str[100];
char my_num[100];
void input(char *);
int calc(char *);
void output(char *, int);
int want;

int main()
{
	while (1)
	{
		input(str);
		if (strcmp(str, "end") == 0) { break; }
		want = calc(str);
		output(str, want);
	}
	return 0;
}

void input(char *str)
{
	printf("문장을 입력하시오 : ");
	scanf("%s", str);
}

int calc(char *str)
{
	int num, i, j, k, l, n, sum = 0, small_num, have;
	num = strlen(str);
	for (i = 0; i < num; i++)
	{
		j = i;
		if (48 <= str[i] && str[i] <= 57)
		{
			k = 0;
			while (1)
			{
				if (str[j] < 48) { break; }
				if (str[j] > 57) { break; }
				my_num[k] = str[j];
				k++;
				j++;
			}
			small_num = strlen(my_num);
			i += (small_num - 1);
			have = 1;
			for (l = 1; l <= small_num; l++)
			{
				if (l > 1) { have *= 10; }
			}
			n = 0;
			for (have; have >= 1; have /= 10)
			{
				sum += (my_num[n] - '0')*have;
				n++;
			}
		}
	}
	return sum;
}

void output(char *str, int sum)
{
	printf("\"%s\" 내의 총 숫자는 [%d]입니다.\n", str, sum);
}