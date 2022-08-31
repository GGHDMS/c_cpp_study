#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#include "UseMoney.h"



class Person {
private:
    int useCnt; // 저장된 사용 내역 수
    int money; // 사용자 보유 금액
    string name; // 사용자 이름
    UseMoney useList[100]; // 사용내역 저장 배열
public:
	//생성자
	Person(int money = 0, string name = "NONAME");
	//함수
    bool putUseList(int amount, string detail, bool income, int date); // 새로운 사용내역을 추가하는 함수.
    bool deleteUseList(string detail); // 입력받은 내역으로 삭제
    void sortUseList(); // 사용내역 배열을 날짜순으로 sort
	int sumMoney(); // 사용자의 총액을 계산
	void showPerson(); // useList의 내용들 모두 출력
	//get,set
	int getUseCnt();
	void setUseCnt(int c);
	int getMoney();
    void setMoney(int money);
    string getName();
    void setName(string name);
	UseMoney *getUseList();
};
