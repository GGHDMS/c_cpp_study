#pragma warning (disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef struct _person
{
	char *name;         // ���� ���� ���
	int age;             // ���� ���� ���
	char address[20];   // �ּ� ���� ���
}Person;
void myFlush();
void personInput(Person *sp);
void personOutput(Person sVal);
void personClear(Person *sp);
void stringInput(const char *message, char *tp, size_t length);
void personMemCpy(Person *p1, Person *p2);

int main()
{
	Person  var1 = { NULL,0, "" }, var2 = { NULL,0, "" };
	printf("1��\n");
	personInput(&var1);  // ����ü �� ����� ���� �Է� �޾ƿ�
	personOutput(var1);
	printf("\n");
	personInput(&var2);
	personOutput(var2);
	printf("\n");
	//var1 = var2;    // ���� ����� ���� personClear()�Լ� ���� �� ��Ÿ�ӿ��� �߻�
	personMemCpy(&var1, &var2);

	personOutput(var1); // ����ü ���� ������  ���
	personOutput(var2);
	printf("\n");

	personClear(&var1);  // ����ü ����� �޸𸮸� �����ϰ� ������ ��� ����
	personClear(&var2);
	//---------------------------------------------------------------------
	Person temp1 = { NULL, 0, "" };
	Person  var3 = { NULL, 0, "" };

	printf("2�� \n");
	personInput(&var3);  // ����ü �� ����� ���� �Է� �޾ƿ�
	personOutput(var3);
	printf("\n");

	personMemCpy(&var3, &temp1);

	personOutput(var3); // ����ü ���� ������  ���
	personOutput(temp1);
	printf("\n");

	personClear(&var3);  // ����ü ����� �޸𸮸� �����ϰ� ������ ��� ����
	personClear(&temp1);
	//---------------------------------------------------------------------
	Person temp2 = { NULL, 0, "" };
	Person  var4 = { NULL, 0, "" };

	printf("3��\n");
	personInput(&temp2);  // ����ü �� ����� ���� �Է� �޾ƿ�
	personOutput(temp2);
	printf("\n");

	personMemCpy(&var4, &temp2);

	personOutput(var4); // ����ü ���� ������  ���
	personOutput(temp2);
	printf("\n");

	personClear(&var4);  // ����ü ����� �޸𸮸� �����ϰ� ������ ��� ����
	personClear(&temp2);
	//---------------------------------------------------------------------
	Person temp3 = { NULL, 0, "" };
	Person  var5 = { NULL, 0, "" };

	printf("4��\n");
	personMemCpy(&var5, &temp3);

	personOutput(var5); // ����ü ���� ������  ���
	personOutput(temp3);
	printf("\n");

	personClear(&var5);  // ����ü ����� �޸𸮸� �����ϰ� ������ ��� ����
	personClear(&temp3);

	getchar();
	return 0;
}
//--------------------------------------------------------------------------
void personInput(Person *sp)
{
	char temp[101];
	size_t length;
	stringInput("���� �Է�(100byte �̳�) : ", temp, sizeof(temp));
	length = strlen(temp);
	sp->name = (char *)malloc(sizeof(char) * (length + 1)); //null���� ���� +1
	assert(sp->name != NULL);
	strcpy(sp->name, temp);
	printf("���� �Է� : ");
	scanf("%d", &sp->age);
	myFlush();
	stringInput("�ּ� �Է�(19byte �̳�) : ", temp, sizeof(sp->address));
	strcpy(sp->address, temp);
	return;
}
//---------------------------------------------------------------------------
void stringInput(const char *message, char *tp, size_t length)
{
	printf(message);
	fgets(tp, length, stdin);

	if (tp[strlen(tp) - 1] == '\n') // ���ڿ��� ���������� �ԷµǾ�����
	{
		tp[strlen(tp) - 1] = '\0'; // ���ڿ����� ���๮�� ����
	}
	else  // �Էµ� ���ڿ��� �迭�� ũ�⸦ �ʰ��ϰ� �ԷµǾ��ٸ�
	{
		printf("�Էµ� ���ڿ��� �ʹ� �� �Ϻ� ���ڿ��� �߸��� �˴ϴ�.\n");
		myFlush();  // stdin ���ۿ� �����ִ� ���̳� ��� �����
	}
	return;
}
//---------------------------------------------------------------------------
void personOutput(Person sVal)
{
	printf("���� : %s(%d��), �ּ� : %s\n", sVal.name, sVal.age, sVal.address);
	return;
}
//---------------------------------------------------------------------------
void personClear(Person *sp)
{
	if (sp->name != NULL) {
		memset(sp->name, 0, strlen(sp->name));
		free(sp->name);
		sp->name = NULL;
	}
	sp->age = 0;
	memset(sp->address, 0, sizeof(sp->address));

	return;
}
void myFlush()
{
	while (getchar() != '\n');
}

//--------------------------------------------------------------------------- ���� ����

void personMemCpy(Person *var1, Person *var2) {
	if (var1->name != NULL) {
		memset(var1->name, 0, strlen(var1->name));
		free(var1->name);
		var1->name = NULL;
	}
	/*if (var2->name == NULL) {
		var1->name = NULL;
	}
	else */
	if (var2 ->name !=NULL){
		var1->name = (char *)(malloc(sizeof(char) + strlen(var2->name) + 1));
		assert(var1->name != NULL); // NULL �̸� ���α׷� ����; 
		strcpy(var1->name, var2->name);
	}
	var1->age = var2->age;
	strcpy(var1->address, var2->address);
}