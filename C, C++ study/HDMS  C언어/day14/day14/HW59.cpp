//작성자 허석문 HW59

#include<stdio.h>
int num, sum, res;
int my_num[100];
int calc[1000];

int main()
{
	while (1)
	{
		int i, f_num;
		for (i = 0; i < 1000; i++)
		{
			calc[i] = 0;
		}
		sum = 0;
		printf("입력할 숫자의 개수 :");
		res = scanf("%d", &num);
		if (getchar() != '\n') { break; }
		printf("숫자 입력 :");
		for(i=0; i< num; i++)
		{
			scanf("%d", &my_num[i]);
		}
		for (i = 0; i < num; i++)
		{
			f_num = my_num[i];
			calc[f_num] = 1;
		}
		for (i = 0; i < 1000; i++)
		{
			if (calc[i] != 0) { sum += 1; }
		}
		printf("서로 다른 수의 개수 : %d\n", sum);
	}
	return 0;
}