#pragma once
#include <string>
using namespace std;

class Computer
{
protected:
	string prdName;
	string proName;
	int memory;
	int price;
public:
	Computer(string prdName, string proName, int memory, int price);
	Computer(string prdName, int memory, int price, string proName);
	void setPrdName(string prdName);
	void setProName(string proName);
	void setPrice(int price);
	string getPrdName();
	string getProName();
	int getPrice();
	void showSpace();
	~Computer() {};
};

