//�ۼ��� �㼮�� HW9

#include<stdio.h>

int input();

int main()
{
	int num;
	num = input();
	printf("�Էµ� ���� 8������ %#o�Դϴ�.", num);
	printf("�Էµ� ���� 16������ %#x�Դϴ�.", num);
	return 0;
}

int input()
{	
	int name;
	printf("������ �Է��ϼ���:");
	scanf("%d", &name);
	return name;
}

