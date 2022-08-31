#pragma warning (disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef struct _person
{
	char *name;         // 성명 저장 멤버
	int age;             // 나이 저장 멤버
	char address[20];   // 주소 저장 멤버
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
	printf("1번\n");
	personInput(&var1);  // 구조체 각 멤버에 값을 입력 받아옴
	personOutput(var1);
	printf("\n");
	personInput(&var2);
	personOutput(var2);
	printf("\n");
	//var1 = var2;    // 얕은 복사로 이후 personClear()함수 수행 시 런타임에러 발생
	personMemCpy(&var1, &var2);

	personOutput(var1); // 구조체 내의 데이터  출력
	personOutput(var2);
	printf("\n");

	personClear(&var1);  // 구조체 멤버의 메모리를 해제하고 데이터 모두 삭제
	personClear(&var2);
	//---------------------------------------------------------------------
	Person temp1 = { NULL, 0, "" };
	Person  var3 = { NULL, 0, "" };

	printf("2번 \n");
	personInput(&var3);  // 구조체 각 멤버에 값을 입력 받아옴
	personOutput(var3);
	printf("\n");

	personMemCpy(&var3, &temp1);

	personOutput(var3); // 구조체 내의 데이터  출력
	personOutput(temp1);
	printf("\n");

	personClear(&var3);  // 구조체 멤버의 메모리를 해제하고 데이터 모두 삭제
	personClear(&temp1);
	//---------------------------------------------------------------------
	Person temp2 = { NULL, 0, "" };
	Person  var4 = { NULL, 0, "" };

	printf("3번\n");
	personInput(&temp2);  // 구조체 각 멤버에 값을 입력 받아옴
	personOutput(temp2);
	printf("\n");

	personMemCpy(&var4, &temp2);

	personOutput(var4); // 구조체 내의 데이터  출력
	personOutput(temp2);
	printf("\n");

	personClear(&var4);  // 구조체 멤버의 메모리를 해제하고 데이터 모두 삭제
	personClear(&temp2);
	//---------------------------------------------------------------------
	Person temp3 = { NULL, 0, "" };
	Person  var5 = { NULL, 0, "" };

	printf("4번\n");
	personMemCpy(&var5, &temp3);

	personOutput(var5); // 구조체 내의 데이터  출력
	personOutput(temp3);
	printf("\n");

	personClear(&var5);  // 구조체 멤버의 메모리를 해제하고 데이터 모두 삭제
	personClear(&temp3);

	getchar();
	return 0;
}
//--------------------------------------------------------------------------
void personInput(Person *sp)
{
	char temp[101];
	size_t length;
	stringInput("성명 입력(100byte 이내) : ", temp, sizeof(temp));
	length = strlen(temp);
	sp->name = (char *)malloc(sizeof(char) * (length + 1)); //null문자 위해 +1
	assert(sp->name != NULL);
	strcpy(sp->name, temp);
	printf("나이 입력 : ");
	scanf("%d", &sp->age);
	myFlush();
	stringInput("주소 입력(19byte 이내) : ", temp, sizeof(sp->address));
	strcpy(sp->address, temp);
	return;
}
//---------------------------------------------------------------------------
void stringInput(const char *message, char *tp, size_t length)
{
	printf(message);
	fgets(tp, length, stdin);

	if (tp[strlen(tp) - 1] == '\n') // 문자열이 정상적으로 입력되었으면
	{
		tp[strlen(tp) - 1] = '\0'; // 문자열뒤의 개행문자 삭제
	}
	else  // 입력된 문자열이 배열의 크기를 초과하게 입력되었다면
	{
		printf("입력된 문자열이 너무 길어서 일부 문자열이 잘리게 됩니다.\n");
		myFlush();  // stdin 버퍼에 남아있는 데이너 모두 지우기
	}
	return;
}
//---------------------------------------------------------------------------
void personOutput(Person sVal)
{
	printf("성명 : %s(%d세), 주소 : %s\n", sVal.name, sVal.age, sVal.address);
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

//--------------------------------------------------------------------------- 내가 만든

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
		assert(var1->name != NULL); // NULL 이면 프로그램 종료; 
		strcpy(var1->name, var2->name);
	}
	var1->age = var2->age;
	strcpy(var1->address, var2->address);
}