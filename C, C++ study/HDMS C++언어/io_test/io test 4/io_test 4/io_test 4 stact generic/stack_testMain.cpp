#include "arrayStack.h"
#include <stdio.h>
#include "Person.h"

int menu(const char **mList, size_t menuCnt);	/* �޴� ��� �� �޴���ȣ �Է� �Լ� */
void mInput(Stack *sp);			/* �Է¸޴� ó�� �Լ� */
void myDelete(Stack *sp);		/* �����޴� ó�� �Լ� */
void mOutput(Stack *sp);		/* ��¸޴� ó�� �Լ� */
void myflush();					/* �Է� ���� flush �Լ� */
/*----------------------------------------------------------------------------------
Function name	: main
----------------------------------------------------------------------------------*/
int main()
{
	Stack stk;		/* ���û���*/
	const char *menuList[] = { "�Է��ϱ�", "�����ϱ�", "����ϱ�", "����" }; /* �޴� ����Ʈ*/
	int menuCnt;	/* �޴����� ���庯��*/
	int menuNum;	/* �޴���ȣ ���庯��*/

	if (createStack(&stk, 5, sizeof(Person)) == FALSE) { /* ���� �ʱ�ȭ*/
		return 1;
	}
	menuCnt = sizeof(menuList) / sizeof(menuList[0]);  /* �޴� ���� ����ϱ�*/

	while (1)
	{
		menuNum = menu(menuList, menuCnt);
		if (menuNum == menuCnt)  /* ����޴� ���� �� �ݺ��� Ż���ϱ�*/
		{
			break;
		}
		switch (menuNum)
		{
		case 1: mInput(&stk);  break;
		case 2: myDelete(&stk); break;
		case 3: mOutput(&stk); /* stack���� ��� ������ ����ϱ�*/
		}
	}
	destroyStack(&stk, sizeof(Person), personClear);
	return 0;
}
/*--------------------------------------------------------------------------------------
Function name	: mInput() - ���ÿ� �����͸� �ݺ������� �Է���
Parameters		: sp - ������ �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void mInput(Stack *sp)
{
	//int data;
	char tname[20];
	Person np = {NULL, 0, ""};

	while (1) {
		printf("Push�� �̸��� �Է��Ͻÿ�(end �Է� �� ����) : ");
		scanf("%s", tname);
		if (strcmp(tname, "end") == 0) { /* end �ԷµǸ� while���� ��������*/
			break;
		}
		np.name = (char *)calloc(strlen(tname)+1, sizeof(char));
		strcpy(np.name, tname);
		printf("Push�� ���̸� �Է��Ͻÿ� : ");
		scanf("%d", &np.age);
		printf("Push�� ��ȭ��ȣ�� �Է��Ͻÿ� : ");
		scanf("%s", np.phoneNumber);
		if (push(sp, &np, sizeof(Person), personMemcpy) == FALSE)
			printf("push ����!\n");
		free(np.name);
	}
}
/*--------------------------------------------------------------------------------------
Function name	: myDelete() - ������ �����͸� �ݺ������� ����
Parameters		: sp - ������ �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void myDelete(Stack *sp)
{
	int i;
	int cnt;		/* pop�� Ƚ���� �Է¹޾� ������ ����*/
	//int popData;	/* pop�� �����͸� ������ ����*/
	BOOL res;		/* pop()�Լ��� ���ϰ��� ������ ����*/
	Person np = { NULL, 0, "" };

	printf("Stack���� �����͸� pop�� Ƚ���� �Է��Ͻÿ�: ");
	scanf("%d", &cnt);
	for (i = 0; i<cnt; i++) {
		res = pop(sp, &np, sizeof(Person), personMemcpy, personClear);
		if (res == TRUE)  /* ���������� pop �۾�������������*/
		{
			personPrint(&np);
		}
		else
			printf("pop ����!\n");
	}
}
/*--------------------------------------------------------------------------------------
Function name	: mOutput - ������ ��� ������ ��� �ϱ�
Parameters		: sp - ������ �ּ�
Returns			: ����
--------------------------------------------------------------------------------------*/
void mOutput(Stack *sp)
{
	printStack(sp, sizeof(Person), personPrint);
}
/*--------------------------------------------------------------------------------------
Function name	: menu() - �޴��� ����ϰ� �޴���ȣ�� �Է¹޾� ������
Parameters		: menuLIst - �޴������ ���ڿ�
				  menuCnt  - �޴�����
Returns			: ���õȸ޴���ȣ
--------------------------------------------------------------------------------------*/
int menu(const char **menuList, size_t menuCnt)
{
	size_t i;
	size_t menuNum = 0;	/* �Էµ� �޴���ȣ ���� ����*/
	int res;			/* scanf()�Լ��� ���ϰ� ���� ����*/
	for (i = 0; i<menuCnt; i++)
	{
		printf("%d. %s\n", i + 1, menuList[i]);
	}

	while (menuNum<1 || menuNum>menuCnt)  /* �޴���ȣ �������� ��ȣ�� �Էµɶ� ���� �ݺ�*/
	{
		printf("# �޴���ȣ�� �Է��ϼ��� : ");
		res = scanf("%u", &menuNum);
		if (res != 1)  /* ������ �Էµ��� �ʾ�����*/
		{
			myflush();  /* �Է¹��� ����*/
			continue;
		}
	}
	return menuNum;
}
/*----------------------------------------------------------------------------------
Function name	: myflush - �Է� ���� ���� ��� ������ ����� �Լ�
Parameters		: ����
Returns			: ����
----------------------------------------------------------------------------------*/
void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}
