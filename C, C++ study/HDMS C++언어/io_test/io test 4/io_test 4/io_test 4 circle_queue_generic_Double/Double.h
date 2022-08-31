#pragma once
#pragma warning(disable : 4996)
#include <stdlib.h>
#include <stdio.h>

void doubleMemcpy(void *p1, void *p2); // p2가 가리키는 double형값을 p1이 가리키는 영역에 복사
void doubleClear(void *p); //부가 메모리 해제함
void doublePrint(void *p); //doulb 값 출력해 줌
int doubleCompare(void *p1, void *p2); // 값 비교하여 p1이 가리키는 값이 크면 1 같으면 0 작으면 -1

