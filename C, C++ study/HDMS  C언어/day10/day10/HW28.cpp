//�ۼ��� �㼮�� HW28

#include<stdio.h>
int eng = 0, num = 0, blank = 0, rest = 0;
int calc;

int main()
{
	printf("���� ������ �Է� �Ͻÿ�:\n");
	while ((calc = getchar()) != EOF)
	{
		if ('A' <= calc && calc <= 'Z' || 'a' <= calc && calc <= 'z') { eng++; }
		else if ('0' <= calc && calc <= '9') { num++; }
		else if (calc == '\n' || calc == '\t' || calc == ' ') { blank++; }
		else { rest++; }
	}

	printf("������ ��ҹ��� ����: %d\n", eng);
	printf("���ڹ��� ����: %d\n", num);
	printf("���鹮��(space, tab, enter)���� : %d\n", blank);
	printf("�� �� ��Ÿ���� ���� : %d\n", rest);
	return 0;
}
