//작성자 허석문 HW23

#include<stdio.h>
int res, num1, num2;

int main()
{
	while (1)
	{
		printf("두개의 정수를 입력하세요:");
		res = scanf("%d %d", &num1, &num2);
		if (res != 2) { break; }
		if (num1 > num2)
		{
			printf("%d - %d = %d\n", num1, num2, num1 - num2);
		}
		else
		{
			printf("%d - %d = %d\n", num2, num1, num2 - num1);
		}
	}
	return 0;
}