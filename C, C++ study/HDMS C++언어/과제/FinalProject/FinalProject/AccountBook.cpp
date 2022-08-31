#include "AccountBook.h"

AccountBook::AccountBook() :pCnt(0), budget(0) {}

bool AccountBook::addPerson(string name, int money) { // �������ڷ� ���� name�� money�� ���ο� ��� ���. name�� ���ο� ����� �̸�, money�� ���ο� ����� �����ִ� ��.
    if (pCnt == 10) {
        cout << "������ �߰� ����." << endl;
        return false;
    }

    pList[pCnt].setName(name);
    pList[pCnt++].setMoney(money);
    return true;
}

bool AccountBook::deletePerson(string name) { // �������ڷ� ���� name���� ������ data ã�Ƽ� ���� ������ true, ���н� false ����
    int index;
    bool findFlag = false;
    for (index = 0; index < pCnt; ++index) {
        if (pList[index].getName() == name) {
            findFlag = true;
            break;
        }
    }

    if (findFlag == false) {
        return false;
    }

    for (++index; index < pCnt; ++index) {
        pList[index - 1] = pList[index];
    }

    --pCnt;
    return true;
}

int AccountBook::getBuget() {
    return budget;
}

void AccountBook::setBuget(int money) {
    budget = money;
}

int AccountBook::calTotalMoney() { // ��ϵ� ������� �����ִ� �� �׼� ���ؼ� ����
    int money = 0;
    for (int i = 0; i < pCnt; ++i) {
        money += pList[i].sumMoney();
    }

    return money;
}

void AccountBook::showList() { // ������� ��볻�� ��� (��¥��), �� �ݾ�, ���� �ʰ����� ���
	if (pCnt == 0)
	{
		cout << "��ϵ� ������ �����ϴ�." << endl;
		return;
	}
    for (int i = 0; i < pCnt; ++i) {
        pList[i].showPerson();
        cout<<"------------------"<<endl;
    }
    cout << "�� �ݾ� : " << calTotalMoney() << endl ;
    cout << "���� : " << budget << endl;
    cout << "�� ��� �ݾ� : " << getTotalUseMoney() << endl;
    int gap = budget - getTotalUseMoney();
    if (gap < 0) {
        cout << "������ " << -gap << "�� �ʰ��߽��ϴ�." << endl;
    } else {
        cout << "������ " << gap << "�� ���ҽ��ϴ�." << endl;
    }
    cout << endl;
}

Person *AccountBook::getPList() {
    return pList;
}

int AccountBook::getPCnt() {
    return pCnt;
}

int AccountBook::getTotalUseMoney() {
    int useAmount = 0;

    for (int i = 0; i < pCnt; ++i) {
        for (int j = 0; j < pList[i].getUseCnt(); ++j) {
            if (pList[i].getUseList()[j].getIncome()) {
                ;
            } else {
                useAmount += pList[i].getUseList()[j].getAmount();
            }
        }
    }

    return useAmount;
}
