// �ۼ��� �㼮�� HW17

#include<stdio.h>
#include<string.h>

double height;
char name[20], gender;
int len;

int main()
{
	printf("���� �Է�:");
	fgets(name, 20, stdin);
	len = strlen(name);
	name[len - 1] = '\0';
	printf("Ű �Է�:");
	scanf("%lf", &height);
	printf("�����Է�(M/F):");
	scanf(" %c", &gender);
	if (gender == 'M') {
		printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�.\n", name, height);
	}
	if (gender == 'F'){
		printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�.\n", name, height);
	}
	return 0;
}

