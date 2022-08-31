// 작성자 허석문 HW15

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
	printf("몸무게를 입려하세요(kg):");
	scanf("%d", &wei);
	return wei;
}

double input2()
{
	double  hei;
	printf("키를 입력하세요(m):");
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

	if (bmi < 18.5) { printf("당신의 BMI는 %lf으로 저체중입니다", bmi); }
	else if (bmi < 25.0) { printf("당신의 BMI는 %lf으로 정상체중입니다", bmi); }
	else if (bmi < 30.0) { printf("당신의 BMI는 %lf으로 과체중입니다", bmi); }
	else if (bmi < 40.0) { printf("당신의 BMI는 %lf으로 비만입니다", bmi); }
	else { printf("당신의 BMI는 %lf으로 고도비만입니다", bmi); }
}