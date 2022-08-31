#include <stdio.h>
#include "doublyLinkedlist.h"
#include "Person.h"

int menu(const char **mList, size_t menuCnt);	/* �޴� ��� �� �޴���ȣ �Է� �Լ� */
void mInput(List *lp);		/* �Է¸޴� ó�� �Լ� */
void mOutput(List *lp);		/* ��¸޴� ó�� �Լ� */
void mSearch(List *lp);		/* �˻��޴� ó�� �Լ� */
void mDelete(List *lp);		/* �����޴� ó�� �Լ� */
void mSort(List *lp);		/* ���ĸ޴� ó�� �Լ� */
void myflush();				/* �Է� ���� flush �Լ� */
/*----------------------------------------------------------------------------------
Function name : main
----------------------------------------------------------------------------------*/
int main()
{
	const char *menuList[] = { "�Է��ϱ�","����ϱ�","�˻��ϱ�","�����ϱ�", "�����ϱ�", "��  ��" };
	int menuNum;	/* �޴���ȣ ���� ���� */
	int menuCnt;	/* �޴����� ���� ���� */
	List list;		/* ����Ʈ���� ����ü ���� */
	BOOL bres;

	menuCnt = sizeof(menuList) / sizeof(menuList[0]);

	bres = createList(&list);		/* ����ִ� ����Ʈ �ʱ�ȭ */
	if (bres == TRUE)
		printf("@ list ���� ����!\n");
	else {
		printf("@ list ���� ����!\n");
		return 1;	/* list ���� ���� �� ���α׷��� �� ������ �ǹ̰� �����Ƿ� ���α׷� ���� */
	}
		
	while (1)
	{
		menuNum = menu(menuList, menuCnt);	/* �޴�ȭ���� ���� �޴���ȣ�� �Է� ���� */
		if (menuNum == menuCnt) { break; }
		switch (menuNum)
		{
		case 1: mInput(&list); break;		/* �Է¸޴� ���� */
		case 2: mOutput(&list); break;		/* ��¸޴� ���� */
		case 3: mSearch(&list); break;		/* �˻��޴� ���� */
		case 4: mDelete(&list); break;		/* �����޴� ���� */
		case 5: mSort(&list); break;		/* ���ĸ޴� ���� */
		}
	}
	printf("list���� ������ ����� ���� : %d\n", list.size);

	destroyList(&list, personClear);	/* ����Ʈ���� ��� ������ ���� */

	return 0;
}
/*----------------------------------------------------------------------------------
Function name	: menu
Parameters		: mList - �޴� ��� �迭
				  menuCnt - �޴� ����
Returns			: ����� ������ �޴���ȣ
----------------------------------------------------------------------------------*/
int menu(const char **mList, size_t menuCnt)
{
	size_t menuNum = 0;	/* �������� �ʴ� �޴� ��ȣ ���� */
	size_t i;

	printf("\n\n");
	for (i = 0; i < menuCnt; i++) {	/* �޴� ��� */
		printf("%d. %s\n", i + 1, mList[i]);
	}

	while (menuNum<1 || menuNum>menuCnt) {	/* �޴���ȣ�� ��ȿ���� ���� ���� �ݺ� */
		printf("# �޴� ���� : ");
		scanf("%d", &menuNum);	/* �޴� ��ȣ �Է� */
	}
	return menuNum;
}
/*----------------------------------------------------------------------------------
Function name	: mInput - �Է� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mInput(List *lp)
{
	//int inData;
	Person inData = { NULL,0,"" };
	int res;  /* scanf()�Լ��� ���� �� ���� */
	BOOL bres;
	char tname[100];

	printf("\n[ �Է��ϱ� �޴� ]\n\n");

	while (1) {
		printf("# �̸��� �Է��ϼ���(end �Է½� ����) : ");
		res = scanf("%s", tname);	/* scanf()�Լ��� ���� �� : ���� �Է� �� 1, ���� �Է� �� 0���� ��*/
		if (strcmp("end", tname) == 0) {  // end �Է½� ����
			break;
		}

		inData.name = (char *)calloc(strlen(tname) + 1, sizeof(char));
		strcpy(inData.name, tname);

		printf("���� �Է� : ");
		scanf("%d", &inData.age);
		printf("��ȭ��ȣ �Է� : ");
		scanf("%s", inData.phoneNumber);

		bres = addLast(lp, &inData, sizeof(Person), personMemcpy);	/* tail ��� �տ� ������ �߰�  */
		if (bres == TRUE)
			printf("@ ������ �߰� ����!\n");
		else
			printf("@ ������ �߰� ����!\n");
		free(inData.name); // ���ϸ� while �� ������ �޸� ����
	}
	return;
}
/*----------------------------------------------------------------------------------
Function name	: mOutput - ��� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mOutput(List *lp)
{
	displayList(lp, personPrint);
}
/*----------------------------------------------------------------------------------
Function name	: mSearch - �˻� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mSearch(List * lp)
{
	//int sData;
	Person sData = { NULL,0,"" };
	Node *resp;		/* �˻��� ����� �����ּ� ���� */
	int res;		/* scanf()�Լ��� ���� �� ���� */
	char tname[30];

	printf("\n[ �˻��ϱ� �޴� ]\n\n");
	while (1) {
		printf("# ã�� �̸��� �Է��ϼ���(end �Է� �� ����) : ");
		res = scanf("%s", &tname);	/* scanf()�Լ��� ���� �� : ���� �Է� �� 1, ���� �Է� �� 0���� ��*/
		if (strcmp(tname, "end")==0) {		/* end �Է� �� ���� */
			break;
		}
		sData.name = (char *)calloc(strlen(tname) + 1, sizeof(char));
		strcpy(sData.name, tname);
		resp = searchNode(lp, &sData, personNameCompare);
		if (resp != NULL) {	/* �����͸� ã������ */
			printf("@ �˻� ������ ����!\n");
		}
		else {				/* �����͸� ��ã������ */
			printf("@ �˻� ������ �������� ����!\n");
		}
		free(sData.name);
	}
	return;
}
/*----------------------------------------------------------------------------------
Function name	: mDelete - ���� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mDelete(List * lp)
{
	//int delData;
	Person delData = {NULL, 0, ""};
	int res;		/* scanf()�Լ��� ���� �� ���� */
	BOOL bres;
	char tname[20];

	printf("\n[ �����ϱ� �޴� ]\n\n");
	while (1) {
		printf("# ������ �̸��� �Է��ϼ���(end �Է� �� ����) : ");
		res = scanf("%s", tname);	/* scanf()�Լ��� ���� �� : ���� �Է� �� 1, ���� �Է� �� 0���� ��*/
		if (strcmp(tname, "end") == 0) {		/* end  �Է½� ����*/
			break;
		}

		delData.name = (char *)calloc(strlen(tname) + 1, sizeof(char));
		strcpy(delData.name, tname);
		bres = removeNode(lp, &delData, personNameCompare, personClear);
		if (bres == TRUE)
			printf("@ ���� ����!\n");
		else
			printf("@ ���� ����!\n");
		free(delData.name);
	}
	return;
}
/*----------------------------------------------------------------------------------
Function name	: mSort - ���� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mSort(List *lp)
{
	sortList(lp, sizeof(Person), personNameCompare, personMemcpy, personClear);
}
/*----------------------------------------------------------------------------------
Function name	: myflush - �Է� ���� ���� ��� ������ ����� �Լ�
Parameters		: ����
Returns			: ����
----------------------------------------------------------------------------------*/
void myflush()
{
	while (getchar() != '\n') {
		;
	}
}
