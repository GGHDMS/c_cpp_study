// �ۼ��� �㼮�� HW15

#include<stdio.h>

int weight;
double height, bmi;
int input1();
double input2();
double calc(int, double);
void output(double bmi);

int main()
{
	weight = input1();
	height = input2();
	bmi = calc(weight, height);
	output(bmi);
	return 0;
}

int input1()
{
	int wei;
	printf("�����Ը� �Է��ϼ���(kg):");
	scanf("%d", &wei);
	return wei;
}

double input2()
{
	double  hei;
	printf("Ű�� �Է��ϼ���(m):");
	scanf("%lf", &hei);
	return hei;
}

double calc(int weight, double height)
{
	double bmi;
	bmi = weight / (height*height);
	return bmi;
}

void output(double bmi)
{

	if (bmi < 18.5) { printf("����� BMI�� %lf���� ��ü���Դϴ�", bmi); }
	else if (bmi < 25.0) { printf("����� BMI�� %lf���� ����ü���Դϴ�", bmi); }
	else if (bmi < 30.0) { printf("����� BMI�� %lf���� ��ü���Դϴ�", bmi); }
	else if (bmi < 40.0) { printf("����� BMI�� %lf���� ���Դϴ�", bmi); }
	else { printf("����� BMI�� %lf���� �����Դϴ�", bmi); }
}