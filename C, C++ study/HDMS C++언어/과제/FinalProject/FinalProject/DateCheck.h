#pragma once

class Check {
	int year; // 
	int month;
	int day;
	bool check; // 날짜가 잘못되었으면 false 맞으면 true
public:
	Check(int date = 20000000);
	~Check() {}
	void realCheck(); // 날짜 검사
	int leapCheck(); // 윤년검사
	bool getCheck() { realCheck(); return check; } // 날짜 검사 후 check 리턴
};
