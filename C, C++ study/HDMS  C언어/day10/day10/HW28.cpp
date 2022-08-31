//작성자 허석문 HW28

#include<stdio.h>
int eng = 0, num = 0, blank = 0, rest = 0;
int calc;

int main()
{
	printf("영문 문장을 입력 하시오:\n");
	while ((calc = getchar()) != EOF)
	{
		if ('A' <= calc && calc <= 'Z' || 'a' <= calc && calc <= 'z') { eng++; }
		else if ('0' <= calc && calc <= '9') { num++; }
		else if (calc == '\n' || calc == '\t' || calc == ' ') { blank++; }
		else { rest++; }
	}

	printf("영문자 대소문자 개수: %d\n", eng);
	printf("숫자문자 개수: %d\n", num);
	printf("여백문자(space, tab, enter)개수 : %d\n", blank);
	printf("그 외 기타문자 개수 : %d\n", rest);
	return 0;
}
