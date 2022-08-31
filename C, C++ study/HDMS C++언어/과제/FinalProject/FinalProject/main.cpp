#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include"AccountBook.h"

int menu(const char **menuList, int menuCnt); // ���޵� �޴��� ����ϰ� ��Ȯ�� �޴���ȣ�� �����ϴ� �Լ�
int controlMenuSelect(string message, int menuCnt); // ������ǰ�� ���º��� ó���� ���� �޴� �Լ�
void displayTitle(string title); // ó������ ���� ����ϱ� ���� Ÿ��Ʋ ����Լ� 
void screen(AccountBook &rAc); // �ָ޴��� ����ϰ� �޴��� ���ù޾� �ݺ������� �ָ޴��� ó���ϴ� �Լ�
int inputInteger(const char *message);  //  message�� ����ϰ� ������ �Է� �޾� ����(����, �Ǽ��� ���� ó��)
int inputInteger(string message); //  message�� ����ϰ� ������ �Է� �޾� ����(����, �Ǽ��� ���� ó��)
void myFlush();  // cin�Է� ���۸� ��� ���� fail���¸� �ʱ���·� �缳��
string getString();

void addPerson(AccountBook &rAc);
void deletePerson(AccountBook &rAc);
void recordUse(AccountBook &rAc);
void deleteUse(AccountBook &rAc);
void showUseList(AccountBook &rAc);
void modifyBudget(AccountBook &rAc);

void LoadData(AccountBook &rAc);
void SaveData(AccountBook &rAc);

int main() {
    AccountBook accountBook1;

    LoadData(accountBook1);

    screen(accountBook1);

    SaveData(accountBook1);

    getchar(); getchar();
    return 0;
}

// ���� ���� �޴� �߰��ϱ�

void screen(AccountBook &rAc) {
    const char *menuList[] = { "������ �߰� ", "������ ���� ", "��볻�� �Է� ", "��볻�� ���� ", "��ü ��볻�� ��� ", "���� ����", "���� " };
    int menuCnt = sizeof(menuList) / sizeof(menuList[0]);
    int menuNum;

    displayTitle("����� ���α׷� ����");

    if (rAc.getBuget() == 0) {
        modifyBudget(rAc);
    }
    
    while (true) {
        menuNum = menu((const char**)menuList, menuCnt);
        if (menuNum == menuCnt) { break; }
        displayTitle(menuList[menuNum - 1]);
        switch (menuNum) {
        case 1: addPerson(rAc); break;
        case 2: deletePerson(rAc); break;
        case 3: recordUse(rAc); break;
        case 4: deleteUse(rAc); break;
        case 5: showUseList(rAc); break;
        case 6: modifyBudget(rAc); break;
        }
    }

    displayTitle("����� ���α׷� ����");
    return;
}

int controlMenuSelect(string message, int menuCnt) {
    int menuNum;

    while (true) {
        menuNum = inputInteger(message);
        if (menuNum > 0 && menuNum <= menuCnt) { break; }
    }
    return menuNum;
}

int menu(const char **menuList, int menuCnt) {
    int i;
    int menuNum = 0; /* �Էµ� �޴� ��ȣ ���� ����*/

    cout << endl << "==================================" << endl;
    for (i = 0; i < menuCnt; i++) {
        cout << i + 1 << "." << menuList[i] << endl;
    }
    cout << "==================================" << endl;
    while (menuNum<1 || menuNum>menuCnt)  /* ���� ���� ��ȣ�� �Էµ� �� ���� �ݺ�*/
    {
        menuNum = inputInteger("# �޴���ȣ�� �Է��ϼ��� : ");

    }
    return menuNum;
}

void displayTitle(string title) // ȭ�� Ÿ��Ʋ ��� �Լ�
{
    cout << endl << "------------------------------" << endl;
    cout << "    " << title << endl;
    cout << "------------------------------" << endl;
}

// message�� ����ϰ� ������ �Է� �޾� ����(����, �Ǽ��� ���� ó��)
int inputInteger(const char *message) {
    int number;

    while (1) {
        cout << message;
        cin >> number;

        if (cin.get() == '\n') {
            if (number >= 0) {
                return number;
            } else {
                continue;
            }
        }

        myFlush();
    }
}

