//�ۼ��� �㼮�� HW12

#include<stdio.h>
char name[20];

int main()
{	

	printf("�̸��� �Է��Ͻÿ�:");
	scanf("%s", name);
	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"", name);
}