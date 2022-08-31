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
	lp->head = (Node *)calloc(1, sizeof(Node)); // heda node ����
	if (lp->head == NULL) {
		return False;
	}
	lp->tail = (Node *)calloc(1, sizeof(Node)); // tail node ����
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
BOOL addFirst(List *lp, void *data, size_t dataSize, void(*memCpy)(void *p1, void *p2))
{
	// TODO

	return 0; // ���ϰ��� ������ �����ϼ���.
}
/*----------------------------------------------------------------------------------
Function name	: addLast - tail node �տ� �� node �߰�(���� ����)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
				  data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL addLast(List *lp, void *data, size_t dataSize, void(*memCpy)(void *, void *))
{
	Node * np;
	if (lp == NULL) {
		return False;
	}

	np = (Node *)calloc(1, sizeof(Node)+dataSize);
	if (np == NULL) {
		return False;
	}
	np->prev = lp->tail->prev;
	np->next = lp->tail;

	lp->tail->prev->next = np;
	//np->prev->next = np;
	lp->tail->prev = np;
	//np->next->prev = np;

	memCpy(np + 1, data); // Node ���ּҿ� ���� ����  
	lp->size++;

	return TRUE; // ���ϰ��� ������ �����ϼ���.
}
/*----------------------------------------------------------------------------------
Function name	: displayList - ����Ʈ ���� ��� ������ ���
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void displayList(List *lp, void(*dataprint)(void *))
{
	Node *tp;
	tp = lp->head->next; // ù �����ͳ�带 ����Ű�� ��.

	while (tp !=lp->tail) {
		//printf("%5d", tp->data);
		dataprint(tp + 1);
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
Node * searchNode(List *lp, void *data, int(*compare)(void *, void *))
{
	Node *tp;
	tp = lp->head->next;
	while (tp != lp->tail) {
		if (compare(data, tp + 1) == 0) {
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
BOOL removeNode(List *lp, void(*data), int (*compare)(void *, void *), void (*dataFree)(void *))
{
	if (lp == NULL) {
		return False;
	}

	Node * tp;
	tp = searchNode(lp, data, compare);
	if (tp == NULL) {
		return False;
	}
	tp->prev->next = tp->next;
	tp->next->prev = tp->prev;

	dataFree(tp + 1);
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
void sortList(List *lp, size_t datasize, int(*compare)(void *, void *), void(*memCpy)(void *, void *), void(*dataFree)(void *))
{
	Node *np, *tp;
	void *temp;
	if (lp == NULL) {
		return;
	}
	temp = calloc(datasize, sizeof(char));
	np = lp->head->next;
	while (np != lp->tail) {
		tp = np->next->next;
		while (tp != lp->tail) {
			if (compare(np + 1, tp + 1) > 0) {
				memCpy(temp, np + 1);
				memCpy(np + 1, tp + 1);
				memCpy(tp + 1, temp);
			}
			tp = tp->next;
		}
		np = np->next;
	}
	dataFree(temp);
	free(temp);
	return;
}
/*----------------------------------------------------------------------------------
Function name	: destroyList - ����Ʈ ���� ��� ���(head, tail ��� ����)�� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void destroyList(List *lp, void(*dataFree)(void *))
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
		dataFree(dp + 1); // �ΰ� �޸� ����
		free(dp); // Node + data ������ ����
		
	}
	free(lp->head);
	free(lp->tail);
	lp->head = lp->tail = NULL;
	lp->size = 0;
	return;
}
