#pragma once
#include <iostream>
#include <string>
using namespace std;

class UseMoney {
private:
    int amount; // ����� �ݾ�
    string detail; // ��볻��
    bool income; // �����̸� true, �����̸� false
    int date; //��� ��¥
public:
    UseMoney(int amount = 0, string detail = "", bool income = true, int date = 20000000);
    int getAmount() const; // get�Լ� ���� const
    bool recordUseMoney(int amount, string detail, bool income, int date); //date�� �߸��Ǿ����� false ����
    int getDate() const; 
	string getDetail() const;
	bool getIncome() const;
    void showUseMoney();
	void setAmount(int amount);
	void setDetail(string detail);
	void setIncome(bool income);
	bool setDate(int date); // date�� �߸��Ǿ����� false ����
	UseMoney *getUseList() { return this; } // UseMoney �ּ� ����
};