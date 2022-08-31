#include "Person.h"

// Person 구조체의 부가메모리 해제 함수
void personClear(void *p) {
	if (((Person*)p)->name != NULL) {
		free(((Person *)p)->name);
	}
	((Person*)p)->name = NULL; // 메모리 해제 후 name멤버를 NULL 포인터로 바꿈
	((Person*)p)->age = 0;
	strcpy(((Person *)p)->phoneNumber, "");
}


// Person 구조체 deep copy 함수
void personMemcpy(void *p1, void *p2) {
	personClear(p1); // name 멤버의 메모리 해제
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

// Person 구조체 출력 함수
void personPrint(void *p) {
	printf("성명 : %s / 나이 : %d / 전화번호 : %s\n", ((Person *)p)->name, ((Person *)p)->age, ((Person *)p)->phoneNumber);
}

// Person구조체 name 멤버  비교 함수
int personNameCompare(void *p1, void *p2) {
	return strcmp(((Person *)p1)->name, ((Person *)p2)->name);
}

// 나이를 비교하여 p1이 가리키는 나이가 크면 1, 같으면 0, 작으면 1 리턴
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

// 성명과 나이를 비교하여 같으면 0, 다르면 -1 리턴
int personCompare(void *p1, void *p2) {
	if (personAgeCompare(p1, p2) == 0 && personNameCompare(p1, p2) == 0) {
		return 0;
	}
	else {
		return -1;
	}
}


