#include "Happy.h"

Happy::Happy(string np, int money):name(np){
	this->money = money;
	list[0] = NULL;
	index = 0;
}
Happy::Happy(Happy &r):name(r.name){
	int i;
	money = r.money;
	for (i = 0; i < r.index; i++) {
		list[i] = new char[strlen(r.list[i]) + 1];
	}
	index = r.index;
}
Happy::~Happy(){
	int i;
	for (i = 0; i < index; i++) {
		delete[]list[i];
	}
}
Happy &Happy::operator=(Happy &r){
	int i;
	if (this == &r)return *this;
	for (i = 0; i < index; i++) {
		delete[]list[i];
	}
	index = r.index;
	for (i = 0; i < index; i++) {
		list[i] = new char[strlen(r.list[i]) + 1];
		strcpy(list[i], r.list[i]);
	}
	name = r.name;
	money = r.money;
	return *this;
}
void Happy::use(const char *str, int n){
	if (index == 100)return;
	if (money >= n) {
		money -= n;
		list[index] = new char[strlen(str) + 1];
		strcpy(list[index], str);
		index++;
	}
	else {
		cout << "금액이 부족합니다." << endl;
	}
}
Happy & Happy::winner(Happy &r){
	if (money > r.money) {
		return *this;
	}
	else {
		return r;
	}
}
void Happy::setName(string &name){
	this->name = name;
}
string & Happy::getName(){
	return name;
}
void Happy::setMoney(int money){
	if (this->money < 0) {
		this->money = 0;
	}
	else {
		this->money = money;
	}
}
int Happy::getMoney(){
	return money;
}
char **Happy::getList(){
	return list;
}
int Happy::getIndex(){
	return index;
}
