#include "doublyLinkedlist.h"
#include <stdio.h>  // printf(), scanf()
#include <stdlib.h>  // malloc(), free()
/*----------------------------------------------------------------------------------
Function name	: createList - ���� ����Ʈ �ʱ�ȭ
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL createList(List *lp)
{
	if (lp == NULL) {
		return False;
	}
	lp->head = (Node *)malloc(sizeof(Node)); // heda node ����
	if (lp->head == NULL) {
		return False;
	}
	lp->tail = (Node *)malloc(sizeof(Node)); // tail node ����
	if (lp->tail == NULL) {
		free(lp->head); // ������ ������ ����� ����
		return False;
	}
	lp->head->next = lp->tail;
	lp->tail->prev = lp->head;
	lp->head->prev = lp->head;
	lp->tail->next = lp->tail;

	lp->size = 0;

	return TRUE; // ���ϰ��� ������ �����ϼ���.
}
/*----------------------------------------------------------------------------------
Function name	: addFirst - head node �ڿ� node �߰�(���� ����)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL addFirst(List *lp, int data)
{
	Node *np;
	if (lp == NULL) {
		return False;
	}

	np = (Node *)malloc(sizeof(Node));
	if (np == NULL) {
		return False;
	}

	np->next = lp->head->next;
	np->prev = lp->head->next->prev;

	lp->head->next = np;
	lp->head->next->prev = np;

	np->data = data;
	lp->size++;

	return TRUE; // ���ϰ��� ������ �����ϼ���.
}
/*----------------------------------------------------------------------------------
Function name	: addLast - tail node �տ� �� node �߰�(���� ����)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL addLast(List *lp, int data)
{
	Node * np;
	if (lp == NULL) {
		return False;
	}

	np = (Node *)malloc(sizeof(Node));
	if (np == NULL) {
		return False;
	}
	np->prev = lp->tail->prev;
	np->next = lp->tail;

	lp->tail->prev->next = np;
	//np->prev->next = np;
	lp->tail->prev = np;
	//np->next->prev = np;

	np->data = data;
	lp->size++;

	return TRUE; // ���ϰ��� ������ �����ϼ���.
}
/*----------------------------------------------------------------------------------
Function name	: displayList - ����Ʈ ���� ��� ������ ���
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void displayList(List *lp)
{
	Node *tp;
	tp = lp->head->next; // ù �����ͳ�带 ����Ű�� ��.

	while (tp !=lp->tail) {
		printf("%5d", tp->data);
		tp = tp->next; // ���� ���� �̵�
	}
	printf("\n");

	/*tp = lp->head->next;
	int i;
	for (i = 0; i < lp->size; i++) {
		printf("%5d", tp->data);
		tp = tp->next;
	}
	printf("\n");*/
	return;
}
/*----------------------------------------------------------------------------------
Function name	: searchNode - data�� ��ġ�ϴ� ù ��° node �˻�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
data - �˻��� ������
Returns			: ���� - �˻��� ����� �ּ� / ���� - NULL pointer
----------------------------------------------------------------------------------*/
Node * searchNode(List *lp, int data)
{
	Node *tp;
	tp = lp->head->next;
	while (tp != lp->tail) {
		if (tp->data == data) {
			return tp;
		}
		tp = tp->next; // ���� ���� �̵�
	}

	return NULL; // ��ã���� NULL return
}
/*----------------------------------------------------------------------------------
Function name	: removeNode - data�� ��ġ�ϴ� ù ��° ��� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
data - ������ ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL removeNode(List *lp, void *data)
{
	if (lp == NULL) {
		return False;
	}

	Node * tp;
	tp = searchNode(lp, data);
	if (tp == NULL) {
		return False;
	}
	tp->prev->next = tp->next;
	tp->next->prev = tp->prev;
	free(tp);
	lp->size--;
	return TRUE;

	//tp = lp->head->next;
	//while (tp != lp->tail) {
	//	if (tp->data == data) {
	//		tp->prev->next = tp->next;
	//		tp->next->prev = tp->prev;
	//		free(tp);
	//		lp->size--;
	//		return TRUE;
	//	}
	//	tp = tp->next; // ���� ���� �̵�
	//}

	//return False; // ���ϰ��� ������ �����ϼ���.
}
/*----------------------------------------------------------------------------------
Function name	: sortList - ��� ����(��������)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void sortList(List *lp)
{
	Node *tp;
	int i, j, calc;
	for (i = 0; i < lp->size - 1; i++) {
		tp = lp->head->next;
		for (j = 0; j < lp->size - 1 - i; j++) {
			if (tp->data > tp->next->data) {
				calc = tp->data;
				tp->data = tp->next->data;
				tp->next->data = calc;
			}
			tp = tp->next;
		}
	}
	return;
}
/*----------------------------------------------------------------------------------
Function name	: destroyList - ����Ʈ ���� ��� ���(head, tail ��� ����)�� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void destroyList(List *lp)
{
	if (lp == NULL) {
		return;
	}

	Node *tp;
	Node *dp;
	tp = lp->head->next;
	
	while (tp != lp->tail)
	{
		dp = tp;
		tp = tp->next;
		free(dp);
	}
	free(lp->head);
	free(lp->tail);
	lp->head = lp->tail = NULL;
	lp->size = 0;
	return;
}
