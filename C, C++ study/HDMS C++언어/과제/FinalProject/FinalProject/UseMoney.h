#pragma once
#include <iostream>
#include <string>
using namespace std;

class UseMoney {
private:
    int amount; // 사용한 금액
    string detail; // 사용내역
    bool income; // 수입이면 true, 지출이면 false
    int date; //사용 날짜
public:
    UseMoney(int amount = 0, string detail = "", bool income = true, int date = 20000000);
    int getAmount() const; // get함수 전부 const
    bool recordUseMoney(int amount, string detail, bool income, int date); //date가 잘못되었으면 false 리턴
    int getDate() const; 
	string getDetail() const;
	bool getIncome() const;
    void showUseMoney();
	void setAmount(int amount);
	void setDetail(string detail);
	void setIncome(bool income);
	bool setDate(int date); // date가 잘못되었으면 false 리턴
	UseMoney *getUseList() { return this; } // UseMoney 주소 리턴
};