//�ۼ��� �㼮�� HW18

#include<stdio.h>

int age, num, fee, f_fee, sale = 0;
int input1();
int input2();
void output(int, int, int);

int main()
{
	age = input1();
	num = input2();
	if (age <= 7){fee = 500 * num;}
	else if (age <= 13){fee = 700 * num;}
	else if (age <= 19){fee = 1000 * num;}
	else if (age <= 55){fee = 1500 * num;}
	else {fee = 500 * num;}
	if (num >= 5) {sale = (int)(fee * 0.1);}
	f_fee = fee - sale;
	output(fee, f_fee, sale);
}

int input1()
{
	printf("���尴�� ���̸� �Է��Ͻÿ�:");
	scanf("%d", &age);
	return age;
}

int input2()
{
	printf("���尴�� ���� �Է��Ͻÿ�:");
	scanf("%d", &num);
	return num;
}

void output(int fee, int f_fee, int sale)
{
	printf("����� = > %d��\n���αݾ� = >%d��\n�����ݾ� = >%d��", fee, sale, f_fee);
}