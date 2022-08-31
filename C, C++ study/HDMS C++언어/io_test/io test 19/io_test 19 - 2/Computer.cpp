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
	cout << "��ǰ��Ī" << prdName << endl;
	cout << "���μ���" << proName << endl;
	cout << "�����ġ" << memory << endl;
	cout << "�ǸŰ���" << price << "��" << endl;
}


