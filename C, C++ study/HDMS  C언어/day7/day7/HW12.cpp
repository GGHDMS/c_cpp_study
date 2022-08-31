//작성자 허석문 HW12

#include<stdio.h>
char name[20];

int main()
{	

	printf("이름을 입력하시오:");
	scanf("%s", name);
	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"", name);
}