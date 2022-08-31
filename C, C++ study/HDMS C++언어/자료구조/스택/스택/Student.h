#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAX_STRING 100

class Student {
	int id;
	char name[MAX_STRING];
	char dept[MAX_STRING];
public:
	Student(int i = 0, const char* n = "", const char* d = "") { set(i, n, d); }
	void set(int i, const char* n, const char* d) {
		id = i;
		strcpy(name, n);
		strcpy(dept, d);
	}
	void display() {
		printf("학번:%-15d 성명:%-10s 학과:%-20s\n", id, name, dept);
	}
};