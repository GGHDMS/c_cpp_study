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
	lp->head = (Node *)calloc(1, sizeof(Node)); // heda node 생성
	if (lp->head == NULL) {
		return False;
	}
	lp->tail = (Node *)calloc(1, sizeof(Node)); // tail node 생성
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
BOOL addFirst(List *lp, void *data, size_t dataSize, void(*memCpy)(void *p1, void *p2))
{
	// TODO

	return 0; // 리턴값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: addLast - tail node 앞에 새 node 추가(정순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
				  data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL addLast(List *lp, void *data, size_t dataSize, void(*memCpy)(void *, void *))
{
	Node * np;
	if (lp == NULL) {
		return False;
	}

	np = (Node *)calloc(1, sizeof(Node)+dataSize);
	if (np == NULL) {
		return False;
	}
	np->prev = lp->tail->prev;
	np->next = lp->tail;

	lp->tail->prev->next = np;
	//np->prev->next = np;
	lp->tail->prev = np;
	//np->next->prev = np;

	memCpy(np + 1, data); // Node 뒷주소에 깊은 복사  
	lp->size++;

	return TRUE; // 리턴값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: displayList - 리스트 내의 모든 데이터 출력
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void displayList(List *lp, void(*dataprint)(void *))
{
	Node *tp;
	tp = lp->head->next; // 첫 데이터노드를 가리키게 함.

	while (tp !=lp->tail) {
		//printf("%5d", tp->data);
		dataprint(tp + 1);
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
Node * searchNode(List *lp, void *data, int(*compare)(void *, void *))
{
	Node *tp;
	tp = lp->head->next;
	while (tp != lp->tail) {
		if (compare(data, tp + 1) == 0) {
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
BOOL removeNode(List *lp, void(*data), int (*compare)(void *, void *), void (*dataFree)(void *))
{
	if (lp == NULL) {
		return False;
	}

	Node * tp;
	tp = searchNode(lp, data, compare);
	if (tp == NULL) {
		return False;
	}
	tp->prev->next = tp->next;
	tp->next->prev = tp->prev;

	dataFree(tp + 1);
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
void sortList(List *lp, size_t datasize, int(*compare)(void *, void *), void(*memCpy)(void *, void *), void(*dataFree)(void *))
{
	Node *np, *tp;
	void *temp;
	if (lp == NULL) {
		return;
	}
	temp = calloc(datasize, sizeof(char));
	np = lp->head->next;
	while (np != lp->tail) {
		tp = np->next->next;
		while (tp != lp->tail) {
			if (compare(np + 1, tp + 1) > 0) {
				memCpy(temp, np + 1);
				memCpy(np + 1, tp + 1);
				memCpy(tp + 1, temp);
			}
			tp = tp->next;
		}
		np = np->next;
	}
	dataFree(temp);
	free(temp);
	return;
}
/*----------------------------------------------------------------------------------
Function name	: destroyList - 리스트 내의 모든 노드(head, tail 노드 포함)를 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void destroyList(List *lp, void(*dataFree)(void *))
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
		dataFree(dp + 1); // 부가 메모리 해제
		free(dp); // Node + data 영역을 해제
		
	}
	free(lp->head);
	free(lp->tail);
	lp->head = lp->tail = NULL;
	lp->size = 0;
	return;
}
