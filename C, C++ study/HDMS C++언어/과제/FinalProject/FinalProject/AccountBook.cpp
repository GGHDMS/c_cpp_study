#include "AccountBook.h"

AccountBook::AccountBook() :pCnt(0), budget(0) {}

bool AccountBook::addPerson(string name, int money) { // 전달인자로 받은 name과 money로 새로운 사람 등록. name은 새로운 사람의 이름, money는 새로운 사람이 갖고있는 돈.
    if (pCnt == 10) {
        cout << "구성원 추가 실패." << endl;
        return false;
    }

    pList[pCnt].setName(name);
    pList[pCnt++].setMoney(money);
    return true;
}

bool AccountBook::deletePerson(string name) { // 전달인자로 받은 name으로 삭제할 data 찾아서 삭제 성공시 true, 실패시 false 리턴
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

int AccountBook::calTotalMoney() { // 등록된 사람들이 갖고있는 총 액수 구해서 리턴
    int money = 0;
    for (int i = 0; i < pCnt; ++i) {
        money += pList[i].sumMoney();
    }

    return money;
}

void AccountBook::showList() { // 사람별로 사용내역 출력 (날짜순), 총 금액, 예산 초과여부 출력
	if (pCnt == 0)
	{
		cout << "등록된 가족이 없습니다." << endl;
		return;
	}
    for (int i = 0; i < pCnt; ++i) {
        pList[i].showPerson();
        cout<<"------------------"<<endl;
    }
    cout << "총 금액 : " << calTotalMoney() << endl ;
    cout << "예산 : " << budget << endl;
    cout << "총 사용 금액 : " << getTotalUseMoney() << endl;
    int gap = budget - getTotalUseMoney();
    if (gap < 0) {
        cout << "예산을 " << -gap << "원 초과했습니다." << endl;
    } else {
        cout << "예산이 " << gap << "원 남았습니다." << endl;
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
