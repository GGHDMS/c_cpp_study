#pragma once
#include "MoneyBox.h"

class iMoneyBox :public MoneyBox {
private:
	int limit;
public:
	iMoneyBox(const char *np = "¾Æ¹«°³", int m = 0, int l = 1000);
	void setLimit(int limit);
	void save(int m);
	int getLimit();
	int check();
};
