#include "arrayStack.h"
#include <stdio.h>
#include <malloc.h>
/*----------------------------------------------------------------------------------
Function name	: createStack - ������ ũ���� ������ �����ϴ� �Լ�
Parameters		: sp - ���ð��� ����ü�� �ּ�
				  size - ������ ũ��
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL createStack(Stack *sp, int size, int size_t)
{
	if (sp == NULL) {
		return FALSE;
	}
	sp->stack = (void *)calloc(size, size_t);
	if (sp->stack == NULL) {
		return FALSE;
	}
	sp->size = size;
	sp->top = 0;
	return TRUE;  // ���ϰ��� �������ּ���.
}
/*-----------------------------------------------------------------------------------
Function name	: isStackFull - ������ �� ���ִ��� �˻�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ������ �� �������� TRUE, �ƴϸ� FALSE ����
-----------------------------------------------------------------------------------*/
BOOL isStackFull(Stack *sp)
{
	if (sp == NULL) {
		return FALSE;
	}
	if (sp->size == sp->top) {
		return TRUE;
	}
	return FALSE;  // ���ϰ��� �������ּ���.
}
/*-----------------------------------------------------------------------------------
Function name	: isStackEmpty - ������ ������ ����ִ��� �˻�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ������ ������ ��������� TRUE, �ƴϸ� FALSE ����
-----------------------------------------------------------------------------------*/
BOOL isStackEmpty(Stack *sp)
{
	if (sp == NULL) {
		return FALSE;
	}
	if (sp->top == 0) {
		return TRUE;
	}
	return FALSE;  // ���ϰ��� �������ּ���.
}
/*--------------------------------------------------------------------------------------
Function name	: push - ���ÿ� ������ �ϳ��� ������
Parameters		: sp - ���ð��� ����ü�� �ּ�
inData - ���ÿ� ������ ������
Returns			: ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL push(Stack *sp, void *np, size_t datasize, void (*dataMemcpy)(void *, void *))
{
	if (sp == NULL) {
		return FALSE;
	}
	if (isStackFull(sp) == TRUE) {
		return FALSE;
	}
	dataMemcpy((char *)sp->stack + datasize * sp->top, np);
	sp->top++;
	return TRUE;  // ���ϰ��� �������ּ���.
}
/*--------------------------------------------------------------------------------------
Function name	: pop - ���ÿ��� ������ �ϳ��� ����
Parameters		: sp - ���ð��� ����ü�� �ּ�
popData -  ���� �����͸� ������ �������� �ּ�
Returns			: ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL pop(Stack * sp, void *np, size_t datasize, void (*memcpy)(void *, void *), void (*clear)(void *p))
{
	if (sp == NULL) {
		return FALSE;
	}
	if (isStackEmpty(sp) == TRUE) {
		return FALSE;
	}
	sp->top--;
	memcpy(np, (char *)sp -> stack + datasize * sp->top);
	clear((char *)sp -> stack + sp -> top * datasize);
	return TRUE;  // ���ϰ��� �������ּ���.
}
/*--------------------------------------------------------------------------------------
Function name	: printStack - ������ ��� ������ ���(pop�ϸ� ������ ������� ���)
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void printStack(const Stack* sp, size_t datasize, void(*print)(void *))
{
	if (sp == NULL) {
		return;
	}
	int i = sp->top - 1;
	for (i; i >= 0; i--) {
		print((char *)sp->stack + datasize * i);
	}
	printf("\n");
	return;
}
/*--------------------------------------------------------------------------------------
Function name	: destroyStack -  ���� �Ҹ� �Լ�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sp, size_t datasize, void(* clear)(void *))
{
	int i;
	if (sp == NULL) {
		return;
	}
	if(sp->stack == NULL) {
		return;
	}
	i = sp->size - 1;
	for (i; i >= 0; i--) {
		clear((char *)sp + datasize * i);
	}
	free(sp->stack);
	sp->stack = NULL;
	sp->size = 0;
	sp->top = 0;
	return;
}
