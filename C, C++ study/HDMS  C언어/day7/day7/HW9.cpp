//작성자 허석문 HW9

#include<stdio.h>

int input();

int main()
{
	int num;
	num = input();
	printf("입력된 값은 8진수로 %#o입니다.", num);
	printf("입력된 값은 16진수로 %#x입니다.", num);
	return 0;
}

int input()
{	
	int name;
	printf("정수를 입력하세요:");
	scanf("%d", &name);
	return name;
}

