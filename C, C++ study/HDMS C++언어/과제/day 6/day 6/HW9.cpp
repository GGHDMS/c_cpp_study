//수강생 허석문 HW9

#include <iostream>
#include <ctime> 
#include <windows.h>
#include <cstring>
using namespace std;

struct Goods {
	char item[50]; // 품목
	int price; // 정가
	int year; // 유통기한(년도) 
	int mon; // 유통기한 (월)
	int day; // 유통기한(일)
	int discount; // 할인율
};

struct date {
	unsigned int da_year;
	unsigned int da_mon;
	unsigned int da_day;
};

void input(Goods &s);
void selling_price(Goods &s);
void prn(const Goods &s);
int tot_days(int y, int m, int d);
int year_check(int year);
void getdate(struct date *);
void myFlush();

int main() {
	Goods s;
	input(s);
	selling_price(s);
	prn(s);
	return 0;
}


void input(Goods &s) {
	cout << "품목 입력 : ";
	cin.getline(s.item, sizeof(s.item), '\n');
	while (1) {
		cout << "정가 입력 : ";
		cin >> s.price;
		if (cin.fail()) {
			myFlush();
		}
		else {
			myFlush();
			if (s.price > 0) {
				break;
			}
		}
	}

	while (1) {
		cout << "유통기한 입력 : ";
		cin >> s.year >> s.mon >> s.day;
		if (cin.fail()) {
			myFlush();
		}
		else {
			break;
		}
	}
}

void selling_price(Goods &s) {
	int tsum1, tsum2, sum;
	struct date stdate;
	getdate(&stdate);
	tsum1 = tot_days(stdate.da_year, stdate.da_mon, stdate.da_day); // 오늘날 총 일수
	tsum2 = tot_days(s.year, s.mon, s.day); // 유통기한 총 일수
	sum = tsum2 - tsum1;
	if (sum < 0) {
		s.discount = -1;
	}
	else if (sum < 4) {
		s.discount = 50;
	}
	else if(sum < 11) {
		s.discount = 20;
	}
	else {
		s.discount = 0;
	}
}

void prn(const Goods &s){
	if (s.discount != -1) {
		cout << "품명 : " << s.item << endl;
		cout << "판매가 : " << s.price - s.price * s.discount / 100 << endl;
		cout << "유통기한 : " << s.year << "년 " << s.mon << "월 " << s.day << "일" << endl;
		cout << "할인율 : " << s.discount << "%" << endl;
	}
	else {
		cout << "유통기한이 지났습니다!" << endl;
	}
}

int tot_days(int y, int m, int d) {
	int calc_month[] = { 31 , 28 , 31, 30, 31, 30, 31, 31, 30 , 31, 30, 31 };
	int sum = 0, num, i;
	for (i = 1900; i < y; i++){
		num = year_check(i);
		if (num == 366) { sum += 366; }
		else { sum += 365; }
	}
	for (i = 1; i < m; i++){
		num = year_check(y);
		if (num == 366)	{
			if (i == 2) {
				sum += 29;
			}
			else {
				sum += calc_month[i - 1];
			}
		}
		else{
			sum += calc_month[i - 1];
		}
	}
	sum += d;
	return sum;
}

int year_check(int year) {
	if (year % 4 == 0)	{
		if (year % 100 == 0){
			if (year % 400 == 0){
				return 366;
			}
			else{
				return 365;
			}
		}
		else{
			return 366;
		}
	}
	else{
		return 365;
	}
}

void getdate(struct date *p)
{

	char temp[128];
	char *cp, syear[5] = "20";
	_strdate(temp);
	cp = strtok(temp, "/");
	p->da_mon = atoi(cp);
	cp = strtok(NULL, "/");
	p->da_day = atoi(cp);
	cp = strtok(NULL, "/");
	strcat(syear, cp);
	p->da_year = atoi(syear);
}

void myFlush() {
	cin.clear();
	while (cin.get() != '\n') {
		;
	}
}