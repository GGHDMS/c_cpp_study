// ������ �㼮�� HW4

#pragma warning (disable : 4996)

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(int *);
int random(int);;
int **create(int);
void gamePractice(int **, int);
void gamePlay(int **, int **, int *, int);
int check(int **, int);
void myFlush();

int main() {
	int num, tnum;
	int **p1, **p2;
	int *pt;
	srand((unsigned int)time(NULL));
	while (1) {
		num = 0, tnum = 0;
		menu(&num);
		if (num == 3) {
			break;
		}
		while (tnum < 2 || 10 < tnum) {
			printf("# �������� ����, ���� ũ�⸦ �Է����ּ���(����� �Է�) : ");
			scanf("%d", &tnum);
			myFlush();
		}
		if (num == 1) {
			p1 = create(tnum);
			gamePractice(p1, tnum);
			for (num = 0; num < tnum; num++) {
				free(p1[num]);
			}
			free(p1);
		}
		if (num == 2) {
			int i, nt, mt, tr;
			p1 = create(tnum);
			p2 = create(tnum);
			pt = (int *)malloc(sizeof(int) * tnum * tnum);
			for (i = 1; i <= tnum * tnum; i++) {
				pt[i - 1] = i;
			}
			for (i = 0; i < tnum*tnum; i++) {
				nt = random(tnum*tnum);
				mt = random(tnum*tnum);
				tr = pt[nt];
				pt[nt] = pt[mt];
				pt[mt] = tr;
			}
			gamePlay(p1, p2, pt, tnum);
			for (num = 0; num < tnum; num++) {
				free(p1[num]);
			}
			free(p1);
			for (num = 0; num < tnum; num++) {
				free(p2[num]);
			}
			free(p2);
			free(pt);
		}
	}
	return 0;
}

void menu(int *num) {
	while (*num < 1 || 3 < *num) {
		printf("1. ��������(���� ������)\n");
		printf("2. ��������(��ǻ�Ϳ� ������)\n");
		printf("3. ����\n\n");
		printf("# �޴����� :");
		scanf("%d", num);
		myFlush();
	}
}

int random(int n) {
	int res;
	res = rand() % n;
	return res;
}

int ** create(int num) {
	int **p;
	int i, j, nt, mt, tnum;
	int *t;
	t = (int *)malloc(sizeof(int) * num * num);
	for (i = 1; i <= num*num; i++) {
		t[i - 1] = i;
	}
	for (i = 0; i < num*num; i++) {
		 nt = random(num*num);
		 mt = random(num*num);
		 tnum = t[nt];
		 t[nt] = t[mt];
		 t[mt] = tnum;
	}
	p = (int **)malloc(num * sizeof(int*));
	for (i = 0; i < num; i++) {
		p[i] = (int *)malloc(num * sizeof(int));
	}
	tnum = 0;
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			p[i][j] = t[tnum++];
		}
	}
	free(t);
	return p;
}

void gamePractice(int ** p, int tnum) {
	int i, j, num;
	while (1) {
		printf("\n");
		for (i = 0; i < tnum; i++) {
			printf("|");
			for (j = 0; j < tnum; j++) {
				if (p[i][j] == 0) {
					printf("%3c", 'X');
					continue;
				}
				printf("%3d", p[i][j]);
			}
			printf(" |\n");
		}
		printf("\n");
		num = 0;
		while (num < 1 || tnum * tnum < num) {
			printf("���� ���� �Է�(1~%d) : ", tnum*tnum);
			scanf("%d", &num);
			myFlush();
		}
		for (i = 0; i < tnum; i++) {
			for (j = 0; j < tnum; j++) {
				if (p[i][j] == num) {
					break;
				}
			}
			if (p[i][j] == num) {
				p[i][j] = 0;
				break;
			}
		}
		printf("����� ���� : %d��\n", check(p, tnum));
		if (check(p, tnum) >= tnum)
		{
			break;
		}
		if (i == tnum) {
			printf("�̹� ������ ���� �Դϴ�. �ٽ� �Է��ϼ���.\n");
		}
	}
	getchar();
}

