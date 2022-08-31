#pragma once
#include <iostream>
#include <string>
using namespace std;
#include"Person.h"

class AccountBook {
private:
    int pCnt; // 저장된 사람 수 
    int budget;
    Person pList[10];
public:
    AccountBook();
    bool addPerson(string name, int money); // 전달인자로 받은 name과 money로 새로운 사람 등록. name은 새로운 사람의 이름, money는 새로운 사람이 갖고있는 돈.
    bool deletePerson(string name); // 전달인자로 받은 name으로 삭제할 data 찾아서 삭제 성공시 true, 실패시 false 리턴
    void showList(); // 사람별로 사용내역 출력 (날짜순), 총 금액, 예산 초과여부 출력
    int getBuget();
    void setBuget(int money);
    int calTotalMoney(); // 등록된 사람들이 갖고있는 총 액수 구해서 리턴

    //추가된 함수
    Person *getPList();
    int getPCnt();
    int getTotalUseMoney();
};
