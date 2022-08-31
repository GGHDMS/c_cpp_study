#include <stdio.h> 
#include <malloc.h> 
#include "circularQueue.h" 

/*--------------------------------------------------------------------------------------
Function name	: createQueue - ����ť ���� �� �ʱ�ȭ �Լ�
Parameters		: qp - ť ����ü�� �ּ�
				  size - ť�� ũ��
Returns			: ���� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL createQueue(Queue * qp, int size)
{
	if (qp == NULL) {
		return FALSE;
	}
	qp->queue = (int *)calloc(size, sizeof(int));
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
BOOL enqueue(Queue * qp, int enqueData)
{
	if (qp == NULL) {
		return TRUE;
	}
	if (isQueueFull(qp) == TRUE) {
		return FALSE;
	}

	qp->queue[qp->rear] = enqueData;
	qp->rear = (qp->rear + 1) % qp->size;
	return TRUE;  // ���ϰ��� �����ϼ���.
}
/*--------------------------------------------------------------------------------------
Function name	: dequeue() - ť���� ������ �ϳ��� ����
Parameters		: qp - ť ����ü�� �ּ�
				  dequeData - ���� �����͸� ������ �������� �ּ�
Returns			: ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL dequeue(Queue * qp, int * dequeData)
{
	if (qp == NULL) {
		return TRUE;
	}
	if (isQueueEmpty(qp) == TRUE) {
		return FALSE;
	}
	*dequeData = qp->queue[qp->front];
	qp->front = (qp->front + 1) % qp->size;
	return TRUE;  // ���ϰ��� �����ϼ���.
}
/*--------------------------------------------------------------------------------------
Function name	: printQueue() - ť ���� ��� �����͸� ��� ��
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void printQueue(const Queue * qp)
{
	int i;
	i = qp->front;
	for (i; i != qp->rear; i = (i + 1) % qp->size) {
		printf("%5d", qp->queue[i]);
	}
	printf("\n");
	return;
}
/*--------------------------------------------------------------------------------------
Function name	: destroyQueue() - ť �Ҹ� �Լ�
Parameters		: qp - ť ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void destroyQueue(Queue * qp)
{
	if (qp == NULL) {
		return;
	}
	if (qp->queue != NULL) {
		free(qp->queue);
		qp->queue = NULL;
	}
	qp->front = 0;
	qp->rear = 0;
	qp->size = 0;
	return;
}