void gamePlay(int **p1, int **p2, int *pt, int tnum) {
	int i, j, num, winM, winC, comNum;
	printf("\n����� ��������� ������ �������Դϴ�.\n");
	printf("��ǻ�� ������ ������ �������Դϴ�.\n\n");
	printf("%s%*c%s", "user", tnum * 4, ' ', "computer\n");
	for (i = 0; i < tnum; i++) {
		printf("|");
		for (j = 0; j < tnum; j++) {
			if (p1[i][j] == 0) {
				printf("%3c", 'X');
				continue;
			}
			printf("%3d", p1[i][j]);
		}
		printf("|%*c", tnum, ' ');
		printf("|");
		for (j = 0; j < tnum; j++) {
			if (p2[i][j] == 0) {
				printf("%3c", 'X');
				continue;
			}
			printf("%3d", p2[i][j]);
		}
		printf(" |\n");
	}
	printf("\n");
	while (1) {
		num = 0;

		// ����� ���� �̱�
		while (num < 1 || tnum * tnum < num) {
			printf("���� ���� �Է�(1~%d) : ", tnum*tnum);
			scanf("%d", &num);
			myFlush();
		}
		for (i = 0; i < tnum; i++) {
			for (j = 0; j < tnum; j++) {
				if (p1[i][j] == num) {
					break;
				}
			}
			if (p1[i][j] == num) {
				p1[i][j] = 0;
				break;
			}
		}
		if (i == tnum) {
			printf("�̹� ������ ���� �Դϴ�. �ٽ� �Է��ϼ���.\n\n");
			continue;
		}
		for (i = 0; i < tnum; i++) {
			for (j = 0; j < tnum; j++) {
				if (p2[i][j] == num) {
					break;
				}
			}
			if (p2[i][j] == num) {
				p2[i][j] = 0;
				break;
			}
		}
		printf("\n%s%*c%s", "user", tnum * 4, ' ', "computer\n");

		for (i = 0; i < tnum; i++) {
			printf("|");
			for (j = 0; j < tnum; j++) {
				if (p1[i][j] == 0) {
					printf("%3c", 'X');
					continue;
				}
				printf("%3d", p1[i][j]);
			}
			printf("|%*c", tnum, ' ');
			printf("|");
			for (j = 0; j < tnum; j++) {
				if (p2[i][j] == 0) {
					printf("%3c", 'X');
					continue;
				}
				printf("%3d", p2[i][j]);
			}
			printf(" |\n");
		}
		printf("\n");

		winM = check(p1, tnum);
		printf("\n");
		winC = check(p2, tnum);
		printf("����� ���� : %d��\n", winM);
		printf("��ǻ�� ���� : %d��\n\n", winC);
		if (winC >= tnum && winM >= tnum) {
			printf("�����, ��ǻ�� ���º�!\n");
			break;
		}
		if (winC >= tnum) {
			printf("��ǻ�� ��!\n");
			break;
		}
		if (winM >= tnum) {
			printf("����� ��!\n");
			break;
		}

		// ��ǻ�� ���� �̱�
		for (i = 0; i < tnum*tnum; i++) {
			if (pt[i] == num) {
				pt[i] = 0;
				break;
			}
		}
		for (i = 0; i < tnum*tnum; i++) {
			if (pt[i] != 0) {
				comNum = pt[i];
				pt[i] = 0;
				break;
			}
		}
		printf("��ǻ�Ͱ� ������ ���ڴ� (%d)�Դϴ�.\n\n", comNum);

		for (i = 0; i < tnum; i++) {
			for (j = 0; j < tnum; j++) {
				if (p1[i][j] == comNum) {
					break;
				}
			}
			if (p1[i][j] == comNum) {
				p1[i][j] = 0;
				break;
			}
		}
		for (i = 0; i < tnum; i++) {
			for (j = 0; j < tnum; j++) {
				if (p2[i][j] == comNum) {
					break;
				}
			}
			if (p2[i][j] == comNum) {
				p2[i][j] = 0;
				break;
			}
		}

		for (i = 0; i < tnum; i++) {
			printf("|");
			for (j = 0; j < tnum; j++) {
				if (p1[i][j] == 0) {
					printf("%3c", 'X');
					continue;
				}
				printf("%3d", p1[i][j]);
			}
			printf("|%*c", tnum, ' ');
			printf("|");
			for (j = 0; j < tnum; j++) {
				if (p2[i][j] == 0) {
					printf("%3c", 'X');
					continue;
				}
				printf("%3d", p2[i][j]);
			}
			printf(" |\n");
		}
		printf("\n");

		winM = check(p1, tnum);
		winC = check(p2, tnum);
		printf("����� ���� : %d��\n", winM);
		printf("��ǻ�� ���� : %d��\n\n", winC);
		if (winC >= tnum && winM >= tnum) {
			printf("�����, ��ǻ�� ���º�!\n");
			break;
		}
		if (winC >= tnum) {
			printf("��ǻ�� ��!\n");
			break;
		}
		if (winM >= tnum) {
			printf("����� ��!\n");
			break;
		}
	}
	getchar();
}

int check(int **p, int tnum) {
	int n = 0, sum;
	int i, j;
	for (i = 0; i < tnum; i++) {
		sum = 0;
		for (j = 0; j < tnum; j++) {
			sum += p[i][j];
		}
		if (sum == 0) {
			n++;
		}
	}

	for (i = 0; i < tnum; i++) {
		sum = 0;
		for (j = 0; j < tnum; j++) {
			sum += p[j][i];
		}
		if (sum == 0) {
			n++;
		}
	}

	j = 0;
	sum = 0;
	for (i = 0; i < tnum; i++) {
		sum += p[i][j];
		j++;
	}

	if (sum == 0) {
		n++;
	}

	j = tnum -1;
	sum = 0;
	for (i = 0; i < tnum; i++) {
		sum += p[i][j];
		j--;
	}

	if (sum == 0) {
		n++;
	}

	return n;
}

void myFlush() {
	while (getchar() != '\n') {
		;
	}
}