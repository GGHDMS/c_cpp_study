//�ۼ��� �㼮�� HW1

#include<stdio.h>

void printAge(int);
void printHeight(double);

int main()
{
	char name[20] = "�㼮��";
	int age = 20;
	double height = 176.5;

	printf("����: %s\n", name);
	printAge(age);
	printHeight(height);

	return 0;
}

void printAge(int my_age)
{
	printf("����: %d\n", my_age);
}

void printHeight(double my_height)
{
	printf("Ű: %lf\n", my_height);
}