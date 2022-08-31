//작성자 허석문 HW35

#include<stdio.h>
int i, num, sum = 0;

int main()
{
	for (i = 1; i <= 5; i++)
	{
		printf("0보다 큰수를 입력하시오(%d 번째):", i);
		scanf("%d", &num);
		if (num < 0)
		{
			i--;
			continue;
		}
		sum += num;
	}
	printf("입력된 값의 총 합: %d", sum);
	return 0;
}