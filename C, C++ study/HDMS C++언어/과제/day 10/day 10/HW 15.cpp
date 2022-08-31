#include "Fitness.h"

int menu();
void input(Fitness **, int *, int *);
void show(Fitness **, int *);
void search(Fitness **, int *);
void out(Fitness **, int *, int *);
void manage(Fitness **, int *);
void myFlush();

int main() {
	Fitness * fart[100];
	int num;
	int memberCnt = 0;
	int memberNum = 1;

	while (1) {
		num = menu();
		switch (num)
		{
		case 1: input(fart, &memberCnt, &memberNum); break;
		case 2: show(fart, &memberCnt); break;
		case 3: search(fart, &memberCnt); break;
		case 4: out(fart, &memberCnt, &memberNum); break;
		case 5: manage(fart, &memberCnt); break;
		default:break;
		}
		if (num == 6) {
			break;
		}
	}
	for (int i = 0; i < memberCnt; i++) {
		delete fart[i];
	}
}

int menu() {
	int num;
	while (1)
	{
		cout << "1. 회원등록" << endl;
		cout << "2. 회원전체보기" << endl;
		cout << "3. 회전정보검색" << endl;
		cout << "4. 회원탈퇴" << endl;
		cout << "5. 특별관리 회원" << endl;
		cout << "6. 종료" << endl;
		cout << "입력 : ";
		cin >> num;
		myFlush();
		if (0 < num&&num < 7) {
			return num;
		}
	}
}
void input(Fitness **f, int *cnt, int *num) {
	if (*cnt == 99) {
		return;
	}
	char name[50];
	int weight, height;
	cout << "이름을 입력하시오 : ";
	cin >> name;
	while (1) {
		cout << "몸무게를 입력하시오 : ";
		cin >> weight;
		myFlush();
		if (weight > 0) {
			break;
		}
	}
	while (1) {
		cout << "키를 입력하시오 : ";
		cin >> height;
		myFlush();
		if (height > 0) {
			break;
		}
	}
	Fitness *n = new Fitness(*num, name, weight, height);
	f[*cnt] = n;
	(*cnt)++;
	(*num)++;
}
void show(Fitness **f, int *cnt) {
	int i;
	for (i = 0; i < *cnt; i++) {
		cout << "회원번호: " << f[i]->getNum() << " ";
		cout << "성명: " << f[i]->getName() << " ";
		cout << "몸무게: " << f[i]->getWeight() << "kg ";
		cout << "신장: " << f[i]->getHeight() << "cm " << endl;
	}
}
void search(Fitness **f, int *cnt) {
	int i;
	char name[50];
	cout << "이름을 입력하시오 : ";
	cin >> name;
	for (i = 0; i < *cnt; i++) {
		if (strcmp(name, f[i]->getName()) == 0) {
			cout << "회원번호: " << f[i]->getNum ()<< " ";
			cout << "성명: " << f[i]->getName() << " ";
			cout << "몸무게: " << f[i]->getWeight() << "kg ";
			cout << "신장: " << f[i]->getHeight() << "cm " << endl;
		}
	}
}
void out(Fitness **f, int *cnt, int *num) {
	int tnum, i;
	while (1) {
		cout << "회원번호를 입력하시오 : ";
		cin >> tnum;
		myFlush();
		if (tnum > 0) {
			break;
		}
	}
	for (i = 0; i < *cnt; i++) {
		if (f[i]->getNum() == tnum) {
			delete f[i];
			break;
		}
	}
	for (i; i < *cnt - 1; i++) {
		f[i] = f[i + 1];
	}
	(*cnt)--;
}
void manage(Fitness **f, int *cnt) {
	int i;
	for (i = 0; i < *cnt; i++) {
		if (f[i]-> bmi() >= 25) {
			cout << "회원번호: " << f[i]->getNum() << " ";
			cout << "성명: " << f[i]->getName() << " ";
			cout << "몸무게: " << f[i]->getWeight() << "kg ";
			cout << "신장: " << f[i]->getHeight() << "cm " << endl;
		}
	}
}
void myFlush() {
	cin.clear();
	while (cin.get() != '\n') { ; }
}