// 작성자 허석문 HW22

#include<stdio.h>
double num, sum = 0;
int older=1;

int main()
{
	while (older <= 5)
	{
		printf("%d 번 학생의 키는?", older);
		scanf("%lf", &num);
		sum += num;
		older++;
	}
	printf("다섯 명의 평균 키는 %.1lf cm 입니다.\n", sum / 5);
	return 0;
}