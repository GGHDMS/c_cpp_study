//�ۼ��� �㼮�� HW13

#include<stdio.h>
#include<string.h>

int main()
{
	char f_name[20], name[20];
	printf("���� �Է��ϼ���:");
	scanf("%s", f_name);
	printf("�̸��� �Է��ϼ���:");
	scanf("%s", name);
	printf("%s %s\n", f_name, name);
	int num1 = strlen(f_name), num2 = strlen(name);
	printf("%*d %*d", num1, num1, num2, num2);
	return 0;
}