#pragma once
#include "MyString.h"
class MoneyBox {
private:
	MyString name; // ������
protected:
	int sum; // �ܾ�
public:
	MoneyBox(const char *np = "�ƹ���", int m = 0); // �����ε�������
	MoneyBox(const MoneyBox &br); // ���������
	void save(int m); // ����
	void use(int m); // ���
	void setName(MyString name); // name�������
	MyString getName(); // name���������
	void setSum(int sum); // sum�������
	int getSum(); // sum���������
};

