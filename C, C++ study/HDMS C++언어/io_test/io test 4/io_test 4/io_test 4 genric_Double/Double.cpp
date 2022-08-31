#include "Double.h"

// �ΰ��޸� ���� �Լ�
void doubleClear(void *p) {
	*(double *)p = 0;
}


// double ���� copy �Լ�
void doubleMemcpy(void *p1, void *p2) {
	*(double *)p1 = *(double *)p2;
}

// double ���� ��� �Լ�
void doublePrint(void *p) {
	printf("%.2lf\n", *(double *)p);
}

// double ���� �� �Լ�
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

