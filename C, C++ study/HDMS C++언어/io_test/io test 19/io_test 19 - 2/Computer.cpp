#include "Computer.h"
#include <iostream>
using namespace std;


Computer::Computer(string prdName, string proName, int memory, int price) :prdName(prdName), proName(proName), memory(memory), price(price) { ; }

Computer::Computer(string prdName, int memory, int price, string proName) { this->prdName = proName; }
void Computer::setPrdName(string prdName) { this->prdName = prdName; }
void Computer::setProName(string proName) { this->proName = proName; }
void Computer::setPrice(int price) { this->price = price; }
string Computer::getPrdName() { return prdName; }
string Computer::getProName() { return proName; }
int Computer::getPrice() { return price; }
void Computer::showSpace(){
	cout << "제품명칭" << prdName << endl;
	cout << "프로세서" << proName << endl;
	cout << "기억장치" << memory << endl;
	cout << "판매가격" << price << "원" << endl;
}


