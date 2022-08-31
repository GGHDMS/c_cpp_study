#include "doublyLinkedlist.h"
#include <stdio.h>  // printf(), scanf()
#include <stdlib.h>  // malloc(), free()
/*----------------------------------------------------------------------------------
Function name	: createList - 연결 리스트 초기화
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL createList(List *lp)
{
	if (lp == NULL) {
		return False;
	}
	lp->head = (Node *)malloc(sizeof(Node)); // heda node 생성
	if (lp->head == NULL) {
		return False;
	}
	lp->tail = (Node *)malloc(sizeof(Node)); // tail node 생성
	if (lp->tail == NULL) {
		free(lp->head); // 위에서 성공한 헤드노드 삭제
		return False;
	}
	lp->head->next = lp->tail;
	lp->tail->prev = lp->head;
	lp->head->prev = lp->head;
	lp->tail->next = lp->tail;

	lp->size = 0;

	return TRUE; // 리턴값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: addFirst - head node 뒤에 node 추가(역순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL addFirst(List *lp, int data)
{
	Node *np;
	if (lp == NULL) {
		return False;
	}

	np = (Node *)malloc(sizeof(Node));
	if (np == NULL) {
		return False;
	}

	np->next = lp->head->next;
	np->prev = lp->head->next->prev;

	lp->head->next = np;
	lp->head->next->prev = np;

	np->data = data;
	lp->size++;

	return TRUE; // 리턴값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: addLast - tail node 앞에 새 node 추가(정순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL addLast(List *lp, int data)
{
	Node * np;
	if (lp == NULL) {
		return False;
	}

	np = (Node *)malloc(sizeof(Node));
	if (np == NULL) {
		return False;
	}
	np->prev = lp->tail->prev;
	np->next = lp->tail;

	lp->tail->prev->next = np;
	//np->prev->next = np;
	lp->tail->prev = np;
	//np->next->prev = np;

	np->data = data;
	lp->size++;

	return TRUE; // 리턴값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: displayList - 리스트 내의 모든 데이터 출력
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void displayList(List *lp)
{
	Node *tp;
	tp = lp->head->next; // 첫 데이터노드를 가리키게 함.

	while (tp !=lp->tail) {
		printf("%5d", tp->data);
		tp = tp->next; // 다음 노드로 이동
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
Function name	: searchNode - data와 일치하는 첫 번째 node 검색
Parameters		: lp - 리스트 관리 구조체의 주소
data - 검색할 데이터
Returns			: 성공 - 검색된 노드의 주소 / 실패 - NULL pointer
----------------------------------------------------------------------------------*/
Node * searchNode(List *lp, int data)
{
	Node *tp;
	tp = lp->head->next;
	while (tp != lp->tail) {
		if (tp->data == data) {
			return tp;
		}
		tp = tp->next; // 다음 노드로 이동
	}

	return NULL; // 못찾으면 NULL return
}
/*----------------------------------------------------------------------------------
Function name	: removeNode - data와 일치하는 첫 번째 노드 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
data - 삭제할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL removeNode(List *lp, void *data)
{
	if (lp == NULL) {
		return False;
	}

	Node * tp;
	tp = searchNode(lp, data);
	if (tp == NULL) {
		return False;
	}
	tp->prev->next = tp->next;
	tp->next->prev = tp->prev;
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
	//	tp = tp->next; // 다음 노드로 이동
	//}

	//return False; // 리턴값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: sortList - 노드 정렬(오름차순)
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void sortList(List *lp)
{
	Node *tp;
	int i, j, calc;
	for (i = 0; i < lp->size - 1; i++) {
		tp = lp->head->next;
		for (j = 0; j < lp->size - 1 - i; j++) {
			if (tp->data > tp->next->data) {
				calc = tp->data;
				tp->data = tp->next->data;
				tp->next->data = calc;
			}
			tp = tp->next;
		}
	}
	return;
}
/*----------------------------------------------------------------------------------
Function name	: destroyList - 리스트 내의 모든 노드(head, tail 노드 포함)를 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void destroyList(List *lp)
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
		free(dp);
	}
	free(lp->head);
	free(lp->tail);
	lp->head = lp->tail = NULL;
	lp->size = 0;
	return;
}
