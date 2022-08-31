#include <iostream>
using namespace std;
#include "Robot.h"

Robot * input(int);
void work(Robot *, int);
void output(Robot *, int);
void myFlush();

int main() {
	Robot *rp;
	int rCnt;
	while (1) {
		cout << "구입할 로봇 대수를 입력하시오 : ";
		cin >> rCnt;
		if (cin.fail()) {
			myFlush();
			continue;
		}
		if (rCnt > 0) {
			myFlush();
			break;
		}
		myFlush();
	}
	rp = input(rCnt);
	work(rp, rCnt);
	output(rp, rCnt);
	delete[]rp;
}

Robot * input(int n) {
	Robot *rp;
	char name[100];
	int e;
	rp = new Robot[n];
	for (int i = 0; i < n; i++) {
		cout << i + 1 << "번 로봇명을 입력하시오 : ";
		cin >> name;
		(rp + i)->setName(name);
		while (1) {
			cout << name << "의 에너지 양을 입력하시오 : ";
			cin >> e;
			if (cin.fail()) {
				myFlush();
				continue;
			}
			if (e > 0) {
				myFlush();
				break;
			}
			myFlush();
		}
		(rp + i)->setEnergy(e);

	}
	return rp;
}

void work(Robot * rp, int n) {
	char name[100];
	int i, w, c;
	while (1) {
		cout << "# 로봇명 선택(";
		for (i = 0; i < n; i++) {
			cout << (rp + i)->getName();
			if (i + 1 == n) {
				break;
			}
			cout << ", ";
		}
		cout << ") : ";
		cin.getline(name, sizeof(name));
		if (strcmp(name, "") == 0) {
			break;
		}
		for (i = 0; i < n; i++) {
			if (strcmp(name, (rp + i)->getName()) == 0) {
				break;
			}
		}
		if (i == n) {
			continue;
		}
		while (1) {
			w = 0;
			cout << "# 할일 선택(1.전진/2.후진/3.회전/4.점프/5.충전) : ";
			cin >> w;
			if (0 < w && w < 6) {
				myFlush();
				break;
			}
			myFlush();
		}
		switch (w)
		{
		case 1:cout << (rp + i)->getName() << " "; (rp + i)->go(); break;
		case 2:cout << (rp + i)->getName() << " "; (rp + i)->back(); break;
		case 3:cout << (rp + i)->getName() << " "; (rp + i)->turn(); break;
		case 4:cout << (rp + i)->getName() << " "; (rp + i)->jump(); break;
		default:break;
		}
		if (w == 5) {
			while (1) {
				cout << "충전할 에너지양 입력 : ";
				cin >> c;
				if (cin.fail()) {
					myFlush();
				}
				else {
					(rp + i)->charge(c);
					myFlush();
					break;
				}
			}			
		}
	}
}

void output(Robot *rp, int n) {
	for (int i = 0; i < n; i++) {
		cout << i+1 << ". " << (rp + i)->getName() << " : " << (rp + i)->getEnergy() << endl;
	}
}

void myFlush() {
	cin.clear();
	while (cin.get() != '\n') { ; }
}