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

BOOL createQueue(Queue * qp, int size, size_t datasize);		/* 큐 생성 및 초기화 함수 */
BOOL isQueueEmpty(const Queue *qp);			/* 큐가 완전히 비어있는가 */
BOOL isQueueFull(const Queue *qp);			/* 큐가 꽉차있는가 검사 */
BOOL enqueue(Queue * qp, void *np, size_t datasize, void(*memcpy)(void *p1, void *p2));	/* 큐에 데이터 하나를 저장 함 */
BOOL dequeue(Queue * qp, void *np, size_t datasize, void(*memcpy)(void *p1, void *p2), void(*clear)(void *p));	/* 큐에서 데이터 하나를 꺼냄 */
void printQueue(const Queue * qp, size_t datasize, void(*print)(void *));		/* 큐 내의 모든 데이터를 출력(dequeue하는 것은 아님) */
void destroyQueue(Queue * qp, size_t datasize, void(*clear)(void *));			/* 큐 소멸 함수 */
