#include <stdio.h>
#include <string.h>
void *find(void *begin, void *end, void *value, size_t size, int(*compareData)(void *, void *));
int compareInt(void *vp1, void *vp2);     // vp1�� ����Ű�� ���� ũ�� 1, ������ 0, ������ -1 ����
int compareDouble(void *vp1, void *vp2);  // vp1�� ����Ű�� ���� ũ�� 1, ������ 0, ������ -1 ����
int comparePerson(void *vp1, void *vp2);

typedef struct _person {
	char name[20];
	int age;

}Person;

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	double  y[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	Person ary[3] = { {"�̻���", 20}, {"������", 25}, {"�λ���", 23} };

	int number = 5;
	double dNumber = 5.5;
	Person fData = { "������", 0 };

	int *ip;
	double *dp;
	Person *pp;

	pp = (Person *)find(ary, ary + 3, &fData, sizeof(Person), comparePerson);
	if (pp == ary + 3) { printf("not find\n"); }
	else { printf("find data = %s(%d��)\n", pp->name, pp->age); }

	ip = (int *)find(x, x + 10, &number, sizeof(int), compareInt);

	if (ip == x + 10) { printf("not find\n"); }
	else { printf("find data = %d\n", *ip); }

	dp = (double *)find(y, y + 5, &dNumber, sizeof(double), compareDouble);
	if (dp == y + 5) { printf("not find\n"); }
	else { printf("find data = %lf\n", *dp); }

	return 0;
}
int compareInt(void *vp1, void *vp2) {     // vp1�� ����Ű�� ���� ũ�� 1, ������ 0, ������ -1 ����
	if (*(int *)vp1 > *(int *)vp2) {
		return 1;
	}
	else if (*(int *)vp1 == *(int *)vp2) {
		return 0;
	}
	else {
		return -1;
	}
}
int compareDouble(void *vp1, void *vp2) { // vp1�� ����Ű�� ���� ũ�� 1, ������ 0, ������ -1 ����
	if (*(double *)vp1 > *(double *)vp2) {
		return 1;
	}
	else if (*(double *)vp1 == *(double *)vp2) {
		return 0;
	}
	else {
		return -1;
	}
}
int comparePerson(void *vp1, void*vp2) {
	return strcmp(((Person *)vp1)->name, ((Person *)vp2)->name);
}

void *find(void *begin, void *end, void *value, size_t size, int(*compareData)(void *, void *))
{
	while (begin != end && compareData(begin, value) != 0) {
		begin = (char *)begin + size;
	}

	return begin;

}