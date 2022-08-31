#pragma once 
//enum BOOL { FALSE, TRUE };

#define FALSE (0)
#define TRUE (1)
typedef int BOOL;

typedef struct _queue {
	void *queue;
	int size;
	int front, rear;
}Queue;

BOOL createQueue(Queue * qp, int size, size_t datasize);		/* ť ���� �� �ʱ�ȭ �Լ� */
BOOL isQueueEmpty(const Queue *qp);			/* ť�� ������ ����ִ°� */
BOOL isQueueFull(const Queue *qp);			/* ť�� �����ִ°� �˻� */
BOOL enqueue(Queue * qp, void *np, size_t datasize, void(*memcpy)(void *p1, void *p2));	/* ť�� ������ �ϳ��� ���� �� */
BOOL dequeue(Queue * qp, void *np, size_t datasize, void(*memcpy)(void *p1, void *p2), void(*clear)(void *p));	/* ť���� ������ �ϳ��� ���� */
void printQueue(const Queue * qp, size_t datasize, void(*print)(void *));		/* ť ���� ��� �����͸� ���(dequeue�ϴ� ���� �ƴ�) */
void destroyQueue(Queue * qp, size_t datasize, void(*clear)(void *));			/* ť �Ҹ� �Լ� */
