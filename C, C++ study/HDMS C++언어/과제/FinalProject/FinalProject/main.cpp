#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include"AccountBook.h"

int menu(const char **menuList, int menuCnt); // 전달된 메뉴를 출력하고 정확한 메뉴번호를 리턴하는 함수
int controlMenuSelect(string message, int menuCnt); // 가전제품의 상태변경 처리를 위한 메뉴 함수
void displayTitle(string title); // 처리중인 내용 출력하기 위한 타이틀 출력함수 
void screen(AccountBook &rAc); // 주메뉴를 출력하고 메뉴를 선택받아 반복적으로 주메뉴를 처리하는 함수
int inputInteger(const char *message);  //  message를 출력하고 정수값 입력 받아 리턴(문자, 실수값 예외 처리)
int inputInteger(string message); //  message를 출력하고 정수값 입력 받아 리턴(문자, 실수값 예외 처리)
void myFlush();  // cin입력 버퍼를 모두 비우고 fail상태를 초기상태로 재설정
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

// 예산 수정 메뉴 추가하기

void screen(AccountBook &rAc) {
    const char *menuList[] = { "구성원 추가 ", "구성원 삭제 ", "사용내역 입력 ", "사용내역 삭제 ", "전체 사용내역 출력 ", "예산 수정", "종료 " };
    int menuCnt = sizeof(menuList) / sizeof(menuList[0]);
    int menuNum;

    displayTitle("가계부 프로그램 시작");

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

    displayTitle("가계부 프로그램 종료");
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
    int menuNum = 0; /* 입력된 메뉴 번호 저장 변수*/

    cout << endl << "==================================" << endl;
    for (i = 0; i < menuCnt; i++) {
        cout << i + 1 << "." << menuList[i] << endl;
    }
    cout << "==================================" << endl;
    while (menuNum<1 || menuNum>menuCnt)  /* 범위 내의 번호가 입력될 때 까지 반복*/
    {
        menuNum = inputInteger("# 메뉴번호를 입력하세요 : ");

    }
    return menuNum;
}

void displayTitle(string title) // 화면 타이틀 출력 함수
{
    cout << endl << "------------------------------" << endl;
    cout << "    " << title << endl;
    cout << "------------------------------" << endl;
}

// message를 출력하고 정수값 입력 받아 리턴(문자, 실수값 예외 처리)
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

// message를 출력하고 정수값 입력 받아 리턴(문자, 실수값 예외 처리)
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

// 기능 : cin입력 버퍼를 모두 비우고 fail상태를 초기상태로 재설정
void myFlush() {
    cin.clear();  // 에러로 설정되어있는 flag멤버의 값을 0으로 재초기화
    while (cin.get() != '\n');  // 개행문자가 나올때까지 버퍼내의 모든 문자 지움
}


void addPerson(AccountBook &rAc) {
    string tmpName;
    int money;

    cout << "추가할 구성원의 이름을 입력하세요 : ";
    cin >> tmpName;
    while (true) {
        money = inputInteger("새로운 구성원이 소지한 총 금액을 입력하세요 : ");
        if (money < 0) continue;
        else break;          
    }

    if (rAc.addPerson(tmpName, money) == true) {
        cout << "등록 완료." << endl;
    } else {
        cout << "등록 실패." << endl;
    }
}

void deletePerson(AccountBook &rAc) {
    string tmpName;

    cout << "삭제할 구성원의 이름을 입력하세요 : ";
    cin >> tmpName;

    char tmpChar;
    myFlush();
    cout << "삭제하시겠습니까? (삭제는 'Y', 삭제취소는 'N' 입력): ";
    cin.get(tmpChar);
    if (tmpChar == 'Y' || tmpChar == 'y') {
        if (rAc.deletePerson(tmpName) == true) {
            cout << "삭제 완료." << endl;
        } else {
            cout << "삭제 실패." << endl;
        }
    }
    myFlush();
    
}

void recordUse(AccountBook &rAc) {
    int index;
    bool findFlag = false;
    string tmpName;

    cout << "사용내역을 추가할 구성원의 이름을 입력하세요 : ";
    cin >> tmpName;

    for (index = 0; index < rAc.getPCnt(); ++index) {
        if (tmpName == rAc.getPList()[index].getName()) {
            findFlag = true;
            break;
        }
    }

    if (findFlag == false) {
        cout << "존재하지 않는 이름입니다." << endl;
        return;
    }

    int amount;
    amount = inputInteger("금액을 입력하세요 : ");

    string detail;
    cout << "사용내역을 입력하세요 : ";
    detail = getString();

    int date;
    date = inputInteger("날짜를 입력하세요 : ");

    bool income;
    char tmpChar;
    while (true) {
        cout << "수입인지 지출인지 입력하세요 (수입이면 'I', 지출이면 'E' 입력): ";
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
        cout << "등록 완료." << endl;
    } else {
        cout << "등록 실패." << endl;
    }

}

void deleteUse(AccountBook &rAc) {
    int index;
    bool findFlag = false;
    string tmpName;

    cout << "사용내역을 삭제할 구성원의 이름을 입력하세요 : ";
    cin >> tmpName;

    for (index = 0; index < rAc.getPCnt(); ++index) {
        if (tmpName == rAc.getPList()[index].getName()) {
            findFlag = true;
            break;
        }
    }

    if (findFlag == false) {
        cout << "존재하지 않는 이름입니다." << endl;
        return;
    }

    rAc.getPList()[index].showPerson();

    string detail;
    cout << "삭제할 데이터의 사용내역을 입력하세요 : ";
    myFlush();
    detail = getString();

    char tmpChar;
    cout << "삭제하시겠습니까? (삭제는 'Y', 삭제취소는 'N' 입력): ";
    cin.get(tmpChar);
    if (tmpChar == 'Y' || tmpChar == 'y') {
        if (rAc.getPList()[index].deleteUseList(detail)) {
            cout << "삭제 완료." << endl;
        } else {
            cout << "삭제 실패." << endl;
        }
    }
    myFlush();
    
    
}

void modifyBudget(AccountBook &rAc) {
    int budget = inputInteger("예산을 입력하세요 : ");
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
        cout << "데이터 불러오기 실패" << endl;
    } else {
        char tmpChar;
        cout << "저장된 데이터를 불러오시겠습니까? (불러오기는 'Y', 불러오기 안함은 'N' 입력) : ";
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
            cout << "불러오기 완료" << endl;
        }
    }
    fin.close();
}

void SaveData(AccountBook &rAc) {
    ofstream fout("C:\\data\\budgetBook.txt");
    if (fout.fail()) {
        cout << "데이터 저장 실패" << endl;
    } else {
        char tmpChar;
        cout << "데이터를 저장하시겠습니까? (저장은 'Y', 저장 안함은 'N' 입력) : ";
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
            cout << "저장 완료" << endl;
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