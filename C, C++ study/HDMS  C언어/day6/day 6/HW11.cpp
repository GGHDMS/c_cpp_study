// 작성자 허석문 HW11

#include<stdio.h>

int code;

int main()
{
	printf("ASCII code값을 입력하세요:");
	scanf("%d", &code);
	printf("%d은 '%c'의 ASCII code 입니다\n", code, code);
	return 0;
}