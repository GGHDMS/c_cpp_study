#include"knight.h"

const string knight::name = "���";

knight::knight() :Charactor(knight::name) {}
knight::~knight() {}
void knight::fight()
{
	if (way != NULL)
	{
		cout << name << "�� �ο� �غ� �մϴ�." << endl;
		way->doFight();
	}
	else
	{
		cout << name << "�� ���⸦ ������ ���� �����Ƿ� �Ǽ����� �ο�ϴ�." << endl;
	}
}