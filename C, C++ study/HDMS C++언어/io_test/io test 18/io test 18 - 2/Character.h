#pragma once

#include"IDefence.h"

class Character {
private:
	IDefence * defenceTool;
public:
	Character();
	virtaul ~Character();
	void setDefenceTool(IDefence *tool);
	void doDefenceTest(int damage);

};
