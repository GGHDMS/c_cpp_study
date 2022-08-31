#include <stdio.h>
#include "doublyLinkedlist.h"
#include "Double.h"

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

	destroyList(&list, doubleClear);	/* ����Ʈ���� ��� ������ ���� */

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
	double inData;
	int res;  /* scanf()�Լ��� ���� �� ���� */
	BOOL bres;

	printf("\n[ �Է��ϱ� �޴� ]\n\n");

	while (1) {
		printf("# �Ǽ����� �Է��ϼ���(���� �Է½� ����) : ");
		res = scanf("%lf", &inData);	/* scanf()�Լ��� ���� �� : ���� �Է� �� 1, ���� �Է� �� 0���� ��*/
		if (res == 0) {	/* ���� �Է� �� ���� */
			myflush();
			break;
		}
		bres = addLast(lp, &inData, sizeof(double), doubleMemcpy);	/* tail ��� �տ� ������ �߰�  */
		if (bres == TRUE)
			printf("@ ������ �߰� ����!\n");
		else
			printf("@ ������ �߰� ����!\n");
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
	displayList(lp, doublePrint);
}
/*----------------------------------------------------------------------------------
Function name	: mSearch - �˻� �޴� ó�� �Լ�
Parameters		: lp - ����Ʈ ���� ����ü�� �ּ�
Returns			: ����
----------------------------------------------------------------------------------*/
void mSearch(List * lp)
{
	//int sData;
	double sData;
	Node *resp;		/* �˻��� ����� �����ּ� ���� */
	int res;		/* scanf()�Լ��� ���� �� ���� */
	
	printf("\n[ �˻��ϱ� �޴� ]\n\n");
	while (1) {
		printf("# �Ǽ����� �Է��ϼ���(���� �Է� �� ����) : ");
		res = scanf("%lf", &sData);	/* scanf()�Լ��� ���� �� : ���� �Է� �� 1, ���� �Է� �� 0���� ��*/
		if (res == 0) {		/* ���� �Է� �� ���� */
			myflush();
			break;
		}
		
		resp = searchNode(lp, &sData, doubleCompare);
		if (resp != NULL) {	/* �����͸� ã������ */
			printf("@ �˻� ������ ����!\n");
		}
		else {				/* �����͸� ��ã������ */
			printf("@ �˻� ������ �������� ����!\n");
		}
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
	double delData;
	int res;		/* scanf()�Լ��� ���� �� ���� */
	BOOL bres;

	printf("\n[ �����ϱ� �޴� ]\n\n");
	while (1) {
		printf("# ������ �̸��� �Է��ϼ���(end �Է� �� ����) : ");
		res = scanf("%lf", &delData);	/* scanf()�Լ��� ���� �� : ���� �Է� �� 1, ���� �Է� �� 0���� ��*/
		if (res == 0) {		/* ���� �Է½� ���� */
			myflush();
			break;
		}

		bres = removeNode(lp, &delData, doubleCompare, doubleClear);
		if (bres == TRUE)
			printf("@ ���� ����!\n");
		else
			printf("@ ���� ����!\n");
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
	sortList(lp, sizeof(double), doubleCompare, doubleMemcpy, doubleClear);
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
