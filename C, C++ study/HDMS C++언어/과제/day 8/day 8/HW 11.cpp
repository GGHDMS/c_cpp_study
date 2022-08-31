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
		cout << "������ �κ� ����� �Է��Ͻÿ� : ";
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
		cout << i + 1 << "�� �κ����� �Է��Ͻÿ� : ";
		cin >> name;
		(rp + i)->setName(name);
		while (1) {
			cout << name << "�� ������ ���� �Է��Ͻÿ� : ";
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
		cout << "# �κ��� ����(";
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
			cout << "# ���� ����(1.����/2.����/3.ȸ��/4.����/5.����) : ";
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
				cout << "������ �������� �Է� : ";
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