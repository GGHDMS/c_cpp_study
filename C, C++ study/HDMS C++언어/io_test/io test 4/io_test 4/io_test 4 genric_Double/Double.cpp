#include "Double.h"

// 부가메모리 해제 함수
void doubleClear(void *p) {
	*(double *)p = 0;
}


// double 변수 copy 함수
void doubleMemcpy(void *p1, void *p2) {
	*(double *)p1 = *(double *)p2;
}

// double 변수 출력 함수
void doublePrint(void *p) {
	printf("%.2lf\n", *(double *)p);
}

// double 변수 비교 함수
int doubleCompare(void *p1, void *p2) {
	if (*(double *)p1 > *(double *)p2) {
		return 1;
	}
	else if (*(double *)p1 == *(double *)p2) {
		return 0;
	}
	else {
		return - 1;
	}
}

