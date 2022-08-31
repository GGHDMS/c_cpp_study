#pragma once
#include<string>
#include"IFight.h"

class Charactor
{
protected:
	string name;
	IFight *way;
public:
	Charactor(string name);
	~Charactor();
	void setWay(IFight *way);
	virtual void fight()=0;
};