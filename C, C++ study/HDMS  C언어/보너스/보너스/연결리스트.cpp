#pragma once
#include <stdio.h>  // printf(), scanf()
#include <stdlib.h>  // malloc(), free()

enum BOOL { FALSE, TRUE };
typedef struct _node Node;				/* ����ü ��� ���������� */
struct  _node {							/* ��� ����ü (�ڱ����� ����ü ���) */
	int data; 							/* ������ ���� : int�� ������ ���� */
	Node *next;							/* ������ ���� */
};
typedef  struct  _list { 				/* ���� ����Ʈ ���� ����ü */
	Node *head;							/* head pointer (head node ����Ŵ) */
	Node *tail; 						/* tail pointer (tail node ����Ŵ) */
	int size;							/* ���� ����Ʈ�� ũ�� - ���� data node�� ���� */
}List;

BOOL createList(List *lp);					/* ���� ����Ʈ �ʱ�ȭ */
BOOL addFirst(List *lp, int data);			/* head node �ڿ� node �߰�(���� ����) */
BOOL addLast(List *lp, int data);			/* tail node �տ� node �߰�(���� ����) */
void displayList(List *lp);					/* ����Ʈ ���� ��� ������ ��� */
BOOL removeNode(List *lp, int data);		/* data ��� ���� */
Node * searchNode(List *lp, int data);		/* data�� ��ġ�ϴ� node �˻� */
void sortList(List *lp);					/* ��� ���� - �������� */
void destroyList(List *lp);					/* ����Ʈ ���� ��� ��带 ���� */

/*----------------------------------------------------------------------------------
Function name	: createList - ���� ����Ʈ ���� �� �ʱ�ȭ
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL createList(List *lp)
{
	lp->head = (Node*)malloc(sizeof(Node));
	if ((lp->head) == NULL)return FALSE;
	lp->tail = (Node*)malloc(sizeof(Node));
	if ((lp->tail) == NULL)return FALSE;
	lp->head->next = lp->tail;
	lp->tail->next = lp->tail;
	lp->size = 0;
	return TRUE; // return ���� ������ �����ϼ���.
}

/*----------------------------------------------------------------------------------
Function name	: addFirst - head node �ڿ� node �߰�(���� ����)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL addFirst(List *lp, int data)
{
	// TODO

	return TRUE; // return ���� ������ �����ϼ���.
}
/*----------------------------------------------------------------------------------
Function name	: addLast - tail node �տ� �� node �߰�(���� ����)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
data - �߰��� ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL addLast(List *lp, int data)
{
	// TODO

	return TRUE; // return ���� ������ �����ϼ���.
}

/*----------------------------------------------------------------------------------
Function name	: displayList - ����Ʈ ���� ��� ������ ���
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void displayList(List *lp)
{
	// TODO

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
	// TODO

	return NULL; // return ���� ������ �����ϼ���.
}
/*----------------------------------------------------------------------------------
Function name	: removeNode - data�� ��ġ�ϴ� ù ��° ��� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
data - ������ ������
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL removeNode(List *lp, int data)
{
	// TODO

	return TRUE; // return ���� ������ �����ϼ���.
}
/*----------------------------------------------------------------------------------
Function name	: sortList - ��� ����(��������)
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void sortList(List *lp)
{
	// TODO

	return;
}
/*----------------------------------------------------------------------------------
Function name	: destroyList - ����Ʈ ���� ��� ���(head, tail ��� ����)�� ����
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void destroyList(List *lp)
{
	// TODO

	return;
}

