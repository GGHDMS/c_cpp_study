#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#include "UseMoney.h"



class Person {
private:
    int useCnt; // ����� ��� ���� ��
    int money; // ����� ���� �ݾ�
    string name; // ����� �̸�
    UseMoney useList[100]; // ��볻�� ���� �迭
public:
	//������
	Person(int money = 0, string name = "NONAME");
	//�Լ�
    bool putUseList(int amount, string detail, bool income, int date); // ���ο� ��볻���� �߰��ϴ� �Լ�.
    bool deleteUseList(string detail); // �Է¹��� �������� ����
    void sortUseList(); // ��볻�� �迭�� ��¥������ sort
	int sumMoney(); // ������� �Ѿ��� ���
	void showPerson(); // useList�� ����� ��� ���
	//get,set
	int getUseCnt();
	void setUseCnt(int c);
	int getMoney();
    void setMoney(int money);
    string getName();
    void setName(string name);
	UseMoney *getUseList();
};
