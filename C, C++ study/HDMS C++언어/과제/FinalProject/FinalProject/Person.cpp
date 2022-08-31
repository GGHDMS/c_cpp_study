 
#include "Person.h"
int compare(const UseMoney* one, UseMoney* two)
{
	return (one->getDate() > two->getDate()) ? -1 : 1;
}
// 생성자
Person::Person(int money, string name)// name을 Null string, money를 0으로 초기화
{
	this->useCnt = 0;
	this->money = money;
	this->name = name;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
// 함수
bool Person::putUseList(int amount, string detail, bool income, int date)
{
	if (this->useCnt >= 100) return false; // 사용내역저장 배열의 크기가 꽉 찼으면 false return
    if (!income) {
        if (sumMoney() - amount < 0) return false;
    }
    if (this->useList[this->useCnt].recordUseMoney(amount, detail, income, date)) {
        useCnt++;
        return true;
    }

	return false;
}
bool Person::deleteUseList(string detail)
{
	if (this->useCnt <= 0) return false; // 삭제할 사용내역이 없으면 flase return
	for (int i = 0; i < useCnt; i++)
	{
		if (detail == this->useList[i].getDetail())
		{
			for (int j = i; j < useCnt; j++)
			{
				this->useList[j].setDetail(this->useList[j + 1].getDetail());
			}
			//this->useList[this->useCnt].recordUseMoney(0,"", 0, 20000000);
			useCnt--;			
			return true;
		}
	}
	
	return false; // 삭제할 사용내역이 없으면 false return
}
void Person::sortUseList()
{
	qsort(this->useList, useCnt, sizeof(this->useList[0]), reinterpret_cast<int(*)(const void*, const void*)>(compare));
}
int Person::sumMoney()
{
	int tmpMoney = money;
	for (int i = 0; i < useCnt; i++)
	{
		if (useList[i].getIncome() == true) // 수입이면 총액 증가
		{
			tmpMoney += useList[i].getAmount();
		}
		else if (useList[i].getIncome() == false)
		{
			tmpMoney -= useList[i].getAmount(); // 지출이면 총액 감소
		}
	}

	return tmpMoney;
}
void Person::showPerson()
{
    cout << "<<< 이름 : " << name << " 님의 사용내역입니다.>>>" << endl;
	if (useCnt == 0)
	{
		cout << "아직 등록된 이용내역이 없습니다." << endl;
        cout << "총 보유 금액 : " << sumMoney() << endl;
		return;
	}
	sortUseList();
	for (int i = 0; i < useCnt; i++)
	{
		if (useList[i].getIncome() == true)
		{
			cout << "/ 날짜 : " << useList[i].getDate() << " / 항목 : 수입" <<  " / 금액 : " << useList[i].getAmount() << " / 사용내역 : " << useList[i].getDetail() << " /"<< endl;
		}
		else
		{
			cout << "/ 날짜 : " << useList[i].getDate() << " / 항목 : 지출" <<  " / 금액 : " << useList[i].getAmount() << " / 사용내역 : " << useList[i].getDetail() << " /" << endl;
		}

	}
	cout << "총 보유 금액 : " << sumMoney() << endl;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
 // get,set
int Person::getUseCnt()
{
	return this->useCnt;
}
void Person::setUseCnt(int c)
{
	if (c > 100)
	{
		cout << "사용내역 항목이 100개를 넘어갈 수 없습니다!" << endl;
		return;
	}
	this->useCnt = c;
}
int Person::getMoney()
{
	return  this->money;
}
void Person::setMoney(int money)
{
	this->money = money;
}
string Person::getName()
{
	return this->name;
}
void Person::setName(string name)
{
	this->name = name;
}
UseMoney *Person::getUseList()
{
	return this->useList;
}