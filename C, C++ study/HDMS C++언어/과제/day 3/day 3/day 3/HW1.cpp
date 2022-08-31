//������ �㼮�� HW1

#include <stdio.h>
#include <string.h>

void input(struct Dic *, int *);
void output(struct Dic *, int *);
void search(struct Dic *, int *);
void del(struct Dic *, int *);
void myflush();

struct Dic{
	char word[20];
	char mean[80];
	int len;
};

int main() {
	struct Dic ary[10];
	int num, check = 0, res;

	while (1) {
		printf("�޴��� �����ϼ���\n");
		printf("�Է��ϱ�(1) ����ϱ�(2) �˻��ϱ�(3) �����ϱ�(4) : ");
		res = scanf("%d", &num);
		myflush();
		if (res != 1) {
			continue;
		}
		switch (num)
		{
			case 1:input(ary, &check); break;
			case 2:output(ary, &check); break;
			case 3:search(ary, &check); break;
			case 4:del(ary, &check); break;
			default: break;
		}
	}
	return 0;
}

void input(struct Dic *ary, int *check) {
	int len;
	while (*check < 10) {
		printf("#�ܾ �Է��Ͻÿ� : ");
		scanf("%s", ary[*check].word);
		if (strcmp("end", ary[*check].word) == 0) {
			myflush();
			break;
		}
		myflush();
		printf("#���� �Է��Ͻÿ� : ");
		fgets(ary[*check].mean, 80, stdin);
		len = (strlen(ary[*check].mean));
		if (ary[*check].mean[len-1] == '\n'){
			ary[*check].mean[len-1] = '\0';
		}
		else{
			myflush();
		}
		ary[*check].len = strlen(ary[*check].word);
		(*check)++;
	}
}

void output(struct Dic *ary, int *check) {
	struct Dic temp;
	int i, j;
	for (i = 0; i < *check - 1; i++) {
		for (j = 0; j < *check - 1 - i; j++) {
			if (strcmp(ary[j].word , ary[j + 1].word)>0) {
				temp = (ary[j]);
				ary[j] = ary[j + 1];
				ary[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < *check; i++) {
		if (strlen(ary[i].mean) > 50) {
			printf("%2d. %20s(%2d) : ", i + 1, ary[i].word, ary[i].len);
			for (int j = 0; j < 50; j++) {
				printf("%c", ary[i].mean[j]);
			}
			printf("~\n");
		}
		else{
			printf("%2d. %20s(%2d) : %s\n", i + 1, ary[i].word, ary[i].len, ary[i].mean);
		}	
	}
	getchar();
}

void search(struct Dic *ary, int *check) {
	char str[20];
	int i;
	printf("#ã�� �ܾ �Է��Ͻÿ� : ");
	scanf("%s", str);
	myflush();
	while (strcmp(str, "end") != 0) {
		for (i = 0; i < *check; i++) {
			if (strcmp(str, ary[i].word) == 0) {
				printf("�ܾ��� �� : %s\n", ary[i].mean);
				myflush();
				break;
			}
		}
		if (i == *check) {
			printf("�ش� �ܾ�� �������� �ʽ��ϴ�.\n");
		}
		printf("#ã�� �ܾ �Է��Ͻÿ� : ");
		scanf("%s", str);
	}
}

void del(struct Dic *ary, int * check) {
	char str[20], ch;
	int i;
	printf("#������ �ܾ �Է��Ͻÿ� : ");
	scanf("%s", str);
	myflush();
	while (strcmp(str, "end") != 0) {
		for (i = 0; i < *check; i++) {
			if (strcmp(str, ary[i].word) == 0) {
				printf("������ �����Ͻðڽ��ϱ�?(y/n) : ");
				scanf(" %c", &ch);
				if (ch == 'y') {
					ary[i] = ary[*check-1];
					(*check)--;
					printf("�����Ǿ����ϴ�.\n");
					i--;
				}
				myflush();
				break;
			}
		}
		if (i == *check) {
			printf("�ش� �ܾ�� �������� �ʽ��ϴ�.\n");
		}
		printf("#������ �ܾ �Է��Ͻÿ� : ");
		scanf("%s", str);
		myflush();
	}
}

void myflush() {
	while (getchar() != '\n') {
		;
	}
}