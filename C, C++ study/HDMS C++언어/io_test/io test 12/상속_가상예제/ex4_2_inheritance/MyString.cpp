#include<ostream>
using namespace std;
#include "MyString.h"

MyString::MyString() // 디폴트 생성자
{
	this->len = 0;
	this->str = new char[this->len + 1];
	strcpy(this->str, "");
	//cout << __FUNCTION__ << "()" << endl;
}
MyString::MyString(const char *cp)  // 오버로디드 생성자
{
	this->len = strlen(cp);
	this->str = new char[this->len + 1];
	strcpy(this->str, cp);
}
MyString::MyString(const MyString &br) // 복사 생성자
{
	this->len = br.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, br.str);
}
MyString::~MyString() // 소멸자
{
	delete[] this->str;
}
MyString &MyString::operator=(const MyString &br) // 대입연산자 멤버함수
{
	if (this == &br) {  // 나 = 나; 방지 코드
		return *this;
	}
	delete[] this->str; // 메모리 누수 방지 코드
	this->len = br.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, br.str);
	return *this;
}
MyString MyString::operator+(const MyString &br) // 덧셈 연산자
{
	char *cp;
	cp = new char[this->len + br.len + 1];
	strcpy(cp, this->str);
	strcat(cp, br.str);
	MyString temp(cp);
	delete[] cp;
	return temp;
	/*char temp[1000];
	strcpy(temp, this->str);
	strcat(temp, br.str);
	return MyString(temp);*/
}
bool MyString::operator>(const MyString &br) // 관계연산자 멤버함수
{
	return (this->len > br.len);
}
void MyString::setStr(const char *cp)
{
	if (this->str == cp) { // 내 문자열로 객체를 재초기화 방지 코드
		return;
	}
	delete[] this->str;
	this->len = strlen(cp);
	this->str = new char[this->len + 1];
	strcpy(this->str, cp);
}
char *MyString::getStr(void) const
{
	return this->str;
}
int MyString::getLen(void) const
{
	return this->len;
}


