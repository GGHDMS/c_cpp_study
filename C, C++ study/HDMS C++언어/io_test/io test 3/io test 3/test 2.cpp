#include<stdio.h>
void forEach(void *start, void *end, int, void(*workData)(void *vp));
void showInt(void *vp);
void showDouble(void *vp);
void showStudent(void *vp);
void inputInt(void *vp);
void inputDouble(void *vp);
void myFlush();

typedef struct _student
{
	char name[20];
	int id;
}Student;

int main()
{
	int   x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	double   y[5] = { 1.1,2.2,3.3,4.4,5.5 };
	Student ary[3] = { {"홍길동", 20},{"이순신", 22},{"강감찬", 23} };

	printf("[ x 배열 출력하기 ]\n");
	forEach(x, x + 10, sizeof(int), showInt);

	printf("\n[ y 배열 출력하기 ]\n");
	forEach(y, y + 5, sizeof(double), showDouble);

	printf("\n[ ary 배열 출력하기 ]\n");
	forEach(ary, ary + 3, sizeof(Student), showStudent);

	printf("\n[ y 배열 입력 받기 ]\n");
	forEach(y, y + 5, sizeof(double), inputDouble);

	printf("\n[ y 배열 출력하기 ]\n");
	forEach(y, y + 5, sizeof(double), showDouble);
	return 0;
}
void forEach(void *start, void *end, int size, void(*workData)(void *vp))
{
	while (start != end)
	{
		workData(start);
		start = (char *)start + size;
	}
}

void showInt(void *vp)
{
	printf("num=%d\n", *(int *)vp);
}

void showDouble(void *vp) {
	printf("num=%lf\n", *(double *)vp);
}

void showStudent(void *vp) {
	Student *sp = (Student *)vp;
	printf("%s(%d세)\n", sp->name, sp->id);
	//printf("%s(%d세)\n", ((Student*)vp) ->name, ((Student*)vp)->id);
}

void inputInt(void *vp)
{
	int res;
	printf("정수값 입력 : ");
	while ((res = scanf("%d", vp)) != 1)
	{
		printf("잘못 입력하셨습니다. 다시 입력 : ");
		myFlush();
	}
	return;
}

void inputDouble(void *vp)
{
	int res;
	printf("실수값 입력 : ");
	while ((res = scanf("%lf", vp)) != 1)
	{
		printf("잘못 입력하셨습니다. 다시 입력 : ");
		myFlush();
	}
	return;
}
void myFlush()
{
	while (getchar() != '\n');
}
