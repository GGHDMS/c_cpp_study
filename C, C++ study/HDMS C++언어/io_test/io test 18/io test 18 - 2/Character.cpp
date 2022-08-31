#include "Character.h"

Character::Character() {
	this->defenceTool = NULL;
}
Character::Character() {
	delete this->defenceTool;
}
void Character::setDefenceTool(IDefence *tool) {
	delete this->defenceTool;
	this->defenceTool = tool;
}

void Character::doDefenceTest(int damage) {
	if (this->defenceTool != NULL) {
		damage = this->defenceTool->doDefence;
	}
	cout << "최종 데미지 : " << damage << endl;
}