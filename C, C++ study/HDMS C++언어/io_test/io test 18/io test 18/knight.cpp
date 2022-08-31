#include"knight.h"

const string knight::name = "기사";

knight::knight() :Charactor(knight::name) {}
knight::~knight() {}
void knight::fight()
{
	if (way != NULL)
	{
		cout << name << "이 싸울 준비를 합니다." << endl;
		way->doFight();
	}
	else
	{
		cout << name << "는 무기를 가지고 있지 않으므로 맨손으로 싸웁니다." << endl;
	}
}