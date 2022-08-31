//�ۼ��� �㼮�� HW34

#include<stdio.h>
#include<string.h>

int number, quan, money;
int inputInt(const char*);
int inputInt1(const char*);
int calc(int, int);
void output(int, int, int);
void myflush();


int main()
{
	number = inputInt("*����� �ڵ带 �Է��Ͻʽÿ�(1:������/2:�����/3:������)");
	quan = inputInt1("*��뷮�� �Է��Ͻÿ�(ton����)");
	money = calc(number, quan);
	output(number, quan, money);
	return 0;
}

int inputInt(const char *msg)
{
	int n;
	while (1)
	{
		int res;
		printf(msg);
		if (scanf("%d", &n) == 1 && 1 <= n && n <= 3) { break; }
		else{
			myflush();
		}
	}
	return n;
}
int inputInt1(const char *msg)
{
	int n;
	while (1)
	{
		int res;
		printf(msg);
		if (scanf("%d", &n) == 1 && 1 <= n && getchar()=='\n') { break; }
		else {
			myflush();
		}
	}
	return n;
}


int calc(int n, int ton)
{
	int num;
	switch (n)
	{
		case 1: num = 50 * ton; break;
		case 2: num = 45 * ton; break;
		case 3: num = 30 * ton; break;	
	}
	return num;
}

void output(int n, int ton, int m)
{
	char str[20];
	if (n == 1){
		strcpy(str, "������");
		printf("����� �ڵ� : %d(%s)\n", n, str);
		printf("��뷮 : %d ton\n", ton);
		printf("�Ѽ������ : %d\n", (int) (m * 1.05));
	}
	if (n == 2) {
		strcpy(str, "�����");
		printf("����� �ڵ� : %d(%s)\n", n, str);
		printf("��뷮 : %d ton\n", ton);
		printf("�Ѽ������ : %d\n", (int) (m * 1.05));
	}
	if (n == 3) {
		strcpy(str, "������");
		printf("����� �ڵ� : %d(%s)\n", n, str);
		printf("��뷮 : %d ton\n", ton);
		printf("�Ѽ������ : %d\n", (int) (m * 1.05));
	}
}

void myflush()
{
	while (getchar()!= '\n')
	{
		;
	}
}

