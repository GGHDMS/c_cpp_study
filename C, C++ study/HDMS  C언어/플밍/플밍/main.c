#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
typedef struct  node Node;

struct node {
	int codfficient;
	int exponet;
	Node *next;
};

typedef struct  list
{
	Node *head;
	Node *tail;
}List;

void create_list(List * lp);
void input_node(List *lp);
void output_node(List *lp);
void delete_node(List *lp);

int main() {
	printf("���� 1\n");
	List lp;
	create_list(&lp);
	input_node(&lp);
	input_node(&lp);
	input_node(&lp);
	output_node(&lp);
	delete_node(&lp);
	return 0;
}

void create_list(List *lp) {
	lp->head = (Node*)malloc(sizeof(Node));
	if (lp->head == NULL) {
		printf("�޸� �Ҵ���� create_list()\n");
	}
	lp->tail = (Node*)malloc(sizeof(Node));
	if (lp->tail == NULL) {
		printf("�޸� �Ҵ���� creat_list()\n");
	}
	lp->head->next = lp->tail;
	lp->tail->next = NULL;
}

void input_node(List *lp) {
	int a, b;
	scanf("%d %d", &a, &b);
	Node *np = (Node *)malloc(sizeof(Node));
	if (np == NULL) {
		printf("�޸� �Ҵ���� input_node\n");
	}
	np->codfficient = a;
	np->exponet = b;
	Node *tp= lp->head;
	while (tp -> next!= lp->tail) {
		tp = tp->next;
	}
	np->next = tp ->next;
	tp->next = np;
}

void output_node(List *lp) {
	Node *tp = lp->head->next;
	while (tp != lp->tail)
	{
		printf("codf : %d, exp : %d\n", tp->codfficient, tp->exponet);
		tp = tp->next;
	}
}

void delete_node(List *lp) {
	Node *tp = lp->head->next;
	Node *cl;
	while (tp != lp->tail)
	{
		cl = tp;
		tp = tp->next;
		free(cl);
	}
	free(lp->head);
	free(lp->tail);
}
*/

/*--------------------------------------------------------------------------*/

/*
void input(FILE *);
void output(FILE *);

int main() {
	printf("2�� ����\n");
	FILE *p1 = fopen("read.txt", "w");
	if (p1 == NULL) {
		return 1;
	}
	printf("������ ���� �Ǿ����ϴ�.\n");
	input(p1);
	FILE *p2 = fopen("read.txt", "r");
	if (p2 == NULL) {
		printf("������ �����ϴ�.\n");
	}
	printf("������ ���� �Ǿ����ϴ�.\n");
	output(p2);
}

void input(FILE *p) {
	while (1)
	{
		char ch[20];
		fgets(ch, 20, stdin);
		fputs(ch, p);
		if (strcmp(ch, "exit\n")==0) {
			break;
		}
	}
	int res = fclose(p);
	if (res != 0) {
		printf("������ ������ �ʽ��ϴ�.\n");
	}
}

void output(FILE *p) {
	int i = 0;
	while (1) {
		char ch[20];
		fgets(ch, 20, p);
		fputs(ch, stdout);
		i++;
		if (strcmp(ch, "exit\n")==0) {
			break;
		}
	}
	printf("�� line �� : %d\n", i);
	int res = fclose(p);
	if (res != 0) {
		printf("������ ������ �ʽ��ϴ�.\n");
	}
}
*/

/*-------------------------------------------------------------------*/

/*
void input(FILE *, FILE *, FILE *);

int main() {
	printf("3�� ����\n");
	FILE * A = fopen("readA.txt", "r");
	if (A == NULL) {
		return 1;
	}
	printf("������ ���� �Ǿ����ϴ�.\n");
	FILE * B = fopen("readB.txt", "r");
	if (B == NULL) {
		return 1;
	}
	printf("������ ���� �Ǿ����ϴ�.\n");

	FILE * out = fopen("output.txt", "w");
	if (out == NULL) {
		return 1;
	}
	printf("������ ���� �Ǿ����ϴ�.\n");

	input(A, B, out);


	return 0;
}

void input(FILE *a, FILE *b, FILE *out) {
	char ch[20];
	while (1){
		void *res;
		res = fgets(ch, 20, a);
		if (res == NULL) {
			break;
		}
		fputs(ch, out);
	} 

	while (1)
	{
		void * res;
		res = fgets(ch, 20, b);
		if (res == NULL) {
			break;
		}
		fputs(ch, out);
	} 
	fclose(a);
	fclose(b);
	fclose(out);
}
*/