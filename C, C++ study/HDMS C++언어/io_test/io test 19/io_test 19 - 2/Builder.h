#pragma once
#include "Computer.h"

class Builder
{
	Computer *computer;
	Builder();
public:
	static Builder *instance;
	static Builder *getInstance();
	Builder * getComputer();
	Builder * setProName(string proName);
	Builder * setPrdName(string prdName);
	Builder * setMemory(int memory);
	Builder * setPrice(int price);
	~Builder();
};

