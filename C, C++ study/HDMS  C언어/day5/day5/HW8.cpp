// 작성자 허석문 HW8

#include<stdio.h>

int his, cul, fun, tot;
double avg;

int main()
{
	printf("역사, 문학, 예능 점수를 입력하세요 :");
	scanf("%d %d %d", &his, &cul, &fun);
	tot = his + cul + fun;
	avg = tot / 3.0;
	printf("총점은 %d이고 평균은 %.2lf입니다", tot, avg);
	return 0;
}
