#pragma once
#include<iostream>
using namespace std;

class IFight
{
public:
	virtual void doFight()=0;
	IFight() {}
	virtual ~IFight() {}
};