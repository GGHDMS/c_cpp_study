//작성자 허석문 HW10

#include<stdio.h>
int num1, num2;

int main()
{
	printf("두개의 정수를 입력하시오:");
	scanf("%d %d", &num1, &num2);
	printf("%d + %d = %d\n", num1, num2, num1 + num2);
	printf("%d - %d = %d\n", num1, num2, num1 - num2);
	printf("%d * %d = %d\n", num1, num2, num1 * num2);
	printf("%d / %d = %.2lf\n", num1, num2, (double)num1 / num2);
	return 0;
}