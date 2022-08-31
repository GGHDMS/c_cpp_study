#include <stdio.h>
//#define TC

#ifdef TC
#include <conio.h>
#define MAX_INT 32767
#else
#define MAX_INT 2147483647
#endif

int main()
{
	int m = MAX_INT;
	printf("Maximum value => %d\n", m);
#ifdef TC
	char ch= getch();
	printf("getch한 문자 = %c\n", ch);
#endif
	printf("program 끝\n");
	return 0;
}
