#pragma once
#include <iostream>
using namespace std;

class MyString {
private:
	char *str;
	int len;
public:
	MyString();
	MyString(const char *cp);
	MyString(const MyString &br);
	~MyString();
	MyString &operator=(const MyString &br);
	MyString operator+(const MyString &br);
	bool operator>(const MyString &br);
	friend ostream & operator<<(ostream &, const MyString &);
	friend istream & operator>>(istream &, MyString &);
	//getter, setter 멤버함수 추가
	void setStr(const char *cp);
	char * getStr(void)const;
	int getLen(void)const;

};