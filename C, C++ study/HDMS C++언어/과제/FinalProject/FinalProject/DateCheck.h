#pragma once

class Check {
	int year; // 
	int month;
	int day;
	bool check; // ��¥�� �߸��Ǿ����� false ������ true
public:
	Check(int date = 20000000);
	~Check() {}
	void realCheck(); // ��¥ �˻�
	int leapCheck(); // ����˻�
	bool getCheck() { realCheck(); return check; } // ��¥ �˻� �� check ����
};
