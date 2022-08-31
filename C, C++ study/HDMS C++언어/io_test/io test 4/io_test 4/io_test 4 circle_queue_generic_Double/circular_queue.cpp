#include <stdio.h> 
#include <malloc.h> 
#include "circularQueue.h" 

/*--------------------------------------------------------------------------------------
Function name	: createQueue - ����ť ���� �� �ʱ�ȭ �Լ�
Parameters		: qp - ť ����ü�� �ּ�
				  size - ť�� ũ��
Returns			: ���� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL createQueue(Queue * qp, int size, size_t datasize)
{
	if (qp == NULL) {
		return FALSE;
	}
	qp->queue = (void *)calloc(size, datasize);
	if (qp->queue == NULL) {
		return FALSE;
	}
	qp->size = size;
	qp->front = 0;
	qp->rear = 0;
	return TRUE;  // ���ϰ��� �����ϼ���.	
}
/*--------------------------------------------------------------------------------------
Function name	: isQueueEmpty - ť�� ����ִ°� �˻�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ������ ��������� TRUE ����, ������� ������ FALSE ����
--------------------------------------------------------------------------------------*/
BOOL isQueueEmpty(const Queue *qp)
{
	if (qp == NULL) {
		return TRUE;
	}
	if (qp->front == qp->rear) {
		return TRUE;
	}
	else {
		return FALSE;
	}
	// ���ϰ��� �����ϼ���.
}
/*--------------------------------------------------------------------------------------
Function name	: isQueueFull - ť�� �����ִ°� �˻�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ���� ������ TRUE ����, �ƴϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL isQueueFull(const Queue *qp)
{
	if (qp == NULL) {
		return TRUE;
	}
	if (qp->front == (qp->rear +1) % qp -> size) {
		return TRUE;
	}
	else {
		return FALSE;
	} 
	// ���ϰ��� �����ϼ���.
}
/*--------------------------------------------------------------------------------------
Function name	: enqueue() - ť�� ������ �ϳ��� ������
Parameters		: qp - ť ����ü�� �ּ�
			  	  enqueData - ť�� ������ ������
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL enqueue(Queue * qp, void *np, size_t datasize, void(*memcpy)(void *p1, void *p2))
{
	if (qp == NULL) {
		return TRUE;
	}
	if (isQueueFull(qp) == TRUE) {
		return FALSE;
	}

	memcpy((char *)qp->queue + datasize * qp->rear, np);
	qp->rear = (qp->rear + 1) % qp->size;
	return TRUE;  // ���ϰ��� �����ϼ���.
}
/*--------------------------------------------------------------------------------------
Function name	: dequeue() - ť���� ������ �ϳ��� ����
Parameters		: qp - ť ����ü�� �ּ�
				  dequeData - ���� �����͸� ������ �������� �ּ�
Returns			: ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL dequeue(Queue * qp, void *np, size_t datasize, void(*memcpy)(void *p1, void *p2), void(*clear)(void *p))
{
	if (qp == NULL) {
		return TRUE;
	}
	if (isQueueEmpty(qp) == TRUE) {
		return FALSE;
	}
	memcpy(np , ((char *)qp->queue + datasize * qp->front));
	clear((char *)qp->queue + datasize * qp->front);
	qp->front = (qp->front + 1) % qp->size;
	return TRUE;  // ���ϰ��� �����ϼ���.
}
/*--------------------------------------------------------------------------------------
Function name	: printQueue() - ť ���� ��� �����͸� ��� ��
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void printQueue(const Queue * qp, size_t datasize, void (*print)(void *))
{
	int i;
	i = qp->front;
	for (i; i != qp->rear; i = (i + 1) % qp->size) {
		print((char *)(qp->queue) + i * datasize);
	}
	printf("\n");
	return;
}
/*--------------------------------------------------------------------------------------
Function name	: destroyQueue() - ť �Ҹ� �Լ�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void destroyQueue(Queue * qp, size_t datasize, void(*clear)(void *))
{
	int i;
	if (qp == NULL) {
		return;
	}
	if (qp->queue != NULL) {
		i = qp->front;
		for (i; i != qp->rear; i = (i + 1) % qp->size) {
			clear((char *)qp->queue + i * datasize);
		}
		free(qp->queue);
		qp->queue = NULL;
	}
	qp->front = 0;
	qp->rear = 0;
	qp->size = 0;
	return;
}
