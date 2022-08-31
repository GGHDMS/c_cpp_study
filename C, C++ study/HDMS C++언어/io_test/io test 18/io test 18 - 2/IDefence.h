#pragma once
#include <iostream>
#include <string>
using namespace std;

class IDefence {
protected:
	string toolName;
	int defencePower;
	IDefence *nextTool;
public:
	IDefence(string naem, int power, IDefence *tool);
	~IDefence();
	int doDefence(int damage);
};
