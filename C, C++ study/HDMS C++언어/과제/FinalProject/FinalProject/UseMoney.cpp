#include "UseMoney.h"
#include "DateCheck.h"

UseMoney::UseMoney(int amount, string detail, bool income, int date):amount(amount), detail(detail), income(income), date(date) { }

int UseMoney::getAmount() const{
    return amount;
}
bool UseMoney::recordUseMoney(int amount, string detail, bool income, int date) {
	if (1) {
		Check d(date);
		if (d.getCheck()) {
			this->date = date;
		}
		else {
			cout << "잘못된 날짜 입니다." << endl;
			return false;
		}
	}
    this->income = income;
    this->amount = amount;
	this->detail = detail;
	return true;
 }

int UseMoney::getDate() const {
    return date;
}

string UseMoney::getDetail() const {
	return detail;
}

void UseMoney::showUseMoney() {
    const char *incomeOrExpense;
    if (income == true) {
        incomeOrExpense = "수입 ";
    } else {
        incomeOrExpense = "지출";
    }
    cout << "날짜 : " << date << " / "<< incomeOrExpense << " / 금액 : " << amount << " / 사용내역 : " << detail << endl;
}

bool UseMoney::getIncome() const {
	return income;
}

void UseMoney::setAmount(int amount) {
	if (amount < 0) {
		this->amount = 0;
	}
	else{
		this->amount = amount;
	}
}

void UseMoney::setDetail(string detail){
	this->detail = detail;
}

void UseMoney::setIncome(bool income) {
	this->income = income;
}

bool UseMoney::setDate(int date) {
	Check d(date);
	if (d.getCheck()) {
		this->date = date;
        return true;
	}
	else {
		cout << "날짜가 잘못 되었습니다." << endl;
		return false;
	}
}