// message�� ����ϰ� ������ �Է� �޾� ����(����, �Ǽ��� ���� ó��)
int inputInteger(string message) {
    int number;

    while (1) {
        cout << message;
        cin >> number;

        if (cin.get() == '\n') {
            if (number >= 0) {
                return number;
            } else {
                continue;
            }
        }

        myFlush();
    }
}

// ��� : cin�Է� ���۸� ��� ���� fail���¸� �ʱ���·� �缳��
void myFlush() {
    cin.clear();  // ������ �����Ǿ��ִ� flag����� ���� 0���� ���ʱ�ȭ
    while (cin.get() != '\n');  // ���๮�ڰ� ���ö����� ���۳��� ��� ���� ����
}


void addPerson(AccountBook &rAc) {
    string tmpName;
    int money;

    cout << "�߰��� �������� �̸��� �Է��ϼ��� : ";
    cin >> tmpName;
    while (true) {
        money = inputInteger("���ο� �������� ������ �� �ݾ��� �Է��ϼ��� : ");
        if (money < 0) continue;
        else break;          
    }

    if (rAc.addPerson(tmpName, money) == true) {
        cout << "��� �Ϸ�." << endl;
    } else {
        cout << "��� ����." << endl;
    }
}

void deletePerson(AccountBook &rAc) {
    string tmpName;

    cout << "������ �������� �̸��� �Է��ϼ��� : ";
    cin >> tmpName;

    char tmpChar;
    myFlush();
    cout << "�����Ͻðڽ��ϱ�? (������ 'Y', ������Ҵ� 'N' �Է�): ";
    cin.get(tmpChar);
    if (tmpChar == 'Y' || tmpChar == 'y') {
        if (rAc.deletePerson(tmpName) == true) {
            cout << "���� �Ϸ�." << endl;
        } else {
            cout << "���� ����." << endl;
        }
    }
    myFlush();
    
}

void recordUse(AccountBook &rAc) {
    int index;
    bool findFlag = false;
    string tmpName;

    cout << "��볻���� �߰��� �������� �̸��� �Է��ϼ��� : ";
    cin >> tmpName;

    for (index = 0; index < rAc.getPCnt(); ++index) {
        if (tmpName == rAc.getPList()[index].getName()) {
            findFlag = true;
            break;
        }
    }

    if (findFlag == false) {
        cout << "�������� �ʴ� �̸��Դϴ�." << endl;
        return;
    }

    int amount;
    amount = inputInteger("�ݾ��� �Է��ϼ��� : ");

    string detail;
    cout << "��볻���� �Է��ϼ��� : ";
    detail = getString();

    int date;
    date = inputInteger("��¥�� �Է��ϼ��� : ");

    bool income;
    char tmpChar;
    while (true) {
        cout << "�������� �������� �Է��ϼ��� (�����̸� 'I', �����̸� 'E' �Է�): ";
        cin.get(tmpChar);
        if (tmpChar == 'I' || tmpChar == 'i') {
            income = true;
            break;
        } else if (tmpChar == 'E' || tmpChar == 'e') {
            income = false;
            break;
        } else {
            myFlush();
            continue;
        }
    }

    if (rAc.getPList()[index].putUseList(amount, detail, income, date)) {
        cout << "��� �Ϸ�." << endl;
    } else {
        cout << "��� ����." << endl;
    }

}

void deleteUse(AccountBook &rAc) {
    int index;
    bool findFlag = false;
    string tmpName;

    cout << "��볻���� ������ �������� �̸��� �Է��ϼ��� : ";
    cin >> tmpName;

    for (index = 0; index < rAc.getPCnt(); ++index) {
        if (tmpName == rAc.getPList()[index].getName()) {
            findFlag = true;
            break;
        }
    }

    if (findFlag == false) {
        cout << "�������� �ʴ� �̸��Դϴ�." << endl;
        return;
    }

    rAc.getPList()[index].showPerson();

    string detail;
    cout << "������ �������� ��볻���� �Է��ϼ��� : ";
    myFlush();
    detail = getString();

    char tmpChar;
    cout << "�����Ͻðڽ��ϱ�? (������ 'Y', ������Ҵ� 'N' �Է�): ";
    cin.get(tmpChar);
    if (tmpChar == 'Y' || tmpChar == 'y') {
        if (rAc.getPList()[index].deleteUseList(detail)) {
            cout << "���� �Ϸ�." << endl;
        } else {
            cout << "���� ����." << endl;
        }
    }
    myFlush();
    
    
}

