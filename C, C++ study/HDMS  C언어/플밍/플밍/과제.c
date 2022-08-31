#include <stdio.h>
int main()
{
	FILE *fp;
	char ch;
	fp = fopen("a.txt", "r");
	if (fp == NULL) {
		printf("파일 개방 실패.\n");
		return 1;
	}
	while (1) {
		ch = fgetc(fp);
		if (ch == EOF) break;
		putchar(ch);
	}
	printf("\n");
	printf("문자한개를 입력하세요: ");
	ch = getchar();
	printf("입력된 문자 : %c\n", ch);
	fclose(fp);
	return 0;
}
