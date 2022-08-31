#include "Person.h"

// Person ����ü�� �ΰ��޸� ���� �Լ�
void personClear(void *p) {
	if (((Person*)p)->name != NULL) {
		free(((Person *)p)->name);
	}
	((Person*)p)->name = NULL; // �޸� ���� �� name����� NULL �����ͷ� �ٲ�
	((Person*)p)->age = 0;
	strcpy(((Person *)p)->phoneNumber, "");
}


// Person ����ü deep copy �Լ�
void personMemcpy(void *p1, void *p2) {
	personClear(p1); // name ����� �޸� ����
	if (((Person *)p2)->name != NULL) {
		((Person *)p1)->name = (char *)calloc(1, strlen(((Person *)p2)->name) + 1);
		if (((Person *)p1)->name == NULL) {
			return;
		}
		strcpy(((Person *)p1)->name, ((Person *)p2)->name);
	}
	((Person *)p1)->age = ((Person *)p2)->age;
	strcpy(((Person *)p1)->phoneNumber, ((Person *)p2)->phoneNumber);
}

// Person ����ü ��� �Լ�
void personPrint(void *p) {
	printf("���� : %s / ���� : %d / ��ȭ��ȣ : %s\n", ((Person *)p)->name, ((Person *)p)->age, ((Person *)p)->phoneNumber);
}

// Person����ü name ���  �� �Լ�
int personNameCompare(void *p1, void *p2) {
	return strcmp(((Person *)p1)->name, ((Person *)p2)->name);
}

// ���̸� ���Ͽ� p1�� ����Ű�� ���̰� ũ�� 1, ������ 0, ������ 1 ����
int personAgeCompare(void *p1, void *p2) {
	if (((Person *)p1)->age > ((Person *)p2)->age) {
		return 1;
	}
	else if (((Person *)p1)->age == ((Person *)p2)->age){
		return 0;
	}
	else{
		return -1;
	}
}

// ����� ���̸� ���Ͽ� ������ 0, �ٸ��� -1 ����
int personCompare(void *p1, void *p2) {
	if (personAgeCompare(p1, p2) == 0 && personNameCompare(p1, p2) == 0) {
		return 0;
	}
	else {
		return -1;
	}
}


