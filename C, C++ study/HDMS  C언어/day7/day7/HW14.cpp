//작성자 허석문 HW14

#include<stdio.h>
#include<string.h>

int main()
{
	char str[20];
	printf("문자열 입력:");
	scanf("%s", str);
	int num = strlen(str);
	printf("[%*.*s...]", num, num / 2, str);
	return 0;
}