#include <stdio.h>
int main()
{
	FILE *fp;
	char ch;
	fp = fopen("a.txt", "r");
	if (fp == NULL) {
		printf("���� ���� ����.\n");
		return 1;
	}
	while (1) {
		ch = fgetc(fp);
		if (ch == EOF) break;
		putchar(ch);
	}
	printf("\n");
	printf("�����Ѱ��� �Է��ϼ���: ");
	ch = getchar();
	printf("�Էµ� ���� : %c\n", ch);
	fclose(fp);
	return 0;
}
