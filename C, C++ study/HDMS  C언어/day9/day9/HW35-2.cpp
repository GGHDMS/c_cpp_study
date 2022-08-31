//작성자 허석문 HW35-2

#include<stdio.h>

int main()
{
	int i;
	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			if (i % 3 == 0 && i % 5 != 0)
			{
				printf("%3c",'*');
			}
			else if (i % 3 != 0 && i % 5 == 0)
			{
				printf("%3c",'#');
			}
			else
			{
				printf("%3d", i);
			}
		}
		else
		{
			printf("%3d", i);
		}
		if (i % 10 == 0)
		{
			printf("\n");
		}
	}
	return 0;
}