#pragma once
#include <string>
#include <iostream>
using namespace std;

class Happy{
private:
	string name;
	int money;
	char *list[100];
	int index;
public:
	Happy(string np = "", int money = 10000);
	Happy(Happy &r);
	~Happy();
	Happy &operator=(Happy &r);
	void use(const char *, int n);
	Happy &winner(Happy &r);
	void setName(string &name);
	string & getName();
	void setMoney(int money);
	int getMoney();
	char **getList();
	int getIndex();
};
