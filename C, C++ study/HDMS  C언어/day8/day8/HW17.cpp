// 작성자 허석문 HW17

#include<stdio.h>
#include<string.h>

double height;
char name[20], gender;
int len;

int main()
{
	printf("성명 입력:");
	fgets(name, 20, stdin);
	len = strlen(name);
	name[len - 1] = '\0';
	printf("키 입력:");
	scanf("%lf", &height);
	printf("성별입력(M/F):");
	scanf(" %c", &gender);
	if (gender == 'M') {
		printf("%s씨의 키는 %.2lfcm이고 남성입니다.\n", name, height);
	}
	if (gender == 'F'){
		printf("%s씨의 키는 %.2lfcm이고 여성입니다.\n", name, height);
	}
	return 0;
}

