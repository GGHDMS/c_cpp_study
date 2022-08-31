#include<ostream>
using namespace std;
#include "MyString.h"

MyString::MyString() // ����Ʈ ������
{
	this->len = 0;
	this->str = new char[this->len + 1];
	strcpy(this->str, "");
	//cout << __FUNCTION__ << "()" << endl;
}
MyString::MyString(const char *cp)  // �����ε�� ������
{
	this->len = strlen(cp);
	this->str = new char[this->len + 1];
	strcpy(this->str, cp);
}
MyString::MyString(const MyString &br) // ���� ������
{
	this->len = br.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, br.str);
}
MyString::~MyString() // �Ҹ���
{
	delete[] this->str;
}
MyString &MyString::operator=(const MyString &br) // ���Կ����� ����Լ�
{
	if (this == &br) {  // �� = ��; ���� �ڵ�
		return *this;
	}
	delete[] this->str; // �޸� ���� ���� �ڵ�
	this->len = br.len;
	this->str = new char[this->len + 1];
	strcpy(this->str, br.str);
	return *this;
}
MyString MyString::operator+(const MyString &br) // ���� ������
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
bool MyString::operator>(const MyString &br) // ���迬���� ����Լ�
{
	return (this->len > br.len);
}
void MyString::setStr(const char *cp)
{
	if (this->str == cp) { // �� ���ڿ��� ��ü�� ���ʱ�ȭ ���� �ڵ�
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


