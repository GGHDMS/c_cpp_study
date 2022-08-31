#pragma once
#include <iostream>
#include <string>
using namespace std;
#include"Person.h"

class AccountBook {
private:
    int pCnt; // ����� ��� �� 
    int budget;
    Person pList[10];
public:
    AccountBook();
    bool addPerson(string name, int money); // �������ڷ� ���� name�� money�� ���ο� ��� ���. name�� ���ο� ����� �̸�, money�� ���ο� ����� �����ִ� ��.
    bool deletePerson(string name); // �������ڷ� ���� name���� ������ data ã�Ƽ� ���� ������ true, ���н� false ����
    void showList(); // ������� ��볻�� ��� (��¥��), �� �ݾ�, ���� �ʰ����� ���
    int getBuget();
    void setBuget(int money);
    int calTotalMoney(); // ��ϵ� ������� �����ִ� �� �׼� ���ؼ� ����

    //�߰��� �Լ�
    Person *getPList();
    int getPCnt();
    int getTotalUseMoney();
};
