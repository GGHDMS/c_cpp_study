//작성자 허석문 HW1

#include<stdio.h>

void printAge(int);
void printHeight(double);

int main()
{
	char name[20] = "허석문";
	int age = 20;
	double height = 176.5;

	printf("성명: %s\n", name);
	printAge(age);
	printHeight(height);

	return 0;
}

void printAge(int my_age)
{
	printf("나이: %d\n", my_age);
}

void printHeight(double my_height)
{
	printf("키: %lf\n", my_height);
}