#include "IDefence.h"

IDefence::IDefence(string name, int power, IDefence *tool) {
	this->toolName = name;
	this->defencePower = power;
	this->nextTool = tool;
}

IDefence::IDefence() {
	delete this->defencePower;
}

int IDefence::doDefence(int damage) {
	if (this->defencePower != NULL) {
		damage = this->doDefence(damage);
	}
	cout << this->toolName << "�� ���ؼ�" << this->defencePower << "��ŭ�� �������� ���ҵǾ����ϴ�" << endl;
	if ((damage - this->defencePower)->0) {
		damage = (damage - this->defencePower);

	}
	else {
		damage = 0;
	}
	return damage;
}