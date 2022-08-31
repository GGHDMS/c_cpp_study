//작성자 허석문 HW66

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int len;
char *min;
char *calc;
char *p[5];
char temp[1000];

int main()
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		printf("문자열 %d : ", i+1);
		scanf("%s", temp);
		len = strlen(temp);
		p[i] = (char *)malloc(sizeof(char)*(len+1));
		strcpy(p[i], temp);
	}
	for (i = 0; i < 4; i++)
	{
		min = p[i];
		for (j = i + 1; j < 5; j++)
		{
			if (strcmp(min, p[j]) == 1)
			{
				calc = min;
				min = p[j];
				p[i] = p[j];
				p[j] = calc;
			}
		}
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d. %s\n", i+1, p[i]);
	}
	for (i = 0; i < 5; i++)
	{
		free(p[i]);
	}
	return 0;
}


