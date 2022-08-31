#pragma once
#include <stdio.h>  // printf(), scanf()
#include <stdlib.h>  // malloc(), free()

enum BOOL { FALSE, TRUE };
typedef struct _node Node;				/* 구조체 노드 형명재지정 */
struct  _node {							/* 노드 구조체 (자기참조 구조체 사용) */
	int data; 							/* 데이터 영역 : int형 데이터 저장 */
	Node *next;							/* 포인터 영역 */
};
typedef  struct  _list { 				/* 연결 리스트 관리 구조체 */
	Node *head;							/* head pointer (head node 가리킴) */
	Node *tail; 						/* tail pointer (tail node 가리킴) */
	int size;							/* 연결 리스트의 크기 - 실제 data node의 개수 */
}List;

BOOL createList(List *lp);					/* 연결 리스트 초기화 */
BOOL addFirst(List *lp, int data);			/* head node 뒤에 node 추가(역순 저장) */
BOOL addLast(List *lp, int data);			/* tail node 앞에 node 추가(정순 저장) */
void displayList(List *lp);					/* 리스트 내의 모든 데이터 출력 */
BOOL removeNode(List *lp, int data);		/* data 노드 삭제 */
Node * searchNode(List *lp, int data);		/* data와 일치하는 node 검색 */
void sortList(List *lp);					/* 노드 정렬 - 오름차순 */
void destroyList(List *lp);					/* 리스트 내의 모든 노드를 삭제 */

/*----------------------------------------------------------------------------------
Function name	: createList - 연결 리스트 생성 및 초기화
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL createList(List *lp)
{
	lp->head = (Node*)malloc(sizeof(Node));
	if ((lp->head) == NULL)return FALSE;
	lp->tail = (Node*)malloc(sizeof(Node));
	if ((lp->tail) == NULL)return FALSE;
	lp->head->next = lp->tail;
	lp->tail->next = lp->tail;
	lp->size = 0;
	return TRUE; // return 값을 적절히 수정하세요.
}

/*----------------------------------------------------------------------------------
Function name	: addFirst - head node 뒤에 node 추가(역순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL addFirst(List *lp, int data)
{
	// TODO

	return TRUE; // return 값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: addLast - tail node 앞에 새 node 추가(정순 저장)
Parameters		: lp - 리스트 관리 구조체의 주소
data - 추가할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL addLast(List *lp, int data)
{
	// TODO

	return TRUE; // return 값을 적절히 수정하세요.
}

/*----------------------------------------------------------------------------------
Function name	: displayList - 리스트 내의 모든 데이터 출력
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void displayList(List *lp)
{
	// TODO

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
	// TODO

	return NULL; // return 값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: removeNode - data와 일치하는 첫 번째 노드 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
data - 삭제할 데이터
Returns			: 성공 - TRUE / 실패 - FALSE
----------------------------------------------------------------------------------*/
BOOL removeNode(List *lp, int data)
{
	// TODO

	return TRUE; // return 값을 적절히 수정하세요.
}
/*----------------------------------------------------------------------------------
Function name	: sortList - 노드 정렬(오름차순)
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void sortList(List *lp)
{
	// TODO

	return;
}
/*----------------------------------------------------------------------------------
Function name	: destroyList - 리스트 내의 모든 노드(head, tail 노드 포함)를 삭제
Parameters		: lp - 리스트 관리 구조체의 주소
Returns			: 없음
----------------------------------------------------------------------------------*/
void destroyList(List *lp)
{
	// TODO

	return;
}

