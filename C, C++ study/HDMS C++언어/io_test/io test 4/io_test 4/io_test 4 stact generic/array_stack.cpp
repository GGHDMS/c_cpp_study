#include "arrayStack.h"
#include <stdio.h>
#include <malloc.h>
/*----------------------------------------------------------------------------------
Function name	: createStack - 지정된 크기의 스택을 생성하는 함수
Parameters		: sp - 스택관리 구조체의 주소
				  size - 스택의 크기
Returns			: 성공 - TRUE / 실패 - FALSE
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
	return TRUE;  // 리턴값은 수정해주세요.
}
/*-----------------------------------------------------------------------------------
Function name	: isStackFull - 스택이 꽉 차있는지 검사
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 스택이 꽉 차있으면 TRUE, 아니면 FALSE 리턴
-----------------------------------------------------------------------------------*/
BOOL isStackFull(Stack *sp)
{
	if (sp == NULL) {
		return FALSE;
	}
	if (sp->size == sp->top) {
		return TRUE;
	}
	return FALSE;  // 리턴값은 수정해주세요.
}
/*-----------------------------------------------------------------------------------
Function name	: isStackEmpty - 스택이 완전히 비어있는지 검사
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 스택이 완전히 비어있으면 TRUE, 아니면 FALSE 리턴
-----------------------------------------------------------------------------------*/
BOOL isStackEmpty(Stack *sp)
{
	if (sp == NULL) {
		return FALSE;
	}
	if (sp->top == 0) {
		return TRUE;
	}
	return FALSE;  // 리턴값은 수정해주세요.
}
/*--------------------------------------------------------------------------------------
Function name	: push - 스택에 데이터 하나를 저장함
Parameters		: sp - 스택관리 구조체의 주소
inData - 스택에 저장할 데이터
Returns			: 성공적으로 저장하면 TRUE, 실패하면 FALSE 리턴
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
	return TRUE;  // 리턴값은 수정해주세요.
}
/*--------------------------------------------------------------------------------------
Function name	: pop - 스택에서 데이터 하나를 꺼냄
Parameters		: sp - 스택관리 구조체의 주소
popData -  꺼낸 데이터를 저장할 기억공간의 주소
Returns			: 성공적으로 꺼내면 TRUE, 실패하면 FALSE 리턴
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
	return TRUE;  // 리턴값은 수정해주세요.
}
/*--------------------------------------------------------------------------------------
Function name	: printStack - 스택의 모든 데이터 출력(pop하면 나오는 순서대로 출력)
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 없음
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
Function name	: destroyStack -  스택 소멸 함수
Parameters		: sp - 스택관리 구조체의 주소
Returns			: 없음
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
