#include<stdio.h>

float x;
int count = 1;

int main()
{
	for (x = 100000001.0f; x <= 100000010.0f; x += 1.0f)
	{
		printf("%d. x = %.30f\n", count++, x);
	}
}