#pragma once
#include"IFight.h"
class FightWithAx : public IFight
{
public:
	FightWithAx();
	virtual ~FightWithAx();
	void doFight();
};