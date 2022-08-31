 
#include "Person.h"
int compare(const UseMoney* one, UseMoney* two)
{
	return (one->getDate() > two->getDate()) ? -1 : 1;
}
// ������
Person::Person(int money, string name)// name�� Null string, money�� 0���� �ʱ�ȭ
{
	this->useCnt = 0;
	this->money = money;
	this->name = name;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
// �Լ�
bool Person::putUseList(int amount, string detail, bool income, int date)
{
	if (this->useCnt >= 100) return false; // ��볻������ �迭�� ũ�Ⱑ �� á���� false return
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
	if (this->useCnt <= 0) return false; // ������ ��볻���� ������ flase return
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
	
	return false; // ������ ��볻���� ������ false return
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
		if (useList[i].getIncome() == true) // �����̸� �Ѿ� ����
		{
			tmpMoney += useList[i].getAmount();
		}
		else if (useList[i].getIncome() == false)
		{
			tmpMoney -= useList[i].getAmount(); // �����̸� �Ѿ� ����
		}
	}

	return tmpMoney;
}
void Person::showPerson()
{
    cout << "<<< �̸� : " << name << " ���� ��볻���Դϴ�.>>>" << endl;
	if (useCnt == 0)
	{
		cout << "���� ��ϵ� �̿볻���� �����ϴ�." << endl;
        cout << "�� ���� �ݾ� : " << sumMoney() << endl;
		return;
	}
	sortUseList();
	for (int i = 0; i < useCnt; i++)
	{
		if (useList[i].getIncome() == true)
		{
			cout << "/ ��¥ : " << useList[i].getDate() << " / �׸� : ����" <<  " / �ݾ� : " << useList[i].getAmount() << " / ��볻�� : " << useList[i].getDetail() << " /"<< endl;
		}
		else
		{
			cout << "/ ��¥ : " << useList[i].getDate() << " / �׸� : ����" <<  " / �ݾ� : " << useList[i].getAmount() << " / ��볻�� : " << useList[i].getDetail() << " /" << endl;
		}

	}
	cout << "�� ���� �ݾ� : " << sumMoney() << endl;
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
		cout << "��볻�� �׸��� 100���� �Ѿ �� �����ϴ�!" << endl;
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