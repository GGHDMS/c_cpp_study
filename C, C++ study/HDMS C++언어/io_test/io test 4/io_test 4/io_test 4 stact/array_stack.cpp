#include "arrayStack.h"
#include <stdio.h>
#include <malloc.h>
/*----------------------------------------------------------------------------------
Function name	: createStack - ������ ũ���� ������ �����ϴ� �Լ�
Parameters		: sp - ���ð��� ����ü�� �ּ�
				  size - ������ ũ��
Returns			: ���� - TRUE / ���� - FALSE
----------------------------------------------------------------------------------*/
BOOL createStack(Stack *sp, int size)
{
	if (sp == NULL) {
		return FALSE;
	}
	sp->stack = (int *)calloc(size, sizeof(int));
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
BOOL push(Stack *sp, int inData)
{
	if (sp == NULL) {
		return FALSE;
	}
	if (isStackFull(sp) == TRUE) {
		return FALSE;
	}
	sp->stack[sp->top++] = inData;
	//sp->top++;
	return TRUE;  // ���ϰ��� �������ּ���.
}
/*--------------------------------------------------------------------------------------
Function name	: pop - ���ÿ��� ������ �ϳ��� ����
Parameters		: sp - ���ð��� ����ü�� �ּ�
popData -  ���� �����͸� ������ �������� �ּ�
Returns			: ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
BOOL pop(Stack * sp, int *popData)
{
	if (sp == NULL) {
		return FALSE;
	}
	if (isStackEmpty(sp) == TRUE) {
		return FALSE;
	}
	//sp->top--;
	*popData = sp->stack[--sp -> top];
	return TRUE;  // ���ϰ��� �������ּ���.
}
/*--------------------------------------------------------------------------------------
Function name	: printStack - ������ ��� ������ ���(pop�ϸ� ������ ������� ���)
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void printStack(const Stack* sp)
{
	if (sp == NULL) {
		return;
	}
	int i = sp->top - 1;
	for (i; i >= 0; i--) {
		printf("%5d", sp->stack[i]);
	}
	printf("\n");
	return;
}
/*--------------------------------------------------------------------------------------
Function name	: destroyStack -  ���� �Ҹ� �Լ�
Parameters		: sp - ���ð��� ����ü�� �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sp)
{
	if (sp == NULL) {
		return;
	}
	if(sp->stack == NULL) {
		return;
	}
	free(sp->stack);
	sp->stack = NULL;
	sp->size = 0;
	sp->top = 0;
	return;
}