void modifyBudget(AccountBook &rAc) {
    int budget = inputInteger("������ �Է��ϼ��� : ");
    rAc.setBuget(budget);
}

void showUseList(AccountBook &rAc) {
    rAc.showList();
}

void LoadData(AccountBook &rAc) {
    int budget;
    int pCnt;
    string name;
    int money;
    int useCnt;
    int amount;
    string detail;
    char tmpDetail[20];
    bool income;
    int date;

    ifstream fin("C:\\data\\budgetBook.txt");
    if (fin.fail()) {
        cout << "������ �ҷ����� ����" << endl;
    } else {
        char tmpChar;
        cout << "����� �����͸� �ҷ����ðڽ��ϱ�? (�ҷ������ 'Y', �ҷ����� ������ 'N' �Է�) : ";
        cin.get(tmpChar);
        if (tmpChar == 'Y' || tmpChar == 'y') {
            fin >> budget;
            rAc.setBuget(budget);
            fin >> pCnt;
            for (int i = 0; i < pCnt; ++i) {
                fin >> name;
                fin >> money;
                rAc.addPerson(name, money);
                fin >> useCnt;
                for (int j = 0; j < useCnt; ++j) {
                    fin >> amount;

                    while (fin.get() != '\n');
                    fin.getline(tmpDetail, sizeof(tmpDetail) / sizeof(tmpDetail[0]));
                    detail = tmpDetail;

                    fin >> income;
                    fin >> date;

                    rAc.getPList()[i].putUseList(amount, detail, income, date);
                    if (rAc.getPList()[i].getUseList()[i].getIncome() == true) {
                        money -= rAc.getPList()[i].getUseList()[i].getAmount();
                    } else {
                        money += rAc.getPList()[i].getUseList()[i].getAmount();
                    }
                }
            }
            cout << "�ҷ����� �Ϸ�" << endl;
        }
    }
    fin.close();
}

void SaveData(AccountBook &rAc) {
    ofstream fout("C:\\data\\budgetBook.txt");
    if (fout.fail()) {
        cout << "������ ���� ����" << endl;
    } else {
        char tmpChar;
        cout << "�����͸� �����Ͻðڽ��ϱ�? (������ 'Y', ���� ������ 'N' �Է�) : ";
        cin.get(tmpChar);
        if (tmpChar == 'Y' || tmpChar == 'y') {
            fout << rAc.getBuget() << endl;
            fout << rAc.getPCnt() << endl;
            for (int i = 0; i < rAc.getPCnt(); ++i) {
                fout << rAc.getPList()[i].getName() << endl;
                fout << rAc.getPList()[i].getMoney() << endl;
                fout << rAc.getPList()[i].getUseCnt() << endl;
                for (int j = 0; j < rAc.getPList()[i].getUseCnt(); ++j) {
                    fout << rAc.getPList()[i].getUseList()[j].getAmount() << endl;
                    fout << rAc.getPList()[i].getUseList()[j].getDetail() << endl;
                    fout << rAc.getPList()[i].getUseList()[j].getIncome() << endl;
                    fout << rAc.getPList()[i].getUseList()[j].getDate() << endl;
                }
            }
            cout << "���� �Ϸ�" << endl;
        }
    }
    fout.close();
}


string getString() {
    int len = 0;
    char *tmpString = new char[20];

    while (int tmpChar = cin.get()) {
        if (tmpChar == '\n'/* || tmpChar == ' '*/) {
            tmpString[len] = '\0';
            break;
        }
        tmpString[len++] = tmpChar;
        if (len % 20 == 0) {
            tmpString[len - 1] = '\0';
            myFlush();
            break;
        }
    }

    string tmp(tmpString);

    return tmp;
}