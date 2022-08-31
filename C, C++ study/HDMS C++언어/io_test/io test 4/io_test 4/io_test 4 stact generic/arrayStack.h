#pragma once
//enum BOOL { FALSE, TRUE };

#define FALSE (0)
#define TRUE (1)
typedef int BOOL;

typedef struct _stack {
	void *stack;		/* stack���� ���Ǵ� �����Ҵ� �迭�� ����Ű�� ������ ���� */
	int size;		/* ������ ũ��(size) */
	int top;		/* ������ ��,�ⱸ ��ġ���� ���� */
}Stack;

BOOL createStack(Stack *, int, int);		/* ���� �޸� �Ҵ� �� ��� �ʱ�ȭ �Լ� */
BOOL isStackFull(Stack *sPtr);		/* ������ �� ���ִ��� �˻� */
BOOL isStackEmpty(Stack *sPtr);		/* ������ ������ ����ִ°� �˻� */
BOOL push(Stack *sp, void *np, size_t datasize, void(*memcpy)(void *, void *));			/* ���ÿ� ������ �����ϴ� �Լ� */
BOOL pop(Stack * sp, void *np, size_t datasize, void(*memcpy)(void *, void*), void(*clear)(void *p));	/* ���ÿ��� �����͸� ������ �Լ� */
void printStack(const Stack*, size_t datasize, void(*print)(void *));		/* ���� ���� ��� �����͸� ����ϴ� �Լ� */
void destroyStack(Stack *, size_t datasize, void(*clear)(void *));			/* ���� �޸� ���� �Լ� */
