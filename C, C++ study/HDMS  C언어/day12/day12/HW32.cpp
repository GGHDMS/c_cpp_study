//�ۼ��� �㼮�� HW32

#include<stdio.h>
int num_u1, num_d1, num_u2, ans1;
double num_d2, ans2;
unsigned int inputUInt(const char *);
int ipow(int, int);
double fpow(double, int);
double inputDouble(const char *);
void myflush();

int main()
{
	num_d1 = inputUInt("���� ���� ���� �Է��Ͻÿ� :");
	num_u1 = inputUInt("���� ���� �Է��ϼ��� :");
	ans1 = ipow(num_d1, num_u1);
	printf("%d�� %d���� %d�Դϴ�.\n", num_d1, num_u1, ans1);
	num_d2 = inputDouble("���� �Ǽ� ���� �Է��Ͻÿ� :");
	num_u2 = inputUInt("���� ���� �Է��ϼ��� :");
	ans2 = fpow(num_d2, num_u2);
	printf("%.2lf�� %d���� %.3lf�Դϴ�.\n", num_d2, num_u2, ans2);

	return 0;
}

unsigned int inputUInt(const char *msg)
{
	int n;
	while (1)
	{
		printf(msg);
		scanf("%d", &n);
		if (getchar() == '\n' && n >= 0) { break; }
		else if (n < 0) { ; }
		else{myflush();	}
	}
	return n;
}

int ipow(int d, int u)
{
	int i, calc;
	calc = 1;
	if (d == 0) { return 0; }
	else if (u == 0) { return 1; }
	else
	{
		for (i = 1; i <= u; i++)
		{
			 calc = calc * d;
		}
		return calc;
	}
}

double inputDouble(const char *msg)
{
	double n;
	while (1)
	{
		printf(msg);
		scanf("%lf", &n);
		if (getchar() == '\n' && n >= 0) { break; }
		else if (n < 0) { ; }
		else { myflush(); }
	}
	return n;

}

double fpow(double d, int u)
{
	int i;
	double calc;
	calc = 1.0;
	if (d == 0) { return 0; }
	else if (u == 0) { return 1; }
	else
	{
		for (i = 1; i <= u; i++)
		{
			calc = calc * d;
		}
		return calc;
	}
}

void myflush()
{
	while (getchar() != '\n')
	{
		;
	}
}